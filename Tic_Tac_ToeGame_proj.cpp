#include<iostream>
#include<time.h>
#include<stdlib.h>
//22-cs-178,Sarim Ammad
using namespace std;

//Global Variable Declarations
int r, c;
char grid[3][3];
bool draw=false, is_ai=0;
int turn=0;
char symbol;

//Function Prototyping
void showboard();
bool gameover();
void moves();
void resetboard();

int main()
{
	int p1score=0, p2score=0,cscore=0, pscore=0;
	bool replay=1;
	int command;
	while(command!=3)
	{
		resetboard();
		system("CLS");
		cout<<"\n\n\n\t\t\t\t\t\t\tTIC-TAC-TOE\n\n\n\n\n";
		cout<<"\t\t 1) Player vs Player \n\n\n\t\t 2) Player vs Computer \n\n\n\t\t 3) Quit\n";
		cout<<"\n\n\n\t\t > ";
		cin>>command;
		replay = 1;
		switch (command)
		{
			case 1:
				while (replay)
				{
					is_ai=0;
					turn=0;
					resetboard();
					while (!gameover())
					{
						moves();
						++turn;
					}
					showboard();
					if (draw)
					{
						cout<<"\n\t\t\t\tThe game was a draw :(\n";
					}
					else if (symbol=='X')
					{
						cout<<"\n\t\t\t\tPlayer 1 Won!"<<endl;
						++p1score;
					}
					else
					{
						cout<<"\n\t\t\t\tPlayer 2 Won!"<<endl;
						++p2score;
					}
					system("pause");
					system("cls");
					cout<<"Player 1 Score: "<<p1score<<endl;
					cout<<"Player 2 Score: "<<p2score<<endl;
					system("pause");
					cout<<"Do you wish to continue? (Enter 1 for Yes & 0 for No)"<<endl;
					cin>>replay;
				}
				break;
			
			case 2:
				is_ai=1;
				while (replay)
				{
					turn=0;
					resetboard();
					while (!gameover())
					{
						moves();
						++turn;
					}
					showboard();
					if (draw)
					{
						cout<<"\n\t\t\t\tThe game was a draw :(\n";
					}
					else if (symbol=='X')
					{
						cout<<"\n\t\t\t\tPlayer 1 Won!"<<endl;
						++pscore;
					}
					else
					{
						cout<<"\n\t\t\t\tComputer has Won!"<<endl;
						++cscore;
					}
					system("pause");
					system("cls");
					cout<<"Player 1 Score: "<<p1score<<endl;
					cout<<"Computer Score: "<<cscore<<endl;
					system("pause");
					cout<<"Do you wish to continue? (Enter 1 for Yes & 0 for No)"<<endl;
					cin>>replay;
				}
		}
	}
	return 0;
}

//Basic function to show board
void showboard()
{
	system("CLS");
	cout<<"\n\t\t\t\t\t\t   TIC-TAC-TOE \n\n\n\n";
	if (turn==0)
	{
		cout<<"\t\t\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t\t\t  1  |  2  |  3  \n";
    	cout<<"\t\t\t\t\t\t_____|_____|_____\n";
    	cout<<"\t\t\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t\t\t  4  |  5  |  6  \n";
    	cout<<"\t\t\t\t\t\t_____|_____|_____\n";
    	cout<<"\t\t\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t\t\t  7  |  8  |  9  \n";
    	cout<<"\t\t\t\t\t\t     |     |     \n";
	}
	else
	{
		cout<<"\t\t\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t\t\t  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<" \n";
    	cout<<"\t\t\t\t\t\t_____|_____|_____\n";
    	cout<<"\t\t\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t\t\t  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<" \n";
    	cout<<"\t\t\t\t\t\t_____|_____|_____\n";
    	cout<<"\t\t\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t\t\t  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<" \n";
    	cout<<"\t\t\t\t\t\t     |     |     \n";
	}
}

//reset board each time we start game
void resetboard()
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			grid[i][j]=' ';
		}
	}
}

//Function to make moves
void moves()
{
	showboard();
	int choice;
	if (turn%2==0)
	{
		symbol='X';
		cout<<"\n\n\t\t\tPlayer 1's Turn: ";
	}
	else
	{
		symbol='O';
		cout<<"\n\n\t\t\tPlayer 2's Turn: ";
	}
	if ((is_ai)&&(symbol=='O'))
	{
		srand(time(NULL));
		choice = (rand()%(9-1+1)+1);
	}
	else
	{
		cin>>choice;
	}
	--choice;
	r=choice/3;
	c=choice-(3*r);
	if (grid[r][c]==' ')
	{
		grid[r][c]=symbol;
	}
	else
	{
		cout<<"\aChoose correct move";
		moves();
	}
}


bool gameover()
{
	draw=false;
	for (int i = 0; i<3; i++)
	{
		if ((grid[i][0]==grid[i][1])&&(grid[i][1]==grid[i][2])&&(grid[i][0]!=' '))
		{
			return true;
		}
		else if ((grid[0][i]==grid[1][i])&&(grid[1][i]==grid[2][i])&&(grid[0][i]!=' '))
		{
			return true;
		}
	}
	if (((grid[0][0]==grid[1][1])&&(grid[1][1]==grid[2][2])&&(grid[0][0]!=' '))||((grid[0][2]==grid[1][1])&&(grid[1][1]==grid[2][0])&&(grid[1][1]!= ' ')))
	{
		return true;
	}
	int spaces=0;
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (grid[i][j]==' ')
			{
				++spaces;
			}
		}
	}
	if (spaces == 0)
	{
		draw = true;
		return true;
	}
}
