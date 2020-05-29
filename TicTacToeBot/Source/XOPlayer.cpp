//
// Created by Sam Petrov on 25.05.2020.
//

#include "XOPlayer.h"
#include <cassert>

XOPlayer::XOPlayer(TreeNode &tree, PlayField::csState symbol): Tree(tree) {
    CurNode = &Tree;
    selectPlayer(symbol);
}

void XOPlayer::selectPlayer(PlayField::csState symbol) {
    Bot = (symbol == PlayField::csCross) ? PlayField::csNought : PlayField::csCross;
}

void XOPlayer::makeMove(PlayField::CellPos iCell) {
    assert(CurNode->value()[iCell] == PlayField::csEmpty);
    for (int i = 0; i < CurNode->childCount(); ++i)
        if ((*CurNode)[i].value()[iCell] != PlayField::csEmpty) {
            CurNode = &(*CurNode)[i];
            break;
        }
}

bool XOPlayer::isBestMove(TreeNode &goodTurn, TreeNode &current) const {
    return (Bot == PlayField::csCross && current.getCrossesWin() > goodTurn.getCrossesWin()
            || Bot == PlayField::csNought && current.getNoughtsWin() > goodTurn.getNoughtsWin())
            && current.getDraw() > goodTurn.getDraw();
}

void XOPlayer::makeMove() {
    assert(CurNode->childCount() != 0);
    TreeNode *goodTurn = &(*CurNode)[0];

    for (int i = 1; i < CurNode->childCount(); ++i)
        if (isBestMove(*goodTurn, (*CurNode)[i]))
            goodTurn = &(*CurNode)[i];
    CurNode = goodTurn;
}

