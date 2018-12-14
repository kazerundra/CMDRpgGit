#include "stdafx.h"
#include "Equip.h"
#include <string>
#include "Work.h"
using namespace std;

struct  Player
	{
	public:
		Player();
		int Lvl;
		string Name;
		Equip equip;
		Work baito;
		bool Alive;
		float MaxHP, HP, STR, VIT, LUCK, EXP;
		void LvlUP();
		void Status();
		int Gold;
		void TakeDmg(int dmg);
		int Attack();
		void Heal();
		void GetExp(int exp);
		void GetGold(int gold);
	};
