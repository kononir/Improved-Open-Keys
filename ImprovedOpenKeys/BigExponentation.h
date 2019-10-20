#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

struct DivResult {
	string quotient, residue;
};

string exponentiationBig(string a, string x, string p);
string discretLogarithm(string a, string b, string p);

string sqrtBig(string x);
string mult(string x1, string x2);
string simpleMult(char a, char b);
string sum(string x1, string x2);
string simpleThreeSum(char a, char b, char c);
string simpleTwoSum(char a, char b);
DivResult div(string a, string b);
string simpleDiv(string a, string b);
string simpleMod(string a, string b);
bool isOdd(string x);
string fastDecr(string a);
string sub(string a, string b);
string simpleThreeSub(char a, char b, char c);
string simpleTwoSub(char a, char b);
string simpleSub(string a, string b);
bool moreThan(string a, string b);
bool moreOrEqual(string a, string b);