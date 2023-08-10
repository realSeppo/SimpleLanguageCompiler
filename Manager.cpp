#include <iostream>
#include <string>
#include "Lexer.hpp"
using namespace std;

int main()
{
	string input = "2 + 3 * 10";
	Parser::Lexer lexer(input);
	list<Parser::Token> tokens = lexer.tokenize();

	for (Parser::Token& token : tokens) {
		cout << "Token: " + token.to_string() << endl;
	}
	return 0;
}
