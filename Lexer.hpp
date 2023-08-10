#include <list>
#include "Token.hpp"
#include <string>
#include <map>
using namespace std;

namespace Parser {
	class Lexer final {
	private:
		map<char, TokenType> operatorsMap;

		const string input;
		list<Parser::Token> tokens;
		const int length;
		int pos;

		char next();
		char peek(int relativePosition);

		void tokenizeNumber();
		void tokenizeOperator();

		void addToken(TokenType type, string text = "");

	public:
		Lexer(string input) : input(input), length(input.length()) {
			operatorsMap['+'] = TokenType::PLUS;
			operatorsMap['-'] = TokenType::MINUS;
			operatorsMap['*'] = TokenType::STAR;
			operatorsMap['/'] = TokenType::SLASH;
		}
		
		list<Parser::Token> tokenize();
	};
}
