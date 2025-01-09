#include "controller.h"

void	ft_start_game(const char *path_file)
{
	t_game	*game;

//	init_structs(game);
	game->mlx = NULL;
	ft_create_window(&game); // retornar mlx
	game->render = ft_render(path_file, game->mlx);
	//ft_write_map_to_window(game->mlx, game->render);
	mlx_key_hook(game->mlx, (mlx_keyfunc)ft_close_window, &game);
	mlx_loop(game->mlx);
}
