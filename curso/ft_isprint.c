//#include <stdio.h>
int ft_isprint(int c)
{
    int isprint;

    isprint = 0;
    if (' ' <= c && c <= '~')
    {
        isprint = 1;
    }
    return (isprint);
}
/*
int main()
{
  int c;
  
  c = 32;
  printf("%i", ft_isprint(c));
}*/