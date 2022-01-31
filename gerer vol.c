//Correction proposée par M. EL KASMI
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PERS 10
#define MAX_AEROPORT 10
typedef struct heure
{
    int h;
    int m;
    int s;
}Heure;
typedef struct date
{
    int a;
    int m;
    int j;
}Date;
typedef struct Localisation
{
    char Ville[20];
    char Pays[20];
}Localisation;
typedef struct Personnel
{
    int Matricule;
    char CIN[10];
    char Nationnalite[20];
    char Fonction[30];// (pilote, co-pilote, hôtesse de l’aire, Stewart, ...)
	float Salaire;
}Personnel;
typedef struct avion
{
    int NumA;
    char Modele[20];
    char Constructeur[20];
    int Capacite;
}Avion;
typedef struct VolGen
{
char NumVolgen[10];//Numéro de vol générique (N° Vol : chaine de charactère)
int NumJour;//Le jour du vol (1 : Lundi ; … ;7 : Dimanche)
char VilleDepart[15];
char VilleArrivee[15];
Heure Depart;
Heure Arrivee;
}VolGen;
typedef struct VolReel
{
    VolGen VG;
    Date DateVol;
    Avion AV;
    int NbPer;
    Personnel ListePersonnel[MAX_PERS];
}VolReel;
typedef struct Aeroport
{
int RS;
Date DateCreat;
Localisation Loc;
int NbVolAn;
VolReel ListeVolReel[MAX_AEROPORT];
}Aeroport;
typedef struct Groupement
{
    Aeroport T[4];
    int Nb;
}STR_GAE;
Heure SaisirHeure()
{
    Heure X;
    printf("\nEntrer l'heure, minute et seconde");
    scanf("%d%d%d",&X.h,&X.m,&X.s);
    return X;
}
void AfficherHeure(Heure X)
{
    printf("%2d:%2d:%2d",X.h,X.m,X.s);
}
Date SaisirDate()
{
    Date X;
    printf("\nEntrer l'année, mois et le jour");
    scanf("%d%d%d",&X.a,&X.m,&X.j);
    return X;
}
void AfficherDate(Date X)
{
    printf("%4d-%2d-%2d",X.a,X.m,X.j);
}

Localisation SaisirLocalisation()
{
    Localisation X;
    printf("\nEntrer la ville et le pays");
    scanf("%s%s",X.Ville,X.Pays);
    return X;
}
void AfficherLocalisation(Localisation X)
{
    printf("\nLa ville %s et le pays %s",X.Ville,X.Pays);
}

