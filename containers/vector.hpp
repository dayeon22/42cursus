#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft{
	
	template < class T, class Alloc = std::allocator<T> > class vector{
		public:
			typedef T					value_type;
			typedef Alloc				allocator_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;
			// iterator;
			// const_iterator;
			// reverse_iterator;
			// const_reverse_iterator;
			typedef std::ptrdiff_t		difference_type;
			typedef std::size_t			size_type;

		private:
			pointer			_start;
			size_type		_size;
			size_type		_capacity;
			//allocator_type	_alloc;  // 멤버변수 _alloc 없애고 인자로 받은 alloc 이용해 함수안에서 할당해 넣는것 생각해보기!



		public:
			// =============== (CONSTRUCTOR) ===============
			// https://legacy.cplusplus.com/reference/vector/vector/vector/

			// default(1)
			explicit vector (const allocator_type& alloc = allocator_type()) {
				_start = 0;
				_size = 0;
				_capacity = 0;
			}

			// fill(2)
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) {
				_start = alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (int i = 0; i < n; i++) {
					alloc.construct(_start + i, val);
				}
			}

			// range(3)
			template <class InputIterator>
				vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) {  // SFINAE
				if (first > last)
					throw std::length_error("vector - constructor");
				_size = last - first;  // TODO: iterator간의 빼기연산하면 어떻게되는지, std::ptrdiff_t 알아보기!
				_capacity = _size;
				_start = alloc.allocate(_size);
				for (int i = 0; i < _size; i++) {
					alloc.construct(_start + i, *(first + i));
				}
			}

			// copy(4)
			vector (const vector& x) {

			}


			// =============== (DESTRUCTOR) ===============
			// https://legacy.cplusplus.com/reference/vector/vector/~vector/
			~vector() {

			}


			// =============== OPERATOR= ===============
			// https://legacy.cplusplus.com/reference/vector/vector/operator=/
			vector& operator= (const vector& x) {
				
			}
	};

}

#endif
