#ifndef READ_FILE_H_INCLUDED
#define READ_FILE_H_INCLUDED

#include <stdio.h>

int read_file()
{
    FILE *fp;
    fp = fopen("test_file","r");
    int i=0;
    char str[100];
    char c;
    while(1)
    {
        c=fgetc(fp);
        if (c==EOF)
            break;
        else
        {
            if (c!='\n')
            {
                str[i]=c;
                i+=1;
            }
        }
    }
    str[i]='\0';
    printf("The stream of bytes is: %s \n",str);
    fclose(fp);
    return (0);
}


#endif // READ_FILE_H_INCLUDED
