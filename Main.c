#include <stdio.h>
#include "string_functions.h"
#include "single_frame.h"
#include "first_frame.h"
#include "consecutive_frame.h"
#include "read_file.h"
#include "write_file.h"

int main()
{
    int option;
    int flag=0;
    while(flag==0)
    {
        printf("Select the option you desire: \n");
        printf("1. Write file with stream of data as input \n");
        printf("2. Read file with the individual CAN frames as data stream \n");
        printf("3. Quit program \n");
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            write_file();
            break;
        case 2:
            read_file();
            break;
        case 3:
            flag=1;
            break;
        default:
            printf("Wrong option, try again ");
        }
    }
    return (0);
}
