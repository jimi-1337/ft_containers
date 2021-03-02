/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:02:26 by amoujane          #+#    #+#             */
/*   Updated: 2021/02/28 15:15:16 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List/List.hpp"
#include "iterators/listiterator.hpp"
#include <iostream>
#include <list>
#include <cmath>
#include "vector/Vector.hpp"

#include <list>

void print_list(ft::list<int> a)
{
    ft::list<int>::iterator it = a.begin();
    while (it != a.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

void print_list_c(ft::list<std::string> a)
{
    ft::list<std::string>::iterator it = a.begin();
    while (it != a.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

bool mycomparison (double first, double second)
{ return ( int(first) > int(second) ); }

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

int main()
{
    ft::list<int> x;
    ft::list<int> y(5, 10);
    ft::list<int> z(y.begin(), y.end());
    ft::list<int> z1(z);
    ft::list<int> t;
    ft::list<int> i;

    std::cout << "Begin" << std::endl;
    std::cout << *x.begin() << std::endl;
    std::cout << *y.begin() << std::endl;
    std::cout << *z.begin() << std::endl;
    std::cout << *z1.begin() << std::endl;

    // end
    std::cout << "\nEnd" << std::endl;
    std::cout << *x.end() << std::endl;
    std::cout << *y.end() << std::endl;
    std::cout << *z.end() << std::endl;
    std::cout << *z1.end() << std::endl;

    // rbegin
    std::cout << "\nrBegin" << std::endl;
    std::cout << *x.rbegin() << std::endl;
    std::cout << *y.rbegin() << std::endl;
    std::cout << *z.rbegin() << std::endl;
    std::cout << *z1.rbegin() << std::endl;

    // rend
    std::cout << "\nrend" << std::endl;
    std::cout << *x.rend() << std::endl;
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
    std::cout << x.front() << std::endl;
    std::cout << y.front() << std::endl;
    std::cout << z.front() << std::endl;
    std::cout << z1.front() << std::endl;

    // back
    std::cout << "\nback" << std::endl;
    std::cout << x.back() << std::endl;
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

    // pusH_front
    //push_back
    std::cout << "\npush_front, push_back, front and back" << std::endl;
    y.push_front(-1);
    y.push_back(-22222);
    std::cout << "front: " << y.front() << "  back:" << y.back() << std::endl;

    //pop_front
    //pop_back
    std::cout << "\npop" << std::endl;
    y.pop_front();
    y.pop_back();
    std::cout << "front: " << y.front() << "  back:" << y.back() << std::endl;


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
    x.push_back(1);
    x.push_back(2);
    x.push_front(3);
    x.push_front(4);
    ft::list<int>::iterator it = x.begin();
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

    //merge
    std::cout << "\nmerge" << std::endl;
    i.push_back(5);
    i.push_back(4);
    i.push_back(3);

    t.push_back(4);
    t.push_back(1);
    
    t.merge(i, mycomparison);
    std::cout << "-----list t------" << std::endl;
    print_list(t);
    std::cout << "------size-------" << std::endl;
    std::cout << i.size() << std::endl;
    std::cout << t.size() << std::endl;
    //splice
    std::cout << "\nsplice" << std::endl;
    ft::list<int> mylist1, mylist2;
    // ft::list<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4

    for (int i=1; i<=3; ++i)
        mylist2.push_back(i*10);   // mylist2: 10 20 30

    it = mylist1.begin();
    ++it;                         // points to 2

    mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
                                          
    mylist2.splice (mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
    it = mylist1.begin();
    ft::advance(it, 3);         // "it" points now to 30

    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());// mylist1: 30 3 4 1 10 20

    std::cout << "mylist1 contains:";
    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "mylist2 contains:";
    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    //remove
    std::cout << "\nremove" << std::endl;
    mylist1.push_back(30);
    mylist1.push_back(11);
    std::cout << "------size-------" << std::endl;
    std::cout << mylist1.size() << std::endl;
    std::cout << "-----list 1------" << std::endl;
    mylist1.remove(30);
    print_list(mylist1);
    std::cout << "------size-------" << std::endl;
    std::cout << mylist1.size() << std::endl;
    
    //remove_if
    std::cout << "\nremove_if" << std::endl;
    mylist1.remove_if (single_digit);           // 10 20 11
    std::cout << "-----list 1------" << std::endl;
    print_list(mylist1);
    std::cout << "------size-------" << std::endl;
    std::cout << mylist1.size() << std::endl;
    mylist1.remove_if (is_odd());               // 10 20
    std::cout << "-----list 1------" << std::endl;
    print_list(mylist1);
    std::cout << "------size-------" << std::endl;
    std::cout << mylist1.size() << std::endl;
    
    //unique
    std::cout << "\nunique" << std::endl;
    x.clear();
    x.push_back(1);
    x.push_back(1);
    x.push_back(2);
    x.push_back(2);
    x.push_back(1);
    x.push_back(2);
    x.unique();
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    x.unique(same_integral_part);               // 1 2 1 2
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    x.unique (is_near());                       // 1
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "------size-------" << std::endl;
    std::cout << x.size() << std::endl;

    //sort
    std::cout << "\nsort" << std::endl;
    x.clear();
    x.push_back(1);
    x.push_back(3);
    x.push_back(0);
    x.push_back(2);
    x.push_back(1);
    x.push_back(2);
    x.sort();
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    ft::list<std::string> c;
    c.push_back("one");
    c.push_back("two");
    c.push_back("Three");
    c.sort();
    std::cout << "-----list c------" << std::endl;
    print_list_c(c);
    c.sort(compare_nocase);
    std::cout << "-----list c------" << std::endl;
    print_list_c(c);
    
    //reverse
    std::cout << "\nreverse" << std::endl;
    x.reverse();
    std::cout << "-----list x------" << std::endl;
    print_list(x);

    std::cout << "---------------------------\n" << std::endl;
    
	ft::list<std::string> myList(5, "hats");
	ft::list<std::string> otherList(5, "hats");

	if (myList == otherList)
		std::cout << "\tmylist == otherlist" << std::endl;
	else
		std::cout << "NOT\tmylist == otherlist" << std::endl;

	if (myList != otherList)
		std::cout << "\tmylist != otherlist" << std::endl;
	else
		std::cout << "NOT\tmylist != otherlist" << std::endl;

	if (myList < otherList)
		std::cout << "\tmylist < otherlist" << std::endl;
	else
		std::cout << "NOT\tmylist < otherlist" << std::endl;

	if (myList > otherList)
		std::cout << "\tmylist > otherlist" << std::endl;
	else
		std::cout << "NOT\tmylist > otherlist" << std::endl;

	if (myList >= otherList)
		std::cout << "\tmylist >= otherlist" << std::endl;
	else
		std::cout << "NOT\tmylist >= otherlist" << std::endl;
	if (myList <= otherList)
		std::cout << "\tmylist <= otherlist" << std::endl;
	else
		std::cout << "NOT\tmylist <= otherlist" << std::endl;
    return (0);
}
// int main()
// {
//     return (0);
// }