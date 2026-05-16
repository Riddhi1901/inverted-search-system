#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
    char filename[20];
    struct node *link;
}Flist;

typedef struct subnode
{
    int wordcount;
    char filename[20];
    struct subnode *sublink;
}s_node;

typedef struct mainode
{
    int filecount;
    char word[20];
    s_node *slink;
    struct mainode *mlink;
}m_node;

typedef struct mnode
{
    int index;
    m_node *link;
}hash_t;

/* Function Prototypes */
int read_and_validation(int argc, char *argv[], Flist **head);
int insert_last(Flist **head, char *fname);
int create_database(hash_t *arr, Flist *head);
void display_database(hash_t *arr);
void search_database(hash_t *arr);
int update_database(hash_t *arr, Flist **head);
int save_database(hash_t *arr);

#endif