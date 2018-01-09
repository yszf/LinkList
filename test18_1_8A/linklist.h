#ifndef	_LINKLIST_H_
#define _LINKLIST_H_

typedef int Elem_Type;

typedef struct LNode
{
	Elem_Type data;
	struct LNode* next;
}LNode,*LinkList;

void init_list(LinkList* phead);
void insert_tail(LinkList* phead,Elem_Type val);
void insert_head(LinkList* phead,Elem_Type val);
void remove_node(LinkList* phead,Elem_Type val);
void clear_list(LinkList* phead);
void destroy_list(LinkList* phead);
void show_list(LinkList* phead);
bool is_Empty(LinkList* phead);
int list_size(LinkList* phead);

void printListReversely_iteratively(LinkList phead);
void printListReversely_recursively(LinkList phead);

#endif