#include "Lexer.hpp"
#include "TokenType.hpp"
#include <string>
#include <list>
using namespace std;

namespace Parsing {
	list<Parsing::Token> Lexer::tokenize() {
		while (pos < length){
			char current = peek();

			if (isdigit(current)) tokenizeNumber();
			else if (operatorsMap.find(current) != operatorsMap.end()) tokenizeOperator();
			else next(); // пробел/табул€ци€
		}
		return tokens;
	}

	void Lexer::tokenizeNumber() {
		string buffer;

		while (true) {
			char current = peek();
			if (isdigit(current)) {
				buffer += current;
				next();
			}
			else break;
		}
		addToken(TokenType::NUMBER, buffer);
	}

	void Lexer::tokenizeOperator() {
		addToken(operatorsMap.at(peek()));
		next();
	}

	char Lexer::next() {
		pos++;
		return peek();
	}
	char Lexer::peek(int relativePosition) {
		const int position = pos + relativePosition;

		if (position >= length) return '\0';
		return input[position];
	}

	void Lexer::addToken(TokenType type, string text) {
		Lexer::tokens.push_back(Parsing::Token(type, text));
	}
}