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
	cout << "HP�� " << up  << " �オ��܂���" << endl;
	up = rand() % 3+1;
	STR += up;
	if (up != 0)
		cout << "STR�� " << up << " �オ��܂���" << endl;
	up = rand() % 3+1;
	VIT += rand() % 3;
	if (up != 0)
		cout << "VIT�� " << up << " �オ��܂���" << endl;
	up = rand() % 1;
	LUCK += up;
	cout << "�^�� " << up << " �オ��܂���" << endl;
	Lvl += 1;
	cout << "���݂�LVL" << Lvl << endl;

}
void Player::Status()
{
	cout << "���O" << Name << endl;
	cout << "LVL" << Lvl << endl;
	cout << "HP" << HP << "/" << MaxHP << endl;
	cout << "�U���� " << STR; 
	if (equip.WName != "�Ȃ�")cout << " + " << equip.Atk << endl; else cout << endl;
	cout << "�h��� " << VIT;
	if (equip.WName != "�Ȃ�")cout << "+ " << equip.Def << endl; else cout << endl;
	cout << "�^" << LUCK << endl;
	cout << "����  " << equip.WName << endl;
	cout << "�Z " << equip.AName << endl;
	cout << "�S�[���h " << Gold << endl;
	baito.getWorkLvl();
	cout << "�������X�g: " << endl;
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
		cout << Name << "����U�����܂�" << endl;
	}
	else
	{
		dmg = (STR + equip.Atk) + (rand() % minmax);
		cout << Name << "���U�����܂�" << endl;
	}
	return dmg;
	
}
void Player::TakeDmg(int dmg)
{
	dmg -= (VIT + equip.Def);
	if (dmg <= 0) dmg = 0;
	HP -= dmg;
	cout << "�v���C���[��" << dmg << "�_���W�[�󂯂܂���" << endl;
	if (HP <= 0) { cout << Name << "������" << endl; Alive = false; };
}
void Player::Heal() 
{
	int heal = MaxHP -HP;
	HP += heal;
}
void Player::GetExp(int exp)
{
	cout << exp << "EXP ���炢�܂���"<<endl;
	EXP -= exp;
	if (EXP <= 0) 
	{
		LvlUP();
		exp = (Lvl * 15);
	}
}
void Player::GetGold(int gold) 
{
	cout << gold << "�S�[���h���炦�܂���" << endl;
	Gold += gold;
}