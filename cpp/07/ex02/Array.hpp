/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:07:59 by daypark           #+#    #+#             */
/*   Updated: 2022/05/31 23:51:40 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    unsigned int size_;
    T *arr_;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &array);
    ~Array();
    Array &operator=(const Array &array);
    T &operator[](unsigned int idx);
    const T &operator[](unsigned int idx) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
        const char *what() const throw();
    };
};

template <typename T>
Array<T>::Array() {
    size_ = 0;
    arr_ = new T[size_];
}

template <typename T>
Array<T>::Array(unsigned int n) {
    size_ = n;
    arr_ = new T[size_];
}

template <typename T>
Array<T>::Array(const Array<T> &array) {
    arr_ = NULL;
    *this = array;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr_;
    arr_ = NULL;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &array) {
    if (&array != this)
    {
        size_ = array.size_;
        if (arr_)
            delete[] arr_;
        arr_ = new T[array.size_];
        for (int i = 0; i < array.size_; i++) {
            arr_[i] = array.arr_[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) {
    if (idx < 0 || idx >= size_)
        throw OutOfBoundsException();
    return arr_[idx];
}

template <typename T>
const T &Array<T>::operator[](unsigned int idx) const {
    if (idx < 0 || idx >= size_)
        throw OutOfBoundsException();
    return arr_[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

template <typename T>
std::ostream &operator<<(std::ostream &outputStream, const Array<T> &array)
{
	if (array.size()) {
		for (unsigned int i = 0; i < array.size(); i++)
			outputStream << array[i] << " ";
	}
	return outputStream;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Exception: Out Of Bounds";
}

#endif