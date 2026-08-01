#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//指针的学习
int main()
{
	int a = 10;
	                     //&：取地址操作符，取到a的地址；*：解引用操作符
	int* pa = &a;        //int*是pa类型,同理还存在char*,double*等类型
	printf("%p\n", &a);  //地址的打印
	*pa = 0;             //改变a的值
	printf("a=%d\n", a);   //a=0
	return 0;
}

//void*指针
//void可以接受任何类型，但是不能进行运算和解引用
int main()
{
	int a = 10;
	char c = 'w';
	void* pa = &a;
	void* pc = &c;
	printf("%p\n", pa);
	printf("%p\n", pc);

	return 0;
}

//char*类型一次跳过一个字节
///int*类型一次跳过四个字节

//指针+-整数
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pa = &arr[0];
	int sz = sizeof(arr) / sizeof(arr[0]);//数组大小的计算
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(pa + i));
	}
	return 0;
}

int main()
{
	char arr[] = "hello world";//在arr中以‘hello world\0’的形式存储
	char* pa = &arr[0];
	while (*pa != '\0')//由于'\0'的asc值为0，所以也能写成while( *pa )
	{
		printf("%c", *pa);
		pa++;
	}
	return 0;
}

//指针-指针
//前提：两个指针=指向的是同一内存空间
//得到的是两个指针之间的元素个数

//应用：写一个计算字符串长度的函数
int my_strlen(char* s)
{
	char* p = s;
	while (*p != '\0')
		p++;
	return p - s;
}

int main()
{
	printf("%d\n", my_strlen("abc"));//3
	return 0;
}
//指针也可以进行比较大小
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* pa = &arr[0];
	while (pa < arr + sz)//数组名也可以是数组首个元素的地址：arr==&arr[0]
	{
		printf("%d ", *pa);//1 2 3 4 5 6 7 8 9 10 
		pa++;
	}
}