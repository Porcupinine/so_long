
#include "../../include/map.h"
#include "libft.h"
#include <stdlib.h>

void enqueue (queue *q, int x, int y)
{
    coordinate *new;
    new = malloc(sizeof(coordinate));
    if (new == NULL)
        ft_error("Malloc fail\n");
    new->y = y;
    new->x = x;
    new->next = NULL;
    if(q->tail != NULL)
        q->tail->next = new;
    q->tail = new;
    if(q->head == NULL)
        q->head = new;
}

void dequeue (queue *q)
{
    if (q->head == NULL)
        return ;
    coordinate *temp;
    temp = q->head;
    q->head = q->head->next;
    free (temp);
    if(q->head == NULL)
        q->tail == NULL;

}

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

int check_queue(queue *q, int x, int y)
{
    coordinate *c;

    c = q->head;
    while(c!= NULL)
    {
        if (c->x == x && c->y == y)
            return(0);
        c = c->next;
    }
    return (1);
}

void add_coordinate(coordinate **head, int x, int y)
{
    coordinate *new;
    new = malloc(sizeof (coordinate));
    if(new == NULL)
        ft_error("Malloc fail\n");
    new->y = y;
    new->x = x;
    new->next = *head;
    *head = new;
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
        ft_error("Malloc fail\n");
    map->valid_coordinates = malloc(sizeof (coordinate));
    if(map->valid_coordinates == NULL)
        ft_error("Malloc fail\n");
    map->valid_coordinates->x = map->player-> x;
    map->valid_coordinates->y = map->player-> y;
    map->valid_coordinates->next = NULL;
    q->head = NULL;
    q->tail = NULL;
    while(count_x < map->width - 1)
    {
        if (map->map[count_y-1][count_x] != '1' &&
        check_valid_list(map->valid_coordinates, count_x, count_y-1) != 0 &&
                check_queue(q, count_x, count_y-1) != 0)
            enqueue(q, count_x, count_y-1);
        if (map->map[count_y][count_x-1] != '1' &&
        check_valid_list(map->valid_coordinates, count_x-1, count_y) != 0 &&
                check_queue(q, count_x-1, count_y) != 0)
            enqueue(q, count_x-1, count_y);
        if (map->map[count_y+1][count_x] != '1' &&
        check_valid_list(map->valid_coordinates, count_x, count_y+1) != 0 &&
                check_queue(q, count_x, count_y+1) != 0)
            enqueue(q, count_x, count_y+1);
        if (map->map[count_y][count_x+1] != '1' &&
        check_valid_list(map->valid_coordinates, count_x+1, count_y) != 0 &&
        check_queue(q, count_x+1, count_y) != 0)
        {
            add_coordinate(&map->valid_coordinates, count_x+1, count_y);
            print_valid_coordinates(map);
            print_queue(q);
            count_x++;
        }
        else if (map->map[count_y][count_x+1] == '1' ||
        check_valid_list(map->valid_coordinates, count_x+1, count_y) == 1 ||
                check_queue(q, count_x+1, count_y) == 1)
        {
            if (q != NULL)
            {
                count_y = q->head->y;
                count_x = q->head->x;
                dequeue(q);
            }
            else
                break;
        }
    }

}