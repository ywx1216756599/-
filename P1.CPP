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

		//����һ�����鳤��Ϊ100
		int a[100];	
		//��0��100��ֵ��a[0]��a[99]
		for (i=0;i<100;i++){
			a[i]=i+1;
		}
		// ��ʼ���������
		srand((unsigned int)time(NULL));
		for (i = 0; i < 100; ++i){
			// 100�������
			b = rand() % 99;
			//��������i�������н���
			temp = a[i];
			a[i] = a[b];
			a[b] = temp;
		}	
			//���������������
		CreateHeadList_Lk(L,a,100);



		printf("\n\n");
		printf("                        ����С����\n\n");
		printf("     *************************************************\n     *                                               *\n");
		printf("     *       1--------ѡ���������--------           *\n     *                                               *\n");
		printf("     *       2--------ð������------------           *\n     *                                               *\n");
		printf("     *       3--------��ѡ������--------           *\n     *                                               *\n");
		printf("     *       4--------��������------------           *\n     *                                               *\n");
		printf("     *       5--------�鲢����------------           *\n     *                                               *\n");
		printf("     *       6--------��������------------           *\n     *                                               *\n");
		printf("     *************************************************\n\n");

		printf("     ��������ѡ�������:");
		j = getchar();

		system("cls");
		printf("������L���£�\n");
		ListTraverse_Lk(L);

		switch(j){
			case '1':
				printf("ѡ���������󣬵�����L���£�\n");
				InsertSort_Lk(L);
				break;

			case '2':
				printf("ð������󣬵�����L���£�\n");
				BubbleSort_Lk(L);
				break;

			case '3':
				printf("��ѡ������󣬵�����L����:\n");
				SelectSort_Lk(L);
				break;
				
			case '4':
				printf("��������󣬵�����L����:\n");
				QuickSort_Lk(L->next,NULL);
				break;

			case '5':
				printf("�鲢����󣬵�����L����:\n");
				sortList(L);
				break;

			case '6':
				printf("��������󣬵�����L����:\n");
				RadixSort_LK(L);
				break;
			default :
				printf("\n��������ȷ����!!\n\n\n");
				printf("������L����:\n");

		}
				ListTraverse_Lk(L);
				printf("����һ���س�������������!");
				fflush(stdin);
				getch();
				system("cls");
	}
	return 0;
}