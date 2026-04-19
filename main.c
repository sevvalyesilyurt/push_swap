#include "includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_ps	push_swap;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);// bu kesin değil ekleme yapılabilir
	parser_main(&push_swap.a, argc, argv);
	return (0);
}
