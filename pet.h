#pragma once
#ifndef PET_H

#define PET_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include<fstream>
#include<sstream>
#include "rlutil.h"
using namespace std;




class Pet {
	private:
		int No=0;
		string Name = { "" };
		string Type = { "" };
		int Hp=0;
		int MaxHp=0;
		int Attack=0;
		int MaxAttack = 0;
		int Defense=0;
		int Speed=0;
		int MaxSpeed = 0;
		int Ability=0;
		int back_attack = 0;
		int Mark = 4;//紀錄特殊情況
		//4:沒有被使用過特殊能力
		//3:被使用的第一回合(能力下回合才開始)
		//2:被使用第二回合(開始動能力)
		//1:被使用的第三回合(第二次被動能力)
		//0:不用被控制了
	public:
		Pet() {}
		Pet(int no, string name, string type, int hp, int mxhp, int atk, int def, int speed, int ability) :No(no), Name(name), Type(type), Hp(hp), MaxHp(mxhp), Attack(atk), Defense(def), Speed(speed), Ability(ability) { 
			back_attack = MaxHp; 
			MaxSpeed = Speed;
			MaxAttack = Attack;
		}
		void setHP(int hp) { Hp = hp; }
		void setMark(int m) { Mark = m; }
		void setSpeed(int s) { Speed = s; }
		void setAttack(int a) { Attack = a; }
		int getMark() { return Mark; }
		int getNO() { return No; }
		string getName() { return Name; }
		string getType() { return Type; }
		int getHp() { return Hp; }
		int getMaxHp() { return MaxHp; }
		int getMaxSpeed() { return MaxSpeed; }
		int getMaxAttack() { return MaxAttack; }
		int getAttack() { return Attack; }
		int getDefense() { return Defense; }
		int getSpeed() { return Speed; }
		int getAbility() { return Ability; }
		void getCounterAttack(Pet& m) { 
			int num = (back_attack - getHp()) /5;
			back_attack = getHp();
			int de = m.getDefense();
			m.setHP(m.getHp() - num);
		}
		void showStats() {
			cout <<setw(10)<< "PokeGo : " << getName() << "(" << getHp() << "/" << getMaxHp() << ")" << endl;
			cout << setw(10) << "No : " << getNO() << endl;
			cout << setw(10) << "Type : " << getType() << endl;
			cout << setw(10) << "Attack : " << getAttack() << endl;
			cout << setw(10) << "Defense : " << getDefense() << endl;
			cout << setw(10) << "Speed : " << getSpeed() << endl;
			cout << setw(10) <<"Ability : " << getAbility() << endl;
		}
		void attack(Pet& p) {
			int atk = 0;
			int r3 = rand() % 3 + 1;//1-3
			int r2 = rand() % 2 + 2;//2-3
			int r5 = rand() % 5 + 1;//1-5//==1時有效
			int atktime = 1;
			int noatk = 0;
			int atkless2 = 0;
			if (this->getAbility() == 2 || this->getAbility() == 4 || this->getAbility() == 5 || this->getAbility() == 7 || this->getAbility() == 8 || this->getAbility() == 9 || this->getAbility() == 11 || this->getAbility() == 12) {
				if (getAbility() == 2) atk = r3;
				else if (getAbility() == 4 && p.getAbility() == 10)atk = 2;
				else if (getAbility() == 5)setHP(getHp() + r2);
				else if (getAbility() == 7 && r5 == 1)atktime++;
				else if (getAbility() == 8 && p.getAbility() != 4 && p.getMark() == 4)p.setMark(3);
				else if (getAbility() == 9 && p.getAbility() != 4 && p.getMark() == 4)p.setMark(3);
				else if (getAbility() == 11 && p.getAbility() != 4 && p.getMark() == 4)p.setMark(3);
				else if (getAbility() == 12 && p.getAbility() != 4 && p.getMark() == 4)p.setMark(3);
			}
			if (/*p.getAbility() == 3 || */p.getAbility() == 6 || p.getAbility() == 10) {
			/*if (p.getAbility() == 3 && r5 == 1)p.getCounterAttack(*this);
				else */
				if (p.getAbility() == 6 && r5 == 1)noatk = 1;
				else if (p.getAbility() == 10 && getAbility() != 4)atk -= 2;
			}
			while (atktime > 0) {
				if (noatk == 0) {
					 if (getAbility() == 8&&p.getMark()<4) {
						 if (p.getMark() == 3) {
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense() ));
							 p.setMark(p.getMark() - 1);
						 }
						 else if (p.getMark() == 2 || p.getMark() == 1) {
							p.setHP(p.getHp() - (getAttack() + atk  - p.getDefense() - 2));
							p.setMark(p.getMark() - 1);
						}
						 else {
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
						 }
					}
					else if (getAbility() == 9 && p.getMark() < 4) {
						 if (p.getMark() == 3) {
							 p.setMark(p.getMark() - 1);
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
						 }
						 else if (p.getMark() == 2 || p.getMark() == 1) {
							p.setHP(p.getHp() - (getAttack() + atk  - p.getDefense()));
							p.setSpeed(p.getSpeed() - 2);
							p.setMark(p.getMark() - 1);
						}
						 else if (p.getMark() == 0) { 
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
							 p.setSpeed(p.getMaxSpeed()); 
						 }
					}
					else if (getAbility() == 11 && p.getMark() < 4) {
						 if (p.getMark() == 3) {
							 p.setMark(p.getMark() - 1);
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense() ));
						 }
						 else if (p.getMark() == 2 || p.getMark() == 1) {
							p.setHP(p.getHp() - (getAttack() + atk  - p.getDefense()+2));
							p.setMark(p.getMark() - 1);
						}
						 else  p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
					}
					else if (getAbility() == 12 && p.getMark() < 4) {
						 if (p.getMark() == 3) {
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
							 p.setMark(p.getMark() - 1);
						 }
						 else if (p.getMark() == 2 || p.getMark() == 1) {
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
							 p.setAttack(p.getAttack() - 2);
							 p.setMark(p.getMark() - 1);
						 }
						 else if (p.getMark() == 0) {
							 p.setAttack(p.getMaxAttack());
							 p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
							 
						 }
					 }
					else p.setHP(p.getHp() - (getAttack() + atk - p.getDefense()));
				}
				if (noatk == 1)noatk = 0;
				if (p.getAbility() == 3 && r5 == 1)p.getCounterAttack(*this);
				atktime--;
			}
		}
		void PetReset() {
			Hp = MaxHp;
		}
};
class Player
{
public:
	Player() {
		for (int i = 0; i < 3; i++) {
			PetList[i] = nullptr;
		}
	}
	Player(string name) :Name(name) {
		for (int i = 0; i < 3; i++){
			PetList[i] = nullptr;
		}
	}
	/*~Player() {
		delete[]PetList;
	}*/
	string getName() {
		return Name;
	}
	void setName(string n) {
		Name = n;
	}
	void setPetList(Pet &pet, int num) {
		PetList[num - 1] = &pet;
	}
	Pet* getCurrentPet() {
		for (int i = 0; i < 3; i++) {
			if (PetList[i]->getHp() > 0)
				return PetList[i];
		}
		return nullptr;
	}
	void  showAlivePets() {
		for (int i = 0; i < 3; i++) {
			if (PetList[i] == nullptr)continue;
			else if (PetList[i]->getHp() > 0) {
				cout << endl;
				PetList[i]->showStats();
				cout << endl;
			}
		}
	}
	void  showAlivePetsForWar(Player& npc) {
		int cnt = 1;
		int col = rlutil::tcols();//row:30(高),col:120(寬)
		cout << getName()<<" Pokemons : " << setw(col / 2)<<npc.getName() << " Pokemons : \n";
		for (int i = 0; i < 3; i++) {
				cout <<i+1<<". "<<PetList[i]->getName() << "(" << PetList[i]->getHp() << "/" << PetList[i]->getMaxHp() << ")";
				cout << setw(col / 2) <<  i+1<< ". " << npc.PetList[i]->getName() << "(" << npc.PetList[i]->getHp() << "/" << npc.PetList[i]->getMaxHp() << ")" <<"\n";
		}
	}
	int getPetNum() {
		int number=0;
		for (int i = 0; i < 3; i++) {
			if (PetList[i] == nullptr)continue;
			else number++;
		}
		return number;
	}
	void Reset(){
		for (int i = 0; i < 3; i++) {
			PetList[i]->PetReset();
		}
	}
	
private:
	string Name = { " " };
	Pet* PetList[3] = {};
};


#endif // !PET_H
