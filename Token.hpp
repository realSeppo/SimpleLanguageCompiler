#pragma once
#include <string>
#include "TokenType.hpp"
#include <map>
using namespace std;

namespace Parsing {
	class Token final {
	private:
		string text;
		TokenType type;

	public:
		Token() = default;
		Token(TokenType type, string text) : type(type),
			text(text) {}

		TokenType getType() {
			return type;
		}
		void setType(TokenType type) {
			this->type = type;
		}

		string getText() {
			return text;
		}
		void setText(string text) {
			this->text = text;
		}

		string to_string() {
			return "N" + std::to_string(static_cast<int>(type)) + "; text: " + text;
		}
	};
}