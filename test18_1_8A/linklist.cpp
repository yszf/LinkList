#include "linklist.h"
#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

//初始化单链表
void init_list(LinkList* phead)
{
	assert(phead != NULL);
	(*phead) = new LNode;
	(*phead)->next = NULL;
}

//尾插
void insert_tail(LinkList* phead, Elem_Type val)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (NULL == p)
	{
		return;
	}

	while (p->next != NULL)
	{
		p = p->next;
	}

	LNode* newNode = new LNode;
	newNode->data = val;
	newNode->next = NULL;
	p->next = newNode;
}

//头插
void insert_head(LinkList* phead, Elem_Type val)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (NULL == p)
	{
		return;
	}

	LNode* newNode = new LNode;
	newNode->data = val;
	newNode->next = p->next;
	p->next = newNode;
}

//删除结点
void remove_node(LinkList* phead, Elem_Type val)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (NULL == p)
	{
		return;
	}

	LNode* ppre = p;
	LNode* pcur = p->next;
	while (pcur != NULL)
	{
		if (pcur->data == val)
		{
			ppre->next = pcur->next;
			delete pcur;
			pcur = ppre->next;
		}
		else
		{
			ppre = pcur;
			pcur = ppre->next;
		}
	}
}

//清空单链表
void clear_list(LinkList* phead)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (p == NULL)
	{
		return;
	}

	LNode* ptmp = p->next;
	while (ptmp != NULL)
	{
		p = ptmp->next;
		delete ptmp;
		ptmp = p;
	}
	(*phead)->next = NULL;
}

//销毁链表
void destroy_list(LinkList* phead)
{
	assert(phead != NULL);
	LNode* p = *phead;

	LNode* ptmp;
	while (p != NULL)
	{
		ptmp = p->next;
		delete p;
		p = ptmp;
	}
	*phead = NULL;
}

//打印单链表
void show_list(LinkList* phead)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (p == NULL)
	{
		return;
	}

	while (p->next != NULL)
	{
		cout << p->next->data << " ";
		p = p->next;
	}
	cout << endl;
}

//判空
bool is_Empty(LinkList* phead)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (p == NULL)
	{
		return true;
	}
	return p->next == NULL;
}

//单链表的大小
int list_size(LinkList* phead)
{
	assert(phead != NULL);
	LNode* p = *phead;
	if (p == NULL)
	{
		return 0;
	}
	int i = 0;
	while (p->next != NULL)
	{
		++i;
		p = p->next;
	}
	return i;
}

//非递归逆序打印链表
void printListReversely_iteratively(LinkList phead)
{
	assert(phead != NULL);

	stack<LNode*> sta;
	LNode* p = phead->next;
	while (p != NULL)
	{
		sta.push(p);
		p = p->next;
	}

	while (!sta.empty())
	{
		LNode* node = sta.top();
		cout << node->data << " ";
		sta.pop();
	}
	cout << endl;
}

//逆序打印链表
void printList(LNode* p);

//递归逆序打印链表
void printListReversely_recursively(LinkList phead)
{
	assert(phead != NULL);
	printList(phead->next);
}

void printList(LNode* p)
{
	if (p != NULL)
	{
		if (p->next != NULL)
		{
			printList(p->next);
		}
		cout << p->data << " ";
	}
}