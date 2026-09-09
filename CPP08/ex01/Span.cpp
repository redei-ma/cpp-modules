#include "Span.hpp"
#include <climits>

Span::Span() :maxSize(0) {}

Span::Span(unsigned int size) :maxSize(size)
{
	storage.reserve(size);
}

Span::Span(const Span &other) :storage(other.storage), maxSize(other.maxSize) {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other) {
		storage = other.storage;
		maxSize = other.maxSize;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(const int number)
{
	if (storage.size() >= maxSize)
		throw std::length_error("Storage is full");
	storage.push_back(number);
}

// the gap between two ints can reach UINT_MAX, so it is computed unsigned
unsigned int	Span::shortestSpan()	const
{
	if (storage.size() < 2)
		throw std::runtime_error("Too few numbers stored");

	unsigned int		range = UINT_MAX;
	std::vector<int>	sorted(storage);

	std::sort(sorted.begin(), sorted.end());
	for (unsigned int i = 0; i < sorted.size() - 1; i++) {
		unsigned int	gap = static_cast<unsigned int>(sorted[i + 1]) - static_cast<unsigned int>(sorted[i]);
		if (gap < range)
			range = gap;
	}
	return (range);
}

unsigned int	Span::longestSpan()	const
{
	if (storage.size() < 2)
		throw std::runtime_error("Too few numbers stored");

	int	min = *std::min_element(storage.begin(), storage.end());
	int	max = *std::max_element(storage.begin(), storage.end());

	return (static_cast<unsigned int>(max) - static_cast<unsigned int>(min));
}
