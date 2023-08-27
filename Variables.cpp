#include <string>
#include <map>
#include "Variables.hpp"
using namespace std;

namespace libs {
	bool Variables::isExist(string key) {
		return variables.find(key) != variables.end();
	}
	double Variables::get(string key) {
		if (!isExist(key)) return 0;
		return variables.at(key);
	}
	void Variables::set(string key, double value) {
		variables[key] = value;
	}

	map<string, double> Variables::variables = { {"PI", 3.14}, {"GOLDEN_RATIO", 1.61}, {"E", 2.71}};
}