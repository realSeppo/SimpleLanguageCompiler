#include "Statement.hpp"
#include <string>
#include "Expression.hpp"
#include "Variables.hpp"
#include <iostream>

using namespace libs;
using namespace std;

namespace ast
{
	class PrintStatement final : public Statement {
	private:
		Expression* expression;
	public:
		PrintStatement(Expression* expression) : expression(expression) {}

		void execute() override {
			cout << expression->eval();
		}
		string toString() override {
			return "print " + to_string(expression->eval());
		}
	};
}