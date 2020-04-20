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
	int choix_jouere,val_a_trouve,mode,choix,tours,tenta;
	int points1=0;
	int points2=0;
	int pointsPlayer1=0;
	int pointsPlayer2=0;
	int totalp1=0;
	int totalp2=0;
	int count;
	char player1[20];
	char player2[20];

	srand(time(NULL));
	val_a_trouve = rand() % 101;
	
	printf("Choisissez votre mode (1 ou 2)\n");
	printf("1) Mode Solo\n");
	printf("2) Mode Multi-Jouere\n");

	
	do
	{
		/*Choosing between solo or multiplayer which will be save in the variable choix*/
		printf("Votre choix : ");
		scanf("%d",&choix);
		if(choix!=1 && choix!=2)
		{
			printf("Erreur, veuillez re-essayez\n");
		}
		else
		{
			break;
		}
	}while(choix!=1 && choix!=2);

	printf("\033[0m");
	printf("\n");
	
	if (choix==1)
	{
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

	else //Here is the multiolayer mode
	{
		printf("Entrez le nom du premier jouere : ");
		scanf("%s",player1);
		printf("Entrez le nom du deusieme jouere : ");
		scanf("%s",player2);
		
		printf("\n");

		printf("Choisissez le nombre de tours par joueres (max 10)\n");//the players shall choose between 1 and 10 only
		do
		{
			printf("Votre choix : ");
			scanf("%d",&tours);
			if ((tours>10) || (tours<1))
			{
				printf("Entrez un chriffre de 1 a 10\n");
				printf("Re-essayez\n");
			}
			
		}while((tours>10) || (tours<1));




		
		printf("\n");	

		for(int i=1; i<=tours; i++)
		{

			pointsPlayer2=0;//re initialising the variables
			points2=0;
			pointsPlayer1=0;
			points1=0;
			
			printf("Vous etes au tour numero %d \n",i);
			printf("\n");
			
			
			if (i%2==0)// Each "tour" another player will choose the number of tries
			{
				printf("%s, Choissisez le nombre de tentatives (minimum 10) :",player2);
				scanf("%d",&tenta);
			}
			else
			{
				printf("%s, Choissisez le nombre de tentatives (minimum 10) :",player1);
				scanf("%d",&tenta);
			}
	

			printf("\n");
			

			for(int j=1;j<=tenta;j++)
			{
				printf("%s Vous etes au tentative numero %d\n",player2, j);
				printf("Entrez un numero : ");
				scanf("%d",&choix_jouere);
				plus_moins(choix_jouere,val_a_trouve);
				printf("\n");


				points2+=1;
	
				
				if(j==tenta)
				{
					printf("%s, vous avez pas trouvez la reponse a temps! \n", player2);
				}

				if (choix_jouere==val_a_trouve)
				{
					break;
				}

		
			}
			
			pointsPlayer2=(tenta-points2);
			totalp2+=pointsPlayer2;
		
			
			printf("\n");
			printf("Maintenant c'est au tour de l'autre jouere\n");
			
			val_a_trouve = rand() % 101;
			srand(time(NULL));

			for(int k=1;k<=tenta;k++)
			{
				printf("%s Vous etes au tentative numero %d\n",player1, k);
				printf("Entrez un numero : ");
				scanf("%d",&choix_jouere);
				plus_moins(choix_jouere,val_a_trouve);

				printf("\n");
				points1+=1;
				

				if(k==tenta)
				{
					printf("%s, vous avez pas trouvez la reponse a temps! \n", player1);
				}

				if (choix_jouere==val_a_trouve)
				{
					break;
				}

				
			}
			
			pointsPlayer1=(tenta-points1);
			totalp1+=pointsPlayer1;
		
		}
		
		printf("\n");		

		printf("\033[0;36m");
		if(totalp1>totalp2)
		{
			printf("%s, vous avez ganier\n",player1);
		}
		else if(totalp2>totalp1)
		{
			printf("%s, vous avez ganier\n",player2);
		}
		else
		{
			printf("Vous etes a egaliter\n");
		}

		printf("%s a %d points \n",player1,totalp1);
		printf("%s a %d points \n",player2, totalp2);
		printf("\033[0m");

	}

	

	
} 

