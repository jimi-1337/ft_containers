/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseiterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:42:01 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/28 15:44:25 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

template <class Iterator >
class ReverseI {
protected:
	Iterator	current;
public:
	typedef Iterator							iterator_type;
	typedef typename Iterator::pointer			pointer;
	typedef typename Iterator::reference		reference;
	typedef typename Iterator::size_type		size_type;
	typedef typename Iterator::difference_type	difference_type;
	typedef typename Iterator::iterator_category	iterator_category;

	ReverseI() : current() { }
	ReverseI(const iterator_type& x) : current(x) { }
	ReverseI(const ReverseI& x) : current(x.current) { }
	template<typename Iter>
	ReverseI(const ReverseI<Iter>& x) : current(x.geter()) { }
	~ReverseI() { }
	ReverseI&	operator=(const ReverseI& x) {
		this->current = x.current;
		return *this;
	}
	iterator_type	geter() const { return this->current; }

	reference	operator*() {
		return *current;
	}
	pointer		operator->() {
		return &operator*();
	}
	ReverseI&	operator++() {
		--current;
		return *this;
	}
	ReverseI	operator++(int) {
		ReverseI	out(*this);
		--current;
		return out;
	}
	ReverseI&	operator--() {
		++current;
		return *this;
	}
	ReverseI	operator--(int) {
		ReverseI	out(*this);
		++current;
		return out;
	}
};
template <typename Iterator>
inline bool	operator==(const ReverseI<Iterator>& lhs, const ReverseI<Iterator>& rhs) {
	return (lhs.geter() == rhs.geter());
}
template <typename Iterator>
inline bool	operator<(const ReverseI<Iterator>& lhs, const ReverseI<Iterator>& rhs) {
	return (rhs.geter() < lhs.geter());
}
template <typename Iterator>
inline bool	operator!=(const ReverseI<Iterator>& lhs, const ReverseI<Iterator>& rhs) {
	return !(lhs == rhs);
}
template <typename Iterator>
inline bool	operator>(const ReverseI<Iterator>& lhs, const ReverseI<Iterator>& rhs) {
	return (rhs < lhs);
}
template <typename Iterator>
inline bool	operator<=(const ReverseI<Iterator>& lhs, const ReverseI<Iterator>& rhs) {
	return !(rhs < lhs);
}
template <typename Iterator>
inline bool	operator>=(const ReverseI<Iterator>& lhs, const ReverseI<Iterator>& rhs) {
	return !(lhs < rhs);
}
// Comparison of reverse_iterator to const reverse iterator
template <typename IteratorL, typename IteratorR>
inline bool operator==(const ReverseI<IteratorL>& lhs, const ReverseI<IteratorR>& rhs) {
	return (lhs.geter() == rhs.geter());
}
template <typename IteratorL, typename IteratorR>
inline bool operator<(const ReverseI<IteratorL>& lhs, const ReverseI<IteratorR>& rhs) {
	return (rhs.geter() < lhs.geter());
}
template <typename IteratorL, typename IteratorR>
inline bool operator!=(const ReverseI<IteratorL>& lhs, const ReverseI<IteratorR>& rhs) {
	return !(lhs == rhs);
}
template <typename IteratorL, typename IteratorR>
inline bool operator>(const ReverseI<IteratorL>& lhs, const ReverseI<IteratorR>& rhs) {
	return (rhs < lhs);
}
template <typename IteratorL, typename IteratorR>
inline bool operator<=(const ReverseI<IteratorL>& lhs, const ReverseI<IteratorR>& rhs) {
	return !(rhs < lhs);
}
template <typename IteratorL, typename IteratorR>
inline bool operator>=(const ReverseI<IteratorL>& lhs, const ReverseI<IteratorR>& rhs) {
	return !(lhs < rhs);
}
// Generator function for reverse_iterator
// template <typename Iterator>
// inline ReverseI<Iterator>	make_reverse_iterator(Iterator i) {
// 	return ReverseI<Iterator>(i);
// }

template <class Iterator >
class ReverseRAI : public ReverseI<Iterator> {
	public:
		typedef ReverseI<Iterator>	Base;
		typedef Iterator iterator_type;
		using typename Base::pointer;
		using typename Base::reference;
		using typename Base::size_type;
		using typename Base::difference_type;
		using typename Base::iterator_category;

		ReverseRAI() : Base() { }
		ReverseRAI(const iterator_type& x) : Base(x) { }
		ReverseRAI(const ReverseRAI& x) : Base(x.current) { }
		template<typename Iter>
		ReverseRAI(const ReverseI<Iter>& x) : Base(x.geter()) { } //.geter() returns the underlying iterator
		~ReverseRAI() { }
		// ReverseRAI&	operator=(const ReverseRAI& x) {
		// 	geter::operator=(x);
		// 	return *this;
		// }

		ReverseRAI	operator+(difference_type n) const {
			return ReverseRAI(this->current - n);
		}
		ReverseRAI&	operator+=(difference_type n) {
			this->current -= n;
			return  *this;
		}
		ReverseRAI	operator-(difference_type n) const {
			return ReverseRAI(this->current + n);
		}
		ReverseRAI&	operator-=(difference_type n) {
			this->current += n;
			return *this;
		}
		reference	operator[](difference_type n) {
			return *(*this + n);
		}
};

template<typename Iterator>
inline typename ReverseRAI<Iterator>::difference_type operator-(const ReverseRAI<Iterator>& lhs, const ReverseRAI<Iterator>& rhs) {
	return (lhs.geter() - rhs.geter());
}
template<typename IteratorL, typename IteratorR>
inline typename ReverseRAI<IteratorL>::difference_type operator-(const ReverseRAI<IteratorL>& lhs, const ReverseRAI<IteratorR>& rhs) {
	return (lhs.geter() - rhs.geter());
}

template <typename Iterator>
inline ReverseRAI<Iterator>	operator+(typename ReverseRAI<Iterator>::difference_type n, const ReverseRAI<Iterator>& x) {
	return ReverseRAI<Iterator>(x.geter() - n);
}

#endif
