#include<stdio.h>
main()
{int mois,annee,r,i;
printf("entree l annee sible\n");scanf("%d",&annee);r=(annee%4==0)?366:365;
{if (annee%4==0){printf("le nombre de jour de l annee est :%d\n",365);
}else printf("le nombre de jour de l annee est : %d\n",366);
 printf("donner le nombre du mois\n");}
 scanf("%d",&mois);
 if(mois==1)printf("c est janvier\n");
 if(mois==2)printf("c est fevrier\n");
 if(mois==3)printf("c est mars\n");
 if(mois==4)printf("c est avril\n");
 if(mois==5)printf("c est mai\n");
 if(mois==6)printf("c est juin\n");
 if(mois==7)printf("c est juiller\n");
 if(mois==8)printf("cest aout\n");
 if(mois==9)printf("c est septembre \n");
 if(mois==10)printf("c est octobre\n");    
 if(mois==11)printf("cest novembre \n");
 if(mois==12)printf("cest decembre \n");
 
 if(mois==1|mois==3|mois==5|mois==7|mois==8|mois==10|mois==12) 
  {printf("le nombre de jour est :%d",31);} 
   else if(mois==4|mois==6|mois==9|mois==11)
   {printf("le nombre de jour est :%d",30);}
   else {
	 if(r==365) printf("le nombre de jour est 28\n");
	 else if(r==366) printf("le nombre de jour est 29\n");}

	return 0;
} 
