//
// Created by Sam Petrov on 22.04.2020.
//
#ifndef TICTACTOE_TREENODE_H
#define TICTACTOE_TREENODE_H

#include <vector>
#include "PlayField.h"

class TreeNode{
public:
    TreeNode(const PlayField f, TreeNode* p = nullptr): field(f), parent(p) {}
    ~TreeNode();
    void addChild(PlayField);
    TreeNode& operator[](int) const;
    int childCount() const;
    const PlayField& value() const;

    void addCrossesWin() {  countOutcome.crossesWin++; }
    void addNoughtsWin() {  countOutcome.noughtsWin++; }
    void addDraw() { countOutcome.draw++; }
    double getCrossesWin() const { return  countOutcome.crossesWin / getTotal(); }
    double getNoughtsWin() const { return  countOutcome.noughtsWin / getTotal(); }
    double getDraw() const { return  countOutcome.draw / getTotal(); }
    double getTotal() const { return static_cast<double>(countOutcome.crossesWin + countOutcome.crossesWin + countOutcome.draw); }
    void operator+=(const TreeNode &node);

private:
    struct Counter {
        int crossesWin = 0;
        int noughtsWin = 0;
        int draw = 0;
    };
    int childQty() const;

    Counter countOutcome;
    const PlayField field;
    TreeNode* parent;
    std::vector<TreeNode*> children;
};
#endif //TICTACTOE_TREENODE_H