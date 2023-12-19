#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T> {
	public:
		class iterator {
			private:
				typename std::stack<T>::container_type::iterator _it;
			public:
				iterator(typename std::stack<T>::container_type::iterator it);
				iterator(const iterator &src);
				iterator &operator=(const iterator &src);
				~iterator();

				iterator &operator++();
				iterator &operator--();
				iterator operator++(int);
				iterator operator--(int);
				bool operator==(const iterator &other) const;
				bool operator!=(const iterator &other) const;
				T &operator*();
		};

		iterator begin();
		iterator end();
};

# include "./MutantStack.tpp"

#endif