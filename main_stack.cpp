/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:00:40 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/18 16:03:07 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.hpp"
#include <stack>
#include <iostream>

int main()
{
    std::stack<int> a;
    std::stack<int> b;
    ft::stack<int> x;
    ft::stack<int> y;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);

    b.push(1);
    b.push(2);
    b.push(3);
    b.push(1); 
    b.push(5);

    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);

    y.push(1);
    y.push(2);
    y.push(3);
    y.push(1);
    y.push(5);


    std::cout << (b > a) << (b < a) << (b == a) << (b >= a) << (b <= a) << std::endl;
    // if (b > a)
    //     std::cout << "dsds" << std::endl;
    // // std::cout << a.size() << std::endl;
    // std::cout << a.empty() << std::endl;
    // int i = 0;
    // while(a.size())
    // {
    //     std::cout << a.top() << std::endl;
    //     a.pop();
    // }
    // std::cout << a.empty() << std::endl;
    // // std::cout << a.size() << std::endl;
}