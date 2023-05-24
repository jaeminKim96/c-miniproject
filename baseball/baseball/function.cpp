
#define _CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

extern int current_count; //�Էµ� ���� ���� 

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
    cout << "                     �޴�    " << endl;
    line();
    cout << "1. �����˻�" << endl;
    cout << "2. �����߰�" << endl;
    cout << "3. �����ҷ�����" << endl;
    cout << "4. ������ �����ϱ�" << endl;
    cout << "5. ������ ����ϱ�" << endl;
    cout << "6. ���� �����ϱ�" << endl;
    line();
    cout << "���Ḧ ���ϽŴٸ� Q �Ǵ� q �� ��������" << endl;
}

void function::player_search() // menu 1 �Է¹��� ���ڿ��� ���� �˻�
{
    cout << "�˻��Ϸ��� ������ ��ȣ�� �Է��ϼ���" << endl;
    cin >> searchName;
    if (isdigit(searchName[0]))  // �Է¹��� ���ڿ� ù ��°�� �����̸� 1, �ƴϸ� 0
    {
        char temp[10] = { 0 };
        searchNumber = atoi(searchName);
        cout << "���� ��ȣ �˻�" << endl;
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
        cout << "�̸� �˻�" << endl;
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
void function::player_add() //���� �߰� 
{
    // 1. Ÿ������ �������� �Է�
    // 2. �����ǿ� ���� ���� ���� �Է�
    char c;
    char name[20];
    int number;
    hitter phitter = { 0 };
    pitcher ppitcher = { 0 };

    if (current_count == SIZEE - 1)
    {
        cout << "��� �ԷµǾ����ϴ�.";
    }
    else
    {
        cout << "Ÿ�ڷ� �Է��Ϸ��� y, ������ �Է��Ϸ��� n�� �Է��Ͻÿ�";
        cin >> c;
        if (c == 'y') // Ÿ�� ���� �Է�
        {
            cout << "Ÿ�� �̸�: ";
            cin >> name;
            cout << "Ÿ�� ��ȣ: ";
            cin >> number;
            cout << "�� Ÿ��: ";
            cin >> phitter.ab;
            cout << "��Ÿ: ";
            cin >> phitter.h;
            cout << "2��Ÿ: ";
            cin >> phitter.h2;
            cout << "3��Ÿ: ";
            cin >> phitter.h3;
            cout << "Ȩ��: ";
            cin >> phitter.hr;
            cout << "����: ";
            cin >> phitter.bb;
            phitter.avg = (double)phitter.h / phitter.ab;
            phitter.obp = (double)(phitter.h + phitter.bb) / (phitter.ab + phitter.bb);
            phitter.slg = (double)(phitter.h + (phitter.h2 * 2) + (phitter.h3 * 3) + (phitter.hr * 4)) / phitter.ab;
            phitter.ops = phitter.obp + phitter.slg;
            people[current_count].setinfo(name, number, 1);
            people[current_count].setHitter(phitter);

        }
        else if (c == 'n') // ���� ���� �Է�
        {
            cout << "���� ���� �Է� (�̸� ��ȣ �¸�, �й�, �����å��, �� �̴�, �� ��å�� ,Ż����, ���̺�)" << endl;
            cout << "���� �̸�: ";
            cin >> name;
            cout << "���� ��ȣ: ";
            cin >> number;
            cout << "�¸�: ";
            cin >> ppitcher.w;
            cout << "�й�: ";
            cin >> ppitcher.l;
            cout << "��� ��å��: ";
            cin >> ppitcher.era;
            cout << "�� �̴�: ";
            cin >> ppitcher.ip;
            cout << "�� ��å��: ";
            cin >> ppitcher.er;
            cout << "Ż����: ";
            cin >> ppitcher.so;
            cout << "���̺�: ";
            cin >> ppitcher.sv;
            ppitcher.k_9 = (ppitcher.ip != 0) ? (double)ppitcher.so / ppitcher.ip * 9 : 0;
            ppitcher.winning_rate = (ppitcher.w + ppitcher.l) != 0 ? (double)(ppitcher.w) / (ppitcher.w + ppitcher.l) : 0;
            people[current_count].setinfo(name, number, 0);
            people[current_count].setPitcher(ppitcher);
        }
        else
        {
            cout << "�ٽ� �Է�" << endl;
        }
    }
    current_count++;
}

void function::player_load() //���� �ҷ����� �̱���
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
        while (!in.eof()) // ���� ������ ���� ������ �ݺ�
        {
            int i = 0;
            in.getline(arr, 255); // ù��° line
            char* temp = strtok(arr, "/");
            if (temp[0] == '1')
            {
                while (temp != NULL)
                { //���� �ƴҶ����� �ݺ�

                    temp = strtok(NULL, "/");	// "/"�� �������� �ٽ� �ڸ���
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
                { //���� �ƴҶ����� �ݺ�

                    temp = strtok(NULL, "/");	//"/"�� �������� �ٽ� �ڸ���
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
        cout << "�������� �ҷ��Խ��ϴ�." << endl;
    }

}

void function::player_save() // ������ �����ϱ�
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
    cout << "���忡 �����߽��ϴ�." << endl;

}

void function::player_print() // ������ ����ϱ�
{
    char c;
    cout << "�����̸����(y) // ����������(n) : ";
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
        cout << "�߸� �Է��ϼ̽��ϴ�.";

}
void function::player_delete() // ���� ����
{
    char name[50];
    player_print();
    cout << "������ ������ �̸��� �Է��Ͻÿ�: ";
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
    cout << "���� �Ǿ����ϴ�" << endl;
}

function::~function()
{
    delete[] searchName;
}
