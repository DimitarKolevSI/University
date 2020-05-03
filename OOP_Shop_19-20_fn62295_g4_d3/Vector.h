#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Vector
{
private:
	T* elements = nullptr;
	int size;
	int maxSize;
	void resize();
	void shrink();
	void setSize(const int size);
	void setMaxSize(const int maxSize);
	void copy(T* source, T* destination, const int size);
public:
	Vector();
	Vector(const int maxSize);
	Vector(const Vector<T>& copy);
	const Vector<T>& operator=(const Vector<T>& copy);

	const int getSize() const;
	const int getMaxSize() const;

	void add(const T element);
	void removeWithIndex(const int index);
	void remove(const T& element);
	const bool isEmpty() const;
	void empty();
	void print() const;
	T getAt(const int index) const;

	~Vector();
};

template<typename T>
inline void Vector<T>::resize()
{
	this->maxSize *= 2;
	T* temp = new T[maxSize];
	copy(elements, temp, size);
	delete[] elements;
	elements = temp;
}

template<typename T>
inline void Vector<T>::shrink()
{
	this->maxSize /= 2;
	T* temp = new T[maxSize];
	copy(elements, temp, size);
	delete[] elements;
	elements = temp;
}

template<typename T>
inline void Vector<T>::setSize(const int size)
{
	this->size = size;
}

template<typename T>
inline void Vector<T>::setMaxSize(const int maxSize)
{
	this->maxSize = maxSize;
}

template<typename T>
inline void Vector<T>::copy(T * source, T * destination, const int size)
{
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}

template<typename T>
inline Vector<T>::Vector()
{
	setSize(0);
	setMaxSize(6);
	this->elements = new T[this->maxSize];
}

template<typename T>
inline Vector<T>::Vector(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->elements = new T[this->maxSize];
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& copyObject)
{
	setSize(copyObject.getSize());
	setMaxSize(copyObject.getMaxSize());
	this->elements = new T[this->maxSize];
	copy(copyObject.elements, this->elements, copyObject.getSize());
}

template<typename T>
inline const Vector<T>& Vector<T>::operator=(const Vector<T>& copyObject)
{
	if (this != &copyObject) 
	{
		if (this->elements != nullptr) delete[] elements;
		setSize(copyObject.getSize());
		setMaxSize(copyObject.getMaxSize());
		this->elements = new T[this->maxSize];
		copy(copyObject.elements, this->elements, copyObject.getSize());
	}

	return *this;
}

template<typename T>
inline const int Vector<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline const int Vector<T>::getMaxSize() const
{
	return this->maxSize;
}

template<typename T>
inline void Vector<T>::add(const T element)
{
	if (this->size == this->maxSize) resize();
	elements[size] = element;
	size++;
}

template<typename T>
inline void Vector<T>::removeWithIndex(const int index)
{
	if (isEmpty())
	{
		cout << "The vector is empty cannot remove!\n";
	}
	else if (index < 0 || index >= this->size)
	{
		cout << "Invalid index!\n";
	}
	else
	{
		for (int i = index; i < this->size - 1; i++) {
			this->elements[i] = this->elements[i + 1];
		}
		this->size--;
		if (this->maxSize >= this->size * 4) shrink();
	}
}

template<typename T>
inline void Vector<T>::remove(const T& element)
{
	for (int i = 0; i < this->size; i++)
	{
		if (elements[i] == element)
		{
			removeWithIndex(i);
			break;
		}
	}
}

template<typename T>
inline void Vector<T>::empty()
{
	if (elements != nullptr) delete[] elements;
	setSize(0);
	setMaxSize(6);
	elements = new T[maxSize];
}

template<typename T>
inline void Vector<T>::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		cout << elements[i];
	}
}

template<typename T>
inline const bool Vector<T>::isEmpty() const
{
	return this->size==0;
}

template<typename T>
inline T Vector<T>::getAt(const int index) const
{
	if (index < 0 || index >= this->size)
	{
		cout << "Invalid index!\n";
		return T();
	}
	return elements[index];
}

template<typename T>
inline Vector<T>::~Vector()
{
	if (elements != nullptr)
	{
		delete[] elements;
		elements = nullptr;
	}
}
