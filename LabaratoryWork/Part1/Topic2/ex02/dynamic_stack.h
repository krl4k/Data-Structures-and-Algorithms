#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

/*
 * functuons protected
 * does not segfault
 * no leaks
 * when trying to delete when the stack is already empty.
 */

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack {
	t_node	*top;
	int		size;
}				t_stack;

void	init(t_stack **stack);

//return value of top elem
int		top(t_stack *stack);
bool	isEmpty(t_stack *stack);
int		size(t_stack *top);

void	push(t_stack **stack, int data);
void	pop(t_stack **stack);

void	printStack(t_stack *stack);
void	clear(t_stack **stack);

#endif