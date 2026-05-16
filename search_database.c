#include "header.h"
#include <ctype.h>

void search_database(hash_t *arr)
{
    char key[20];
    int index;

    printf("Enter the word to search: ");
    scanf("%19s", key);

   for (int i = 0; key[i]; i++)
    key[i] = tolower((unsigned char)key[i]);

     if (isalpha((unsigned char)key[0]))
    index = key[0] - 'a';
    else
    index = 26;

    m_node *mtemp = arr[index].link;

    while (mtemp != NULL)
    {
        if (strcmp(mtemp->word, key) == 0)
        {
            printf("\nWord found: %s\n", key);
            printf("Present in %d file(s):\n", mtemp->filecount);

            s_node *stemp = mtemp->slink;
            while (stemp != NULL)
            {
                printf("  %s  -> %d times\n",
                       stemp->filename, stemp->wordcount);
                stemp = stemp->sublink;
            }
            return;
        }
        mtemp = mtemp->mlink;
    }

    printf("\nWord '%s' not found in database.\n", key);
}