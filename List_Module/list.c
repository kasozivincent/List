#include "list.h"
#define head list->content
#define tail list->next

typedef List Node;

struct _node{
    Data content;
    struct _node* next;
};

bool null(const List list){
    return list == None;
}

int list_length(const List list){
    if(null(list)) return 0;
    else return 1 + list_length(tail);
}

//helper function to create a list node.
List cons(Data data, List list){
    Node node = malloc(sizeof(list));
    if(node == None) exit(1);
    *node = (struct _node){.content = data, .next = list};
    return node;
}

List list_prepend(Data item, const List list){
    if(null(list)) return singleton(item);
    else return cons(item, list);
}

List singleton(Data item){
    return cons(item, None);
}

List map(const List list, Func func){
    if(null(list)) return None;
    else return cons(func(head), map(tail, func));
}

void print_list(const List list, Show show, bool start){
    if(null(list)) printf("[]\n");
    else{
          if(start)
            printf("[");
          show(head);
          if(list->next != None)
            printf(", ");
          else{
            printf("]\n"); return;
          }
          print_list(tail, show, false);
    }
}