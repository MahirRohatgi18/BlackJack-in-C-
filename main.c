#include<stdio.h>


#define DECK_SIZE 52

void menuOne(); //navigation. Has menuOne(); MAIN SCREEN ONE
void menuTwo(); //navigation. Has menuOne(); menuTwo(); menuDeck(); singlePlayer();  MAIN SCREEN TWO
void singlePlayerGame(); //The Game starts place here.
void playerChoice(); //input from user.
void defineStrength(); //adds points to the active player.
void hit(); //adds a card to defined deck
void restartSinglePlayerGame(); //Gives the player the option to play again or quit. randomiseDeck(); singlePlayerGame(); menuOne();
void stand(); //Player contuines with his score and then dealer takes turn.
void initialiseDeck(); //fills up deck array with card Strings. Deck deck[]
void displayDeck(); //displays current card. int cardsDrawn. Deck deck[]
void dealerTurn(); //Where the dealer hits and stands, after dealer hits or stands a winner is decided
	//this was the longest and most difficult function to create as when the player splits more conditions have to be made
	//restartSinglePlayerGame(); dealerHit();
	//int activePlayer, playerOneSplit, playerOnePoints, playerOneSplitPoints, dealerCardRevealed, dealerPoints
void dealerHit(); //Where the dealer draws if < 17, stands or busts. displayDeck(); defineStrength(); dealerHit(); dealerTurns();

int menuScreen = 0, cardsDrawn = 0;
int playerOnePoints = 0, dealerPoints = 0, activePlayer = 0;
int playerOneSplitPoints = 0, playerOneSplit = 0, dealerCardRevealed = 0;
int amountOfDecks = 1;

struct deck { //structure to initilise deck of cards easier
	char* strength;
	char suit[20];
};

typedef struct deck Deck;
//filled arrays which will be used to initilise deck
char* strength[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
char suit[4][20] = { "Clubs", "Diamonds", "Hearts", "Spades" };

void randomiseDeck(Deck[]); //used to shuffle the deck
Deck deck[DECK_SIZE] = { "", "" }; //208 if 4 decks are used, will never reach past 52 so no worries of error

void main() {

	int option; //used for input

	printf("****Welcome to BlackJack****\n");
	printf("Type the corresponding Number to contuine\n");

	initialiseDeck(); //making deck
	randomiseDeck(deck); //shuffling

	menuOne(); //from this function everything else is called from

}

void menuOne()
{

	printf("1: Start Game\n");
	//printf("2: Load Game\n"); had to scrap save and load

	int option;
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		menuTwo(); //screen two
		break;

//	case 2:
		//CODE FOR RELOADING GAME
//		break;

	default:
		printf("\n");
		menuOne();
		break;
	}
}

void menuTwo()
{
	printf("1: Start Game\n");
	printf("2: Main Screen\n");

	int option;
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		printf("\n");
		singlePlayerGame();
		break;

	case 2:
		printf("\n");
		menuOne();
		break;

	default:
		printf("\n");
		menuTwo();
		break;
	}
}

void singlePlayerGame()
{
	int option;

	cardsDrawn = 0;
	playerOnePoints = 0;
	dealerPoints = 0;
	playerOneSplitPoints = 0;
	playerOneSplit = 0;
	dealerCardRevealed = 0;

	printf("****Instructions****\n");
	printf("1.  Hit\n");
	printf("2. Stand\n");
	printf("****Instructions****\n\n");

	printf("Dealer has drawn \n");
	activePlayer = 0;
	displayDeck(); //card 0
	defineStrength();
	cardsDrawn++; //cards drawn = 1
	printf("Face-Down Card\n");
	printf("Dealer has %d points shown\n\n", dealerPoints);
	defineStrength();
	cardsDrawn++; //cards drawn = 2


	printf("Player One has: \n");
	activePlayer = 1;
	displayDeck(); // card 2
	defineStrength();
	cardsDrawn++; //cards drawm = 3
	displayDeck(); // card 3
	defineStrength();
	cardsDrawn++; //cards drawn = 4
	printf("You have %d points\n\n", playerOnePoints);

	if (dealerPoints == 21 && playerOnePoints == 21) {
		printf("Dealer reveals BlackJack and it is a tie\n");
		restartSinglePlayerGame();
	}
	else if (dealerPoints == 21) {
		printf("Dealer reveals BlackJack and wins\n");
		restartSinglePlayerGame();
	}
	else if (playerOnePoints == 21) {
		printf("Player One wins with BlackJack\n");
		restartSinglePlayerGame();
	}
	playerChoice();

}
void playerChoice()
{
	int option;

	switch (playerOneSplit)
	{
	case 0:
		printf("It is your turn\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			hit();
			break;
		case 2:
			stand();
			break;
		default:
			hit();
			break;
		}
	case 1:
		printf("It is your turn\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			hit();
			break;
		case 2:
			stand();
			break;
		//case 3:
			//split();
			//break;
		default:
			hit();
			break;
		}
		break;

	default:
		break;
	}
}

