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

	int choix_jouere,val_a_trouve;


	srand(time(NULL));
	val_a_trouve = rand() % 101;
	printf("La valeur a trouver est : %d \n",val_a_trouve);
	
	
	printf("\033[0m");
	printf("\n");
	

	do
	{
		printf("Entrez un numero : ");
		scanf("%d",&choix_jouere);
		plus_moins(choix_jouere,val_a_trouve);//Here the Function is called

	}while(choix_jouere!=val_a_trouve);
	
}
