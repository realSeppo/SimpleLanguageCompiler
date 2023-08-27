#include "Lexer.hpp"
#include "TokenType.hpp"
#include <string>
#include <list>
#include <iostream>
using namespace std;

namespace Parsing {
	list<Parsing::Token> Lexer::tokenize() {
		while (pos < length) {
			char current = peek();

			if (isdigit(current)) tokenizeNumber();
			else if (isalpha(current)) tokenizeWord();
			else if (operatorsMap.find(current) != operatorsMap.end()) tokenizeOperator();
			else next(); // пробел/табул€ци€
		}
		return tokens;
	}

	void Lexer::tokenizeWord() {
		string buffer;

		while (true) {
			char current = peek();
			if (!isalnum(current) && (current != '_') && (current != '$')) {
				break;
			}
			else {
				buffer += current;
				next();
			}
		}
		if (buffer == "print") addToken(TokenType::PRINT);
		else addToken(TokenType::WORD, buffer);
	}

	void Lexer::tokenizeNumber() {
		string buffer;

		while (true) {
			char current = peek();
			if (isdigit(current)) {
				buffer += current;
				next();
			}
			else if (current == '.') {
				if (buffer.find(current) == string::npos) {
					cerr << "Invalid number" << endl;
					exit(0);
				}
				else {
					buffer += current;
					next();
				}
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