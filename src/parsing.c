#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include "quaky.h"

int	parse_map(struct s_quaky *game)
{
	int		fd = open("map.qke", O_RDONLY);
	char	c;
	uint8_t	i = 0;
	uint8_t	j = 0;

	if (fd == -1)
		return puts("could not open map file \"map.qke\""), 1;
	while (read(fd, &c, 1)) {
		switch (c) {
			case '\n':
				game->map[j][i] = '\0';
				i = 0;
				j++;
				game->map[j] = malloc(sizeof(char) * 64);
				break ;
			case '0':
				game->map[j][i] = c;
				i++;
				break ;
			case '1':
				game->map[j][i] = c;
				i++;
				break ;
			default :
				close(fd);
				return 1;
		}
	}
	game->map[j + 1] = NULL;
	close(fd);
	return 0;
}
