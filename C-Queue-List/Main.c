#include "MyHeader.h"

int main()
{
	/*Queue *qu = ConstructorQueue();
	Push(qu, 5);
	Push(qu, 10);
	Push(qu, 20);
	printf("%d\n", Lenght(qu));
	printf("%d\n", Pop(qu));
	printf("%d\n", Pop(qu));
	printf("%d\n", Pop(qu));
	QueueDestructor(qu);*/

	List *list = ConstructorList();
	InsertFirst(list, 10);
	InsertFirst(list, 15);
	InsertFirst(list, 30);
	printf("%d\n", ListLenght(list));


	return 0;
}