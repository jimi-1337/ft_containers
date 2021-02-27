/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:54:39 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/17 14:53:41 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

namespace ft{
	template<typename T>
	class node
	{
	public:
		typedef	T		value_type;
		typedef T&		reference;
		typedef T*		pointer;
		typedef size_t	size_type;
		typedef const T&	const_reference;
		typedef const T*	const_pointer;
		// friend class map;

		value_type data;
		node<T>* next;
		node<T>* prev;
		
		explicit node(const T &val = T()) : data(val), next(0), prev(0) {};
		node (const node &other) : data(other), next(0), prev(0) {}
		~node() {};
		node &operator=(node const &rhs) {
			printf("-----------\n");
			if (this != &rhs)
			{
				this->datat = rhs.data;
				this->next = rhs.next;
				this->prev = rhs.prev;
			}
			return (*this);
		}
		bool &operator==(node const &rhs) {
			return(this->data == rhs.data && this->next = rhs.next && this->prev = rhs.prev);
		}
		bool	operator!=(const node& rhs) const {
			return *this != rhs;
		}
		node*	getnext() {
			return this->next;
		}
		node*	getprevious() {
			return this->prev;
		}
	};
}

#endif