#include "Expression.hpp"
#include <string>

namespace ast {
	class BinaryExpression final : public Expression {
	private:
		Expression* expr1;
		Expression* expr2;
		const char operation;

	public:
		BinaryExpression(char operation, Expression* expr1, Expression* expr2) : operation(operation) {
			this->expr1 = expr1;
			this->expr2 = expr2;
		}

		double eval() override {

			switch (operation)
			{
			case '+':
				return  expr1->eval() + expr2->eval();
			case '-':
				return expr1->eval() - expr2->eval();
			case '*':
				return expr1->eval() * expr2->eval();
			case '/':
				return expr1->eval() / expr2->eval();
			default:
				return expr1->eval() + expr2->eval();
			}
		}
	};
}