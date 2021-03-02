/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:24:32 by amoujane          #+#    #+#             */
/*   Updated: 2021/03/01 15:50:33 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue/queue.hpp"
#include <queue>

void print_queue(ft::queue<int> a)
{
    while(a.size())
    {
        std::cout << a.front() << std::endl;
        a.pop();
    }
}

int main()
{
	{
		ft::queue<int> MyQueue;
        std::cout << "\n empty and size" << std::endl;
		std::cout << MyQueue.empty() << std::endl;
		std::cout << MyQueue.size() << std::endl;
	}
	std::cout << std::endl;
	{
		ft::queue<int> MyQueue;
        std::cout << "\n push" << std::endl;
		MyQueue.push(88);
		std::cout << MyQueue.empty() << std::endl;
		MyQueue.push(44);
		std::cout << MyQueue.size() << std::endl;
        std::cout << "--------stack Mystack--------" << std::endl;
        print_queue(MyQueue);
        std::cout << "\n back" << std::endl;
		std::cout << MyQueue.back() << std::endl;
        std::cout << "\n pop" << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.back() << std::endl;
		std::cout << MyQueue.size() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.back() << std::endl;
		std::cout << MyQueue.size() << std::endl;
	}
	std::cout << std::endl;
	{
		ft::queue<int> MyQueue;
		std::cout << MyQueue.empty() << std::endl;
		MyQueue.push(88);
        std::cout << "\n front" << std::endl;
		std::cout << MyQueue.front() << std::endl;
		MyQueue.push(44);
		std::cout << MyQueue.front() << std::endl;
		std::cout << MyQueue.size() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.size() << std::endl;
		std::cout << MyQueue.front() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.size() << std::endl;
	}
    std::cout << std::endl;
	{
		ft::queue<int> MyQueue1;
		ft::queue<int> MyQueue2;

		MyQueue1.push(100);
		MyQueue1.push(44);

		MyQueue2.push(100);
		MyQueue2.push(44);

		if (MyQueue1 == MyQueue2)
			std::cout << "MyQueue1 is equal to MyQueue2" << std::endl;
		if (MyQueue1 < MyQueue2)
			std::cout << "MyQueue1 is smaller than MyQueue2" << std::endl;
		if (MyQueue1 <= MyQueue2)
			std::cout << "MyQueue1 is smaller than or equal to MyQueue2" << std::endl;
		if (MyQueue1 > MyQueue2)
			std::cout << "MyQueue1 is larger than MyQueue2" << std::endl;
		if (MyQueue1 >= MyQueue2)
			std::cout << "MyQueue1 is larger than or equal to MyQueue2" << std::endl;
	}
}