//
// Created by Sam Petrov on 19.05.2020.
//

#ifndef MATRIX_LINKEDLIST_H
#define MATRIX_LINKEDLIST_H

class LinkedList {
public:
    class Item {
    public:
        Item(int data, Item* item);
        int getData() const;
        Item* getPrevious() const;
        void setPrevious(Item* item);
        ~Item();

    private:
        int Data;
        Item* Previous;
    };

    ~LinkedList();
    void addItem(const int data);
    Item* searchItem(const int data) const;
    void deleteDuplicates();
private:
    Item* Head = nullptr;
    Item* Tail = nullptr;
};
#endif //MATRIX_LINKEDLIST_H
