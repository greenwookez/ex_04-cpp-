#include "intlist.hpp"
#include <stdlib.h>
#include <stdio.h>


IntList :: IntList() {
    current_elem = NULL;
    left = NULL;
    right = NULL;
    buffer = 0;
};

int IntList :: countCurrentElemPosition() {
    IntDequeElement * tmp;
    int count = 1;

    tmp = left;
    while(tmp) {
        if (current_elem == tmp) {
            return count;
        };
        count++;
        tmp = tmp -> GetNext();
    };
    
    return 0;
};

IntList :: IntList(IntList & plist) : IntDeque(plist) {
    IntDequeElement * marker;
    int count,i;
    count = plist.countCurrentElemPosition();
    marker = left;
    i = 1;
    while(i < count) {
        marker = marker -> GetNext();
        i++;
    };
    current_elem = marker;
};

IntDequeElement * IntList :: GoToLeft() {
    current_elem = left;
    return left;
};

IntDequeElement * IntList :: GoToRight() {
    current_elem = right;
    return right;
};

IntDequeElement * IntList :: GoToNext() {
    if (current_elem == NULL) {
        return NULL;
    } else if (current_elem == right) {
        return NULL;
    } else {
        current_elem = current_elem -> GetNext();
        return current_elem;    
    }
};

IntDequeElement * IntList :: GoToPrev() {
    if (current_elem == NULL) {
        return NULL;
    } else if (current_elem == left) {
        return NULL;
    } else {
        current_elem = current_elem -> GetPrev();
        return current_elem;    
    }
};

int * IntList :: Fetch() {
    if (current_elem == NULL) {
        return NULL;
    } else {
        buffer = current_elem -> GetElement();
        return &buffer;
    }
};

int * IntList :: Store(int elem) {
    if (current_elem == NULL) {
        return NULL;
    } else {
        current_elem -> SetElement(elem);
        buffer = elem;
        return &buffer;
    }
};

int * IntList :: AddLeft(int _element) {
    int * tmp;

    if (tmp = IntDeque :: AddLeft(_element)) {
        current_elem = GetLeft();
    }

    return tmp;
};

int * IntList :: AddRight(int _element) {
    int * tmp;

    if (tmp = IntDeque :: AddRight(_element)) {
        current_elem = GetRight();
    }

    return tmp;
};
int * IntList :: operator --() {
    if (left == right) {
        current_elem = NULL;
        return RemoveLeft();
    } else {
        GoToLeft();
        current_elem = current_elem -> GetNext();
        return RemoveLeft();
    }
    
};

int * IntList :: operator --(int nothing) {
    if (left == right) {
        current_elem = NULL;
        return RemoveRight();
    } else {
        GoToRight();
        current_elem = current_elem -> GetPrev();
        return RemoveRight();
    }    
};

IntList & IntList :: operator =(IntList & _list) {
    IntDequeElement * marker;


    IntDeque::operator=(_list);
    int count,i;
    count = _list.countCurrentElemPosition();
    marker = left;
    i = 1;
    while(i < count) {
        marker = marker -> GetNext();
        i++;
    };
    current_elem = marker;

    return *this;
};


int IntList :: operator ==(IntList & _list) {
    IntDequeElement * tmp1;
    IntDequeElement * tmp2;
    if (this -> countCurrentElemPosition() != _list.countCurrentElemPosition()) {
        return 0;
    }
    tmp1 = this -> left;
    tmp2 = _list.left; 
    while (1) {
        if ((tmp1 == NULL && tmp2 != NULL) || (tmp2 == NULL && tmp1 != NULL)) {
            return 0;
        } else if (tmp1 == NULL && tmp2 == NULL) {
            return 1;

        } else {
            if (tmp1 -> GetElement() != tmp2 -> GetElement()) {
                return 0;
            } else {
                tmp1 = tmp1 -> GetNext();
                tmp2 = tmp2 -> GetNext();
            };
        };
        
    };
}; 