#include <stdio.h>

#include "array_list.h"

void print_int_al(int_al list){
    printf("[");
    for(size_t i=0;i<list.size;i++){
        printf("%d",list.items[i]);
        if(i!=list.size-1){
            printf(", ");
        }
    }
    printf("]\n");
}

int main(){
    
    int_al list1 = {0};
    int_al list2 = {0};

    printf("Let's populate two lists: (append_al)\n");
    for(size_t i=0;i<10;i++){
        append_al(list1,i);
        append_al(list2,i);
    }
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's attach list2 to list1: (append_all_al)\n");
    append_all_al(list1,list2);
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's remove the last element from list2: (remove_last_al)\n");
    remove_last_al(list2);
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's add a number (123) in position 2 in list2: (add_al)\n");
    add_al(list2,2,123);
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's remove the elements in position 4,5,6 from list1: (remove_al)\n");
    remove_al(list1,6);
    remove_al(list1,5);
    remove_al(list1,4);
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's set the element in position 1 to a number (123) in list1: (set_al)\n");
    set_al(list1,1,123);
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's trim to size list1: (trim_to_size_al)\n");
    printf("Capacity of list1 before trim: %d\n",list1.capacity);
    trim_to_size_al(list1);
    printf("Capacity of list1 after trim:  %d\n",list1.capacity);
    printf("\n");

    printf("Let's clean list1 and list2: (clean_al)\n");
    clean_al(list1);
    clean_al(list2);
    printf("list1: "); print_int_al(list1);
    printf("list2: "); print_int_al(list2);
    printf("\n");

    printf("Let's free list1 and list2 for good measure: (free_al)\n");
    free_al(list1);
    free_al(list2);
}

// to compile, stay in the directory of this file and the run: 
//      gcc example.c -o example
