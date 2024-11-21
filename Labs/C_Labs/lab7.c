#include<stdio.h>


int main()
{
    unsigned char x = 128;
    // printf("%d\n", x);

    printf("%d\n", sizeof(int)); // 4 bytes
    printf("%d\n", sizeof(char)); // 1
    printf("%d\n", sizeof(float)); // 4
    printf("%d\n", sizeof(double)); // 8
    printf("%d\n", sizeof(short int)); // 2
    printf("%d\n", sizeof(long int)); // 4
    printf("%d\n", sizeof(long double)); // 16
    printf("%d\n", sizeof(long long int )); // 8 not standard

    return 0;
}