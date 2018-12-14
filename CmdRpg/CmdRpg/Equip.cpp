#include "stdafx.h"
#include "Equip.h"
#include <string>
using namespace std;

Equip::Equip()
{
	// 1.ナイフ 2短剣 3 "長剣" 4"クレイモア" 5チェインメイル" 6"鉄鎧"7シールド 8 魔剣 0 神剣
	WName = "ない";
	AName = "ない";
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
			cout << AName << "装備しました" << endl;
		}
		else
		{
			WName = Weapon[code];
			Atk = WeaponA[code];
			cout << WName << "装備しました" << endl;
		}
	}
	void Equip::BuyWeapon(int code)
	{
		WInventory[code - 1] ++; cout << Weapon[code - 1] << " 買いました" << endl;

	}
	void Equip::BuyArmor(int code)
	{
		AInventory[code - 1] ++; cout << Armor[code - 1] << "　買いました" << endl;
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