void defineStrength()
{
	if (activePlayer == 0) {
		if (strcmp(deck[cardsDrawn].strength, "Deuce") == 0) {
			dealerPoints += 2;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Three") == 0) {
			dealerPoints += 3;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Four") == 0) {
			dealerPoints += 4;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Five") == 0) {
			dealerPoints += 5;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Six") == 0) {
			dealerPoints += 6;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Seven") == 0) {
			dealerPoints += 7;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Eight") == 0) {
			dealerPoints += 8;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Nine") == 0) {
			dealerPoints += 9;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ten") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Jack") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Queen") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "King") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ace") == 0) {
			if (dealerPoints <= 10) {
				dealerPoints += 11;
			}
			else {
				dealerPoints += 1;
			}

		}
	}
	else if (activePlayer == 1) {
		if (strcmp(deck[cardsDrawn].strength, "Deuce") == 0) {
			playerOnePoints += 2;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Three") == 0) {
			playerOnePoints += 3;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Four") == 0) {
			playerOnePoints += 4;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Five") == 0) {
			playerOnePoints += 5;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Six") == 0) {
			playerOnePoints += 6;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Seven") == 0) {
			playerOnePoints += 7;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Eight") == 0) {
			playerOnePoints += 8;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Nine") == 0) {
			playerOnePoints += 9;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ten") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Jack") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Queen") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "King") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ace") == 0) {
			if (playerOnePoints <= 10) {
				playerOnePoints += 11;
			}
			else {
				playerOnePoints += 1;
			}
		}
	}
}

void restartSinglePlayerGame()
{
	int option;

	randomiseDeck(deck);
	printf("\n1. Another game\n");
	printf("2. Main Menu\n");
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		singlePlayerGame();
		break;
	case 2:
		menuOne();
	default:
		singlePlayerGame();
		break;
	}
}
void dealerTurn()
{
	activePlayer = 0;

	if (playerOneSplit == 1) {
		if (playerOnePoints > 21 && playerOneSplitPoints > 21) {
			printf("Both Split Piles has gone Bust, Dealer Wins");
			restartSinglePlayerGame();
		}
		else if (playerOnePoints > 21) {
			playerOnePoints = playerOneSplitPoints;
			playerOneSplitPoints = 0;
		}
	}

	if (dealerCardRevealed == 0) {
		printf("Dealer reveals : ");
		printf("%5s of %-12s\n", deck[1].strength, deck[1].suit);
		dealerCardRevealed = 1;
	}

	if (playerOneSplitPoints == 0) {
		if (dealerPoints < 17) {
			dealerHit();
		}
		else if (dealerPoints >= 17 && dealerPoints <= 21) {
			printf("Dealer Stands, his final score for the round is : %d\n", dealerPoints);
			if (dealerPoints > playerOnePoints) {
				printf("Dealer wins with : %d\n", dealerPoints);
				restartSinglePlayerGame();
			}
			else if (dealerPoints == playerOnePoints) {
				printf("Dealer wins with : %d\n", dealerPoints);
				restartSinglePlayerGame();
			}
			else {
				printf("Player One wins with : %d\n", playerOnePoints);
				restartSinglePlayerGame();
			}
		}
		else if (dealerPoints > 21) {
			printf("Dealer goes Bust, you win with : %d\n", playerOnePoints);
			restartSinglePlayerGame();
		}
	}
	else if (playerOnePoints <= 21 && playerOneSplitPoints <= 21 && playerOneSplit == 1)
	{
		if (dealerPoints < 17) {
			dealerHit();
		}
		else if (dealerPoints >= 17 && dealerPoints <= 21) {
			printf("Dealer Stands, his final score for the round is : %d\n", dealerPoints);
			if (dealerPoints > playerOnePoints && dealerPoints > playerOneSplitPoints) {
				printf("Dealer wins by beating both Splits with : %d\n", dealerPoints);
				restartSinglePlayerGame();
			}
			else if (playerOnePoints > dealerPoints && dealerPoints > playerOneSplitPoints){
				printf("Player One wins with Stack One : %d\n", playerOnePoints);
				restartSinglePlayerGame();
			}
			else if (playerOnePoints < dealerPoints && dealerPoints < playerOnePoints) {
				printf("Player One wins with Stack Two : %d\n", playerOnePoints);
				restartSinglePlayerGame();
			}
			else if (playerOnePoints > dealerPoints && playerOneSplitPoints > dealerPoints) {
				printf("Player One wins with both stacks : %d and %d\n", playerOnePoints, playerOneSplitPoints);
				restartSinglePlayerGame();
			}
			else {
				printf("Dealer wins with : %d", dealerPoints);
				restartSinglePlayerGame();
			}
		}
		else if (dealerPoints > 21) {
			printf("Dealer goes Bust, you win with : %d and %d\n", playerOnePoints, playerOneSplitPoints);
			restartSinglePlayerGame();
		}
	}

}


