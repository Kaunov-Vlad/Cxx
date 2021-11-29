#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

bool GameOver;
int height = 15;
int width = 140;
int Y;
int X = width / 2;
int WallX, WallY, WallYChance, TWallX, TWallY, TWallYChance;
int CoinX, CoinY, CoinChance, TCoinX, TCoinY, TCoinChance;
int Bonus, speed, CoinRand, TCoinRand, HP, Fon, TFon, TrFon, Texit = 1;
long score;
enum MenuControl {One = 1, Two, Tree};
MenuControl MainMenu;
enum PlayerControl { WUp = 1, WMi, WDo };
PlayerControl StartMove;
string SetCoin = "none";
string Diff = "easy";

void Setup(){
	srand (time(NULL));
	GameOver = false;
	StartMove = WMi;
	Y = 7;
	HP = 1;
	Fon = 0;
	TFon = 0;
	TrFon = 0;
	speed = 1;
	CoinX = -10;
	TCoinX = 160;
	WallX = 141;
	TWallX = -71;
	score = 0;
	WallYChance = 1;
	if (WallYChance == 1) {
		WallY = 2;
	}
	else {
		if (WallYChance == 2) {
			WallY = 7;
		}else {
			WallY = 12;
		}
	}

	CoinChance = rand() % 2;
	if (CoinChance == 1) {
		CoinY = 2;
	}
	else {
		if (CoinChance == 2) {
			CoinY = 7;
		}
		else {
			CoinY = 12;
		}
	}

	TCoinChance = rand() % 2;
	if (TCoinChance == 1) {
		TCoinY = 2;
	}
	else {
		if (TCoinChance == 2) {
			TCoinY = 7;
		}
		else {
			TCoinY = 12;
		}
	}

	TWallYChance = 3;
	if (TWallYChance == 1) {
		TWallY = 2;
	}else {
		if (TWallYChance == 2) {
			TWallY = 7;
		}
		else {
			TWallY = 12;
		}
	}
}

