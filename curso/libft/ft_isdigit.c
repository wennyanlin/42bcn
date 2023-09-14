//#include <stdio.h>
int isdigit(int c)
{
    int isdigit;

    isdigit = 0;
    if ('0' <= c && c <= '9')
    {
        isdigit = 1;
    }
    return (isdigit);
}
/*
int main()
{
    int c;
    
    c = 51;
    printf("%i", isdigit(c));
}*/