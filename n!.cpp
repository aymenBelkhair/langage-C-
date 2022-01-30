#include<stdio.h>
#include<stdlib.h>
 
	//on essay a calculer le factoriale d un nonbre donner exemple: 5! = 5*4*3*2*1 = 120
int fact(int n) {
	
	int i,p;
	
	for(i=1,p=1;i<=n;i++)
	
	p=p*i;
	
	return p;
}

int main(){
	int x,n;
	
	printf("saisir n = ");scanf("%d",&n);

	if(n==1)   {return 1;}
 	
	 	else x=fact(n);
 
	printf("%d!= %d",n,x);	
}
