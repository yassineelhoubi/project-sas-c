#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int numP=0 ,nbrP ;// numP :  président N° //nbrP : nombre des présidets
	int numE=0 , nbrE;// numE : électeur N° //nbrE : nombre des électeurs
	
	printf("                    programme des elections presidentielles\n\n\n");////////Titre
	printf("\n********************************************************************************\n");
	/////////////////////////////////////////////////////détermination de nombre des présidents
	
	printf("\nEntrer le nombre des president : ");
	scanf("%d",&nbrP);
	
	//////////////////////////////////////////////////// verification de nombre égale ou superieur a 5
	
	while(nbrP<5)
	{printf("\nstp Donner le nombre des Presidents superieur ou egale a 5 : ");
	scanf("%d",&nbrP);
	}
	/////////////////////////////////////////////////////insertion des présidents
	
	char nomP[nbrP][30]; //tableau 1 de nom des présidents 
	
	do{
		printf("\n donner le nom de presidents  %d : ",numP+1);
		scanf("%s",&nomP[numP]);
		numP++;
	}while(numP<nbrP);
	
	
	printf("\n********************************************************************************\n");
	//////////////////////////////////////////////////////détermination de nombre des électeur
	
	printf("\nEntrer le nombre des electeur : ");
	scanf("%d",&nbrE);
	
	////////////////////////////////////////////////////// verification de nombre des électeur superieur ou égale 10
	
	while(nbrE<10){
		printf("\nstp donner le nombre des electeur superieur ou egale a 10 : ");
		scanf("%d",&nbrE);
	}
	/////////////////////////////////////////////////////// insertion des electeurs
	
	char cinE[nbrE][20];////////////////////////////////tableau de CIN des electeur
	
	do{
		printf("\n donner le CIN d'electeur %d :",numE+1);
		scanf("%s",&cinE[numE]);
		numE++;
	}while(numE<nbrE );
	printf("\n********************************************************************************\n");
	printf("\n******************  1er Tour  ******************");
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////// TOUR 1
	
	int e , p , ch ; //e--> numéro d'électeur //p-->numéro de président // ch-->choix 
	float tbvote1 [nbrP];//tableau de vote 1
	////////////////////////////////////////////////////////// /Menu et vote
	
void refait1(){///////////////////////////pour refait le tour en cas d'égalité
    for(int o=0;o<nbrP;o++){///////initialisation de tableau de vote
		tbvote1[o]=0;
		}
	for(e=0;e<numE;e++)
	{
		printf("\n____________________________\n");
		printf("\n   _ L'electeur %s :\n ",cinE[e]);
		printf(" \n  Menu des Presidents de premiere Tour\n\n");
		for(p=0;p<numP;p++)
		{
			printf(" pour %s taper : %d \n",nomP[p],p+1);
			
		}
		printf("\n votre choix est :");
		scanf("%d",&ch);
		while(ch<=0 || ch >nbrP){
			printf("stp voter de 1 a %d ",nbrP);
			scanf("%d",&ch);
		}
		tbvote1[ch-1]++;
		}
	}
refait1();////////////////////////////// Vérification si tous les vote sont égaux
int aa=0;////////////variable de comparaison
for(int p=0;p<numP;p++)
		{
			if(tbvote1[0]==tbvote1[p]){
				
				aa++;
			}			
		}
if(aa==numP){
	printf("\n____________________________\n");
	///////////////////////////////// affichage de pourcentage
	int r ;//r-->numéro de président
	printf("\n resultat de premiere Tour \n  ");
	for(r=0;r<nbrP;r++){
		printf("\n le president %s a obtenu  : ",nomP[r]);
		printf("%.2f %% de vote",100*tbvote1[r]/nbrE);}
		
	printf("\n\n le tour doit etre refait car tous les presidents nomines ont un nombre de votes ex aequo");
	printf("\n____________________________\n");
	refait1();////////// le refait de tour de vote
}
	//////////////////////////////////////////////////////////////// affichage de pourcentage
	
	int r ;//r-->numéro de président
	printf("\n____________________________\n");
	printf("\n resultat de premiere Tour\n ");
	for(r=0;r<nbrP;r++){
		printf("\n le president %s a obtenu  : ",nomP[r]);
		printf("%.2f %% de vote",100*tbvote1[r]/nbrE);}
	  
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////// TOUR 2
	
	float tbvote2[200];
	char nomP2[200][30];//tableau 2 de nom des présidents 
	int nbrP2=0 , ch2 , z ;
	
	
	/////////////////////////////////////////////////////////////// remplissage de 2émé tableau des présidents
	 
	for(z=0;z<nbrP;z++)
	{
	if (100*tbvote1[z]/nbrE>15)
	{
	strcpy(nomP2[nbrP2],nomP[z]);
	nbrP2++;
	}
	}
	////////////////////////////////////////////////////////////////// Menu et Vote
	
	printf("\n********************************************************************************\n");
	printf("\n******************  2eme Tour  ******************");
void refait2(){///////////////////////////pour refait le tour en cas d'égalité
    for(int o=0;o<nbrP;o++){///////initialisation de tableau de vote
		tbvote2[o]=0;
		}
	for(e=0;e<nbrE;e++)
	{
		printf("\n____________________________\n");
		printf("\n   _ L'electeur %s :\n ",cinE[e]);
		printf(" \n  Menu des Presidents de la deuxieme Tour \n\n");
		
		for(p=0;p<nbrP2;p++)
		{
			printf(" pour %s taper : %d \n",nomP2[p],p+1);	
		}

		printf("\n votre choix est N:");
		scanf("%d",&ch2);
		while(ch2<=0 || ch2 >nbrP2){
			printf("stp voter de 1 a %d ",nbrP2);
			scanf("%d",&ch2);
		}
		tbvote2[ch2-1]++;
		}
	}
