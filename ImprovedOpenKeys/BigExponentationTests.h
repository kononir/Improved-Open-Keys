#pragma once
#include "BigExponentation.h"
#include <cassert>
#include <iostream>

#define TEST_PASSED 0
#define TEST_NOT_PASSED 1

int runTests();

int test_sum_should_return_4_when_given_2_2();
int test_sum_should_return_16_when_given_2_14();
int test_sum_should_return_22_when_given_5_17();

int test_sub_should_return_2_when_given_4_2();
int test_sub_should_return_0_when_given_8_8();
int test_sub_should_return_8_when_given_16_8();
int test_sub_should_return_100_when_given_101_1();
int test_sub_should_return_999_when_given_1000_1();
int test_sub_should_return_109_when_given_301_192();

int test_mult_should_return_4_when_given_2_2();
int test_mult_should_return_32_when_given_2_16();
int test_mult_should_return_144_when_given_12_12();

int test_div_should_return_2_0_when_given_4_2();
int test_div_should_return_2_0_when_given_16_8();
int test_div_should_return_101_0_when_given_202_2();
int test_div_should_return_16_10_when_given_289_18();
int test_div_should_return_0_0_when_given_0_2();

int test_exponentiationBig_should_return_0_when_given_12_6_36();
int test_exponentiationBig_should_return_17_when_given_17_5_18();
int test_exponentiationBig_should_return_6_when_given_11_11_13();
int test_exponentiationBig_should_return_1_when_given_5_0_7();

int test_sqrtBig_should_return_2_when_given_4();
int test_sqrtBig_should_return_6_when_given_36();
int test_sqrtBig_should_return_12_when_given_144();
int test_sqrtBig_should_return_60_when_given_3600();

int test_discretLogarithm_should_return_2_when_given_5_4_7();

__declspec(selectany) int(*tests[])(void) = {
	test_sum_should_return_4_when_given_2_2,
	test_sum_should_return_16_when_given_2_14,
	test_sum_should_return_22_when_given_5_17,

	test_sub_should_return_2_when_given_4_2,
	test_sub_should_return_0_when_given_8_8,
	test_sub_should_return_8_when_given_16_8,
	test_sub_should_return_100_when_given_101_1,
	test_sub_should_return_999_when_given_1000_1,
	test_sub_should_return_109_when_given_301_192,

	test_mult_should_return_4_when_given_2_2,
	test_mult_should_return_32_when_given_2_16,
	test_mult_should_return_144_when_given_12_12,

	test_div_should_return_2_0_when_given_4_2,
	test_div_should_return_2_0_when_given_16_8,
	test_div_should_return_101_0_when_given_202_2,
	test_div_should_return_16_10_when_given_289_18,
	test_div_should_return_0_0_when_given_0_2,

	test_exponentiationBig_should_return_0_when_given_12_6_36,
	test_exponentiationBig_should_return_17_when_given_17_5_18,
	test_exponentiationBig_should_return_6_when_given_11_11_13,
	test_exponentiationBig_should_return_1_when_given_5_0_7,

	test_sqrtBig_should_return_2_when_given_4,
	test_sqrtBig_should_return_6_when_given_36,
	test_sqrtBig_should_return_12_when_given_144,
	test_sqrtBig_should_return_60_when_given_3600,

	test_discretLogarithm_should_return_2_when_given_5_4_7
};

__declspec(selectany) string names[] = {
	"test_sum_should_return_4_when_given_2_2",
	"test_sum_should_return_16_when_given_2_14",
	"test_sum_should_return_22_when_given_5_17",

	"test_sub_should_return_2_when_given_4_2",
	"test_sub_should_return_0_when_given_8_8",
	"test_sub_should_return_8_when_given_16_8",
	"test_sub_should_return_100_when_given_101_1",
	"test_sub_should_return_999_when_given_1000_1",
	"test_sub_should_return_109_when_given_301_192",

	"test_mult_should_return_4_when_given_2_2",
	"test_mult_should_return_32_when_given_2_16",
	"test_mult_should_return_144_when_given_12_12",

	"test_div_should_return_2_when_given_4_2",
	"test_div_should_return_2_when_given_16_8",
	"test_div_should_return_101_when_given_202_2",
	"test_div_should_return_16_when_given_289_18",
	"test_div_should_return_0_0_when_given_0_2",

	"test_exponentiationBig_should_return_0_when_given_12_6_36",
	"test_exponentiationBig_should_return_17_when_given_17_5_18",
	"test_exponentiationBig_should_return_6_when_given_11_11_13",
	"test_exponentiationBig_should_return_1_when_given_5_0_7",

	"test_sqrtBig_should_return_2_when_given_4",
	"test_sqrtBig_should_return_6_when_given_36",
	"test_sqrtBig_should_return_12_when_given_144",
	"test_sqrtBig_should_return_60_when_given_3600",

	"test_discretLogarithm_should_return_2_when_given_5_4_7"
};