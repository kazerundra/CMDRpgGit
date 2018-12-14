#pragma once
#include<iostream>
#include<string>
using namespace std;

class Equip
{
public:
	Equip();
	// 1.ナイフ 2短剣 3 "長剣" 4"クレイモア" 5チェインメイル" 6"鉄鎧"7シールド 8 魔剣 0 神剣

	string WName;
	string AName;
	float Atk;
	float Def;
	int WInventory[6] = { 0,0,0,0,0,0 };
	int AInventory[3] = { 0,0,0 };
	string Weapon[6] = { "ナイフ","短剣","長剣","クレイモア","魔剣","神剣" };
	int WeaponA[6] = { 3,6,10,20,30,32 };
	int WPrice[4] = { 200, 500, 1000, 2000 };
	string Armor[3] = { "チェインメイル","鉄鎧","シールド" };
	int ArmorD[3] = { 20,10,5};
	int APrice[3] = { 2000,800,300 };
	void setEquip(string type, int code);
	void BuyWeapon(int code);
	void BuyArmor(int code);
	void GetInventory();
};
