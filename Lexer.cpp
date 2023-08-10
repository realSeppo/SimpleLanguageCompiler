#include "Lexer.hpp"
#include "TokenType.hpp"
#include <string>
#include <list>
using namespace std;

namespace Parser {
	list<Parser::Token> Lexer::tokenize() {
		while (pos < length){
			char current = peek(0);

			if (isdigit(current)) tokenizeNumber();
			else if (operatorsMap.find(current) != operatorsMap.end())
				tokenizeOperator();
			else {
				next(); // пробел/табул€ци€
			}
		}
		return tokens;
	}

	void Lexer::tokenizeNumber() {
		string buffer;
		char current = peek(0);

		while (true) {
			if (isdigit(peek(0))) {
				buffer += current;
				next();
			}
			else break;
		}
		addToken(TokenType::NUMBER, buffer);
	}
	void Lexer::tokenizeOperator() {
		addToken(operatorsMap.at(peek(0)));
		next();
	}

	char Lexer::next() {
		pos++;
		return peek(0);
	}
	char Lexer::peek(int relativePosition) {
		const int position = pos + relativePosition;

		if (position >= length) return '\0';
		return input[position];
	}

	void Lexer::addToken(TokenType type, string text) {
		Lexer::tokens.push_back(Parser::Token(type, text));
	}
}