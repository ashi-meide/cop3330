#ifndef _STACK_HPP
#define _STACK_HPP

#include <string>
#include "Stack.h"

// Private

template <typename T>
void Stack<T>::resize() {
	T* new_array = new T[array_capacity * 2];

	// Copy elements
	for (int i = 0; i < array_capacity; i++)
		new_array[i] = array[i];

	// Replace existing array
	delete[] array;
	array_capacity *= 2;
	array = new_array;
}

// Public

template <typename T>
Stack<T>::Stack(int n) : stack_size(0), array_capacity(n), array(new T[n]) {}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
	: stack_size(other.stack_size),
	  array_capacity(other.array_capacity),
	  array(new T[other.array_capacity]) {
	// Copy elements
	for (int i = 0; i < array_capacity; i++)
		array[i] = other.array[i];
}

template <typename T>
Stack<T>::~Stack() {
	delete[] array;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	// Self-assignment guard
	if (this == &other) {
		return *this;
	}

	stack_size = other.stack_size;
	array_capacity = other.array_capacity;

	// Replace existing array
	delete[] array;
	array = new T[array_capacity];

	// Copy elements
	for (int i = 0; i < array_capacity; i++)
		array[i] = other.array[i];
}

template <typename T>
bool Stack<T>::empty() const {
	return stack_size == 0;
}

template <typename T>
T Stack<T>::top() const {
	return array[stack_size - 1];
}

template <typename T>
void Stack<T>::push(const T& item) {
	// Resize if necessary
	if (stack_size == array_capacity)
		resize();

	// Insert and increment
	array[stack_size++] = item;
}

template <typename T>
T Stack<T>::pop() {
	return array[--stack_size];	 // Shrink stack logically and return last item
}

#endif
