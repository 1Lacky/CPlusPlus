//
// Created by Sam Petrov on 19.05.2020.
//

#include <cassert>
#include <unordered_set>
#include "LinkedList.h"

int LinkedList::Item::getData() const{
    return data;
}

LinkedList::Item* LinkedList::Item:: getPrevious() const{
    return previous;
}

void LinkedList::Item::setData(int d){
    data = d;
}

void LinkedList::Item::setPrevious(LinkedList::Item* item) {
    previous = item;
}

LinkedList::Item::~Item(){
    delete(previous);
}

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList(){
    delete(tail);
}

void LinkedList::addItem(int n) {
    Item *tmp = new Item;
    tmp->setData(n);
    tmp->setPrevious(tail);

    if(head == nullptr) head = tmp;
    tail = tmp;
}

LinkedList::Item* LinkedList::searchItem(int k) const {
    assert(k > 0);
    auto current = tail;
    --k;
    while(current != nullptr && k > 0){
        current = current->getPrevious();
        --k;
    }
    return (k > 0) ? nullptr : current;
}

void LinkedList::deleteDuplicates() {
    auto current = tail;
    std::unordered_set <int> set;
    Item* previous = nullptr;

    while (current != nullptr) {
        if (set.find(current->getData()) == set.end()) {
            set.insert(current->getData());
            previous = current;
        } else
            previous->setPrevious(current->getPrevious());
        current = current->getPrevious();
    }
}