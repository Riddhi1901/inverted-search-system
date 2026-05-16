#include "header.h"
#include <ctype.h>

#include "header.h"
#include <ctype.h>

int create_database(hash_t *arr, Flist *head)
{
    int index;
    Flist *temp = head;
    char input_word[20];

    while (temp != NULL)
    {
        FILE *fptr = fopen(temp->filename, "r");
        if (fptr == NULL)
        {
            temp = temp->link;
            continue;
        }

        while (fscanf(fptr, "%19s", input_word) != EOF)
        {
            
            for (int i = 0; input_word[i]; i++)
                input_word[i] = tolower((unsigned char)input_word[i]);

            
            if (isalpha((unsigned char)input_word[0]))
                index = input_word[0] - 'a';
            else
                index = 26;

            if (arr[index].link == NULL)
            {
                m_node *mnew = malloc(sizeof(m_node));
                s_node *snew = malloc(sizeof(s_node));
                if (!mnew || !snew)
                    return FAILURE;

                mnew->filecount = 1;
                strcpy(mnew->word, input_word);
                mnew->slink = snew;
                mnew->mlink = NULL;

                snew->wordcount = 1;
                strcpy(snew->filename, temp->filename);
                snew->sublink = NULL;

                arr[index].link = mnew;
            }
            else
            {
                m_node *mtemp = arr[index].link;
                m_node *mprev = NULL;

               
                while (mtemp != NULL)
                {
                    if (strcmp(mtemp->word, input_word) == 0)
                        break;

                    mprev = mtemp;
                    mtemp = mtemp->mlink;
                }

                if (mtemp != NULL)
                {
                    s_node *stemp = mtemp->slink;
                    s_node *sprev = NULL;

                    while (stemp != NULL)
                    {
                        if (strcmp(temp->filename, stemp->filename) == 0)
                        {
                            stemp->wordcount++;
                            break;
                        }
                        sprev = stemp;
                        stemp = stemp->sublink;
                    }

                    if (stemp == NULL)
                    {
                        s_node *snew = malloc(sizeof(s_node));
                        if (!snew)
                            return FAILURE;

                        snew->wordcount = 1;
                        strcpy(snew->filename, temp->filename);
                        snew->sublink = NULL;

                        sprev->sublink = snew;
                        mtemp->filecount++;
                    }
                }
                else
                {
                    m_node *mnew = malloc(sizeof(m_node));
                    s_node *snew = malloc(sizeof(s_node));
                    if (!mnew || !snew)
                        return FAILURE;

                    mnew->filecount = 1;
                    strcpy(mnew->word, input_word);
                    mnew->slink = snew;
                    mnew->mlink = NULL;

                    snew->wordcount = 1;
                    strcpy(snew->filename, temp->filename);
                    snew->sublink = NULL;

                    mprev->mlink = mnew;
                }
            }
        }

      
        fclose(fptr);
        temp = temp->link;
    }

   
    return SUCCESS;
}