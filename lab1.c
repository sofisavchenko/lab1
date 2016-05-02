#include<stdio.h>
#include <locale.h>
int schr(char*str, char ch)
{
    int i=0, idx=-1;
    for(i=0;(str[i]!='\0')&&(str[i]!=ch);i++);
        if(str[i]==ch)
            idx=i;
    //printf("%d=idx\n", idx);
    return idx;
}//POISK PERVOGO VHOZHDENIA SIMVOLA V STROKU
void input(char path[])
{
    fgets(path, 261, stdin);
   // printf("%s", path);
}//VVOD STROKI SIMVOLOV
int stok(char str[], char delim, char*ptr[])
{
    char*suf=str;
    ptr[0]=str;
    int i, j=1;
    while((i=schr(suf,delim))>=0)
    {
        suf[i]='\0';
        suf=suf+i+1;
        ptr[j]=suf;
        j++;
    }

    return j;
}//RAZBIENIE STROKI CHAR NA TOKENI RAZDELITELEM DELIM, UKAZATELI NA NACHALA TOKENO V PTR
char toLowCase(char ch)
{
	if(ch>='A'&&ch<='Z')
		return ch+('a'-'A');
	return ch;
}//MENYAET REGISTR SIMVOLA NA STROCHNII
/*int slen(int i, char*ptr[i] )
{
    int len;
	for(i=0; ptr[i]!='\0';i++);
    len=i;
    return len;
}*/
int slen(char str[])
{
    int len, i=0;
    while(str[i]!='\0')i++;
	len=i;
    return len;
}//IZMERYAET DLINU STR
/*int symbols(char token[], char* ptr[], int n)
{
    char* suf = token;
    ptr[0] = token;
    int i = 0, j = 1;
    while(i < n)
    {
        suf[i] = toLowCase(suf[i]);
        suf = suf + 1;
        ptr[j] = suf;

        i++; j++;
    }
    printf("%s=ptr[%d] \t", ptr[i], i);
    return 0;
}*/

int main()
{
    setlocale(LC_ALL, "Russian");

    char path[261],sequence[261];
    printf("VVEDITE PUT'\n"); input(path);
    printf("VVEDITE RYAD DLYA POISKA\n"); input(sequence);

/*    int lenght;
    lenght=slen(path);
    printf("%s=lenght of path", lenght);
*/
    int indexW, indexL;
    indexW=schr(path,'\\');
    indexL=schr(path,'/');
    char* ptr[261]={0};int j;
    if (indexW>indexL)
    {
        printf("%d=index pervogo vhozhdeniya v stroku simvola '\\' \n => OS: Windows \n", indexW);

        j = stok(path, '\\', ptr);

    }
    else
    {
        printf("%d=index pervogo vhozhdeniya v stroku simvola '/' \n => OS: GNU Linux \n",indexL);

        j = stok(path,'/', ptr);
    }

    printf("%d=j\n",j-1);//j-kolichestvo '\0', (j-1)-kolichestvo razdelitelei delim

    int i = 0, lenght[j], m;
    char *stroka;
 	for (i = 0; i < j; i++)
	{
		printf("%s=ptr[%d] \t", ptr[i], i+1);
		lenght[i]=slen(ptr[i]);//
		printf(" %d=lenght[%d] \n", lenght[i], i);
		stroka = ptr[i]; printf("%s = stroka\n", stroka);
		for(m = 0; m < lenght[i]; m++)
        {
            stroka[m] = toLowCase(stroka[m]);
        }
    printf("%s = stroka\n", stroka);
    }//VIVOD TOKENOV

    int n;
    /*char* ch[261]={0};
    for (i = 0; i < j; i++)
	{
	    symbols(ptr[i], ch, lenght[i]);
    }*/

   /* for (i = 0; i < j; i++)
	{
		printf("%s=ptr[%d] \t", ptr[i], i+1);

    }*/

    return 0;
}
