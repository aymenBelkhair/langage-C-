#include <stdio.h>
int main()
{
int tab[100];

int i,j,n;

do

{printf("donner la taille du tableau n = ");scanf("%d",&n);}

while(n<0||n>100);

for(i=0;i<n;i++){

printf("tab[%d] = ",i);

scanf("%d",&tab[i]);}
printf("affichage\n");
for(i=0;i<n;i++){


printf("tab[%d] = %d",i,tab[i]);printf("\n");}

}

