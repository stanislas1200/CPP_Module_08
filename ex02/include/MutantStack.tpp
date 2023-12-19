#include "../include/MutantStack.hpp"

template <class T>
MutantStack<T>::iterator::iterator(typename std::stack<T>::container_type::iterator it) : _it(it) {}

template <class T>
MutantStack<T>::iterator::iterator(const iterator &src) : _it(src._it) {}

template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const iterator &src) {
	if (this != &src)
		_it = src._it;
	return *this;
}

template <class T>
MutantStack<T>::iterator::~iterator() {}

template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++() {
	_it++;
	return *this;
}

template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--() {
	_it--;
	return *this;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int) {
	iterator tmp(*this);
	operator++();
	return tmp;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int) {
	iterator tmp(*this);
	operator--();
	return tmp;
}

template <class T>
bool MutantStack<T>::iterator::operator==(const iterator &other) const {
	return _it == other._it;
}

template <class T>
bool MutantStack<T>::iterator::operator!=(const iterator &other) const {
	return _it != other._it;
}

template <class T>
T &MutantStack<T>::iterator::operator*() {
	return *_it;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return iterator(std::stack<T>::c.begin());
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return iterator(std::stack<T>::c.end());
}

