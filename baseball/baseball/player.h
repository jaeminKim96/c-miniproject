struct hitter
{
	double avg; // 타율
	int ab; // 타수
	int h; // 안타
	int h2; // 2루타
	int h3; // 3루타
	int hr; // 홈런
	int bb; // 볼넷
	double obp; // 출루율
	double slg; // 장타율
	double ops; // 출루율 + 장타율

};

struct pitcher
{
	int w; //승
	int l; //패
	double era; //평균자책점
	int sv; //세이브
	double ip; //총 이닝 수
	int er; //총 자책점
	int so; // 탈삼진
	double k_9; //9이닝 당 탈삼진 수
	double winning_rate; // 승률
};

class human
{
protected:
	char* name;   // 선수 이름 포인터
	int number;   // 선수 번호
	int position;  // 1 - 타자 ,  0 - 투수
	hitter hp = {0};      // 타자 구조체
	pitcher bp = { 0 };     // 투수 구조체
public:
	human();
	void setinfo(const char*, int, int);  //  name, number, position
	const char* getName()const; // 이름 반환
	int getNumber()const; // 선수 번호 반환
	int getPosition()const; // 포지션 반환
	void showSimpleInfo()const; //이름 포지션 등번호 확인
	void ShowPlayerInfo() const; // 선수 정보 
	void setHitter(struct hitter);
	hitter getHitter() const; // 타자 정보 반환
	void setPitcher(struct pitcher);
	pitcher getPitcher() const; // 투수 정보 반환
	~human();   // delete[] name 사용
	
};