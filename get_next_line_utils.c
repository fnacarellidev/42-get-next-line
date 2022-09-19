#include "get_next_line.h"

int	has_matching_fd(t_fdstruct *node, int fd)
{
	while (node->next && node->fd != fd)
		node = node->next;
	if (node->fd == fd)
		return (1);
	else
		return (0);
}

void	ft_nodeadd_back(t_fdstruct **head, t_fdstruct *new)
{
	t_fdstruct	*last_node;

	if (head && new)
	{
		if (*head == NULL)
			*head = new;
		else
		{
			last_node = ft_nodelast(*head);
			last_node->next = new;
		}
	}
}

t_fdstruct	*ft_nodelast(t_fdstruct *node)
{
	if (!node)
		return (0);
	while (node->next != 0)
		node = node->next;
	return (node);
}

t_fdstruct	*ft_newnode(int fd)
{
	t_fdstruct	*new_node;

	new_node = malloc(sizeof(t_fdstruct));
	if (!new_node)
		return (0);
	new_node->fd = fd;
	new_node->index_to_search = 0;
	new_node->line = 0;
	new_node->next = NULL;
	return (new_node);
}
