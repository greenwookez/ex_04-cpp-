#include "intlist.hpp"
#include <stdio.h>
#include <stdlib.h>

/* Output Format Functions */
void int_plus_list_o(IntList & _list, int _element, const char * name);
void list_plus_int_o(IntList & _list, int _element, const char * name);
void prefix_deque_o(IntList & _list, const char * name);
void postfix_deque_o(IntList & _list, const char * name);
void go_to_left_o(IntList & _list, const char * name);
void go_to_right_o(IntList & _list, const char * name);
void go_to_next_o(IntList & _list, const char * name);
void go_to_prev_o(IntList & _list, const char * name);
void fetch_o(IntList & _list, const char * name);
void store_o(IntList & _list, const char * name, int elem);

int main() {
    IntList plist01;
    int_plus_list_o(plist01, 64, "plist01");
    int_plus_list_o(plist01, 32, "plist01");
    int_plus_list_o(plist01, 16, "plist01");
    list_plus_int_o(plist01, 65, "plist01");
    list_plus_int_o(plist01, 33, "plist01");
    list_plus_int_o(plist01, 17, "plist01");


    return 0;
};

void int_plus_list_o(IntList & _list, int _element, const char * name) {
    int * tmp;
    tmp = _element + _list;
    printf("%d + %s == ", _element, name);
    if (tmp) {
        printf("OK\n");
    } else {
        printf("NoMemory\n");
    }
};

void list_plus_int_o(IntList & _list, int _element, const char * name) {
    int * tmp;
    tmp = _list + _element;
    printf("%s + %d == ", name, _element);
    if (tmp) {
        printf("OK\n");
    } else {
        printf("NoMemory\n");
    }
};

void prefix_deque_o(IntList & _list, const char * name) {
    int * tmp;
    tmp = --_list;
    printf("--%s == ",name);
    if (tmp) {
        printf("%d\n",*tmp);
    } else {
        printf("ListIsEmpty\n");
    }
};

void postfix_deque_o(IntList & _list, const char * name) {
    int * tmp;
    tmp = _list--;
    printf("%s-- == ",name);
    if (tmp) {
        printf("%d\n",*tmp);
    } else {
        printf("ListIsEmpty\n");
    }
};

void go_to_left_o(IntList & _list, const char * name) {
    _list.GoToLeft();
    printf("%s.GoToLeft() == OK\n", name);
};

void go_to_right_o(IntList & _list, const char * name) {
    _list.GoToRight();
    printf("%s.GoToLeft() == OK\n", name);
};

void go_to_next_o(IntList & _list, const char * name) { //TODO
    int * pint;
    IntDequeElement *tmp1, *tmp2;
    _list.GoToPrev();
    tmp1 = _list.GoToNext();
    if (tmp1 == NULL) {
        printf("%s.GoToNext() == NoCurrentElement\n", name);
    } else if (tmp1 == _list.GoToNext()) {
        printf("%s.GoToNext() == NoNextElement\n", name);
    } else {
        printf("%s.GoToNext() == OK\n", name);
    }
    
};

void go_to_prev_o(IntList & _list, const char * name) { //TODO
    
    
    _list.GoToPrev();
    printf("%s.GoToPrev() == OK\n", name);
};

void fetch_o(IntList & _list, const char * name) { 
    int * tmp;

    tmp = _list.Fetch();
    printf("%s.Fetch() == ",name);
    if (tmp) {
        printf("%d\n",*tmp);
    } else {
        printf("NoCurrentElement\n");
    };
};

void store_o(IntList & _list, const char * name, int elem) {
   int * tmp;

    tmp = _list.Store(elem);
    printf("%s.Store(%d) == ",name,elem);
    if (tmp) {
        printf("OK\n");
    } else {
        printf("NoCurrentElement\n");
    }; 
};

/* Debug Functions. Requires getters GetLeft(), GetRight(), etc...*/
/*void print_list_state(IntList & _list, const char* name) {
    printf("        %s list state is:\n    left = %p\n    right = %p\n    buffer = %d\n    current_elem = %p\n",name,_list.GetLeft(),_list.GetRight(),_list.GetBuffer(), _list.GetCurrentElement());
};

void print_list(IntList & _list, const char* name) {
    IntDequeElement * tmp;
    printf("Printing %s: ",name);
    tmp = _list.GetLeft();
    while(tmp) {
        printf("%d ",tmp -> GetElement());
        tmp = tmp -> GetNext();
    };
    printf("\n");
};*/