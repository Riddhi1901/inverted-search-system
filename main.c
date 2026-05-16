#include "header.h"

/*Name -> RIDDHI BALAJI SHITOLE (25034f_036)
Project name -> Inverted Search */

int main(int argc, char *argv[])
{
    Flist *head = NULL;
    int option;
    hash_t arr[27];
    for(int i = 0; i < 27; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
    //check the CLA is passed or not
   // => if passed
   if(read_and_validation(argc,argv, &head) == SUCCESS)
   {
     printf("read and validation is successfully done\n");
     //print_list(head);
     while(1)
     {
     //Display menu
     printf("\n1.Create database\n2.Display database\n3.Search database\n4.Save database\n5.Update database\n6.Exit\n");
     scanf("%d", &option);

switch (option)
{
    case 1:
        create_database(arr, head);
        break;
    case 2:
        display_database(arr);
        break;
    case 3:
        search_database(arr);
        break;
    case 4:
        save_database(arr);
        break;
        case 5:
        update_database(arr, &head);
        break;
    case 6:
        return 0;
}
     }
   }
   else
   {
     printf("Error : read and validation is not done completely\n");
   }
   //-> not passed => print error &  usage msg 

}