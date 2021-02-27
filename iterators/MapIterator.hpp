#pragma once

# include <memory>
# include <cstddef>
# include <iostream>
# include <algorithm>
# include "../map/MapNode.hpp"

namespace ft {

template <typename T, typename Pointer, typename Reference>
class MapIterator {
public:
	typedef MapIterator<T, Pointer, Reference>	        this_type;
	typedef MapIterator<T, T*, T&>      				iterator;
	typedef size_t										size_type;
	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
    typedef node<T>									    nodemap;
	typedef node<T>*									node_pointer;
	typedef T*		    								pointer;
	typedef T&      									reference;
	typedef std::bidirectional_iterator_tag				iterator_category;
	
	node_pointer ptr;
	MapIterator() : ptr(NULL) {}
	MapIterator(nodemap* elem) : ptr(elem) { }
	MapIterator(const iterator& x) : ptr(x.ptr) {}
	~MapIterator( ) { }
    // friend class map;
	
	this_type&	operator=(const iterator& x) {
		this->ptr = x.ptr;
		return *this;
	}

	reference operator*() const { return ptr->data; }
	value_type* operator->() const { return &(this->ptr->data); }

	this_type& operator++() {
		ptr = ptr->next;
		return *this;
	}
	this_type  operator++(int) {
		this_type	out(*this);
		ptr = ptr->next;
		return out;
	}
	this_type& operator--() {
		ptr = ptr->prev;
		return *this;
	}
	this_type  operator--(int) {
		this_type	out(*this);
		ptr = ptr->prev;
		return out;
	}
	template<typename T2, typename P, typename R>
	friend bool operator==(const this_type& lhs, const MapIterator<T2, P, R>& rhs) {
		return (lhs.ptr == rhs.ptr);
	}
	template<typename T2, typename P, typename R>
	friend bool operator!=(const this_type& lhs, const MapIterator<T2, P, R>& rhs) { return !(lhs == rhs); }
	
	// protected:
	node_pointer	getnext() const { return ptr->next; }
	node_pointer	getprev() const { return ptr->prev; }
	node_pointer	getptr() const { return ptr; }
	};

template <typename T, typename Pointer, typename Reference>
class rev_MapIterator {
public:
	typedef rev_MapIterator<T, Pointer, Reference>	    this_type;
	typedef rev_MapIterator<T, T*, T&>      			iterator;
	typedef size_t										size_type;
	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
    typedef node<T>									    nodemap;
	typedef node<T>*									node_pointer;
	typedef T*		    								pointer;
	typedef T&      									reference;
	typedef std::bidirectional_iterator_tag				iterator_category;
	
	node_pointer ptr;
	rev_MapIterator() : ptr(NULL) {}
	rev_MapIterator(nodemap* elem) : ptr(elem) { }
	rev_MapIterator(const iterator& x) : ptr(x.ptr) {}
	~rev_MapIterator( ) { }
    // friend class map;
	
	this_type&	operator=(const iterator& x) {
		this->ptr = x.ptr;
		return *this;
	}

	reference operator*() const { return ptr->data; }
	value_type* operator->() const { return &(this->ptr->data); }

	this_type& operator++() {
		ptr = ptr->prev;
		return *this;
	}
	this_type  operator++(int) {
		this_type	out(*this);
		ptr = ptr->prev;
		return out;
	}
	this_type& operator--() {
		ptr = ptr->next;
		return *this;
	}
	this_type  operator--(int) {
		this_type	out(*this);
		ptr = ptr->next;
		return out;
	}
	template<typename T2, typename P, typename R>
	friend bool operator==(const this_type& lhs, const rev_MapIterator<T2, P, R>& rhs) {
		return (lhs.ptr == rhs.ptr);
	}
	template<typename T2, typename P, typename R>
	friend bool operator!=(const this_type& lhs, const rev_MapIterator<T2, P, R>& rhs) { return !(lhs == rhs); }
	
	// protected:
	node_pointer	getnext() const { return ptr->next; }
	node_pointer	getprev() const { return ptr->prev; }
	node_pointer	getptr() const { return ptr; }
	};
};