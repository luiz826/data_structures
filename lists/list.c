/*
    Author: Luiz Fernando Costa dos Santos
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Functions
void clean_list(struct list *l)
{
    if (l->counter == -1)
    {
        printf("This list is allready empty.\n");
        exit(1);
    } 

    l->counter = -1;
}

void create_list(struct list *l)
{
    l->counter = -1; // (*pl).counter = -1
}

int element_index(struct list *l, int element)
{
    for (int i=0; i<l->counter; i++)
    {
        if (l->data[i] == element)
        {
            return i;
        }
    }

    return -1;
}

void insert_beginning(struct list *l, int value)
{
    if (isempty(l))
    {
        insert_end(l, value);
        return ;
    }

    int i;

    for (i=l->counter+1; i>=0; i--)
    {
        l->data[i] = l->data[i-1];
    }  

    l->data[i+1] = value;
    l->counter++;
}

void insert_end(struct list *l, int value)
{
    if (isfull(l))
    {
        printf("This list is full.\n");
        exit(1);
    } 

    l->data[l->counter+1] = value;
    l->counter++;
}

void insert_sort(struct list *l, int value)
{
    if (isempty(l))
    {
        insert_end(l, value);
    } else 
    {
    
    insert_end(l, value);

    int i, key, j;

    for (i = 0; i <= l->counter+1; i++)
    {
        key = l->data[i];
        j = i - 1;

        while (j >= 0 && l->data[j] > key)
        {
            l->data[j + 1] = l->data[j];
            j--;
        }
        l->data[j + 1] = key;
    }
    }
}

int isempty(struct list *l)
{
    if (l->counter == -1){
        return 1;
    }
    return 0;
}

int isfull(struct list *l)
{
    if (l->counter == (LIST_DATA_SIZE-1)){
        return 1;
    }
    return 0;
}

void remove_beginning(struct list *l) 
{
    if (isempty(l))
    {
        printf("This list is empty.\n");
        exit(1);
    }

    for (int i=0; i<l->counter+1;i++)
    {
        l->data[i] = l->data[i+1];
    }

    l->counter--;

}

void remove_end(struct list *l)
{
    if (isempty(l))
    {
        printf("This list is empty.\n");
        exit(1);
    }

    l->counter--;
}

void show_list(struct list l)
{
    printf("\n[  ");
    for (int i=0; i<=l.counter; i++)
    {
        printf("%d  ", l.data[i]);
    } 
    printf("]\n");
}
