#include "header.h"

int read_and_validation(int argc, char *argv[], Flist **head)
{
    //take CLA one by one
    for(int i = 1; i < argc; i++)
    {
        //check argv[] extn is .txt or not 
        if(strstr(argv[i], ".txt") != NULL)
        {
          //check the file is present or not
          FILE *fptr = fopen(argv[i], "r");
          if(fptr != NULL)
          {
            //check the file is empty or not
            fseek(fptr,0,SEEK_END);
            if(ftell(fptr))
            {
              fclose(fptr); 
              if(insert_last(head,argv[i]) != 0)
              {
                printf("%s file successfully added in list\n",argv[i]);
              }
              else
              {
                printf("%s is duplicate file\n",argv[i]);
              }
            }
            else
            {
                fclose(fptr); 
                printf("%s file is empty\n",argv[i]);
            }
          }
          else
          {
            printf("%s file is not present \n",argv[i]);
          }
        }
        else
        {
            printf("%s is not .txt file\n",argv[i]);

        }
    }
    return SUCCESS;
}
int insert_last(Flist **head, char *fname)
{
    Flist *temp = *head;

    // check duplicate
    while (temp != NULL)
    {
        if (strcmp(temp->filename, fname) == 0)
            return FAILURE;

        if (temp->link == NULL)
            break;

        temp = temp->link;
    }

    // create new node
    Flist *new = malloc(sizeof(Flist));
    if (new == NULL)
        return FAILURE;

    strcpy(new->filename, fname);
    new->link = NULL;

    // insert
    if (*head == NULL)
        *head = new;
    else
        temp->link = new;

    return SUCCESS;
}

 