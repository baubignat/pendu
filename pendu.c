// RESTE A FAIRE
// incorporer fonction lireCaractere

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define TAILLE_MAX_MOT 50

char lireCaractere()
{
	char caractere=0;
	caractere=getchar();
	caractere=toupper(caractere);
	while(getchar()!='\n');
	return caractere ;
}

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
	strtok(mot,"\n");
	printf("Bienvenue au jeu du pendu !\n");
	int playCount=10;
	char* motJoueur = 0 ;
	int size = strlen(mot);
	motJoueur = malloc(size*sizeof(char));
	if(motJoueur==NULL)
	{
		exit(0);
	}
	int i=0;
	for(i=0;i<strlen(motJoueur);i++)
	{
		motJoueur[i]=mot[i];
	}
	for(i=0;i<strlen(motJoueur);i++)
	{
		motJoueur[i]='*';
	}
	/*char lettre=0;
	while(playCount>0 || strcmp(mot,motJoueur)!=0)
	{
		printf("Mot à deviner : %s\n",motJoueur);
		printf("Il vous reste %d essais.\n", playCount);
		printf("Devinez une lettre : ");
		lettre=lireCaractere();
		int i=0;
		for(i=0;i<strlen(mot);i++)
		{
			if(mot[i]=lettre)
			{
				motJoueur[i]=lettre;
			}
		}
		playCount-- ;
	}
	if(playCount==0)
	{
		printf("Vous avez perdu :-(\n");
	}
	else if(strcmp(mot,motJoueur)==0)
	{
		printf("Vous avez gagné :-)\n");
	}*/
	free(motJoueur);
	return 0;
}
