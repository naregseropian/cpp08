#include <iostream>
#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    // Test with provided code
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }

    // Test with 10000 numbers
    {
        Span sp(10000);
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i)
            v.push_back(rand());
        sp.addManyNumbers(v.begin(), v.end());
        std::cout << "Shortest Span (10000 numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span (10000 numbers): " << sp.longestSpan() << std::endl;
    }

    // Test exception when adding more numbers than capacity
    {
        try {
            Span sp(3);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4); // Should throw exception
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    // Test exception when finding spans with insufficient numbers
    {
        try {
            Span sp(5);
            sp.addNumber(5);
            std::cout << "Attempting to find spans with only one number..." << std::endl;
            sp.shortestSpan();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}
