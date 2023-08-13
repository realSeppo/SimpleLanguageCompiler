#include "Expression.hpp"
#include <typeinfo>

namespace ast {
	class NumberExpression final : public Expression {
	private:
		const double value;

	public:

		NumberExpression(double value) : value(value) {}
			
		double eval() override {
			return value;
		}
	};
}