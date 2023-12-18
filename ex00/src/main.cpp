#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


# define RED "\x1b[1m\x1b[38;2;255;0;0m"
# define MB "\x1b[1m\x1b[38;2;25;25;599m"
# define GREEN "\x1b[1m\x1b[38;2;0;128;0m"
# define YELLOW "\x1b[1m\x1b[38;2;205;205;0m"
# define DV "\x1b[1m\x1b[38;2;148;0;211m"
# define C "\x1b[0m"

int main(void) {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
		v.push_back(i);
	}

	std::cout << MB "Vector: " DV;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << MB "List: " DV;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << MB "Deque: " DV;
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << MB "Searching for 5 in vector: ";
	std::vector<int>::iterator it = easyfind(v, 5);
	if (it != v.end())
		std::cout << GREEN "Found " << *it << std::endl;
	else
		std::cout << RED "Not found" << std::endl;

	std::cout << MB "Searching for 5 in list: ";
	std::list<int>::iterator it2 = easyfind(l, 5);
	if (it2 != l.end())
		std::cout << GREEN "Found " << *it2 << std::endl;
	else
		std::cout << RED "Not found" << std::endl;

	std::cout << MB "Searching for 5 in deque: ";
	std::deque<int>::iterator it3 = easyfind(d, 5);
	if (it3 != d.end())
		std::cout << GREEN "Found " << *it3 << std::endl;
	else
		std::cout << RED "Not found" << std::endl;

	std::cout << MB "Searching for 19 in vector: ";
	it = easyfind(v, 19);
	if (it != v.end())
		std::cout << GREEN "Found " << *it << std::endl;
	else
		std::cout << RED "Not found" << std::endl;

	std::cout << MB "Searching for 19 in list: ";
	it2 = easyfind(l, 19);
	if (it2 != l.end())
		std::cout << GREEN "Found " << *it2 << std::endl;
	else
		std::cout << RED "Not found" << std::endl;
	
	std::cout << MB "Searching for 19 in deque: ";
	it3 = easyfind(d, 19);
	if (it3 != d.end())
		std::cout << GREEN "Found " << *it3 << std::endl;
	else
		std::cout << RED "Not found" << std::endl;	
}