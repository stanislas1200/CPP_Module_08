#include "../include/MutantStack.hpp"
#include <list>

# define RED "\x1b[1m\x1b[38;2;255;0;0m"
# define MB "\x1b[1m\x1b[38;2;25;25;599m"
# define GREEN "\x1b[1m\x1b[38;2;0;128;0m"
# define YELLOW "\x1b[1m\x1b[38;2;205;205;0m"
# define DV "\x1b[1m\x1b[38;2;148;0;211m"
# define C "\x1b[0m"

int main()
{
	std::cout << YELLOW << "MutantStack: " << C << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << MB "Top:   " GREEN << mstack.top() << std::endl;
	mstack.pop();
	std::cout << MB "Size:  " GREEN << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << MB "Value: " GREEN << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << MB "Top:  " GREEN << mstack.top() << MB " Copy: " GREEN << s.top() << std::endl;
	std::cout << MB "Size: " GREEN << mstack.size() << MB " Copy: " GREEN << s.size() << std::endl;
	std::stack<int> s3 = mstack;
	std::cout << MB "Top:  " GREEN << mstack.top() << MB " Copy: " GREEN << s3.top() << std::endl;
	std::cout << MB "Size: " GREEN << mstack.size() << MB " Copy: " GREEN << s3.size() << std::endl;

	std::cout << DV "---------------------" << std::endl;
	std::cout << YELLOW << "List: " << C << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << MB "Top:   " GREEN << lst.back() << std::endl;
	lst.pop_back();
	std::cout << MB "Size:  " GREEN << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
	std::cout << MB "Value: " GREEN << *it2 << std::endl;
	++it2;
	}
	std::list<int> l2(lst);
	std::cout << MB "Top:  " GREEN << lst.back() << MB " Copy: " GREEN << l2.back() << std::endl;
	std::cout << MB "Size: " GREEN << lst.size() << MB " Copy: " GREEN << l2.size() << std::endl;
	std::list<int> l3 = lst;
	std::cout << MB "Top:  " GREEN << lst.back() << MB " Copy: " GREEN << l3.back() << std::endl;
	std::cout << MB "Size: " GREEN << lst.size() << MB " Copy: " GREEN << l3.size() << std::endl;
	return 0;
}