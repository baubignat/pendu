// RESTE A FAIRE
// strlen(mot) est trop grand de 1
// incorporer fonction lireCaractere

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAILLE_MAX_MOT 50

int main ()
{
	FILE* dico=fopen("dico.txt","r");
	if(dico==NULL)
	{
		exit(0);
	}
	fseek(dico,0,SEEK_END);
	long tailleDico=ftell(dico);
	srand(time(NULL));
	fseek(dico,rand()%(tailleDico-6),SEEK_SET);
	char mot[TAILLE_MAX_MOT]="";
	fgets(mot,TAILLE_MAX_MOT,dico);
	fgets(mot,TAILLE_MAX_MOT,dico);
	fclose(dico);
	/*char* motADeviner = NULL;
	motADeviner = malloc((strlen(mot)-1)*sizeof(char));
	if(motADeviner==NULL)
	{
		exit(0);
	}
	int i=0;
	for(i=0;i<strlen(motADeviner);i++)
	{
		motADeviner[i]=mot[i];
	}*/
	printf("%s",mot);
	printf("%ld",strlen(mot));
	//free(motADeviner);
	printf("Bienvenue au jeu du pendu !\n");
	int playCount=0;
	char* motJoueur = NULL ;
	motJoueur = malloc(strlen(mot)*sizeof(char));
	if(motJoueur==NULL)
	{
		exit(0);
	}
	int ii=0;
	for(ii=0;ii<strlen(motJoueur);ii++)
	{
		motJoueur[ii]='*';
	}
	char* lettre=""; // insérer à la place fonction lireCaractere
	while(playCount<10 || strcmp(mot,motJoueur)!=0)
	{
		printf("Mot à deviner : %s\n",motJoueur);
		printf("Devinez une lettre : ");
		//lireCaractere
		int i=0;
		for(i=0;i<strlen(mot);i++)
		{
			if(mot[i]='lettre')
			{
				motJoueur[i]='lettre';
			}
		}
	}
	if(playCount==10)
	{
		printf("Vous avez perdu :-(\n");
	}
	else if(strcmp(mot,motJoueur)==0)
	{
		printf("Vous avez gagné :-)\n");
	}
	free(motJoueur);
	return 0;
}
