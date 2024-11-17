#include <stdio.h>


void prog1()
{
    int len, wid;
    printf("enter rectangle length: ");
    scanf("%d", &len);
    
    printf("enter rectangle width: ");
    scanf("%d", &wid);
    
    printf("circumference %d and area is %d: ", (len + wid) * 2, len*wid);
}
void prog2()
{
    int n1,n2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &n1, &n2);
    
    printf("1- Summation: %d", n1 + n2);
    printf("1- Summation: %d", n1 - n2);
    printf("1- Summation: %d", n1 * n2);
    printf("1- Summation: %d", n1 / n2);

}



int main()
{
    // prog1();
    // prog2();

    return 0;
}