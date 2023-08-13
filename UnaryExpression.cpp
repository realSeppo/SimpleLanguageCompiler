#include "Expression.hpp"
#include <typeinfo>

namespace ast {
	class UnaryExpression final : public Expression {
	private:
		Expression* expr;
		const char operation;
	public:

		UnaryExpression(char operation, Expression* expr) : operation(operation), expr(expr) {}

		double eval() override {

			switch (operation)
			{
			case '+':
				return expr->eval();
			case '-':
				return -expr->eval();
			default:
				return expr->eval();
			}
		}
	};
}