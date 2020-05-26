//
// Created by Sam Petrov on 25.05.2020.
//
#ifndef TICTACTOE_XOPLAYER_H
#define TICTACTOE_XOPLAYER_H

#include "TreeNode.h"

class XOPlayer {
public:
    XOPlayer(TreeNode* tree, PlayField::csState symbol);
    void selectPlayer(PlayField::csState symbol);
    void makeMove(PlayField::CellPos iCell);
    void makeMove();
    PlayField currentState() const { return Field; };
    PlayField::fnState fieldStatus() const { return Field.checkFieldStatus(); };

private:
    TreeNode *CurNode = nullptr;
    PlayField::csState Bot = PlayField::csEmpty;
    PlayField Field;
};
#endif //TICTACTOE_XOPLAYER_H