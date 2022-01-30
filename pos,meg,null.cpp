#include<stdio.h>
main()
{//en essay a calculer le nombre des nombre entre par l'utilisateur et leur separer par types{negative,positive,null} 
int Npos=0,Nneg=0,Nnul=0,n,i;

float nombre;

printf("combien de nombre voulez vous verifier\n");

scanf("%d",&n);

for(i=1;i<=n;i++){

printf("entrer le nombres %d\n",i);

scanf("%f",&nombre);

if(nombre>0){Npos+=1;}

else if(nombre<0){Nneg+=1;}

else {Nnul+=1;}}

printf("le quantite de nombre null est %d\n",Nnul);

printf("le quantite de nombre + est %d\n",Npos);

printf("le quantite de nombre - est %d\n",Nneg);
}
