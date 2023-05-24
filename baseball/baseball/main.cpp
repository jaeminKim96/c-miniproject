

#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int current_count = 0;



int main()
{
	char c;
	function f;
	while (1)
	{
		
		f.runMenu();
		cin >> c;
		//system("cls");
		if (c == 'q')
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else if (c == 'Q')
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}

		switch (c)
		{
		case '1':
			f.player_search();
			break;
		case '2':
			f.player_add();
			break;
		case '3':
			f.player_load();
			break;
		case '4':
			f.player_save();
			break;
		case '5':
			f.player_print();
			break;
		case '6':
			f.player_delete();
			break;
		default:
			cout << "잘못 입력했습니다 다시 입력하세요." << endl;
			break;
		}

	} 
}