/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:00:40 by amoujane          #+#    #+#             */
/*   Updated: 2021/03/01 15:41:55 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.hpp"
#include <stack>
#include <iostream>

void print_stack(ft::stack<int> a)
{
    while(a.size())
    {
        std::cout << a.top() << std::endl;
        a.pop();
    }
}

int main()
{
	{
		ft::stack<int> MyStack;
        std::cout << "\n empty and size" << std::endl;
		std::cout << MyStack.empty() << std::endl;
		std::cout << MyStack.size() << std::endl;
	}
	std::cout << std::endl;
	{
		ft::stack<int> MyStack;
        std::cout << "\n push" << std::endl;
		MyStack.push(88);
		std::cout << MyStack.empty() << std::endl;
		MyStack.push(44);
        std::cout << "--------stack Mystack--------" << std::endl;
        print_stack(MyStack);
        std::cout << "\n top" << std::endl;
		std::cout << MyStack.top() << std::endl;
		std::cout << MyStack.size() << std::endl;
        std::cout << "\n pop" << std::endl;
		MyStack.pop();
		std::cout << MyStack.size() << std::endl;
		std::cout << MyStack.top() << std::endl;
		MyStack.pop();
		std::cout << MyStack.size() << std::endl;
	}
    std::cout << std::endl;
	{
        std::cout << "--------relational operators--------" << std::endl;
		ft::stack<int> MyStack1;
		ft::stack<int> MyStack2;

		MyStack1.push(100);
		MyStack1.push(44);

		MyStack2.push(100);
		MyStack2.push(44);

		if (MyStack1 == MyStack2)
			std::cout << "MyStack1 is equal to MyStack2" << std::endl;
		if (MyStack1 < MyStack2)
			std::cout << "MyStack1 is smaller than MyStack2" << std::endl;
		if (MyStack1 <= MyStack2)
			std::cout << "MyStack1 is smaller than or equal to MyStack2" << std::endl;
		if (MyStack1 > MyStack2)
			std::cout << "MyStack1 is larger than MyStack2" << std::endl;
		if (MyStack1 >= MyStack2)
			std::cout << "MyStack1 is larger than or equal to MyStack2" << std::endl;
	}
}