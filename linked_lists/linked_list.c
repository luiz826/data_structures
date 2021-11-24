/*
    author: Luiz Fernando Costa dos Santos
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//////////////////////////////////////////funcs//////////////////////////////////////////////////////////////// 
void change_element(struct node **l, int old, int new_)
{
    struct node *aux;

    if (is_empty(*l))
    {
        printf("\nThe list is empty.\n");
        return ;
    }

    if (find_element(*l, old) == -1)
    {
        printf("\nThe element isn't in the list.\n");   
        return ; 
    } 
    for (aux = *l; aux->next; aux = aux = aux->next)
    {
        if (aux->data == old)
        {
            aux->data = new_;
            return ;
        }
    }
}

int find_element(struct node *l, int value)
{
    struct node *aux;
    int i = 0;

    if (is_empty(l))
    {
        printf("\nThe list is empty.\n");
        return -1;
    }

    for (aux = l; aux->next; aux = aux = aux->next)
    {
        if (aux->data == value)
        {
            return i;
        }
        i++;
    }

    return -1;
}

void clean_list(struct node **l)
{
    struct node *aux;
    int c = 1; 

    if (is_empty(*l))
    {
        printf("\nThe list is already empty.\n");
        return ;
    }

    for (aux = *l; aux->next; aux = aux->next)
    {
        c++;
    }

    for (int i=0; i<c; i++)
    {
        remove_beg(l);
    }

}

struct node* create_list(void)
{
    return NULL;
}

void insert_beg(struct node **l, int value)
{
    struct node *new;
    
    // allocating
    new = (struct node *)malloc(sizeof(struct node));

    // checking
    if (!new) 
    {
        printf("\nThis value wasn't allocated.\n");
        return ;    
    }

    // inserting
    new->data = value;
    new->next = *l;
    *l = new;
}

void insert_end(struct node **l, int value)
{
    struct node *aux, *new;

    // allocating
    new = (struct node *)malloc(sizeof(struct node));

    // checking
    if (!new) 
    {
        printf("\nThis value wasn't allocated.\n");
        return ;    
    }

    // inserting    
    new->data = value;
    new->next = NULL;

    // inserting in the list
    if (is_empty(*l))
    {
        *l = new;
    } else 
    {
        for (aux = *l; aux->next; aux = aux->next); // the aux is going to pass-through all the list and stop in the end
        aux->next = new; // The next space, before the end, is gonna receive the new value, inserted up there
    }   
}

int is_empty(struct node *l)
{
    if (l == NULL) // l only is NULL when the list is empty
    {
        return 1;
    } else 
    {
        return 0;
    }

}

void print_list(struct node *l)
{
    struct node *aux;
    printf("\n[");
    for (aux = l; aux != NULL; aux = aux->next)
    {
        printf(" %d ", aux->data);
    }
    printf("]\n");
}

void remove_beg(struct node **l)
{
    if (is_empty(*l))
    {
        printf("\nThe list is empty.\n");
        return ;
    }
    struct node *aux;
    aux = *l; // aux is equal to l (this is for free the memory)

    *l = aux->next; // l starts to point to the next value 

    free(aux);
}

void remove_end(struct node **l)
{
    if (is_empty(*l))
    {
        printf("\nThe list is empty.\n");
        return ;
    } 

    struct node *aux, *p;
    aux = *l;

    if (aux->next == NULL) // if the list have only one element, remove from the beginning
    {
        remove_beg(l);
        return ;
    }

    for (aux; aux->next; aux = aux->next) // aux is going to receive the last value
    {
        p = aux; // p is going to receive the last but one value 
    }

    p->next = NULL; // the list end in the p, and the aux becomes trash

    free(aux);
}