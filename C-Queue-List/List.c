#include "MyHeader.h"

typedef struct Node {
	int value;
	struct Node *next;
}Node;

typedef struct List {
	Node *head;
	Node *tail;
}List;

List* ConstructorList()
{
	List* list = (List *)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void InsertFirst(List *list, int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->next = list->head;
	if (list->tail == NULL)
	{
		list->tail = node;
	}
	list->head = node;
}

int ListLenght(List *list)
{
	Node *item = list->head;
	int counter;
	while (item != NULL)
	{
		item = item->next;
		counter++;
	}
}

void PrintList(List *list)
{
	printf("[_");
	Node *node = list->head;
	while (node != NULL)
	{
		printf("%d_", node->value);
		node = node->next;
	}
	printf("]\n");
}