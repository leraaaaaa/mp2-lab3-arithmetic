// объявление функций и классов для вычисления арифметических выражений

#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include <iostream>
#include "stack.h"
#include <string>

class Arithmetic
{
private:
	double x;
	char op;
	bool f;

public:
	Arithmetic()
	{
		f = true;
		x = 1.0;
	}

	Arithmetic(const double& a)
	{
		f = 1;
		x = a;
	}

	Arithmetic(const char& oper)
	{
		f = 0;
		op = oper;
	}

	~Arithmetic()
	{ }

	void operator = (const double& a);
	void operator = (const char& op);
	void operator = (const Arithmetic& v);
	double GetX() const;
	char GetOp() const;
	bool GetF() const;
	int GetPriority();
	double res(Arithmetic* m, int n);
	double result(string s);
	bool aaa(Arithmetic* m, int n);
};

#endif
