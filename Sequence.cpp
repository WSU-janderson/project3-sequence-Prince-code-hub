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
        push_back(current->item);
        current = current->next;
    }
}


std::string &Sequence::operator[](size_t position) {
}


void Sequence::clear() {
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

void Sequence::erase(size_t position) {
    SequenceNode *current = head;
    if (current == nullptr) {
        return;
    }else {
        size_t count = 0;
        while (count < position) {
            current = current->next;
            count++;
        }
        current -> prev -> next = current-> next;
        current -> prev -> prev = current ->prev;
        delete current;
    }
    numElts--;
}

void Sequence::erase(size_t position, size_t count) {
    SequenceNode *current = head;
    if (current == nullptr) {
        return;
    }else{
        size_t length = 0;
        while (length < position) {
            current = current->next;
            length++;
        }
        while (count != 0) {
            SequenceNode *temp = current;
            current = current->next;
            temp -> prev -> next = temp-> next;
            temp -> next -> prev = temp ->prev;
            delete temp;
            count--;
            numElts--;
        }

    }

}


Sequence::~Sequence() {
    clear();
}

Sequence & Sequence::operator=(const Sequence &s) {

  clear();

    SequenceNode *current = s.head;
    while (current != nullptr) {
        SequenceNode *temp = current;
        current = current->next;
        delete temp;
    }

    head = tail = nullptr;
    numElts = 0;


    return *this;

}
void Sequence::push_back(std::string item) {

    SequenceNode *newNode = new SequenceNode;
    newNode->item = item;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    numElts++;
}

void Sequence::pop_back() {
    SequenceNode *current = tail;

    if (numElts == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }else if(current->next == nullptr) {
        tail = tail -> prev;
        tail->next = nullptr;
        delete current;
    }
    numElts--;
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
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
    numElts++;
}

std::string Sequence::front() const {
    SequenceNode *current = head;

    if (current == nullptr) {
        return "Empty List";
    }else {
        return current->item;
    }
}

std::string Sequence::back() const {
    SequenceNode *current = tail;
    if (current == nullptr) {
        return "Tail Empty";
    }else {
        return current->item;
    }
}

bool Sequence::empty() const {
    SequenceNode *current = head;
    if (current == nullptr) {
        return true;
    }else {
        return false;
    }
}

size_t Sequence::size() const {
    return numElts;
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
    return os;

}
