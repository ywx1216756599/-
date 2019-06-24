#include <stdio.h>
#include <stdlib.h>

typedef	int Status;

#define		OK		1
#define		ERROR	0
#define		TRUE	1
#define		FALSE	0
#define		INFEASIBLE	-1
#define		OVERFLOW	-2

typedef  int  ElemType;
typedef  struct  LNode
{
	ElemType		data;
	struct  LNode	*next;
}LNode, *LinkList;

//1. 初始化一个带头结点的空链表
Status InitList_Lk(LinkList &L);
//2. 销毁一个链表
Status DestroyList_Lk(LinkList &L);
//3. 创建一个链表
//(1) 按向头生长方式生成链表
Status CreateHeadList_Lk(LinkList &L, ElemType a[], int n);
//(2) 按向尾生长方式生成链表
Status CreateTailList_Lk(LinkList &L, ElemType a[], int n);
//4. 判断一个链表是否是空表
Status ListEmpty_Lk(LinkList L);
//5. 求链表的长度
int ListLength_Lk(LinkList L);
//7. 在链表中查找元素e的位置，如果不存在，返回0
int LocateElem_Lk(LinkList L, ElemType e);
//8. 在链表中返回元素cur_e的前驱元素值，由pre_e带回
Status PriorElem_Lk(LinkList L, ElemType cur_e, ElemType &pre_e);
//9. 在链表中返回元素e的后继元素值
Status NextElem_Lk(LinkList L, ElemType cur_e, ElemType &next_e);
//10. 向链表中第i个位置处插入一个新结点e，如果i值不合法，则插入失败
Status ListInsert_Lk(LinkList &L, int i, ElemType e);
//11. 删除链表中第i个结点，被删除的元素值由e带回，如果i值不合法，则删除失败
Status ListDelete_Lk(LinkList &L, int i, ElemType &e);
//12. 遍历链表
Status ListTraverse_Lk(LinkList L);
//13. 对链表中的结点进行排序
//(1) 直接插入排序
Status InsertSort_Lk(LinkList &L);
//(2) 冒泡排序
Status BubbleSort_Lk(LinkList &L);
//(3) 简单选择排序
Status SelectSort_Lk(LinkList &L);
//(4) 快速排序
 Status QuickSort_Lk(LinkList head, LinkList end);
//(5)归并排序
LinkList sortList(LinkList head);
LinkList merge(LinkList head1, LinkList head2);
//(6)基数排序
Status RadixSort_LK(LinkList &L);
int Qurey(int x);
int GetNum(LinkList p,int count);
int Power(int a,int n);