#include "op.h"

static int	init_op(char **str, char **start, int *i, t_op *content)
{
	*i = 0;
	*start = NULL;
	content->str = NULL;
	if (!ft_strchr(*str, '(') || !ft_strchr(*str, ')'))
	{
		while (**str)
			(*str)++;
		return (1);
	}
	return (0);
}


static void	process_op(char **str, char **start, int *i)
{	
	while (**str)
	{
		if (**str == '(')
		{
			if (!*start)
				*start = *str;
			(*i)++;
		}
		else if (**str == ')')
			(*i)--;
		if (*i < 0 || (!(*i) && *start))
			break;
		(*str)++;
	}
}

t_list		*op(char **str)
{
	char	*start;
	int	i;
	t_op	content;
	t_list	*tmp;

	if (init_op(str, &start, &i, &content))
		return (NULL);
	process_op(str, &start, &i);
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
