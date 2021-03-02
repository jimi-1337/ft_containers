/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:06:25 by amoujane          #+#    #+#             */
/*   Updated: 2021/03/01 15:16:47 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iostream>
# include <cstddef>
# include "MapNode.hpp"
# include "../utils/Extra.hpp"
# include "../utils/Pair.hpp"
# include "../iterators/MapIterator.hpp"

namespace ft {
template < class Key, class Value, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,Value> > >
	class map
	{
	public:
	// class iterator;
	typedef ft::pair<const Key,Value>	value_type;
	typedef Key							key_type;
	typedef Value						mapped_type;
	typedef Compare						key_compare;
	typedef Alloc						allocator_type;
	typedef value_type&					reference;
	typedef value_type&					const_reference;
	typedef value_type*					pointer;
	typedef value_type*					const_pointer;
	typedef	ptrdiff_t					difference_type;
	typedef size_t						size_type;
	typedef node<value_type>			nodemap;
	typedef MapIterator<value_type, pointer, reference>				iterator;
	typedef MapIterator<value_type, const_pointer, const_reference>		const_iterator;
	typedef rev_MapIterator<value_type, pointer, reference>			reverse_iterator;
	typedef rev_MapIterator<value_type, const_pointer, const_reference>		const_reverse_iterator;

	class value_compare
	{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  		friend class map;
	protected:
  		Compare comp;
  		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
  		typedef bool result_type;
  		typedef value_type first_argument_type;
  		typedef value_type second_argument_type;
  		bool operator() (const value_type& x, const value_type& y) const
  		{
    		return comp(x.first, y.first);
  		}
	};

	private:
	nodemap*	_head;
	nodemap*	_tail;
	size_type			_size;
	key_compare			_comp;
	allocator_type		_alloc;
	
	public:
	// Constructors, destructors and operator=
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc) {
			this->_head = new nodemap;
			this->_tail = new nodemap;
			this->_size = 0;
			this->_head->next = _tail;
			this->_tail->prev = _head;
			this->_tail->next = NULL;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_size(0), _comp(comp), _alloc(alloc){
			this->_head = new nodemap;
			this->_tail = new nodemap;
			this->_size = 0;
			this->_head->next = _tail;
			this->_tail->prev = _head;
			this->_tail->next = NULL;
			this->insert(first, last);
		}
		map (const map& x): _size(0), _comp(x._comp), _alloc(x._alloc) {
			this->_head = new nodemap;
			this->_tail = new nodemap;
			this->_size = 0;
			this->_head->next = _tail;
			this->_tail->prev = _head;
			this->_tail->next = NULL;
			insert(x.cbegin(), x.cend());
		}
		~map(){
			this->clear();
			delete _head;
			delete _tail;
			_head = NULL;
			_tail = NULL;
		};
		map& operator= (const map& x) {
		if (this != &x) {
			this->clear();
			this->_alloc = x._alloc;
			this->_comp = x._comp;
			this->insert(x.begin(), x.end());
		}
		return (*this);
		}
		/*iterator*/
		iterator	begin() {
			return iterator(this->_head->next);
		}
		const_iterator	cbegin() const {
			return const_iterator(this->_head->next);
		}
		iterator	end() {
			return iterator(this->_tail);
		}
		const_iterator	cend() const {
			return const_iterator(this->_tail);
		}
		reverse_iterator		rbegin() {
			return reverse_iterator(this->_tail->prev);
		}
		const_reverse_iterator	crbegin() const {
			return const_reverse_iterator(this->_tail->prev);
		}
		reverse_iterator		rend() {
			return reverse_iterator(this->_head);
		}
		const_reverse_iterator	crend() const {
			return const_reverse_iterator(this->_head);
		}
		/*capacity*/
		bool empty() const {return (_size == 0);};
		size_type size() const {{return (_size);}};
		size_type max_size() const {return (461168601842738790);};
		/*Element access*/
		mapped_type&		operator[](const key_type& k) {
			return insert(ft::make_pair(k, mapped_type())).first->second;
		}
		/*Modifiers*/
		bool ft_compare(key_type a, key_type b, key_compare U = Compare())
		{
			return (U(a, b));
		}
		ft::pair<iterator,bool> insert (const value_type& val){
			nodemap *ptr = new nodemap(val);
			nodemap *tmp1;
			// nodemap *tmp2;
			tmp1 = _head->next;
			size_type i = 0;
			while(i < _size && tmp1->next != NULL)
			{
				if (tmp1->data.first == val.first)
				{
					return (ft::pair<iterator, bool>(iterator(tmp1), true));
				}
				tmp1 = tmp1->next;
				i++;
			}
			tmp1 = _head->next;
			i = 0;
			while(tmp1->next != NULL && i < _size)
			{
				if (ft_compare(val.first, tmp1->data.first) == 1)
				{
					ptr->next = tmp1;
					ptr->prev = tmp1->prev;
					tmp1->prev->next = ptr;
					tmp1->prev = ptr;
					_size++;
					return (ft::pair<iterator, bool>(iterator(ptr), true));
				}
				tmp1 = tmp1->next;
			}
			ptr->next = _tail;
			ptr->prev = _tail->prev;
			_tail->prev->next = ptr;
			_tail->prev = ptr;
			_tail->next = NULL;
			_size++;
			return (ft::pair<iterator, bool>(iterator(ptr), false));
		}
		iterator insert (iterator position, const value_type& val){
			(void)position;
			return (insert(val).first);
		}
		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last){
			while(first != last)
			{
				insert(std::make_pair(first->first, first->second));
				first++;
			}
		}
		void erase (iterator position){
			nodemap *tmp = position.getptr();
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
			this->_size--;
		}
		size_type erase (const key_type& k){
			nodemap *tmp;
			tmp = _head->next;
			size_type count;
			int i = 0;			
			while(tmp->next != NULL && i < _size)
			{
				if (tmp->data.first == k)
				{
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					delete tmp;
					this->_size--;
					return (count);
				}
				tmp = tmp->next;
				count++;
				i++;
			}
			return (0);
		}
		void erase (iterator first, iterator last){
			while(first != last)
			{
				erase(first);
				first++;
			}
		}
		void swap (map& x){
			ft::itemswap(this->_head, x._head);
			ft::itemswap(this->_tail, x._tail);
			ft::itemswap(this->_size, x._size);
			ft::itemswap(this->_alloc, x._alloc);
			ft::itemswap(this->_comp, x._comp);
		}
		void clear(){
			while(_size > 0)
			{
				nodemap	*tmp = this->_tail->prev->prev;
				tmp->next = this->_tail;
				delete this->_tail->prev;
				this->_tail->prev = tmp;
				this->_tail->next = NULL;
				this->_size--;
			}
		}
		/*Observers*/
		key_compare key_comp() const{
			return(Compare());
		}
		value_compare value_comp() const{
			return(value_compare(Compare()));
		}
		/*Operations*/
		iterator find (const key_type& k){
			nodemap *tmp1;
			tmp1 = _head->next;
			size_type i = 0;
			while(tmp1->next != NULL && i < _size)
			{
				if (tmp1->data.first == k)
					return (iterator(tmp1));
				tmp1 = tmp1->next;
				i++;
			}
			return (end());	
		}
		const_iterator find (const key_type& k) const{
			nodemap *tmp1;
			tmp1 = _head->next;
			int i = 0;
			while(tmp1->next != NULL && i < _size)
			{
				if (tmp1->data.first == k)
					return (iterator(tmp1));
				tmp1 = tmp1->next;
				i++;
			}
			return (end());
		}
		size_type count (const key_type& k) const{
			nodemap *tmp;

			tmp = _head->next;
			while(tmp->next != NULL)
			{
				if (tmp->data.first == k)
					return (1);
				tmp = tmp->next;
			}
			return (0);
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it->first != ite->first || it->second != ite->second)
			{
				if (it->first == k)
					return (it);
				it++;
			}
			return (ite);
		}
		const_iterator lower_bound (const key_type& k) const{
			const_iterator it = this->cbegin();
			const_iterator ite = this->cend();
			while (it->first != ite->first || it->second != ite->second)
			{
				if (it->first == k)
					return (it);
				it++;
			}
			return (ite);
		}
		iterator upper_bound (const key_type& k){
			iterator it = this->begin();
			iterator ite = this->end();
			while (it->first != ite->first || it->second != ite->second)
			{
				if (it->first == k)
					return (++it);
				it++;
			}
			return (ite);
		}
		const_iterator upper_bound (const key_type& k) const{
			const_iterator it = this->cbegin();
			const_iterator ite = this->cend();
			while (it->first != ite->first || it->second != ite->second)
			{
				if (it->first == k)
					return (++it);
				it++;
			}
			return (ite);
		}
		ft::pair<iterator,iterator>             equal_range (const key_type& k){
			return (std::make_pair(lower_bound(k), upper_bound(k)));
		}
	};
    
} // namespace ft

#endif