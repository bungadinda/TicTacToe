//5220600025_BungaAdinda
#include "gameManager.h"

using namespace std;

//do tictactoe
GameManager::GameManager()
{
	cout << "~~~~~~~~~TicTacToe Horrayyyeaaayy!~~~~~~~~~~~" << endl;
	cout << " What's ur name (p1) : " << endl;
	player_1.setName();
	player_1.setPlayerMark('X');
	cout << " What's ur name (p2) : " << endl;
	player_2.setName();
	player_2.setPlayerMark('O');

	player_turn = player_1;

}

//check if there's winner
bool GameManager::checkWin()
{
	
	if (board.getDiagonal() || board.getHorizontal() || board.getVertical())
	{
		isWin = true;
		switchTurn();
		player_win = player_turn;
		board.Display();
		return true;
	}
	else if (board.isFull())
	{
		isDraw = true;
		return true;
	}
	else
	{
		return false;
	}
}

//function for switch player
void GameManager::switchTurn()
{
	if (player_turn == player_1)
	{
		player_turn = player_2;
	}
	else if (player_turn == player_2)
	{
		player_turn = player_1;
	}
}

//function for input coord
void GameManager::makeMove()
{
	int coorX, coorY;
	cout << player_turn.getName() << "'s turn" << endl;
	board.Display();
	cout << "Insert coordinate : " << endl;
	cin >> coorX; cin >> coorY;
	if (board.isLegal(coorX, coorY))
	{
		board.setMark(player_turn.getPlayerMark(), coorX, coorY);
		switchTurn();
	}
	else {
		cout << "Cannot move, try another coordinate :(" << endl;
	}
}

//update state
void GameManager::announce()
{
	if (isWin)
	{
		// cout << "The Winner is: " << player_win.getName() << endl;
		player_1.updateState(player_win);
		player_2.updateState(player_win);
		cout << endl << "Current Score ^^ : " << endl;
		cout << player_1.getName() << ": " << player_1.getWins() << endl;
		cout << player_2.getName() << ": " << player_2.getWins() << endl;
	}
	else if (isDraw)
	{
		cout << "It's a Draw! ^^" << endl;
	}
}

//reset game for new one
void GameManager::newGame()
{
	board.Reset();
	if (!board.isEmpty())
	{
		cout << "Error";
		exit;
	}
	else
	{
		isWin = false;
		isDraw = false;
	}
}

int main()
{
	GameManager game1;
	char retry;
	bool gameState = true;
	while (gameState)
	{
		game1.makeMove();
		if (game1.checkWin())
		{
			game1.announce();
			cout << endl << "Let's play again? :D (Y/N)";
			cin >> retry;
			if (retry == 'Y')
			{
				game1.newGame();
			}
			else
			{
				cout << endl << "Good Game, Thank you for playing see u when i see u ^^ ";
				break;
			}
		}
	}

	return 0;
}