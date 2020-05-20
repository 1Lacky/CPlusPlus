//
// Created by Sam Petrov on 20.05.2020.
//

#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H

class TreeNode {
public:
    TreeNode();
    TreeNode(int);
    ~ TreeNode();
    void setLeft(TreeNode*);
    void setRight(TreeNode*);
    void setData(const int);
    TreeNode* getLeft() const;
    TreeNode* getRight() const;
    int getData() const;
private:
    int data;
    TreeNode* left;
    TreeNode* right;
};

#endif //BINARYTREE_TREENODE_H
