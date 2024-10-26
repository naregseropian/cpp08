#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <typeinfo>
#include <stdexcept>
#include <limits>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    if (typeid(typename T::value_type) != typeid(int))
        throw std::runtime_error("Le conteneur doit contenir des valeurs de type int.");

    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        throw std::overflow_error("Value exceeds the limits of int");

    int intValue = static_cast<int>(value);
    typename T::iterator it = std::find(container.begin(), container.end(), intValue);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

#endif