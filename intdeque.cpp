#include "intdeque.hpp"
#include <stdlib.h>
#include <stdio.h>

/* IntDequeElement Methods */
    IntDequeElement :: IntDequeElement() {
        element = 0;
        next = NULL;
        prev = NULL;
    };
    IntDequeElement :: IntDequeElement(int _element){
        element = _element;
        next = NULL;
        prev = NULL;
    };

    IntDequeElement :: IntDequeElement(int _element, IntDequeElement * _prev, IntDequeElement * _next) {
        element = _element;
        next = _next;
        prev = _prev;  
    };

    void IntDequeElement :: SetElement(int _element) {
        element = _element;
    };

    int IntDequeElement :: GetElement() {
        return element;
    };

    void IntDequeElement :: SetNext(IntDequeElement * _next) {
        next = _next;
    };

    IntDequeElement * IntDequeElement :: GetNext() {
        return next;
    };

    void IntDequeElement :: SetPrev(IntDequeElement * _prev) {
        prev = _prev;
    };

    IntDequeElement * IntDequeElement :: GetPrev() {
        return prev;
    };
/* End of IntDequeElement Methods */

/* IntDeque Methods */
    IntDeque :: IntDeque() {
        left = NULL;
        right = NULL;
        buffer = 0;
    };

    IntDeque :: IntDeque(IntDeque & _deque) {
        IntDequeElement * tmp1;
        IntDequeElement * tmp2;
        IntDequeElement * marker;
        if (_deque.left == _deque.right && _deque.right != NULL) {
            buffer = _deque.buffer;
            tmp2 = new IntDequeElement;
            tmp2 -> SetPrev(NULL);
            tmp2 -> SetNext(NULL);
            tmp2 -> SetElement(_deque.right -> GetElement());
            left = tmp2;
            right = tmp2;

        } else if (_deque.left == _deque.right && _deque.right == NULL) {
             buffer = _deque.buffer;
             left = NULL;
             right = NULL;
        } else {
            buffer = _deque.buffer;
            marker = _deque.left;
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
    };

    int * IntDeque :: AddLeft(int element) {
            IntDequeElement * tmp;

            tmp = new IntDequeElement;

            if (!tmp) {
                return NULL;
            } else {
                if ((this -> left == NULL) && (this -> right == NULL)) {
                    this -> right = tmp;
                    this -> left = tmp;
                    this -> buffer = element;
                    tmp -> SetElement(element);
                    tmp -> SetNext(NULL);
                    tmp -> SetPrev(NULL);
                    return &(this -> buffer); 
                } else if (this -> right == this -> left && (this -> right != NULL && this -> left != NULL)) {
                    tmp -> SetNext(this -> left);
                    tmp -> SetPrev(NULL);
                    tmp -> SetElement(element);
                    this -> left = tmp;
                    this -> buffer = element;
                    this -> right -> SetPrev(tmp);
                    return &(this -> buffer); 
                } else {
                    this -> left ->SetPrev(tmp);
                    tmp -> SetNext(this -> left);
                    tmp -> SetPrev(NULL);
                    tmp -> SetElement(element);
                    this -> left = tmp;
                    this -> buffer = element;
                    return &(this -> buffer); 
                }
            }
    };

    int * IntDeque :: AddRight(int element) {
        IntDequeElement * tmp;

        tmp = new IntDequeElement;

        if (!tmp) {
            return NULL;
        } else {
            if (this -> left == NULL && this -> right == NULL) {
                this -> right = tmp;
                this -> left = tmp;
                this -> buffer = element;
                tmp -> SetElement(element);
                tmp -> SetNext(NULL);
                tmp -> SetPrev(NULL);
                return &(this -> buffer); 
            } else if (this -> right == this -> left && (this -> right != NULL && this -> left != NULL)) {
                tmp -> SetPrev(this -> right);
                tmp -> SetNext(NULL);
                tmp -> SetElement(element);
                this -> right = tmp;
                this -> buffer = element;
                this -> left -> SetNext(tmp);
                return &(this->buffer); 
            } else {
                this -> right -> SetNext(tmp);
                tmp -> SetPrev(this -> right);
                tmp -> SetNext(NULL);
                tmp -> SetElement(element);
                this -> right = tmp;
                this -> buffer = element;
                return &(this->buffer); 
            }
        }
    };
    
    int * IntDeque :: RemoveLeft() {
        IntDequeElement * tmp;
        if (this -> left == NULL) {
            return NULL;
        } else if (this -> left == this -> right){
            this -> buffer = this -> left -> GetElement();
            delete this -> left;
            this -> left = NULL;
            this -> right = NULL;
            return &(this -> buffer);
        } else {
            tmp = this -> left;
            this -> left = tmp -> GetNext();
            this -> left -> SetPrev(NULL);
            this -> buffer = tmp -> GetElement();
            delete tmp;
            return &(this -> buffer);
        };            
    };

    int * IntDeque :: RemoveRight() {
        IntDequeElement * tmp;

        if (this -> right == NULL) {
            return NULL;
        } else if (this -> left == this -> right) {
            this -> buffer = this -> left -> GetElement();
            delete this -> left;
            this -> left = NULL;
            this -> right = NULL;
            return &(this -> buffer);
        } else {
            tmp = this -> right;
            this -> right = tmp -> GetPrev();
            this -> right -> SetNext(NULL);
            this -> buffer = tmp -> GetElement();
            delete tmp;
            return &(this -> buffer);
        };
    };
    
    int IntDeque :: GetElement() {
        return (this -> buffer);
    };

    int IntDeque :: IsEmpty() {
        if (this -> left == NULL) {
            return 1;
        } else {
            return 0;
        }
    };
    
    IntDeque :: ~IntDeque() {
        IntDequeElement * tmp;
        while(this -> left) {
            tmp = this -> left;
            this -> left = tmp -> GetNext();
            delete tmp;
        };
    };
    
/* End of IntDeque Methods */

/* IntDeque Operators */
    int* IntDeque :: operator + (int _element) { // deque + elem
        return this -> AddRight(_element);
    };

    int* operator +(int _element, IntDeque & _deque) { // elem + deque
        return _deque.AddLeft(_element);
    };

    int* IntDeque :: operator --() { // --deque
        return this -> RemoveLeft();
    };

    int* IntDeque :: operator -- (int nothing) { // deque--
        return this -> RemoveRight();
    };

    IntDeque & IntDeque :: operator =(IntDeque & _deque) { // deque = _deque
        IntDequeElement * tmp;
        IntDequeElement * tmp1;
        IntDequeElement * tmp2;
        IntDequeElement * marker;
        if (this == &_deque) {
            return *this;
        }


        while(this -> left) {
            tmp = this -> left;
            this -> left = tmp -> GetNext();
            delete tmp;
        };

        if (_deque.left == _deque.right && _deque.right != NULL) {
            buffer = _deque.buffer;
            tmp2 = new IntDequeElement;
            tmp2 -> SetPrev(NULL);
            tmp2 -> SetNext(NULL);
            tmp2 -> SetElement(_deque.right -> GetElement());
            left = tmp2;
            right = tmp2;

        } else if (_deque.left == _deque.right && _deque.right == NULL) {
             buffer = _deque.buffer;
             left = NULL;
             right = NULL;
        } else {
            buffer = _deque.buffer;
            marker = _deque.left;
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
        return *this;
    };

    int IntDeque :: operator ==(IntDeque & _deque) { // deque == deque

        IntDequeElement * tmp1;
        IntDequeElement * tmp2;

        tmp1 = this -> left;
        tmp2 = _deque.left; 
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

        return 0;
    };
/* End of IntDeque Operators */