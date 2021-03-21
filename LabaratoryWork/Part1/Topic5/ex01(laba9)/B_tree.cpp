// CLion
// Created by Foster Grisella on 3/21/21 17:29.
//

#include "B_tree.h"

t_node *init(t_node **parent, int count_nodes, int level)
{
	t_node *current;
	static int x = 0;
	int count_l;
	int count_r;

	current = *parent;
	if (count_nodes == 0)
	{
		*parent = nullptr;
	}
	else
	{
		count_l = count_nodes / 2;
		count_r = count_nodes - count_l - 1;
//		std::cin >> x;
//		x = std::rand() % 100;
		std::cout << "x = " << x << std::endl;
		current = new t_node;
		current->data = x++;
		current->level = level;
		init(&(current->left), count_l, level + 1);
		init(&(current->right), count_r, level + 1);
		*parent = current;
	}
	return *parent;
}

void printNode(t_node *node, int level)
{
	for (int i = 0; i < node->level; ++i) {
		std::cout << "     ";
	}
//	std::cout << "node value = " << node->data << ", level = " << node->level << "\n";
	std::cout << node->data << std::endl;
}

void preorder(t_node *root, void (func)(t_node *, int))
{
	if (root == nullptr)   // Базовый случай
	{
		return;
	}
	func(root, 0);
	preorder(root->left, func);   //рекурсивный вызов левого поддерева
	preorder(root->right, func);  //рекурсивный вызов правого поддерева
}

void inorder(t_node *root, void (func)(t_node *, int))
{
	if (root == nullptr)   // Базовый случай
	{
		return;
	}
	inorder(root->left, func);   //рекурсивный вызов левого поддерева
	func(root, 0);
	inorder(root->right, func);  //рекурсивный вызов правого поддерева
}

void reverseInorder(t_node *root, void (func)(t_node *, int))
{
	if (root == nullptr)   // Базовый случай
	{
		return;
	}
	reverseInorder(root->right, func);  //рекурсивный вызов правого поддерева
	func(root, 0);
	reverseInorder(root->left, func);   //рекурсивный вызов левого поддерева
}

void postorder(t_node *root, void (func)(t_node *, int))
{
	if (root == nullptr)   // Базовый случай
	{
		return;
	}
	postorder(root->left, func);   //рекурсивный вызов левого поддерева
	postorder(root->right, func);  //рекурсивный вызов правого поддерева
	func(root, 0);
}

