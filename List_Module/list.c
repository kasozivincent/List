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

List filter(const List list, Predicate predicate){
    if(null(list)) return None;
    else if(predicate(head)) return  cons(head, filter(tail, predicate));
    else return filter(tail, predicate);
}

List concat(const List left, const List right){
    if(null(left)) return right;
    else return cons(left->content, concat(left->next, right));
}

List append(Data item, const List list){
    if(null(list)) return singleton(item);
    else return cons(head, append(item, tail));
}

List from_array(Data arr[], int size){
    if(size == 0) return None;
    else return concat(from_array(arr, size - 1), singleton(arr[size - 1]));
}

List _intersperse(Data, const List);
List intersperse(Data item, const List list){
    if(null(list)) return None;
    else return cons(head, _intersperse(item, tail));
}

List _intersperse(Data item, const List list){
    if(null(list)) return None;
    else return cons(item, intersperse(item, list));
}
