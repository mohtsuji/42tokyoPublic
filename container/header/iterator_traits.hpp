#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {

template < class Iter >
struct iterator_traits {

	typedef typename Iter::value_type			value_type;
	typedef typename Iter::difference_type		difference_type;//iterator間の距離を示す
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::iterator_category	iterator_category;

};

template < class T >
struct iterator_traits<T*> {

	typedef T							value_type;
	typedef typename std::ptrdiff_t		difference_type;//iterator間の距離を示す
	typedef T*							pointer;
	typedef T&							reference;
	typedef typename std::random_access_iterator_tag	iterator_category;

};

template < class T >
struct iterator_traits<const T*> {

	typedef T							value_type;
	typedef typename std::ptrdiff_t		difference_type;//iterator間の距離を示す
	typedef const T*					pointer;
	typedef const T&					reference;
	typedef typename std::random_access_iterator_tag	iterator_category;

};
};
#endif
