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
	string input = "varA = 100 * PI	varB = 10 print varA - varB"; //код
	list<Token> tokens = Lexer(input).tokenize(); // перевод кода в токены (enum с ними в TokenType.hpp)

	for (Token& token : tokens) {
		cout << "Token: " + token.to_string() << endl; //вывод информации о токенах
	}

	list<Statement*> statements = Parser(tokens).parse(); //получение операторов

	for (Statement* statement : statements) {
		cout << statement->toString() << endl; //вывод информации об операторах
		statement->execute(); //выполнение оператора, например, присвоение переменной
	}
	return 0;
}
