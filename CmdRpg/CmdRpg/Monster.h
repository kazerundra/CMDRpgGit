#pragma once
#include<string>
using namespace std;

class Monster
{
	int Hp;
	int Atk;
	int Def;
	int Exp;
	int Luck;
	int Gold;
	bool alive;
	string Name;
	int area;
	string NameList[4][3] = {
		{ "�X���C��", "�ԃX���C��" ,"���X���C��" },
	{ "�R�{���h", "�S�[����" ,"�O���t�H��" },
	{ "���C�o�[��", "�h���S��" ,"�h���S���L���O" },
	{"����","����" ,"����" }
	};
public:

	int GetGold();
	string getName();
	bool getAlive();
	Monster();
	int dealDamage();
	void takeDamage(int dmg);
	int giveExp();
	void spawnMonster(int area);
	void setEnemyStatus();

};
