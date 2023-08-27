#pragma once
#include <string>
#include <map>
using namespace std;

namespace libs {
	class Variables final {
	public:
		static bool isExist(string key);
		static double get(string key);
		static void set(string key, double value);
	private:
		static map<string, double> variables;
	};
}