/*
原语文法
exp ::= exp addop term | term
addop ::= + | -
term ::= term mulop factor | factor
mulop ::= * | /
factor ::= (exp) | number

消除做递归后
exp ::= term exp1
exp1 ::=addop term
     ::=空
addop ::= + | -
term ::= factor term1
term1 ::=  mulop factor
      ::=  空
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

