#include "stdafx.h"
#include "Player.h"
#include "Equip.h"
#include <string>
using namespace std;

Player::Player() 
{
	MaxHP = 30; HP = 30;
	STR = 5;
	VIT = 5;
	LUCK = 5;
	Lvl = 1;
	Gold = 500;
	EXP = 10;
	Alive = true;
}

void Player::LvlUP()
{
	cout << "LVLUP" << endl;
	int up;
	up = rand() % 10+6;
	MaxHP +=  up;
	cout << "HPが " << up  << " 上がりました" << endl;
	up = rand() % 3+1;
	STR += up;
	if (up != 0)
		cout << "STRが " << up << " 上がりました" << endl;
	up = rand() % 3+1;
	VIT += rand() % 3;
	if (up != 0)
		cout << "VITが " << up << " 上がりました" << endl;
	up = rand() % 1;
	LUCK += up;
	cout << "運が " << up << " 上がりました" << endl;
	Lvl += 1;
	cout << "現在のLVL" << Lvl << endl;

}
void Player::Status()
{
	cout << "名前" << Name << endl;
	cout << "LVL" << Lvl << endl;
	cout << "HP" << HP << "/" << MaxHP << endl;
	cout << "攻撃力 " << STR; 
	if (equip.WName != "ない")cout << " + " << equip.Atk << endl; else cout << endl;
	cout << "防御力 " << VIT;
	if (equip.WName != "ない")cout << "+ " << equip.Def << endl; else cout << endl;
	cout << "運" << LUCK << endl;
	cout << "武器  " << equip.WName << endl;
	cout << "鎧 " << equip.AName << endl;
	cout << "ゴールド " << Gold << endl;
	baito.getWorkLvl();
	cout << "装備リスト: " << endl;
	equip.GetInventory();
}
int Player::Attack() 
{
	int dmg;
	bool critical = false; int minmax = STR/2;
	if (rand() % 100 <= LUCK) critical;
	if (critical) 
	{
		dmg = (STR + equip.Atk)*2 +(rand()% minmax);
		cout << Name << "が大攻撃します" << endl;
	}
	else
	{
		dmg = (STR + equip.Atk) + (rand() % minmax);
		cout << Name << "が攻撃します" << endl;
	}
	return dmg;
	
}
void Player::TakeDmg(int dmg)
{
	dmg -= (VIT + equip.Def);
	if (dmg <= 0) dmg = 0;
	HP -= dmg;
	cout << "プレイヤーが" << dmg << "ダメジー受けました" << endl;
	if (HP <= 0) { cout << Name << "が死んだ" << endl; Alive = false; };
}
void Player::Heal() 
{
	int heal = MaxHP -HP;
	HP += heal;
}
void Player::GetExp(int exp)
{
	cout << exp << "EXP もらいました"<<endl;
	EXP -= exp;
	if (EXP <= 0) 
	{
		LvlUP();
		exp = (Lvl * 15);
	}
}
void Player::GetGold(int gold) 
{
	cout << gold << "ゴールドもらえました" << endl;
	Gold += gold;
}