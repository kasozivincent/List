#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#define None NULL

struct _list;
typedef void* Data;
typedef struct _node* Node;
typedef struct _list* List;

List empty_list();
bool null(const List);
int list_length(const List);