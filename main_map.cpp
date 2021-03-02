/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:31:00 by amoujane          #+#    #+#             */
/*   Updated: 2021/03/01 15:22:41 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/Map.hpp"
#include "map/MapNode.hpp"
#include <iostream>
#include <map>
#include <cmath>

void ft_print_pair(ft::pair<int, int> it)
{
    std::cout << "first : " << it.first << "\tsecond : " << it.second << std::endl;
}

void ft_print_map(ft::map<int,int> x)
{
    ft::map<int,int>::iterator it = x.begin();
    while(it != x.end())
    {
        std::cout << "first : " << it->first << "\tsecond : " << it->second << std::endl;
        it++;
    }
}

int main()
{
    ft::map<int, int> x;
    std::cout << "--------default constructor--------" << std::endl;
    std::cout << "--------map x--------" << std::endl;
    ft_print_map(x);
    //insert
    std::cout << "--------insert--------" << std::endl;
    x.insert(x.begin(), ft::pair<int, int>(1, 2));
    x.insert(x.begin(), ft::pair<int, int>(2, 3));
    x.insert(x.begin(), ft::pair<int, int>(3, 5));
    x.insert(x.begin(), ft::pair<int, int>(4, 7));
    std::cout << "--------map x--------" << std::endl;
    // ft_print_map(x);
    std::cout << "--------copy constructor--------" << std::endl;
	ft::map<int, int> y(x);
    std::cout << "--------map y--------" << std::endl;
    ft_print_map(y);
    std::cout << "--------constructor with iter--------" << std::endl;
    ft::map<int, int> z(++x.begin(), x.end());
    std::cout << "--------map z--------" << std::endl;
    ft_print_map(z);

    std::cout << "Begin" << std::endl;
    std::cout << (*x.begin()).first << std::endl;
    // std::cout << (*x.begin()).second << std::endl;
    std::cout << y.begin()->first << std::endl;
    std::cout << z.begin()->first << std::endl;

    // end
    std::cout << "\nEnd" << std::endl;
    std::cout << x.end()->first << std::endl;
    std::cout << y.end()->first << std::endl;
    std::cout << z.end()->first << std::endl;

    // rbegin
    std::cout << "\nrBegin" << std::endl;
    std::cout << x.rbegin()->first << std::endl;
    std::cout << y.rbegin()->first << std::endl;
    std::cout << z.rbegin()->first << std::endl;

    // rend
    std::cout << "\nrend" << std::endl;
    std::cout << x.rend()->first << std::endl;
    std::cout << y.rend()->first << std::endl;
    std::cout << z.rend()->first << std::endl;

    // empty
    std::cout << "\nempty" << std::endl;
    std::cout << x.empty() << std::endl;
    std::cout << y.empty() << std::endl;
    std::cout << z.empty() << std::endl;

    // size
    std::cout << "\nsize" << std::endl;
    std::cout << x.size() << std::endl;
    std::cout << y.size() << std::endl;
    std::cout << z.size() << std::endl;

    // max_size
    std::cout << "\nmax_size" << std::endl;
    std::cout << x.max_size() << std::endl;
    //operator
    std::cout << "\noperator []" << std::endl;
    x.clear();
    int i = 0;
    while(i < 3)
    {
        x[i] = 1;
        i++;
    }
    ft_print_map(x);
    std::cout << x.size() << std::endl;
    // erase
    std::cout << "\nerase" << std::endl;
    ft::map<int, int>::iterator it = x.begin();
    it++;
    std::cout << "-----map x------" << std::endl;
    ft_print_map(x);
    std::cout << "-----map x------" << std::endl;
    x.erase(it);
    ft_print_map(x);
    std::cout << "-----map x------" << std::endl;
    x.erase(x.begin(), x.end());
    ft_print_map(x);

    //swap
    std::cout << "\nswap" << std::endl;
    std::cout << "-----map y------" << std::endl;
    ft_print_map(y);
    x.swap(y);
    std::cout << "-----map x------" << std::endl;
    ft_print_map(x);
    std::cout << "-----map y------" << std::endl;
    ft_print_map(y);
    std::cout << "-----size y------" << std::endl;
    std::cout << y.size() << std::endl;
    
    //clear
    std::cout << "\nclear" << std::endl;
    x.clear();
    std::cout << "-----map x------" << std::endl;
    ft_print_map(x);
    
    //key_comp
    std::cout << "\nkey_comp" << std::endl;
    ft::map<char,int> mymap;

    ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:\n";

    char highest = mymap.rbegin()->first;     // key value of last element

    std::cout << highest << std::endl;
    ft::map<char,int>::iterator iter = mymap.begin();
    do {
    std::cout << iter->first << " => " << iter->second << '\n';
    } while ( mycomp((*iter++).first, highest) );

    std::cout << '\n';
    
    //value_comp
    std::cout << "\nvalue_comp" << std::endl;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    ft::pair<char,int> high = *mymap.rbegin();          // last element

    ft::map<char,int>::iterator t = mymap.begin();
    do {
        std::cout << t->first << " => " << t->second << '\n';
    } while ( mymap.value_comp()(*t++, high) );

    //find
    // y.clear();
    y.insert(ft::pair<int, int>(1, 2));
    y.insert(ft::pair<int, int>(2, 3));
    y.insert(ft::pair<int, int>(3, 4));
    y.insert(ft::pair<int, int>(4, 5));
    y.insert(ft::pair<int, int>(5, 2));
    std::cout << "-----------map y----------" << std::endl;
    ft_print_map(y);
    std::cout << "--------find--------" << std::endl;
    it = y.find(3);
    ft_print_pair(*it);
    it = y.find(-5555);
    ft_print_pair(*it);

    // count:
    std::cout << "--------count--------" << std::endl;
    std::cout << y.count(2) << std::endl;

    // lower_bound:
    std::cout << "--------lower_bound--------" << std::endl;
    it = y.lower_bound(3);
    ft_print_pair(*it);

    // upper_bound:
    std::cout << "--------upper_bound--------" << std::endl;
    it = y.upper_bound(1);
    ft_print_pair(*it);

    // equal_range:
    std::cout << "--------equal_range--------" << std::endl;
    ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> p2;
    p2 = y.equal_range(3);

    std::cout << "lower bound points to: ";
    std::cout << p2.first->first << " => " << p2.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << p2.second->first << " => " << p2.second->second << '\n';

    // Loop
    // iter++:
    std::cout << "--------iter++--------" << std::endl;
    it = y.begin();
    for (; it != y.end(); it++)
        std::cout << it->first  << std::endl;
    // iter--:
    std::cout << "--------iter(--)--------" << std::endl;
    it = y.end();
    for (; it != y.begin(); it--)
        std::cout << it->first  << std::endl;
    std::cout << it->first  << std::endl;

    //reverse_iter++
    std::cout << "--------reverse_iter++--------" << std::endl;
    ft::map<int, int>::reverse_iterator rit;
    rit = y.rbegin();
    for (; rit != y.rend(); rit++)
        std::cout << rit->first  << std::endl;
    //reverse_iter--
    std::cout << "--------reverse_iter(--)--------" << std::endl;
    rit = y.rend();
    for (; rit != y.rbegin(); rit--)
        std::cout << rit->first  << std::endl;
    std::cout << rit->first  << std::endl;
}