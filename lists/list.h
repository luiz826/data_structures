/*
    Author: Luiz Fernando Costa dos Santos
*/
#include <stdio.h>

// Macros
#define LIST_DATA_SIZE 10

// Structs
struct list
{
    int data[LIST_DATA_SIZE];
    int counter;
};

// Prototypes
void clean_list(struct list *l);
void create_list(struct list *l);
int element_index(struct list *l, int element);
void insert_beginning(struct list *l, int value);
void insert_end(struct list *l, int value);
void insert_sort(struct list *l, int value);
int isempty(struct list *l);
int isfull(struct list *l);
void remove_beginning(struct list *l);
void remove_end(struct list *l);
void show_list(struct list l);