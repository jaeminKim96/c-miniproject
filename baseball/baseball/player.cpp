#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

human::human()
{
    name = new char[20];
    number = 0;
    position = 0;
}
void human::setinfo(const char*str, int num, int posit)
{
    strcpy(name, str);
    number = num;
    position = posit;
}
void human::ShowPlayerInfo() const // ���� ��ü ������
{
   if(position == 1) {// Ÿ��
   cout<<"���� �̸�: "<<name << " | "<<"���� ��ȣ: "<< number << " | " <<"Ÿ��:" << hp.avg << " | " <<"Ÿ��:" << hp.ab<< " | "
   << " ��Ÿ:" << hp.h << " | "<< "2��Ÿ:" << hp.h2 << " | "<< "3��Ÿ:" << hp.h3 << " | "<< "Ȩ��:" << hp.hr
   << " | "<< "����:" << hp.bb << " | "<< "�����:" << hp.obp << " | "<< "��Ÿ��:" << hp.slg << " | "<< "OPS:" << hp.ops << endl;

   }
   else // ����
   {
    cout << "���� �̸�: " << name <<" | "<< "�¸�: "<<bp.w<<" | " <<  "�й�:" <<bp.l<<  " | "<< "�·�: "<< bp.winning_rate << " | "<<"�����å��: "<<bp.era<<" | "<<"���̺�"
    <<bp.sv<<" | "<< "�� �̴׼�: "<<bp.ip<< " | " <<"�� ��å��: "<<bp.er<< " | "<< "Ż����: "<<bp.so<< " | "<<"9�̴״� Ż���� ��: "<<bp.k_9 << endl;
   }

}  
void human:: showSimpleInfo()const //�̸� ������ ���ȣ Ȯ��
{
    cout << "���� ��ȣ: "<<number <<" | "<< "���� �̸�: " << name <<" | "<< "������: " << ((position==1) ? "Ÿ��" : "����") << endl;
}
int human:: getPosition()const // ������ ��ȯ
{
    return position;
}
const char*  human::getName() const// ���� �̸� ��ȯ
{
    return name;
}

int human:: getNumber() const // ���� ��ȣ ��ȯ
{
    return number;
}
void human:: setHitter(struct hitter p)
{
    hp = p;
}
hitter human:: getHitter() const // Ÿ�� ���� ��ȯ
{
    return hp;
}
void human::setPitcher(struct pitcher p) 
{
    bp = p;
}
pitcher human:: getPitcher() const // ���� ���� ��ȯ
{
    return bp;
}

human::~human()
{
    delete[] name;
}