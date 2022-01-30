#include<stdio.h>
main()
{ //on essay a calculer l'inverse d'un nombre exemple 478-->874
int anv=0,n,r;

do{printf("donnez un nombre\n",n);

    scanf("%d",&n);r=n;}
    
	   while(n<0);
	   
while(n>0){anv=anv*10;
               anv=anv+n%10;
			             n=n/10;}
			             
printf(" l inverse de %d est %d",r,anv);
}
