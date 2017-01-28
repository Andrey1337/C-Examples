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

void Push(Queue *queue, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	Node *tail = queue->head;
	if (tail != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
	}

	if (tail == NULL)
		queue->head = node;
	else
		tail->next = node;
}

int Top(Queue *queue)
{
	if (queue->head != NULL)
		return queue->head->value;

	return -1;
}


int Pop(Queue *queue)
{
	if (queue->head == NULL)
		return -1; //!!! Exception?

	Node *item = queue->head;
	queue->head = queue->head->next;
	int num = item->value;
	free(item);
	return num;

}

int Lenght(Queue *queue)
{
	int counter = 0;
	if (queue->head != NULL)
	{
		++counter;
		Node *item = queue->head;
		while (item->next != NULL)
		{
			item = item->next;
			++counter;
		}
	}
	return counter;
}

void QueueDestructor(Queue* queue)
{
	Node* ptr = queue->head;
	if (ptr == NULL)
	{
		free(ptr);
	}
	else
	{
		Node* item = ptr;
		while (ptr->next)
		{
			item = ptr;
			ptr = ptr->next;
			free(item);
		}
		free(ptr);
	}
	free(queue);
}

int main()
{
	Queue *qu = ConstructorQueue();
	Push(qu, 5);
	Push(qu, 10);
	Push(qu, 20);
	printf("%d\n", Lenght(qu));
	printf("%d\n", Pop(qu));
	printf("%d\n", Pop(qu));
	printf("%d\n", Pop(qu));
	QueueDestructor(qu);

	//DestructorQeueu(qu);
	return 0;
}