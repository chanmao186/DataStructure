#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//*******************************************************************
class PlayingCard //扑克类
{
private:
	int nValue; //扑克牌面值对应的数值
	char chSuit; //扑克的花色（黑、红、梅、方）
public:
	PlayingCard();//构造函数
	void ShowCard();//显示扑克牌
	void CardMake(int, char); //生成扑克牌
	int GetValue();//返回当前牌的面值
	char GetSuit();//返回当前牌的花色
};

class Deck//一副扑克（52张）
{
private:
	PlayingCard m_cardarray[52];//52张扑克
	int nLastDelt; //当前可用扑克牌的位置，初值为0
public:
	friend class CardPlayer;
	Deck();// 构造函数
	void MakeDeck();//生成一副扑克牌
	PlayingCard DealOne();// 从整副牌中发出（删除）一张扑克牌
	void ShowDeck();// 显示一副牌
};

class CardPlayer
{
private:
	PlayingCard card[2];//每个玩家2张牌
	int nWin;//赢的次数
	int nLose;//输的次数
	int nDraw;//平局的次数
	int nBet;//赌注
	int nMoney;//总的赌本
	//0输1胜利2平局
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
		//两个都是同花，比大小
		if ((c1.GetSuit() == c2.GetSuit()) && (c3.GetSuit() == c4.GetSuit())) {
			return CompareByValue(c1.GetValue(), c2.GetValue(), c3.GetValue(), c4.GetValue());
		}
		else if ((c1.GetSuit() == c2.GetSuit()) && (c3.GetSuit() != c4.GetSuit())) {
			return 1;
		}
		else if ((c1.GetSuit() != c2.GetSuit()) && (c3.GetSuit() == c4.GetSuit())) {
			return 0;
		}
		//两个都是对
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
		
		
	};//友元函数
	CardPlayer() {
		CardPlayer(100);
	};//构造函数
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
	};//从整副牌中获得两张牌
	void DisplayCard() {
		card[0].ShowCard();
		card[1].ShowCard();
		cout << endl;
	};//显示玩家的牌
	void Win() {
		nWin++;
		cout << "恭喜您赢了，获得" << nBet * 2 << endl;
		nMoney += (nBet * 2);
	};//赢时修改赢的次数，收回赢的钱（是赌注的两倍，含自己的赌注在内）
	void Lose() {
		cout << "您输了了" << endl;
		nLose++;
	};//输时修改输的次数
	void Draw() {
		cout << "平局" << endl;
		nMoney += nBet;
		nDraw++;
	};//平局时修改平局次数，并把赌注收回
	void SetBet(int bet) {
		nBet = bet;
		nMoney -= bet;
	};//下赌注
	int GetBet() {
		return nBet;
	};//获得总赌注
	void AddBet(int bet) {
		nBet += bet;
		nMoney -= bet;
	};//加赌注
	void Show() {
		cout << "赢:" << nWin << "\n输" << nLose << "\n平局：" << nDraw << "\n当前钱数" << nMoney << endl;
	};//显示最后结果
	int GetMoney() {
		return nMoney;
	};//返回当前钱数
};
//全局子函数声明
void CenterText(char ShellText[80]);// 居中显示字符串
char pause();// 暂停，按任意键继续

PlayingCard::PlayingCard() // 构造函数
{
	chSuit = ' ';// 初始化为空
	nValue = 0;
}
int PlayingCard::GetValue()//返回当前牌的面值
{
	return nValue;
}
char PlayingCard::GetSuit()//返回当前牌的花色
{
	return chSuit;
}
void PlayingCard::ShowCard() //显示单张扑克牌
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

void PlayingCard::CardMake(int num, char suit)//生成一张牌
{
	nValue = num;
	chSuit = suit;
}

Deck::Deck() //构造函数，生成一副空牌
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		m_cardarray[i] = PlayingCard();
	}
	nLastDelt = 0;//当前牌的有效起始位置
}

