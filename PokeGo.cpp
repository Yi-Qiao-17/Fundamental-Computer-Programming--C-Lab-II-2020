#include"pet.h"//pokemon
#include "rlutil.h"
#include<iostream>
#include <fstream>
#include<string>
#include<sstream>
#include <stdexcept> 
#include<iomanip>
using namespace std;
using std::logic_error;
using std::out_of_range;

char lvl[100][100] = { ' ' };//地圖
string poke[32] = { "" };//讀檔
Pet pokemons[32];//存取32隻pokemon
Player NPC[13];//存取13個NPC
int win_cnt = 0;//記錄贏幾次
int x, y;
int row = rlutil::trows(), col = rlutil::tcols();//row:30(高),col:120(寬)
void Readmap() {
	int cnt = 0;
	ifstream fin("yzumap.txt");
	string s;
	while (getline(fin, s)) {
		for (int i = 0; i < s.size(); i++) {
			lvl[cnt][i] = s[i];
		}
		cnt++;
		//cout << endl;
	}

}

void DrawMap() {
	rlutil::cls();
	rlutil::locate(0, 0);
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 100; j++) {
			if (lvl[i][j] == ';') {
				rlutil::setColor(10);//綠
			}
			else if (lvl[i][j] == '!') {
				rlutil::setColor(6);//棕
			}
			else if (lvl[i][j] == '~') {
				rlutil::setColor(11);//藍
			}
			else if (lvl[i][j] == '#') {
				rlutil::setColor(14);//黃
			}
			cout << lvl[i][j];
			rlutil::resetColor();
		}
		cout << endl;
	}
}

void ReadPokemons() {
	int cnt = 0;
	ifstream fin("pokemons.csv");
	string data;
	while (getline(fin, data)) {
		poke[cnt++] = data;
	}
	/*for (int i = 0; i < sizeof(poke) / sizeof(poke[0]); i++) {
		cout << poke[i] << endl;
	}*/
	//sizeof(poke) / sizeof(poke[0]);
	stringstream ss;
	for (int i = 0; i < sizeof(poke) / sizeof(poke[0]); i++) {
		int no, hp, atk, def, speed, ability;
		string name, type;
		ss.str("");
		ss.clear();
		ss << poke[i];
		int cnt2 = 0;
		while (getline(ss, data, ',')) {
			stringstream ss2;
			ss2.str("");
			ss2.clear();
			if (cnt2 == 0) {
				ss2<<data;
				ss2 >> no;
			}
			else if (cnt2 == 1) {
				name = data;
			}
			else if (cnt2 == 2) {
				type = data;
			}
			else if (cnt2 == 3) {
				ss2 << data;
				ss2 >> hp;
			}
			else if (cnt2 == 4) {
				ss2 << data;
				ss2 >> atk;
			}
			else if (cnt2 == 5) {
				ss2 << data;
				ss2 >>def;
			}
			else if (cnt2 == 6) {
				ss2 << data;
				ss2 >>speed;
			}
			else if (cnt2 == 7) {
				ss2 << data;
				ss2 >> ability;
			}
			cnt2++;
		}
		Pet p(no, name, type, hp, hp, atk, def, speed, ability);
		pokemons[i] = p;
	}

}

