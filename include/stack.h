// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

#ifndef __STACK_H__

#define __STACK_H__

#include <iostream>

using namespace std;

template <class T>

class TStack
{
private:
	T* stack;
	int head, size;
  
public:
	TStack()
	{
		stack = new T[100];
		head = 0;
		size = 100;
	}

	TStack(int n)
	{
		if (n < 0)
			throw "incorrect stack size";
		stack = new T[n];
		head = 0; 
		size = n;
	}

	TStack(const TStack& a)
	{
		size = a.size;
		head = a.head;
		stack = new T[size];
		for (int i = 0; i < size; i++)
			stack[i] = a.stack[i];
	}

	~TStack()
	{
		delete[] stack;
	}

	void push(T& A)
	{
		if (head == size)
		{
			T* a = stack;
			stack = new T[2 * size];
			for (int i = 0; i < size; i++)
				stack[i] = a[i];
			delete[] a;
			size = 2 * size;
		}
		stack[head++] = A;
	}

	T pop()
	{
		if (IsEmpty()) throw "it is not possible to use pop with an empty stack";
		head--;
		return stack[head];
	}

	bool IsEmpty()
	{
		if (head == 0) return true;
		else return false;
	}

	void clear()
	{
		delete[] stack;
		stack = new T[size];
		head = 0;
	}

	int GetHead()
	{
		return head;
	}

	T peek()
	{
		if (IsEmpty()) throw "it is not possible to use peek with an empty stack";
		return stack[head - 1];
	}
};

#endif
