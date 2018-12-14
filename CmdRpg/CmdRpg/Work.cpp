#include "stdafx.h"
#include "Work.h"
#include <iostream>
using namespace std;

Work::Work()
{
	workExp = 0;
	workLvl = 1;
}
int Work::goToWork(int day) 

{
	int gold = 0;
	for (int i = 0; i < day; i++) 
	{
		workExp += 100;
		while (workExp >= 300)
		{
			workLvl += 1;
			workExp -= 300;
			cout << "バイトLVLアップ" << endl;
		}
		gold += (workLvl * 50);
		if (workLvl > 3) gold += 100;
		if (workLvl > 5) gold += 300;
	}
	cout << "ゴールド　" << gold << "手に入れました" << endl;
	return gold;
}
void Work::getWorkLvl()
{
	cout << "現在のバイトLVL " << workLvl << " ";
	if (workLvl < 3) cout << "店員　";
	else if(workLvl  <5)
	{
		cout << "店長";
	}
	else
	{
		cout << "CEO";
	}
	cout << endl;
}


