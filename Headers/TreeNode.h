//
// Created by Sam Petrov on 22.04.2020.
//
#include <vector>
#include "PlayField.h"

#ifndef TICTACTOE_TREENODE_H
#define TICTACTOE_TREENODE_H
class TreeNode{
private:
    const PlayField field;
    TreeNode *parent;
    std::vector<TreeNode*> children;

    int childQty() const;
public:
    TreeNode* getParent(); // Удобный метод для отладки
    TreeNode(PlayField, TreeNode* = nullptr);
    ~TreeNode();
    bool isTerminal();
    void addChild(PlayField);
    TreeNode& operator[](int);
    int childCount();
    PlayField const& value();
};
#endif //TICTACTOE_TREENODE_H
