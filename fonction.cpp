#include<stdio.h>
main()
{	//on essay de cree le fonctionnement d;une fonction

int x,a,n=0;

	do{
		
	printf("donner la valeur du 1 terme\n",a);
	
    scanf("%d",&a);
    
	   }while(a==0);
   
   while(x==1){
   	
	printf("donner le nombre x\n",x);
	
	scanf("%d",&x);
	
		if(x%2==0){x/=2;}
		
			else{x=3*x+1;};
			
	printf("x=%d",x);}
}
   
 



