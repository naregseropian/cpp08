#include <list>
#include <vector>
#include "easyfind.hpp"

template<typename T>
void printContainer(const T& container)
{
    /* declare a read-only iterator and assign it to the start of the container */
	typename T::const_iterator it = container.begin();
    
	std::cout << "[ ";

	while (it != container.end())
    {
		std::cout << *it;
		++it;
		if (it != container.end())
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

int main()
{
    // Test with vector<int>
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value 5 in vector at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with list<int>
    std::list<int> lst;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i * 2);

    try {
        std::list<int>::iterator it = easyfind(lst, 6);
        std::cout << "Found value 6 in list at position: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with value not in container
    try {
        easyfind(vec, 42);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}