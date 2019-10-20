// ImprovedOpenKeys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "BigExponentation.h"
#include "BigExponentationTests.h"

using namespace std;

int main()
{
	runTests();

	string p;
	cout << "Input p: ";
	getline(cin, p);
	cout << "Length p = " << p.size() << endl;
	string a;
	cout << "Input a: ";
	getline(cin, a);
	cout << "Length a = " << a.size() << endl;
	string xA;
	cout << "Input Allice x: ";
	getline(cin, xA);;
	cout << "Allice x length = " << xA.size() << endl;
	string xB;
	cout << "Input Bob x: ";
	getline(cin, xB);;
	cout << "Bob x length = " << xB.size() << endl << endl;

	string yA = exponentiationBig(a, xA, p);
	cout << "Found opened key of Allice: " << yA << endl;
	cout << "Allice opened key length = " << yA.size() << endl;

	string yB = exponentiationBig(a, xB, p);
	cout << "Found opened key of Bob: " << yB << endl;
	cout << "Bob opened key length = " << yB.size() << endl << endl;

	string zA = exponentiationBig(yB, xA, p);
	cout << "Found secret key of Allice/Bob: " << zA << endl;
	cout << "Allice/Bob secret key length = " << zA.size() << endl;

	string zB = exponentiationBig(yA, xB, p);
	cout << "Found secret key of Bob/Allice: " << zB << endl;
	cout << "Bob/Allice secret key length = " << zB.size() << endl << endl;

	cout << "Do you want to hack? (y/n) ";
	if (_getch() == 'y') {
		cout << endl;

		string hacked_key = discretLogarithm(a, yB, p);
		cout << "Hacked key: " << hacked_key << endl;
		cout << "Hacked key length = " << hacked_key.size() << endl << endl;
	}

	system("pause");
}
