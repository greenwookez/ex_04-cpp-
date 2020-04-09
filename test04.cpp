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
    IntList plist01;
    plist01 + 13;
    12 + plist01;
    14 + plist01;
    15 + plist01;
    16 + plist01;
    print_list_state(plist01,"plist01");

    plist01.GoToRight();
    int count;
    count = plist01.countCurrentElemPosition();
    printf("count of plist01 = %d\n", count);
    print_list(plist01,"plist01");

    IntList plist02 = plist01;
    count = plist02.countCurrentElemPosition();
    printf("count of plist02 = %d\n", count); 
    print_list(plist02,"plist02");

    printf("plist02 == plist01? answer: %d\n", plist02 == plist01);


    IntList plist03;
    plist03 = plist02;
    plist03--;
    plist03.GoToPrev();
    count = plist03.countCurrentElemPosition();
    printf("count of plist03 = %d\n", count);
    print_list(plist03,"plist03");
    plist01--;
    plist01.GoToLeft();
    plist01.GoToNext();
    plist01.GoToNext();
    printf("plist01 == plist03? answer: %d\n", plist01 == plist03);
    return 0;
};