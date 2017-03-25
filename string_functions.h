#ifndef STRING_FUNCTIONS_H_INCLUDED
#define STRING_FUNCTIONS_H_INCLUDED

int str_length(char *a)
{
    int i;
    for(i=0;a[i]!='\0';++i);
    return(i);
}

void concatenation(char *a,char *b)
{
    int i, j;
    for(i=0; a[i]!='\0'; ++i);
    for(j=0; a[j]!='\0'; ++j, ++i)
    {
        a[i]=b[j];
    }
    a[i]='\0';
}

char convert_to_hex(int num)
{
    char buf;
    switch(num)
    {
        case 10:
            return('A');
        case 11:
            return('B');
        case 12:
            return('C');
        case 13:
            return('D');
        case 14:
            return('E');
        case 15:
            return('F');
        default:
            return(num+'0');
    }
}

char* len_to_hex(int len)
{
    char temp[4]="000";
    int rem,i=2;
    while(len!=0)
    {
        rem=len%16;
        if (rem<10)
            temp[i]=rem+'0';
        else
            temp[i]=convert_to_hex(rem);
        i--;
        len/=16;
    }
    temp[3]='\0';
    return temp;
}


#endif // STRING_FUNCTIONS_H_INCLUDED
