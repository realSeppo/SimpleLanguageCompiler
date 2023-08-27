#include "Expression.hpp"
#include <typeinfo>
#include <string>
#include "Variables.hpp"
#include <iostream>
using namespace std;
using namespace libs;

namespace ast {
	class VariableExpression final : public Expression {
	private:
		const string name;

	public:

		VariableExpression(string name) : name(name) {}

		double eval() override {
			if (!Variables::isExist(name)) {
				cerr << "Variable does not exist" << endl;
				exit(0);
			}
			else {
				return Variables::get(name);
			}
		}
	};
}