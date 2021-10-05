#include <stdio.h>

int main()
{
    int i, j, num, sum;

   
    printf("Enter upper limit: ");
    scanf("%d", &num);

    printf("Perfect numbers between 1 to %d:\n", num);
    
  
    for(i=1; i<=num; i++)
    {
        sum = 0;

        
        for(j=1; j<i; j++)
        {
            if(i % j == 0)
            {
                sum = sum + j;
            }
        }
 
      
        if(sum == i)
        {
            printf("%d \n", i);
        }
    }

    return 0;
}
