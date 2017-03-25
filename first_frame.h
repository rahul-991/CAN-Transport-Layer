#ifndef FIRST_FRAME_H_INCLUDED
#define FIRST_FRAME_H_INCLUDED
#include "string_functions.h"
void first_frame(char *a,int len)
{
    char temp[16]="1";
    char *temp2=len_to_hex(len);
    concatenation(temp,temp2);
    int i,j;
    for(i=0,j=4;j<16;i++,j++)
        temp[j]=a[i];
    temp[j]='\0';
    for(i=0;temp[i]!='\0';i++)
        a[i]=temp[i];
    a[i]='\0';
    //printf("first frame: %s",a);
}

#endif // FIRST_FRAME_H_INCLUDED
