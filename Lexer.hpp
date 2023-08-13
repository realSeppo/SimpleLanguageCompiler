#pragma once
#include <list>
#include "Token.hpp"
#include <string>
#include <map>
using namespace std;

namespace Parsing {
	class Lexer final {
	private:
		map<char, TokenType> operatorsMap;

		const string input;
		list<Parsing::Token> tokens;
		const int length;
		int pos;

		char next();
		char peek(int relativePosition = 0);

		void tokenizeNumber();
		void tokenizeOperator();

		void addToken(TokenType type, string text = "");

	public:
		Lexer(string input) : input(input), pos(0), length(input.length()) {
			operatorsMap['+'] = TokenType::PLUS;
			operatorsMap['-'] = TokenType::MINUS;
			operatorsMap['*'] = TokenType::STAR;
			operatorsMap['/'] = TokenType::SLASH;
			operatorsMap['('] = TokenType::LPAREN;
			operatorsMap[')'] = TokenType::RPAREN;
		}
		
		list<Parsing::Token> tokenize();
	};
}
