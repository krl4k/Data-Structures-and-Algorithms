#include "dynamic_queue.h"

bool isEmpty(t_queue *queue) {
	//	if(!queue->front)
	//		return true;
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
//	(queue)->front->data = da;
//	(queue)->front->next = nullptr;
	(queue)->end = (queue)->front;
	(queue)->size = 0;
	/*(*queue)->front = new t_list;
	(*queue)->front->data = data;
	(*queue)->front->next = nullptr;
	(*queue)->end = (*queue)->front;
	(*queue)->size = 1;
*/}

void deleteQueue(t_queue *&queue) {
	if(!queue)
		return;
	while (!isEmpty(queue))
		pop(queue);
	if((queue)->end) {
		delete (queue)->end;
		(queue)->end = nullptr;
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
	if(!queue)
		return;
	if(!isEmpty(queue)) {
		t_node *tmp = queue->front;
		std::cout << "Queue(first is front) = ";
		while ((tmp)) {
			std::cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		std::cout << '\n';
	}
}

void push(t_queue *&queue, int data) {
	if(!(queue)) {
		init(queue);
//		std::cout << "Something went wrong, data = " << data << " not added!!!" << '\n';
//		return;
	}
	if(0 == (size(queue))) {
		if((queue)->end) {
			(queue)->front = (queue)->end;
			(queue)->front->data = data;
			(queue)->front->next = nullptr;
			//	(*queue)->end = (*queue)->front;
			(queue)->size = 1;
			std::cout << "size 0 end found" << '\n';
		}
		else
			init(queue);

	} else {
		t_node *newElem = createElem(data);
		(queue)->end->next = newElem;
		(queue)->end = (queue)->end->next;
		(queue)->size++;
	}
};

void pop(t_queue *&queue) {
	//	if (!*queue)
	//		return;
	if(size(queue) > 0) {
		t_node *temp = (queue)->front;
		(queue)->front = (queue)->front->next;
		(queue)->size--;
		if((queue)->size > 0)
			delete temp;
	}
}

int back(t_queue *queue) {
	if(queue && size(queue) >= 0)
		return queue->end->data;
	std::cout << "back elem not found. Size of queue = 0!" << std::endl;
	return 0;
};

int front(t_queue *queue) {
	if(queue && size(queue) > 0)
		return queue->front->data;
	std::cout << "front elem not found. Size of queue = 0!" << std::endl;
	return 0;
};


int main()
{
	t_queue *queue = nullptr;
	for (int i = 0; i < 5; i++)
	{
		push(queue, i);
	}
	printQueue(queue);
}

