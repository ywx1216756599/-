#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//1. 初始化一个带头结点的空链表
Status InitList_Lk(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}
//2. 销毁一个链表
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
//3. 创建一个链表
//(1) 按向头生长方式生成链表
Status CreateHeadList_Lk(LinkList &L, ElemType a[], int n)
{
	LinkList p;
	int i;
	InitList_Lk(L);			//先初始化单链表L
	for(i=0;i<n;i++)		//将n个元素依次插入到L中，作为第1个结点，这便是向头生长
	{
		p=(LinkList)malloc(sizeof(LNode));	//生成新结点p
		p->data=a[i];
		p->next=L->next;					//p插在头结点的后面，作为第1个元素
		L->next=p;
	}
	return OK;
}
//(2) 按向尾生长方式生成链表
Status CreateTailList_Lk(LinkList &L, ElemType a[], int n)
{
	LinkList p,r;			//指针r始终指向L的尾结点，当前新结点p始终插在r的后面
	int i;
	InitList_Lk(L);
	r=L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));	//生成新结点p
		p->data=a[i];
		r->next=p;							//p插在尾结点r的后面
		r=p;								//现在p是新的尾结点
	}
	return OK;
}
//4. 判断一个链表是否是空表
Status ListEmpty_Lk(LinkList L)
{
	return L->next==NULL ? TRUE : FALSE;
}
//5. 求链表的长度
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
//6. 取第i个结点的元素值，由参数e带回
int GetElem_Lk(LinkList L, int i, ElemType &e)
{
	if(i<=0)			//i值太小，不合法
		return ERROR;
	int n=0;
	LinkList p=L;
	while(n<i && p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	if(n<i)				//i值太大，不合法
		return ERROR;
	e=p->data;
	return OK;
}
//7. 在链表中查找元素e的位置，如果不存在，返回0
int LocateElem_Lk(LinkList L, ElemType e)
{
	int n=1;
	LinkList p=L->next;
	while(p!=NULL)
	{
		if(p->data==e)		//找到了
			return n;		//此时n值就是元素e的位置
		n++;
		p=p->next;
	}
	return 0;				//如果上述循环结束都示找到，则说明e不存在
}
//8. 在链表中返回元素cur_e的前驱元素值，由pre_e带回
Status PriorElem_Lk(LinkList L, ElemType cur_e, ElemType &pre_e);
//9. 在链表中返回元素e的后继元素值
Status NextElem_Lk(LinkList L, ElemType cur_e, ElemType &next_e);
//10. 向链表中第i个位置处插入一个新结点e，如果i值不合法，则插入失败
Status ListInsert_Lk(LinkList &L, int i, ElemType e);
//11. 删除链表中第i个结点，被删除的元素值由e带回，如果i值不合法，则删除失败
Status ListDelete_Lk(LinkList &L, int i, ElemType &e);
//12. 遍历链表
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
//13. 对链表中的结点进行排序
int swap(int *x,int *y){
	int n;
	n = *x;
	*x = *y;
	*y = n;
	return OK;
}
//(1) 选择插入排序
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
//(2) 冒泡排序
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
//(3) 简单选择排序
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

//(4)快速排序
 Status QuickSort_Lk(LinkList head, LinkList end){  
        if(head == NULL || head == end)             //如果头指针为空或者链表为空，直接返回  
            return ERROR;   
        LinkList p = head -> next;                  //用来遍历的指针  
        LinkList small = head;  
        while( p != end){  
            if( p -> data < head -> data){      //对于小于轴的元素放在左边  
                small = small -> next;
				swap(&small->data,&p->data);
            }  	
            p = p -> next;  
        }  
		swap(&small->data,&head->data);
        QuickSort_Lk(head, small);                     //对左右进行递归  
        QuickSort_Lk(small -> next, end);  
		return OK;
    }  
 //(5)归并排序
LinkList sortList(LinkList head) {
    if(head == NULL || head->next == NULL)
        return head;
    else{
        //快慢指针找到中间节点
        LinkList fast = head;
		LinkList slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortList(head);//前半段排序
        slow = sortList(slow);//后半段排序
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
//(6)基数排序
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
			n = GetNum(array,x);//某位的数字
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

