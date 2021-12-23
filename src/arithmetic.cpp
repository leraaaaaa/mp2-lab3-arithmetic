// реализация функций и классов для вычисления арифметических выражений

#include "..\include\arithmetic.h"
#include <cmath>

void Arithmetic::operator = (const double& a)
{
	x = a;
	f = 1;
}
void Arithmetic::operator= (const char& _op)
{
	op = _op;
	f = 0;
}
void Arithmetic::operator = (const Arithmetic& v)
{
	switch (v.GetF())
	{
	case 1:
	{
		x = v.GetX();
		f = 1;
		break;
	}
	case 0:
	{
		op = v.GetOp();
		f = 0;
	}
	}
}
double Arithmetic::GetX() const
{
	return x;
}
char Arithmetic::GetOp() const
{
	return op;
}
bool Arithmetic::GetF() const
{
	return f;
}
int Arithmetic::GetPriority() 
{
	if ((op == '+') || (op == '-'))
		return 2;
	if ((op == '*') || (op == '/'))
		return 3;
	if (op == '(')
		return 1;
	if (op == ')')
		return 0;
	if (op == '~') return 4;
	throw "translation error";
}

double Arithmetic::result(string s)
{
	int i = 0, j = 0, f1 = 1, f2 = 1, f0 = 1;
	Arithmetic m[50];
	while (i < s.length())
	{
		if (s[i] >= '0' && s[i] <= '9' || s[i] == '.')
		{	
			double res = 0, del = 10, x = 0;
			int points = 0;

			while (s[i] >= '0' && s[i] <= '9')
			{
				x = (s[i] - '0');
				res = res * 10 + x;
				i++;
			}
			if (s[i] == '.')
			{
				i++;
				points++;
				while (s[i] >= '0' && s[i] <= '9'|| s[i]=='.')
				{
					if (s[i] == '.') throw "more than 2 points in the number";
					x = s[i++] - '0';
					res += (x / del);
					del *= 10;
				}
			}
			m[j++] = res;
		}
		if (i < s.length())
		{
			switch (s[i])
			{
			case '+':
			{
				m[j++] = '+';
				i++;
				break;
			}
			case '/':
			{
				m[j++] = '/';
				i++;
				break;
			}
			case '*':
			{
				m[j++] = '*';
				i++;
				break;
			}
			case '(':
			{
				m[j++] = '(';
				i++;
				break;
			}
			case ')':
			{
				m[j++] = ')';
				i++;
				break;
			}
			case '-':
			{
				if (i == 0)
				{
					m[j++] = -1.0;
					m[j++] = '*';
					i++;
				}
				else if ((!m[j - 1].GetF()) && (m[j - 1].GetOp() != ')'))
				{
					m[j++] = '~';
					i++;
				}
				else
				{
					m[j++] = '-';
					i++;
				}
				break;
			}
			case'x':
			{
				double v;
				if (f0)
				{
					cout << "Please, enter x" << endl;
					cin >> v;
					if (cin.fail())
						throw "incorrect input of x";
					f0 = 0;
				}
				m[j++] = v;
				i++;
				break;
			}

			case'y':
			{
				double v;
				if (f1)
				{
					cout << "Please, enter y" << endl;
					cin >> v;
					if (cin.fail())
						throw "incorrect input of y";
					f1 = 0;
				}
				m[j++] = v;
				i++;
				break;
			}

			case'z':
			{
				double v;
				if (f2)
				{
					cout << "Please, enter z" << endl;
					cin >> v;
					if (cin.fail())
						throw "incorrect input of z";
					f2 = 0;
				}
				m[j++] = v;
				i++;
				break;
			}
			default:
			{
				cout << s[i]<< " is ";
				throw "incorrect symbol";
			}
			}
		}
	}

	switch (aaa(m, j))
	{
	case true: break;
	case false: throw "incorrect expression";
	}

	Arithmetic* pol = new Arithmetic[j];
	TStack<Arithmetic> stack1;
	int k = 0;
	for (int i = 0; i < j; i++)
	{
		if (m[i].GetF())
			pol[k++] = m[i];
		else if (stack1.IsEmpty())
			stack1.push(m[i]);
		else if (m[i].GetPriority() == 1)
			stack1.push(m[i]);
		else
		{
			while (!(stack1.IsEmpty()) && (m[i].GetPriority() <= stack1.peek().GetPriority()))
			{
				if (stack1.peek().GetPriority() == 1)
				{
					stack1.pop();
					break;
				}
				pol[k++] = stack1.pop();
			}
			if (m[i].GetPriority() != 0)
				stack1.push(m[i]);
		}
	}
	while (!stack1.IsEmpty())
		pol[k++] = stack1.pop();
	return res(pol, k);
}

