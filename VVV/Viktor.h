#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include <initializer_list>
#include <cstddef>
#include <string>
#include <stdexcept>


template <typename T>

class Viktor {
public:
	std::unique_ptr<unsigned char[]> m_buffer;
	T* m_nextElement=nullptr;
	std::size_t m_numberOfElements=0;
	std::size_t m_capacity=0;


	
	Viktor();
	Viktor(const std::initializer_list<T>& list);
	~Viktor();
	
	Viktor(const Viktor& other);



	void memoryAddress(int indexOfElement); // tmp
	void destructElement(int indexOfElement); // tmp
	void printElements(); // tmp


	T& operator[](const int index);
	const T& operator[](const int index) const;
	T& at(int index);
	


	Viktor<T>& operator=(const Viktor& other);
	Viktor<T>& operator=(Viktor&& other);
	Viktor<T>& operator=(std::initializer_list<T> ilist);
};
//m_nextElement=(T*)m_buffer.get();



template <typename T>
Viktor<T>::Viktor() 
{
	m_numberOfElements = 3;
	m_capacity = 5;
	m_buffer = std::make_unique<unsigned char[]>(m_capacity*sizeof(T));
	m_nextElement =reinterpret_cast<T*>(m_buffer.get());

}

template <typename T>
Viktor<T>::Viktor(const std::initializer_list<T>& list):
	m_numberOfElements(list.size()), m_capacity(list.size()+2)
{
	m_buffer = std::make_unique<unsigned char[]>(m_capacity * sizeof(T));
	m_nextElement = reinterpret_cast<T*>(m_buffer.get());
	
	for (auto& element : list)
	{
		new(m_nextElement) T(element);
		m_nextElement ++;



	}



}

template <typename T>
Viktor<T>::~Viktor() {

	
	for (int i = 0; i < m_numberOfElements; i++)
	{
		((reinterpret_cast<T*>(m_buffer.get())) + i)->~T();

	}
}

template <typename T>
Viktor<T>::Viktor(const Viktor& other):
	m_capacity(other.m_capacity), m_numberOfElements(other.m_numberOfElements)
{

	
	//std::cout << "Copy constructor is working(const Viktor& other)" << std::endl;
	//
	//std::cout << "this: " << this << std::endl;
	//std::cout << "other: " << &other << std::endl;

	m_buffer = std::make_unique<unsigned char[]>(m_capacity * sizeof(T));
	m_nextElement = reinterpret_cast<T*>(m_buffer.get());

	for (std::size_t iii = 0; iii < m_numberOfElements; iii++)
	{
		*m_nextElement = other[iii];
		m_nextElement++;

	}

	

}




template <typename T>
void Viktor<T>::memoryAddress(int indexOfElement) {

	std::cout << "Adress of element #" << indexOfElement << ": " << static_cast<void*>(m_buffer.get() + (sizeof(T) * indexOfElement)) << std::endl;


}


template <typename T>
T &Viktor<T>::operator[](const int index) {

	assert(index < m_numberOfElements && "out of range");
	return *(reinterpret_cast<T*>(m_buffer.get()) + index);
}

template<typename T>
const T& Viktor<T>::operator[](const int index) const {
	assert(index < m_numberOfElements && "out of range");
	return *(reinterpret_cast<T*>(m_buffer.get()) + index);

}

template<typename T>
Viktor<T> &Viktor<T>::operator=(const Viktor &other){

	assert(this = *other && "attempt to selfcopy");										//change to if->return *this.
	m_numberOfElements = other.m_numberOfElements;
	m_capacity = other.m_capacity;
	m_buffer.reset();																	//change to reset(std::make_uniue?)
	m_buffer = std::make_unique<unsigned char[]>(m_capacity * sizeof(T));				//change to reset(std::make_uniue?)
	m_nextElement = reinterpret_cast<T*>(m_buffer.get());

	for (std::size_t i = 0; i < m_numberOfElements; i++)
	{
		*m_nextElement = other[i];
		m_nextElement++;

	}



}

template<typename T>
Viktor<T> &Viktor<T>::operator=(Viktor&& other){
	std::cout << "move assignment operator is working" << std::endl;
	m_numberOfElements = other.m_numberOfElements;
	m_capacity = other.m_capacity;
	m_buffer = std::move(other.m_buffer);							//delete other.m_nextElement?
	m_nextElement = other.m_nextElement;
	return *this;
}

template<typename T>
Viktor<T> &Viktor<T>::operator=(std::initializer_list<T> ilist){
	m_numberOfElements = ilist.size();
	m_capacity = m_numberOfElements + 2;
	m_buffer.reset();
	m_buffer = std::make_unique<unsigned char[]>(m_capacity * sizeof(T));
	m_nextElement = reinterpret_cast<T*>(m_buffer.get());

	for (auto& element : ilist)
	{
		new(m_nextElement) T(element);
		m_nextElement++;



	}
	return *this;
}\

template<typename T>
T& Viktor<T>::at(int index) {

	if (index>=m_numberOfElements)
	{
		throw std::out_of_range("wrong vector subscript");
	}
	return (*this)[index];
}


template <typename T>
void Viktor<T>::destructElement(int indexOfElement) {

	((reinterpret_cast<T*>(m_buffer.get())) + indexOfElement)->~T();

}

template <typename T>
 void Viktor<T>::printElements() {

	for (int i = 0; i < m_numberOfElements; i++)
	{
		std::cout << "Element #" << i << " " << (*this)[i] << std::endl;
		


	}


}

//A
//B
//C
//
//A aa;
//B bb;
//A* ptr1 = &bb;
//A* ptr2 = &aa;
//
//
//dynamic_cast<B*> prt; // превращает поинтор на родителя в поинтор на ребёнка
//dynamic_cast<B*> ptr2;