void Readicon(int no,int setx) {
	string s;
	int cnt = 1;
	if (no == 1) {
		ifstream fin("001.txt");
		while (getline(fin, s)){
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 2) {
		ifstream fin("002.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 3) {
		ifstream fin("003.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 4) {
		ifstream fin("004.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 5) {
		ifstream fin("005.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 6) {
		ifstream fin("006.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 7) {
		ifstream fin("007.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 8) {
		ifstream fin("008.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 9) {
		ifstream fin("009.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 10) {
		ifstream fin("010.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 11) {
		ifstream fin("011.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 12) {
		ifstream fin("012.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 13) {
		ifstream fin("013.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 14) {
		ifstream fin("014.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 15) {
		ifstream fin("015.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 16) {
		ifstream fin("016.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 17) {
		ifstream fin("017.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 18) {
		ifstream fin("018.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 19) {
		ifstream fin("019.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 20) {
		ifstream fin("020.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 21) {
		ifstream fin("021.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 22) {
		ifstream fin("022.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 23) {
		ifstream fin("023.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 24) { 
			ifstream fin("024.txt");
			while (getline(fin, s)) {
				rlutil::locate(setx, cnt++);
				cout << s << endl;
			}
	}
	else if (no == 25) {
		ifstream fin("025.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 26) {
		ifstream fin("026.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 27) {
		ifstream fin("027.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 28) {
		ifstream fin("028.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 29) {
		ifstream fin("029.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 30) {
		ifstream fin("030.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 31) {
		ifstream fin("031.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	else if (no == 32) {
		ifstream fin("032.txt");
		while (getline(fin, s)) {
			rlutil::locate(setx, cnt++);
			cout << s << endl;
		}
	}
	cnt = 1;

}

void CatchPet(Player& player, char c) {
	int grass[41] = { 1,1,2,2,3,3,4,5,6,7,8,9,10,10,11,11,12,12,13,13,14,14,15,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	int water[35] = { 1,2,3,4,5,6,7,7,8,8,9,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	int Random;
	if (c == ';') {
		int x = rand() % 41;//0~40
		Random = grass[x];
	}
	else if (c == '~') {
		int x = rand() % 35;//0~34
		Random = water[x];
	}
	else Random = rand() % 32+1;//1~32
	Pet P = pokemons[Random - 1];
	rlutil::cls();
	rlutil::locate(1, 1);
	Readicon(P.getNO(), 1);
	int  i = 5;
	//cout << "=============================================================" << endl;
	rlutil::locate(col / 2, 1+i);
	cout << " PokeGo : " << P.getName() << "(" << P.getHp() << "/" << P.getMaxHp() << ")";
	rlutil::locate(col / 2, 3+i);
	cout << "     No : " << P.getNO();
	rlutil::locate(col / 2, 5 + i);
	cout << "   Type : " << P.getType();
	rlutil::locate(col / 2, 7 + i);
	cout << " Attack : " << P.getAttack();
	rlutil::locate(col / 2, 9 + i);
	cout << "Defense : " << P.getDefense();
	rlutil::locate(col / 2, 11 + i);
	cout << "  Speed : " << P.getSpeed();
	rlutil::locate(col / 2, 13 + i);
	cout << " Ability : " << P.getAbility() << endl;
	rlutil::locate(1, 25);
	/*cout << "\n\nThis is your pokemons : \n";
	if (player.getCurrentPet() == nullptr)cout << "There no have any pokemon."<<endl;
	else 	player.showAlivePets();*/
	//cout << "=============================================================" << endl;
	string s;
	rlutil::locate(col / 3-5, 26);
	cout << "Do you want to catch this pokemon?" << endl;
	rlutil::locate(col / 3-5, 27);
	cout << "If you want enter  「yes」or 「no」 : ";
	cin >> s;
	//expetion
	try {
		if (s!="yes" && s!="no")throw std::out_of_range("Error  chose");
	}
	catch (const std::out_of_range & oor) {
		
		cerr <<setw(col/3+14)<< "Out of Range error: " << oor.what()  <<  ". You need to enter new chose : ";
		cin >> s;
	}
	//rlutil::cls();
	if (s == "yes") {
		if (player.getPetNum() < 3) {
			rlutil::locate(col / 3 - 5, 29);
			cout << "you get " << P.getName() << " !";
			player.setPetList(pokemons[Random - 1], player.getPetNum() + 1);
			system("pause");
			rlutil::cls();
			cout << "Now your pokemons is:\n";
			player.showAlivePets();
		}
		else {
			rlutil::locate(col / 3 - 5, 29);
			cout << "You're pokemons more than 3 ,you need to choose one to change.\n\n";
			system("pause");
			rlutil::cls();
			//cout << "1. " << player.getCurrentPet()->getName();
			player.showAlivePets();
			cout << "Please to enter 1/2/3 to change pokemon : ";
			int num;
			cin >> num;
			player.setPetList(pokemons[Random - 1], num);
			cout << "\nNow your pokemons is:\n";
			player.showAlivePets();
		}
	}
	else {
		rlutil::locate(col / 3 - 5, 29);
		cout << "You give-up to catch this pokemon" << endl;
		rlutil::locate(col / 3 - 5, 30);
		cout<<"After you push enter will come back to yzumap.";
	}
	system("pause");
	DrawMap();
}

void MakeNPC() {
	for (int i = 0; i < 13; i++) {
		NPC[i].setName("NPC");
		int Random;
		for (int j = 0; j < 3; j++) {
			Random = rand() % 32;//0~31
			//p[j] = pokemons[Random];
			NPC[i].setPetList(pokemons[Random], j + 1);
		}
	}
}

void ShowWarData(Player leader,Player npc) {
	Readicon(leader.getCurrentPet()->getNO(), 1);
	Readicon(npc.getCurrentPet()->getNO(), col / 2);
	cout << "========================================================================================================================" << endl;
	//一次放兩者個目前屬性
	cout << "PokeGo : " << leader.getCurrentPet()->getName() << "(" << leader.getCurrentPet()->getHp() << "/" << leader.getCurrentPet()->getMaxHp() << ")";
	cout << setw(col / 2) << "PokeGo : " << npc.getCurrentPet()->getName() << "(" << npc.getCurrentPet()->getHp() << "/" << npc.getCurrentPet()->getMaxHp() << ")" << "\n";
	cout << "No : " << leader.getCurrentPet()->getNO();
	cout << setw(col / 2) << "No : " << npc.getCurrentPet()->getNO() << "\n";
	cout << "Type : " << leader.getCurrentPet()->getType() << "\n";
	cout << setw(col / 2) <<  "Type : " << npc.getCurrentPet()->getType() << "\n";
	cout << "Attack : " << leader.getCurrentPet()->getAttack() << "\n";
	cout << setw(col / 2) << "Attack : " << npc.getCurrentPet()->getAttack() << "\n";
	cout << "Defense : " << leader.getCurrentPet()->getDefense() << "\n";
	cout << setw(col / 2) << "Defense : " << npc.getCurrentPet()->getSpeed() << "\n";
	cout << "Ability: " << leader.getCurrentPet()->getAbility() << "\n";
	cout << setw(col / 2) << "Ability: " << npc.getCurrentPet()->getAbility() << "\n";
	cout << "========================================================================================================================" << endl;
	leader.showAlivePetsForWar(npc);
	cout << "========================================================================================================================" << endl;
}

void war(Player& leader,Player& npc) {
	int cnt = 1;
	while (true)
	{
		std::cout << "Round " << cnt << std::endl;
		ShowWarData(leader, npc);
		if (leader.getCurrentPet()->getAbility() == 1) {
			leader.getCurrentPet()->setHP(leader.getCurrentPet()->getHp() + 3);
		}
		if (npc.getCurrentPet()->getAbility() == 1) {
			npc.getCurrentPet()->setHP(npc.getCurrentPet()->getHp() + 3);
		}
		
       //玩家先攻
		if (leader.getCurrentPet()->getSpeed() >= npc.getCurrentPet()->getSpeed()) {
			cout << leader.getCurrentPet()->getName() << " First Attack " << npc.getCurrentPet()->getName() << endl;
			leader.getCurrentPet()->attack(*npc.getCurrentPet());
			cout << endl << "==========================================Pokemons===================================================================" << endl;
			leader.showAlivePetsForWar(npc);
			cout << "========================================================================================================================" << endl;
			if (npc.getCurrentPet() == nullptr) {
				win_cnt++;
				rlutil::cls();
				cout << endl << "Player :" << leader.getName() << " WIN!" << endl << endl;
				break;
			}
			cout << npc.getCurrentPet()->getName() << " Attack " << leader.getCurrentPet()->getName() << endl;
			npc.getCurrentPet()->attack(*leader.getCurrentPet());
			cout << endl << "==========================================Pokemons===================================================================" << endl;
			npc.showAlivePetsForWar(leader);
			cout << "========================================================================================================================" << endl;
			if (leader.getCurrentPet() == nullptr) {
				rlutil::cls();
				cout << endl << npc.getName() << " WIN!" << endl << endl;
				break;
			}
		}
		else {
			cout << npc.getCurrentPet()->getName() << " First Attack " << leader.getCurrentPet()->getName() << endl;
			npc.getCurrentPet()->attack(*leader.getCurrentPet());
			cout << endl << "==========================================Pokemons===================================================================" << endl;
			npc.showAlivePetsForWar(leader);
			cout << "========================================================================================================================" << endl;
			if (leader.getCurrentPet() == nullptr) {
				rlutil::cls();
				cout << endl << npc.getName() << " WIN!" << endl << endl;
				break;
			}
			cout << leader.getCurrentPet()->getName() << " Attack " << npc.getCurrentPet()->getName() << endl;
			leader.getCurrentPet()->attack(*npc.getCurrentPet());
			cout << endl << "==========================================Pokemons===================================================================" << endl;
			leader.showAlivePetsForWar(npc);
			cout << "========================================================================================================================" << endl;
			if (npc.getCurrentPet() == nullptr) {
				win_cnt++;
				rlutil::cls();
				cout << endl << "Player :" << leader.getName() << " WIN!" << endl << endl;
				break;
			}
		}
		system("pause");
		system("cls");
		if (leader.getCurrentPet() == nullptr || npc.getCurrentPet() == nullptr) {
			break;
		}
		cnt++;
	}
}


int main() {
	srand(time(NULL));
	//cout YzuMap
	Readmap();
	DrawMap();
	//建立寶可夢清單
	ReadPokemons();
	//建立13個NPC
	MakeNPC();
	//Player
	Player leader("Sunny") ;
	//隱藏游標
	rlutil::hidecursor();
	//Set "@"
	x = 20, y = 30;
	rlutil::setColor(4);
	rlutil::locate(x, y); std::cout << "@";
	rlutil::resetColor();

	//move
	while (true) {
		if (kbhit()) {//如果不想讓你的運算被等待輸入阻斷要加入這個
			char k = getch(); // Get character
			int oldx = x, oldy = y;
			int chance= rand() % 10 + 1;//1~10
			char chanceicon = { ' ' };
			rlutil::locate(x, y); std::cout << " "; // Erase player
			if (k == 'a') --x;
			else if (k == 'd') ++x;
			else if (k == 'w') --y;
			else if (k == 's') ++y;
			else if (k == ' ') break;
			char l = lvl[y-1][x-1];
			//遇牆
			if (l == '*' || l == '!' || l == 'A' || l == 'B' || l == 'C' || l == 'D' || l == '1' || l == '2' || l == '3' || l == '4' || l == '5' || l == '6' || l == '7' || l == '8' || l == '9') { x = oldx; y = oldy; }//遇到牆就不動
			//特殊地形-增加機率OR對戰
			else if (l == ';')chanceicon = ';';
			else if (l == '~')chanceicon = '~';
			//對戰
			else if (l == '#') {
				if (leader.getPetNum()<3) {
					rlutil::cls();
					rlutil::resetColor();
					cout << "You don't have enough pokemon." << endl;
					system("pause");
					x++;
					DrawMap();
					rlutil::locate(x, y);
					rlutil::setColor(4);
					std::cout << '@'; // Output player
					continue;
				}rlutil::cls();
				int R = rand() % 13;
				while (true) {
					war(leader, NPC[R]);
					if (leader.getCurrentPet() == nullptr || NPC[R].getCurrentPet() == nullptr) {
						leader.Reset();
						NPC[R].Reset();
						break;
					}
				}
				system("pause");
				system("cls");
				DrawMap();
			}
			//行走機率抓寵
			if (chance == 1) {
				CatchPet(leader, chanceicon);
			}
			rlutil::locate(x, y);
			rlutil::setColor(4);
			std::cout << '@'; // Output player
			
		}
		std::cout.flush();
		if (win_cnt == 7) {
			rlutil::cls();
			rlutil::resetColor();
			cout << "You win over seven times so....";
			rlutil::msleep(1000);
			system("pause");
			rlutil::cls();
			rlutil::resetColor();
			cout << "Game Over！\n";
			rlutil::msleep(1000);
			system("pause");
			break;
		}
	}
	


	
	
}