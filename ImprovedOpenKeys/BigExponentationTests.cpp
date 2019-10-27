#include "pch.h"
#include "BigExponentationTests.h"

int runTests() {
	int testNumber, passedNumber = 0;

	cout << "\t\t\t\t Tests:" << endl;

	for (testNumber = 0; testNumber < sizeof(tests) / sizeof(tests[0]); testNumber++) {
		int rezult = (*tests[testNumber])();

		if (rezult == TEST_PASSED) {
			cout << names[testNumber] + " passed!" << endl;
			passedNumber++;
		}
	}

	cout << endl << to_string(passedNumber) + " tests passed!" << endl << endl;

	return 0;
}

int test_sum_should_return_4_when_given_2_2() {
	assert("4" == sum("2", "2"));
	return TEST_PASSED;
}

int test_sum_should_return_16_when_given_2_14()
{
	assert("16" == sum("2", "14"));
	return TEST_PASSED;
}

int test_sum_should_return_22_when_given_5_17()
{
	assert("22" == sum("5", "17"));
	return TEST_PASSED;
}

int test_sub_should_return_2_when_given_4_2()
{
	assert("2" == sub("4", "2"));
	return TEST_PASSED;
}

int test_sub_should_return_0_when_given_8_8()
{
	assert("0" == sub("8", "8"));
	return TEST_PASSED;
}

int test_sub_should_return_8_when_given_16_8()
{
	assert("8" == sub("16", "8"));
	return TEST_PASSED;
}

int test_sub_should_return_100_when_given_101_1()
{
	assert("100" == sub("101", "1"));
	return TEST_PASSED;
}

int test_sub_should_return_999_when_given_1000_1()
{
	assert("999" == sub("1000", "1"));
	return TEST_PASSED;
}

int test_sub_should_return_1052851270917481491046580764152685_when_given_1318104130729672549682889244152684_265252859812191058636308479999999()
{
	assert("1052851270917481491046580764152685" == sub("1318104130729672549682889244152684", "265252859812191058636308479999999"));
	return TEST_PASSED;
}

int test_sub_should_return_0_when_given_111_111()
{
	assert("0" == sub("111", "111"));
	return TEST_PASSED;
}

int test_mult_should_return_4_when_given_2_2() {
	assert("4" == mult("2", "2"));
	return TEST_PASSED;
}

int test_mult_should_return_32_when_given_2_16() {
	assert("32" == mult("2", "16"));
	return TEST_PASSED;
}

int test_mult_should_return_144_when_given_12_12()
{
	assert("144" == mult("12", "12"));
	return TEST_PASSED;
}

int test_div_should_return_2_0_when_given_4_2()
{
	assert("2" == div("4", "2").quotient);
	return TEST_PASSED;
}

int test_div_should_return_2_0_when_given_16_8()
{
	assert("2" == div("16", "8").quotient);
	return TEST_PASSED;
}

int test_div_should_return_101_0_when_given_202_2()
{
	assert("101" == div("202", "2").quotient);
	return TEST_PASSED;
}

int test_div_should_return_16_10_when_given_289_18()
{
	assert("16" == div("289", "18").quotient);
	return TEST_PASSED;
}

int test_div_should_return_0_0_when_given_0_2()
{
	assert("0" == div("0", "2").quotient);
	return TEST_PASSED;
}

int test_exponentiationBig_should_return_0_when_given_12_6_36() {
	assert("0" == exponentiationBig("12", "6", "36"));
	return TEST_PASSED;
}

int test_exponentiationBig_should_return_17_when_given_17_5_18()
{
	assert("17" == exponentiationBig("17", "5", "18"));
	return TEST_PASSED;
}

int test_exponentiationBig_should_return_6_when_given_11_11_13()
{
	assert("6" == exponentiationBig("11", "11", "13"));
	return TEST_PASSED;
}

int test_exponentiationBig_should_return_1_when_given_5_0_7()
{
	assert("1" == exponentiationBig("5", "0", "7"));
	return TEST_PASSED;
}

int test_sqrtBig_should_return_2_when_given_4()
{
	assert("2" == sqrtBig("4"));
	return TEST_PASSED;
}

int test_sqrtBig_should_return_6_when_given_36()
{
	assert("6" == sqrtBig("36"));
	return TEST_PASSED;
}

int test_sqrtBig_should_return_12_when_given_144()
{
	assert("12" == sqrtBig("144"));
	return TEST_PASSED;
}

int test_sqrtBig_should_return_60_when_given_3600()
{
	assert("60" == sqrtBig("3600"));
	return TEST_PASSED;
}

int test_discretLogarithm_should_return_2_when_given_5_4_7()
{
	assert("2" == discretLogarithm("5", "4", "7"));
	return TEST_PASSED;
}
