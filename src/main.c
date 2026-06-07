#include <stdlib.h>
#include <stdio.h>

#include "quaky.h"

int	parse_map(struct s_quaky *game);

/*
 *
 * frees are going to be hideous on this one
 *
 *
 */

void	display_map(char **map)
{
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
}

int	init(struct s_quaky *game)
{
	game->map.map = malloc(sizeof(char *) * 8);
	if (!(game->map.map))
		return 1;
	game->map.map[0] = malloc(sizeof(char) * 8);
	if (!(game->map.map[0]))
		return 1;
	game->map.lines = 7;
	return 0;
}

int	main()
{
	struct s_quaky	game;

	if (init(&game) == 1)
		return 1;
	if (parse_map(&game) == 1)
		return 1;
	display_map(game.map);
	return 0;
}
