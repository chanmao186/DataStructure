#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

//字符变量，存放最新读进的原程序字符串
char ch;
//字符数组，存放构成单词符号的字符串
string CurentToken;
//当前的代码
string code;

int Index = 0;
//关键字
vector<string> key = { "do","for","if","int","main","return","while","void" };
//输入的代码的长度
int length;

string ToBinary();
struct Token
{
	string token = "";
	int typeCode;
	string value = "-";
	Token(int typeCode) {
		this->typeCode = typeCode;
		this->token = CurentToken;
	}
	Token(int typeCode, string _token) {
		this->typeCode = typeCode;
		this->token = _token;
		this->value = CurentToken;
		if (_token == "整常数") {
			this->value = ToBinary();
		}

	}

};
vector<Token> tokens;

string ToBinary() {
	string temp = "";
	//将内码值转化为二进制形式
	int num = atoi(CurentToken.c_str());
	for (; (num / 2) > 0; num /= 2) {
		temp += (num % 2 + '0');
	}
	if (num != 0) {
		temp += '1';
	}
	if (temp.length() == 0) {
		temp = "0";
	}
	//将所的数反转
	reverse(temp.begin(), temp.end());
	return temp;
}



void concat() {//将ch中的字符与token中的字符串连接
	CurentToken += ch;
}

void getch() {
	if (Index <= length) {
		ch = code[Index++];
	}
	else {
		//ch=非法字符
		ch = '@';
	}
}
void getbc() {
	getch();
	while (ch == ' ') {
		getch();
	}
}
//整数函数，对 token 中的字符串查找关键字表，若它是一个关键字则返回它的编码，否则返回标识符的种别码 10。
int reserve() {
	for (int i = 0; i < 8; i++) {
		if (CurentToken == key[i]) {
			return i;
		}
	}
	return 10;
}

void retract() {
	Index--;
}

//获取ch的类型
char ChType() {
	if (isalpha(ch)) {
		return 1;
	}
	else if (isdigit(ch)) {
		return 2;
	}
	return ch;
}
bool letter() {
	return isalpha(ch);
}

bool digtal() {
	return isdigit(ch);
}

void InitToken() {
	CurentToken = "";
}
//获取下一个
Token NextToken() {
	InitToken();
	getbc();
	int state = ChType();
	int t = 0;
	switch (state)
	{
	case 1:
		while (letter() || digtal()) {
			concat();
			getch();
		}
		retract();

		t = reserve();
		if (t == 10) {
			return Token(10, "标识符");
		}
		else {
			return Token(t);
		}
	case 2:
		while (digtal())
		{
			concat();
			getch();
		}
		retract();
		return Token(11, "整常数");
	case '+':
		concat(); 
		getch();
		if (ch == '+') {
			concat();
			return Token(34);
		}
		retract();
		return Token(12);
	case '-':
		concat();
		getch();
		if (ch == '>') {
			concat();
			return Token(30);
		}
		else if (ch == '-') {
			concat();
			return Token(35);
		}
		retract();
		return Token(13);
	case '*':
		concat();
		getch();

		if (ch == '/') {
			concat();
			return Token(29);
		}
		retract();
		return Token(14);
	case '/':
		concat();
		getch();
		if (ch == '/') {
			concat();
			return Token(27);
		}
		else if (ch == '*') {
			concat();
			return Token(28);
		}
		retract();
		return Token(15);

	case '<':
		concat();
		getch();
		if (ch == '=') {
			concat();
			return Token(17);
		}
		retract();
		return Token(16);
	case '>':
		concat();
		getch();
		if (ch == '=') {
			concat();
			return Token(19);
		}
		retract();
		return Token(18);
	case '=':
		concat();
		getch();
		if (ch == '=') {
			concat();
			return Token(22);
		}
		retract();
		return Token(20);
	case '!':
		concat();
		getch();
		if (ch == '=') {
			concat();
			return Token(21);
		}
		retract();
		return Token(31, "ERROR");
	case ';':concat(); return Token(23);
	case ':':concat(); return Token(24);
	case '(':concat(); return Token(25);
	case ')':concat(); return Token(26);
	case '{':concat(); return Token(31);
	case '}':concat(); return Token(32);
		//默认返回错误情况
	default:return Token(31, "ERROR");
	}
	return Token(31, "ERROR");
}
//展示读取的结果
void display() {
	printf_s("\n\n共读取%d个符号：\n", (int)tokens.size());
	for (auto t : tokens) {
		printf_s("<%s , %d , %s>\n", t.token.c_str(), t.typeCode, t.value.c_str());
	}
}

void Input() {
	printf_s("请输入您的代码，并以“etc”作为代码结尾:\n");
	string check = "";
	getline(cin, check);
	while (check != "etc") {
		code += " ";
		code += check;
		getline(cin, check);
	}
}
int main() {
	Input();
	length = code.length();
	while (Index < length) {
		tokens.push_back(NextToken());
	}
	int i = 5;

	display();
	return 0;
}

/*
测试案例
int main() {
	int num = 1;
	while (num < 0) {
		num += 1;
	}
	for (int i = 0; i < 10; i++) {
		if (i > 5)return;
	}
	return 0;
}
etc
*/