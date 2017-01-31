#include <stdio.h>
#include "targetver.h"

#ifndef MY_HEAD_H
#define MY_HEAD_H

// Queue functions declaration 

typedef struct Queue Queue;

struct Queue* ConstructorQueue();

void Push(Queue *queue, int value);

int Top(Queue *queue);

int Pop(Queue *queue);

int QueueLenght(Queue *queue);

void QueueDestructor(Queue* queue);

// List functions declaration

typedef struct List List;

List* ConstructorList();

void InsertFirst(List *list, int value);

int ListLenght(List *list);

void PrintList(List *list);

#endif 