#include<stdio.h>
main()
{// on essay a voire si un nombre est divisible par la somme de es nombre exemple 987 = 9+8+7=24 puis 987/24 et voire s'il est divisible ou non 
int  s,n,m;

 s=0;

do {printf("donner un nombre positif\n",n);

scanf("%d",&n);}while(n<1);m=n;

do{s=s+n%10;n=n/10;}while(n!=0);

printf("la somme de ses nombre est %d\n",s);

if(m%s==0)printf("il divise");

else printf("il ne divise pas");
}



