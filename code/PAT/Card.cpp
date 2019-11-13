#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//*******************************************************************
class PlayingCard //�˿���
{
private:
	int nValue; //�˿�����ֵ��Ӧ����ֵ
	char chSuit; //�˿˵Ļ�ɫ���ڡ��졢÷������
public:
	PlayingCard();//���캯��
	void ShowCard();//��ʾ�˿���
	void CardMake(int, char); //�����˿���
	int GetValue();//���ص�ǰ�Ƶ���ֵ
	char GetSuit();//���ص�ǰ�ƵĻ�ɫ
};

class Deck//һ���˿ˣ�52�ţ�
{
private:
	PlayingCard m_cardarray[52];//52���˿�
	int nLastDelt; //��ǰ�����˿��Ƶ�λ�ã���ֵΪ0
public:
	friend class CardPlayer;
	Deck();// ���캯��
	void MakeDeck();//����һ���˿���
	PlayingCard DealOne();// ���������з�����ɾ����һ���˿���
	void ShowDeck();// ��ʾһ����
};

class CardPlayer
{
private:
	PlayingCard card[2];//ÿ�����2����
	int nWin;//Ӯ�Ĵ���
	int nLose;//��Ĵ���
	int nDraw;//ƽ�ֵĴ���
	int nBet;//��ע
	int nMoney;//�ܵĶı�
	//0��1ʤ��2ƽ��
	static int CompareByValue(int c1, int c2, int c3, int c4) {
		int max1, min1, max2, min2;
		c1 > c2 ? max1 = c1, min1 = c2: max1 = c2, min1 = c1;
		c3 > c4 ? max2 = c3, min1 = c4 : max2 = c4, min2 = c3;
		if (max1 > max2) {
			return 1;
		}
		else if (max1 == max2) {
			if (min1 == min2) {
				return 2;
			}
			else if (min1 > min2) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
public:
	
	friend int Compare(CardPlayer& p1, CardPlayer& p2) {
		PlayingCard c1, c2, c3, c4;
		c1 = p1.card[0];
		c2 = p1.card[1];
		c3 = p2.card[0];
		c4 = p2.card[1];
		//��������ͬ�����ȴ�С
		if ((c1.GetSuit() == c2.GetSuit()) && (c3.GetSuit() == c4.GetSuit())) {
			return CompareByValue(c1.GetValue(), c2.GetValue(), c3.GetValue(), c4.GetValue());
		}
		else if ((c1.GetSuit() == c2.GetSuit()) && (c3.GetSuit() != c4.GetSuit())) {
			return 1;
		}
		else if ((c1.GetSuit() != c2.GetSuit()) && (c3.GetSuit() == c4.GetSuit())) {
			return 0;
		}
		//�������Ƕ�
		else if ((c1.GetValue() == c2.GetValue()) && (c3.GetValue() == c4.GetValue())) {
			return CompareByValue(c1.GetValue(), c2.GetValue(), c3.GetValue(), c4.GetValue());
		}
		else if ((c1.GetValue() == c2.GetValue()) && (c3.GetValue() != c4.GetValue())) {
			return 1;
		}
		else if ((c1.GetValue() != c2.GetValue()) && (c3.GetValue() == c4.GetValue())) {
			return 0;
		}
		else {
			return CompareByValue(c1.GetValue(), c2.GetValue(), c3.GetValue(), c4.GetValue());
		}
		
		
	};//��Ԫ����
	CardPlayer() {
		CardPlayer(100);
	};//���캯��
	CardPlayer(int n) {
		nBet = 0;
		nWin = 0;
		nLose = 0;
		nDraw = 0;
		nBet = 0;
		nMoney = n;
	};
	void GetCard(Deck& d) {
		card[0] = d.DealOne();
		card[1] = d.DealOne();
	};//���������л��������
	void DisplayCard() {
		card[0].ShowCard();
		card[1].ShowCard();
		cout << endl;
	};//��ʾ��ҵ���
	void Win() {
		nWin++;
		cout << "��ϲ��Ӯ�ˣ����" << nBet * 2 << endl;
		nMoney += (nBet * 2);
	};//Ӯʱ�޸�Ӯ�Ĵ������ջ�Ӯ��Ǯ���Ƕ�ע�����������Լ��Ķ�ע���ڣ�
	void Lose() {
		cout << "��������" << endl;
		nLose++;
	};//��ʱ�޸���Ĵ���
	void Draw() {
		cout << "ƽ��" << endl;
		nMoney += nBet;
		nDraw++;
	};//ƽ��ʱ�޸�ƽ�ִ��������Ѷ�ע�ջ�
	void SetBet(int bet) {
		nBet = bet;
		nMoney -= bet;
	};//�¶�ע
	int GetBet() {
		return nBet;
	};//����ܶ�ע
	void AddBet(int bet) {
		nBet += bet;
		nMoney -= bet;
	};//�Ӷ�ע
	void Show() {
		cout << "Ӯ:" << nWin << "\n��" << nLose << "\nƽ�֣�" << nDraw << "\n��ǰǮ��" << nMoney << endl;
	};//��ʾ�����
	int GetMoney() {
		return nMoney;
	};//���ص�ǰǮ��
};
//ȫ���Ӻ�������
void CenterText(char ShellText[80]);// ������ʾ�ַ���
char pause();// ��ͣ�������������

PlayingCard::PlayingCard() // ���캯��
{
	chSuit = ' ';// ��ʼ��Ϊ��
	nValue = 0;
}
int PlayingCard::GetValue()//���ص�ǰ�Ƶ���ֵ
{
	return nValue;
}
char PlayingCard::GetSuit()//���ص�ǰ�ƵĻ�ɫ
{
	return chSuit;
}
void PlayingCard::ShowCard() //��ʾ�����˿���
{
	cout << " ";
	switch (nValue)
	{
	case 14:cout << "A"; break;
	case 13:cout << "K"; break;
	case 12:cout << "Q"; break;
	case 11:cout << "J"; break;
	default:cout << nValue; break;
	}
	cout << (char)chSuit;
	cout << " ";
	cout.flush();
}

void PlayingCard::CardMake(int num, char suit)//����һ����
{
	nValue = num;
	chSuit = suit;
}

Deck::Deck() //���캯��������һ������
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		m_cardarray[i] = PlayingCard();
	}
	nLastDelt = 0;//��ǰ�Ƶ���Ч��ʼλ��
}

