#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

template <typename It>
void	Span::addRange(const It begin, const It end)
{
	if (storage.size() + std::distance(begin, end) > maxSize)
		throw std::length_error("Not enough storage");
	storage.insert(storage.end(), begin, end);
}
#endif