void stand()
{
	if (playerOneSplit == 1) {
		if (activePlayer == 1) {
			printf("You choose to stand, your final score for stack One is : %d\n", playerOnePoints);
			activePlayer = 2;
			playerChoice();
		}
		else if(activePlayer == 2) {
			printf("You choose to stand, your final score for stack Two is : %d\n", playerOneSplitPoints);
			dealerTurn();
		}
	}
	else {
		printf("You choose to stand, your final score for the round is : %d\n", playerOnePoints);
		dealerTurn();
	}
}

void hit()
{

	switch (playerOneSplit)
	{
	case 0 :
		displayDeck();
		defineStrength();
		cardsDrawn++;
		printf("You have %d points\n\n", playerOnePoints);


		if (playerOnePoints > 21) {
			printf("You have bust, Dealer wins\n");
			restartSinglePlayerGame();
		}
		else if (playerOnePoints == 21) {
			stand();
		}
		else if (playerOnePoints < 21) {
			playerChoice();
		}
		break;

	case 1:
		if (activePlayer == 1) {
			displayDeck();
			defineStrength();
			cardsDrawn++;
			printf("You have %d points in Stack One\n\n", playerOnePoints);

			if (playerOnePoints > 21) {
				printf("You have bust stack One, Going to Stack Two\n");
				activePlayer = 2;
				playerChoice();

			}
			else if (playerOnePoints == 21) {
				stand();
				activePlayer = 2;
				playerChoice();
			}
			else if (playerOnePoints < 21) {
				playerChoice();
			}
		}
		else if (activePlayer == 2) {
			displayDeck();
			defineStrength();
			cardsDrawn++;
			printf("You have %d points in Stack Two\n\n", playerOneSplitPoints);

			if (playerOneSplitPoints > 21) {
				printf("You have bust stack Two\n");
				playerOneSplitPoints = 0;
				dealerTurn();
			}
			else if (playerOneSplitPoints == 21) {
				stand();
				dealerTurn();
			}
			else if (playerOneSplitPoints < 21) {
				playerChoice();
			}
		}
		break;

	default:
		break;
	}

}
void displayDeck() {
	printf("%5s of %-12s\n", deck[cardsDrawn].strength, deck[cardsDrawn].suit);
}

void randomiseDeck(Deck deck[])
{
	int indexSwap = 0;
	Deck temp = { "", "" };
	srand(time(NULL));
	for (int i = 0; i < DECK_SIZE; i++) {
		indexSwap = rand() % (DECK_SIZE);
		temp = deck[i];
		deck[i] = deck[indexSwap];
		deck[indexSwap] = temp;
	} //creating a temperorary structure deck to store the changed index
}

void initialiseDeck()
{
	for (int i = 0; i < DECK_SIZE; i++) {
		deck[i].strength = strength[i % 13];
		strncpy(deck[i].suit, suit[i / 13], 9);
	}
}
