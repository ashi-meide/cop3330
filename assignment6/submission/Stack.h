#ifndef _STACK_H
#define _STACK_H

template <typename T>
class Stack {
   private:
	int stack_size;
	int array_capacity;
	T* array;
	void resize();

   public:
	Stack(int n = 10);
	Stack(const Stack<T>& other);  // Copy constructor
	~Stack();
	Stack<T>& operator=(const Stack<T>& other); // Copy assignment
	bool empty() const;
	T top() const;
	void push(const T& item);
	T pop();
};

#include "Stack.hpp"
#endif
