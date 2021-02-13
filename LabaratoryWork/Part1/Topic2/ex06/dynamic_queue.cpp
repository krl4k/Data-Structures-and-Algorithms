#include "dynamic_queue.h"
#include <queue>
bool isEmpty(t_queue *queue) {
	if (!queue)
		return false;
	if(queue->size == 0)
		return true;
	return false;
}

int size(t_queue *queue) {
	if(queue)
		return (queue->size);
	return 0;
}

void init(t_queue* &queue) {
	queue = new t_queue;
	(queue)->front = new t_node;
	(queue)->back = (queue)->front;
	(queue)->size = 0;
}

void deleteQueue(t_queue *&queue) {
	if(!queue)
		return;
	while (!isEmpty(queue))
		pop(queue);
	if((queue)->back) {
		delete (queue)->back;
		(queue)->back = nullptr;
	}
	delete queue;
	queue = nullptr;
}

t_node *createElem(int data) {
	t_node *newElem = new t_node;
	newElem->data = data;
	newElem->next = nullptr;
	return (newElem);
}

void printQueue(t_queue *queue) {
	std::cout << "------------Queue info-----------------" << std::endl;
	if(!queue || isEmpty(queue))
	{
		std::cout << "Queue is empty!" << std::endl;
		return;
	}
	else
		{
		t_node *tmp = queue->front;
		std::cout << "Queue(first is front) = ";
		while ((tmp)) {
			std::cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		std::cout << '\n';
	}
}

void push(t_queue *&queue, char data) {
	if(!queue) {
		init(queue);
//		std::cout << "Queue is empty!!!" << '\n';
//		return;
	}
	if(0 == (size(queue)))
	{
		if((queue)->back)
		{
			(queue)->front = (queue)->back;
			(queue)->front->data = data;
			(queue)->front->next = nullptr;
			(queue)->size = 1;
		}
		else
			init(queue);

	} else {
		t_node *newElem = createElem(data);
		(queue)->back->next = newElem;
		(queue)->back = (queue)->back->next;
		(queue)->size++;
	}
};

void pop(t_queue *&queue) {
	if(size(queue) > 0) {
		t_node *temp = (queue)->front;
		(queue)->front = (queue)->front->next;
		(queue)->size--;
		if((queue)->size > 0)
			delete temp;
	}
}

char back(t_queue *queue) {
	if(queue && size(queue) >= 0)
		return queue->back->data;
//	std::cout << "back elem not found. Size of queue = 0!" << std::endl;
	return 0;
};

char front(t_queue *queue) {
	if(queue && size(queue) > 0)
		return queue->front->data;
//	std::cout << "front elem not found. Size of queue = 0!" << std::endl;
	return 0;
};

//int main()
//{
//	t_queue *queue = nullptr;
//	init(queue);
//	for (int i = 0; i < 5; i++)
//	{
//		push(queue, (char) ('a' + i));
//	}
//	push(queue, 'w');
//
//	printQueue(queue);
//
//	std::cout << "back = " << back(queue) << std::endl;
//	deleteQueue(queue);
//}
/*
 * original
 */
	//	std::queue<int> queue;
//	queue.push(1);
//	queue.push(2);
//	queue.push(3);
//	queue.pop();
//	queue.pop();
//	queue.pop();
//	queue.push(123);
//	std::cout << queue.back() << std::endl;
//}

