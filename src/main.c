#include "op.h"

static t_list	*op(char **str)
{
	char	*start;
	int	i;
	t_op	content;
	t_list	*tmp;

	i = 0;
	start = NULL;
	content.str = NULL;
	if (!ft_strchr(*str, '(') || !ft_strchr(*str, ')'))
	{
		while (**str)
			(*str)++;
		return (NULL);
	}
	while (**str)
	{
		if (**str == '(')
		{
			if (!start)
				start = *str;
			i++;
		}
		else if (**str == ')')
			i--;
		if (i < 0 || (!i && start))
			break;
		(*str)++;
	}
	if (i < 0 || !**str)
		return (NULL);
	if (!(content.str = ft_strsub(start + 1, 0, *str - start - 1))
		|| !ft_strlen(content.str))
	{
		free(content.str);
		return (NULL);
	}
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
	{
		del_s_op(&content, sizeof(content));
		return (NULL);
	}
	(*str)++;
	return (tmp);
}

static void	display_s_op(t_list *lst)
{
	char *tmp;

	while (lst)
	{
		tmp = ((t_op*)(lst->content))->str;
		ft_printf("%s", tmp);
		lst = lst->next;
		if (lst)
			ft_printf(" ");
	}
	ft_printf("\n");
}

int		main(int ac, char **av)
{
	t_list	*tmp;
	char	*str;
	t_list	*new;

	tmp = NULL;
	new = NULL;
	if (ac != 2)
	{
		ft_printf("Wrong parameters number! Must be 1!\n");
		return (1);
	}

	str = av[1];
	while ((tmp = op(&str)))
		ft_lstadd(&new, tmp);
	ft_lstrev(&new);
	display_s_op(new);
	ft_lstdel(&new, (void(*)(void*, size_t))del_s_op);
	return (0);
}
