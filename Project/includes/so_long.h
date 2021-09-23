/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:33:13 by fbonini-          #+#    #+#             */
/*   Updated: 2021/09/14 15:58:26 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"
# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define A 97
# define W 119
# define S 115
# define D 100
# define ESC 65307
# define TOTAL_ACTIONS 5
# define MOVEMENTS 4
# define YELLOW 16766720

typedef int	(*t_funct)();

typedef struct s_key
{
	int	key[TOTAL_ACTIONS];
}			t_key;

typedef struct s_actions
{
	t_funct	function[TOTAL_ACTIONS];
}			t_actions;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_server
{
	void	*mlx;
	void	*win;
}			t_server;

typedef struct s_map
{
	t_image		wall;
	t_image		floor;
	int			line;
	int			col;
	size_t		col_numb;
	size_t		line_size;
	int			w_tag;
	int			f_tag;
}			t_map;

typedef struct s_player
{
	t_image	img;
	int		posx;
	int		posy;
	char	tag;
}			t_player;

typedef struct s_item
{
	struct s_item	*next;
	struct s_item	*prev;
	t_image			img;
	int				posx;
	int				posy;
}			t_item;

typedef struct s_item_list
{
	t_item			*first;
	t_item			*last;
	unsigned int	total;
	char			i_tag;
}			t_item_list;

typedef struct s_enemy
{
	struct s_enemy	*next;
	struct s_enemy	*prev;
	t_image			img;
	int				posx;
	int				posy;
	int				check;
	char			e_tag;
}			t_enemy;

typedef struct s_enemy_list
{
	t_enemy			*first;
	t_enemy			*last;
	unsigned int	total;
}			t_enemy_list;

typedef struct s_gate
{
	t_image			img;
	int				posx;
	int				posy;
	char			tag;
}			t_gate;

typedef struct s_mem
{
	t_player		*player;
	t_item_list		*item_list;
	t_enemy_list	*enemy_list;
	t_gate			*gate;
	t_image			*win_img;
	t_map			*map;
	t_server		*server;
	t_key			*keys;
	t_actions		*actions;
	char			**design_map;
	int				moves;
	int				frames;
	int				ani_player;
}			t_mem;

int				ft_check_extension(char *file, char *ext);
int				ft_strncmp(const char *str1, const char *str2, size_t len);
void			ft_putstr_fd(char *s, int fd);

void			ft_struct_memmory(t_mem *game_memory);
t_player		*ft_alloc_player(t_mem *mem);
t_item_list		*ft_alloc_item_list(t_mem *mem);
t_enemy_list	*ft_alloc_enemy_list(t_mem *mem);
t_gate			*ft_alloc_exit_gate(t_mem *mem);
t_image			*ft_alloc_image(t_mem *mem);
t_map			*ft_alloc_map(t_mem *mem);
t_server		*ft_alloc_server(t_mem *mem);

t_key			*ft_alloc_keys(t_mem *mem);
void			ft_get_keys(int *keys);

t_actions		*ft_alloc_actions(t_mem *mem);
void			ft_get_actions(t_funct *function);

int				ft_open_file(t_mem *mem, char **argv);
void			ft_read_file(int fd, t_mem *mem);
void			ft_alloc_mapdesign(t_mem *game_memory);

void			ft_read_map(t_mem *mem, char **argv);
void			ft_read_design(int fd, t_mem *mem);

void			ft_map_check(t_mem *mem);
void			ft_wall_check(t_mem *mem, size_t col, size_t line);
void			ft_check_element(t_mem *mem, char tag, int *x, int *y);
void			ft_list_check(t_mem *mem);
void			ft_fill_item_list(t_mem *mem, int i, int j);
t_item			*ft_alloc_item(t_mem *mem, int i, int j);
void			ft_fill_enemy_list(t_mem *mem, int i, int j, char tag);
t_enemy			*ft_alloc_enemy(t_mem *mem, int i, int j, char tag);
void			ft_error_map(t_mem *mem, int check);

int				ft_game_start(t_mem *mem);
void			ft_init_setup(t_mem *mem, int hori_size, int vert_size);
void			ft_get_game_image(t_mem *mem);
void			ft_loop_game(t_mem *mem);

t_image			ft_load_image(t_mem *mem, void *mlx, char *path);
void			ft_load_item_image(t_item *item, t_mem *mem);
void			ft_load_enemy_image(t_enemy *enemy, t_mem *mem);

void			ft_loop_game(t_mem *mem);
int				ft_render_next_frame(t_mem *mem);
void			ft_put_img(t_mem *mem, void *img, int posY, int posX);
void			ft_print_map(t_mem *mem);

int				ft_item_animation(t_item_list *list, t_mem *mem);
void			ft_load_item_right(t_item *item, t_mem *mem);
void			ft_load_item_left(t_item *item, t_mem *mem);
void			ft_load_item_mid(t_item *item, t_mem *mem);
int				ft_put_item_image(t_item *item, t_mem *mem);

void			ft_enemy_movement(t_mem *mem, t_enemy *enemy);
void			ft_movement_v(t_mem *mem, t_enemy *enemy);
void			ft_movement_h(t_mem *mem, t_enemy *enemy);
int				ft_put_enemy_image(t_enemy *enemy, t_mem *mem);

void			ft_print_total_moves(int moves, t_mem *mem);
char			*ft_itoa(int n);
int				ft_numblen(int numb);

int				ft_key_hook(int key, t_mem *mem);
int				ft_valid_key(t_mem *mem, int key);

char			ft_check_future_space(t_mem *mem, int key, int x, int y);

int				ft_player_action(int (*funct)(), t_mem *mem, char space);

int				ft_move_up(t_mem *mem);
int				ft_move_down(t_mem *mem);
int				ft_move_right(t_mem *mem);
int				ft_move_left(t_mem *mem);

int				ft_player_animation(t_mem *mem, int (*funct)());
int				ft_player_ani_up(t_mem *mem);
int				ft_player_ani_right(t_mem *mem);
int				ft_player_ani_left(t_mem *mem);
int				ft_player_ani_down(t_mem *mem);

void			ft_collect_item(t_mem *mem, t_item_list *list);
t_item			*ft_get_item_pos(t_item *item, t_item_list *list, int x, int y);

void			ft_check_exit(t_mem *mem, unsigned int items);

int				ft_end_game(t_mem *mem);

void			ft_destroy_game(t_mem *mem);
void			ft_dstr_item(t_mem *mem, t_item_list *list, t_item *get_item);
void			ft_dstr_enemy(t_mem *mem, t_enemy_list *list, t_enemy *enemy);

void			ft_free_game(t_mem *mem);
void			ft_free_map_design(t_mem *mem);

#endif