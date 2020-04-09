#include "intdeque.hpp"
#include <stdlib.h>
#include <stdio.h>

/* Output Functions */
    void addleft_o(IntDeque & _deque, int _element, const char * name);
    void addright_o(IntDeque & _deque, int _element, const char * name);
    void removeleft_o(IntDeque & _deque, const char * name);
    void removeright_o(IntDeque & _deque, const char * name);
    void int_plus_deque_o(IntDeque & _deque, int _element, const char * name);
    void deque_plus_int_o(IntDeque & _deque, int _element, const char * name);
    void prefix_deque_o(IntDeque & _deque, const char * name);
    void postfix_deque_o(IntDeque & _deque, const char * name);
    void if_equals_deque_o(IntDeque & _deque1, const char * name1,IntDeque & _deque2, const char * name2);
/* End of Output Functions */

/* Debug Functions */
    void print_deque_state(IntDeque & input, const char* name);
    void print_deque(IntDeque & input, const char* name);
/* End of Debug Functions */

int main() {
    IntDeque pdeque01,pdeque02;
    printf("       Fiiling up pdeque01...\n");
    int_plus_deque_o(pdeque01, 1, "pdeque01");
    int_plus_deque_o(pdeque01, 5, "pdeque01");
    int_plus_deque_o(pdeque01, 6, "pdeque01");
    deque_plus_int_o(pdeque01, 7, "pdeque01");
    deque_plus_int_o(pdeque01, 6, "pdeque01");
    deque_plus_int_o(pdeque01, 9, "pdeque01");

    printf("       Testing --pdeque01 only...\n");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");

    printf("       Fiiling up pdeque01...\n");
    int_plus_deque_o(pdeque01, 1, "pdeque01");
    int_plus_deque_o(pdeque01, 5, "pdeque01");
    int_plus_deque_o(pdeque01, 6, "pdeque01");
    deque_plus_int_o(pdeque01, 7, "pdeque01");
    deque_plus_int_o(pdeque01, 6, "pdeque01");
    deque_plus_int_o(pdeque01, 9, "pdeque01");

    printf("       Testing pdeque01-- only...\n");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");

    printf("       Fiiling up pdeque01...\n");
    int_plus_deque_o(pdeque01, 1, "pdeque01");
    int_plus_deque_o(pdeque01, 5, "pdeque01");
    int_plus_deque_o(pdeque01, 6, "pdeque01");
    deque_plus_int_o(pdeque01, 7, "pdeque01");
    deque_plus_int_o(pdeque01, 6, "pdeque01");
    deque_plus_int_o(pdeque01, 9, "pdeque01");

    printf("       Testing --pdeque01 and pdeque01-- together...\n");
    postfix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");

    printf("       Fiiling up pdeque01...\n");
    int_plus_deque_o(pdeque01, 3, "pdeque01");
    int_plus_deque_o(pdeque01, 2, "pdeque01");
    int_plus_deque_o(pdeque01, 1, "pdeque01");
    deque_plus_int_o(pdeque01, 4, "pdeque01");
    deque_plus_int_o(pdeque01, 5, "pdeque01");
    deque_plus_int_o(pdeque01, 6, "pdeque01");
    printf("       Fiiling up pdeque02...\n");
    int_plus_deque_o(pdeque02, 3, "pdeque02");
    int_plus_deque_o(pdeque02, 2, "pdeque02");
    int_plus_deque_o(pdeque02, 1, "pdeque02");
    deque_plus_int_o(pdeque02, 4, "pdeque02");
    deque_plus_int_o(pdeque02, 5, "pdeque02");
    deque_plus_int_o(pdeque02, 6, "pdeque02");

    printf("       Is pdeque01 equals pdeque02?\n");
    if_equals_deque_o(pdeque01, "pdeque01", pdeque02, "pdeque02");

    printf("       Changing pdeque01...\n");
    prefix_deque_o(pdeque01, "pdeque01");
    prefix_deque_o(pdeque01, "pdeque01");

    printf("       Is pdeque01 equals pdeque02?\n");
    if_equals_deque_o(pdeque01, "pdeque01", pdeque02, "pdeque02");
    printf("       Let's make an equation between pdeque01 and pdeque02...\n");
    prefix_deque_o(pdeque02, "pdeque02");
    prefix_deque_o(pdeque02, "pdeque02");

    printf("       Is pdeque01 equals pdeque02?\n");
    if_equals_deque_o(pdeque01, "pdeque01", pdeque02, "pdeque02");

    printf("       Constructing pdeque03...\n"); 
    IntDeque pdeque03;
    printf("       Assigning pdeque01 to pdeque03...\n"); 
    pdeque03 = pdeque01;

    printf("       Is pdeque03 equals pdeque02?\n");
    if_equals_deque_o(pdeque03, "pdeque03", pdeque02, "pdeque02");


    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    postfix_deque_o(pdeque01, "pdeque01");
    pdeque03 = pdeque02 = pdeque01;

    postfix_deque_o(pdeque03, "pdeque03");
    postfix_deque_o(pdeque02, "pdeque02");
    printf("       Is pdeque03 equals pdeque02?\n");
    if_equals_deque_o(pdeque03, "pdeque03", pdeque02, "pdeque02");

    return 0;
}

