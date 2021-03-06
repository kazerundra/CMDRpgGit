
#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include "Work.h"
#include "Monster.h"
#include "Player.h"
#include "Equip.h"
using namespace std;
int Day = 1;
int lastBattle = false;
Monster monster;
Player player;

int NumberCheck(int min, int max)
{
	int choice;
chooseagain:
	cin >> choice;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << min << "から" << max << "まで入力してください" << endl;
		goto chooseagain;
	}

	if (choice < min || choice> max)
	{
		cout << min << "から" << max << "まで入力してください" << endl;
		goto chooseagain;
	}
	else
	{
		return choice;
	}
}
int TownMenu()
{
	int choice = 0;
	cout << Day << "日" << endl;
	cout << "どこに行きますか" << endl;
	cout << "1.狩り  2.武器屋 3.休み 4.バイト 5.ステータス 6. 魔王と戦う " << endl;
	choice = NumberCheck(1, 6);
	return choice;
}

string WeaponShop()
{
	int choice;
	cout << "1.買う, 2.装備変更 3. 戻る" << endl;
	choice = NumberCheck(1, 2);
	if (choice == 2)
	{
		cout << "1 武器  2 防御装備" << endl;
		choice = NumberCheck(1, 2);
		if (choice == 1) {
			return "ChangeW";
		}
		else {
			return "ChangeA";
		}

	}
	else if (choice == 1)
	{
		return "Buy";
	}
	else
	{
		return "Town";
	}
}
void battle()
{
	if (!lastBattle) 
	{	
		cout << "0 戻る　" << endl;
		cout << "どこに行きますか １．スライム森（ＬＶＬ１－10）　２．グリフォン山（LVL 10-20）　３．ドラゴンの道(LVL 20-30)" << endl;
		int choice = NumberCheck(0, 3);
		if (choice == 0);
		else if (choice != 0)
		{		monster.spawnMonster(choice);
			while (monster.getAlive()&& player.Alive)
			{
				cout << "1.戦う  2. 逃げる "<< endl;
				choice = NumberCheck(1, 2);
				if (choice == 1) 
				{
					monster.takeDamage(player.Attack());
					if (monster.getAlive()) {
						player.TakeDmg(monster.dealDamage());
					}
					else
					{
						cout << monster.getName() << "を倒しました" << endl;
						player.GetExp(monster.giveExp());
						player.GetGold( monster.GetGold());
					}
				}
				else
				{
					if (rand() % 100 < 30) 
					{
						cout << "敵から逃げました" << endl;
						break;
					}
					else
					{
						cout << "失敗しました" << endl;
						player.TakeDmg(monster.dealDamage());
					}
				}
			}
			if (player.Alive) {
				Day += 1;
			}
			else
			{
				player.Alive = true;
				cout << "5日使て復活しました" << endl;
				Day += 5;
			}
		}
	}
	else
	{
		monster.spawnMonster(4);
		while (monster.getAlive() && player.Alive)
		{
			int choice;
			cout << "1.戦う  2. 逃げる "<< endl;
			choice = NumberCheck(1, 2);
			if (choice == 1)
			{
				monster.takeDamage(player.Attack());
				if (monster.getAlive()) {
					player.TakeDmg(monster.dealDamage());
				}
				else
				{
					cout << monster.getName() << "を倒しました" << endl;
					player.GetExp(monster.giveExp());
				}
			}
			else
			{
				if (rand() % 100 < 20)
				{
					cout << "敵から逃げました" << endl;
					break;
				}
				else
				{
					cout << "失敗しました" << endl;
					player.TakeDmg(monster.dealDamage());
				}
			}
		}
		if (player.Alive) {
			Day += 1;
		}
		else
		{
			cout << "魔王が勝ちました" << endl;
		}
	}

}

int main()
{
	cout << "ようこそ30日の冒険へ、30日の間に魔王を倒しましょう" << endl;
	cout << "プレイヤーの名前を入れてください" << endl;
	cin >> player.Name;
Town:
	cout << endl;
	int choice = TownMenu();
	switch (choice)
	{
	case 1: { battle(); break; }
	case 2: {
		string nextmove = WeaponShop();

		if (nextmove == "ChangeW")
		{
			int number = 1;
			for (int i = 0; i < 6; i++)
			{
				cout << number << ". "<< player.equip.Weapon[i] << "  X " << player.equip.WInventory[i] << endl;
				number++;
			}
			cout << "どちの武器を装備しますか" << endl;
			int num = NumberCheck(1, 6);
			player.equip.setEquip("weapon", num);
		}
		else if (nextmove == "ChangeA") {
			int number = 1;
			for (int i = 0; i < 3; i++)
			{

				cout << number << ". "<< player.equip.Armor[i] << "  X " << player.equip.AInventory[i] << endl;
				number++;
			}
			cout << "どちの防御装備を装備しますか" << endl;
			int num = NumberCheck(1, 3);
			player.equip.setEquip("armor", num);

		}
		else if (nextmove == "Buy")
		{
			cout << "0. 戻る" << endl;
			cout << "1 武器  2 防御装備" << endl;
			int choice = NumberCheck(0, 3);
			if (choice == 0) break;
			else if (choice == 1) {
				for (int i= 0; i < 4; i++) 
				{
					cout << i+1<<"."<<player.equip.Weapon[i]<<player.equip.WPrice[i]<<" "<<endl;
				}
				int choice = NumberCheck(0, 4);
				if (choice == 0) break;
				else {
					if (player.equip.WPrice[choice-1] < player.Gold)
					{
						player.Gold -= player.equip.WPrice[choice-1];
						player.equip.BuyWeapon(choice);
					}
					else
					{
						cout << "ゴールド足りない" << endl;
						break;
					}
					
				}
			}
			else {
				for (int i = 0; i < 3; i++)
				{
					cout << i + 1 << "." << player.equip.Armor[i] << player.equip.APrice[i] << " " << endl;
				};
				int choice = NumberCheck(0, 3);
				if (choice == 0) break;
				else {
					if (player.equip.APrice[choice-1] <= player.Gold)
					{
						player.Gold -= player.equip.APrice[choice-1];
						player.equip.BuyArmor(choice);
					}
					else
					{
						cout << "ゴールド足りない" << endl;
						break;
					}
				}
			}
		}
		else
		{
			break;
		}
		break;
	}
	case 3: {
		cout << "一日休みました HP 回復しました " << endl;
		player.Heal();
		Day += 1;
		break;
	}

	case 4: {
		int day;
		cout << "何日バイトしますか" << endl;
		cin >> day;
		player.Gold += player.baito.goToWork(day);
		Day += day;
		break;
	}
	case 5: {player.Status(); break; }
	case 6: {lastBattle = true; battle(); }
	default:
		break;
	}


	while (Day <30 && player.Alive)
	{
		goto Town;
	}
	cout << "GameOver" << endl;
	system("pause");
	return 0;
}


