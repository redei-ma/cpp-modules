#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"
# include <stdexcept>

template <class T>
Array<T>::Array() :data(NULL), length(0) {}

template <class T>
Array<T>::Array(unsigned int initialSize) :data(new T[initialSize]()), length(initialSize) {}

template <class T>
Array<T>::Array(const Array<T> &other)
{
	length = other.length;
	data = new T[length];
	for (unsigned int i = 0; i < length; i++)
		data[i] = other.data[i];
}

template <class T>
Array<T>	&Array<T>::operator=(const Array<T> &other)
{
	if (this != &other) {
		delete[] data;
		length = other.length;
		data = new T[length];
		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}
	return (*this);
}

template <class T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= length)
		throw std::out_of_range("Error: index out of range");
	return (data[index]);
}

template <class T>
const T	&Array<T>::operator[](unsigned int index)	const
{
	if (index >= length)
		throw std::out_of_range("Error: index out of range");
	return (data[index]);
}

template <class T>
Array<T>::~Array()
{
	delete[] data;
}

template <class T>
unsigned int	Array<T>::size()	const
{
	return (length);
}

#endif
