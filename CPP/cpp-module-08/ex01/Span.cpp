#include "Span.hpp"

Span::Span(){
	this->N = 0;
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span::~Span(){
}

Span const	&Span::operator=(const Span &obj){
	this->N = obj.N;
	this->myVector = obj.myVector;
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->myVector.size() >= this->N)
		throw Span::FullSpanException();
	this->myVector.push_back(number);
}

int	Span::longestSpan()
{
	if (this->myVector.size() < 2)
		throw Span::EmptySpanException();
	typedef std::vector<int>::iterator iter;
	iter max = std::max_element(this->myVector.begin(), this->myVector.end());
	iter min = std::min_element(this->myVector.begin(), this->myVector.end());
	return (abs(*max - *min));
}

int Span::shortestSpan()
{
	if (this->myVector.size() < 2)
		throw Span::EmptySpanException();
	typedef std::vector<int>::iterator iter;
	iter idx = this->myVector.begin();
	iter idx2 = this->myVector.begin() + 1;
	int min = std::abs(*idx - *idx2);
	for (;idx != this->myVector.end(); idx++)
	{
		for (idx2 = idx + 1; idx2 != this->myVector.end(); idx2++)
		{
			int temp = std::abs(*idx - *idx2);
			if (temp < min)
				min = temp;
		}
	}
	return (min);
}