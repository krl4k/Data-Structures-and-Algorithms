// CLion
// Created by Foster Grisella on 3/21/21 21:01.
//


#include "../ex01(laba9)/B_tree.h"
int main()
{
	srand(time(0));

	t_t_node *bTree = nullptr;
	int count;
	std::cout << "enter a count of nodes: " << std::endl;
	std::cin >> count;
	init(&bTree, count, 0);

	std::cout << "----вывод в симметричном порядке(recursive)-------------" << std::endl;
	inorder(bTree, printNode);
	std::cout << "--------------------" << std::endl;

	std::cout << "----вывод в симметричном порядке(recursive)-------------" << std::endl;
	inorderIterative(bTree, printNode);
	std::cout << "--------------------" << std::endl;

}