Personnel SaisirPersonnel()
{
    Personnel X;
    printf("\nEntrer le matricule, CIN, Nationnalité, Focntion et salaire");
    scanf("%d%s%s%s%f",&X.Matricule,X.CIN,X.Nationnalite,X.Fonction, &X.Salaire);
    return X;
}
void AfficherPersonnel(Personnel X)
{

    printf("\nMatricule %d, CIN %s, Nationnalité %s, Focntion %s et salaire %f",X.Matricule,X.CIN,X.Nationnalite,X.Fonction, X.Salaire);
}
Avion SaisirAvion()
{
    Avion X;
    printf("\nNuméro d'avion, Modèle, constructeur et capacité");
    scanf("%d%s%s%d",&X.NumA,X.Modele,X.Constructeur,&X.Capacite);
    return X;
}
void AfficherAvion(Avion X)
{
    printf("\nNuméro d'avion %d, Modèle %s, constructeur %s et capacité %d",X.NumA,X.Modele,X.Constructeur,X.Capacite);
}
//////////////////
VolGen SaisirVolGen()
{
    VolGen X;
    printf("\nNuméro du vol générique, Le jour du vol (1:Lundi, ..., 7: Dimanche), ville de départ, ville d'arrivée");
    scanf("%s%d%s%s",X.NumVolgen,&X.NumJour, X.VilleDepart,X.VilleArrivee);
    printf("\nSaisir l'heure de départ du vol générique");
    X.Depart=SaisirHeure();
    printf("\nSaisir l'heure d'arrivée du vol générique");
    X.Arrivee=SaisirHeure();
    return X;
}
void AfficherVolGen(VolGen X)
{
    printf("\nNuméro du vol générique %s, ville de départ %s, ville d'arrivée %s",X.NumVolgen,X.VilleDepart,X.VilleArrivee);
    printf("\nL'heure de départ du vol générique: ");
    AfficherHeure(X.Depart);
    printf("\nL'heure d'arrivée du vol générique: ");
    AfficherHeure(X.Arrivee);
}
/////////////////
VolReel SaisirVolReel()
{
    VolReel X;
    int i;
    X.VG=SaisirVolGen();
    X.AV=SaisirAvion();
    printf("\nNombre personnels navigants");
    scanf("%d",&X.NbPer);
    for(i=0;i<X.NbPer;i++)
        {
            printf("\nSaisir les info du personnel navigant numero %d",i+1);
            X.ListePersonnel[i]=SaisirPersonnel();
        }
    return X;
}
void AfficherVolReel(VolReel X)
{
    AfficherVolGen(X.VG);
    AfficherAvion(X.AV);
    printf("\nNombre personnel navigant %d",X.NbPer);
    int i;
    for(i=0;i<X.NbPer;i++)
        {
            printf("\nLes info du personnel navigant numero %d",i+1);
            AfficherPersonnel(X.ListePersonnel[i]);
        }
}
Aeroport SaisirAeroport()
{
    //printf("\n---------------------");
    Aeroport X;
    printf("\nRaison sociale");
    scanf("%d",&X.RS);
    printf("\nSaisir la date de création de l'aeroport ");
    X.DateCreat=SaisirDate();
    printf("\nSaisir la localisation de l'aeroport");
    X.Loc=SaisirLocalisation();
    printf("\nSaisir le nombre de vol par an");
    scanf("%d",&X.NbVolAn);
    int i;
    for(i=0;i<X.NbVolAn;i++)
        X.ListeVolReel[i]=SaisirVolReel();
    return X;
}
void AfficherAeroport(Aeroport X)
{
    printf("\n****************************************Information de l'aeroport en cours****************************");
    printf("\nRaison sociale %d",X.RS);
    printf("\nLa date de création de l'aeroport ");
    AfficherDate(X.DateCreat);
    printf("\nLa localisation de l'aeroport");
    AfficherLocalisation(X.Loc);
    printf("\nNombre de vol par an est %d\nLa liste des vols réels de l'aeroport ",X.NbVolAn);
    int i;
    for(i=0;i<X.NbVolAn;i++)
        AfficherVolReel(X.ListeVolReel[i]);
}
void SaisirGroupement(STR_GAE *X)
{
    //int i=X->Nb;
    X->T[X->Nb]=SaisirAeroport();
    X->Nb++;
    //((*X).Nb)++;
}
void AfficherGroupement(STR_GAE X)
{
    int i;//=X.Nb-1;
    for(i=0;i<X.Nb;i++)
         {
             printf("\n--------------------------------------Information de l'aeroport numéro %d---------------------------",i+1);
             AfficherAeroport(X.T[i]);

         }
}
int RechercherAeroport(STR_GAE G,int rs)
{
    int i;
    for(i=0;i<G.Nb;i++)
        if(G.T[i].RS==rs)
            return i;
    return -1;
}
void ModifierVolReel(STR_GAE *G, int rs, int nc)
{
    int i,pos=RechercherAeroport(*G, rs);
    if (pos!=-1)
    {
        G->T[pos].NbVolAn=nc;
        for(i=0;i<nc;i++)
            //G->T[pos].ListeVolReel[i]=SaisirVolReel();
            (*G).T[pos].ListeVolReel[i]=SaisirVolReel();
    }
    else
        printf("\nLa raison sociale ne correspond à aucun aéroport!!");
}
void HistoriqueVolReel(STR_GAE G, char c[20])
{
    int i,j,k;
    for(i=0;i<G.Nb;i++)//Parcours des aeroports
    {
        for(j=0;j<G.T[i].NbVolAn;j++)//Parcours des vols réels du ième aeroport
        {
            for(k=0;k<G.T[i].ListeVolReel[j].NbPer;k++)//Parcours des personnels navigants du ième aeroport, jème vol réel
            {
                if (strcmp(G.T[i].ListeVolReel[j].ListePersonnel[k].Fonction,"Pilote")==0 && strcmp(G.T[i].ListeVolReel[j].ListePersonnel[k].CIN,c)==0)
                    AfficherVolReel(G.T[i].ListeVolReel[j]);
            }
        }
    }
}


