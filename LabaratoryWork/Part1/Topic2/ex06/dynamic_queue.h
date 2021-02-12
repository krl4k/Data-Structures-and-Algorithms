#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <iostream>


typedef struct      s_node
{
	int             data;
	struct s_node   *next;
}                   t_node;

typedef struct  s_queue
{
	t_node *front;
	t_node *end;
	int size;
}               t_queue;


void push(t_queue *&queue, int data);
void pop(t_queue *&queue);

void    init(t_queue *&queue);
void    deleteQueue(t_queue *&queue);
void    printQueue(t_queue *queue);
int     size(t_queue *queue);

bool isEmpty(t_queue *queue);

int back(t_queue *queue);
int front(t_queue *queue);


#endif
