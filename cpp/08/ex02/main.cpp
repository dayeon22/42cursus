/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:14:23 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 04:41:08 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }

    std::stack<int> s(mstack);

    std::cout << std::endl << "====================" << std::endl;

    std::list<int> li;
    li.push_back(5);
    li.push_back(17);
    std::cout << li.back() << std::endl;
    li.pop_back();
    std::cout << li.size() << std::endl;
    li.push_back(3);
    li.push_back(5);
    li.push_back(737);
    li.push_back(0);
    std::list<int>::iterator it1 = li.begin();
    std::list<int>::iterator ite1 = li.end();
    ++it1;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << " ";
        ++it1;
    }
    std::cout << std::endl;
    std::list<int>::reverse_iterator rit1 = li.rbegin();
    std::list<int>::reverse_iterator rite1 = li.rend();
    while (rit1 != rite1)
    {
        std::cout << *rit1 << " ";
        ++rit1;
    }

    std::list<int> s1(li);
    
    return 0;
}