void int_plus_deque_o(IntDeque & _deque, int _element, const char * name) {
    int * tmp;
    tmp = _element + _deque;
    printf("%d + %s == ", _element, name);
    if (tmp) {
        printf("OK\n");
    } else {
        printf("NoMemory\n");
    }
};

void deque_plus_int_o(IntDeque & _deque, int _element, const char * name) {
    int * tmp;
    tmp = _deque + _element;
    printf("%s + %d == ", name, _element);
    if (tmp) {
        printf("OK\n");
    } else {
        printf("NoMemory\n");
    }
};

void prefix_deque_o(IntDeque & _deque, const char * name) {
    int * tmp;
    tmp = --_deque;
    printf("--%s == ",name);
    if (tmp) {
        printf("%d\n",*tmp);
    } else {
        printf("DequeIsEmpty\n");
    }
};

void postfix_deque_o(IntDeque & _deque, const char * name) {
    int * tmp;
    tmp = _deque--;
    printf("%s-- == ",name);
    if (tmp) {
        printf("%d\n",*tmp);
    } else {
        printf("DequeIsEmpty\n");
    }
};


void if_equals_deque_o(IntDeque & _deque1, const char * name1,IntDeque & _deque2, const char * name2) {
    int tmp;
    tmp = _deque1 == _deque2;
    if (tmp == 1) {
        printf("%s == %s\n",name1,name2);
    } else {
        printf("%s != %s\n",name1,name2);
    }
};


void addleft_o(IntDeque & _deque, int _element, const char * name) {
    _deque.AddLeft(_element);
    printf("%s.AddLeft(%d); %s.GetElement() == %d\n", name, _element, name, _deque.GetElement()); 
};

void addright_o(IntDeque & _deque, int _element, const char * name) {
    _deque.AddRight(_element);
    printf("%s.AddRight(%d); %s.GetElement() == %d\n", name, _element, name, _deque.GetElement()); 
};

void removeleft_o(IntDeque & _deque, const char * name) {
    int * tmp;
    tmp = _deque.RemoveLeft();
    
    if (tmp != NULL) {
        printf("%s.RemoveLeft(); %s.GetElement == %d\n", name, name, _deque.GetElement());
    } else {
        printf("%s.RemoveLeft() == NULL\n", name);
    }
};

void removeright_o(IntDeque & _deque, const char * name) {
    int * tmp;
    tmp = _deque.RemoveRight();
    
    if (tmp != NULL) {
        printf("%s.RemoveRight(); %s.GetElement == %d\n", name, name, _deque.GetElement());
    } else {
        printf("%s.RemoveRight() == NULL\n", name);
    }
};

/* Debug Functions (request access to private fields) */
    /*void print_deque_state(IntDeque & input,const char* name) {
        printf("\nname == %s\nleft == %p\nright == %p\nbuffer == %d\n", name, input.left, input -> right, input -> buffer);
    };

    void print_deque(IntDeque & input, const char* name) {
        IntDequeElement * tmp;

        printf("\nPrinted %s: \n\n",name);
        tmp = input.left;
        while(tmp) {
            printf("elem: %d \n", tmp->GetElement());
            printf("addr: %p \n", &tmp);
            printf("prev: %p \n", tmp->GetPrev());
            printf("next: %p \n", tmp->GetNext());
            printf("\n");
            tmp = tmp -> GetNext();
        }
    };*/
/* End of Debug Functions */