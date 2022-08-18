#pragma once
#include <iterator>
#include <memory>




template<class Iter>
class reverse_iterator : public std::iterator<typename std::iterator_traits<Iter>::iterator_category, typename std::iterator_traits<Iter>::value_type, typename std::iterator_traits<Iter>::difference_type, typename std::iterator_traits<Iter>::pointer, typename std::iterator_traits<Iter>::reference>
{
public:

	using iterator_type = Iter;

	reverse_iterator();
	reverse_iterator(iterator_type x) :
		current(x) {}

	template<class U>
	reverse_iterator(const reverse_iterator<U>& other) :
		current(other.current) {
	};

	template<class U>
	reverse_iterator& operator=(const reverse_iterator<U>& other) { current = other.current; };


	iterator_type base() const
	{
		return current;
	}

	typename Iter::reference operator*() const
	{
		Iter tmp = current;
		return *--tmp;
	}

	typename Iter::pointer operator->() const
	{
		return &(operator*());
	}

	typename Iter::reference operator[](typename Iter::difference_type n) { return base()[-n - 1]; }

	reverse_iterator& operator++()
	{
		--current;
		return *this;
	}

	reverse_iterator& operator--()
	{
		++current;
		return *this;
	}

	reverse_iterator operator++(int)
	{
		reverse_iterator tmp = *this;
		--current;
		return tmp;
	}

	reverse_iterator operator--(int)
	{
		reverse_iterator tmp = *this;
		++current;
		return tmp;
	}

	reverse_iterator operator+(typename Iter::difference_type n)
	{
		return (this->base() - n);


	}

	reverse_iterator operator-(typename Iter::difference_type n)
	{
		return (this->base + n);
	}

	reverse_iterator operator+=(typename Iter::difference_type n)
	{
		if (n>=0)
			while (n--)
			{
				--(*this);
			}
		else
		{
			while (n++)
			{
				++(*this);
			}
		}
		return *this;
	}

	reverse_iterator operator -=(typename Iter::difference_type n)
	{
		return *(this) += -n;
	};

	template<class Iterator1, class Iterator2>
	friend bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);

	template<class Iterator1, class Iterator2>
	friend bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
	
	template<class Iterator1, class Iterator2>
	friend bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
	
	template<class Iterator1, class Iterator2>
	friend bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
	

	template<class Iterator1, class Iterator2>
	friend bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
	

	template<class Iterator1, class Iterator2>
	friend bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
	
	friend reverse_iterator operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it) {
		return reverse_iterator<Iter>(it.base() - n);

	}

	friend reverse_iterator operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
	{
		return reverse_iterator<Iter>(it.base() + n);
	}

	template<class Iter>
	reverse_iterator<Iter> make_reserve_iterator(Iter i)
	{
		return reverse_iterator<Iter>(i);

	}

protected:
	iterator_type current;

};

template<class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() == rhs.base();

};

template<class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() != rhs.base();
};

template<class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() > rhs.base();
}

template<class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() >= rhs.base();
}

template<class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() < rhs.base();
}

template<class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return lhs.base() <= rhs.base();
}

