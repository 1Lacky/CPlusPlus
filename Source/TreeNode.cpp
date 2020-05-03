//
// Created by Sam Petrov on 22.04.2020.
//
#include "../Headers/TreeNode.h"
#include <cassert>

TreeNode::TreeNode(const PlayField f, TreeNode *p): field(f), parent(p), children(children) {}

TreeNode::~TreeNode() {
    for(auto item : children)
        delete item;
}

int TreeNode::childQty() const {
    return field.getEmptyCells().size();
}

bool TreeNode::isTerminal() {
    return childCount() == 0;
}

/* Удобный метод для отладки */
TreeNode* TreeNode::getParent() {
    return this->parent;
}

void TreeNode::addChild(PlayField f) {
    assert(childCount() <= childQty());
    auto child = new TreeNode(f, this);
    children.push_back(child);
}

TreeNode& TreeNode::operator[](int pos) {
    assert(pos < childCount());
    return *children[pos];
}

int TreeNode::childCount() {
    return children.size();
}

PlayField const& TreeNode::value() {
    return field;
}