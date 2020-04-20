#include<stdio.h>
#include <stdlib.h>
#include <time.h>


void plus_moins(int x, int y)
{
	/*The function*/

	printf("\033[0;32m");
  		
	if (x<y)
	{
		printf("Le chriffre %d est plus petit que le nombre gagnant\n",x);
	}
	else if (x>y)
	{
		printf("Le chriffre %d est plus grand que le nombre gagnant\n",x);
	}
	if (x==y)
	{				
		printf("Bingo!!, vous avez gagné\n");
	}

	printf("\033[0m");
}


int main()
{
	printf("\033[1;36m");
 	
	printf("Bienvenue au jeu de bingo\n");
	printf("\n");
	int choix_jouere,val_a_trouve,mode;


	srand(time(NULL));
	val_a_trouve = rand() % 101;
	

	printf("\033[0m");
	printf("\n");
	
	
	do
	{
		printf("Choisissez la difficulté (1,2 or 3)\n");
		printf("1) Facile : tentatives illimitée\n");
		printf("2) Moyen : 25 tentatives\n");
		printf("3) Difficile : 10 tentatives\n");
		printf("Votre choix : ");
		scanf("%d",&mode);

		if ((mode>3) || (mode<1))
		{
			printf("Erreur, re-essayez\n");
			printf("\n");
		}

	}while(mode>3 || mode<1);



	switch(mode)
	{
		case 1:
			mode=10000;
			break;
		case 2:
			mode=25;
			break;
		case 3:
			mode=10;
			break;
	}	

	printf("\n");
	
	int x=0;//The variable x is used to count the number of tries of the user

	do
	{
		printf("Entrez un numero : ");
		scanf("%d",&choix_jouere);
		plus_moins(choix_jouere,val_a_trouve);//Here the Function is called

		if (choix_jouere==val_a_trouve)
		{
			break;
		}

		x+=1;

		if (x==mode)//This statement will run on the last try
		{
			printf("Malheureusement vos nombres d'essais sont arrives a terme!\n");
		}

	}while(x!=mode);
}
