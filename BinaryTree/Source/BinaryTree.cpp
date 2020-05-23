//
// Created by Sam Petrov on 20.05.2020.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree(const int* arr, const int start, const int end) {
    root = CreateMinimalBST(arr, start, end);
}

BinaryTree::~BinaryTree() {
    delete root;
}

TreeNode* BinaryTree::search(int data) const {
    return search(root, data);
}

TreeNode* BinaryTree::search(TreeNode* node, int data) {
    if(node == nullptr || data == node->getData())
        return node;
    if(data < node->getData())
        return search(node->getLeft(), data);
    else
        return search(node->getRight(), data);
}

void BinaryTree::insert(int d) {
    insert(root, d);
}

TreeNode* BinaryTree::insert(TreeNode* node, int data) {
    if(node == nullptr)
        return new TreeNode(data);
    else if(data < node->getData())
        node->setLeft(insert(node->getLeft(), data));
    else if(data > node->getData())
        node->setRight(insert(node->getRight(), data));
    return node;
}

TreeNode* BinaryTree::CreateMinimalBST(const int* array, const int start, const int end) {
    if (end < start)
        return nullptr;
    const int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(array[mid]);

    node->setLeft(CreateMinimalBST(array, start, mid - 1));
    node->setRight(CreateMinimalBST(array, mid + 1, end));

    return node;
}