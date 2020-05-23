//
// Created by Sam Petrov on 20.05.2020.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include "TreeNode.h"

class BinaryTree{
public:
    BinaryTree(const int* array, const int start, const int end);
    ~BinaryTree();

    TreeNode* search(int data) const;
    void insert(int data);
private:
    TreeNode* root = nullptr;

    static TreeNode* search(TreeNode* node, int data);
    static TreeNode* insert(TreeNode* node, int data);
    static TreeNode* CreateMinimalBST(const int* array, const int start, const int end);
};

#endif //BINARYTREE_BINARYTREE_H
