#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////指针的学习
//int main()
//{
//	int a = 10;
//	                     //&：取地址操作符，取到a的地址；*：解引用操作符
//	int* pa = &a;        //int*是pa类型,同理还存在char*,double*等类型
//	printf("%p\n", &a);  //地址的打印
//	*pa = 0;             //改变a的值
//	printf("a=%d\n", a);   //a=0
//	return 0;
//}
//
////void*指针
////void可以接受任何类型，但是不能进行运算和解引用
//int main()
//{
//	int a = 10;
//	char c = 'w';
//	void* pa = &a;
//	void* pc = &c;
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//
//	return 0;
//}
//
////char*类型一次跳过一个字节
/////int*类型一次跳过四个字节
//
////指针+-整数
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* pa = &arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);//数组大小的计算
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(pa + i));
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr[] = "hello world";//在arr中以‘hello world\0’的形式存储
//	char* pa = &arr[0];
//	while (*pa != '\0')//由于'\0'的asc值为0，所以也能写成while( *pa )
//	{
//		printf("%c", *pa);
//		pa++;
//	}
//	return 0;
//}
//
////指针-指针
////前提：两个指针=指向的是同一内存空间
////得到的是两个指针之间的元素个数
//
////应用：写一个计算字符串长度的函数
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}
//
//int main()
//{
//	printf("%d\n", my_strlen("abc"));//3
//	return 0;
//}
////指针也可以进行比较大小
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* pa = &arr[0];
//	while (pa < arr + sz)//数组名也可以是数组首个元素的地址：arr==&arr[0]
//	{
//		printf("%d ", *pa);//1 2 3 4 5 6 7 8 9 10 
//		pa++;
//	}
//}
//
////const修饰常量，将变量变为常变量
//int main()
//{
//	const int a = 10;
//	printf("%d\n", a);//10
//	int* pa = &a;
//	*pa = 0;//可以通过指针去改变a的值
//	printf("%d\n", a);//0
//	return 0;
//}
//
////const修饰指针
//int main()
//{
//	int a = 10;
//	const int* pa1 = &a;//const在*左边：修饰的是*pa1；*pa1不能去改变a的值
//	printf("%p\n", pa1);//0000008B82FAFA94
//	int b = 0;
//	pa1 = &b;//但是还是能用pa1去取另外一个变量的地址
//	printf("%p\n", pa1);//0000008B82FAFAD4
//
//	int* const pa2 = &a;//const在*右边：修饰的是pa2；pa2不能再去取其他变量的地址
//	printf("%d\n", a);//10
//	*pa2 = 0;//但是可以用*pa2去修改a的值
//	printf("%d\n", a);//0
//	return 0;
//}
//
////野指针初始化
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int* pb = NULL;//NULL为标识符常量，进行野指针的初始化
//	return 0;
//}

//assert断言
//需要包含头文件:#include<assert.h>
//#include<assert.h>
//int main()
//{
//	int* p=NULL;
//	assert(p!=NULL);//此时，p为空指针，会报错
//	//报错信息：Assertion failed: p!=NULL, file D:\Code\C_learn_test\test.c, line 133
//	//若p不为空指针，则不会报错，继续进行
//	return 0;
//}
//
////若不想继续assert断言，则添加NDEBUG
//#define NDEBUG


////strlen的模拟实现2
//#include<assert.h>
//size_t my_strlen(const char* str)//size_t为无符号整型
//{
//	int count = 0;
//	assert(str);//提高安全性
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	printf("%zu\n", my_strlen("abcd"));//size_t类型的打印
//	//4
//	return 0;
//}

//传址调用实例
//写一个函数，交换两个整数变量的值（只有传址调用才能实现）
void swap1(int* pa, int* pb)//传址调用
{
	int z = *pa;//z=a
	*pa = *pb;//z=b
	*pb = z;//b=a
}

int swap2(int x, int y)//此写法在main()函数中可以实现，但是当我们要写一个函数时却无法实现了
{
	int z = x;
	x = y;
	y = z;
	return x, y;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前：a=%d,b=%d\n", a, b);
	swap1(&a, &b);
	//swap2(a, b);//很明显无法实现
	printf("交换后：a=%d,b=%d\n", a, b);
	return 0;
}