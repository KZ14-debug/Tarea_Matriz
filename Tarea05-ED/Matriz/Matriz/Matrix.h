#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::runtime_error;

template<typename E>
class Matrix
{

private: 
	E** matrix;
	int fila;
	int columna;


public:
	Matrix(int fila, int columna) 
	{
		if (fila <= 0 || columna <= 0)
		{
			runtime_error("El numero de filas y columnas debe ser mayor a cero.");
		}


		matrix = new E * [fila];
		for (int i = 0; i < fila; i++)
		{
			matrix[i] = new E[columna];
		}

		this->fila = fila;
		this->columna = columna;
	}

	~Matrix()
	{
		for (int i = 0; i < fila; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	void set(int f, int c, E value) //Este es un metodo para asignar un valor en la matriz, recibe los indices de la fila y columna donde se insertara, tambien pide el valor a insertar
	{
		if (f < 0 || f >= fila || c < 0 || c >= columna)
		{
			runtime_error("Indice fuera de rango.");
		}

		matrix[f][c] = value;
	}

	void setAll(E value) //Esto asigna un valor a toda la matriz, recibe un valor para que asignarlo a la matriz
	{
		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
			{
				matrix[i][j] = value;
			}
		}
	}

	E get(int f, int c) //Este es un metodo para obtener un valor que se encuentra en la matriz, recibe el numero de fila y columna donde se encuentra el valor a obtener
	{ 
		if (f < 0 || f >= fila || c < 0 || c >= columna)
		{
			runtime_error("Indice fuera de rango.");
		}
		return matrix[f][c];

	}

	int getFilas()
	{
		return fila;
	}

	int getColumnas()
	{
		return columna;
	}

	void print()
	{

		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}

	}


};

