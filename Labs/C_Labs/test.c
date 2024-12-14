#include <stdio.h>

int main()
{
char x = 128;
// 128 -> 1000 0000
// and char is 8 bits
// then read it as signed so 1 for (-) sign, it will read -128
printf("%d\n", x); // -128
    return 0;
}