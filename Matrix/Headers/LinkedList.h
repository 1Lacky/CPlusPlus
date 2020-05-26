//
// Created by Sam Petrov on 19.05.2020.
//

#ifndef MATRIX_LINKEDLIST_H
#define MATRIX_LINKEDLIST_H

class LinkedList {
public:
    class Item {
    public:
        int getData() const;
        Item* getPrevious() const;
        void setData(int);
        void setPrevious(Item*);
        ~Item();
    private:
        int data;
        Item* previous;

    };

    LinkedList();
    ~LinkedList();
    void addItem(const int n);
    Item* searchItem(const int k) const;
    void deleteDuplicates();
private:
    Item *head,*tail;
};
#endif //MATRIX_LINKEDLIST_H
