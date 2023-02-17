#include<stdio.h>

void show_int(void* intptr){
    printf("%d", *((int*)intptr));
}