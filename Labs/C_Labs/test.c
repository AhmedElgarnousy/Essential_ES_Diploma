#include <stdio.h>


typedef enum {
    err1, // 0
    err2 = 3, // 3
    err3, // 4
    err4, // 5
}Err_State_t;

int main()
{
Err_State_t i2c_err;

int x = err2;
i2c_err = err4;

printf("%d\n", i2c_err); 
printf("%d\n", x); 

// char x = 128;
// 128 -> 1000 0000
// and char is 8 bits
// then read it as signed so 1 for (-) sign, it will read -128
// printf("%d\n", x); // -128
    return 0;
}