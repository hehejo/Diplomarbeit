#include <string>
#include <iostream>
using namespace std;

struct Dec_A {
	const string decorate(const string& s) const {
		return "A" + s +"A"
	}
};

struct Print {
	void print(const string& s) const {
		cout << s;
	}
};

template <class Decorator, class Printer>
struct Ausgabe : public Decorator, public Printer {
	void put(string s) const {
		Printer::print(Decorator::decorate(s));
	}
};

Ausgabe<Dec_A, Print> bar;
bar.put("Guten Tag");
// -> AGuten TagA
