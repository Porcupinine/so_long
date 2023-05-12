
#include "../../include/map.h"
#include "libft.h"
#include <stdlib.h>
#include "../../include/utils.h"

int check_valid_list(coordinate *valid_node, int x, int y)
{
    while (valid_node != NULL)
    {
        if (valid_node->y == y && valid_node->x == x)
            return (0);
        valid_node = valid_node->next;
    }
    return (1);
}

static void add_coordinate(coordinate **head, int x, int y, game_map *map)
{
    coordinate *new;
    new = malloc(sizeof (coordinate));
    if(new == NULL)
        ft_error("Error\n new node malloc fail\n");
    new->y = y;
    new->x = x;
    new->next = *head;
    *head = new;
}

static void check_sides(game_map *map, queue *q, int32_t x, int32_t y)
{
    if (map->map[y-1][x] != '1' &&
        check_valid_list(map->valid_coordinates, x, y-1) != 0 &&
        check_queue(q, x, y-1) != 0)
        enqueue(q, x, y-1);
    if (map->map[y][x-1] != '1' &&
        check_valid_list(map->valid_coordinates, x-1, y) != 0 &&
        check_queue(q, x-1, y) != 0)
        enqueue(q, x-1, y);
    if (map->map[y+1][x] != '1' &&
        check_valid_list(map->valid_coordinates, x, y+1) != 0 &&
        check_queue(q, x, y+1) != 0)
        enqueue(q, x, y+1);
}
static void init_valid_coordinates(game_map *map)
{
    map->valid_coordinates = malloc(sizeof (coordinate));
    if(map->valid_coordinates == NULL)
        ft_error("Error\nValid_coordinates malloc fail\n");
    map->valid_coordinates->x = map->player-> x;
    map->valid_coordinates->y = map->player-> y;
    map->valid_coordinates->next = NULL;
}

void map_valid_coordinates(game_map *map)
{
    queue *q;
    int count_y;
    int count_x;

    count_x = map->player->x;
    count_y = map->player->y;
    q = malloc(sizeof (queue));
    if (q == NULL)
        ft_error("Error\nQueue malloc fail\n");
    init_valid_coordinates(map);
    q->head = NULL;
    q->tail = NULL;
    while(count_x < map->width - 1)
    {
        check_sides(map, q, count_x, count_y);
        if (map->map[count_y][count_x+1] != '1' &&
        check_valid_list(map->valid_coordinates, count_x+1, count_y) != 0 &&
                check_queue(q, count_x+1, count_y) != 0)
        {
            add_coordinate(&map->valid_coordinates, count_x+1, count_y, map);
            count_x++;
        }
        else
        {
            if (q->head != NULL)
            {
                count_y = q->head->y;
                count_x = q->head->x;
                dequeue(q);
                add_coordinate(&map->valid_coordinates, count_x, count_y, map);
            }
            else
                break;
        }
    }
}