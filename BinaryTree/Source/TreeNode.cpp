//
// Created by Sam Petrov on 20.05.2020.
//

#include "TreeNode.h"

TreeNode::TreeNode() {
    data = 0;
    right = nullptr;
    left = nullptr;
}

TreeNode::TreeNode(int d) {
    data = d;
    right = nullptr;
    left = nullptr;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

void TreeNode::setLeft(TreeNode* node) {
    left = node;
}

void TreeNode::setRight(TreeNode* node) {
    right = node;
}

void TreeNode::setData(const int d) {
    data = d;
}

TreeNode* TreeNode::getLeft() const {
    return left;
}

TreeNode* TreeNode::getRight() const {
    return right;
}

int TreeNode::getData() const {
    return data;
}
