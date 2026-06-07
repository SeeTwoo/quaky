#include <stdlib.h>

#include "quaky.h"

int	parse_map(struct s_quaky *game);

/*
 *
 * frees are going to be hideous on this one
 *
 *
 */

int	init(struct s_quaky *game)
{
	game->map = malloc(sizeof(char *) * 64);
	if (!game->map)
		return 1;
	game->map[0] = malloc(sizeof(char) * 64);
	return 0;
}

int	main()
{
	struct s_quaky	game;

	if (init(&game) == 1)
		return 1;
	if (parse_map(&game) == 1)
		return 1;

	return 0;
}
