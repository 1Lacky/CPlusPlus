//
// Created by Sam Petrov on 20.05.2020.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include "TreeNode.h"

class BinaryTree{
public:
    BinaryTree();
    BinaryTree(TreeNode*);
    BinaryTree(const int*, const int, const int);
    ~BinaryTree();

    TreeNode* search(int) const;
    void insert(int);
private:
    TreeNode* root;

    TreeNode* search(TreeNode*, int) const;
    TreeNode* insert(TreeNode*, int);
    static TreeNode* CreateMinimalBST(const int*, const int, const int);
};

#endif //BINARYTREE_BINARYTREE_H
