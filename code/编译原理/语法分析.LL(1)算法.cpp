/*
ԭ���ķ�
exp ::= exp addop term | term
addop ::= + | -
term ::= term mulop factor | factor
mulop ::= * | /
factor ::= (exp) | number

�������ݹ��
exp ::= term exp1
exp1 ::=addop term
     ::=��
addop ::= + | -
term ::= factor term1
term1 ::=  mulop factor
      ::=  ��
mulop ::= * | /
factor ::= (exp) | number
*/
#include <iostream>
#include <vector>
using namespace std;

enum tokeType
{
	terminal,nontermial
};
struct token {
	tokeType type;
	string name;
};

struct Produation {
	token Right;
	vector<token> Left;
};

Produation p[9];