void Draw() {
	system("cls");
	if (score < 10) {
		Bonus = 5;
	}
	else {
		if (score > 9 && score < 100) {
			Bonus = 4;
		}
		else {
			if (score > 99 && score < 1000) {
				Bonus = 3;
			}
			else {
				if (score > 999 && score < 10000) {
					Bonus = 2;
				}
				else {
					if (score > 9999 && score < 100000) {
						Bonus = 1;
					}
					else {
						Bonus = 0;
					}
				}
			}
		}
	}
	cout << "- score: ";
	for (int O = 0; O < Bonus; O++) {
		cout << "0";
	}
	cout << score << " --- Hp: " << HP << "/3 ";
	for (int i = 0; i < width - 28; i++) {
		cout << "-";
	}
	for (int j = 0; j < height; j++) {
		for(int V = 0; V < width; V++){
			if (Y == j && X - 1 == V) {
				cout << "/";
			}
			else {
				if (Y == j && X + 1 == V) {
					cout << "\\";
				}
				else {
					if (Y - 1 == j && X == V) {
						cout << "_";
					}else{
						if (Y == j && X == V) {
							cout << "_";
						}
						else {
							if (WallY == j && WallX + 6 == V || WallY - 1 == j && WallX + 6 == V
								|| WallY - 2 == j && WallX + 6 == V || WallY + 1 == j && WallX + 6 == V
								|| WallY + 2 == j && WallX + 6 == V || WallY == j && WallX + 5 == V 
								|| WallY - 1 == j && WallX + 5 == V || WallY - 2 == j && WallX + 5 == V 
								|| WallY + 1 == j && WallX + 5 == V || WallY + 2 == j && WallX + 5 == V) {
								cout << "|";
							}
							else {
								if (TWallY == j && TWallX - 6 == V || TWallY - 1 == j && TWallX - 6 == V
									|| TWallY - 2 == j && TWallX - 6 == V || TWallY + 1 == j && TWallX - 6 == V
									|| TWallY + 2 == j && TWallX - 6 == V || TWallY == j && TWallX - 5 == V 
									|| TWallY - 1 == j && TWallX - 5 == V || TWallY - 2 == j && TWallX - 5 == V 
									|| TWallY + 1 == j && TWallX - 5 == V || TWallY + 2 == j && TWallX - 5 == V) {
									cout << "|";
								}
								else {
									if (CoinY == j && CoinX == V || TCoinY == j && TCoinX == V) {
										cout << "O";
									}
									else {
										cout << " ";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int p = 0; p < width - 42; p++) {
		cout << "-";
	}
	cout << " w: move up --- s: move down --- x: exit -";
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			StartMove = WUp;
			break;
		case 's':
			StartMove = WDo;
			break;
		case 'x':
			GameOver = true;
			break;
		default:
			StartMove = WMi;
			break;
		}
	}
}

void Mexa() {
	switch (StartMove) {
	case WUp:
		if (Y == 12) {
			Y = 7;
		}else {
			if (Y == 7) {
				Y = 2;
			}
		}
		StartMove = WMi;
		break;
	case WDo:
		if (Y == 2) {
			Y = 7;
		}
		else {
			if (Y == 7) {
				Y = 12;
			}
		}
		StartMove = WMi;
		break;
	}

	

	if (speed == 2) {
		if (WallY == Y && WallX == X || WallY == Y && WallX == X - 1) {
			HP--;
			TFon = 12;
		}
		if (TWallY == Y && TWallX == X || TWallY == Y && TWallX == X + 1) {
			HP--;
			TFon = 12;
		}
	}
	else {
		if (speed == 3) {
			if (WallY == Y && WallX == X || WallY == Y && WallX == X - 1 || WallY == Y && WallX == X - 2) {
				HP--;
				TFon = 12;
			}
			if (TWallY == Y && TWallX == X || TWallY == Y && TWallX == X + 1 || TWallY == Y && TWallX == X + 2) {
				HP--;
				TFon = 12;
			}
		}
		else {
			if (speed == 4) {
				if (WallY == Y && WallX == X || WallY == Y && WallX == X - 1 || WallY == Y && WallX == X - 2 
					|| WallY == Y && WallX == X - 3 || WallY == Y && WallX == X - 4) {
					HP--;
					TFon = 12;
				}
				if (TWallY == Y && TWallX == X || TWallY == Y && TWallX == X + 1 || TWallY == Y && TWallX == X + 2 
					|| TWallY == Y && TWallX == X + 3 || TWallY == Y && TWallX == X + 4) {
					HP--;
					TFon = 12;
				}
			}
			else {
				if (WallY == Y && WallX == X) {
					HP--;
					TFon = 12;
				}
				if (TWallY == Y && TWallX == X) {
					HP--;
					TFon = 12;
				}
			}
		}
	}

	if (speed == 2) {
		if (Y == CoinY && X == CoinX || Y == CoinY && X - 1 == CoinX || CoinX > 141) {
			if (Y == CoinY && X == CoinX || Y == CoinY && X - 1 == CoinX) {
				CoinRand = rand() % 2;
				if (CoinRand == 1) {
					if (HP < 3) {
						HP++;
						Fon = 12;
					}
				}
				else {
					score += rand() % 900 + 100;
					TrFon = 12;
				}
			}
			CoinX = rand() % 1000 - 1500;
		}
	}
	else {
		if (speed == 3) {
			if (Y == CoinY && X == CoinX || Y == CoinY && X - 1 == CoinX || Y == CoinY && X - 2 == CoinX || CoinX > 141) {
				if (Y == CoinY && X == CoinX || Y == CoinY && X - 1 == CoinX || Y == CoinY && X - 2 == CoinX) {
					CoinRand = rand() % 2;
					if (CoinRand == 1) {
						if (HP < 3) {
							HP++;
							Fon = 12;
						}
					}
					else {
						score += rand() % 900 + 100;
						TrFon = 12;
					}
				}
				CoinX = rand() % 1000 - 1500;
			}
		}
		else {
			if (speed == 4) {
				if (Y == CoinY && X == CoinX || Y == CoinY && X - 1 == CoinX || Y == CoinY && X - 2 == CoinX 
					|| Y == CoinY && X - 3 == CoinX || Y == CoinY && X - 4 == CoinX || CoinX > 141) {
					if (Y == CoinY && X == CoinX || Y == CoinY && X - 1 == CoinX || Y == CoinY && X - 2 == CoinX
						|| Y == CoinY && X - 3 == CoinX || Y == CoinY && X - 4 == CoinX) {
						CoinRand = rand() % 2;
						if (CoinRand == 1) {
							if (HP < 3) {
								HP++;
								Fon = 12;
							}
						}
						else {
							score += rand() % 900 + 100;
							TrFon = 12;
						}
					}
					CoinX = rand() % 1000 - 1500;
				}
			}
			else {
				if (Y == CoinY && X == CoinX || CoinX > 141) {
					if (Y == CoinY && X == CoinX) {
						CoinRand = rand() % 2;
						if (CoinRand == 1) {
							if (HP < 3) {
								HP++;
								Fon = 12;
							}
						}
						else {
							score += rand() % 900 + 100;
							TrFon = 12;
						}
					}
					CoinX = rand() % 1000 - 1500;
				}
			}
		}
	}

	if (speed == 2) {
		if (Y == TCoinY && X == TCoinX || Y == TCoinY && X - 1 == TCoinX || TCoinX < 0) {
			if (Y == TCoinY && X == TCoinX || Y == TCoinY && X - 1 == TCoinX) {
				TCoinRand = rand() % 2;
				if (TCoinRand == 1) {
					if (HP < 3) {
						HP++;
						Fon = 12;
					}
				}
				else {
					score += rand() % 900 + 100;
					TrFon = 12;
				}
			}
			TCoinX = rand() % 1000 - 140;
		}
	}
	else {
		if (speed == 3) {
			if (Y == TCoinY && X == TCoinX || Y == TCoinY && X - 1 == TCoinX || Y == TCoinY && X - 2 == TCoinX || TCoinX < 0) {
				if (Y == TCoinY && X == TCoinX || Y == TCoinY && X - 1 == TCoinX || Y == TCoinY && X - 2 == TCoinX) {
					TCoinRand = rand() % 2;
					if (TCoinRand == 1) {
						if (HP < 3) {
							HP++;
							Fon = 12;
						}
					}
					else {
						score += rand() % 900 + 100;
						TrFon = 12;
					}
				}
				TCoinX = rand() % 1000 - 140;
			}
		}
		else {
			if (speed == 4) {
				if (Y == TCoinY && X == TCoinX || Y == TCoinY && X - 1 == TCoinX || Y == TCoinY && X - 2 == TCoinX
					|| Y == TCoinY && X - 3 == TCoinX || Y == TCoinY && X - 4 == TCoinX || TCoinX < 0) {
					if (Y == TCoinY && X == TCoinX || Y == TCoinY && X - 1 == TCoinX || Y == TCoinY && X - 2 == TCoinX
						|| Y == TCoinY && X - 3 == TCoinX || Y == TCoinY && X - 4 == TCoinX) {
						TCoinRand = rand() % 2;
						if (TCoinRand == 1) {
							if (HP < 3) {
								HP++;
								Fon = 12;
							}
						}
						else {
							score += rand() % 900 + 100;
							TrFon = 12;
						}
					}
					TCoinX = rand() % 1000 - 140;
				}
			}
			else {
				if (Y == TCoinY && X == TCoinX || TCoinX < 0) {
					if (Y == TCoinY && X == TCoinX) {
						TCoinRand = rand() % 2;
						if (TCoinRand == 1) {
							if (HP < 3) {
								HP++;
								Fon = 12;
							}
						}
						else {
							score += rand() % 900 + 100;
							TrFon = 12;
						}
					}
					TCoinX = rand() % 1000 - 140;
				}
			}
		}
	}

	if (WallX < 0) {
		WallX = 141;
		if (Diff == "easy") {
			WallYChance = rand() % 3 + 1;
			if (WallYChance == 1) {
				WallY = 2;
			}
			else {
				if (WallYChance == 2) {
					WallY = 7;
				}
				else {
					WallY = 12;
				}
			}
		}
		else {
			WallYChance = rand() % 2;
			if (WallYChance == 1) {
				if (TWallY == 2) {
					WallY = 7;
				}
				else {
					WallY = 2;
				}
			}
			else {
				if (WallYChance == 2) {
					if (TWallY == 7) {
						WallY = 2;
					}
					else {
						WallY = 7;
					}
				}
				else {
					if (TWallY == 12) {
						WallY = 7;
					}
					else {
						WallY = 12;
					}
				}
			}
		}
	}

	if (TWallX > 140) {
		TWallX = -1;
		TWallYChance = rand() % 2;
		if (TWallYChance == 1) {
			if (WallY == 2) {
				TWallY = 7;
			}
			else {
				TWallY = 2;
			}
		}
		else {
			if (TWallYChance == 2) {
				if (WallY == 7) {
					TWallY = 2;
				}
				else {
					TWallY = 7;
				}
			}
			else {
				if (WallY == 12) {
					TWallY = 7;
				}
				else {
					TWallY = 12;
				}
			}
		}
	}
}

int main()
{
	int exit = 1;
	int Menu;
	system("mode con cols=30 lines=22");
	system("color C0");
	for(;exit != 0;){
		system("cls");
		system("color C0");
		Texit = 1;
		
		cout << "\n\t-------------\n\t  Main menu\n\t-------------" << endl;
		cout << "\n\tPlay!\t[1]\n\tSetting\t[2]\n\tExit\t[3]" << endl;

		if (_kbhit()) {
			switch (_getch()) {
			case '1':
				system("mode con cols=140 lines=17");
				Setup();
				system("cls");
				for (; !GameOver; score++) {
					Draw();
					Input();
					Mexa();
					if (score < 100) {
						speed = 1;
						WallX--;
						if (Diff == "normal") {
							TWallX++;
						}
						if (SetCoin == "many") {
							CoinX++;
							TCoinX--;
						}
						else {
							if (SetCoin == "few") {
								CoinX++;
							}
							else {}
						}
					}
					else {
						if (score > 99 && score < 300) {
							speed = 2;
							WallX -= 2;
							if (Diff == "normal") {
								TWallX += 2;
							}
							if (SetCoin == "many") {
								CoinX += 2;
								TCoinX -= 2;
							}
							else {
								if (SetCoin == "few") {
									CoinX += 2;
								}
								else {}
							}
						}
						else {
							if (score > 299 && score < 499) {
								speed = 3;
								WallX -= 3;
								if (Diff == "normal") {
									TWallX += 3;
								}
								if (SetCoin == "many") {
									CoinX += 3;
									TCoinX -= 3;
								}
								else {
									if (SetCoin == "few") {
										CoinX += 3;
									}
									else {}
								}
							}
							else {
								speed = 4;
								WallX -= 5;
								if (Diff == "normal") {
									TWallX += 5;
								}
								if (SetCoin == "many") {
									CoinX += 5;
									TCoinX -= 5;
								}
								else {
									if (SetCoin == "few") {
										CoinX += 5;
									}else{}
								}
							}
						}
					}
					if (HP < 1) {
						GameOver = true;
					}
					if (Fon == 12) {
						system("color 5F");
						Fon--;
					}
					else {
						if (Fon == 1) {
							system("color C0");
							Fon--;
						}
						else {
							if (Fon > 0) {
								Fon--;
							}
						}
					}

					if (TFon == 12) {
						system("color 4F");
						TFon--;
					}
					else {
						if (TFon == 1) {
							system("color C0");
							TFon--;
						}
						else {
							if (TFon > 0) {
								TFon--;
							}
						}
					}

					if (TrFon == 12) {
						system("color 6F");
						TrFon--;
					}
					else {
						if (TrFon == 1) {
							system("color C0");
							TrFon--;
						}
						else {
							if (TrFon > 0) {
								TrFon--;
							}
						}
					}

					Sleep(1000 / 100);
				}
				system("cls");
				system("mode con cols=30 lines=22");
				system("color 10");
				cout << "\n\n\n\n\n\n\n\tYour score: " << score << "\n\n\n" << endl;
				system("pause");
				break;
			case '2':
				for (; Texit != 0;) {
					system("cls");
					cout << "\n Game settings\n\n Difficulty: " << Diff << "\t[1]\n Coins: " 
						<< SetCoin << "\t\t[2]\n Back: \t\t\t[3]\n\n\n" << endl;

					if (_kbhit()) {
						switch (_getch()) {
						case '1':
							if (Diff == "normal") {
								Diff = "easy";
							}
							else {
								if (Diff == "easy") {
									Diff = "normal";
								}else{}
							}
							break;
						case '2':
							if (SetCoin == "many") {
								SetCoin = "none";
							}
							else {
								if (SetCoin == "none") {
									SetCoin = "few";
								}
								else {
									if (SetCoin == "few") {
										SetCoin = "many";
									}else{}
								}
							}
							break;
						default:
							Texit = 0;
						}
					}
				}
				break;
			case '3':
				exit = 0;
				break;
			}
		}
	}
}