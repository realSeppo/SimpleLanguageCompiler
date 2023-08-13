#include <iostream>
#include <string>
#include "Lexer.hpp"
#include <list>
#include "Expression.hpp"
#include "Parser.hpp"
using namespace std;
using namespace ast;
using namespace Parsing;

int main()
{
	string input = "(2 + 2) * -2";
	Lexer lexer(input);
	list<Token> tokens = lexer.tokenize();

	for (Token& token : tokens) {
		cout << "Token: " + token.to_string() << endl;
	}

	list<Expression*> expressions = Parser(tokens).parse();

	for (Expression* expr : expressions) {
		cout << "Expression: " << to_string(expr->eval()) << endl;
	}

	return 0;
}
