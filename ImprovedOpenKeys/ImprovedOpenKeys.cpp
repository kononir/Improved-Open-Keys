// ImprovedOpenKeys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include "BigExponentation.h"
#include "BigExponentationTests.h"

using namespace std;

int main()
{
	runTests();

	string a;
	cout << "Input a: ";
	getline(cin, a);
	cout << "Length a = " << a.size() << endl;
	string x;
	cout << "Input x: ";
	getline(cin, x);;
	cout << "Length x = " << x.size() << endl;
	string p;
	cout << "Input p: ";
	getline(cin, p);
	cout << "Length p = " << p.size() << endl << endl;

	string res = exponentiationBig(a, x, p);
	cout << "Exponentiation result: " << res << endl;
	cout << "Length result = " << res.size() << endl << endl;;

	system("pause");
}
