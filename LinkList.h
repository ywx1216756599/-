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

//1. ��ʼ��һ����ͷ���Ŀ�����
Status InitList_Lk(LinkList &L);
//2. ����һ������
Status DestroyList_Lk(LinkList &L);
//3. ����һ������
//(1) ����ͷ������ʽ��������
Status CreateHeadList_Lk(LinkList &L, ElemType a[], int n);
//(2) ����β������ʽ��������
Status CreateTailList_Lk(LinkList &L, ElemType a[], int n);
//4. �ж�һ�������Ƿ��ǿձ�
Status ListEmpty_Lk(LinkList L);
//5. ������ĳ���
int ListLength_Lk(LinkList L);
//7. �������в���Ԫ��e��λ�ã���������ڣ�����0
int LocateElem_Lk(LinkList L, ElemType e);
//8. �������з���Ԫ��cur_e��ǰ��Ԫ��ֵ����pre_e����
Status PriorElem_Lk(LinkList L, ElemType cur_e, ElemType &pre_e);
//9. �������з���Ԫ��e�ĺ��Ԫ��ֵ
Status NextElem_Lk(LinkList L, ElemType cur_e, ElemType &next_e);
//10. �������е�i��λ�ô�����һ���½��e�����iֵ���Ϸ��������ʧ��
Status ListInsert_Lk(LinkList &L, int i, ElemType e);
//11. ɾ�������е�i����㣬��ɾ����Ԫ��ֵ��e���أ����iֵ���Ϸ�����ɾ��ʧ��
Status ListDelete_Lk(LinkList &L, int i, ElemType &e);
//12. ��������
Status ListTraverse_Lk(LinkList L);
//13. �������еĽ���������
//(1) ֱ�Ӳ�������
Status InsertSort_Lk(LinkList &L);
//(2) ð������
Status BubbleSort_Lk(LinkList &L);
//(3) ��ѡ������
Status SelectSort_Lk(LinkList &L);
//(4) ��������
 Status QuickSort_Lk(LinkList head, LinkList end);
//(5)�鲢����
LinkList sortList(LinkList head);
LinkList merge(LinkList head1, LinkList head2);
//(6)��������
Status RadixSort_LK(LinkList &L);
int Qurey(int x);
int GetNum(LinkList p,int count);
int Power(int a,int n);