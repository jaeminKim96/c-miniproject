#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "player.h"
#define SIZEE 30

class function
{
private:
	human people[SIZEE];
	char* searchName;
	int searchNumber;
public:
	function(); // searchName �޸��߰�
	
	void runMenu();		  // �޴� ���
	
	void player_search(); // �����˻����
	
	void player_add();	  // �����߰����
	
	void player_load();	  // �����ҷ����� txt ���� �б�
	
	void player_save();   //  ������ �����ϱ� txt
	
	void player_print();  //  ������ ����ϱ�

	void player_delete(); //  �����߹��� �߰� ����

	~function(); // searchName �޸� ����
};