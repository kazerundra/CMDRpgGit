#include "stdafx.h"
#include "Equip.h"
#include <string>
using namespace std;

Equip::Equip()
{
	// 1.�i�C�t 2�Z�� 3 "����" 4"�N���C���A" 5�`�F�C�����C��" 6"�S�Z"7�V�[���h 8 ���� 0 �_��
	WName = "�Ȃ�";
	AName = "�Ȃ�";
	Atk = 0;
	Def = 0;

}
	void Equip::setEquip(string type, int code)
	{

		code -= 1;
		if (type == "armor")
		{
			AName = Armor[code];
			Def = ArmorD[code];
			cout << AName << "�������܂���" << endl;
		}
		else
		{
			WName = Weapon[code];
			Atk = WeaponA[code];
			cout << WName << "�������܂���" << endl;
		}
	}
	void Equip::BuyWeapon(int code)
	{
		WInventory[code - 1] ++; cout << Weapon[code - 1] << " �����܂���" << endl;

	}
	void Equip::BuyArmor(int code)
	{
		AInventory[code - 1] ++; cout << Armor[code - 1] << "�@�����܂���" << endl;
	}
	

	void Equip::GetInventory()
	{

		int number = 1;
		for (int i = 0; i < 6; i++)
		{
			if (WInventory[i] > 0)
			{
				cout << number << Weapon[i] << endl;
				number++;

			}
		}
		for (int i = 0; i <3; i++)
		{
			if (AInventory[i] > 0)
			{
				cout << number << Armor[i] << endl;
				number++;
			}
		}
	}