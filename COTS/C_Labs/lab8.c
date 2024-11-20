#include<stdio.h>
#include"STD_TYPES.h"

/*
struct employee
{
    int salary ;
    int bonus ;
    int deductions ;
};
*/

typedef struct 
{
    int salary ;
    int bonus ;
    int deductions ;
}employee;


void prog1()
{
    employee ahmed, waleed,Amr;
    
    printf("ahmed data respectivly: ");
    scanf("%d%d%d", &ahmed.salary, &ahmed.bonus, &ahmed.deductions);

    printf("waleed data: ");
    scanf("%d%d%d", &waleed.salary, &waleed.bonus, &waleed.deductions);

    printf("Amr data: ");
    scanf("%d%d%d", &Amr.salary, &Amr.bonus, &Amr.deductions);

    printf("Ahmed salary: %d\n", ahmed.salary);
    printf("Ahmed bonus: %d\n", ahmed.bonus);
    printf("Ahmed deduction: %d\n", ahmed.deductions);

    printf("waleed salary: %d\n", waleed.salary);
    printf("waleed bonus: %d\n", waleed.bonus);
    printf("waleed deduction: %d\n", waleed.deductions);

    printf("Amr salary: %d\n", Amr.salary);
    printf("Amr bonus: %d\n", Amr.bonus);
    printf("Amr deduction: %d\n", Amr.deductions);
}

int prog2( employee emp)
{
    return emp.salary + emp.bonus;
}

employee scanEmployee(void)
{
    employee emp;
    // code
    return emp;
}

void prog3()
{
    employee emp1 = {100, 140, 90};
    employee* ptr= & emp1;

    printf("%d\n", ptr->salary);
}


void prog4()
{
    typedef struct  {
        u16 language;
        u16 physics;
        u16 math;
        u16 chemisty;
    } student;

    student arr[10]; //u can say class instead of arr
    int ID;
    printf("please enter ID of student from 1 to 10:");
    scanf("%d",&ID);

	for(u8 i = 0; i < 10 ; i++)
	{
		arr[i].math = i*7 + 20;
		arr[i].language = i*6 + 40;
		arr[i].physics = i*5 + 50;
		arr[i].chemisty = i*4 + 60;
	}

	if( ID < 1 || ID > 10){
		printf("ID not found");
	}
	else {
		ID--;
		printf("language grade %d\n", arr[ID].language);
		printf("physics grade %d\n", arr[ID].physics);
		printf("math grade %d\n", arr[ID].math);
		printf("chemisty   grade %d\n",arr[ID].chemisty );
	}
}

// #pragma pack(1) 

void prog5()
{
    typedef struct 
    {
        u16 salary;
        u16 bonus;
        u8 ID;
        u8 ID2;
    }employee;

    employee adel;
    printf("%d\n", sizeof(adel)); // 
}

void prog6 ()
{
    typedef union 
    {
        u8 x;
        u16 y;
    }MyUnion;
    
    MyUnion obj1;
    
    printf("%d\n", sizeof(obj1)); // 2 byte
    
    obj1.x = 10;
    printf("%d\n", obj1.y); // 10
}


void prog7() {
    typedef union 
    {
        struct 
        {
            u8 Bit1 : 1;
            u8 Bit2 : 1;
            u8 Bit3 : 1;
            u8 Bit4 : 1;
            u8 Bit5 : 1;
            u8 Bit6 : 1;
            u8 Bit7 : 1;
        } BitAccess;

        u8 ByteAccess;
    }register_t;

    register_t MemoryByte;
    MemoryByte.ByteAccess = 20;
    MemoryByte.BitAccess.Bit1 = 1;
}

int main()
{
   // printf("%d\n", sizeof(void)); // 1 is a compiler dependent
    // prog1();
    // prog3();
    // prog4();
    // prog5();
    // prog6();
    prog7();
    
    return 0;
}