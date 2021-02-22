#include "dynamic_queue.h"
#include <queue>

bool isEmpty(t_queue *queue) {
    if (!queue)
        return false;
    if (queue->size == 0)
        return true;
    return false;
}

int size(t_queue *queue) {
    if (queue)
        return (queue->size);
    return 0;
}

void init(t_queue *&queue) {
    if (!queue)
        queue = new t_queue;
    (queue)->front = new t_node;
    (queue)->back = (queue)->front;
    (queue)->size = 0;
}

void deleteQueue(t_queue *&queue) {
    if (!queue)
        return;
    while (queue->size) {
        t_node *temp;
        temp = queue->front->next;
        delete queue->front;
        queue->front = temp;
        queue->size--;
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
    if (!queue || isEmpty(queue)) {
        std::cout << "Queue is empty!" << std::endl;
    } else {
        t_node *tmp = queue->front;
        std::cout << "Queue(first is front) = ";
        for (int i = 0; i < queue->size && tmp; ++i) {
            std::cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        std::cout << '\n';
    }
    std::cout << "---------------------------------------" << std::endl;
}

void push(t_queue *&queue, char data) {
    if (!queue) {
        init(queue);
//        std::cout << "Queue is empty!!!" << '\n';
//        return;
    }
    if (0 == (size(queue))) {
        if ((queue)->back) {
//            printf("tut!\n");
            (queue)->front = (queue)->back;
            (queue)->front->data = data;
            (queue)->size = 1;
        }
    } else {
        t_node *newElem = createElem(data);
        (queue)->back->next = newElem;
        (queue)->back = (queue)->back->next;
        (queue)->back->next = queue->front;
        (queue)->size++;
    }
};

/*
void pop(t_queue *&queue) {
	if(size(queue) > 0) {
		t_node *temp = (queue)->front;
		(queue)->front = (queue)->front->next;
		(queue)->size--;
		if((queue)->size > 0)
			delete temp;
	}
}*/

void pop(t_queue *&queue) {
    if (size(queue) > 0) {
        t_node *temp = (queue)->front;
        queue->front = queue->front->next;
        if (queue->size > 1) {
            delete temp;
            temp = nullptr;
        }
        (queue)->size--;
    }
}

char back(t_queue *queue) {
    if (queue && size(queue) >= 0)
        return queue->back->data;
    return 0;
};

char front(t_queue *queue) {
    if (queue && size(queue) > 0)
        return queue->front->data;
    return 0;
};
/*
int main() {
    t_queue *queue = nullptr;
//    init(queue);
    for (int i = 0; i < 5; i++) {
        push(queue, (char) ('a' + i));
    }
    printQueue(queue);

    for (int i = 0; i < 10; ++i) {
        pop(queue);
    }
    printQueue(queue);
    std::cout << "back = " << back(queue) << std::endl;
    std::cout << "front = " << front(queue) << std::endl;

    for (int i = 0; i < 5; i++) {
        push(queue, (char) ('j' + i));
    }
    printQueue(queue);
    pop(queue);
    printQueue(queue);
    std::cout << "back = " << back(queue) << std::endl;
    std::cout << "front = " << front(queue) << std::endl;

    deleteQueue(queue);
    push(queue, 'A');
    printQueue(queue);
    std::cout << "back = " << back(queue) << std::endl;
    std::cout << "front = " << front(queue) << std::endl;
}*/
///*
// * original
// */
//		std::queue<int> queue;
//	queue.push(1);
//	queue.push(2);
//	queue.push(3);
//	queue.pop();
//	queue.pop();
//	queue.pop();
//	queue.push(123);
//	std::cout << queue.back() << std::endl;
//}

