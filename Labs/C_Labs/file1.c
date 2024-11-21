#include<stdio.h>

void func(int *ptr);

int main()
{
    int arr[3] = {1,2,3};
    printf("%d from file1\n", sizeof(arr) / sizeof(arr[0])); // 3
    func(arr);
    return 0;
}