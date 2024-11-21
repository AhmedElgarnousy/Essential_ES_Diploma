#include<stdio.h>


void prog1()
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nreversed array\n");

    for(int i = 9; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
}
void prog2(){
    int arr[10];
    
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        sum +=  arr[i];
    }
    printf("summation = %d\n",sum);
    printf("avg = %f ",sum / 10.0);
}

void swap(int *num1, int * num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(){
    int arr[5] = {9,7,30,15,11};
    for(int i =0 ; i < 4; i++)
    {
        for(int j =0 ; j < 4 -i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    //print 
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    // prog1();
    // prog2();
    bubbleSort();

    return 0;
}