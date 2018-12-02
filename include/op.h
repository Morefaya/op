#ifndef OP_H
# define OP_H

# include <term.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct	s_op
{
	char	*str;
}		t_op;

void	del_s_op(t_op *content, size_t size);

#endif
