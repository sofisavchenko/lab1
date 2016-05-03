#include<stdio.h>
int slen(char str[])
{
    int len, i=0;
    while(str[i]!='\0')i++;
    len=i;
    return len;
}
int main()
{
    char sequence[] = "mpi\t";
    char stroka[] = "openmpi\n";printf("%d = dlina stroki\n", slen(stroka));
    int seq, str;
    seq = slen(sequence); printf("%d = dlina sequence\t", seq);
//  str = slen(stroka); printf("%d = dlina stroki\n", seq);
    int n;
    int flg;
    if(seq > str)
    {
        for(n = 0; n < seq; n++)
        {
            if(sequence[n] == stroka[n]) flg++;
            else if(sequence[n] != stroka[n]) stroka[n] = 0;
        //  printf("%s = stroka[%d]", stroka[n], n);
        }
     printf("\n%d flg\n \n", flg);
    }
    else if(str > seq)
    {
        for(n = 0; n < str; n++)
        {
            if(sequence[n] == stroka[n]) flg++;
            else if(sequence[n] != stroka[n]) stroka[n] = 0;
           // printf("%s = stroka[%d]", stroka[n], n);

        }
     printf("%d flg", flg);

    }
    return 0;
}
