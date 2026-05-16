#include "header.h"

int update_database(hash_t *arr, Flist **head)
{
    char fname[50];

    printf("Enter new file name to update DB: ");
    scanf("%49s", fname);

    // check extension
    if (strstr(fname, ".txt") == NULL)
    {
        printf("Error: Only .txt files allowed\n");
        return FAILURE;
    }

    // check file exists
    FILE *fptr = fopen(fname, "r");
    if (!fptr)
    {
        printf("Error: File not found\n");
        return FAILURE;
    }

    // check file empty
    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        printf("Error: File is empty\n");
        fclose(fptr);
        return FAILURE;
    }
    fclose(fptr);

    // insert into file list (reuse your existing logic)
    if (insert_last(head, fname) == FAILURE)
    {
        printf("Error: File already exists in database\n");
        return FAILURE;
    }

    // now just index this one file
    Flist *temp = *head;
    while (temp->link != NULL)   // go to last file added
        temp = temp->link;

    // reuse create_database logic for a single file
    create_database(arr, temp);

    printf("Database updated successfully with '%s'\n", fname);
    return SUCCESS;
}
