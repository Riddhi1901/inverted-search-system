#include "header.h"

void display_database(hash_t *arr)
{
    for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
            m_node *mtemp = arr[i].link;

            while (mtemp != NULL)
            {
                printf("[%d] Word: %-15s  File Count: %d  -> ",
                       i, mtemp->word, mtemp->filecount);

                s_node *stemp = mtemp->slink;
                while (stemp != NULL)
                {
                    printf("(%s : %d) ",
                           stemp->filename, stemp->wordcount);
                    stemp = stemp->sublink;
                }
                printf("\n");

                mtemp = mtemp->mlink;
            }
        }
    }

    
}

