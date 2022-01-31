#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
 typedef struct tab{
 	int val;
 	struct tab *suiv;
 } *liste; 
 
 liste ne(int n)
 {
 	liste k,nouv,p;
  	int i;
     k=(liste)malloc(sizeof(struct tab));
     k->val=1;
     k->suiv=NULL;
     k=p;
     for(i=2;i<=n;i++)
     {
     	nouv=(liste)malloc(sizeof(struct tab));
     	nouv->val=i;
     	nouv->suiv=NULL;
     		nouv=k;

	 }
	 return k;
 }
 void aff(liste k,int n)
 { int i;
 for(i=2;i<=n;i++)
		  {
	 printf("%d",k->val);k=k->suiv;}
 }
 
   int main()
   
  { 
  liste k;
  int i,n;
  	     scanf("%d",&n);
  	     k=ne(n);
  	     for(i=1;i<=n;i++) aff(k,n);
  	    

	      
  	
	}        
	
		

