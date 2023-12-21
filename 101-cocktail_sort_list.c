#include "sort.h"
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - This swaps a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: pointer to the head of a doubly-linked
 * list of integers.
 * @tail: A pointer to the tail of the
 * doubly-linked list.
 * @shaker: pointer to the current swapping node of the
 * cocktail shaker algo
 *
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpo = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpo;
	else
		*list = tmpo;
	tmpo->prev = (*shaker)->prev;
	(*shaker)->next = tmpo->next;
	if (tmpo->next != NULL)
		tmpo->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpo;
	tmpo->next = *shaker;
	*shaker = tmpo;
}

/**
 * swap_node_behind - This swaps a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: pointer to the head of a doubly-linked
 * list of integers.
 * @tail: A pointer to the tail of the
 * doubly-linked list.
 * @shaker: A pointer to the current swapping node of the
 * cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpo = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpo;
	else
		*tail = tmpo;
	tmpo->next = (*shaker)->next;
	(*shaker)->prev = tmpo->prev;
	if (tmpo->prev != NULL)
		tmpo->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpo;
	tmpo->prev = *shaker;
	*shaker = tmpo;
}

/**
 * cocktail_sort_list - This sorts a listint_t doubly-linked list of integers
 * in ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of
 * a listint_t doubly-linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
