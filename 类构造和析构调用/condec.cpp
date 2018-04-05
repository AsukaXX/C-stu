#include<iostream>

using namespace std;

class A {
public:
	A(int a = 0) :_a(a) {
		cout << "A co" << endl;
	}
	A(const A& a) {
		_a = a._a;
	}
	A& operator=(const A& a) {
		_a = a._a;
		return *this;
	}
	ostream& print(ostream &os) {
		os << "A" << endl;
		os << _a << endl;
		return os;
	}
	virtual ostream& v_print(ostream& os) {
		os << "A_v" << endl;
		os << _a << endl;
		return os;
	}
	~A() {
		cout << "A de" << endl;
	}
private:
	int _a;
};

class B :public A {
public:
	B(int a = 0,int b = 0) :A(a),_b(b) {
		cout << "B co" << endl;
	}
	B(const B& b) {
		_b = b._b;
	}
	B& operator=(const B& b) {
		_b = b._b;
		return *this;
	}
	ostream& print(ostream &os) {
		os << "B" << endl;
		os << _b << endl;
		return os;
	}
	virtual ostream& v_print(ostream& os) {
		os << "B_v" << endl;
		os << _b << endl;
		return os;
	}
	~B() {
		cout << "B de" << endl;
	}
private:
	int _b;
};

class C :public B {
public:
	C(int a = 0, int b = 0,int c = 0) :B(a,b),_c(c) {
		cout << "C co" << endl;
	}
	C(const C& c) {
		_c = c._c;
	}
	C& operator=(const C& c) {
		_c = c._c;
		return *this;
	}
	ostream& print(ostream &os) {
		os << "C" << endl;
		os << _c << endl;
		return os;
	}
	virtual ostream& v_print(ostream& os) {
		os << "C_v" << endl;
		os << _c << endl;
		return os;
	}
	~C() {
		cout << "C de" << endl;
	}
private:
	int _c;
};

int main() {
	A a(1), *a1, *a2, *a3;
	B b(2,3);
	C c(4,5,6);

	a1 = &a;
	a2 = &b;
	a3 = &c;

	a.print(cout);
	b.print(cout);
	c.print(cout);

	a1->print(cout);
	a2->print(cout);
	a3->print(cout);

	a1->v_print(cout);
	a2->v_print(cout);
	a3->v_print(cout);

	a = b;
	a.print(cout);
	a = c;
	a.print(cout);
	return 0;
}