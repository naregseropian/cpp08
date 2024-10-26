#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <limits>

class Span
{
    public:
        Span(unsigned int _maxSize);
        Span(const Span &other);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int data);

        template <typename Iterator>
        void addManyNumbers(Iterator begin, Iterator end) {
            if (std::distance(begin, end) + _data.size() > _maxSize)
                throw SpanFullException();
            _data.insert(_data.end(), begin, end);
        }
        
        int shortestSpan() const;
        int longestSpan() const;

        // Exception classes
        class SpanFullException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        unsigned int _maxSize;
        std::vector<int> _data;
};

#endif