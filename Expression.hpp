#pragma once
#include <string>

namespace ast {
	class Expression {
	public:
		virtual double eval() = 0;
	};
}