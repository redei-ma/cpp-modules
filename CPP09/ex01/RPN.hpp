#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

enum	e_operator
{
	ADD,
	SUB,
	MUL,
	DIV
};

class	RPN
{
	private:
		std::stack<double>	operands;
		void	calculate(e_operator code);

	public:
		RPN();
		RPN(const RPN &);
		RPN	&operator=(const RPN &);
		~RPN();
		double	calculateRPN(const std::string &);
};

#endif
