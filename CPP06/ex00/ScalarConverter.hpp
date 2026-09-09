#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cctype>

enum	e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	INVALID,
};

struct Result {
	char c;
	int i;
	float f;
	double d;
	bool char_imp;
	bool char_nondisp;
	bool int_imp;
	bool float_imp;
	bool double_imp;
};

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter&	operator=(ScalarConverter const &other);
		~ScalarConverter();

	public:
		static void	convert(std::string const &input);
};

e_type	findType(const std::string &input);
template<typename T>
bool	convertTo(std::string const &input, T &result, bool &imp);
char&	convertToChar(std::string const &input, char &result, bool &imp, bool &nondisp);
void	handleFailure(Result& res, e_type failed_type, const std::string& input);
void	printResult(Result const &res);
void	printSpecial(std::string const &f, std::string const &d);

#endif
