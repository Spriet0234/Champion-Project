#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "champion.h"

int main(int argc, char* argv[]){
//Checks for command line argument
if(argc != 2)
{
printf("Error: Missing command line argument\n");
return 0;
}
char* a = argv[1];
int b = atoi(a);
//Checks for correct input
if(b < 1)
{
printf("Error: Input number must be greater than 0\n");
return 0;
}
//Initializing srand seed
srand(time(NULL));

Champion* head1 = buildChampionList(b);
Champion* head2 = buildChampionList(b);

int roundNumber =0;
Champion* temp = NULL;

printf("\n============= PLAYER 1 V PLAYER 2 SHOWDOWN =============\n");

//loops through game options while heads are not NULL
while(head1 != NULL && head2 != NULL){

//prints round and champion lists
roundNumber++;
printf("\n----- ROUND %d -----\n",roundNumber);
printf("Player 1: ");
printChampionList(head1);
printf("\nPlayer 2: ");
printChampionList(head2);
printf("\n");

//mage vs mage case
if(head1->role == M && head2->role == M){
	if(head1->level == head2->level){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	}
	if(head1->level > head2->level){
	head1 = removeChampion(head1);
	head2 = removeChampion(head2);
	temp = createChampion();
	head1 = addChampion(head1,temp);
	head2 = removeChampion(head2);
	printf("Player 1 is a MAGE and player 2 is a MAGE\n");
	printf("Player 1 (MAGE) wins and gains one new champion.\n");
	printf("Player 2 (MAGE) loses one champion.\n");
	}else if(head1->level < head2->level){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	temp = createChampion();
	head2 = addChampion(head2,temp);
	head1 = removeChampion(head1);
	printf("Player 1 is a MAGE and player 2 is a MAGE\n");
	printf("Player 1 (MAGE) loses one champion.\n");
        printf("Player 2 (MAGE) wins and gains one new champion.\n");
	}
//mage vs fighter case
}else if(head1->role == M && head2->role == F || head1->role == F && head2->role == M){
	if(head1->level > head2->level){
		if(head1->role == M){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		temp = createChampion();
		head1 = addChampion(head1,temp);
		printf("Player 1 is a MAGE and player 2 is a FIGHTER\n");
		printf("Player 1 (MAGE) wins and gains one new champion.\n");
	        printf("Player 2 (FIGHTER) loses but with no penalty.\n");
		}else if(head1->role == F){
		head1 = removeChampion(head1);
	        head2 = removeChampion(head2);
		head1 = removeChampion(head1);
		printf("Player 1 is a MAGE and player 2 is a MAGE\n");
		printf("Player 1 (MAGE) wins but gains no reward.\n");
    	        printf("Player 2 (MAGE) loses one champion.\n");
		}
        }else if(head1->level < head2->level){
        	if(head2->role == M){
		head1 = removeChampion(head1);
	        head2 = removeChampion(head2);
                temp = createChampion();
                head2 = addChampion(head2,temp);
		printf("Player 1 is a FIGHTER and player 2 is a MAGE\n");
		printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
                }else if(head2->role == F){
		head1 = removeChampion(head1);
	        head2 = removeChampion(head2);
                head1 = removeChampion(head1);
		printf("Player 1 is a MAGE and player 2 is a FIGHTER\n");
		printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins but gains no reward.\n");
                }
	}
//mage vs support case
}else if(head1->role == M && head2->role == S || head1->role == S && head2->role == M){
	if(head1->level == head2->level){
        head1 = removeChampion(head1);
        head2 = removeChampion(head2);
        }
	if(head1->level > head2->level){
                if(head1->role == M){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
                temp = createChampion();
                head1 = addChampion(head1,temp);
		head2 = removeChampion(head2);
		head2 = removeChampion(head2);
		printf("Player 1 is a MAGE and player 2 is a SUPPORT\n");
		printf("Player 1 (MAGE) wins and gains one new champion.\n");
                printf("Player 2 (SUPPORT) loses two champions.\n");
                }else if(head1->role == S){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		temp = createChampion();
		head1 = addChampion(head1,temp);
		temp = createChampion();
		head1 = addChampion(head1,temp);
                head2 = removeChampion(head2);
		printf("Player 1 is a SUPPORT and player 2 is a MAGE\n");
                printf("Player 1 (SUPPORT) wins and gains two new champions.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
		}
        }else if(head1->level < head2->level){
                if(head2->role == S){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		head1 = removeChampion(head1);
                temp = createChampion();
		head2 = addChampion(head2,temp);
		temp = createChampion();
                head2 = addChampion(head2,temp);
		printf("Player 1 is a MAGE and player 2 is a SUPPORT\n");
		printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (SUPPORT) wins and gains two champions.\n");
                }else if(head2->role == M){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		temp = createChampion();
		head2 = addChampion(head2,temp);
                head1 = removeChampion(head1);
		head1 = removeChampion(head1);
		printf("Player 1 is a SUPPORT and player 2 is a MAGE\n");
		printf("Player 1 (SUPPORT) loses two champions.\n");
                printf("Player 2 (MAGE ) wins and gains one champion.\n");
                }
	}
//mage vs tank case
}else if(head1->role == M && head2->role == T || head1->role == T && head2->role == M){
	if(head1->role == T){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	head1 = removeChampion(head1);
	temp = createChampion();
	head2 = addChampion(head2,temp);
	printf("Player 1 is a TANK and player 2 is a MAGE\n");
	printf("Player 1 (TANK) loses one champion.\n");
        printf("Player 2 (MAGE) gains one champion.\n");
	}else if(head1->role == M){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	head2 = removeChampion(head2);
	temp = createChampion();
	head1 = addChampion(head1,temp);	
	printf("Player 1 is a MAGE and player 2 is a TANK\n");
	printf("Player 1 (MAGE) gains one champion.\n");
	printf("Player 2 (TANK) loses one champion.\n");
	}
//fighter vs fighter case
}else if(head1->role == F && head2->role == F){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	temp = createChampion();
	head1 = addChampion(head1,temp);
	temp = createChampion();
	head2 = addChampion(head2,temp);
	printf("Player 1 is a FIGHTER and player 2 is a FIGHTER\n");
	printf("Both players gain one champion\n");
//support vs fighter case
}else if(head1->role == S && head2->role == F || head1->role == F && head2->role == S){
	if(head1->level == head2->level){
        head1 = removeChampion(head1);
        head2 = removeChampion(head2);
        }

	if(head1->level > head2->level){
                if(head1->role == S){
                head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		temp = createChampion();
                head1 = addChampion(head1,temp);
		printf("Player 1 is a SUPPORT and player 2 is a FIGHTER\n");
		printf("Player 1 (SUPPORT) wins and gains one champion\n");
		printf("Player 2 (FIGHTER) loses but no penalty\n");
                }else if(head1->role == F){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
                head2 = removeChampion(head2);
		printf("Player 1 is a FIGHTER and player 2 is a SUPPORT\n");
                printf("Player 1 (FIGHTER) wins but gains no reward\n");
                printf("Player 2 (SUPPORT) loses one champion\n");
		}
        }else if(head1->level < head2->level){
                if(head2->role == S){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		printf("Player 1 is a FIGHTER and player 2 is a SUPPORT\n");
                printf("Player 1 (FIGHTER) loses by no penalty\n");
                printf("Player 2 (SUPPORT) wins and gains one champion\n");
                temp = createChampion();
                head2 = addChampion(head2,temp);
                }else if(head2->role == F){
		head1 = removeChampion(head1);
                head2 = removeChampion(head2);
		printf("Player 1 is a SUPPORT and player 2 is a FIGHTER\n");
		printf("Player 1 (SUPPORT) loses one champion\n");
		printf("Player 2 (FIGHTER) wins but gains no reward\n");
                head1 = removeChampion(head1);
		}
        }
//tank vs fighter case
}else if(head1->role == T && head2->role == F || head1->role == F && head2->role == T){
	if(head1->role == F){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	printf("Player 1 is a FIGHTER and player 2 is a TANK\n");
	printf("Player 1 (FIGHTER) wins and gains a new champion\n");
	printf("Player 2 (TANK) loses but no penalty\n");
	temp = createChampion();
	head1 = addChampion(head1,temp);
	}else{
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	printf("Player 1 is a TANK and player 2 is a FIGHTER\n");
	printf("Player 1 (TANK) loses but no penalty\n");
	printf("Player 2 (FIGHTER) wins and gains a new champion\n");
	temp = createChampion();
	head2 = addChampion(head2,temp);
	}
//support vs support case
}else if(head1->role == S && head2->role == S){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	printf("Player 1 is a SUPPORT and player 2 is a SUPPORT\n");
	printf("Both players lose one champion\n");
	head1 = removeChampion(head1);
	head2 = removeChampion(head2);
//support vs tank case
}else if(head1->role == S && head2->role == T || head1->role == T && head2->role == S){
	if(head1->role == S){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	printf("Player 1 is a SUPPORT and player 2 is a TANK\n");
	printf("Player 1 (SUPPORT) loses but no penalty\n");
	printf("Player 2 (TANK) wins and gets a new champion\n");
	temp = createChampion();
	head2 = addChampion(head2,temp);
	}else{
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	printf("Player 1 is a TANK and player 2 is a SUPPORT\n");
	printf("Player 1 (TANK) wins and gets a new champion\n");
	printf("Player 2 (SUPPORT) loses but no penalty\n");
	temp = createChampion();
	head1 = addChampion(head1,temp);
	}
//tank vs tank case
}else if(head1->role == T && head2->role == T){
	head1 = removeChampion(head1);
        head2 = removeChampion(head2);
	printf("Player 1 is a TANK and player 2 is a TANK\n");
	printf("Nothing happens - no penalty or reward\n");
}
}
//prints results
printf("\n============= GAME OVER =============\n");

if(head1 == NULL && head2 == NULL){
printf("\nTIE -- both players ran out of champions.\n");
}else if(head1 == NULL && head2 != NULL){
printf("\nPlayer 1 ran out of champions. Player 2 wins.\n");
}else if(head1 != NULL && head2 == NULL){
printf("\nPlayer 2 ran out of champions. Player 1 wins.\n");
}
printf("\n");
//destroys and frees champion linked lists
destroyChampionList(head1);
destroyChampionList(head2);

return 0;
}
