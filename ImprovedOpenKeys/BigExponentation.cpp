#include "pch.h"
#include "BigExponentation.h"

string exponentiationBig(string a, string x, string p) {
	string buf = "1";
	string curr_a;
	if (x == "0") {
		curr_a = "1";
	}
	else {
		curr_a = a;
	}

	while (moreThan(x, "1")) {
		curr_a = div(curr_a, p).residue;
		if (curr_a == "1" || curr_a == "0") {
			break;
		}

		buf = div(buf, p).residue;

		if (isOdd(x)) {
			buf = mult(buf, curr_a);
			x = fastDecr(x);
		}

		curr_a = mult(curr_a, curr_a);
		x = div(x, "2").quotient;
	}

	curr_a = div(curr_a, p).residue;
	buf = div(buf, p).residue;

	return div(mult(buf, curr_a), p).residue;
}

string discretLogarithm(string a, string b, string p)
{
	string H = sum(sqrtBig(p), "1");
	string c = exponentiationBig(a, H, p);

	unordered_map<string, string> u_table;
	for (string u = "1"; moreOrEqual(H, u); u = sum(u, "1")) {
		string key = exponentiationBig(c, u, p);
		u_table.insert(pair<string, string>(key, u));
	}
	unordered_map<string, string> v_table;
	for (string v = "0"; moreOrEqual(H, v); v = sum(v, "1")) {
		string key = div(mult(div(b, p).residue, exponentiationBig(a, v, p)), p).residue;
		v_table.insert(pair<string, string>(key, v));
	}

	string u;
	string v;
	auto u_table_iter = u_table.begin();
	while (true) {
		auto v_table_iter = v_table.find(u_table_iter->first);
		if (v_table_iter != v_table.end()) {
			u = u_table_iter->second;
			v = v_table_iter->second;
			break;
		}
		u_table_iter++;
	}

	return div(sub(mult(H, u), v), sub(p, "1")).residue;
}

string sqrtBig(string x)
{
	int two_dig_size = x.size() / 2 + x.size() % 2;

	string* two_dig = new string[two_dig_size];
	auto x_iter = x.rbegin();
	auto end = x.rend();
	int two_dig_num = 0;
	while (x_iter != end) {
		char second = *x_iter;
		x_iter++;
		if (x_iter != end) {
			two_dig[two_dig_num] = string(1, *x_iter) + string(1, second);

			two_dig_num++;
			x_iter++;
		}
		else {
			two_dig[two_dig_num] = string(1, second);
		}
	}

	two_dig_num = two_dig_size - 1;
	string first_two_dig = two_dig[two_dig_num];
	string result = to_string((int)sqrt(stoi(first_two_dig)));
	
	string residue = sub(first_two_dig, mult(result, result));
	if (first_two_dig != "0" && residue == "0") {
		residue = "";
	}

	two_dig_num--;
	if (two_dig_num >= 0) {
		residue += two_dig[two_dig_num];
	}

	while (two_dig_num >= 0) {
		string buff = mult(result, "2");
		string residue_without_last = residue.substr(0, residue.size() - 1);
		string div_res = div(residue_without_last, buff).quotient;

		two_dig_num--;
		if (two_dig_num >= 0) {
			if (div_res != "0") {
				buff += div_res;
				residue = sub(residue, mult(buff, div_res));
			}
			else {
				residue += two_dig[two_dig_num];
			}
		}
		
		result += div_res;
	}

	return result;
}

string mult(string x1, string x2) {
	string a;
	string b;
	if (x1.size() > x2.size()) {
		a = x1;
		b = x2;
	}
	else {
		a = x2;
		b = x1;
	}

	string outer_buf = "0";
	string outer_shift = "";
	for (auto i = b.rbegin(); i != b.rend(); i++) {
		string inner_buf = "0";
		string inner_shift = "";
		for (auto j = a.rbegin(); j != a.rend(); j++) {
			inner_buf = sum(inner_buf, simpleMult(*i, *j) + inner_shift);
			inner_shift = inner_shift + "0";
		}
		outer_buf = sum(outer_buf, inner_buf + outer_shift);
		outer_shift = outer_shift + "0";
	}

	return outer_buf;
}

string simpleMult(char a, char b) {
	int integer_a = a - '0';
	int integer_b = b - '0';

	return to_string(integer_a * integer_b);
}

string sum(string x1, string x2) {
	string a;
	string b;
	if (x1.size() > x2.size()) {
		a = x1;
		b = x2;
	}
	else {
		a = x2;
		b = x1;
	}

	string res;
	char general_buf = '0';
	auto a_iter = a.rbegin();
	auto b_iter = b.rbegin();

	for (unsigned int i = 0; i < b.size(); a_iter++, b_iter++, i++) {
		string curr_sum = simpleThreeSum(*a_iter, *b_iter, general_buf);
		if (curr_sum.size() == 2) {
			general_buf = '1';
			res = curr_sum[1] + res;
		}
		else {
			general_buf = '0';
			res = curr_sum[0] + res;
		}
	}

	for (int j = 0; j < a.size() - b.size(); a_iter++, j++) {
		string curr_sum = simpleTwoSum(*a_iter, general_buf);
		if (curr_sum.size() == 2) {
			general_buf = '1';
			res = curr_sum[1] + res;
		}
		else {
			general_buf = '0';
			res = curr_sum[0] + res;
		}
	}

	if (general_buf == '1') {
		res = general_buf + res;
	}

	return res;
}

