#include<stdio.h>


void func(int *ptr)
{
    printf("%d from file2\n", sizeof(ptr) / sizeof(ptr[0])); // 2 or garbage
}