#include "intdeque.hpp"

class IntList : public IntDeque {
    IntDequeElement * current_elem;

    public:
    IntDequeElement * GoToLeft();
    IntDequeElement * GoToRight();
    IntDequeElement * GoToNext();
    IntDequeElement * GoToPrev();
    int * Fetch();
    int * Store(int elem);

    IntList();
    IntList(IntList & plist);
    int * operator +(int _element); // overloading operator list + int
    friend int* operator +(int _element, IntList & _deque); // overloading operator int + list
    int * operator --();
    int * operator --(int nothing);

    IntList & operator =(IntList & _deque); // overloading operator =
    int operator ==(IntList & _deque); // overloading operator ==



    /* tmp */

    IntDequeElement * GetLeft() {
        return left;
    };

    IntDequeElement * GetRight() {
        return right;
    };

    IntDequeElement * GetCurrentElement() {
        return current_elem;
    };

    int GetBuffer() {
        return buffer;
    }



    /* tmp */
};

int* operator +(int _element, IntList & _deque); // overloading operator int + list