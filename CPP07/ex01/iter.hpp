#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename Function>
void	iter(T *arr, std::size_t const size, Function func)
{
	for (std::size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
