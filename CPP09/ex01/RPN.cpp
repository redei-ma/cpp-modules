#include "RPN.hpp"
#include <stdexcept>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <cerrno>

RPN::RPN() {}

RPN::RPN(const RPN &other) :operands(other.operands) {}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other) {
		operands = other.operands;
	}
	return (*this);
}

RPN::~RPN() {}

static void	parseStr(const std::string &str)
{
	unsigned long	strLen = str.length();
	for (unsigned long i = 0; i < strLen; i++) {
		if (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != ' ')
			throw std::invalid_argument("Invalid character");
	}
}

double	RPN::calculateRPN(const std::string &str)
{
	std::istringstream	ss(str);
	std::string			value;

	if (str.empty())
		throw std::logic_error("Empty input");
	parseStr(str);
	while (std::getline(ss, value, ' ')) {
		if (value.empty())
			continue ;
		else if (value.length() == 1 && value[0] == '+')
			calculate(ADD);
		else if (value.length() == 1 && value[0] == '-')
			calculate(SUB);
		else if (value.length() == 1 && value[0] == '*')
			calculate(MUL);
		else if (value.length() == 1 && value[0] == '/')
			calculate(DIV);
		else {
			char	*endptr;

			errno = 0;
			double	num = std::strtod(value.c_str(), &endptr);

			if (*endptr != '\0' || errno == ERANGE || num >= 10)
				throw std::invalid_argument("Invalid number");
			operands.push(num);
		}
	}

	if (operands.size() != 1)
		throw std::logic_error("Invalid operation");
	return (operands.top());
}

void	RPN::calculate(e_operator code)
{
	double	first;
	double	second;
	double	tmp;

	if (operands.size() < 2)
		throw std::logic_error("Invalid operation");
	second = operands.top();
	operands.pop();
	first = operands.top();
	operands.pop();
	switch (code) {
	case ADD:
		tmp = first + second;
		break;
	case SUB:
		tmp = first - second;
		break;
	case MUL:
		tmp = first * second;
		break;
	case DIV:
		if (second == 0)
			throw std::logic_error("Invalid division by zero");
		tmp = first / second;
		break;
	default:
		throw std::logic_error("Invalid operation");
	}
	operands.push(tmp);
}
