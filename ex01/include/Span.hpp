#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _vec;
	public:
		Span();
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);

		Span(unsigned int n);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			if (this->_vec.size() + std::distance(begin, end) > this->_n)
				throw Span::FullException();
			this->_vec.insert(this->_vec.end(), begin, end);
		};
		class FullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif