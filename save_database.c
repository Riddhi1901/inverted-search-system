#include "header.h"

int save_database(hash_t *arr)
{
    char fname[50];
    printf("Enter output file name to save DB: ");
    scanf("%49s", fname);

    FILE *fptr = fopen(fname, "w");
    if (!fptr)
    {
        printf("Error: Unable to create file\n");
        return FAILURE;
    }

    for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
            m_node *mtemp = arr[i].link;

            while (mtemp != NULL)
            {
                fprintf(fptr, "#%d;%s;%d;",
                        i, mtemp->word, mtemp->filecount);

                s_node *stemp = mtemp->slink;
                while (stemp != NULL)
                {
                    fprintf(fptr, "%s,%d;",
                            stemp->filename, stemp->wordcount);
                    stemp = stemp->sublink;
                }
                fprintf(fptr, "#\n");

                mtemp = mtemp->mlink;
            }
        }
    }

    fclose(fptr);
    printf("Database saved successfully into '%s'\n", fname);
    return SUCCESS;
}