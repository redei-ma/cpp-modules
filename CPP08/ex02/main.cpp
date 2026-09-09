#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::string(60, '=') << std::endl;

	std::list<int> ls;

	ls.push_back(5);
	ls.push_back(17);

	std::cout << ls.back() << std::endl;

	ls.pop_back();

	std::cout << ls.size() << std::endl;

	ls.push_back(3);
	ls.push_back(5);
	ls.push_back(737);
	ls.push_back(0);

	std::list<int>::iterator itLis = ls.begin();
	std::list<int>::iterator iteLis = ls.end();

	++itLis;
	--itLis;
	while (itLis != iteLis)
	{
		std::cout << *itLis << std::endl;
		++itLis;
	}

	std::cout << std::string(60, '=') << std::endl;

	std::cout << "Before: ";
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After: ";
	std::cout << mstack.top() << std::endl;

	return 0;
}
