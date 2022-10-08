#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

bool mati;
const int width = 20;
const int height = 20;
int x, y, buahx, buahy, score;
int ekorx[100], ekory[100];
int nekor;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
char kp;


void pengaturan();
void tampilan();
void input();
void logic();
void kalah();
void hati();

int main()
{
	do
	{
		srand(time(NULL));
		pengaturan();

		while(!mati){
			tampilan();
			input();
			logic();
		}

		hati();

		cout << endl ;

		kalah();

	} while (kp != 'n');		

	return 0;
}

void pengaturan()
{
	mati = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	buahx = rand() % 19 + 1;
	buahy = rand() % 19 + 1;
	score = 0;
	nekor = 0;

}

void tampilan()
{
	system("cls");

	cout << "score" << endl;
	cout << score << endl;

	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}

	for (int i = 1; i < width; i++)
	{
		cout << endl;
		for (int j = 0; j <= height; j++)
		{
			if (j == 0 || j == height)
			{
				cout << "#";
			}
			else if (i == x && j == y)
			{
				cout << "O" ;
			}
			else if (i == buahx && j == buahy)
			{
				cout << "M" ;
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nekor; ++k)
				{
					if (ekorx[k] == i && ekory[k] == j)
					{
						cout << "o" ;
						print = true;
					}
				}

				if (!print)
				{
					cout << " " ;
				}
			}
		}
	}

	cout << endl;

	for (int i = 0; i < width+1; i++)
	{
		cout << "#" ;
	}
}
void input()
{
	if (_kbhit())
	{
		if (_getch() == 224)
		{
			switch (_getch())
			{
				case 75:
					dir = LEFT ;
					break;
				case 77:
					dir = RIGHT ;
					break;
				case 72:
					dir = UP ;
					break;
				case 80:
					dir = DOWN ;
					break;					
			}
		}
		else
		{
			switch (_getch()){
				case ' ':
					mati = true;
					break;
			}
		}
	}
}

void logic()
{
	int prevx = ekorx[0];
	int prevy = ekory[0];
	int prev2x, prev2y;
	ekorx[0] = x;
	ekory[0] = y;

	for (int i = 1; i < nekor; i++)
	{
		prev2x = ekorx[i];
		prev2y = ekory[i];
		ekorx[i] = prevx;
		ekory[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;

	}

	for (int i = 1; i < nekor; ++i)
	{
		if (x == ekorx[i] && y == ekory[i])
		{
			mati = true;
		}
	}

	switch(dir)
	{
		case LEFT:
			y-- ;
			break;
		case RIGHT:
			y++ ;
			break;
		case UP:
			x-- ;
			break;
		case DOWN:
			x++ ;
			break;
		default:
			break;				
	}

	if (x > width || x < 0 || y > height || y < 0)
	{
		mati = true ;
	}

	if (x == buahx && y == buahy)
	{
		score += 10;
		buahx = rand() % 19 + 1;
		buahy = rand() % 19 + 1;
		nekor++ ;
	}
}

void kalah()
{
	cout << "ANDA KALAH" << endl;

	cout << endl ;

	cout << "Total Perolehan Score: " << score << endl;

	cout << "Letak Buah: " << buahx << " , " << buahy << endl;

	cout << endl;

	cout << "Tekan 'n' untuk keluar | Tekan apa saja untuk bermain lagi " ;
	cin >> kp;
}

void hati()
{
	system("cls");
	for (int i = 0; i < 36; ++i)
	{
		cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 7 && i <= 14) || (i >= 22 && i <= 29))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}

	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 5 && i <= 16) || (i >= 20 && i <= 31))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 3 && i <= 17) || (i >= 19 && i <= 33))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 3; ++i)
	{
		for (int i = 0; i < 36; ++i)
		{
			if (i >= 2 && i <= 34)
			{
				cout << "#" ;
			}
			else
			{
				cout << " " ;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 3 && i <= 33))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 4 && i <= 32))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 6 && i <= 30))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 9 && i <= 27))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 13 && i <= 23))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ((i >= 16 && i <= 20))
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
	cout << endl;

	for (int i = 0; i < 36; ++i)
	{
		if ( i == 18 )
		{
			cout << "#" ;
		}
		else
		{
			cout << " " ;
		}
	}
}
