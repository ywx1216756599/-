#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "LinkList.h"

int main()
{
	int i,j,b,temp;
	LinkList L;
	while(1){

		//创建一个数组长度为100
		int a[100];	
		//将0到100赋值给a[0]到a[99]
		for (i=0;i<100;i++){
			a[i]=i+1;
		}
		// 初始化随机环境
		srand((unsigned int)time(NULL));
		for (i = 0; i < 100; ++i){
			// 100个随机数
			b = rand() % 99;
			//随机数与第i个数进行交换
			temp = a[i];
			a[i] = a[b];
			a[b] = temp;
		}	
			//将数组插入链表中
		CreateHeadList_Lk(L,a,100);



		printf("\n\n");
		printf("                        排序小助手\n\n");
		printf("     *************************************************\n     *                                               *\n");
		printf("     *       1--------选择插入排序--------           *\n     *                                               *\n");
		printf("     *       2--------冒泡排序------------           *\n     *                                               *\n");
		printf("     *       3--------简单选择排序--------           *\n     *                                               *\n");
		printf("     *       4--------快速排序------------           *\n     *                                               *\n");
		printf("     *       5--------归并排序------------           *\n     *                                               *\n");
		printf("     *       6--------基数排序------------           *\n     *                                               *\n");
		printf("     *************************************************\n\n");

		printf("     请输入你选择的排序:");
		j = getchar();

		system("cls");
		printf("单链表L如下：\n");
		ListTraverse_Lk(L);

		switch(j){
			case '1':
				printf("选择插入排序后，单链表L如下：\n");
				InsertSort_Lk(L);
				break;

			case '2':
				printf("冒泡排序后，单链表L如下：\n");
				BubbleSort_Lk(L);
				break;

			case '3':
				printf("简单选择排序后，单链表L如下:\n");
				SelectSort_Lk(L);
				break;
				
			case '4':
				printf("快速排序后，单链表L如下:\n");
				QuickSort_Lk(L->next,NULL);
				break;

			case '5':
				printf("归并排序后，单链表L如下:\n");
				sortList(L);
				break;

			case '6':
				printf("基数排序后，单链表L如下:\n");
				RadixSort_LK(L);
				break;
			default :
				printf("\n请输入正确数字!!\n\n\n");
				printf("单链表L不变:\n");

		}
				ListTraverse_Lk(L);
				printf("按下一个回车，返回主界面!");
				fflush(stdin);
				getch();
				system("cls");
	}
	return 0;
}