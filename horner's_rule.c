#include <stdio.h>

int main()
{
     float a[100],sum=0,x;
     int n,i;

     printf("Enter degree of the polynomial X : ");
     scanf("%d",&n);
     printf("\nEnter coefficient's of the polynomial X \n");
     for(i=n;i>=0;i--)
     {
            printf("Enter Coefficient of X^%d : ",i);
            scanf("%f",&a[i]);
     }
     printf("\nEquation is : ");
     for(i=n;i>=0;i--)
     {
         if(i!=0)
            printf("%.1f X^%d + ",a[i],i);
         else
            printf("%.1f X^%d \n",a[i],i);
            
     }
     printf("\nEnter the value of X : ");
     scanf("%f",&x);

     for(i=n;i>0;i--)
     {
        sum=(sum+a[i])*x;
     }

     sum=sum+a[0];

     printf("\nValue of the polynomial is = %.2f \n",sum);

     return 0;
}