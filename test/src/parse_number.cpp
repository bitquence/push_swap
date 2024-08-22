#include <gtest/gtest.h>
#include <climits>

extern "C" {
#include "input.h"
};

static_assert(
	std::numeric_limits<int>::max() == std::numeric_limits<int32_t>::max(),
	"`parse_number` tests only hold for a 32 bit int"
);

TEST(WordIsValidNumberTest, EmptyWordIsInvalidNumber) {
	ASSERT_FALSE(word_is_valid_number(""));
}

TEST(WordIsValidNumberTest, SimpleSignIsInvalidNumber) {
	ASSERT_FALSE(word_is_valid_number("+"));
	ASSERT_FALSE(word_is_valid_number("-"));
}

TEST(WordIsValidNumberTest, ManySimpleSignsIsInvalidNumber) {
	ASSERT_FALSE(word_is_valid_number("+++"));
	ASSERT_FALSE(word_is_valid_number("---"));
}

TEST(WordIsValidNumberTest, ValidNumberWithManySignsIsInvalidNumber) {
	ASSERT_FALSE(word_is_valid_number("++42"));
	ASSERT_FALSE(word_is_valid_number("--42"));
}

TEST(WordIsValidNumberTest, ValidUnterminatedNumberIsInvalidNumber) {
	ASSERT_FALSE(word_is_valid_number("+4242v"));
	ASSERT_FALSE(word_is_valid_number("-4242v"));
}

TEST(WordIsValidNumberTest, ValidNumberBeginningWithSpacesIsValidNumber) {
	ASSERT_TRUE(word_is_valid_number(" 42"));
	ASSERT_TRUE(word_is_valid_number("    -42"));
}

TEST(WordIsValidNumberTest, ValidNumberWithLeadingZeroesIsValidNumber) {
	ASSERT_TRUE(word_is_valid_number("00042"));
	ASSERT_TRUE(word_is_valid_number("0042"));
	ASSERT_TRUE(word_is_valid_number("042"));
	ASSERT_TRUE(word_is_valid_number("+042"));
	ASSERT_TRUE(word_is_valid_number("-042"));
}

TEST(WordIsValidNumberTest, ValidNumberInRange) {
	ASSERT_TRUE(word_is_valid_number("0"));
	ASSERT_TRUE(word_is_valid_number("+0"));
	ASSERT_TRUE(word_is_valid_number("-0"));

	ASSERT_TRUE(word_is_valid_number("1"));
	ASSERT_TRUE(word_is_valid_number("+1"));
	ASSERT_TRUE(word_is_valid_number("-1"));

	ASSERT_TRUE(word_is_valid_number("42"));
	ASSERT_TRUE(word_is_valid_number("+42"));
	ASSERT_TRUE(word_is_valid_number("-42"));

	ASSERT_TRUE(word_is_valid_number("42"));
	ASSERT_TRUE(word_is_valid_number("+42"));
	ASSERT_TRUE(word_is_valid_number("-42"));

	// whether this number is in range or not is platform dependant!
	ASSERT_TRUE(word_is_valid_number("2147483647"));
	ASSERT_TRUE(word_is_valid_number("+2147483647"));
	ASSERT_TRUE(word_is_valid_number("-2147483648"));
}

TEST(WordIsValidNumberTest, ValidNumberOutOfRange) {
	// whether this number is in range or not is platform dependant!
	ASSERT_TRUE(word_is_valid_number("2147483648"));
	ASSERT_TRUE(word_is_valid_number("+2147483648"));
	ASSERT_TRUE(word_is_valid_number("-2147483649"));
}

#define ASSERT_PARSES_NUMBER(ascii_number, expected)					\
	do {																\
		int	numeric_result;												\
		int	return_value;												\
																		\
		return_value = parse_number((ascii_number), &numeric_result);	\
		ASSERT_EQ(return_value, 0);										\
		ASSERT_EQ(numeric_result, expected);							\
	} while (0)

#define ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER(ascii_number, expected_return) \
	do {																\
		int	numeric_result;												\
		int	return_value;												\
																		\
		return_value = parse_number((ascii_number), &numeric_result);	\
		ASSERT_EQ(return_value, expected_return);						\
	} while (0)

TEST(ParseNumberTest, ValidPositiveNumber) {
	ASSERT_PARSES_NUMBER("1", 1);
	ASSERT_PARSES_NUMBER("42", 42);
	ASSERT_PARSES_NUMBER("2147483646", 2147483646);
}

TEST(ParseNumberTest, ValidNegativeNumber) {
	ASSERT_PARSES_NUMBER("-1", -1);
	ASSERT_PARSES_NUMBER("-42", -42);
	ASSERT_PARSES_NUMBER("-2147483647", -2147483647);
}

TEST(ParseNumberTest, ValidNumberPrecededByPositiveSign) {
	ASSERT_PARSES_NUMBER("+1", 1);
	ASSERT_PARSES_NUMBER("+42", 42);
}

TEST(ParseNumberTest, NegativeAndPositiveZero) {
	ASSERT_PARSES_NUMBER("0", 0);
	ASSERT_PARSES_NUMBER("+0", 0);
	ASSERT_PARSES_NUMBER("-0", 0);
}

// the following tests are not platform independant!

TEST(ParseNumberTest, MaximumIntegerValueIsCorrectlyParsed) {
	ASSERT_PARSES_NUMBER("2147483647", INT_MAX);
}

TEST(ParseNumberTest, MinimumIntegerValueIsCorrectlyParsed) {
	ASSERT_PARSES_NUMBER("-2147483648", INT_MIN);
}

TEST(ParseNumberTest, OverflowingNumber) {
	ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER("2147483648", 1);
	ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER("4294967295", 1);
	ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER("9223372036854775807", 1);
}

TEST(ParseNumberTest, UnderflowingNumber) {
	ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER("-2147483649", -1);
	ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER("-4294967295", -1);
	ASSERT_DOES_NOT_PARSE_OUT_OF_RANGE_NUMBER("-9223372036854775807", -1);
}
