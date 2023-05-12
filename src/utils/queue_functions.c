#include "../../include/map.h"
#include <stdlib.h>
#include "libft.h"

void enqueue (queue *q, int x, int y)
{
    coordinate *new;
    new = malloc(sizeof(coordinate));
    if (new == NULL)
        ft_error("Error\n New node malloc fail\n");
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
        q->tail = NULL;
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
