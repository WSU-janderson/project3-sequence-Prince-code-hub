//Sequence.cpp
// Name: Prince Patel
// Course: CS 3100
// Project: Sequence
//
// Description:
//   This file implements the Sequence class. It has basic
//   operations like insert, push_back, pop_back, erase.
//   It also includes destruction and deep copy methods.
#include "Sequence.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

// Constructor that initializes a Sequence of given size
Sequence::Sequence(size_t sz) {
    //if sz is 0 then this code block sets head and tail to null pointer and numElts to 0
    if (sz == 0) {
        head = tail = nullptr;
        numElts = 0;
    } else { //this code block makes a new node named node1 and set numElts to 1
        SequenceNode *node1;
        node1 = new SequenceNode;
        head = node1;
        SequenceNode *current = head;
        numElts = 1;

        // make (sz - 1) more nodes and link them together
        size_t count = 1;
        while (count < sz) {
            SequenceNode *newNode = new SequenceNode();
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
            count++;
        }
        //set tail to the last current node
        tail = current;
        numElts = sz;
    }
}
// Copy constructor – makes a deep copy of another Sequence
Sequence::Sequence(const Sequence &s) {
    SequenceNode *current = s.head;

    // copy each element from sequence using push_back
    while (current) {
        push_back(current->item);
        current = current->next;
    }
}

// Overloaded [] operator – returns reference to item at position
std::string &Sequence::operator[](size_t position) {
    // if index is invalid then throw error
    if (position >= numElts) {
        throw runtime_error("Out of range");
    }
    // start from head and move until position
    SequenceNode *current = head;
    size_t count = 0;
    while (count < position) {
        current = current->next;
        count++;
    }
    // return the string stored at that node
    return current->item;
}

// Clears the whole list and frees memory
void Sequence::clear() {
    SequenceNode *current = head;
    // delete each node one by one
    while (current != nullptr) {
        SequenceNode *temp = current->next;
        delete current;
        current = temp;
    }
    // reset pointers and size
    tail = nullptr;
    numElts = 0;
    head = nullptr;
}
// Deletes a single node at given position
void Sequence::erase(size_t position) {
    SequenceNode *current = head;
    // throw error if position invalid
    if (position >= numElts) {
        throw runtime_error("Out of range");
    }
    // if there is only one node then just delete it and reset everything
    if (position == 0 && numElts == 1) {
        delete current;
        head = nullptr;
        tail = nullptr;
        numElts = 0;
        return;
    }
    // move to the node that needs to be delete
    size_t count = 0;
    while (count < position) {
        current = current->next;
        count++;
    }
    // adjust links depending on where the node is
    if (current == head) {
        // deleting first node
        head = current->next;
        head->prev = nullptr;
    } else if (current == tail) {
        // deleting last node
        tail = current->prev;
        tail->next = nullptr;
    } else {
        // deleting middle node
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    // free the node memory
    delete current;
    numElts--;
}
// Deletes count number of nodes starting from position
void Sequence::erase(size_t position, size_t count) {
    // check bounds
    if (position + count > numElts) {
        throw runtime_error("Out of range");
    }
    SequenceNode *current = head;
    if (current == nullptr) {
        return;
    }
    // move to starting position
    size_t length = 0;
    while (length < position) {
        current = current->next;
        length++;
    }

    // delete count number of nodes
    while (current != nullptr && count > 0) {
        SequenceNode *toDelete = current;
        current = current->next;

        // adjust the links between nodes
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
    // if list becomes empty, reset everything
    if (numElts == 0) {
        head = nullptr;
        tail = nullptr;
    }
}

// Destructor – automatically clears all nodes
Sequence::~Sequence() {
    clear();
}
// Assignment operator – do deep copy of another Sequence
Sequence &Sequence::operator=(const Sequence &s) {
    // clear current data first
    clear();

    // copy all items from other sequence
    SequenceNode *current = s.head;
    while (current) {
        push_back(current->item);
        current = current->next;
    }
    return *this;
}
// Adds new item at the end of the list
void Sequence::push_back(std::string item) {
    SequenceNode *newNode = new SequenceNode;
    newNode->item = item;
    newNode->next = nullptr;
    newNode->prev = tail;

    // if list empty, head and tail both point to new node
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    numElts++;
}

// Removes item from the end of the list
void Sequence::pop_back() {
    if (head == nullptr) {
        throw runtime_error("Out of range");
    }
    // if only one element, delete it and reset pointers
    if (numElts == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else{
        // remove tail node
        SequenceNode *current = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete current;
    }
    numElts--;
}
// Inserts an item at given position
void Sequence::insert(size_t position, std::string item) {
    SequenceNode *newNode = new SequenceNode;
    newNode->item = item;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // if it is a empty list
    if (head == nullptr) {
        head = tail = newNode;
    } else if (position == 0) {
        //if have to insert at  beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (position > numElts) {
        //if it is an invalid position
        throw runtime_error("Out of range");
    } else if (position == numElts) {
        //if you have to add at end
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {
        //if have to add in middle
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
// Returns the first element's value
std::string Sequence::front() const {
    SequenceNode *current = head;

    if (current == nullptr) {
        throw runtime_error("Empty Sequence");
    }
        return current->item;
}
// Returns the last element's value
std::string Sequence::back() const {
    SequenceNode *current = tail;
    if (current == nullptr) {
        throw runtime_error("Empty Sequence");
    }
        return current->item;
    }

// Checks if the sequence is empty
bool Sequence::empty() const {
    SequenceNode *current = head;
    if (current == nullptr) {
        return true;
    }
    return false;
}
// Returns number of elements in the sequence
size_t Sequence::size() const {
    return numElts;
}

// Overloaded << operator – prints the list elements
ostream &operator<<(ostream &os, const Sequence &s) {
    SequenceNode *current = s.head;
    size_t count = 0;
    while (current != nullptr) {
        os << "[ ";
        os << current->item;
        os << " ]";
        current = current->next;
        count++;
    }
    return os;
}
