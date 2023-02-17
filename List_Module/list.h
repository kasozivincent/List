#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#define None NULL

typedef void* Data;
typedef struct _node* List;
typedef Data(*Func)(Data);
typedef void(*Show)(Data);
typedef bool(*Predicate)(Data);

bool null(const List);
int list_length(const List);
List list_prepend(Data, const List);
List singleton(Data);
List map(const List, Func);
void print_list(const List, Show, bool);
List filter(const List, Predicate);