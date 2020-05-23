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
private:
    int childQty() const;

    const PlayField field;
    TreeNode* parent;
    std::vector<TreeNode*> children;
};
#endif //TICTACTOE_TREENODE_H
