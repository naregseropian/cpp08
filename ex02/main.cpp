#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    // Testing with MutantStack
    std::cout << "Testing MutantStack:" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // Additional elements
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack); // Copying MutantStack to std::stack

    // Testing with std::list for comparison
    std::cout << "\nTesting std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Last element: " << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "List size after pop_back: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    // Additional elements
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    std::cout << "Iterating through std::list:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
