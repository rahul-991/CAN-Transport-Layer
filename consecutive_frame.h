#ifndef CONSECUTIVE_FRAME_H_INCLUDED
#define CONSECUTIVE_FRAME_H_INCLUDED
#include "string_functions.h"
void consec_frame(char *a,int frame_num,int len)
{
    char temp[16]="2";
    int i,j;
    temp[1]=convert_to_hex(frame_num);
    if (len==14)
    {
        for(i=2,j=0;i<16;i++,j++)
            temp[i]=a[j];
        temp[i]='\0';
        for(i=0;temp[i]!='\0';i++)
            a[i]=temp[i];
        a[i]='\0';
    }
    else
    {
        for(i=2,j=0;j<len;i++,j++)
            temp[i]=a[j];
        while(i<16)
        {
            temp[i]=0+'0';
            i+=1;
        }
        temp[i]='\0';
        for(i=0;temp[i]!='\0';i++)
            a[i]=temp[i];
        a[i]='\0';
    }
}

#endif // CONSECUTIVE_FRAME_H_INCLUDED
