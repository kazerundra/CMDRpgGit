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
		{ "スライム", "赤スライム" ,"金スライム" },
	{ "コボルド", "ゴーレム" ,"グリフォン" },
	{ "ワイバーン", "ドラゴン" ,"ドラゴンキング" },
	{"魔王","魔王" ,"魔王" }
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
