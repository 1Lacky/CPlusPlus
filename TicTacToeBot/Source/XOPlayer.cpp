//
// Created by Sam Petrov on 25.05.2020.
//

#include "XOPlayer.h"
#include <cassert>

XOPlayer::XOPlayer(TreeNode *tree, PlayField::csState symbol) {
    CurNode = tree;
    selectPlayer(symbol);
}

void XOPlayer::selectPlayer(PlayField::csState symbol) {
    Bot = (symbol == PlayField::csCross) ? PlayField::csNought : PlayField::csCross;
}

void XOPlayer::makeMove(PlayField::CellPos iCell) {
    assert(Field[iCell] == PlayField::csEmpty);
    Field = Field.makeMove(iCell);
    for (int i = 0; i < CurNode->childCount(); ++i)
        if ((*CurNode)[i].value()[iCell] != PlayField::csEmpty) {
            CurNode = &(*CurNode)[i];
            break;
        }
}

void XOPlayer::makeMove() {
    assert(CurNode->childCount() != 0);
    TreeNode *goodTurn = &(*CurNode)[0];

    for (int i = 1; i < CurNode->childCount(); ++i) {
        if (((Bot == PlayField::csCross && CurNode[i].getCrossesWin() > goodTurn->getCrossesWin())
             || (Bot == PlayField::csNought && CurNode[i].getNoughtsWin() > goodTurn->getNoughtsWin()))
            && CurNode[i].getDraw() > goodTurn->getDraw())
            goodTurn = &(*CurNode)[i];
    }

    Field = goodTurn->value();
    CurNode = goodTurn;
}