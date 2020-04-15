#include "intdeque.hpp"

class IntList : public IntDeque {
    IntDequeElement * current_elem;
    int countCurrentElemPosition(); // определяет номер текущего элемента по счёту начиная с 1

    protected:
    int * AddLeft(int element);
    int * AddRight(int element);

    public:
    IntDequeElement * GoToLeft();
    IntDequeElement * GoToRight();
    IntDequeElement * GoToNext();
    IntDequeElement * GoToPrev();
    int * Fetch();
    int * Store(int elem);

    IntList();
    IntList(IntList & plist);

    int * operator --();
    int * operator --(int nothing);
    IntList & operator =(IntList & _deque); // overloading operator =
    int operator ==(IntList & _deque); // overloading operator ==
};