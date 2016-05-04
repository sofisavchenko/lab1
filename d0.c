#include <stdio.h>
int slen(char str[])
{
    int len, i=0;
    while(str[i]!='\0')i++;
    len=i;
    return len;
}
int schr(char*str, char ch)
{
    int i=0, idx=-1;
    for(i=0;(str[i]!='\0')&&(str[i]!=ch);i++);
        if(str[i]==ch)
            idx=i;
    //printf("%d=idx\n", idx);
    return idx;
}
int sequal(char s1[], char s2[])
{
    int i, flg = 1;
    for(i = 0; flg && (s1[i] != '\0' || s2[i] != '\0'); i++)
        {
            if(s1[i] != s2[i])
                flg = 0;
        }
    return flg;
}
int sstr(char txt[], char p[])
{
    char*suf = txt;
    int len = slen(p);
    printf("%d = len of sequence", len);
    int pos = -1; printf("%d = pos in start", pos);
    int i = 0;
   i = schr(suf, p[0]); printf("%d = i\n \n", i);
    while(((i = schr(suf, p[0])) >= 0) && (pos < 0))
    {
        printf("%d = i", i);
        char tmp;
        suf = suf + i;
        tmp = suf[len];
        suf[len] = '\0';
        if(sequal(suf, p))
        {
            pos = suf - txt;
            printf("%d = pos", pos);
        }
    suf[len] = tmp;
    suf++;

   }

    return pos;
}

int main()
{       
    char sequence[] = "mpi";
    char stroka[] = "openmpin";

    int index;
    index = sstr(stroka, sequence);
    printf("%d = index", index);
/*  
    printf("%d = dlina stroki\n", slen(stroka)-1);
    int seq, str;
    seq = slen(sequence)-1; printf("%d = dlina sequence\t", seq);
    str = slen(stroka)-1; printf("%d = dlina stroki\n", seq);
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
    
    }*/

    return 0;
}
