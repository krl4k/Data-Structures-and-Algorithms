#include "Queue.h"
#include <iostream>

void init(t_queue **queue)
{
	*queue = new t_queue;
	(*queue)->size = 0;
	(*queue)->front = -1;
	(*queue)->end = -1;
}

bool isEmpty(t_queue *queue)
{
	if (queue->front == -1)
		return true;
	return false;
}

bool isFull(t_queue *queue)
{
	if (queue->front == queue->end + 1)//если конец перед началом(замкнулась)
		return true;
	if (queue->front && queue->end == SIZE - 1)
		return true;
	return false;
}

void push(t_queue *queue, int data)
{
	if (isFull(queue))
	{
		std::cout << "Queue is full!" << std::endl;
		return;
	}
	if (isEmpty(queue))
	{
		queue->front = 0;
		queue->end = 0;
		queue->queue[queue->end] = data;
	} else
	{
//		if (queue->front == -1)
//			queue->front = 0;
		queue->end = (queue->end + 1) % SIZE;
		queue->queue[queue->end] = data;
	}
	printf("added %d\n", queue->queue[queue->end]);
}

void pop(t_queue *queue)
{
	if (isEmpty(queue))
	{
		std::cout << "Queue is empty!" << std::endl;
		return;
	} else
	{
		if (queue->front == queue->end)
		{
			queue->front = -1;
			queue->end = -1;
		} else
		{
			queue->front = (queue->front + 1) % SIZE;
		}
	}
}

void printQueue(t_queue *queue)
{
	if (isEmpty(queue))
	{
		std::cout << "Queue is empty!" << std::endl;
		return;
	}
	std::cout << "Queue: " << std::endl;
	int i;
	for (i = queue->front; i != queue->end; i = (i + 1) % SIZE)
	{
		std::cout << queue->queue[i] << std::endl;
	}
	std::cout << queue->queue[i] << std::endl;
}

void deleteQueue(t_queue **queue);

int size(t_queue *queue);
//int back(t_queue *queue);


int main()
{
	t_queue *queue = nullptr;

	init(&queue);
	for (int i = 0; i < 4; i++)
	{
		printf("i = %d\n", i);
		push(queue, i);
	}

	printQueue(queue);
//	if (queue)
//		printf("qq[%d] = %d\n",3 , queue->queue[3]);
//	else
//		printf("queue null!\n");
//	for (int i = 0; i < 3; i++)
//	{
//		printf("qq[%d] = %d\n",i , queue->queue[i]);
//	}
//	printQueue(queue);
}
