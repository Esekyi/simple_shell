#include "shell.h"

/**
 * add_node - check code structure
 * @head: address to point to head node
 * @str: string field of the node
 * @num: index node
 * Description: adds a node to the start of the list
 * Return: size
 */

list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *head_newNode;

	if (!head)
		return (NULL);
	head_newNode = malloc(sizeof(list_t));

	if (!head_newNode)
		return (NULL);

	fill_mem((void *)head_newNode, 0, sizeof(list_t));
	head_newNode->num = num;

	if (str)
	{
		head_newNode->str = _strdup(str);
		if (!head_newNode->str)
		{
			free(head_newNode);
			return (NULL);
		}
	}

	head_newNode->next = *head;
	*head = head_newNode;

	return (head_newNode);
}


/**
 * add_node_end - check code structure
 * @head: pointer to head, first node of the list
 * @str: string input field of node
 * @num: number index
 * Description: adds a node at the end of a list
 * Return: list size
 */

list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *n_node, *res_node;

	if (!head)
		return (NULL);

	n_node = *head;

	res_node = malloc(sizeof(list_t));

	if (!res_node)
		return (NULL);

	fill_mem((void *)res_node, 0, sizeof(list_t));
	res_node->num = num;

	if (str)
	{
		res_node->str = _strdup(str);
		if (!res_node->str)
		{
			free(res_node);
			return (NULL);
		}
	}

	if (n_node)
	{
		while (n_node->next)
			n_node = n_node->next;
		n_node->next = res_node;
	}
	else
		*head = res_node;

	return (res_node);
}

/**
 * delete_node_at_index - check code structure
 * @head: address of pointer to first node
 * @index: index to delete
 * Description: deletes the node at a given index
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *n_node, *p_node;
	unsigned int itr = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		n_node = *head;
		*head = (*head)->next;

		free(n_node->str);
		free(n_node);

		return (1);
	}
	n_node = *head;

	while (n_node)
	{
		if (itr == index)
		{
			p_node->next = n_node->next;

			free(n_node->str);
			free(n_node);

			return (1);
		}
		itr++;

		p_node = n_node;
		n_node = n_node->next;
	}

	return (0);
}

/**
 * print_list_str - check code structure
 * @head: pointer to head, first node of list
 * Description: prints only the string
 * Return: list size of a list
 */

size_t print_list_str(const list_t *head)
{
	size_t itr = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");

		head = head->next;

		itr++;
	}

	return (itr);
}

/**
 * free_list - check code structure
 * @head_ptr: head pointer
 * Description: frees all nodes
 * Return: Nothing
 */

void free_list(list_t **head_ptr)
{
	list_t *n_node, *p_node, *head;

	if (!head_ptr || !*head_ptr)
		return;

	head = *head_ptr;
	n_node = head;

	while (n_node)
	{
		p_node = n_node->next;
		free(n_node->str);
		free(n_node);

		n_node = p_node;
	}

	*head_ptr = NULL;
}
