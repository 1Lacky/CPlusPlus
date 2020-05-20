//
// Created by Sam Petrov on 20.05.2020.
//

#include "cmath"
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root= nullptr;
}

BinaryTree::BinaryTree(TreeNode* node) {
    root = node;
}

BinaryTree::BinaryTree(const int* arr, const int start, const int end) {
    root = CreateMinimalBST(arr, start, end);
}

BinaryTree::~BinaryTree() {
    delete root;
}

TreeNode* BinaryTree::search(int d) const {
    return search(root, d);
}

TreeNode* BinaryTree::search(TreeNode* node, int d) const {
    if(node == nullptr || d == node->getData())
        return node;
    if(d < node->getData())
        return search(node->getLeft(), d);
    else
        return search(node->getRight(), d);
}

void BinaryTree::insert(int d) {
    insert(root, d);
}

TreeNode* BinaryTree::insert(TreeNode* node, int d) {
    if(node == nullptr)
        return new TreeNode(d);
    else if(d < node->getData())
        node->setLeft(insert(node->getLeft(), d));
    else if(d > node->getData())
        node->setRight(insert(node->getRight(), d));
    return node;
}

TreeNode* BinaryTree::CreateMinimalBST(const int* arr, const int start, const int end) {
    if (end < start)
        return nullptr;
    const int mid = floor((start + end) / 2);
    TreeNode* node = new TreeNode(arr[mid]);

    node->setLeft(CreateMinimalBST(arr, start, mid - 1));
    node->setRight(CreateMinimalBST(arr, mid + 1, end));

    return node;
}