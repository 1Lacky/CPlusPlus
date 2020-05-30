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
    if(symbol == PlayField::csCross) 
	Bot = PlayField::csNought;
    else if(symbol == PlayField::csNought)
	Bot = PlayField::csCross;
    else
	assert("The player contains an invalid csState" && false);
}

void XOPlayer::makeMove(PlayField::CellPos iCell) {
    assert(CurNode->value()[iCell] == PlayField::csEmpty);
    for (int i = 0; i < CurNode->childCount(); ++i)
        if ((*CurNode)[i].value()[iCell] != PlayField::csEmpty) {
            CurNode = &(*CurNode)[i];
            break;
        }
}

bool XOPlayer::isBestMove(const TreeNode &goodTurn,const TreeNode &current) const {
    return (Bot == PlayField::csCross && current.getCrossesWinRatio() > goodTurn.getCrossesWinRatio())
           || (Bot == PlayField::csNought && current.getNoughtsWinRatio() > goodTurn.getNoughtsWinRatio());
}

void XOPlayer::makeMove() {
    assert(CurNode->childCount() != 0);
    TreeNode *goodTurn = &(*CurNode)[0];

    for (int i = 1; i < CurNode->childCount(); ++i)
        if (isBestMove(*goodTurn, (*CurNode)[i]))
            goodTurn = &(*CurNode)[i];
    CurNode = goodTurn;
}

