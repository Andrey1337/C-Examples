#include <stdio.h>

typedef struct Node {
	int value;
	struct Node* next;
}Node;

typedef struct Queue {
	Node *head;
}Queue;

struct Queue* ConstructorQueue()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->head = NULL;
	return queue;
}

Node* GetTail(Node *node)
{
	if (node != NULL)
	{
		if (node->next == NULL)
		{
			return node;
		}
		GetTail(node->next);
	}
	else
	{
		return NULL;
	}
}

void Push(Queue *queue, int value)
{
	if (queue->head == NULL)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->value = value;
		node->next = NULL;
		queue->head = node;
	}
	else
	{
		Node* tail = GetTail(queue->head);
		Node* node = (Node*)malloc(sizeof(Node));
		node->value = value;
		node->next = NULL;
		tail->next = node;
	}
}

int Top(Queue *queue)
{
	if (queue->head != NULL)
	{
		return queue->head->value;
	}
	return 0;
}

int Pop(Queue *queue)
{
	if (queue->head != NULL)
	{
		if (queue->head->next != NULL)
		{
			int num = queue->head->value;
			queue->head = queue->head->next;
			return num;
		}
		else
		{
			int num = queue->head->value;
			queue->head = NULL;
			return num;
		}
	}
	return 0;
}

int LenghtFromNode(Node *currentNode);

int Lenght(Queue *queue)
{
	return LenghtFromNode(queue->head);
}

int LenghtFromNode(Node *currentNode)
{
	if (currentNode != NULL)
	{
		return 1 + LenghtFromNode(currentNode->next);
	}
	return 0;
}

void DestructorNode(Node *currentNode);

void DestructorQeueu(Queue *queue)
{
	if (queue != NULL)
	{
		DestructorNode(queue->head);
		free(queue);
	}
}

void DestructorNode(Node *currentNode)
{
	if (currentNode != NULL)
	{
		if (currentNode->next != NULL)
		{
			DestructorNode(currentNode->next);
		}
		free(currentNode);
	}
}


int main()
{
	Queue *qu = ConstructorQueue();
	Push(qu, 5);
	Push(qu, 10);
	Push(qu, 20);
	printf("%d\n", Pop(qu));
	printf("%d\n", Top(qu));
	DestructorQeueu(qu);
	return 0;
}