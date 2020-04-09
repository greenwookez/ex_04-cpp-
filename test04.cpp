#include "intlist.hpp"
#include <stdio.h>

void print_list_state(IntList & _list, const char* name) {
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
}

int main() {
    IntList plist;
    plist + 13;
    12 + plist;
    14 + plist;
    15 + plist;
    16 + plist;
    print_list_state(plist,"plist");

    plist.GoToRight();
    int count;
    count = plist.countCurrentElemPosition();
    printf("count of plist = %d\n", count);
    print_list(plist,"plist");

    IntList plist02 = plist;
    count = plist02.countCurrentElemPosition();
    printf("count of plist02 = %d\n", count); 
    print_list(plist02,"plist02");
    return 0;
};