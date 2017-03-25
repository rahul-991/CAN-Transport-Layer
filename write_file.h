#ifndef WRITE_FILE_H_INCLUDED
#define WRITE_FILE_H_INCLUDED

#include <stdio.h>
#include "string_functions.h"
#include "single_frame.h"
#include "first_frame.h"
#include "consecutive_frame.h"

int write_file()
{
    FILE *fp=fopen("test_file","w");
    char input[100];
    char test[100];
    char temp[14];
    printf("Enter the stream of bytes: ");
    scanf("%s",input);
    int frame_len;
    int skip=0;
    int input_length=str_length(input);

    int i,j,k,num_frames,count=0;
    for(i=0;i<input_length;i++)
        test[i]=input[i];
    test[i]='\0';

    //Single Frame implementation
    if(input_length<15)
    {
        SFrame(test,input_length);
        fputs(test,fp);
        fputc('\n',fp);
        for(i=input_length+2;i<16;i++)
            test[i]=0+'0';
        test[i]='\0';
    }
    //First frame implementation
    else
    {
        first_frame(test,(input_length/2));
        fputs(test,fp);
        fputc('\n',fp);
        skip+=12;
        for(i=0,j=12;input[j]!='\0';i++,j++)
            test[i]=input[j];
        test[i]='\0';
        num_frames=str_length(test)/14;

        if((str_length(test)%14)>0)
            num_frames+=1;

        //Consecutive frame implementation
        for(i=1;i<=num_frames;i++)
        {
            frame_len=str_length(test);
            if(frame_len>14)
            {
                for(j=0;j<15;j++)
                    temp[j]=test[j];
                temp[j]='\0';
                consec_frame(temp,i%16,14);
                fputs(temp,fp);
                fputc('\n',fp);
                skip+=14;
                for(k=0,j=skip;j<input_length;k++,j++)
                    test[k]=input[j];
                test[k]='\0';
            }
            else
            {
                for(j=0;j<frame_len;j++)
                    temp[j]=test[j];
                temp[j]='\0';
                consec_frame(temp,i%16,frame_len);
                fputs(temp,fp);
                fputc('\n',fp);
            }
        }
    }
    fclose(fp);
    return (0);
}


#endif // WRITE_FILE_H_INCLUDED
