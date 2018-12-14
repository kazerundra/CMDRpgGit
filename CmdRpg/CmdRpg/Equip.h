#pragma once
#include<iostream>
#include<string>
using namespace std;

class Equip
{
public:
	Equip();
	// 1.�i�C�t 2�Z�� 3 "����" 4"�N���C���A" 5�`�F�C�����C��" 6"�S�Z"7�V�[���h 8 ���� 0 �_��

	string WName;
	string AName;
	float Atk;
	float Def;
	int WInventory[6] = { 0,0,0,0,0,0 };
	int AInventory[3] = { 0,0,0 };
	string Weapon[6] = { "�i�C�t","�Z��","����","�N���C���A","����","�_��" };
	int WeaponA[6] = { 3,6,10,20,30,32 };
	int WPrice[4] = { 200, 500, 1000, 2000 };
	string Armor[3] = { "�`�F�C�����C��","�S�Z","�V�[���h" };
	int ArmorD[3] = { 20,10,5};
	int APrice[3] = { 2000,800,300 };
	void setEquip(string type, int code);
	void BuyWeapon(int code);
	void BuyArmor(int code);
	void GetInventory();
};
