#include<stdio.h>


int binSearch(int *arr, int size, int target){
    int left = 0 ;
    int right = size - 1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            left = mid +1;
        else
            right = mid -1;
    }
    return -1; // if not found
}

void return_with_void(int x, int y, int *sum, int *sub)
{
    *sum = x +y;
    *sub = x - y;
}

int main()
{
    /*
    int arr [5] ={7,9,15,20,35};
    printf("%d\n" ,binSearch(arr, 5, 20));
    printf("%d\n" ,binSearch(arr, 5, 7));
    printf("%d\n" ,binSearch(arr, 5, 35));
    printf("%d\n" ,binSearch(arr, 5, 80));
    */

   int x = 10, y = 5;
   int sum, sub;
   return_with_void(x, y, &sum, &sub);
   printf("%d\n",sum);
   printf("%d\n",sub);


    return 0;
}