
/*Тип информационного поля char*.
Добавить в стек элементы с номерами 1, 3, 5 и т.д.
*/

#include<iostream>
#include<stack>
#include<Windows.h>
using namespace std;
char el;

void Print(stack<char> st)
{
	int s = st.size();
	if (s == 0)
	{
		cout << "Стек пуст.";
	}
	else
	{
		cout << "Стек: " << endl;
		for (int i = 0; i < s; i++)
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}

void Add(stack<char> st)
{
	stack<char> st2;
	stack<char> st3;
	cout << "Введите элементы для добавления в стек: " << endl;
	int s = st.size();
	for (int i = 0; i < s; i++)
	{
		cin >> el;
		st2.push(el);
	}
	while (!st.empty())
	{
		st3.push(st.top());
		st.pop();
		st3.push(st2.top());
		st2.pop();
	}
	Print(st3);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	stack<char> st;
	int count;
	cout << "Введите количество элементов стека: ";
	cin >> count;
	cout << "Введите элементы стека: " << endl;
	for (int i = 0; i < count; i++)
	{
		cin >> el;
		st.push(el);
	}
	Add(st);
	return 0;
}
