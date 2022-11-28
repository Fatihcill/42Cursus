#pragma once
#include "iostream"
#include "vector"
#include "array"
#include <exception>
#include <algorithm>
#include <iomanip>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define NORM "\x1B[0m"

class Span{
	private:
		unsigned int N;
		std::vector<int> myVector;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		~Span();

		Span const &operator=(const Span &obj);
	
		void	addNumber(int number);
		template <typename Iter>
		void	addNumber(Iter start, Iter end){
			if (this->myVector.size() >= N)
				throw Span::FullSpanException();
			this->myVector.insert(this->myVector.begin(), start, end);
		}

		int longestSpan();
		int shortestSpan();

		class FullSpanException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("Span is Full!!");
				}
		};
		class EmptySpanException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("No span can be found!!");
				}
		};
};