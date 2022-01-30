#include<stdio.h>
main()
{//en essay a trouver le max des nombre entree par l'utilisateur et compter combien de fois et repeter
          int i,comp=1;float maxN,N,n;

			printf("ecrire 
			
			le nombre de valeur a compare\n");
			
			scanf("%f",&n);
			
			for(i=1,maxN;i<=n;i++){
			
			printf("donnez le nombre %d\n",i);
			
			scanf("%f",&N);
			 
			 if(N>maxN){maxN=N;}
		     
			 	else if(maxN==N){comp+=1;}}
			
			printf("le max des nombre est %.2f\n",maxN);
			
			printf("ce max a etait repeter %d fois",comp);
  
}
