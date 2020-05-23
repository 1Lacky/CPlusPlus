//
// Created by Sam Petrov on 19.05.2020.
//

#include "LinkedList.h"
#include <unordered_set>

LinkedList::Item::Item(int data, Item* item) {
    Data =  data;
    Previous = item;
}

int LinkedList::Item::getData() const {
    return Data;
}

LinkedList::Item* LinkedList::Item::getPrevious() const {
    return Previous;
}

void LinkedList::Item::setPrevious(LinkedList::Item* item) {
    Previous = item;
}

LinkedList::Item::~Item(){
    delete(Previous);
}

LinkedList::~LinkedList(){
    delete(Tail);
}

void LinkedList::addItem(int data) {
    Item* tmp = new Item(data, Tail);

    if(Head == nullptr)
        Head = tmp;
    Tail = tmp;
}

LinkedList::Item* LinkedList::searchItem(int data) const {
    Item* current = Tail;
    --data;
    while(current != nullptr && data > 0){
        current = current->getPrevious();
        --data;
    }
    return (data > 0) ? nullptr : current;
}

void LinkedList::deleteDuplicates() {
    Item* current = Tail;
    std::unordered_set <int> set;
    Item* previous = nullptr;

    while (current != nullptr) {
        if (set.find(current->getData()) == set.end()) {
            set.insert(current->getData());
            previous = current;
            current = current->getPrevious();
        } else {
            previous->setPrevious(current->getPrevious());
            current->setPrevious(nullptr);
            delete current;
            current = previous->getPrevious();
        }
    }
}