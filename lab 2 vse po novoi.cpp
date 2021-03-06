#include "pch.h"
#include <iostream>
#include <ctime>
#include<cmath>
using namespace std;

// Вычисляет положение точки D(x4,y4) относительно прямой AB
double g(double x1, double y1, double x2, double y2, double x4, double y4)
{
	return (x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1);
}

// Лежат ли точки C и D с одной стороны прямой (AB)?
double v(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	return g(x1, y1, x2, y2, x3, y3) * g(x1, y1, x2, y2, x4, y4) ;
}

int main()
{
	setlocale(LC_ALL, "rus");

	/*double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1; // читаем координаты точки A
	cin >> x2 >> y2; // читаем координаты точки B
	cin >> x3 >> y3; // читаем координаты точки C
	cin >> x4 >> y4; // читаем координаты точки D
	if ((x1 == x2) && (x2 == x3))
	{
		cin >> x1 >> y1; // читаем координаты точки A
		cin >> x2 >> y2; // читаем координаты точки B
		cin >> x3 >> y3; // читаем координаты точки C
		cin >> x4 >> y4; // читаем координаты точки D
	}*/
	srand(time(NULL));
	int A[2];
	int B[2];
	int C[2];
	int D[2];

	const int ROW = 2;//хранятся координаты
	const int COL = 4;
	int arr[ROW][COL];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			arr[i][j] = rand() % 11;//координатами будут случайные числа от 0 до 10
	}
	double x1 = arr[0][0];
	double y1 = arr[1][0];
	double x2 = arr[0][1];
	double y2 = arr[1][1];
	double x3 = arr[0][2];
	double y3 = arr[1][2];
	double x4 = arr[0][3];
	double y4 = arr[1][3];

	//void prisvoit(int &x1, int &x2, int &x3, int &y1, int &y2, int &y3, int &x4, int &y4, int arr[ROW][COL]);//создаем ссылки, указывающие на значения,которые хрянятся в массиве
	for (int i = 0; i <= 4; i++)
	{
		switch (i) {
		case 1: {cout << "(x1,y1)=" << "(" << arr[0][0] << "," << arr[1][0] << ")" << endl; break; }
		case 2: {cout << "(x2,y2)=" << "(" << arr[0][1] << "," << arr[1][1] << ")" << endl; break; }
		case 3: {cout << "(x3,y3)=" << "(" << arr[0][2] << "," << arr[1][2] << ")" << endl; break; }
		case 4: {cout << "(x4,y4)=" << "(" << arr[0][3] << "," << arr[1][3] << ")" << endl; break; }

		}

	}
	//void proverka(int &x1, int &x2, int &x3, int &y1, int &y2, int &y3);// // проверка того, сусчествует ли такой треухгольник
	if ((x1 == x2) && (x2 == x3))
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
				arr[i][j] = rand() % 11;//координатами будут случайные числа от 0 до 10
		}
		//void setcoord(int arr);//выбрать координаты, координатами будут случайные числа от 0 до 10
	}
	else if (((x1 == x2) && (y1 == y2)) || ((x2 == x3) && (y2 == y3)) || ((x1 == x2) && (y1 == y2)))
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
				arr[i][j] = rand() % 11;//координатами будут случайные числа от 0 до 10
		}
		//void setcoord(int arr);//выбрать координаты, координатами будут случайные числа от 0 до 10
	}
	int min = NULL;
	int mid = NULL;      //заполняю нулями
	int max = NULL;

	if ((x1 < x2) && (x2 < x3))
	{
		A[0] = x1;
		A[1] = y1;
		B[0] = x2;
		B[1] = y2;
		C[0] = x3;
		C[1] = y3;
	}
	else
	{

		if (x1 > x2)
		{
			min = x2; max = x1;
			if (x3 > x1)
			{
				max = x3;
			}
			if (x2 > x3)
			{
				min = x3;
			}
		}// vrode norm
		else if (x2 > x3)
		{
			max = x2; min = x3;
			if (x1 < x3)
			{
				min = x1;
			}
			if (x1 > x2)
			{
				max = x1;
			}// vrode norm
		}
		else if ((x1 == x2) && (x1 < x3))
		{
			max = y3;
			if (y1 < y2)
			{
				min = y1;
			}
			if (y1 > y2)
			{
				min = y2;
			}
		}
		else if ((x1 == x2) && (x1 > x3))
		{
			min = y3;
			if (y1 < y2)
			{
				max = y2;
			}
			if (y1 > y2)
			{
				max = y1;
			}
		}
		else if ((x2 == x3) && (x1 < x3))
		{
			min = y1;
			if (y2 > y3)
			{
				max = y2;
			}
			if (y2 < y3)
			{
				max = y3;
			}
		}
		else if ((x2 == x3) && (x1 > x3))
		{
			max = y1;
			if (y2 > y3)
			{
				min = y3;
			}
			if (y2 < y3)
			{
				min = y2;
			}
		}
		else if ((x1 == x3) && (x1 < x2))
		{
			max = y2;
			if (y1 < y3)
			{
				min = y1;
			}
			if (y1 > y3)
			{
				min = y3;
			}
		}
		else if ((x1 == x3) && (x1 > x2))
		{
			min = y2;
			if (y1 < y3)
			{
				max = y3;
			}
			if (y1 > y3)
			{
				max = y1;
			}
		}
		if ((x1 != x2) && (x2 != x3) && (x1 != x3))
		{
			mid = (x1 + x2 + x3) - (min + max);
		}
		if ((x1 == x2) || (x2 == x3) || (x1 == x3))
		{
			mid = (y1 + y2 + y3) - (min + max);
		}
		if ((x1 == min) || (y1 == min))
		{
			A[0] = x1;
			A[1] = y1;
		}
		if ((x2 == min) || (y2 == min))
		{
			A[0] = x2;
			A[1] = y2;
		}
		if ((x3 == min) || (y3 == min))
		{
			A[0] = x3;
			A[1] = y3;
		}
		/////////////////////
		if ((x1 == mid) || (y1 == mid))
		{
			B[0] = x1;
			B[1] = y1;
		}
		if ((x2 == mid) || (y2 == mid))
		{
			B[0] = x2;
			B[1] = y2;
		}
		if ((x3 == mid) || (y3 == mid))
		{
			B[0] = x3;
			B[1] = y3;
		}
		//////////////////////
		if ((x1 == max) || (y1 == max))
		{
			C[0] = x1;
			C[1] = y1;
		}
		if ((x2 == max) || (y2 == max))
		{
			C[0] = x2;
			C[1] = y2;
		}
		if ((x3 == max) || (y3 == max))
		{
			C[0] = x3;
			C[1] = y3;
		}

	}
	D[0] = x4;
	D[1] = y4;

	//void coord(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);
	cout << "A (x1,y1)\t" << '=' << '(' << A[0] << ',' << A[1] << ')' << endl;
	cout << "B (x2,y2)\t" << '=' << '(' << B[0] << ',' << B[1] << ')' << endl;
	cout << "C (x3,y3)\t" << '=' << '(' << C[0] << ',' << C[1] << ')' << endl;
	cout << "D (x4,y4)\t" << '=' << '(' << D[0] << ',' << D[1] << ')' << endl;
	//переназначаем координаты 
	x1 = A[0];
	y1 = A[1];
	x2 = B[0];
	y2 = B[1];
	x3 = C[0];
	y3 = C[1];
	x4 = D[0];
	y4 = D[1];

	// непосредственно задача
	if ((v(x1, y1, x2, y2, x3, y3, x4, y4) > 0) && (v(x1, y1, x3, y3, x1, y1, x4, y4) > 0) && (
		v(x3, y3, x1, y1, x2, y2, x4, y4) > 0))//лежит ли в треугольнике
	{
		cout << "лежит в треугольнике";
	}
	else if ((v(x1, y1, x2, y2, x3, y3, x4, y4) == 0) || (v(x1, y1, x3, y3, x1, y1, x4, y4) == 0) || (
		v(x3, y3, x1, y1, x2, y2, x4, y4) == 0))//лежит ли в треугольнике
	{
		cout << "лежит на треугольнике";
	}
	else
		cout << "лежит снаружи треугольника";
}