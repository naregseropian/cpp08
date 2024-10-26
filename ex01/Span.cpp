#include "Span.hpp"
#include <iostream>

// Constructors
Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}

// Destructor
Span::~Span() {}

// Assignment operator
Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs) {
        _data = rhs._data;
        _maxSize = rhs._maxSize;
    }
    return *this;
}

// Member functions
void Span::addNumber(int data)
{
    if (_data.size() >= _maxSize)
        throw SpanFullException();
    _data.push_back(data);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw NoSpanFoundException();

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw NoSpanFoundException();

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}

// Exception messages
const char* Span::SpanFullException::what() const throw() {
    return "Span is full. Cannot add more numbers.";
}

const char* Span::NoSpanFoundException::what() const throw() {
    return "No span can be found (need at least two numbers).";
}
