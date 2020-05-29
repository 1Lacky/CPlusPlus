//
// Created by Sam Petrov on 20.05.2020.
//

#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H

class TreeNode {
public:
    TreeNode(int data);
    ~ TreeNode();

    void setLeft(TreeNode* node);
    void setRight(TreeNode* node);
    TreeNode* getLeft() const;
    TreeNode* getRight() const;
    int getData() const;
private:
    int Data = 0;
    TreeNode* Left = nullptr;
    TreeNode* Right = nullptr;
};

#endif //BINARYTREE_TREENODE_H
