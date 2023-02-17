#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#define None NULL

typedef void* Data;
typedef struct _node* List;

bool null(const List);
int list_length(const List);
List list_prepend(Data, const List);
List singleton(Data);