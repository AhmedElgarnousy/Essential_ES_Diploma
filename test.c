#include<stdio.h>


int main()
{
    int num = 15;
    int second = num %10;    
    int first = num / 10;

    printf("%d %d %d\n", num, first, second);    
    return 0;
}