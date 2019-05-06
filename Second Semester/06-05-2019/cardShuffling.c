#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define FACES 13


struct card{
	unsigned int face : 4;
	unsigned int suit : 2;
	unsigned int color: 1;
};

typedef struct card Card;
const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
    "Nine", "Ten", "Jack", "Queen", "King"};
const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};
void fillDeck( Card * const wDeck );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );


int main(){
	Card* deck[CARDS];
	srand(time(NULL));
	fillDeck(deck);
	shuffle(deck);
	deal(deck);
	return 0;
}

void fillDeck(Card* const wDeck){
	for(int i=0; i<CARDS; i++){
		wDeck[i].face = i % (CARDS/4);
		wDeck[i].suit = i / (CARDS/4);
		wDeck[i].color = i / (CARDS/2);
	}
}

void shuffle(Card* const wDeck){
	Card temp;
	for(int i=0; i<CARDS; i++){
		int j = rand() % CARDS;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card* const wDeck){
	for(int i=0; i<CARDS; i++){
		printf( "%5s of %-8s %c %s", 
            face[wDeck[ i ].face], suit[wDeck[ i ].suit], wDeck[ i ].color ? 'b' : 'r',
            ( i + 1 ) % 4 ? " " : "\n");
	}
}