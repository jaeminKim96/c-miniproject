

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
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		else if (c == 'Q')
		{
			cout << "���α׷��� �����մϴ�." << endl;
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
			cout << "�߸� �Է��߽��ϴ� �ٽ� �Է��ϼ���." << endl;
			break;
		}

	} 
}