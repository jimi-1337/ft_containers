/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:31:34 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/09 14:58:07 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {
	template<typename T>
	class node{
	public:
		T	data;
		node	*next;
		node	*prev;

		explicit node(const T &val = T()) : data(val), next(0), prev(0) {}
		node (const node &other) : data(other), next(0), prev(0) {}
		~node(){}
		
		node &operator=(node const &rhs) {
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
};
#endif