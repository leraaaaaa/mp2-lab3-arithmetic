// реализация пользовательского приложения

#include <..\include\arithmetic.h>
#include <iostream>

using namespace std;

int main()
{
	try
	{
		string s;
		cout << "Please, enter math expression... " << endl;
		cin >> s;
		Arithmetic a;
		double f = a.result(s);
		cout << "Result = " << f << endl;
	}
	catch (char* error)
	{
		cout << error << endl;
	}
  return 0;
}
