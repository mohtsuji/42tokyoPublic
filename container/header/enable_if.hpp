#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"
#include "VectorIterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

//あとでtemplateの本を読む
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

};


#endif
