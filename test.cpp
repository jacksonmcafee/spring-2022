#include <iostream>
#include <string>
using namespace std;

class TestClass {
private:
    int val;
    string str;
    double dub;

public:
    int getVal() {
	return val;
	}
    string getStr() {
	return str;
	}
    double getDub() {
	return dub;
	}
    int getVal2() {
	return val2;
	}
    void setVal(int i) {
	val = i;
	}
    void setStr(string s) {
	str = s;
	}
    void setDub(double d) {
	dub = d;
	}
    void setVal2(int i) {
	val2 = i;
	}

    TestClass();

private:
    int val2;
};

TestClass::TestClass() {
   val = 1;
   str = "this is a class";
   dub = 1.0;
   val2 = 2;
}

int main() {

TestClass myClass;

cout << myClass.getStr() << endl;
cout << myClass.getVal() << endl;
cout << myClass.getVal2() << endl;
}
