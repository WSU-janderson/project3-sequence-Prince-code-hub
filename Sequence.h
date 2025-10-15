using namespace std;
#include<string>
#include<exception>


class SequenceNode {
public: // to make it easier, we can make the data members public so we don't need
    // getters and setters
    SequenceNode *next; // pointer to next Node. If node is the tail, next is
    // nullptr
    SequenceNode *prev; // pointer to previous Node. If node is the head, prev is
    // nullptr
    std::string item; // the element being stored in the node
    //default constructor, ensure next and prev are nullptr
    SequenceNode() : next(nullptr), prev(nullptr) {
    }

    /// parameterized constructor, next and prev are set to nullptr and the
    /// node's element is set to the given value
    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item) {
    }
};

class Sequence {
public:
    SequenceNode *head;
    SequenceNode *tail;
    size_t numElts;
    // Sequence() : head(nullptr), tail(nullptr), numElts(0){
    // // }


    // Creates an empty sequence (numElts == 0) or a sequence of numElts items
    // indexed from 0 ... (numElts - 1).
    Sequence(size_t sz = 0);

    // Creates a (deep) copy of sequence s
    Sequence(const Sequence &s);

    // Destroys all items in the sequence and release the memory
    // associated with the sequence
    ~Sequence();

    // The current sequence is released and replaced by a (deep) copy of sequence
    // s. A reference to the copied sequence is returned (return *this;).
    Sequence &operator=(const Sequence &s);

    // The position satisfies ( position >= 0 && position <= last_index() ).
    // The return value is a reference to the item at index position in the
    // sequence. Throws an exception if the position is outside the bounds
    // of the sequence
    std::string &operator[](size_t position);

    // The value of item is append to the sequence.
    void push_back(std::string item);

    // The item at the end of the sequence is deleted and size of the sequence is
    // reduced by one. If sequence was empty, throws an exception
    void pop_back();

    // The position satisfies ( position >= 0 && position <= last_index() ). The
    // value of item is inserted at position and the size of sequence is increased
    // by one. Throws an exceptionif the position is outside the bounds of the
    // sequence
    void insert(size_t position, std::string item);

    // Returns the first element in the sequence. If the sequence is empty, throw an
    // exception.
    std::string front() const;

    // Return the last element in the sequence. If the sequence is empty, throw an
    // exception.
    std::string back() const;

    // Return true if the sequence has no elements, otherwise false.
    bool empty() const;

    // Return the number of elements in the sequence.
    size_t size() const;

    // All items in the sequence are deleted and the memory associated with the
    // sequence is released, resetting the sequence to an empty state that can have
    // items re-inserted.
    void clear();

    // The item at position is removed from the sequence, and the memory
    // is released. If called with an invalid position throws an exception.
    void erase(size_t position);

    // The items in the sequence at ( position ... (position + count - 1) ) are
    // deleted and their memory released. If called with invalid position and/or
    // count throws an exception.
    void erase(size_t position, size_t count);

    // Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
    // stream. This is *not* a method of the Sequence class, but instead it is a
    // friend function
    friend ostream &operator<<(ostream &os, const Sequence &s);

};

