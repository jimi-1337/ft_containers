/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:31:00 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/18 17:37:40 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/Map.hpp"
#include "map/MapNode.hpp"
#include <iostream>
#include <map>
#include <cmath>

int main()
{
    ft::map<int, int> myList;
	ft::map<int, int> otherList;

    // ft::map<int, int> a;
    // // ft::map<int, int>::const_iterator it;
    // // ft::map<int, int>::const_iterator itc;
    // // // std::map<int, int>::iterator itm;
    // std::map<int, int> b;
    // // // std::map<int,int>::key_compare mycomp = a.key_comp();
    // // // ft::map<int, int>::const_iterator cit;
    
    // std::cout << a.max_size() << std::endl;
    // std::cout << b.max_size() << std::endl;
    // a.insert(std::pair<int, int>(1, 1));
    // a.insert(std::pair<int, int>(4, 1));
    // a.insert(std::pair<int, int>(2, 4));
    // a.insert(std::pair<int, int>(4, 6));
    // a.insert(std::pair<int, int>(3, 9));
    // a.insert(std::pair<int, int>(2, -5));
    // ft::map<int, int> y(a.begin(), a.end());
    // b.insert(std::pair<int, int>(1, 1));
    // b.insert(std::pair<int, int>(4, 1));
    // b.insert(std::pair<int, int>(2, 4));
    // b.insert(std::pair<int, int>(4, 6));
    // b.insert(std::pair<int, int>(3, 9));
    // b.insert(std::pair<int, int>(2, -5));
    // // it = b.end();
    // // a.insert(it, std::pair<int, int>(5, 1));
    // // std::cout << it->second << std::endl;
    // // std::cout << it->second << std::endl;
    // // // std::cout << it << std::endl;
    // // std::cout << a.size() << std::endl;
    // // printf("---------\n");
    // // std::cout << a[6] << std::endl;
    // // it = a.begin();
    // // std::cout << it->first << "\t" << it->second << std::endl;
    // // it = a.end();
    // // std::cout << it->first << "\t" << it->second << std::endl;
    // // b.insert(std::pair<int, int>(10, 10));
    // // b.insert(std::pair<int, int>(9, 9));
    // // b.insert(a.begin(), a.end());
    // // it  = b.begin();
    // // it++;
    // // it++;
    // // b.erase(it, b.end());
    // // b.swap(a);
    // // it  = a.begin();
    // // // int i = 0;
    // // b.clear();
    // // std::cout << b.size() << std::endl;
    // // b.insert(std::pair<int, int>(1, 10));
    // // it = a.begin();
    // // // std::cout << mycomp(6, 2) << std::endl;
    // // // std::cout << a.value_comp()(std::pair<int, int>(100, 10),std::pair<int, int>(10, 10)) << std::endl;
    // // // // cit = b.find(4);
    // // // it = a.upper_bound(3);
    // // // std::cout << it->first << std::endl;

    // // std::cout << a.equal_range(3).first->first << a.equal_range(3).second->first << std::endl;
    // it = y.cbegin();
    // int i = 0;
    // itc = a.upper_bound(3);
    // std::cout << b.max_size() << std::endl;
    // // it--;
    // // std::cout << it->first << std::endl;
    // while(it != y.cend())
    // {
    //     printf("-----------\n");
    //     std::cout << it->first << "\t" << it->second << std::endl;
    //     it++;
    //     i++;
    // }
}