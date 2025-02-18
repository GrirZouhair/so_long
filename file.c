// //1
#include<stdlib.h>

// typedef struct s_list
// {
// 	int value;
// } t_list;

// int main()
// {
// 	t_list game;
// 	game.value = 42;
// 	printf("%d", game.value);
// }


typedef struct s_list
{
	int value;
} t_list;


int main()
{
	t_list *game;

	game = malloc((sizeof(t_list)));
	if (!game)
		return (NULL);
	game->value = 42;
	printf("%d", game->value);
	free(game);
}