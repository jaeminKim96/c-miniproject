
#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

extern int current_count; //입력된 정보 개수 

void line()
{
    cout << "-------------------------------------------------" << endl;
}

function::function()
{
    searchName = new char[20];
}
void function::runMenu() {
    line();
    cout << "                     메뉴    " << endl;
    line();
    cout << "1. 선수검색" << endl;
    cout << "2. 선수추가" << endl;
    cout << "3. 선수불러오기" << endl;
    cout << "4. 선수단 저장하기" << endl;
    cout << "5. 선수단 출력하기" << endl;
    cout << "6. 선수 방출하기" << endl;
    line();
    cout << "종료를 원하신다면 Q 또는 q 를 누르세요" << endl;
}

void function::player_search() // menu 1 입력받은 문자열로 선수 검색
{
    cout << "검색하려는 선수의 번호를 입력하세요" << endl;
    cin >> searchName;
    if (isdigit(searchName[0]))  // 입력받은 문자열 첫 번째가 숫자이면 1, 아니면 0
    {
        char temp[10] = { 0 };
        searchNumber = atoi(searchName);
        cout << "선수 번호 검색" << endl;
        for (int i = 0; i < current_count; i++)
        {
            if (people[i].getNumber() == searchNumber)
            {
                people[i].ShowPlayerInfo();
                break;
            }
        }
    }
    else
    {
        cout << "이름 검색" << endl;
        for (int i = 0; i < current_count; i++)
        {
            if (strcmp(people[i].getName(), searchName) == 0)
            {
                people[i].ShowPlayerInfo();
                break;
            }
        }
    }
}
void function::player_add() //선수 추가 
{
    // 1. 타자인지 투수인지 입력
    // 2. 포지션에 따른 선수 정보 입력
    char c;
    char name[20];
    int number;
    hitter phitter = { 0 };
    pitcher ppitcher = { 0 };

    if (current_count == SIZEE - 1)
    {
        cout << "모두 입력되었습니다.";
    }
    else
    {
        cout << "타자로 입력하려면 y, 투수로 입력하려면 n을 입력하시오";
        cin >> c;
        if (c == 'y') // 타자 정보 입력
        {
            cout << "타자 이름: ";
            cin >> name;
            cout << "타자 번호: ";
            cin >> number;
            cout << "총 타수: ";
            cin >> phitter.ab;
            cout << "안타: ";
            cin >> phitter.h;
            cout << "2루타: ";
            cin >> phitter.h2;
            cout << "3루타: ";
            cin >> phitter.h3;
            cout << "홈런: ";
            cin >> phitter.hr;
            cout << "볼넷: ";
            cin >> phitter.bb;
            phitter.avg = (double)phitter.h / phitter.ab;
            phitter.obp = (double)(phitter.h + phitter.bb) / (phitter.ab + phitter.bb);
            phitter.slg = (double)(phitter.h + (phitter.h2 * 2) + (phitter.h3 * 3) + (phitter.hr * 4)) / phitter.ab;
            phitter.ops = phitter.obp + phitter.slg;
            people[current_count].setinfo(name, number, 1);
            people[current_count].setHitter(phitter);

        }
        else if (c == 'n') // 투수 정보 입력
        {
            cout << "투수 정보 입력 (이름 번호 승리, 패배, 평균자책점, 총 이닝, 총 자책점 ,탈삼진, 세이브)" << endl;
            cout << "투수 이름: ";
            cin >> name;
            cout << "투수 번호: ";
            cin >> number;
            cout << "승리: ";
            cin >> ppitcher.w;
            cout << "패배: ";
            cin >> ppitcher.l;
            cout << "평균 자책점: ";
            cin >> ppitcher.era;
            cout << "총 이닝: ";
            cin >> ppitcher.ip;
            cout << "총 자책점: ";
            cin >> ppitcher.er;
            cout << "탈삼진: ";
            cin >> ppitcher.so;
            cout << "세이브: ";
            cin >> ppitcher.sv;
            ppitcher.k_9 = (ppitcher.ip != 0) ? (double)ppitcher.so / ppitcher.ip * 9 : 0;
            ppitcher.winning_rate = (ppitcher.w + ppitcher.l) != 0 ? (double)(ppitcher.w) / (ppitcher.w + ppitcher.l) : 0;
            people[current_count].setinfo(name, number, 0);
            people[current_count].setPitcher(ppitcher);
        }
        else
        {
            cout << "다시 입력" << endl;
        }
    }
    current_count++;
}

