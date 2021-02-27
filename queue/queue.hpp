/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:22:15 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/18 16:30:04 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../List/List.hpp"
# include <iostream> 

namespace ft {
	
template <class T, class Container = list<T> >
class queue {
public:
	typedef T			value_type;
	typedef	Container	container_type;
	typedef	size_t		size_type;

protected:
	container_type	c;

public:
	explicit queue (const container_type& ctnr = container_type()) : c(ctnr) {
	}
	bool empty() const {
		return this->c.empty();
	}
	size_type size() const {
		return this->c.size();
	}

	value_type& front() {
		return this->c.front();
	}
	const value_type& front() const {
		return this->c.front();
	}
	value_type& back() {
		return this->c.back();
	}
	const value_type& back() const {
		return this->c.back();
	}
	
	void push (const value_type& val) {
		this->c.push_back(val);
	}
	void pop() {
		this->c.pop_front();
	}
	friend bool	operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.c == rhs.c);
	}
	friend bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.c != rhs.c);
	}
	friend bool	operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.c < rhs.c);
	}
	friend bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.c > rhs.c);
	}
	friend bool	operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.c <= rhs.c);
	}
	friend bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.c >= rhs.c);
	}
};

}

#endif
