//
// Created by Sam Petrov on 20.05.2020.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree(int* arr, const int start, const int end) {
    quickSort(arr, start, end);
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

/** Данный метод может создать сбалансированное дерево, только из отсортированного по возрастанию массива **/
TreeNode* BinaryTree::CreateMinimalBST(const int* array, const int start, const int end) {
    if (end < start)
        return nullptr;
    const int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(array[mid]);

    node->setLeft(CreateMinimalBST(array, start, mid - 1));
    node->setRight(CreateMinimalBST(array, mid + 1, end));

    return node;
}

void BinaryTree::swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int BinaryTree::section(int* arr, int start, int end) {
    int pivot = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
        if (arr[j] < pivot) {
            i++;
            swap(arr+i, arr+j);
        }

    swap(arr+(i + 1), arr+end);
    return (i + 1);
}

void BinaryTree::quickSort(int* arr, int start, int end) {
    if (start < end) {
        int pi = section(arr, start, end);

        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}