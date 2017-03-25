#ifndef SINGLE_FRAME_H_INCLUDED
#define SINGLE_FRAME_H_INCLUDED
#include "string_functions.h"
void SFrame(char *a,int len)
{
    char buf[1] = "f";
    char temp[16];
    len/=2;
    sprintf(buf, "%d", len);
    temp[0]='0';
    temp[1]=buf[0];
    int i=2,j;
    for(j=0;a[j]!='\0';j++)
    {
        temp[i]=a[j];
        i+=1;
    }
    temp[i]='\0';
    for(i=0;temp[i]!='\0';i++)
        a[i]=temp[i];
    a[i]='\0';
}


#endif // SINGLE_FRAME_H_INCLUDED
