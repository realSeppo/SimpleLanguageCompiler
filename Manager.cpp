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
	string input = "varA = 100 * PI	varB = 10 print varA - varB";
	Lexer lexer(input);
	list<Token> tokens = lexer.tokenize();

	for (Token& token : tokens) {
		cout << "Token: " + token.to_string() << endl;
	}

	list<Statement*> statements = Parser(tokens).parse();

	for (Statement* statement : statements) {
		//cout << statement->toString() << endl;
		statement->execute();
	}
	return 0;
}
