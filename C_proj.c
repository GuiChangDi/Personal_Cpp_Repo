#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int echofile(const char *file)
{
    FILE *fp;
    char ch;
    if( (fp = fopen(file,"r")) == NULL)
    {
        printf("Reading file Failed");
        return 0;
    }

    ch = fgetc(fp);
    while( ch != EOF )
    {
        putchar(ch);
        ch = fgetc(fp);
    }
    return 1;
}

int writefile(const char* file)
{
    FILE *fp;
    char ch;
    if (( fp = fopen(file,"a")) == NULL)
    {
        printf("open file error\n");
        return 0;
    }
    ch = getchar();
    while( ch != '#' )
    {
        fputc(ch, fp);
        ch = getchar();
    }
    return 1;
}

int main()
{
    echofile("C:\\workspace\\Train\\Algorithm_Training\\Shadowsocks.md");
    writefile("C:\\workspace\\Train\\Algorithm_Training\\Shadowsocks.md");
    return 0;
}