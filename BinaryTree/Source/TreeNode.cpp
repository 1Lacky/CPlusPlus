//
// Created by Sam Petrov on 20.05.2020.
//

#include "TreeNode.h"

TreeNode::TreeNode(int data) {
    Data = data;
}

TreeNode::~TreeNode() {
    delete Left;
    delete Right;
}

void TreeNode::setLeft(TreeNode* node) {
    Left = node;
}

void TreeNode::setRight(TreeNode* node) {
    Right = node;
}

TreeNode* TreeNode::getLeft() const {
    return Left;
}

TreeNode* TreeNode::getRight() const {
    return Right;
}

int TreeNode::getData() const {
    return Data;
}
