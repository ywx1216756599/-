#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//1. ��ʼ��һ����ͷ���Ŀ�����
Status InitList_Lk(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}
//2. ����һ������
Status DestroyList_Lk(LinkList &L)
{
	LinkList p=L->next;
	while(p!=NULL)
	{
		L->next=p->next;
		free(p);
		p=L->next;
	}
	return OK;
}
//3. ����һ������
//(1) ����ͷ������ʽ��������
Status CreateHeadList_Lk(LinkList &L, ElemType a[], int n)
{
	LinkList p;
	int i;
	InitList_Lk(L);			//�ȳ�ʼ��������L
	for(i=0;i<n;i++)		//��n��Ԫ�����β��뵽L�У���Ϊ��1����㣬�������ͷ����
	{
		p=(LinkList)malloc(sizeof(LNode));	//�����½��p
		p->data=a[i];
		p->next=L->next;					//p����ͷ���ĺ��棬��Ϊ��1��Ԫ��
		L->next=p;
	}
	return OK;
}
//(2) ����β������ʽ��������
Status CreateTailList_Lk(LinkList &L, ElemType a[], int n)
{
	LinkList p,r;			//ָ��rʼ��ָ��L��β��㣬��ǰ�½��pʼ�ղ���r�ĺ���
	int i;
	InitList_Lk(L);
	r=L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));	//�����½��p
		p->data=a[i];
		r->next=p;							//p����β���r�ĺ���
		r=p;								//����p���µ�β���
	}
	return OK;
}
//4. �ж�һ�������Ƿ��ǿձ�
Status ListEmpty_Lk(LinkList L)
{
	return L->next==NULL ? TRUE : FALSE;
}
//5. ������ĳ���
int ListLength_Lk(LinkList L)
{
	int n=0;
	LinkList p;
	p=L;
	while(p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}
//6. ȡ��i������Ԫ��ֵ���ɲ���e����
int GetElem_Lk(LinkList L, int i, ElemType &e)
{
	if(i<=0)			//iֵ̫С�����Ϸ�
		return ERROR;
	int n=0;
	LinkList p=L;
	while(n<i && p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	if(n<i)				//iֵ̫�󣬲��Ϸ�
		return ERROR;
	e=p->data;
	return OK;
}
//7. �������в���Ԫ��e��λ�ã���������ڣ�����0
int LocateElem_Lk(LinkList L, ElemType e)
{
	int n=1;
	LinkList p=L->next;
	while(p!=NULL)
	{
		if(p->data==e)		//�ҵ���
			return n;		//��ʱnֵ����Ԫ��e��λ��
		n++;
		p=p->next;
	}
	return 0;				//�������ѭ��������ʾ�ҵ�����˵��e������
}
//8. �������з���Ԫ��cur_e��ǰ��Ԫ��ֵ����pre_e����
Status PriorElem_Lk(LinkList L, ElemType cur_e, ElemType &pre_e);
//9. �������з���Ԫ��e�ĺ��Ԫ��ֵ
Status NextElem_Lk(LinkList L, ElemType cur_e, ElemType &next_e);
//10. �������е�i��λ�ô�����һ���½��e�����iֵ���Ϸ��������ʧ��
Status ListInsert_Lk(LinkList &L, int i, ElemType e);
//11. ɾ�������е�i����㣬��ɾ����Ԫ��ֵ��e���أ����iֵ���Ϸ�����ɾ��ʧ��
Status ListDelete_Lk(LinkList &L, int i, ElemType &e);
//12. ��������
Status ListTraverse_Lk(LinkList L)
{
	LinkList p=L->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	putchar('\n');
	return OK;
}
//13. �������еĽ���������
int swap(int *x,int *y){
	int n;
	n = *x;
	*x = *y;
	*y = n;
	return OK;
}
//(1) ѡ���������
Status InsertSort_Lk(LinkList &L)
{
	LinkList p,q;
	for(p=L->next->next;p!=NULL;p = p->next){
		for(q = L->next;q!=p;q = q->next){
			if(p->data < q->data){
				swap(&p->data,&q->data);
			}
		}
	}
	return OK;
}
//(2) ð������
Status BubbleSort_Lk(LinkList &L)
{
	LinkList p,q;
	int i,j;
	int length;
	length = ListLength_Lk(L)-1;
	for(i=0;i<length;i++){
		p = L->next;
		q = p->next;
		for(j=0;j<length-i;j++){
			if(p->data > q->data){
				swap(&p->data,&q->data);
			}
			p = p->next;
			q = q->next;
		}
	}
	return OK;
}
//(3) ��ѡ������
Status SelectSort_Lk(LinkList &L){
	LinkList p,q;
	int length;
	length = ListLength_Lk(L)-1;
	p = L->next;
	q = p->next;
	for(p = L->next;p->next!=NULL;p = p->next){
		for(q = p->next;q!=NULL;q = q->next){
			if(p->data > q->data){
				swap(&p->data,&q->data);
			}
		}
	}
	return OK;
}

//(4)��������
 Status QuickSort_Lk(LinkList head, LinkList end){  
        if(head == NULL || head == end)             //���ͷָ��Ϊ�ջ�������Ϊ�գ�ֱ�ӷ���  
            return ERROR;   
        LinkList p = head -> next;                  //����������ָ��  
        LinkList small = head;  
        while( p != end){  
            if( p -> data < head -> data){      //����С�����Ԫ�ط������  
                small = small -> next;
				swap(&small->data,&p->data);
            }  	
            p = p -> next;  
        }  
		swap(&small->data,&head->data);
        QuickSort_Lk(head, small);                     //�����ҽ��еݹ�  
        QuickSort_Lk(small -> next, end);  
		return OK;
    }  
 //(5)�鲢����
LinkList sortList(LinkList head) {
    if(head == NULL || head->next == NULL)
        return head;
    else{
        //����ָ���ҵ��м�ڵ�
        LinkList fast = head;
		LinkList slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortList(head);//ǰ�������
        slow = sortList(slow);//��������
        return merge(fast,slow);
    }
 
}

LinkList merge(LinkList head1, LinkList head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    LinkList res , p ;
    if(head1->data < head2->data){
        res = head1; 
        head1 = head1->next;
    }else{
        res = head2; 
        head2 = head2->next;
    }
    p = res;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            p->next = head1;
            head1 = head1->next;
        } else{
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if(head1 != NULL)
        p->next = head1;
    else if(head2 != NULL)
        p->next = head2;
    return res;
}
//(6)��������
int Qurey(int x){
	int i=10;	
	int j;
	int count=1;
	j = x/i;
	while(j!=0){
		j = j/i;
		count++	;
	}
	return count;
}

int Power(int a,int n){
	int y;
	if(n==0)
		return 1;
	else
	{
		y=Power(a,n/2);
		y=y*y;
		if(n%2==1)
			y=y*a;
	}
	return y;
}
 
int GetNum(LinkList p,int count){
	int data=p->data;
	int a;
	count--;
	a=data/Power(10,count);
	return a%10;
}

Status RadixSort_LK(LinkList &L){
	LinkList a[10];
	LinkList array,p;
	int count,n,x,i;
	int length = ListLength_Lk(L);


	for(i=0;i<10;i++){
		a[i] = (LinkList)malloc(sizeof(LNode));
		a[i]->next = NULL;
	}

	length = ListLength_Lk(L);
	count = Qurey(length);

	for(x=1;x<=count;x++){
		array = L->next;
		while(array!=NULL){
			n = GetNum(array,x);//ĳλ������
			p = a[n];
			while(p->next!=NULL){
				p = p->next;
			}
				p->next = array;
				L->next = array->next;
				p = p->next;
				array = L->next;
				p->next = NULL;
		}
		//  array = L;
		L->next = NULL;
		for(i = 0; i<10 ; i++){
			array = L;
			while (array->next != NULL) array = array->next;
			array->next = a[i]->next;
			a[i]->next = NULL;
			//array->next = a[i]->next;
			//a[i]->next = NULL;
			//while(array->next!=NULL){
			//	array = array->next;
			//}
		}
	}
	return OK;
}