string simpleThreeSum(char a, char b, char c) {
	int integer_a = a - '0';
	int integer_b = b - '0';
	int integer_c = c - '0';

	return to_string(integer_a + integer_b + integer_c);
}

string simpleTwoSum(char a, char b) {
	int integer_a = a - '0';
	int integer_b = b - '0';

	return to_string(integer_a + integer_b);
}

DivResult div(string a, string b) {
	string residue = a;
	string quotient;
	while (moreOrEqual(residue, b)) {
		// search for length of current divident (>= divider)
		unsigned int curr_divident_len = 1;
		while (!moreOrEqual(residue.substr(0, curr_divident_len), b) && curr_divident_len < residue.size()) {
			curr_divident_len++;
		}

		// add current result to general result
		quotient += simpleDiv(residue.substr(0, curr_divident_len), b);

		// update residue (add current residue)
		string curr_residue = simpleMod(residue.substr(0, curr_divident_len), b);
		if (residue.size() > curr_divident_len) {
			residue = residue.substr(curr_divident_len, residue.size() - curr_divident_len);
			if (curr_residue != "0") {
				residue = curr_residue + residue;
			}
		}
		else {
			residue = curr_residue;
		}

		if (residue.size() > 1) {
			// search for remaining zeros and add its to global result
			unsigned int num_of_zeros = 0;
			while (num_of_zeros < residue.size()) {
				if (residue[num_of_zeros] == '0') {
					num_of_zeros++;
					quotient += '0';
				}
				else {
					break;
				}
			}

			// update residue (add zeros)
			if (num_of_zeros == residue.size()) {
				residue = "0";
			}
			else if (num_of_zeros > 0) {
				residue = residue.substr(num_of_zeros, residue.size());
			}
		}
	}

	if (quotient.empty()) {
		quotient = "0";
	}

	return DivResult{ quotient, residue };
}

string simpleDiv(string a, string b) {
	int num = 0;
	string curr_a = a;

	while (moreOrEqual(curr_a, b)) {
		curr_a = sub(curr_a, b);
		num++;
	}

	return to_string(num);
}

string simpleMod(string a, string b) {
	string curr_a = a;

	while (moreOrEqual(curr_a, b)) {
		curr_a = sub(curr_a, b);
	}

	return curr_a;
}

bool isOdd(string x) {
	char last = x.back();
	return last == '1' || last == '3' || last == '5' || last == '7' || last == '9';
}

// decrements a; doesn't work with template ^[1-9]+0{2,}$
string fastDecr(string a) {
	if (a.size() > 2) {
		string first_part = a.substr(0, a.size() - 2);
		string two_last_dig = a.substr(a.size() - 2, 2);
		return first_part + simpleSub(two_last_dig, "1");
	}
	else {
		return simpleSub(a, "1");
	}
}

// doesn't work with x1 < x2
string sub(string x1, string x2) {
	string a = x1;
	string b = x2;

	string res;
	char general_buf = '0';
	auto a_iter = a.rbegin();
	auto b_iter = b.rbegin();

	for (unsigned int i = 0; i < b.size(); a_iter++, b_iter++, i++) {
		string curr_sub = simpleThreeSub(*a_iter, *b_iter, general_buf);
		if (curr_sub.size() == 2) {
			general_buf = '1';
			res = to_string(10 + stoi(curr_sub)) + res;
		}
		else if (curr_sub.size() == 1) {
			general_buf = '0';
			res = curr_sub[0] + res;
		}
		// when a[i] = 0, b[i] = 9, general_buf = 1 => 0 - 9 - 1 = -10
		else if (curr_sub.size() == 3) {
			general_buf = '1';
			res = '0' + res;
		}
	}

	for (int j = 0; j < a.size() - b.size(); a_iter++, j++) {
		string curr_sub = simpleTwoSub(*a_iter, general_buf);
		if (curr_sub.size() == 2) {
			general_buf = '1';
			res = to_string(10 + stoi(curr_sub)) + res;
		}
		else {
			general_buf = '0';
			res = curr_sub[0] + res;
		}
	}

	if (general_buf == '1') {
		res = '-' + res;
	}

	// perform to delete extra zeros (pass one zero)
	if (res[0] != '0' || res.size() == 1) {
		return res;
	}
	else {
		int zero_num = 1;
		int i = 1;
		while (i < res.size()) {
			if (res[i] != '0') {
				return res.substr(zero_num, res.size() - zero_num);
			}
			zero_num++;
			i++;
		}
		return "0";
	}
}

string simpleThreeSub(char a, char b, char c) {
	int integer_a = a - '0';
	int integer_b = b - '0';
	int integer_c = c - '0';

	return to_string(integer_a - integer_b - integer_c);
}

string simpleTwoSub(char a, char b) {
	int integer_a = a - '0';
	int integer_b = b - '0';

	return to_string(integer_a - integer_b);
}

string simpleSub(string a, string b) {
	return to_string(stoi(a) - stoi(b));
}

bool moreThan(string a, string b) {
	unsigned int a_len = a.size();
	unsigned int b_len = b.size();

	if (a_len > b_len) {
		return true;
	}
	else if (b_len > a_len) {
		return false;
	}

	unsigned int len = a_len;
	unsigned int i = 0;
	while (i < len) {
		if (a[i] > b[i]) {
			return true;
		}
		else if (b[i] > a[i]) {
			return false;
		}

		i++;
	}

	return false;
}

bool moreOrEqual(string a, string b) {
	if (a == b) {
		return true;
	}
	else {
		return moreThan(a, b);
	}
}