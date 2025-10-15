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

Sequence::Sequence(const Sequence &s) {
    SequenceNode *current = s.head;

    while (current) {
        push_back(current->item);
        current = current->next;
    }
}


std::string &Sequence::operator[](size_t position) {
    if (position >= numElts) {
        throw runtime_error("Out of range");
    }
    SequenceNode *current = head;
    size_t count = 0;
    while (count < position) {
        current = current->next;
        count++;
    }
    return current->item;
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

    if (position >= numElts) {
        throw runtime_error("Out of range");
    }
    if (position == 0 && numElts == 1) {
        delete current;
        head = nullptr;
        tail = nullptr;
        numElts = 0;
        return;
    }

    size_t count = 0;
    while (count < position) {
        current = current->next;
        count++;
    }
    if (current == head) {
        head = current->next;
        head->prev = nullptr;
    } else if (current == tail) {
        tail = current->prev;
        tail->next = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
    numElts--;
}

void Sequence::erase(size_t position, size_t count) {
    if (position + count > numElts) {
        throw runtime_error("Out of range");
    }
    SequenceNode *current = head;
    if (current == nullptr) {
        return;
    }
    size_t length = 0;
    while (length < position) {
        current = current->next;
        length++;
    }

    while (current != nullptr && count > 0) {
        SequenceNode *toDelete = current;
        current = current->next;

        if (toDelete->prev != nullptr) {
            toDelete->prev->next = toDelete->next;
        }else {
            head = toDelete->next;
        }
        if (toDelete->next != nullptr) {
            toDelete-> next -> prev = toDelete->prev;
        }else {
            tail = toDelete->prev;
        }
        delete toDelete;
        count--;
        numElts--;
    }
    if (numElts == 0) {
        head = nullptr;
        tail = nullptr;
    }
}


Sequence::~Sequence() {
    clear();
}

Sequence &Sequence::operator=(const Sequence &s) {
    clear();

    SequenceNode *current = s.head;
    while (current) {
        push_back(current->item);
        current = current->next;
    }
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
    if (head == nullptr) {
        throw runtime_error("Out of range");
    }
    if (numElts == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else{
        SequenceNode *current = tail;
        tail = tail->prev;
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
    } else if (position == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (position > numElts) {
        throw exception();
    } else if (position == numElts) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {
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
        throw runtime_error("Empty Sequence");
    }
        return current->item;
}

std::string Sequence::back() const {
    SequenceNode *current = tail;
    if (current == nullptr) {
        throw runtime_error("Empty Sequence");
    }
        return current->item;
    }


bool Sequence::empty() const {
    SequenceNode *current = head;
    if (current == nullptr) {
        return true;
    }
    return false;
}

size_t Sequence::size() const {
    return numElts;
}

ostream &operator<<(ostream &os, const Sequence &s) {
    SequenceNode *current = s.head;
    size_t count = 0;
    while (current != nullptr) {
        os << "[";
        os << current->item;
        os << "]";
        current = current->next;
        count++;
    }
    return os;
}
