#include "Sequence.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


Sequence::Sequence(size_t sz) {
    if (sz == 0) {
        head = tail = nullptr;
        numElts = 0;
    } else {
        SequenceNode *node1;
        node1 = new SequenceNode;
        head = node1;
        SequenceNode *current = head;
        head = node1;
        numElts = 1;

        size_t count = 1;
        while (count < sz) {
            SequenceNode *newNode = new SequenceNode();
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
            count++;
        }
        tail = current;
        numElts = sz;
    }
}

Sequence::Sequence(const Sequence &s) : numElts(s.numElts), head(s.head), tail(s.head) {
    SequenceNode *current = s.head;

    while (current) {
        addNode(current->item);
        current = current->next;
    }
}

void Sequence::addNode(string item) {
    SequenceNode *newNode = new SequenceNode;

    newNode->item = item;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (this->head == nullptr) {
        this->head = this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    numElts++;
}

void Sequence::clearlist() {
    SequenceNode *current = head;
    while (current != nullptr) {
        SequenceNode *temp = current->next;
        delete current;
        current = temp;
    }

    tail = nullptr;
    numElts = 0;
    head = nullptr;
}


Sequence::~Sequence() {
    clearlist();
}

void Sequence::push_back(std::string item) {

    SequenceNode *newNode = new SequenceNode;
    newNode->item = item;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (this->head == nullptr) {
        this->head = this->tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    numElts++;
}

void Sequence::insert(size_t position, std::string item) {

    SequenceNode *newNode = new SequenceNode;
    newNode->item = item;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    }else if (position == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }else if (position >= numElts) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }else {
        SequenceNode *current = head;
        size_t count = 0;
        while (count < position - 1) {
            current = current->next;
            count++;
        }

        newNode->next = current->next;
        current->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
    numElts++;
}

ostream & operator<<(ostream &os, const Sequence &s) {

    SequenceNode *current = s.head;
    size_t count = 0;

    if (current == nullptr) {
        os << "Empty sequence";
        return os;
    }
    while (current != nullptr) {
        os << "[" ;
        os << current->item;
        current = current->next;
        count++;
    }

}
