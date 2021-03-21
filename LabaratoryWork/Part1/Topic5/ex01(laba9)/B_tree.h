// CLion
// Created by Foster Grisella on 3/21/21 17:29.
//


#ifndef TEST_B_TREE_H
#define TEST_B_TREE_H
#include <iostream>
#include <string>


//https://habr.com/ru/post/267855/#:~:text=%D0%9E%D0%B1%D1%85%D0%BE%D0%B4%D1%83%20%D0%B2%20%D0%B3%D0%BB%D1%83%D0%B1%D0%B8%D0%BD%D1%83%20%D0%B2%20%D0%B3%D1%80%D0%B0%D1%84%D0%B5,%D0%BF%D0%BE%D1%82%D0%BE%D0%BC%D0%BE%D0%BA%2C%20%D0%BA%D0%BE%D1%80%D0%B5%D0%BD%D1%8C%2C%20%D0%BF%D1%80%D0%B0%D0%B2%D1%8B%D0%B9%20%D0%BF%D0%BE%D1%82%D0%BE%D0%BC%D0%BE%D0%BA.

typedef struct s_node
{
	int				data;
	int				level;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

t_node *init(t_node **parent, int count_nodes, int level);

void printNode(t_node *node, int level);

//Функция печатает значения бинарного дерева поиска в прямом порядке.
void preorder(t_node *root, void (func)(t_node *, int));
// Функция печатает значения бинарного дерева поиска в симметричном порядке.
void inorder(t_node *root, void (func)(t_node *, int));
// Функция печатает значения бинарного дерева поиска в обратном порядке.
void postorder(t_node *root, void (func)(t_node *, int));


// Функция печатает значения бинарного дерева поиска в обратном симметричном порядке.
void reverseInorder(t_node *root, void (func)(t_node *, int));


#endif //TEST_B_TREE_H
