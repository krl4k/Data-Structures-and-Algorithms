#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

/*
 * functuons protected
 * does not segfault
 * no leaks
 * when trying to delete when the stack is already empty.
 */
#include "B_tree.h"


typedef struct		s_node
{
	t_t_node		*data;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack {
	t_node	*top;
	int		size;
}				t_stack;

void	init(t_stack **stack);

//return value of top elem
t_t_node *top(t_stack *stack);
bool	isEmpty(t_stack *stack);
int		size(t_stack *top);

void	push(t_stack **stack, t_t_node *node);
void	pop(t_stack **stack);

void	printStack(t_stack *stack);
void	clear(t_stack **stack);

#endif