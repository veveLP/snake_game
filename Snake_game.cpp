#include <iomanip> 
#include <iostream> 
#include <string>
#include <conio.h>
#include <Windows.h>
#include <ctime>


using namespace std;

	int x = 1, y = 1;
	int tail = 0;
	int tail_last = 0;
	int moved = 0;
	bool gameover = false;
	int berry_pocet = 0;
	int time_multi = 500;
	double score = 0;
	bool was_berry = true;
	int returned = 0;
	int High_score = 0;
	string poz[11][11];
	int log_x[1000];
	int log_y[1000];
	int last_w = 0;
	int last_h = 0;
	int snake1_i = 5;
	int snake1_j = 5;
	
	int variable_set() {
		 x = 1, y = 1;
		 tail = 0;
		 tail_last = 0;
		 moved = 0;
		 gameover = false;
		 berry_pocet = 0;
		 time_multi = 500;
		 score = 0;
		 was_berry = true;
		 returned = 0;
		 //High_score = 0;
		 log_x[1000];
		 log_y[1000];
		 last_w = 0;
		 last_h = 0;
		 snake1_i = 5;
		 snake1_j = 5; return 0; }

int berry() {
start:
	if (poz[x][y] == "x " && was_berry == true) { berry_pocet = 0; score++;  time_multi /= 1.05; was_berry = false; tail++; }
	if (poz[x][y] == "0 ") { was_berry = true; }
	else { was_berry = false; }
	if (berry_pocet == 0) {
		srand(time(0));
		y = rand() % 9 + 1;
		srand(time(0));
		x = rand() % 9 + 1;
		if (poz[x][y] == "x " || poz[x][y] == "# ") {

			goto start;
		}
		else { poz[x][y] = "0 ";  berry_pocet=1; }
	}
	return 0;
}

int getpress() {

	if (_kbhit()) {

		switch (_getch()) {

		case 'a':

			returned = 3;
			
			return 0;
			break;

		case 'd':

			returned = 4;
			return 0;
			break;

		case 'w':

			returned = 1;
			return 0;
			break;

		case 's':

			returned = 2;
			return 0;
			break;

		case 'x':

			gameover = true;
			return 0;
			break;
		default: break;

			
		}

	}
	
}


	


int move() {
	
	
	poz[snake1_i][snake1_j] = "  "; 
	
	
	if (returned == 1) { snake1_i--; if (snake1_i < 1) { gameover = true; }}
	if (returned == 2) { snake1_i++; if (snake1_i > 9) { gameover = true; }}
	if (returned == 3) { snake1_j--; if (snake1_j < 1) { gameover = true; }}
	if (returned == 4) { snake1_j++; if (snake1_j > 9) { gameover = true; }}
	
	
	poz[snake1_i][snake1_j] = "x ";


	
	return 0;
}

int draw() {
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++) {
			






			cout << poz[i][j] << "";
			
			if (i == 0 && j == 10) {
				cout << "\tScore:" << score;
			}

		}
		cout << "\n";
	}
	return 0;
	
}

int setup() {
	
	for (int i =0;i<11;i++)
	{
		for (int j = 0; j < 11; j++) {
			if (i == 0) {poz[i][j] = "# "; }
			else if (i == 10) { poz[i][j] = "# "; }
			else if (j == 0) { poz[i][j] = "#"; }
			else if (j == 10) { poz[i][j] = " #"; }
			else { poz[i][j] = "  "; }
		}
	}
	return 0;
}

int main()
{
	int rep = 0;
	while (rep != 2) {
		variable_set();
		setup();
		cout << "Stiskni enter pro start\n";

		cin.get();
		system("cls");
		draw();
		while (gameover == false) {
			berry();
			getpress();
			system("cls");
			move();

			draw();
			Sleep(time_multi);

		}
		system("cls");
		if (score > High_score) { High_score = score; }
		cout << "Game Over\n";
		cout << "High score:" << High_score << "\n";
		cout << "Chcete hrat znovu?\n";
		cout << "1. Ano\n";
		cout << "2. Ne\n";
		cin >> rep;
		cin.get();

	}
	system("cls");
	cout << "Dekuji za hrani\nHru vytvoril Lukas Houzar\n";
	cin.get();
}


