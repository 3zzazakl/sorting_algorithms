#include "sort.h"

/**
 * insertion_sort_list - sorting using insertion
 * @list: input list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (!list || !(*list))
		return;

	current = (*list)->next;
	while (current)
	{
		prev_node = current->prev;
		next_node = current->next;

		prev_node->next = next_node;
		if (next_node)
			next_node->prev = prev_node;

		while (prev_node && current->n < prev_node->n)
			prev_node = prev_node->prev;

		if (prev_node)
		{
			current->next = prev_node->next;
			current->prev = prev_node;
			prev_node->next = current;
			if (current->next)
			{
				current->next->prev = current;
			}
		}
		else
		{
			current->next = *list;
			(*list)->prev = current;
			current->prev = NULL;
			*list = current;
		}
		print_list(*list);
		current = next_node;
	}
}
