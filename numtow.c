#include<string.h>
#include<stdio.h>
#define BUF_SIZE 20

char* one[] = { "", "one ", "two ", "three ", "four ",
                "five ", "six ", "seven ", "eight ",
                "nine ", "ten ", "eleven ", "twelve ",
                "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ",
                "nineteen "
              };

char* ten[] = { "", "", "twenty ", "thirty ", "forty ",
                "fifty ", "sixty ", "seventy ", "eighty ",
                "ninety "
              };
char * numToWords(int n, char* s, char *str, int len)
{
    memset(str,0,len);
 
    if (n > 19)
    {
        strcat(str,ten[n / 10]);
        strcat(str,one[n % 10]);
    }
    else
    {
        strcat(str,one[n]);
    }
   
    if (n)
    {
        strcat(str,s);
    }
    return str;
}

char* convertToWords(long n, char *out)
{
    char str[BUF_SIZE] = {0};
   
    strcat(out, numToWords((n / 10000000), "crore ",str,BUF_SIZE));
    
    strcat(out, numToWords(((n / 100000) % 100), "lakh ",str,BUF_SIZE));
    
    strcat(out, numToWords(((n / 1000) % 100), "thousand ",str,BUF_SIZE));
    
    strcat(out, numToWords(((n / 100) % 10), "hundred ",str,BUF_SIZE));
    
    if (n > 100 && n % 100)
    {
        strcat(out, "and ");
    }
    
    strcat(out, numToWords((n % 100), "",str,BUF_SIZE));
    return out;
}
int main()
{
    
    long num;
    char str[60] = {0};
    
    printf("Enter any number: ");
    scanf("%ld", &num);
    
    printf( "%s",convertToWords(num,str));
    return 0;
}
