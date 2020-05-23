//
// Created by Sam Petrov on 22.04.2020.
//
#include "TreeNode.h"
#include <cassert>

int TreeNode::childQty() const {
    return (parent == nullptr) ? PlayField::FIELD_SIZE : parent->childQty() - 1;
}

void TreeNode::addChild(PlayField f) {
    assert(childCount() <= childQty());
    children.push_back(new TreeNode(f, this));
}

TreeNode::~TreeNode() {
    for (auto item : children)
        delete item;
}

TreeNode& TreeNode::operator[](int pos) const {
    return *children[pos];
}

int TreeNode::childCount() const {
    return children.size();
}

const PlayField& TreeNode::value() const {
    return field;
}