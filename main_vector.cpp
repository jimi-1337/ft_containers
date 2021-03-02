/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:46:20 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/28 16:25:43 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators/listiterator.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include "vector/Vector.hpp"

void print_list(ft::vector<int> a)
{
    ft::vector<int>::iterator it = a.begin();
    while (it != a.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

void	iterators_test() {
	ft::vector<int> hats;
	for (int i = 0; i < 72; i++)
		hats.push_back(i * 10);
	ft::vector<int>::iterator		it = hats.begin();
	ft::vector<int>::iterator		ite = hats.end();
		ite--;
	ft::vector<int>::iterator test = 5 + it;
	std::cout << "*test = " << *test << std::endl;
	std::cout << "*it = " << *it << ", *ite = " << *ite << std::endl;
	ft::vector<int>::const_iterator	cit = hats.begin();
	ft::vector<int>::const_iterator	cite = hats.end();
		cite--;
	std::cout << "const_iterators" << std::endl;
	std::cout << "*cit = " << *cit << ", *cite = " << *cite << std::endl;
	ft::vector<int>::reverse_iterator		rit = hats.rbegin();
	ft::vector<int>::reverse_iterator		rite = hats.rend();
	(void)rite;
	ft::vector<int>::const_reverse_iterator	crit = hats.rbegin();
	ft::vector<int>::const_reverse_iterator	crite = hats.rend();
	std::cout << "regular iterators:" << std::endl;
	std::cout << "reg: operator==(): " << std::boolalpha <<(it == cit) << ", " << (cit == it) << std::endl;
	std::cout << "reg: operator!=(): " << (it != cite) << ", " << (cite != it) << std::endl;
	std::cout << "reg: operator<(): " << (it < cite) << ", " << (cite < it) << std::endl;
	std::cout << "reg: operator<=(): " << (it <= cite) << ", " << (cite <= it) << std::endl;
	std::cout << "reg: operator>(): " << (it > cite) << ", " << (cite > it) << std::endl;
	std::cout << "reg: operator>=(): " << (it >= cite) << ", " << (cite >= it) << std::endl;
	ite = it;
	std::cout << "*it++ gives: " << *it++ << ", it now is " << *it << std::endl;
	std::cout << "*++it gives: " << *++it << ", it now is " << *it << std::endl;
	std::cout << "*rit++ gives: " << *rit++ << ", it now is " << *rit << std::endl;
	std::cout << "*++rit gives: " << *++rit << ", it now is " << *rit << std::endl;
	std::cout << "*it-- gives: " << *it-- << ", it now is " << *it << std::endl;
	std::cout << "*--it gives: " << *--it << ", it now is " << *it << std::endl;
	std::cout << "*rit-- gives: " << *rit-- << ", it now is " << *rit << std::endl;
	std::cout << "*--rit gives: " << *--rit << ", it now is " << *rit << std::endl;
	// *cit += 10;
	// *crit += 10;
	std::cout << "reverse iterators:" << std::endl;
	std::cout << "reverse: operator==(): " << (rit == crit) << ", " << (crit == rit) << std::endl;
	std::cout << "reverse: operator!=(): " << (rit != crite) << ", " << (crite != rit) << std::endl;
	std::cout << "reverse: operator<(): " << (rit < crite) << ", " << (crite < rit) << std::endl;
	std::cout << "reverse: operator<=(): " << (rit <= crite) << ", " << (crite <= rit) << std::endl;
	std::cout << "reverse: operator>(): " << (rit > crite) << ", " << (crite > rit) << std::endl;
	std::cout << "reverse: operator>=(): " << (rit >= crite) << ", " << (crite >= rit) << std::endl;
	std::cout << "dereference operator on iterators: " << it[2] << ", " << cit[3] << ", " << rit[4] << ", " << crit[5] << " WORK!" << std::endl;
}

void	relational_operators_test() {
	ft::vector<int>	a;
	ft::vector<int>	b;
	for (int i = 0; i < 8; i++) {
		a.push_back(i);
		b.push_back(i);
	}
	std::cout << "this one should return 1: " << (a == b) << ", and this one 0: " << (a != b) << std::endl;
	std::cout << (a < b) << "\t" << (b < a) << "\t" << (a <= b) << "\t" << (b <= a) << std::endl;
	a.push_back(0);
	b.push_back(5);
	std::cout << "now this version, should return 0: " << (a == b) << ", and this one 1: " << (a != b) << std::endl;
	std::cout << (a < b) << "\t" << (b < a) << "\t" << (a <= b) << "\t" << (b <= a) << std::endl;
}

int main()
{
    try
    {
    ft::vector<int> x;
    ft::vector<int> y(5, 10);
    ft::vector<int> z(y.begin(), y.end());
    ft::vector<int> z1(z);
    ft::vector<int> t;
    ft::vector<int> i;

    std::cout << "Begin" << std::endl;
    // std::cout << *x.begin() << std::endl;
    std::cout << *y.begin() << std::endl;
    std::cout << *z.begin() << std::endl;
    std::cout << *z1.begin() << std::endl;

    // end
    std::cout << "\nEnd" << std::endl;
    // std::cout << *x.end() << std::endl;
    std::cout << *y.end() << std::endl;
    std::cout << *z.end() << std::endl;
    std::cout << *z1.end() << std::endl;

    // rbegin
    std::cout << "\nrBegin" << std::endl;
    // std::cout << *x.rbegin() << std::endl;
    std::cout << *y.rbegin() << std::endl;
    std::cout << *z.rbegin() << std::endl;
    std::cout << *z1.rbegin() << std::endl;

    // rend
    std::cout << "\nrend" << std::endl;
    // std::cout << *x.rend() << std::endl;
    std::cout << *y.rend() << std::endl;
    std::cout << *z.rend() << std::endl;
    std::cout << *z1.rend() << std::endl;

    // empty
    std::cout << "\nempty" << std::endl;
    std::cout << x.empty() << std::endl;
    std::cout << y.empty() << std::endl;
    std::cout << z.empty() << std::endl;
    std::cout << z1.empty() << std::endl;

    // size
    std::cout << "\nsize" << std::endl;
    std::cout << x.size() << std::endl;
    std::cout << y.size() << std::endl;
    std::cout << z.size() << std::endl;
    std::cout << z1.size() << std::endl;

    // max_size
    std::cout << "\nmax_size" << std::endl;
    std::cout << x.max_size() << std::endl;

    // front
    std::cout << "\nfront" << std::endl;
    // std::cout << x.front() << std::endl;
    std::cout << y.front() << std::endl;
    std::cout << z.front() << std::endl;
    std::cout << z1.front() << std::endl;

    // back
    std::cout << "\nback" << std::endl;
    // std::cout << x.back() << std::endl;
    std::cout << y.back() << std::endl;
    std::cout << z.back() << std::endl;
    std::cout << z1.back() << std::endl;

    // assign
    std::cout << "\nassign" << std::endl;
    x.assign(6, -5);
    y.assign(x.begin(), x.end());
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    //push_back
    std::cout << "\npush_back, front and back" << std::endl;
    y.push_back(-22222);
    std::cout << "front: " << y.front() << "  back:" << y.back() << std::endl;

    //pop_back
    std::cout << "\npop" << std::endl;
    y.pop_back();
    std::cout << "back:" << y.back() << std::endl;


    // insert
    std::cout << "\ninsert" << std::endl;
    x.insert(x.begin(), 555);
    y.insert(y.begin(), x.begin(), x.end());
    x.insert(x.begin(), 2, 2);
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);
    // clear
    std::cout << "\nclear" << std::endl;
    x.clear();
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    
    // erase
    std::cout << "\nerase" << std::endl;
    x.push_back(4);
    x.push_back(3);
    x.push_back(1);
    x.push_back(2);
    ft::vector<int>::iterator it = x.begin();
    it++;
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list x------" << std::endl;
    x.erase(it);
    print_list(x);
    std::cout << "-----list x------" << std::endl;
    x.erase(x.begin(), x.end());
    print_list(x);

    //swap
    std::cout << "\nswap" << std::endl;
    x.swap(y);
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);
    std::cout << "-----size y------" << std::endl;
    std::cout << y.size() << std::endl;

    //resize
    std::cout << "\nresize" << std::endl;
    y.resize(10, 9);
    std::cout << "-----list y------" << std::endl;
    print_list(y);
    std::cout << "-----size y------" << std::endl;
    std::cout << y.size() << std::endl;
    //capacity
    std::cout << "-----capacity y------" << std::endl;
    std::cout << y.capacity() << std::endl;

    //at
    std::cout << "-----at x------" << std::endl;
    std::cout << x.at(0) << std::endl;
    std::cout << "-----operator []------" << std::endl;
    std::cout << x[0] << std::endl;
    //reserve
    std::cout << "-----reserve------" << std::endl;
    ft::vector<int> w;
    w.reserve(10);
    std::cout << "-----capacity x------" << std::endl;
    std::cout << w.capacity() << std::endl;
    std::cout << "-----size x------" << std::endl;
    std::cout << w.size() << std::endl;
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    w.push_back(1);
    std::cout << "-----capacity x------" << std::endl;
    std::cout << w.capacity() << std::endl;
    std::cout << "-----size x------" << std::endl;
    std::cout << w.size() << std::endl;

    std::cout << "-------------------------------" << std::endl;
    iterators_test();
    std::cout << "-------------------------------" << std::endl;
    relational_operators_test();
    std::cout << "-------------------------------" << std::endl;
    swap(w, y);
    std::cout << "-----list y------" << std::endl;
    print_list(y);
    std::cout << "-----list w------" << std::endl;
    print_list(w);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}