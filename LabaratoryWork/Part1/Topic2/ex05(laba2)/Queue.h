#ifndef QUEUE_H
#define QUEUE_H
#define SIZE 4

typedef struct s_queue
{
	int queue[SIZE];
	int front;
	int end;
	int size;
} t_queue;



void init(t_queue **queue);
void deleteQueue(t_queue **queue);
int size(t_queue *queue);
bool isEmpty(t_queue *queue);
bool isFull(t_queue *queue);
void push(t_queue *queue, int data);
int pop(t_queue *queue);
//int back(t_queue *queue);
int front(t_queue *queue);

void printQueue(t_queue *queue);




#endif