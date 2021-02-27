/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:53:20 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/18 15:09:58 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "../vector/Vector.hpp"

namespace ft {
	
template <class T, class Container = vector<T> >
class stack {
public:
	typedef T			value_type;
	typedef	Container	container_type;
	typedef	size_t		size_type;
protected:
	container_type	c;
public:
	explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {
	}
	bool empty() const {
		return this->c.empty();
	}
	size_type size() const {
		return this->c.size();
	}
	value_type& top() {
		return this->c.back();
	}
	const value_type& top() const {
		return this->c.back();
	}
	void push (const value_type& val) {
		this->c.push_back(val);
	}
	void pop() {
		this->c.pop_back();
	}

	friend bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c == rhs.c);
	}
	friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c != rhs.c);
	}
	friend bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c < rhs.c);
	}
	friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c > rhs.c);
	}
	friend bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c <= rhs.c);
	}
	friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c >= rhs.c);
	}

};
}

#endif
