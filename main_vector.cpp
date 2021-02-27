/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:46:20 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/18 16:50:19 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators/listiterator.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include "vector/Vector.hpp"

int main()
{
    ft::vector<int> b;
    std::vector<int> a;

    std::cout << a.max_size() << std::endl;
    std::cout << b.max_size() << std::endl;
    // ft::vector<int> first,second;
    // ft::vector<int>::iterator it;
    // ft::vector<int>::iterator x;
    // ft::vector<int>::iterator y;

    
    // first.push_back(1);
    // first.push_back(2);
    // first.push_back(3);
    // first.push_back(4);

    // second.push_back(5);
    // second.push_back(6);
    // second.push_back(7);
    // second.push_back(8);
    // second.push_back(9);
    // it = first.begin();
    
    // // it = it + 2;
    // it = 2 + it;
    // std::cout << *it << std::endl;
    // it++;
    // first.insert(it, second.begin(), second.end());
    // // first.reserve(10);
    // std::cout << first.capacity() << std::endl;
    // it = first.begin();
    // while(it != first.end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }
}