
#include "intlist.hpp"
#include <stdio.h>

void print_list_state(IntList & _list, const char* name) {
    printf("        %s list state is:\n    left = %p\n    right = %p\n    buffer = %d\n    current_elem = %p\n",name,_list.GetLeft(),_list.GetRight(),_list.GetBuffer(), _list.GetCurrentElement());
};


int main() {
    IntList plist;
    plist + 13;
    12 + plist;
    print_list_state(plist,"plist");

    int * tmp = plist.Store(66);
    printf("%d = tmp\n", *tmp);
    print_list_state(plist,"plist");

    return 0;
};