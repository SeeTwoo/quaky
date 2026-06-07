#ifndef QUAKY_H
#define QUAKY_H

#include <stdint.h>

struct s_player {
	double	x;
	double	y;
	uint8_t	angle;
};

struct s_map {
	char	**map;
	uint8_t	lines;
};

struct s_quaky {
	struct s_map	map;
	struct s_player	player;
};

#endif
