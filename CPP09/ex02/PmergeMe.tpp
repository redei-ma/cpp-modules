#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <stdexcept>
# include <algorithm>
# include <utility>
# include <ctime>

template<typename Container>
const unsigned int PmergeMe<Container>::jacob[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};

template <typename Container>
PmergeMe<Container>::PmergeMe(const int *numbers, const int &size): sequence(numbers, numbers + size), execTime(0.0) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
Container	PmergeMe<Container>::getContainer()	const
{
	return (sequence);
}

template <typename Container>
double	PmergeMe<Container>::getExecTime()	const
{
	return (execTime);
}

// kept as a reference: it builds the Jacobsthal sequence up to n instead of reading it
// from the jacob[] table above, which is precomputed because the insertion order never
// needs more than 31 terms
/* static std::vector<unsigned int> getJacobsthalSequence(unsigned int n)
{
	std::vector<unsigned int> jacobsthal;
	if (n == 0) {
		return jacobsthal;
	}

	jacobsthal.push_back(1);
	if (n == 1) {
		return jacobsthal;
	}

	unsigned int a = 1;
	unsigned int b = 1;
	while (b < n) {
		unsigned int next = b + 2 * a;
		if (next > n) {
			break;
		}
		jacobsthal.push_back(next);
		a = b;
		b = next;
	}

	return jacobsthal;
} */

template <typename Container>
typename Container::iterator PmergeMe<Container>::binarySearch(iterator begin, iterator end, int value)	const
{
	while (begin < end)
	{
		iterator mid = begin + std::distance(begin, end) /  2;

		if (*mid > value)
		{
			end = mid;
		}
		else if (*mid < value)
		{
			begin = mid + 1;
		}
	}
	return (begin);
}

template <typename Container>
void PmergeMe<Container>::insertBinary(Container pendant, std::pair<int, int> *pairs, int pairSize, int i, int extra)
{
	iterator	insertPos;

	if (pendant[i] == extra)
	{
		insertPos = binarySearch(sequence.begin(), sequence.end(), pendant[i]);
	}
	else
	{
		iterator	upperLimit = sequence.end();
		for (int j = 0; j < pairSize; j++)
		{
			if (pairs[j].first == pendant[i])
			{
				upperLimit = std::find(sequence.begin(), sequence.end(), pairs[j].second);
				break;
			}
		}
		insertPos = binarySearch(sequence.begin(), upperLimit, pendant[i]);
	}
	sequence.insert(insertPos, pendant[i]);
}

// std::clock is the C++98 way: CLOCKS_PER_SEC is 1000000 here, so the result is already microseconds
static double	getTime()
{
	std::clock_t	now = std::clock();

	if (now == static_cast<std::clock_t>(-1))
		throw std::runtime_error("Could not read the clock");
	return (static_cast<double>(now) * 1000000.0 / CLOCKS_PER_SEC);
}

template <typename Container>
void	PmergeMe<Container>::execFordJohnson()
{
	double startTime = getTime();
	Container	pendant;
	int	extra = -1;

	if (sequence.size() % 2)
	{
		extra = sequence.back();
		sequence.pop_back();
	}

	int	pairSize = sequence.size() / 2;
	int	idx = 0;
	std::pair<int, int> *pairs = new std::pair<int, int>[pairSize];
	for (unsigned int i = 0; i < sequence.size(); i += 2)
	{
		int	a = sequence[i];
		int	b = sequence[i + 1];

		if (a < b)
		{
			pairs[idx] = (std::make_pair(a, b));
		}
		else
		{
			pairs[idx] = (std::make_pair(b, a));
		}
		idx++;
	}

	sequence.clear();
	for (int i = 0; i < pairSize; i++)
	{
		sequence.push_back(pairs[i].second);
	}

	if (sequence.size() > 1)
	{
		execFordJohnson();
	}

	for (iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		for (int j = 0; j < pairSize; j++)
		{
			if (pairs[j].second == *it)
			{
				pendant.push_back(pairs[j].first);
				break;
			}
		}
	}
	if (extra != -1)
	{
		pendant.push_back(extra);
	}

	const unsigned int* itJacob = std::upper_bound(jacob, jacob + 31, pendant.size());
	int	maxJacob = (itJacob - jacob) - 1;

	sequence.insert(sequence.begin(), pendant[0]);
	for (int k = 1; k <= maxJacob; k++)
	{
		int	start = jacob[k] - 1;
		int	end = (jacob[k-1] - 1) + 1;
		for (int i = start; i >= end; i--)
		{
			insertBinary(pendant, pairs, pairSize, i, extra);
		}
	}
	for (unsigned int i = jacob[maxJacob]; i < pendant.size(); i++)
	{
		insertBinary(pendant, pairs, pairSize, i, extra);
	}
	delete[] pairs;

	execTime = getTime() - startTime;
}

#endif
