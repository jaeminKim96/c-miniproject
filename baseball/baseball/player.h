struct hitter
{
	double avg; // Ÿ��
	int ab; // Ÿ��
	int h; // ��Ÿ
	int h2; // 2��Ÿ
	int h3; // 3��Ÿ
	int hr; // Ȩ��
	int bb; // ����
	double obp; // �����
	double slg; // ��Ÿ��
	double ops; // ����� + ��Ÿ��

};

struct pitcher
{
	int w; //��
	int l; //��
	double era; //�����å��
	int sv; //���̺�
	double ip; //�� �̴� ��
	int er; //�� ��å��
	int so; // Ż����
	double k_9; //9�̴� �� Ż���� ��
	double winning_rate; // �·�
};

class human
{
protected:
	char* name;   // ���� �̸� ������
	int number;   // ���� ��ȣ
	int position;  // 1 - Ÿ�� ,  0 - ����
	hitter hp = {0};      // Ÿ�� ����ü
	pitcher bp = { 0 };     // ���� ����ü
public:
	human();
	void setinfo(const char*, int, int);  //  name, number, position
	const char* getName()const; // �̸� ��ȯ
	int getNumber()const; // ���� ��ȣ ��ȯ
	int getPosition()const; // ������ ��ȯ
	void showSimpleInfo()const; //�̸� ������ ���ȣ Ȯ��
	void ShowPlayerInfo() const; // ���� ���� 
	void setHitter(struct hitter);
	hitter getHitter() const; // Ÿ�� ���� ��ȯ
	void setPitcher(struct pitcher);
	pitcher getPitcher() const; // ���� ���� ��ȯ
	~human();   // delete[] name ���
	
};