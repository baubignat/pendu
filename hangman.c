#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE_WORD 50

char readCharacter()
{
	char character=0;
	character=getchar();	
	while(getchar()!='\n');
	return character ;
}

int main ()
{
	FILE* dictionary=fopen("dictionary.txt","r");
	if(dictionary==NULL)
	{
		exit(0);
	}
	fseek(dictionary,0,SEEK_END);
	long sizeDictionary=ftell(dictionary);
	srand(time(NULL));
	fseek(dictionary,rand()%(sizeDictionary-6),SEEK_SET);
	char word[MAX_SIZE_WORD]="";
	fgets(word,MAX_SIZE_WORD,dictionary);
	fgets(word,MAX_SIZE_WORD,dictionary);
	fclose(dictionary);
	strtok(word,"\n");
	printf("Welcome to the game of hangman!\n");
	int playCount=10;
	char* wordGamer = 0 ;
	int size = strlen(word);
	wordGamer = malloc(size*sizeof(char));
	if(wordGamer==NULL)
	{
		exit(0);
	}
	int i=0;
	for(i=0;i<strlen(wordGamer);i++)
	{
		wordGamer[i]=word[i];
	}
	for(i=0;i<strlen(wordGamer);i++)
	{
		wordGamer[i]='*';
	}
	while(playCount>0 && strcmp(word,wordGamer)!=0)
	{
		printf("Word to guess: %s\n",wordGamer);
		printf("You have %d tries remaining.\n",playCount);
		printf("Guess a letter: ");
		char letter=0;
		letter=readCharacter();
		int i=0;
		for(i=0;i<strlen(word);i++)
		{
			if(word[i]==letter)
			{
				wordGamer[i]=letter;
			}
		}
		playCount--;
	}
	if(playCount==0)
	{
		printf("You lost :-(\nThe word to guess was %s.\n",word);
	}
	else if(strcmp(word,wordGamer)==0)
	{
		printf("You won :-)\n");
	}
	free(wordGamer);
	return 0;
}
