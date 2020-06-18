#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

enum AST_Kind { INT,ADD, TIMES, ID, SUB, OTHER };
typedef struct ASTNode* AST;
struct ASTNode {
	int value;
	AST_Kind kind; 
	AST left;
	AST right;
};

AST CreateASTNode(string value,AST_Kind kind, AST left,AST right) {
	AST temp = (AST)malloc(sizeof(ASTNode));
	temp->value = atoi(value.c_str());
	temp->kind = kind;
	temp->left = left;
	temp->right = right;
	return temp;
}


enum OP_Type{S,R,N,A};
struct OP {
	OP_Type type = N;
	int state = -1;
	OP(OP_Type type,int state){
		this->type = type;
		this->state = state;
	}
	OP(OP_Type type) {
		this->type = type;
	}
	OP() {
		this->type = N;
	}
};

OP ACTION[12][7] = {
	//num     +       -        *         (          )        $
	{OP(S,6),OP()   ,OP(S,5)  ,OP()   , OP(S,2)   ,OP()    ,OP()},//0
	{OP()   ,OP(S,4),OP()     ,OP(S,3), OP(S,2)   ,OP()    ,OP(A)},//1
	{OP(S,6),OP()   ,OP(S,5)  ,OP()   , OP(S,2)   ,OP()    ,OP()},//2
	{OP(S,6),OP()   ,OP(S,5)  ,OP()   , OP(S,2)   ,OP()    ,OP()},//3
	{OP(S,6),OP()   ,OP(S,5)  ,OP()   , OP(S,2)   ,OP()    ,OP()},//4
	{OP(S,6),OP()   ,OP(S,5)  ,OP()   , OP(S,2)   ,OP()    ,OP()},//5
	{OP(R,6),OP(R,6),OP(R,6)  ,OP(R,6), OP(R,6)   ,OP(R,6) ,OP(R,6)},//6
	{OP(R,3),OP(R,3),OP(R,3)  ,OP(R,3), OP(R,3)   ,OP(R,3) ,OP(R,3)},//7
	{OP()   ,OP(R,2),OP()     ,OP(S,3), OP()      ,OP(R,2) ,OP(R,2)},//8
	{OP()   ,OP()   ,OP()     ,OP()   , OP()      ,OP(R,5) ,OP(R,5)},//9
	{OP()   ,OP(S,4),OP()     ,OP(S,3) ,OP()      ,OP(S,11),OP()},//10
	{OP(R,4),OP(R,4),OP(R,4)  ,OP(R,4), OP(R,4)   ,OP(R,4) ,OP(R,4)},//11
};

OP GOTO[12] = { OP(S,1),OP(),OP(S,10),OP(S,7),OP(S,8),OP(S,9),OP(R,6),OP(),OP(),OP(),OP(),OP(R,4) };
/*
TINT：整形数
*/
enum TokenType { TINT, TADD, TSUB, TTIME, TLB, TRB,TEND,TERROR,TE };
struct Token {
	Token(TokenType type, string value) {
		this->type = type;
		this->value = value;
	}
	Token(){}
	TokenType type;
	string value;
};

int n = 0;
string Input;
queue<Token> tokenq;
stack<Token> tokent;
vector<Token> tokens;
stack<AST> asts;
stack<int> state;


//生成符号数组
void CreateTokens() {
	string temp;
	int i = 0;
	for (auto c : Input) {
		if (c == '=')break;
		i++;
	}
	string Input1 = string(Input, i+1);
	for (auto c : Input1) {
		if (isblank(c))continue;

		if (isalnum(c)) {
			temp += c;
		}
		else {
			if (temp.length()>0) {
				tokens.push_back(Token(TINT, temp));
			}
			
			temp = c;
			switch (c)
			{
			case '+':
				tokens.push_back(Token(TADD, temp));
				break;
			case '-':
				tokens.push_back(Token(TSUB, temp));
				break;
			case '*':
				tokens.push_back(Token(TTIME, temp));
				break;
			case '(':
				tokens.push_back(Token(TLB, temp));
				break;
			case ')':
				tokens.push_back(Token(TRB, temp));
				break;
			}
			temp = "";
		}
	}
	if (temp.length() > 0) {
		tokens.push_back(Token(TINT, temp));
	}
}

