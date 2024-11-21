#include <stdio.h>



void prog1()
{
    int x  = 7, y = 4;
    printf("%d \n", x & y); // 4
    printf("%d \n", x | y); // 7
    printf("%d \n", x ^ y); // 3
    printf("%d \n", x >> 1); // 3
    printf("%d \n", y << 2); // 16
}

void test()
{
    unsigned char x = 128;
    unsigned char res = x << 1;

    printf("%d \n", res); // 0

}
void prog2()
{
    int x = 5 ;
    int res ;

    res = x ==5;
    res = x !=5;
    res = x > 5;
    res = x < 5;
    printf("%d \n", res);
}

void prog3()
{
    int num;
    while(scanf("%d", &num))
    {
        if(num % 2)
            printf("num is odd\n");
        else
            printf("num is even\n");
        
    }

}
void prog4()
{
    int grade;
    scanf("%d",&grade);

    if(grade <= 0 && grade < 50)
    {
        printf("failed\n");
    }
    else if(grade <= 50 && grade < 65)
    {
        printf("Normal\n");
    }
    else if(grade <= 65 && grade < 75)
    {
        printf("good\n");
    }
    else if(grade <= 75 && grade < 85)
    {
        printf("very good\n");
    }
    else {
        printf("excellent\n");
    }

}

int main()
{
    // prog1();
    // prog2();
    // prog3();
    prog4();


    return 0;
}