void AfficherVRCasaParisLundi(STR_GAE G)
{
    int i,j,k;
    for(i=0;i<G.Nb;i++)//Parcours des aeroports
    {
        if (G.T[i].NbVolAn>2000)
            {
                for(j=0;j<G.T[i].NbVolAn;j++)//Parcours des vols réels du ième aeroport
                    {
                        if (G.T[i].ListeVolReel[j].VG.NumJour==1 &&
                            strcmp(G.T[i].ListeVolReel[j].VG.VilleDepart,"CASABLANCA")==0 && strcmp(G.T[i].ListeVolReel[j].VG.VilleArrivee,"PARIS")==0)
                                AfficherVolReel(G.T[i].ListeVolReel[j]);
                    }
            }
    }
}
int RechercherAeroportCapacite(STR_GAE G)
{
    int i;
    for(i=0;i<G.Nb;i++)
        if(G.T[i].NbVolAn<2)//1000)
            return i;
    return -1;
}
void SupprimerAeroport(STR_GAE *G)
{
    int i,pos;
    pos=RechercherAeroportCapacite(*G);
    //printf("\n--------------------------%d--------------------------------%d",G->Nb,pos);
    while (pos!=-1)
        {
            for(i=pos;i<G->Nb-1;i++)
                G->T[i]=G->T[i+1];//(*G).T[i]=(*G).T[i+1];
            G->Nb--;
            //(*G).Nb--;
            pos=RechercherAeroportCapacite(*G);
        }

}
void ExporterG(STR_GAE G, char p[]){
	int i , j , k;
	FILE *f;
	f = fopen("Groupement.txt","w") ;
	if ( f != NULL){
		for(i=0;i<G.Nb;i++)
            if (strcmp(G.T[i].Loc.Pays,p)==0)
                {//enregistrement des informations de l'aeroport
                fprintf(f,"%d %d %d %d %s %s %d\n",G.T[i].RS,G.T[i].DateCreat.a,G.T[i].DateCreat.m,G.T[i].DateCreat.j,
                        G.T[i].Loc.Pays,G.T[i].Loc.Ville,G.T[i].NbVolAn);
                for(j=0;j<G.T[i].NbVolAn;j++)
                    {//enregistrement des infos des listes des vols réels
                    fprintf(f,"%s %d %s %s %d %d %d %d %d %d %d %d %d %d %s %s %d %d\n",
                    G.T[i].ListeVolReel[j].VG.NumVolgen,G.T[i].ListeVolReel[j].VG.NumJour,
                    G.T[i].ListeVolReel[j].VG.VilleDepart, G.T[i].ListeVolReel[j].VG.VilleArrivee,
                    G.T[i].ListeVolReel[j].VG.Arrivee.h,G.T[i].ListeVolReel[j].VG.Arrivee.m,G.T[i].ListeVolReel[j].VG.Arrivee.s,
                    G.T[i].ListeVolReel[j].VG.Depart.h,G.T[i].ListeVolReel[j].VG.Depart.m,G.T[i].ListeVolReel[j].VG.Depart.s,
                    G.T[i].ListeVolReel[j].DateVol.a,G.T[i].ListeVolReel[j].DateVol.m,G.T[i].ListeVolReel[j].DateVol.j,
                    G.T[i].ListeVolReel[j].AV.NumA,G.T[i].ListeVolReel[j].AV.Modele, G.T[i].ListeVolReel[j].AV.Constructeur,
                    G.T[i].ListeVolReel[j].AV.Capacite,G.T[i].ListeVolReel[j].NbPer);
                    for(k=0 ; k < G.T[i].ListeVolReel[j].NbPer ; k++)
                        {//enregistrement des infos des personnels navigants
                        fprintf(f,"%d %s %s %s %f\n",G.T[i].ListeVolReel[j].ListePersonnel[k].Matricule, G.T[i].ListeVolReel[j].ListePersonnel[k].CIN,
                        G.T[i].ListeVolReel[j].ListePersonnel[k].Nationnalite,G.T[i].ListeVolReel[j].ListePersonnel[k].Fonction,
                        G.T[i].ListeVolReel[j].ListePersonnel[k].Salaire);
                        }
			}
		}
	fclose(f) ;
	}
}
void ImporterG(STR_GAE *Gr)
{
    int i=0 , j , k;
	FILE *f;
	STR_GAE G;
	f = fopen("Groupement.txt","r") ;
	if ( f != NULL)
        {
            while(!feof(f))
            {
                fscanf(f,"%d %d %d %d %s %s %d",&G.T[i].RS,&G.T[i].DateCreat.a,&G.T[i].DateCreat.m,&G.T[i].DateCreat.j,G.T[i].Loc.Pays,G.T[i].Loc.Ville,&G.T[i].NbVolAn);
                for(j=0;j<G.T[i].NbVolAn;j++)
                {//enregistrement des infos des listes des vols réels
                fscanf(f,"%s %d %s %s %d %d %d %d %d %d %d %d %d %d %s %s %d %d", G.T[i].ListeVolReel[j].VG.NumVolgen,&G.T[i].ListeVolReel[j].VG.NumJour,G.T[i].ListeVolReel[j].VG.VilleDepart, G.T[i].ListeVolReel[j].VG.VilleArrivee,
                &G.T[i].ListeVolReel[j].VG.Arrivee.h,&G.T[i].ListeVolReel[j].VG.Arrivee.m,&G.T[i].ListeVolReel[j].VG.Arrivee.s,
                &G.T[i].ListeVolReel[j].VG.Depart.h,&G.T[i].ListeVolReel[j].VG.Depart.m,&G.T[i].ListeVolReel[j].VG.Depart.s,
                &G.T[i].ListeVolReel[j].DateVol.a,&G.T[i].ListeVolReel[j].DateVol.m,&G.T[i].ListeVolReel[j].DateVol.j,
                &G.T[i].ListeVolReel[j].AV.NumA,G.T[i].ListeVolReel[j].AV.Modele, G.T[i].ListeVolReel[j].AV.Constructeur, &G.T[i].ListeVolReel[j].AV.Capacite,
                &G.T[i].ListeVolReel[j].NbPer);
                for(k=0 ; k < G.T[i].ListeVolReel[j].NbPer;k++)
                    {//enregistrement des infos des personnels navigants
                    fscanf(f,"%d %s %s %s %f",&G.T[i].ListeVolReel[j].ListePersonnel[k].Matricule, G.T[i].ListeVolReel[j].ListePersonnel[k].CIN,
                    G.T[i].ListeVolReel[j].ListePersonnel[k].Nationnalite,G.T[i].ListeVolReel[j].ListePersonnel[k].Fonction,
                    &G.T[i].ListeVolReel[j].ListePersonnel[k].Salaire);
                    }
                }
                int pos=RechercherAeroport(*Gr,G.T[i].RS);
                if (pos==-1)
                    Gr->T[Gr->Nb++]=G.T[i];
                i++;
            //printf("\nAffichage de l'aeroport trouve");
            //AfficherAeroport(G.T[i]);
            }
	fclose(f) ;
	}
}
//Programme de test à améliorer avec un menu .....
void main()
{
STR_GAE Y;
Y.Nb=0;
int rs,nc;
char cin[40];

/*
SaisirGroupement(&Y);
SaisirGroupement(&Y);
printf("\nSaisir la RS du vol réel à modifier et la nouvelle capacité aussi");
scanf("%d%d",&rs,&nc);
//ModifierVolReel(&Y, rs, nc);
//AfficherGroupement(Y);

printf("\n--------------------------------\nSaisir le pays à exporter au fichier");
scanf("%s",cin);
printf("\n");
ExporterG(Y,cin);
*/
ImporterG(&Y);
printf("\nAffichage après importation-----------------------------------");
AfficherGroupement(Y);
printf("\n--------------------------------\nSaisir le CIN du personnel recherché");
scanf("%s",cin);
printf("\nL'historique trouvé");
HistoriqueVolReel(Y,cin);
getch();
printf("\n\n\n----------------------------------------------------------\nAffichage après suppression des aeroport dont la capacité ne dépasse pas 2\n\n--------------------------------------------------------------");
SupprimerAeroport(&Y);
AfficherGroupement(Y);
}
