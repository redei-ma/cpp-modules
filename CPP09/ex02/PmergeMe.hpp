#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <utility>

template <typename Container>
class	PmergeMe
{
	public:
		typedef typename Container::iterator iterator;

	private:
		Container	sequence;
		double		execTime;
		static const unsigned int	jacob[];
		void		insertBinary(Container pendant, std::pair<int, int> *pairs, int pairSize, int i, int extra);
		iterator	binarySearch(iterator, iterator, int)	const;

	public:
		PmergeMe(const int *, const int &);
		~PmergeMe();

		void		execFordJohnson();
		Container	getContainer()	const;
		double		getExecTime()	const;
};

# include "PmergeMe.tpp"

#endif
