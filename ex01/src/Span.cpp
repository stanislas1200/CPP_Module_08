#include "../include/Span.hpp"

Span::Span() : _n(0) {}

Span::Span(const Span &copy) : _n(copy._n), _vec(copy._vec) {}

Span::~Span() {}

Span &Span::operator=(const Span &copy) {
	if (this != &copy)
	{
		this->_n = copy._n;
		this->_vec = copy._vec;
	}
	return (*this);
}

Span::Span(unsigned int n) : _n(n) {}

void Span::addNumber(int n) {
	if (this->_vec.size() == this->_n)
		throw Span::FullException();
	this->_vec.push_back(n);
}

int Span::shortestSpan() {
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();

	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return (min);
}

int Span::longestSpan() {
	if (this->_vec.size() <= 1)
		throw Span::NoSpanException();

	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

const char *Span::FullException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Span has no span";
}