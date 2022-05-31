/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:01:07 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 04:41:06 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>
#include <list>
#include <iostream>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
    
    MutantStack() {}
    MutantStack(const MutantStack &mutantStack) { *this = mutantStack; }
    ~MutantStack() {}
    MutantStack &operator=(const MutantStack &mutantStack) {
        if (this != &mutantStack) {
            std::stack<T>::operator=(mutantStack);
        }
        return *this;
    }

    iterator begin(void) {
        return this->c.begin();
    }

    const_iterator begin(void) const {
        return this->c.begin();
    }

    iterator end(void) {
        return this->c.end();
    }

    const_iterator end(void) const {
        return this->c.end();
    }

    reverse_iterator rbegin(void) {
        return this->c.rbegin();
    }

    const_reverse_iterator rbegin(void) const {
        return this->c.rbegin();
    }

    reverse_iterator rend(void) {
        return this->c.rend();
    }

    const_reverse_iterator rend(void) const {
        return this->c.rend();
    }
};