bool Arithmetic::aaa(Arithmetic* m, int n)
{
	int open = 0;
	int close = 0;
	for (int i = 0; i < n - 1; i++) 
	{
		if (m[i].GetF() == true)
		{
			if (m[i + 1].GetF() == true)
			{
				throw "number after number";
				return false;
			}
				
			switch (m[i + 1].GetOp())
			{
			case'+':
			case'-':
			case'*':
			case'/':
			case')':
				continue;
			default:
			{
				throw "( after a number";
				return false;
			}
			}
		}

		if (m[i].GetF() == false)
		{
			if (m[i].GetOp() == ')')
			{
				if (i == 0)
				{
					throw ") at the beginning of the expression";
					return false;
				}

				if (m[i + 1].GetF() == true)
				{
					throw "a number after )";
					return false;
				}
					
				switch (m[i + 1].GetOp())
				{
				case'+':
				case'-':
				case'*':
				case'/':
				case')':	
				{
					close ++;
					continue;
				}
				default:
				{
					throw "( after )";
					return false;
				}
				}
					if (close > open)
						return false;
			}

			if (m[i].GetOp() == '(')
			{
			
				if (m[i + 1].GetF() == true)
				{	
					open++;
					continue;
				}
				else
					switch (m[i + 1].GetOp())
					{
					case'(':
					case'~':
					{
						open++;
						continue;
					}
					default:
					{
						throw "+ or * or / or ) after (";
						return false;
					}
				}
			}

			if (m[i].GetOp() == '~')
			{
				if (m[i + 1].GetF() == true)
					continue;
				else
					switch (m[i + 1].GetOp())
					{
					case'(':
						break;
					default:
					{
						throw "not ( or number after -";
						return false;
					}
					}
			}

			if ((m[i].GetOp() == '+') || (m[i].GetOp() == '-') || (m[i].GetOp() == '*') || (m[i].GetOp() == '/'))
			{
				if (i == 0)
				{
					throw "incorrect beginning of the expression";
					return false;
				}

				if (m[i + 1].GetF() == true)
					continue;
				else
					switch (m[i + 1].GetOp())
					{
					case'(':
					case '~':
						continue;
					default:
					{
						throw "incorrect operation after operation";
						return false;
					}
					}
			}
		}
	}

	if ((m[n-1].GetF() == false) && (m[n-1].GetOp() == '('))
	{
		throw "( in the end of the expression";
		return false;
	}			

	if ((m[n-1].GetF() == false) && (m[n-1].GetOp() == '~'))
	{
		throw "incorrect end of the expression";
		return false;
	}

	if ((m[n-1].GetF() == false) && ((m[n-1].GetOp() == '+') || (m[n - 1].GetOp() == '-') || (m[n - 1].GetOp() == '/') || (m[n - 1].GetOp() == '*')))
	{
		throw "incorrect end of the expression";
		return false;
	}

	if ((m[n - 1].GetF() == false) && (m[n - 1].GetOp() == ')'))
		close++;

	if (close != open)
	{
		throw "unequal amount of ( and )";
		return false;
	}
	else
		return true;
}

double Arithmetic::res(Arithmetic* m, int n)
{
	TStack<Arithmetic> stack2;
	Arithmetic res;
	double l, r;
	for (int i = 0; i < n; i++)
	{
		if (m[i].GetF())
		{
			stack2.push(m[i]);
			continue;
		}
		switch (m[i].GetOp())
		{
		case '+':
		{
			r = stack2.pop().GetX();
			l = stack2.pop().GetX();
			res = l + r;
			stack2.push(res);
			continue;
		}
		case '-':
		{
			r = stack2.pop().GetX();
			l = stack2.pop().GetX();
			res = l - r;
			stack2.push(res);
			continue;
		}
		case '*':
		{
			r = stack2.pop().GetX();
			l = stack2.pop().GetX();
			res = l * r;
			stack2.push(res);
			continue;
		}
		case '/':
		{
			r = stack2.pop().GetX();
			l = stack2.pop().GetX();
			res = l / r;
			stack2.push(res);
			continue;
		}
		case '~':
		{
			r = stack2.pop().GetX();
			res = (-r);
			stack2.push(res);
			continue;
		}
		default:
			throw "translation error";
		}
	}
	return (stack2.pop().GetX());
}
