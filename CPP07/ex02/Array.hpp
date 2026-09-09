#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class	Array
{
	private:
		T				*data;
		unsigned int	length;

	public:
		Array();
		Array(unsigned int initialSize);
		Array(const Array<T> &other);
		Array<T>	&operator=(const Array<T> &other);
		T	&operator[](unsigned int index);
		const T	&operator[](unsigned int index)	const;
		~Array();

		unsigned int	size()	const;
};

# include "Array.tpp"

#endif
