#include "list.h"

struct _node{
    Data content;
    struct _list* tail;
};

struct _list{
   Node head;
};

List empty_list(){
    List listptr = malloc(sizeof(struct _list));
    if(listptr == None) exit(1);
    *listptr = (struct _list){.head = None};
    return listptr; 
}

bool null(const List list){
    return list->head == None;
}

int list_length(const List list){
    if(null(list)) return 0;
    else return 1 + list_length(list->head->tail);
}