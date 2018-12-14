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
	cout << "HP‚ª " << up  << " ã‚ª‚è‚Ü‚µ‚½" << endl;
	up = rand() % 3+1;
	STR += up;
	if (up != 0)
		cout << "STR‚ª " << up << " ã‚ª‚è‚Ü‚µ‚½" << endl;
	up = rand() % 3+1;
	VIT += rand() % 3;
	if (up != 0)
		cout << "VIT‚ª " << up << " ã‚ª‚è‚Ü‚µ‚½" << endl;
	up = rand() % 1;
	LUCK += up;
	cout << "‰^‚ª " << up << " ã‚ª‚è‚Ü‚µ‚½" << endl;
	Lvl += 1;
	cout << "Œ»Ý‚ÌLVL" << Lvl << endl;

}
void Player::Status()
{
	cout << "–¼‘O" << Name << endl;
	cout << "LVL" << Lvl << endl;
	cout << "HP" << HP << "/" << MaxHP << endl;
	cout << "UŒ‚—Í " << STR; 
	if (equip.WName != "‚È‚¢")cout << " + " << equip.Atk << endl; else cout << endl;
	cout << "–hŒä—Í " << VIT;
	if (equip.WName != "‚È‚¢")cout << "+ " << equip.Def << endl; else cout << endl;
	cout << "‰^" << LUCK << endl;
	cout << "•Ší  " << equip.WName << endl;
	cout << "ŠZ " << equip.AName << endl;
	cout << "ƒS[ƒ‹ƒh " << Gold << endl;
	baito.getWorkLvl();
	cout << "‘•”õƒŠƒXƒg: " << endl;
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
		cout << Name << "‚ª‘åUŒ‚‚µ‚Ü‚·" << endl;
	}
	else
	{
		dmg = (STR + equip.Atk) + (rand() % minmax);
		cout << Name << "‚ªUŒ‚‚µ‚Ü‚·" << endl;
	}
	return dmg;
	
}
void Player::TakeDmg(int dmg)
{
	dmg -= (VIT + equip.Def);
	if (dmg <= 0) dmg = 0;
	HP -= dmg;
	cout << "ƒvƒŒƒCƒ„[‚ª" << dmg << "ƒ_ƒƒW[Žó‚¯‚Ü‚µ‚½" << endl;
	if (HP <= 0) { cout << Name << "‚ªŽ€‚ñ‚¾" << endl; Alive = false; };
}
void Player::Heal() 
{
	int heal = MaxHP -HP;
	HP += heal;
}
void Player::GetExp(int exp)
{
	cout << exp << "EXP ‚à‚ç‚¢‚Ü‚µ‚½"<<endl;
	EXP -= exp;
	if (EXP <= 0) 
	{
		LvlUP();
		exp = (Lvl * 15);
	}
}
void Player::GetGold(int gold) 
{
	cout << gold << "ƒS[ƒ‹ƒh‚à‚ç‚¦‚Ü‚µ‚½" << endl;
	Gold += gold;
}