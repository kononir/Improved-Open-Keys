// ImprovedOpenKeys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cassert>
#include "BigExponentation.h"
#include "BigExponentationTests.h"

using namespace std;

int main()
{
	assert(runTests() == 0);

	string p, a, x1, x2, y1, y2, z1, z2, hacked_key, x, res;

	while (true) {
		cout << "1 - Diffi-Helman algorithm,\n2 - Testing discret exponentation,\n0 - Exit\n\n";
		switch (_getch()) {
		case 49:
			cout << "Input p: ";
			getline(cin, p);
			cout << "Input a: ";
			getline(cin, a);
			cout << "Input x1: ";
			getline(cin, x1);
			cout << "Input x2: ";
			getline(cin, x2);

			y1 = exponentiationBig(a, x1, p);
			cout << "Found opened key y1: " << y1 << endl;

			y2 = exponentiationBig(a, x2, p);
			cout << "Found opened key y2: " << y2 << endl;

			z1 = exponentiationBig(y2, x1, p);
			cout << "Found secret key z1: " << z1 << endl;

			z2 = exponentiationBig(y1, x2, p);
			cout << "Found secret key z2: " << z2 << endl;

			cout << "Do you want to hack x1? (y/n) ";
			if (_getch() == 'y') {
				cout << endl;

				hacked_key = discretLogarithm(a, y2, p);
				cout << "Hacked key x1: " << hacked_key << endl;
			}
			cout << endl;

			break;
		case 50:
			cout << "Input p: ";
			getline(cin, p);
			cout << "Length p = " << p.size() << endl;

			cout << "Input a: ";
			getline(cin, a);
			cout << "Length a = " << a.size() << endl;

			cout << "Input x: ";
			getline(cin, x);;
			cout << "x length = " << x.size() << endl;

			res = exponentiationBig(a, x, p);
			cout << "Exponentation result: " << res << endl;
			cout << "Result length = " << res.size() << endl;

			cout << endl;

			break;
		case 48:
			return 0;
		default:
			break;
		}
	}
}
