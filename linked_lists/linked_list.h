/*
    author: Luiz Fernando Costa dos Santos
*/

#include <stdio.h>
// standard structure for linked lists
struct node
{
    int data;
    struct node *next;
};

//////////////////////////////////prototypes//////////////////////////////////////////////////////////////// 
void change_element(struct node **l, int old, int new_); 
int find_element(struct node *l, int value); 
// return the index value (if it appears more than one time, the first index is returned) or -1 if the value isn't in the list
void clean_list(struct node **l); 
struct node* create_list(void); 
void insert_beg(struct node **l, int value); 
void insert_end(struct node **l, int value); 
int is_empty(struct node *l); 
void print_list(struct node *l); 
void remove_beg(struct node **l); 
void remove_end(struct node **l); 
