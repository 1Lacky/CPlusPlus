//
// Created by Sam Petrov on 22.04.2020.
//
#include "../Headers/TreeNode.h"
#include <cassert>

TreeNode::~TreeNode() {
    for(auto item : children)
        delete item;
}

int TreeNode::childQty() const {
    return field.getEmptyCells().size();
}

TreeNode* TreeNode::getParent() const{
    return parent;
}

void TreeNode::addChild(PlayField f) {
    assert(childCount() <= childQty());
    children.push_back(new TreeNode(f, this));
}

TreeNode& TreeNode::operator[](int pos) const {
    return *children[pos];
}

int TreeNode::childCount() const {
    return children.size();
}

PlayField const& TreeNode::value() const {
    return field;
}