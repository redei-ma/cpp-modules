#include "ScalarConverter.hpp"

void testCase(const std::string& input, const std::string& description)
{
	std::cout << "\n" << std::string(60, '=') << std::endl;
	std::cout << "Testing: " << description << std::endl;
	std::cout << "Input: \"" << input << "\"" << std::endl;
	std::cout << std::string(60, '-') << std::endl;
	ScalarConverter::convert(input);
}

void myTest()
{
	std::cout << "SCALAR CONVERTER TEST SUITE" << std::endl;
	std::cout << std::string(60, '=') << std::endl;

	// CHAR TESTS
	std::cout << "\n*** CHAR TYPE TESTS ***" << std::endl;
	testCase("a", "Single printable character");
	testCase("Z", "Single uppercase character");
	testCase("5", "Single digit character");
	testCase("'c'", "Character with quotes");
	testCase("'@'", "Special character with quotes");
	testCase("0", "ASCII 0 (null character)");
	testCase("31", "ASCII 31 (unit separator - non-displayable)");
	testCase("127", "ASCII 127 (DEL character - non-displayable)");
	testCase("128", "ASCII 128 (out of range for char)");
	testCase("-1", "Negative number (impossible for char)");

	// INT TESTS
	std::cout << "\n*** INT TYPE TESTS ***" << std::endl;
	testCase("42", "Positive integer");
	testCase("-42", "Negative integer");
	testCase("0", "Zero integer");
	testCase("2147483647", "INT_MAX");
	testCase("-2147483648", "INT_MIN");
	testCase("2147483648", "INT_MAX + 1 (overflow)");
	testCase("-2147483649", "INT_MIN - 1 (underflow)");

	// FLOAT TESTS
	std::cout << "\n*** FLOAT TYPE TESTS ***" << std::endl;
	testCase("42.0f", "Simple float");
	testCase("-42.5f", "Negative float");
	testCase("0.0f", "Zero float");
	testCase("3.14159f", "Pi as float");
	testCase("340282346638528859811704183484516925440.0f", "Close to FLT_MAX");
	testCase("999999999999999939709166371603178586112f", "Very large float");
	testCase("-999999999999999939709166371603178586112.0f", "Very large negative float");

	// DOUBLE TESTS
	std::cout << "\n*** DOUBLE TYPE TESTS ***" << std::endl;
	testCase("42.0", "Simple double");
	testCase("-42.5", "Negative double");
	testCase("0.0", "Zero double");
	testCase("3.14159265359", "Pi with more precision");
	testCase("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", "Close to DBL_MAX");
	testCase("1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0", "Too large for double");

	// SPECIAL TESTS
	std::cout << "\n*** SPECIAL TYPE TESTS ***" << std::endl;
	testCase("+inf", "Positive infinity (double)");
	testCase("-inf", "Negative infinity (double)");
	testCase("nan", "Not a number (double)");
	testCase("+inff", "Positive infinity (float)");
	testCase("-inff", "Negative infinity (float)");
	testCase("nanf", "Not a number (float)");

	// INVALID TESTS
	std::cout << "\n*** INVALID TYPE TESTS ***" << std::endl;
	testCase("", "Empty string");
	testCase("abc", "Invalid string");
	testCase("42.5.3", "Multiple decimal points");
	testCase("42f5", "Invalid float format");
	testCase("++42", "Multiple plus signs");
	testCase("--42", "Multiple minus signs");
	testCase("42.f.5", "Invalid decimal format");
	testCase("hello world", "Text with spaces");
	testCase("'ab'", "Multiple characters in quotes");

	// EDGE CASES FOR OVERFLOW TESTING
	std::cout << "\n*** OVERFLOW EDGE CASES ***" << std::endl;
	testCase("2147483647.0", "INT_MAX as double (should work for int)");
	testCase("2147483648.0", "INT_MAX + 1 as double (impossible for int)");

	std::cout << "\n" << std::string(60, '=') << std::endl;
	std::cout << "TEST SUITE COMPLETED" << std::endl;
	std::cout << std::string(60, '=') << std::endl;
}

int main(int ac, char **av)
{
	if (ac == 1)
		myTest();
	else if (ac == 2)
		ScalarConverter::convert(av[1]);
	else {
		std::cerr << "Error: usage: ./convert [literal], or no argument for the test suite" << std::endl;
		return 1;
	}
	return 0;
}
