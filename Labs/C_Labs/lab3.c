#include<stdio.h>

int set_bit(int number,int bit_number){
	number |= (1<<bit_number);
	return number;
}
int clear_bit(int number,int bit_number){
	number &= ~(1 << bit_number);
	return number;
}
int toggle_bit(int number,int bit_number){
	number ^= ( 1 << bit_number);
	return number;
}

void app1()
{
	// note int 32 bit on this machine
    int num = 8, bit = 2;
    printf("%d \n", set_bit(num, bit)); // 12
    printf("%d \n", set_bit(0, 3)); // 8
    printf("%d \n", set_bit(0, 31)); // 2 billion
    printf("%d \n", set_bit(0, 7)); // 128
}
void prog1()
{
	int sum =0, num;
	for(int i= 0; i < 10; i++)
	{
		printf("Number-%d :", i);
		scanf("%d", &num);
		sum += num;
	}
	printf("sum of 10 no is: %d \n",sum);
	printf("the average is: %0.2f\t\n", (sum / 10.0));
}
void prog2()
{
	int n1 = 3, n2 = 4;
	int res;
	// scanf("%d %d", &n1,n2);
	printf("Enter the answer of  %d x %d = ",n1,n2);
	scanf("%d", &res);
	while(res != n1*n2)
	{
		printf("Not Correct Please Try AGAIN: ");
		scanf("%d", &res);
	}
	printf("Guten Tag\n");

}
void multiplication_table(){
	int num;
	scanf("%d", &num);
	for(int i = 1; i < 10; i++)
	{
		printf("%d x %d = %d \n", num, i, num*i);
	}
}
int factorial(int num) {
	int res = num;
	if(num <= 0)
	{
		return 1;
	}
	while(--num)
	{
		res *= num;
	}
	return res;
}
int factorial_R(int num) {

	if(!num)
		return 1;
	return num * factorial(num -1)	;
}
int main()
{
	// app1();
	// prog1();
	// prog2();
	// multiplication_table();
	printf("%d\n", factorial(0));
	printf("%d\n", factorial_R(0));
	printf("%d\n", factorial_R(5));
	printf("%d\n", factorial_R(6));


    return 0;
}