#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class	Span
{
	private:
		std::vector<int>	storage;
		unsigned int		maxSize;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();
		void	addNumber(const int number);
		unsigned int	shortestSpan()	const;
		unsigned int	longestSpan()	const;
		template <typename It>
		void	addRange(const It begin, const It end);
};

# include "Span.tpp"

#endif