void Deck::MakeDeck()//生成一副无序的牌，相当于洗牌之后的牌
{
	int i, j, index;
	char suit[4] = { 6,3,5,4 };//ASCII码为6的是红桃,3黑桃,5梅花,4方块
	int flag[52] = { 0 }; //记录52张牌的位置中哪些位置已经有牌了，1表示已经有牌了
	nLastDelt = 0;
	for (i = 2; i <= 14; i++) //2-A共13种面值的牌，其中A的值为14，比K大
	{
		for (j = 0; j < 4; j++) //每个面值的牌又有4个花色
		{
			do
			{
				index = rand() % 52; //生成0-51之间的随机数
			} while (flag[index] == 1);//如果随机选的位置上已经有牌了，则重新选择
			m_cardarray[index].CardMake(i, suit[j]);
			flag[index] = 1;
		}
	}
}
void Deck::ShowDeck()
{
	int index = nLastDelt; //从当前可用的牌开始显示，即不显示已经发出去的牌
	int newline = 0;
	//CenterText("完整的一副牌");
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
	//if (nLastDelt < 52)// 检查是否还有牌可以发出去
	//{
	//	//cout <<"被删除的牌是：";
	//	//m_cardarray[nLastDelt].ShowCard();
	//}
	//else
	//{
	//	MakeDeck();
	//	nLastDelt = 0;
	//	//cout << "没有牌可以发了";
	//	//cout << "请按任意键继续……" << endl;
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
	char a[80] = "欢迎来到扑克牌游戏";
	CenterText(a);
	cout << endl << '\n';
	//char ans;
	Deck deck_1;//定义一副牌对象
	//询问玩家是否玩牌，若是，才有以下操作，否则程序结束
	//52张牌只够玩13次，之后应该重新洗牌
	cout << "重新洗牌……" << endl;
	deck_1.MakeDeck();//乱序生成一副牌
	//将玩家实体化
	CardPlayer player(100);
	CardPlayer computer(1000000);

	deck_1.ShowDeck(); //显示整副牌，此行为调试用，玩游戏时不能看到整副牌
	pause();//暂停，按任意键继续
	
	do {
		//玩家下盲注
		cout << "请下注:" << endl;
		cin >> bet;	
		//防止数组过大
		while (bet > player.GetMoney()) {
			cout << "您输入的数值超过了剩余钱数，请重新下注:" << endl;
			cin >> bet;
		}
		player.SetBet(bet);
		//给两个玩家各发两张牌
		player.GetCard(deck_1);
		
		computer.GetCard(deck_1);
		//显示玩家的牌，询问是否加注
		cout << "您的牌为:";
		player.DisplayCard();
		if (player.GetMoney() == 0) {
			cout << "您的钱数为0，跳过加注环节" << endl;
		}
		else {
			cout << "  是否加注(Y/S)" << endl;
			cin >> check;
			if (check == "Y" || check == "y") {
				cout << "请输入加注的数量" << endl;
				cin >> bet;
				//询问玩家是否要增加赌注，当下注资金超过现有资金，报错，重新下注
				while (bet > player.GetMoney()) {
					cout << "您输入的数值超过了剩余钱数，请重新下注:" << endl;
					cin >> bet;
				}
				player.AddBet(bet);
			}
		}	
		//显示玩家和计算机的牌
		cout << "电脑的牌为:";
		computer.DisplayCard();
		//比较玩家和计算机牌的大小
		//输出本次牌的比较结果
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
		//显示目前为止，胜、负、平局次数及玩家现有总资金数
		cout << "您当前的成绩为:" << endl;
		player.Show();	
		if (player.GetMoney() == 0) {
			cout << "您的钱数为0，游戏结束" << endl;
			break;
		}
		cout << "是否继续(Y/S)" << endl;
		cin >> check;
	} while (check=="Y"||check=="y");
	cout << "\n请按任意键退出程序……" << endl;//玩家选择不玩游戏后，结束程序
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