#include <stdio.h>
#include <stdbool.h>


char get_winner (char board[3][3]){

	char winner='-';

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			board[i][j]		
		}
	}

	return winner;
}

int main (){

	char board[3][3]={
		{ '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
	};

	printf("%c",get_winner(board));


	return 0;	
}