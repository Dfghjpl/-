#include <iostream>
#include "Progress.h"
using namespace std;

Progress make_Progress(double F, int S) {
	Progress t; //Создание временной переменной
	t.Init(F, S); //Инициализация полей переменной с помощью параметров функции
	return t; //Функция возвращает значение полей переменной t 
}

int main() {
	setlocale(LC_ALL, "RUS");
	int j;
	//Объявлние первого экземпляра и применение к нему методов Init(), Show(), Element()
	cout << "Введите номер элемента, который вы хоите найти\t "; cin >> j;
	cout << "Для первого экземпляра\t" << endl;
	Progress elem1;
	elem1.Init(2, 3);
	elem1.Show();
	cout << j << "-й элемент прогрессии:\t " << elem1.Element(j);
	cout << endl << "-------------------------" << endl;
	//Объявлние второго экземпляра и применение к нему методов Read(), Element()
	cout << "Введите номер элемента, который вы хоите найти\t "; cin >> j;
	cout << "Для второго экземпляра\t" << endl;
	Progress elem2;
	elem2.Read();
	cout << j << "-й элемент прогрессии:\t " << elem2.Element(j);
	cout << endl << "-------------------------" << endl;
	//Объявлние третьего экземпляра через указатель и применение к нему методов Init(), Show(), Element()
	cout << "Введите номер элемента, который вы хоите найти\t "; cin >> j;
	cout << "Для третьего экземпляра\t" << endl;
	Progress* elem3 = new Progress;
	elem3->Init(4, 2);
	elem3->Show();
	cout << j << "-й элемент прогрессии:\t " << elem3->Element(j);
	cout << endl << endl;
	//Создание статического массива экземпляров класса и применение к экземплярам методов класса
	cout << "Введите номер элемента, который вы хоите найти\t "; cin >> j;
	cout << "Для статического массива экземпляров\t" << endl;
	cout << "-------------------------" << endl;
	Progress arrelem[3]{};
	for (int i = 0; i < 3; i++) {
		arrelem[i].Read();
		cout << j << "-й элемент прогрессии:\t " << arrelem[i].Element(j);
		cout << endl << "-------------------------" << endl;
	}
	cout << endl;
	//Создание динамического массива экземпляров класса и применение к экземплярам методов класса
	cout << "Введите номер элемента, который вы хоите найти\t"; cin >> j;
	cout << "Для динамического массива экземпляров\t" << endl;
	cout << "-------------------------" << endl;
	Progress* dinarrelem = new Progress[3]{};
	for (int i = 0; i < 3; i++) {
		dinarrelem[i].Read();
		cout << j << "-й элемент прогрессии:\t " << dinarrelem[i].Element(j);
		cout << endl << "-------------------------" << endl;
	}
	cout << endl;
	//Пример работы внешней функции 
	double F;
	int S;
	Progress elem4;
	cout << "Работа внешней функции:\t " << endl;
	cout << "Введите номер элемента, который вы хоите найти\t "; cin >> j;
	cout << "Введите первый элемент прогрессии:\t "; cin >> F;
	cout << "Введите постоянное отношение прогрессии:\t "; cin >> S;
	elem4 = make_Progress(F, S);
	cout << j << "-й элемент прогрессии:\t " << elem4.Element(j);
	cout << endl;

	delete[] dinarrelem;
	delete elem3;
	return 0;
}