//生成符号队列
void CreateTokenQueue() {
	for (auto t : tokens) {
		tokenq.push(t);
	}
}

Token NextToken() {
	if (tokenq.size() > 0) {
		Token temp = tokenq.front();
		tokenq.pop();
		return temp;
	}
	else {
		return Token(TERROR, "");
	}
	
}

AST_Kind GetKindByKind(TokenType type) {
	switch (type)
	{
	case TINT:
		return INT;
		break;
	case TADD:
		return ADD;
		break;
	case TSUB:
		return SUB;
		break;
	case TTIME:
		return TIMES;
		break;
	default:
		return OTHER;
		break;
	}
}


AST CreateASTNode(Token e) {
	if (e.type == TE) {
		AST temp = asts.top();
		asts.pop();
		return temp;
	}
	return CreateASTNode(e.value, GetKindByKind(e.type), NULL, NULL);
}

//构造抽象语法树
void CreateAST() {
	
	int cs;
	state.push(0);
	Token t;
	while (true)
	{
		if (tokenq.size() == 0) {
			t = Token(TEND,"");
		}
		else {
			t = tokenq.front();
		}
		
		cs = state.top();
		if (ACTION[cs][t.type].type == S) {
			state.push(ACTION[cs][t.type].state);
			tokent.push(t);
			tokenq.pop();
		}
		else if (ACTION[cs][t.type].type == R) {
			Token e1, e2, e3;
			AST a1, a2, a3;
			switch (ACTION[cs][t.type].state)
			{
			case 2:
			case 3:
				e1 = tokent.top();
				tokent.pop();
				e2 = tokent.top();
				tokent.pop();
				e3 = tokent.top();
				tokent.pop();
				state.pop();
				state.pop();
				state.pop();
				a3 = CreateASTNode(e3);
				a1 = CreateASTNode(e1);
				a2 = CreateASTNode(e2.value, GetKindByKind(e2.type), a1, a3);
				break;
			case 4:
				tokent.pop();
				e2 = tokent.top();
				tokent.pop();
				tokent.pop();
				state.pop();
				state.pop();
				state.pop();
				a2 = CreateASTNode(e2);
				break;
			case 5:
				e2 = tokent.top();
				tokent.pop();
				state.pop();
				tokent.pop();
				state.pop();
				a3 = CreateASTNode(e2);
				a2 = CreateASTNode("-", SUB, a3, NULL);				
				break;
			case 6:
				e2 = tokent.top();
				tokent.pop();
				state.pop();
				a2 = CreateASTNode(e2);
				break;
			}
			asts.push(a2);
			cs = state.top();
			tokent.push(Token(TE, ""));
			state.push(GOTO[cs].state);
		}
		else if (ACTION[cs][t.type].type == A) {
			break;
		}
	}
}

int GetCode() {
	return n++;
}

int Gen_E(AST a) {
	int temp = 0;
	int l, r;
	switch (a->kind)
	{
	case INT:
		temp = GetCode();
		printf("X_%d = %d\n", temp, a->value);
		break;
	case ADD:
		l = Gen_E(a->left);
		r = Gen_E(a->right);
		temp = GetCode();
		printf("X_%d = X_%d + X_%d\n",temp,l,r);
		break;
	case SUB:
		l = Gen_E(a->left);
		temp = GetCode();
		printf("X_%d = -X_%d\n", temp, l);
		break;
	case TIMES:
		l = Gen_E(a->left);
		r = Gen_E(a->right);
		temp = GetCode();
		printf("X_%d = X_%d * X_%d\n", temp, l, r);
		break;
	}
	return temp;
}


int Gen_S() {
	string temp;
	for (auto c : Input) {
		if (c == '=')break;
		temp += c;
	}
	int x = Gen_E(asts.top());
	printf("%s = X_%d", temp.c_str(), x);
	return 0;
}

int main() {
	cout << "请输入算式(输入的所有符号均为英文)：" << endl;
	cin >> Input;
	CreateTokens();
	CreateTokenQueue();
	CreateAST();
	cout << "所生成的三地址码为：" << endl;
	Gen_S();
	return 0;
}