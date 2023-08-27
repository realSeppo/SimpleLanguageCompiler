#pragma once
#include <list>
#include "Token.hpp"
#include "Expression.hpp"
#include "TokenType.hpp"
#include "Statement.hpp"
#include "AssignmentStatement.cpp"
using namespace ast;

namespace Parsing {
	class Parser final {
	private:
		const Token FILEEND;
		const list<Token> tokens;
		const int size;
		int pos;

		Statement* statement();
		Statement* assigmentStatement();

		Expression* expression();
		Expression* additive();
		Expression* multiplicative();
		Expression* unary();
		Expression* primary();

		Token get(int relativePosition = 0);
		bool consume(TokenType type);
		bool match(TokenType type);
	public:
		Parser(list<Token> tokens) : tokens(tokens),
			size(tokens.size()),
			pos(0),
			FILEEND(Token(TokenType::FILEEND, "")) {}

		list<Statement*> parse();
	};
}