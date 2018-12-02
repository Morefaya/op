#include "op.h"

void	del_s_op(t_op *op, size_t size)
{
	free(op->str);
	ft_bzero(op, size);
	free(op);
}