void function::player_load() //선수 불러오기 미구현
{
    current_count = 0;
    ifstream in("SSG LANDERS.txt");
    hitter phitter = { 0 };
    pitcher ppitcher = { 0 };
    char name[20];
    int number;
    if (in.is_open())
    {
        char arr[256];
        char* p[20];
        for (int i = 0; i < 20; i++)
        {
            p[i] = new char[20];
        }
        while (!in.eof()) // 파일 끝까지 읽을 때까지 반복
        {
            int i = 0;
            in.getline(arr, 255); // 첫번째 line
            char* temp = strtok(arr, "/");
            if (temp[0] == '1')
            {
                while (temp != NULL)
                { //널이 아닐때까지 반복

                    temp = strtok(NULL, "/");	// "/"를 기준으로 다시 자르기
                    strcpy(p[i], temp);
                    i++;
                    if (i == 8)
                        break;
                }
                strcpy(name, p[0]);
                number = atoi(p[1]);
                phitter.avg = atof(p[2]);
                phitter.ab = atoi(p[3]);
                phitter.h = atoi(p[4]); 
                phitter.h2 = atoi(p[5]);
                phitter.h3 = atoi(p[6]);
                phitter.hr = atoi(p[7]);
                phitter.bb = atoi(p[8]);
                phitter.obp = (double)(phitter.h + phitter.bb) / (phitter.ab + phitter.bb);
                phitter.slg = (double)(phitter.h + (phitter.h2 * 2) + (phitter.h3 * 3) + (phitter.hr * 4)) / phitter.ab;
                phitter.ops = phitter.obp + phitter.slg;
                people[current_count].setinfo(name, number, 1);
                people[current_count].setHitter(phitter);
                current_count++;
            }
            else  // temp[0] == '0'
            {

                while (temp != NULL)
                { //널이 아닐때까지 반복

                    temp = strtok(NULL, "/");	//"/"를 기준으로 다시 자르기
                    strcpy(p[i], temp);
                    i++;
                    if (i == 8)
                        break;
                }
                strcpy(name, p[0]);
                number = atoi(p[1]);
                ppitcher.era = atof(p[2]);
                ppitcher.w = atoi(p[3]);
                ppitcher.l = atoi(p[4]);
                ppitcher.ip = atof(p[5]);
                ppitcher.so = atoi(p[6]);
                ppitcher.sv = atoi(p[7]);
                ppitcher.k_9 = (ppitcher.ip != 0) ? (double)ppitcher.so / ppitcher.ip * 9 : 0;
                ppitcher.winning_rate = (ppitcher.w + ppitcher.l) != 0 ? (double)(ppitcher.w) / (ppitcher.w + ppitcher.l) : 0;
                people[current_count].setinfo(name, number, 0);
                people[current_count].setPitcher(ppitcher);
                current_count++;

            }

        }
        for (int i = 0; i < 20; i++)
        {
            delete[] p[i];
        }
        cout << "선수들을 불러왔습니다." << endl;
    }

}

void function::player_save() // 선수단 저장하기
{
    ofstream out("SSG LANDERS.txt");
    char str[512];
    char temp[10];
    hitter t_hitter;
    pitcher t_pitcher;
    if (out.is_open())
    {

        for (int i = 0; i < current_count; i++)
        {
            if (people[i].getPosition() == 1)
            {
                if (i == current_count - 1 && people[i].getPosition() == 1)
                {
                    t_hitter = people[i].getHitter();
                    out << "1" << "/" << people[i].getName() << "/" << people[i].getNumber() << "/"
                        << t_hitter.avg << "/" << t_hitter.ab << "/" << t_hitter.h << "/"
                        << t_hitter.h2 << "/" << t_hitter.h3 << "/" << t_hitter.hr << "/" << t_hitter.bb;
                    break;
                }
                t_hitter = people[i].getHitter();
                out << "1" << "/" << people[i].getName() << "/" << people[i].getNumber() << "/"
                    << t_hitter.avg << "/" << t_hitter.ab << "/" << t_hitter.h << "/"
                    << t_hitter.h2 << "/" << t_hitter.h3 << "/" << t_hitter.hr << "/" << t_hitter.bb << endl;
            }
            else
            {
                if (i == current_count - 1 && people[i].getPosition() == 0)
                {
                    t_pitcher = people[i].getPitcher();
                    out << "0" << "/" << people[i].getName() << "/" << people[i].getNumber() << "/" <<
                        t_pitcher.era << "/" << t_pitcher.w << "/" << t_pitcher.l << "/" << t_pitcher.ip << "/" <<
                        t_pitcher.so << "/" << t_pitcher.sv;
                    break;
                }
                t_pitcher = people[i].getPitcher();
                out << "0" << "/" << people[i].getName() << "/" << people[i].getNumber() << "/" <<
                    t_pitcher.era << "/" << t_pitcher.w << "/" << t_pitcher.l << "/" << t_pitcher.ip << "/" <<
                    t_pitcher.so << "/" << t_pitcher.sv << endl;

            }

        }
    }
    out.close();
    cout << "저장에 성공했습니다." << endl;

}

void function::player_print() // 선수단 출력하기
{
    char c;
    cout << "선수이름출력(y) // 선수기록출력(n) : ";
    cin >> c;
    if (c == 'y') {
        for (int i = 0; i < current_count; i++) {
            people[i].showSimpleInfo();
        }
    }
    else if (c == 'n') {
        for (int i = 0; i < current_count; i++) {
            people[i].ShowPlayerInfo();
        }
    }
    else
        cout << "잘못 입력하셨습니다.";

}
void function::player_delete() // 선수 방출
{
    char name[50];
    player_print();
    cout << "방출할 선수의 이름을 입력하시오: ";
    cin >> name;

    for (int i = 0; i < current_count; i++)
    {
        if (strcmp(name, people[i].getName()) == 0)
        {
            for (int j = i; j < current_count - 1; j++)
            {
                people[j] = people[j + 1];
            }
            break;
        }
    }
    current_count--;
    cout << "방출 되었습니다" << endl;
}

function::~function()
{
    delete[] searchName;
}
