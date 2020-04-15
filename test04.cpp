#include "intlist.hpp"
#include <stdio.h>
#include <stdlib.h>

/* Output Format Functions */
void int_plus_list_o(IntList & _list, int _element, const char * name);
void list_plus_int_o(IntList & _list, int _element, const char * name);
void prefix_list_o(IntList & _list, const char * name);
void postfix_list_o(IntList & _list, const char * name);
void go_to_left_o(IntList & _list, const char * name);
void go_to_right_o(IntList & _list, const char * name);
void go_to_next_o(IntList & _list, const char * name);
void go_to_prev_o(IntList & _list, const char * name);
void fetch_o(IntList & _list, const char * name);
void store_o(IntList & _list, const char * name, int elem);

int main() {
    IntList plist01, plist02;
    printf("    Filling up plist01...\n");
    int_plus_list_o(plist01, 64, "plist01");
    int_plus_list_o(plist01, 32, "plist01");
    int_plus_list_o(plist01, 16, "plist01");
    int_plus_list_o(plist01, 4, "plist01");
    list_plus_int_o(plist01, 65, "plist01");
    list_plus_int_o(plist01, 33, "plist01");
    list_plus_int_o(plist01, 17, "plist01");
    list_plus_int_o(plist01, 5, "plist01");

    printf("    Testing --plist01 only...\n");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");

    printf("    Filling up plist01...\n");
    int_plus_list_o(plist01, 64, "plist01");
    int_plus_list_o(plist01, 32, "plist01");
    int_plus_list_o(plist01, 16, "plist01");
    int_plus_list_o(plist01, 4, "plist01");
    list_plus_int_o(plist01, 65, "plist01");
    list_plus_int_o(plist01, 33, "plist01");
    list_plus_int_o(plist01, 17, "plist01");
    list_plus_int_o(plist01, 5, "plist01");

    printf("    Testing plist01-- only...\n");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");

    printf("    Filling up plist01...\n");
    int_plus_list_o(plist01, 64, "plist01");
    int_plus_list_o(plist01, 32, "plist01");
    int_plus_list_o(plist01, 16, "plist01");
    int_plus_list_o(plist01, 4, "plist01");
    list_plus_int_o(plist01, 65, "plist01");
    list_plus_int_o(plist01, 33, "plist01");
    list_plus_int_o(plist01, 17, "plist01");
    list_plus_int_o(plist01, 5, "plist01");

    printf("    Testing --plist01 and plist01-- together...\n");
    postfix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    prefix_list_o(plist01, "plist01");
    postfix_list_o(plist01, "plist01");

    printf("    Filling up plist01...\n");
    int_plus_list_o(plist01, 64, "plist01");
    int_plus_list_o(plist01, 32, "plist01");
    int_plus_list_o(plist01, 16, "plist01");
    int_plus_list_o(plist01, 4, "plist01");
    list_plus_int_o(plist01, 65, "plist01");
    list_plus_int_o(plist01, 33, "plist01");
    list_plus_int_o(plist01, 17, "plist01");
    list_plus_int_o(plist01, 5, "plist01");

    printf("    Testing GoTos on plist01...\n");
    go_to_left_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");

    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_right_o(plist01, "plist01");

    printf("    Testing Fetch() on plist01...\n");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist01, "plist01");
    fetch_o(plist01,"plist01");
    go_to_prev_o(plist01, "plist01");
    fetch_o(plist01,"plist01");
    go_to_next_o(plist01, "plist01");
    go_to_next_o(plist01, "plist01");
    fetch_o(plist01,"plist01");

    printf("    Testing Store() on plist01...\n");
    go_to_right_o(plist01, "plist01");
    fetch_o(plist01,"plist01");
    store_o(plist01,"plist01",13);
    fetch_o(plist01,"plist01");

    printf("    Testing plist02 = plist01...\n");
    plist02 = plist01;
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    postfix_list_o(plist02, "plist02");
    
    printf("    Testing copying constructor: IntList plist03 = plist01...\n");
    IntList plist03 = plist01;
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");
    prefix_list_o(plist03, "plist03");

    printf("    What's about equils operator? Is plist01 == plist02? Answer: %d\n", plist01 == plist02);

    plist02 = plist01;
    go_to_prev_o(plist01, "plist01");
    go_to_prev_o(plist02, "plist02");
    printf("    Is plist01 == plist02? Answer: %d\n", plist01 == plist02);

    int_plus_list_o(plist03, 1, "plist03");
    int_plus_list_o(plist03, 2, "plist03");
    int_plus_list_o(plist03, 3, "plist03");

    printf("    plist01 = plist02 = plist03...\n");
    plist01 = plist02 = plist03;
    printf("Is plist01 == plist02? Answer: %d\n", plist01 == plist02);
    printf("Is plist01 == plist03? Answer: %d\n", plist01 == plist03);
    printf("Is plist02 == plist03? Answer: %d\n", plist02 == plist03);
    printf("Is plist03 == plist02? Answer: %d\n", plist03 == plist02);
    printf("Is plist02 == plist02? Answer: %d\n", plist02 == plist02);

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

void prefix_list_o(IntList & _list, const char * name) {
    int * tmp;
    tmp = --_list;
    printf("--%s == ",name);
    if (tmp) {
        printf("%d\n",*tmp);
    } else {
        printf("ListIsEmpty\n");
    }
};

void postfix_list_o(IntList & _list, const char * name) {
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
    printf("%s.GoToLeft() == ",name);
    if (_list.GoToLeft()) {
        printf("OK\n");
    } else {
        printf("NoCurrentElement\n");
    };
};

void go_to_right_o(IntList & _list, const char * name) {
    printf("%s.GoToRight() == ",name);
    if (_list.GoToRight()) {
        printf("OK\n");
    } else {
        printf("NoCurrentElement\n");
    };
};

void go_to_next_o(IntList & _list, const char * name) {
    printf("%s.GoToNext() == ",name);
    if (_list.Fetch() == NULL) {
        printf("NoCurrentElement\n");
    } else {
        if (_list.GoToNext() == NULL) {
            printf("NoNextElement\n");
        } else {
            printf("OK\n");
        };
    };
};

void go_to_prev_o(IntList & _list, const char * name) {
    printf("%s.GoToPrev() == ",name);
    if (_list.Fetch() == NULL) {
        printf("NoCurrentElement\n");
    } else {
        if (_list.GoToPrev() == NULL) {
            printf("NoPrevElement\n");
        } else {
            printf("OK\n");
        };
    };
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