refait2();////////////////////////////// Vérification si tous les vote sont égaux
        int bb=0;
        for(int p=0;p<numP;p++)
		{
			if(tbvote2[0]==tbvote2[p]){
				
				bb++;
			}			
		}
        if(bb==nbrP2){
	        printf("\n____________________________\n");
		/////////////////////////////////////////////////////// affichage de pourcentage
      	int a=0 ;//a-->numéro de président
	
	    printf("\n\n resultat de la deuxieme Tour\n  ");
	    for(a=0;a<nbrP2;a++){
		printf("\n le president %s a obtenu  : ",nomP2[a]);
		printf("%.2f %% de vote",100*tbvote2[a]/nbrE);}
		
	        printf("\n \nle tour doit etre refait car tous les presidents nomines ont un nombre de votes ex aequo");
	        printf("\n____________________________\n");
	        refait2();////////// le refait de tour de vote
        }
		/////////////////////////////////////////////////////// affichage de pourcentage
		
	int a=0 ;//a-->numéro de président
	printf("\n____________________________\n");
	printf("\n resultat de la deuxieme Tour\n  ");
	for(a=0;a<nbrP2;a++){
		printf("\n le president %s a obtenu  : ",nomP2[a]);
		printf("%.2f %% de vote",100*tbvote2[a]/nbrE);}
		
	///////////////////////////////////////////////////////////// détermination de quel président remporte le plus faible pourcentage de voix
	
	int min = tbvote2[0];
	for(a=0;a<nbrP2;a++){
		if(min>tbvote2[a]){
			min=tbvote2[a];
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////TOUR 3
	
	int nbrP3=0 , ch3 ;
	float tbvote3[200];
	char nomP3[nbrP3][30];
	
	//////////////////////////////////////////////////////////////////remplissage de 3émé tableau des présidents
	
	for (int t=0;t<nbrP2;t++){
		if (tbvote2[t]>min)
	{
	strcpy(nomP3[nbrP3],nomP2[t]);
	nbrP3++;
	}	
	}
	
	printf("\n********************************************************************************\n");
		printf("\n******************  3eme Tour  ******************");
		
		/////////////////////////////////////////////////////////////////////%enu et vote
void refait3(){///////////////////////////pour refait le tour en cas d'égalité
    for(int o=0;o<nbrP3;o++){///////initialisation de tableau de vote
		tbvote3[o]=0;
		}		
	for(e=0;e<nbrE;e++)
	{
		printf("\n____________________________\n");
		printf("\n   _ L'electeur %s :\n ",cinE[e]);
		printf(" \n  Menu des Presidents de troisieme Tour\n\n");
		
		for(p=0;p<nbrP3;p++)
		{
			printf(" pour %s taper : %d \n",nomP3[p],p+1);
		}

		printf("\nvotre choix est N:");
		scanf("%d",&ch3);
		while(ch3<=0 || ch3 >nbrP3){
			printf("stp voter de 1 a %d ",nbrP3);
			scanf("%d",&ch3);
		}
		tbvote3[ch3-1]++;
		}
	}
refait3();////////////////////////////// Vérification si tous les vote sont égaux
        int cc=0;////////////variable de comparaison
        for(int p=0;p<nbrP3;p++)
		{
			if(tbvote3[0]==tbvote3[p]){
				
				cc++;
			}			
		}		
		if(cc==nbrP3){
	    printf("\n____________________________\n");
		/////////////////////////////////////////////////////// affichage de pourcentage
      	int a=0 ;//a-->numéro de président
	
	    printf("\n\n resultat de la deuxieme Tour\n  ");
	    for(a=0;a<nbrP3;a++){
		printf("\n le president %s a obtenu  : ",nomP3[a]);
		printf("%.2f %% de vote",100*tbvote3[a]/nbrE);}
		
	        printf("\n \nle tour doit etre refait car tous les presidents nomines ont un nombre de votes ex aequo");
	        printf("\n____________________________\n");
	        refait3();////////// le refait de tour de vote
        }
		
	int max = tbvote3[0];
	for(a=0;a<nbrP3;a++){
		if(max<tbvote3[a]){
			max=tbvote3[a];
		}
	}
		/////////////////////////////////////////////////////// affichage de pourcentage
		
	int l=0 ;//l-->numéro de président
	printf("\n resultat de la troisieme Tour  ");
	for(l=0;l<nbrP3;l++){
		printf("\n le president %s a obtenu  : ",nomP3[l]);
		printf("%.2f %% de vote",100*tbvote3[l]/nbrE);
		}
	///////////////////////////////////////////////////////////////////////////////////////////////////détermination de qui a remporté l'élection
	char nomP4[200][30];
	int nbrP4=0;
	for (int t=0;t<nbrP3;t++){
		if (tbvote3[t]==max)
	{
	strcpy(nomP4[nbrP4],nomP3[t]);
	nbrP4++;
	}	
	}
	printf("\n********************************************************************************\n");
	printf("\nle president gagner dans cette programme des elections est : %s \n",nomP4[0]);
	printf("\n********************************************************************************\n");
	
	return 0;
}