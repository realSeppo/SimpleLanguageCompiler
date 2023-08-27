#include "Statement.hpp"
#include <string>
#include "Expression.hpp"
#include "Variables.hpp"

using namespace libs;
using namespace std;

namespace ast
{
	class AssignmentStatement final : public Statement {
	private:
		const string variable;
		Expression* expression;
	public:
		AssignmentStatement(string variable, Expression* expression) :
			variable(variable), expression(expression) {}

		void execute() override {
			const double result = expression->eval();
			Variables::set(variable, result);
		}
		string toString() override{
			return variable + " = " + to_string(expression->eval());
		}
	};
}