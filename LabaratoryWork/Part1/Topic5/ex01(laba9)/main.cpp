// CLion
// Created by Foster Grisella on 3/21/21 17:32.
//

#include <iostream>
#include "B_tree.h"

int main()
{
	srand(time(0));

	t_node *bTree = nullptr;
	int count;
	std::cout << "enter a count of nodes: " << std::endl;
	std::cin >> count;
	init(&bTree, count, 0);

	std::cout << "-----Вывод в прямом порядке------------" << std::endl;
	preorder(bTree, printNode);
	std::cout << "-----------------" << std::endl;
	std::cout << "----вывод в симметричном порядке-------------" << std::endl;
	inorder(bTree, printNode);
	std::cout << "--------------------" << std::endl;
	std::cout << "-------вывод в обратном порядке-------------" << std::endl;
	postorder(bTree, printNode);
	std::cout << "---вывод в обратно-симметричном порядке--------------" << std::endl;
	reverseInorder(bTree, printNode);
	std::cout << "-----------------" << std::endl;

}

