#include<stdio.h>

void prog1()
{
    char in;
    scanf("%c", &in);
    printf("%d \n", in); //
}

void calculator()
{
    int op1, op2, close = 1;
    char operation;
    
    do
    {

        printf("Enter operand1: ");
        scanf("%d", &op1);
        printf("Enter operand2: ");
        scanf("%d", &op2);

        printf("Enter operation: ");
        scanf(" %c", &operation);

        switch (operation)
        {
            case '+': printf("res: %d\n", op1+op2); break;
            case '-': printf("res: %d\n", op1-op2); break;
            case '*': printf("res: %d\n", op1*op2); break;
            case '/': printf("res: %d\n", op1/op2); break;
            default: printf("Invalid!\n"); break;
        }

        printf("press 1 to contiue or 0 to exit: ");
        scanf("%d",&close);
        system("cls");

    } while (close == 1);
    

}

int main()
{
    // prog1();
    calculator();

    return 0;
}