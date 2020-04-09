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

IntList :: IntList(IntList & plist) {
    IntDequeElement * tmp1;
    IntDequeElement * tmp2;
    IntDequeElement * marker;
    if (plist.left == plist.right && plist.right != NULL) {
        buffer = plist.buffer;
        tmp2 = new IntDequeElement;
        tmp2 -> SetPrev(NULL);
        tmp2 -> SetNext(NULL);
        tmp2 -> SetElement(plist.right -> GetElement());
        left = tmp2;
        right = tmp2;

    } else if (plist.left == plist.right && plist.right == NULL) {
            buffer = plist.buffer;
            left = NULL;
            right = NULL;
    } else {
        buffer = plist.buffer;
        marker = plist.left;
        tmp2 = new IntDequeElement;
        left = tmp2;
        tmp2 -> SetPrev(NULL);
        tmp2 -> SetElement(marker -> GetElement());
        marker = marker -> GetNext();
        tmp1 = tmp2;
        while(marker -> GetNext()) {
            tmp2 = new IntDequeElement;
            tmp1 -> SetNext(tmp2);
            tmp2 -> SetPrev(tmp1);
            tmp2 -> SetElement(marker -> GetElement());
            marker = marker -> GetNext();
            tmp1 = tmp2;
        };
        tmp2 = new IntDequeElement;
        right = tmp2;
        tmp1 -> SetNext(tmp2);
        tmp2 -> SetPrev(tmp1);
        tmp2 -> SetElement(marker -> GetElement());
    };

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

int * IntList :: operator +(int _element) {//list + int
    int * tmp;
    tmp = this -> AddRight(_element);
    if (tmp != NULL) {
        current_elem = right;
        return tmp;
    } else {
        return NULL;
    }
};

int* operator +(int _element, IntList & _deque) {//int + list
    int * tmp;
    tmp = _deque.AddLeft(_element);
    if (tmp != NULL) {
        _deque.current_elem = _deque.left;
        return tmp;
    } else {
        return NULL;
    }
    
};

int * IntList :: operator --() {
    printf("lol\n");
    if (left == right) {
        current_elem = NULL;
        return RemoveLeft();
    } else {
        printf("lol2\n");
        current_elem = current_elem -> GetNext();
        return RemoveLeft();
    }
    
};

int * IntList :: operator --(int nothing) {
    printf("kek\n");
    if (left == right) {
        current_elem = NULL;
        return RemoveRight();
    } else {

        printf("kek2\n");
        current_elem = current_elem -> GetPrev();
        return RemoveRight();
    }    
};

/*IntList & IntList :: operator =(IntList & _deque) {

};


int IntList :: operator ==(IntList & _deque) {

};*/ 