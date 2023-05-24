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
	function(); // searchName 메모리추가
	
	void runMenu();		  // 메뉴 출력
	
	void player_search(); // 선수검색기능
	
	void player_add();	  // 선수추가기능
	
	void player_load();	  // 선수불러오기 txt 파일 읽기
	
	void player_save();   //  선수단 저장하기 txt
	
	void player_print();  //  선수단 출력하기

	void player_delete(); //  선수추방기능 추가 가능

	~function(); // searchName 메모리 삭제
};