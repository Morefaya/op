#include "op.h"

static t_list	*op(char *str)
{
	char	*start;
	int	i;
	t_op	content;
	t_list	*tmp;

	i = 0;
	start = NULL;
	if (!ft_strchr(str, '(') || !ft_strchr(str, ')'))
		return (NULL);
	while (*str)
	{
		if (*str == '(')
		{
			if (!start)
				start = str;
			i++;
		}
		else if (*str == ')')
			i--;
		if (i < 0 || (!i && start))
			break;
		str++;
	}
	if (i < 0 || !*str)
		return (NULL);
	content.str = ft_strsub(start + 1, 0, str - start - 1);
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
	{
		del_s_op(&content, sizeof(content));
		return (NULL);
	}
	return (tmp);
}

/*static t_list	*compute(char *str)
{
	t_list	*tmp;
	t_list	*result;
	

	while (*str)
	{
		if (*str == '(')
		{
			
		}
		str++;
	}
}*/

static void	display_s_op(t_list *lst)
{
	char *tmp;

	while (lst)
	{
		tmp = ((t_op*)(lst->content))->str;
		ft_printf("%s\n", tmp);
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	t_list	*tmp;

	if (ac != 2)
	{
		ft_printf("Wrong parameters number! Must be 1!\n");
		return (1);
	}

	tmp = op(av[1]);
	ft_printf("%x\n", tmp);
	display_s_op(tmp);
	/*ft_printf("%x/%x\n", av[1], ft_strrchr(av[1], '1'));
	return (ft_strrchr(av[1], '1') - av[1]);*/
}
