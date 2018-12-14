#include "stdafx.h"
#include "Monster.h"
#include <iostream>

Monster::Monster()
{
	Hp = 1;
	Atk = 1;
	Def = 1;
	Exp = 1;
	Luck = 1;
	Gold = 1;
	alive = true;
}
string Monster::getName() 
{
	return Name;
}
int Monster::dealDamage()
{
	int damage = 0;
	int critical;
	critical = rand() % 100 + 1;
	if (critical > Luck)
	{
		int minmax = Atk/2;
		damage = Atk + rand() %minmax;
		cout << Name << "が攻撃しました," ;
	}
	else
	{
		int minmax = Atk / 2;
		damage = Atk*2 + rand() % minmax;
		cout << Name << "がクリティカル攻撃しました";
	}
	return damage;
}
void Monster::takeDamage(int dmg)
{
	dmg -= Def;
	if (dmg <= 0) dmg =0;
	Hp -= dmg;
	cout << Name << "が" << dmg << "ダメジーを受けました"<<endl;
	if (Hp <= 0) {
		alive = false;
		cout << Name << "倒しました";
	}
}
int Monster::GetGold() {
	return Gold;
	
}
void Monster::setEnemyStatus()
{
	/*{ "スライム", "赤スライム", "金スライム" },
	{ "コボルド", "ゴーレム" ,"グリフォン" },
	{ "ワイバーン", "ドラゴン" ,"ドラゴンキング" },*/
	if (Name == "スライム") {
		Atk = 10; Def = 2; Hp = 10; Exp = 5; Luck = 5; Gold = 10;
	}
	else if (Name == "赤スライム") {
		Atk = 12; Def = 2; Hp = 15; Exp = 8; Luck = 5; Gold = 15;
	}
	else if (Name == "金スライム") {
		Atk = 20; Def = 10; Hp = 30; Exp = 20; Luck = 10; Gold = 500;
	}
	else if (Name == "コボルド") {
		Atk = 28; Def = 9; Hp = 20; Exp = 15; Luck = 15; Gold = 50;
	}
	else if (Name == "ゴーレム") {
		Atk = 25; Def = 20; Hp = 40; Exp = 30; Luck = 10; Gold = 80;
	}
	else if (Name == "グリフォン") {
		Atk = 55; Def = 10; Hp = 50; Exp = 60; Luck = 25; Gold = 200;
	}
	else if (Name == "ワイバーン") {
		Atk = 50; Def = 20; Hp = 100; Exp = 150; Luck = 40; Gold = 100;
	}
	else if (Name == "ドラゴン") {
		Atk = 70; Def = 25; Hp = 250; Exp = 300; Luck = 30; Gold = 150;
	}
	else if (Name == "ドラゴンキング") {
		Atk = 120; Def = 40; Hp = 1000; Exp = 1500; Luck = 25; Gold = 500;
	}
	else if (Name == "魔王") {
		Atk = 90; Def = 50; Hp = 700; Exp = 0; Luck = 70;
	}
	else {
		Atk = 210; Def = 210; Hp = 2100; Exp = 50; Luck = 90;
	}
}

void Monster::spawnMonster(int area)
{
	alive = true;
	int enemyNumber;
	int randNumber = rand() % 100;
	if (randNumber<50) {
		enemyNumber = 0;
	}
	else if (randNumber >= 50 && randNumber < 85) {
		enemyNumber = 1;
	}
	else
	{
		enemyNumber = 2;
	}
	Name = NameList[area-1][enemyNumber];
	setEnemyStatus();
	cout << Name<<"が現れました" << endl;

}
bool Monster::getAlive() 
{
	return alive;
}
int Monster::giveExp() {
	return Exp;
}
