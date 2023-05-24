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
void human::ShowPlayerInfo() const // 선수 전체 데이터
{
   if(position == 1) {// 타자
   cout<<"선수 이름: "<<name << " | "<<"선수 번호: "<< number << " | " <<"타율:" << hp.avg << " | " <<"타수:" << hp.ab<< " | "
   << " 안타:" << hp.h << " | "<< "2루타:" << hp.h2 << " | "<< "3루타:" << hp.h3 << " | "<< "홈런:" << hp.hr
   << " | "<< "볼넷:" << hp.bb << " | "<< "출루율:" << hp.obp << " | "<< "장타율:" << hp.slg << " | "<< "OPS:" << hp.ops << endl;

   }
   else // 투수
   {
    cout << "선수 이름: " << name <<" | "<< "승리: "<<bp.w<<" | " <<  "패배:" <<bp.l<<  " | "<< "승률: "<< bp.winning_rate << " | "<<"평균자책점: "<<bp.era<<" | "<<"세이브"
    <<bp.sv<<" | "<< "총 이닝수: "<<bp.ip<< " | " <<"총 자책점: "<<bp.er<< " | "<< "탈삼진: "<<bp.so<< " | "<<"9이닝당 탈삼진 수: "<<bp.k_9 << endl;
   }

}  
void human:: showSimpleInfo()const //이름 포지션 등번호 확인
{
    cout << "선수 번호: "<<number <<" | "<< "선수 이름: " << name <<" | "<< "포지션: " << ((position==1) ? "타자" : "투수") << endl;
}
int human:: getPosition()const // 포지션 반환
{
    return position;
}
const char*  human::getName() const// 선수 이름 반환
{
    return name;
}

int human:: getNumber() const // 선수 번호 반환
{
    return number;
}
void human:: setHitter(struct hitter p)
{
    hp = p;
}
hitter human:: getHitter() const // 타자 정보 반환
{
    return hp;
}
void human::setPitcher(struct pitcher p) 
{
    bp = p;
}
pitcher human:: getPitcher() const // 투수 정보 반환
{
    return bp;
}

human::~human()
{
    delete[] name;
}