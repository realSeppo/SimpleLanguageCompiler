#pragma once
#include <string>

namespace ast {
	class Statement {
	public:
		virtual void execute() = 0;
		virtual std::string toString() = 0;
	};
}