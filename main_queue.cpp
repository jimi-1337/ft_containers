/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:24:32 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/18 16:38:45 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue/queue.hpp"
#include <queue>

int main()
{
    ft::queue<int> a;
    ft::queue<int> b;
    std::queue<int> y;
    std::queue<int> x;

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(5);

    b.push(1);
    b.push(2);
    b.push(3);
    b.push(5);
    b.push(1);

    x.push(1);
    x.push(2);
    x.push(3);
    x.push(5);

    y.push(1);
    y.push(2);
    y.push(3);
    y.push(5);
    y.push(1);

    std::cout << (y > x) << (y < x) << (y == x) << (y >= x) << (y <= x) << std::endl;
    std::cout << (b > a) << (b < a) << (b == a) << (b >= a) << (b <= a) << std::endl;

    // std::cout << a.empty() << std::endl;
    // while(a.size())
    // {
    //     std::cout << a.front() << std::endl;
    //     a.pop();
    // }
    // std::cout << a.empty() << std::endl;
}