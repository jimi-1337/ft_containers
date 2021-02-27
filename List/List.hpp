/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:04:52 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/19 17:30:16 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <memory>
# include <cstddef>
# include <iostream>
# include "ListNode.hpp"
# include "../iterators/listiterator.hpp"
# include "../iterators/reverseiterator.hpp"
#include "../utils/Extra.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class list {

	public:
		typedef T			value_type;
		typedef Alloc		allocator_type;
		typedef T			&reference;
		typedef const T		&const_reference;
		typedef T			*pointer;
		typedef const T		*const_pointer;
		typedef node<T> 	*node_pointer;
		typedef ptrdiff_t	difference_type;
		typedef size_t		size_type;
		typedef ListIterator<value_type, pointer, reference>				iterator;
		typedef ListIterator<value_type, const_pointer, const_reference>	const_iterator;
		typedef ReverseI<iterator >											reverse_iterator;
		typedef ReverseI<const_iterator >									const_reverse_iterator;

	// private:
		node_pointer	head;
		node_pointer	tail;
		allocator_type	alloc;
		size_type		length;
	public:
	/* Constructors, destructor and operator= */
		explicit list(const allocator_type& alloc = allocator_type()) : alloc(alloc), length(0) /* Default constructor */
		{
			this->head = new node<T>();
			this->tail = new node<T>();
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->tail->next = NULL;
		}
		explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc), length(0)
		{
			this->head = new node<T>();
			this->tail = new node<T>();
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->tail->next = NULL;
			this->assign(n, val);
		}
		template <class InputIterator>
		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				: alloc(alloc), length(0) {
			this->head = new node<T>();
			this->tail = new node<T>();
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->tail->next = NULL;
			this->assign(first, last);
		}
		list (const list& x) : alloc(x.alloc), length(0) {
			this->head = new node<T>();
			this->tail = new node<T>();
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->tail->next = NULL;
			this->assign(x.begin(), x.end());
		}
		list&	operator=(const list& x) {
			this->clear();
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->tail->next = NULL;
			this->length = 0;
			this->assign(x.begin(), x.end());
			return *this;
		}
		~list() {
			this->clear();
			delete this->tail;
			delete this->head;
		}
	/* Iterators */
		iterator	begin() {
			return iterator(this->head->next);
		}
		const_iterator	begin() const {
			return const_iterator(this->head->next);
		}
		iterator	end() {
			return iterator(this->tail);
		}
		const_iterator	end() const {
			return const_iterator(this->tail);
		}
		reverse_iterator		rbegin() {
			return reverse_iterator(this->tail->prev);
		}
		const_reverse_iterator	rbegin() const {
			return const_reverse_iterator(this->tail->prev);
		}
		reverse_iterator		rend() {
			return reverse_iterator(this->head);
		}
		const_reverse_iterator	rend() const {
			return const_reverse_iterator(this->head);
		}
		/* Capacity */
		bool		empty() const {
			return (this->length == 0);
		}
		size_type	size() const {
			return this->length;
		}
		size_type	max_size() const {
			return (std::numeric_limits<size_type>::max() / (sizeof(node<value_type>)));
		}
	/* Element access */
		reference		front() {
			return this->head->next->data;
		}
		const_reference	front() const {
			return this->head->next->data;
		}
		reference		back() {
			return this->tail->prev->data;
		}
		const_reference	back() const {
			return this->tail->prev->data;
		}
	/* Modifiers */
		template <class InputIterator>
 		void assign(InputIterator first, InputIterator last) {
			this->clear();
			while (first != last && first.getptr()->next != NULL) {
				push_back(*first);
				++first;
			}
		}
		void	assign(int n, const value_type& val) {
			this->clear();
			while (n > 0) {
				push_back(val);
				--n;
			}
		}
		void	assign(size_type n, const value_type& val) {
			this->clear();
			while (n > 0) {
				push_back(val);
				--n;
			}
		}
		void	push_front(const value_type &val) {
			node<T> *ptr = new node<T>(val);
			ptr->prev = this->head;
			ptr->next = this->head->next;
			this->head->next->prev = ptr;
			this->head->next = ptr;
			this->length++;
		}
		void	push_back(const value_type &val) {
			node<T>	*ptr = new node<T>(val);
			ptr->next = this->tail;
			ptr->prev = this->tail->prev;
			this->tail->prev->next = ptr;
			this->tail->prev = ptr;
			this->tail->next = NULL;
			this->length++;
		}
		void	pop_front() {
			if (this->length)
			{
				node<T> *tmp = this->head->next->next;
				tmp->prev = this->head;
				delete this->head->next;
				this->head->next = tmp;
				this->length--;
			}
		}
		void	pop_back() {
			if (this->length)
			{
				node<T>	*tmp = this->tail->prev->prev;
				tmp->next = this->tail;
				delete this->tail->prev;
				this->tail->prev = tmp;
				this->tail->next = NULL;
				this->length--;
			}
		}
		iterator	insert(iterator position, const value_type& val) {
			node<T> *insertion = new node<T>(val);
			insertion->prev = position.getptr()->prev;
			insertion->next = position.getptr();
			insertion->prev->next = insertion;
			insertion->next->prev = insertion;
			this->length++;
			return iterator(insertion);
		}
		void		insert(iterator position, size_type n, const value_type& val) {
			while (n > 0) {
				insert(position, val);
				--n;
			}
		}
		void		insert(iterator position, int n, const value_type& val) {
			while (n > 0) {
				insert(position, val);
				--n;
			}
		}
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last) {
			while (first != last && first.getptr()->next != NULL) {
				insert(position, *first);
				first++;
			}
		}
		iterator	erase(iterator position) {
			if (position.getptr()->next == NULL)
				return position;			
			node<T> *tmp = position.getptr();
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			position++;
			delete tmp;
			this->length--;
			return position;
		}
		iterator	erase(iterator first, iterator last) {
			while (first != last) {
				this->erase(first++);
			}
			return first;
		}
		void	swap(list& x) {
			ft::itemswap(this->head, x.head);
			ft::itemswap(this->tail, x.tail);
			ft::itemswap(this->length, x.length);
			ft::itemswap(this->alloc, x.alloc);
		}
		void	resize(size_type n, value_type val = value_type()) {
			while (this->length > n) {
				pop_back();
			}
			while (this->length < n) {
				push_back(val);
			}
		}
		void	clear() {
			while (this->length) {
				pop_back();
			}
		}
		void	splice(iterator position, list& x) {
			splice(position, x, x.begin(), x.end());
		}
		void	splice(iterator position, list&x, iterator i) {
			iterator next(i);
			this->splice(position, x, i, ++next);
		}
		void	splice(iterator position, list& x, iterator first, iterator last) {
			node_pointer firstx = first.getptr();
			node_pointer lastx = last.getptr();
			node_pointer lastelemx = lastx->prev;
			difference_type	diff = ft::distance(first, last);
			node_pointer pos = position.getptr();
			x.length -= diff;
			this->length += diff;

			firstx->prev->next = lastx;
			lastx->prev = firstx->prev;
			
			pos->prev->next = firstx;
			firstx->prev = pos->prev;
			pos->prev = lastelemx;
			lastelemx->next = pos;
		}
		void	remove(const value_type& val) {
			iterator	it = begin();
			while (it != end()) {
				if (*it == val)
					it = erase(it);
				else
					++it;
			}
		}
		template <class Predicate>
		void remove_if (Predicate pred) {
			iterator it = begin();
			while (it != end()) {
				if (pred(*it) == true)
					it = erase(it);
				else
					++it;
			}
			
		}
		void	unique() { /* Not truly unique, only removes consecutive same-value elements */
			iterator it = begin();
			++it;
			while (it != end()) {
				if (*it == it.getprev()->data)
					it = erase(it);
				else
					++it;
			}
		}
		template <class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred) {
			iterator it = begin();
			++it;
			while (it != end()) {
				if (binary_pred(*it, *it.getprev()->data))
					it = erase(it);
				else
					++it;
			}
		}
		void	sort() {
			iterator it = begin();
			++it;
			while (it != end()) {
				if (*it < it.getprev()->data) {
					this->swap(it.getptr(), it.getprev());
					it = begin();
				}
				++it;
			}
		}
		template <class Compare>
		void	sort(Compare comp) {
			iterator it = begin();
			++it;
			while (it != end()) {
				if (comp(*it, it.getprev()->data)) {
					this->swap(it.getptr(), it.getprev());
					it = begin();
				}
				++it;
			}
		}
		template<typename value_type>
		bool	less_than(const value_type& a, const value_type& b) {
			return (a < b);
		}
		void	merge(list& x) {
			this->merge(x, &less_than<value_type>);
		}
		template <class Compare>
		void merge (list& x, Compare comp) {
			if (&x == this)
				return ;
			iterator it = begin();
			iterator xit = x.begin();
			while (it != end() && xit != x.end()) {
				while (it != end() && !comp(*xit, *it))
					++it;
				++xit;
				this->splice(it, x, xit.getprev());
			}
			if (xit != x.end())
				this->splice(it, x, xit, x.end());
		}
		void	reverse() {
			iterator it = begin();	
			while (it != end()) {
				itemswap(it.getptr()->prev, it.getptr()->next);
				it--;
			}
			itemswap(head->prev, head->next);
			itemswap(tail->prev, tail->next);
			itemswap(head, tail);
		}
	};

/* Relational operators (list) */
template <class T, class Alloc>
bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (list<T,Alloc>& x, list<T,Alloc>& y) {
	ft::itemswap(x.head, y.head);
	ft::itemswap(x.tail, y.tail);
	ft::itemswap(x.length, y.length);
	ft::itemswap(x.alloc, y.alloc);
}
}
#endif