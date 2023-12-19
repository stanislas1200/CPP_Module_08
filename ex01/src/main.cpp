#include "../include/Span.hpp"

# define RED "\x1b[1m\x1b[38;2;255;0;0m"
# define MB "\x1b[1m\x1b[38;2;25;25;599m"
# define GREEN "\x1b[1m\x1b[38;2;0;128;0m"
# define YELLOW "\x1b[1m\x1b[38;2;205;205;0m"
# define DV "\x1b[1m\x1b[38;2;148;0;211m"
# define C "\x1b[0m"

int main()
{
	// PDF
	std::cout << DV "PDF tests:" C << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// My tests
	std::cout << DV "My tests:" C << std::endl;
	std::cout << YELLOW "FullException: ";
	try {
		sp.addNumber(1);
	}
	catch (std::exception &e) {
		std::cout << RED "Error: " YELLOW << e.what() << C << std::endl;
	}

	std::cout << YELLOW "NoSpanException: " C;
	try {
		Span sp1 = Span(1);
		sp1.addNumber(1);
		sp1.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << RED "Error: " YELLOW << e.what() << C << std::endl;
	}
	std::cout << YELLOW "Range test: " C << std::endl;
	Span sp2 = Span(100000);
	int arrayToAdd[] = {0, 22, 33, 44, 55, 66, 77, 88, 99};
	
	sp2.addRange(arrayToAdd, arrayToAdd + sizeof(arrayToAdd) / sizeof(arrayToAdd[0]));
	std::cout << MB "-Shortest Span: " GREEN << sp2.shortestSpan() << std::endl;
	std::cout << MB "-Longest Span: " GREEN << sp2.longestSpan() << std::endl;

	std::vector<int> vecToAdd;
	for (int i = 0; i <= 90000; i++)
		vecToAdd.push_back(i);
	sp2.addRange(vecToAdd.begin(), vecToAdd.end());
	std::cout << MB "-Shortest Span: " GREEN << sp2.shortestSpan() << std::endl;
	std::cout << MB "-Longest Span: " GREEN << sp2.longestSpan() << std::endl;
	
	std::cout << YELLOW "Copy operator: sp3 = sp2 " C << std::endl;
	Span sp3 = sp2;
	std::cout << MB "-Shortest Span: " GREEN << sp3.shortestSpan() << std::endl;
	std::cout << MB "-Longest Span: " GREEN << sp3.longestSpan() << std::endl;

	std::cout << YELLOW "Copy constructor: Span sp4(sp3) " C << std::endl;
	Span sp4(sp3);
	std::cout << MB "-Shortest Span: " GREEN << sp4.shortestSpan() << std::endl;
	std::cout << MB "-Longest Span: " GREEN << sp4.longestSpan() << C << std::endl;
	
	return 0;
}