void Deck::MakeDeck()//����һ��������ƣ��൱��ϴ��֮�����
{
	int i, j, index;
	char suit[4] = { 6,3,5,4 };//ASCII��Ϊ6���Ǻ���,3����,5÷��,4����
	int flag[52] = { 0 }; //��¼52���Ƶ�λ������Щλ���Ѿ������ˣ�1��ʾ�Ѿ�������
	nLastDelt = 0;
	for (i = 2; i <= 14; i++) //2-A��13����ֵ���ƣ�����A��ֵΪ14����K��
	{
		for (j = 0; j < 4; j++) //ÿ����ֵ��������4����ɫ
		{
			do
			{
				index = rand() % 52; //����0-51֮��������
			} while (flag[index] == 1);//������ѡ��λ�����Ѿ������ˣ�������ѡ��
			m_cardarray[index].CardMake(i, suit[j]);
			flag[index] = 1;
		}
	}
}
void Deck::ShowDeck()
{
	int index = nLastDelt; //�ӵ�ǰ���õ��ƿ�ʼ��ʾ��������ʾ�Ѿ�����ȥ����
	int newline = 0;
	//CenterText("������һ����");
	cout << endl;
	while (index <= 51)
	{
		if (newline % 11 == 0) cout << endl;
		m_cardarray[index].ShowCard();
		newline++;
		index++;
	}
}
PlayingCard Deck::DealOne()
{
	//if (nLastDelt < 52)// ����Ƿ����ƿ��Է���ȥ
	//{
	//	//cout <<"��ɾ�������ǣ�";
	//	//m_cardarray[nLastDelt].ShowCard();
	//}
	//else
	//{
	//	MakeDeck();
	//	nLastDelt = 0;
	//	//cout << "û���ƿ��Է���";
	//	//cout << "�밴�������������" << endl;
	//	getch();
	//}
	if (nLastDelt > 51) {
		MakeDeck();
		nLastDelt = 0;
	}
	return m_cardarray[nLastDelt++];
}
int main()
{
	int bet,result;
	string check;
	srand((unsigned)time(NULL)); // Seeds GetRandInt
	char a[80] = "��ӭ�����˿�����Ϸ";
	CenterText(a);
	cout << endl << '\n';
	//char ans;
	Deck deck_1;//����һ���ƶ���
	//ѯ������Ƿ����ƣ����ǣ��������²���������������
	//52����ֻ����13�Σ�֮��Ӧ������ϴ��
	cout << "����ϴ�ơ���" << endl;
	deck_1.MakeDeck();//��������һ����
	//�����ʵ�廯
	CardPlayer player(100);
	CardPlayer computer(1000000);

	deck_1.ShowDeck(); //��ʾ�����ƣ�����Ϊ�����ã�����Ϸʱ���ܿ���������
	pause();//��ͣ�������������
	
	do {
		//�����äע
		cout << "����ע:" << endl;
		cin >> bet;	
		//��ֹ�������
		while (bet > player.GetMoney()) {
			cout << "���������ֵ������ʣ��Ǯ������������ע:" << endl;
			cin >> bet;
		}
		player.SetBet(bet);
		//��������Ҹ���������
		player.GetCard(deck_1);
		
		computer.GetCard(deck_1);
		//��ʾ��ҵ��ƣ�ѯ���Ƿ��ע
		cout << "������Ϊ:";
		player.DisplayCard();
		if (player.GetMoney() == 0) {
			cout << "����Ǯ��Ϊ0��������ע����" << endl;
		}
		else {
			cout << "  �Ƿ��ע(Y/S)" << endl;
			cin >> check;
			if (check == "Y" || check == "y") {
				cout << "�������ע������" << endl;
				cin >> bet;
				//ѯ������Ƿ�Ҫ���Ӷ�ע������ע�ʽ𳬹������ʽ𣬱���������ע
				while (bet > player.GetMoney()) {
					cout << "���������ֵ������ʣ��Ǯ������������ע:" << endl;
					cin >> bet;
				}
				player.AddBet(bet);
			}
		}	
		//��ʾ��Һͼ��������
		cout << "���Ե���Ϊ:";
		computer.DisplayCard();
		//�Ƚ���Һͼ�����ƵĴ�С
		//��������ƵıȽϽ��
		switch (Compare(player, computer)) {
		case 0 :
				player.Lose();
				break;
		case 1:
			player.Win();
			break;
		case 2:
			player.Draw();
			break;
		}
		//��ʾĿǰΪֹ��ʤ������ƽ�ִ���������������ʽ���
		cout << "����ǰ�ĳɼ�Ϊ:" << endl;
		player.Show();	
		if (player.GetMoney() == 0) {
			cout << "����Ǯ��Ϊ0����Ϸ����" << endl;
			break;
		}
		cout << "�Ƿ����(Y/S)" << endl;
		cin >> check;
	} while (check=="Y"||check=="y");
	cout << "\n�밴������˳����򡭡�" << endl;//���ѡ������Ϸ�󣬽�������
	getch();
	return 1;
}

char pause()
{
	char x;
	x = cin.get();
	cout << endl;
	return x;
}

void CenterText(char ShellText[80])
{
	int length;
	int center;
	length = strlen(ShellText);
	center = (80 - length) / 2;
	for (; center != 0; center--)
	{
		cputs(" ");
	}
	cputs(ShellText);
}