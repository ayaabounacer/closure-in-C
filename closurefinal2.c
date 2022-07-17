#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i,j,k,n,tmp;
    char PP[50],DP[50],*A,C[50];
    
    A=(char*)calloc(50,sizeof(char));

    printf("***THIS PROGRAM COMPUTES THE CLOSURE OF A SET OF ATTRIBUTES***\n");

    printf("how many fonctionnal dependencies you want?\n");
    scanf("%d",&n);


  
    for (i=0;i<n;i++)
    {
        printf("enter your %d fonctionnal dependency \n",i+1);
        printf("**1st part --> 2nd part**\n");
        printf("enter the 1st part of your FD: \n");
        scanf("%s",&DP[i] );
        printf("enter the 2nd part of your FD: \n");
        scanf("%s", &PP[i]);

    }
    
    printf("YOUR INPUT IS : \n");
    for (i=0;i<n;i++)
    printf("%c-->%c\n",DP[i],PP[i]);

 strcat(A,PP);
 strcat(A,DP);
    //to avoid repetition
for(i=0;i<strlen(A);i++)
{
    for(j=i+1;j<strlen(A);j++)
    {
        if(A[i]==A[j])
        for(k=j;k<strlen(A);k++){
        A[k]=A[k+1];   // replace 
        }
    }
}
 
printf("the set of attributes of this relation is {%s}:\n", strrev(A));

printf("Enter an attribute whose closure is to be found :");
scanf("%s",&C);
printf("you want to calculate the closure of %s\n",C);


for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(C[i]==DP[j]){
            C[i+1]=PP[j];
            tmp++; 
        }
    }
}

printf("OUTPUT (THE CLOSURE IS):\n");
for(i=0;i<tmp;i++){
    printf("%c",C[i]);
}

}
