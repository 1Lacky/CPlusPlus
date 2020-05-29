//
// Created by Sam Petrov on 25.05.2020.
//
#ifndef TICTACTOE_XOPLAYER_H
#define TICTACTOE_XOPLAYER_H

#include "TreeNode.h"

class XOPlayer {
public:
    XOPlayer() = delete;
    XOPlayer(TreeNode &tree, PlayField::csState symbol);
    void makeMove(PlayField::CellPos iCell);
    void makeMove();
    PlayField currentState() const { return CurNode->value(); };
    PlayField::fnState fieldStatus() const { return CurNode->value().checkFieldStatus(); };
private:
    void selectPlayer(PlayField::csState symbol);
    bool isBestMove(TreeNode &goodTurn, TreeNode &current) const;

    TreeNode &Tree;
    TreeNode* CurNode = nullptr;
    PlayField::csState Bot = PlayField::csEmpty;
};
#endif //TICTACTOE_XOPLAYER_H