#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	static_cast<void>(other);
}
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &other)
{
	static_cast<void>(other);
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string const &input)
{
	Result	res = {0, 0, 0, 0, false, false, false, false, false};

	switch (findType(input)) {
		case (CHAR): {
			res.c = (input.size() == 1) ? input[0] : input[1];
			res.i = static_cast<int>(res.c);
			res.f = static_cast<float>(res.c);
			res.d = static_cast<double>(res.c);
			printResult(res);
			break;
		}
		case (INT): {
			if (!convertTo<int>(input, res.i, res.int_imp))
				handleFailure(res, INT, input);
			else {
				res.c = convertToChar(input, res.c, res.char_imp, res.char_nondisp);
				res.f = static_cast<float>(res.i);
				res.d = static_cast<double>(res.i);
			}
			printResult(res);
			break;
		}
		case (FLOAT): {
			std::string	number = input;
			number.erase(number.size() - 1);
			if (!convertTo<float>(number, res.f, res.float_imp))
				handleFailure(res, FLOAT, number);
			else {
				res.c = convertToChar(input, res.c, res.char_imp, res.char_nondisp);
				if (res.f >  std::numeric_limits<int>::max() || res.f < std::numeric_limits<int>::min())
					res.int_imp = true;
				else
					res.i = static_cast<int>(res.f);
				res.d = static_cast<double>(res.f);
			}
			printResult(res);
			break;
		}
		case (DOUBLE): {
			if (!convertTo<double>(input, res.d, res.double_imp))
				handleFailure(res, DOUBLE, input);
			else {
				res.c = convertToChar(input, res.c, res.char_imp, res.char_nondisp);
				if (res.d > std::numeric_limits<int>::max() || res.d < std::numeric_limits<int>::min())
					res.int_imp = true;
				else
					res.i = static_cast<int>(res.d);
				if (res.d > std::numeric_limits<float>::max() || res.d < -std::numeric_limits<float>::max())
					res.float_imp = true;
				else
					res.f = static_cast<float>(res.d);
			}
			printResult(res);
			break;
		}
		case (SPECIAL): {
			if (input == "+inf" || input == "+inff")
				printSpecial("+inff", "+inf");
			else if (input == "-inf" || input == "-inff")
				printSpecial("-inff", "-inf");
			else
				printSpecial("nanf", "nan");
			break;
		}
		case (INVALID):
			std::cerr << "Error: not a valid literal" << std::endl;
	}
}

//---------------------------------------------------------------------

static bool	isFound(std::string const &str, char c)
{
	std::string::size_type	pos;

	pos = str.find(c);
	if (pos == std::string::npos)
		return (false);
	return (true);
}

static bool	isNumber(std::string const &number)
{
	char	*endptr;

	std::strtod(number.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	return (true);
}

static bool	isValidNumber(std::string const &input)
{
	std::string number = input;

	if (number[number.size() - 1] == 'f')
		number.erase(number.size() - 1);
	return (isNumber(number));
}

static bool	isSpecial(std::string const &input)
{
	if (input == "nan" || input == "nanf"
		|| input == "+inf" || input == "+inff"
		|| input == "-inf" || input == "-inff")
		return (true);
	return (false);
}

e_type	findType(const std::string &input)
{
	if (input.empty())
		return (INVALID);
	else if (isSpecial(input))
		return (SPECIAL);
	else if ((input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) ||
				(input.size() == 3 && std::isprint(input[1]) && input[0] == '\'' && input[2] == '\''))
		return (CHAR);
	else if (isValidNumber(input)) {
		if (isFound(input, 'f'))
			return (FLOAT);
		else if (isFound(input, '.'))
			return (DOUBLE);
		else
			return (INT);
	}
	return (INVALID);
}
template<typename T>
bool	convertTo(std::string const &input, T &result, bool &imp)
{
	std::stringstream	ss(input);

	ss >> result;
	if (ss.fail()) {
		imp = true;
		return (false);
	}
	imp = false;
	return (true);
}

char&	convertToChar(std::string const &input, char &result, bool &imp, bool &nondisp)
{
	std::string number = input;
	int			tmp;

	convertTo<int>(number, tmp, imp);
	if (tmp < 0 || tmp > 127)
		imp = true;
	if (!std::isprint(static_cast<char>(tmp)))
		nondisp = true;
	return (result = static_cast<char>(tmp));
}

void	handleFailure(Result& res, e_type failed_type, const std::string& input)
{
	res.c = convertToChar(input, res.c, res.char_imp, res.char_nondisp);
	if (failed_type != INT)
		convertTo<int>(input, res.i, res.int_imp);
	if (failed_type != FLOAT)
		convertTo<float>(input, res.f, res.float_imp);
	if (failed_type != DOUBLE)
		convertTo<double>(input, res.d, res.double_imp);
}

template<typename T>
static void	printType(const std::string& typeName, T value, bool imp, const std::string& suffix = "")
{
	std::cout << typeName << ": ";
	if (!imp)
		std::cout << value << suffix;
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	printResult(Result const &res)
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);

	if (res.char_imp)
		std::cout << "char: impossible" << std::endl;
	else if (res.char_nondisp)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << res.c << "'" << std::endl;

	printType("int", res.i, res.int_imp);
	printType("float", res.f, res.float_imp, "f");
	printType("double", res.d, res.double_imp);

	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

void	printSpecial(std::string const &f, std::string const &d)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}
