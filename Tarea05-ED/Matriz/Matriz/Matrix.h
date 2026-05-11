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

	E getValue(int fila, int columna)
	{
		if (fila < 0 || fila >= filas)
		{
			runtime_error("Valor no valido.");
		}

		if (columna < 0 || columna >= columnas)
		{
			runtime_error("Valor no valido.");
		}

		return matrix[fila][columna];
	}

	void setValue(int fila, int columna, E value)
	{
		if (fila < 0 || fila >= filas)
		{
			runtime_error("Valor no valido.");
		}

		if (columna < 0 || columna >= columnas)
		{
			runtime_error("Valor no valido.");
		}

		matrix[fila][columna] = value;
	}

	int getFilas()
	{
		return fila;
	}

	int getColumnas()
	{
		return columna;
	}


	void setAll(E value)
	{
		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
			{
				matrix[i][j] = value;
			}
		}
	}

	void transpose()
	{
		E** mTranspuesta = new E * [columna];

		for (int i = 0; i < columna; i++)
		{
			mTranspuesta[i] = new E[fila];
		}


		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
			{
				mTranspuesta[j][i] = matrix[i][j];
			}
		}


		for (int i = 0; i < fila; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;


		matrix = mTranspuesta;
	

		int temp = fila;
		fila = columna;
		columna = temp;
	}

	void addRow(E value)
	{

		E** mNueva= new E * [fila + 1];

		for (int i = 0; i < fila + 1; i++)
		{
			mNueva[i] = new E[columa];
		}


		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
			{
				mNueva[i][j] = matrix[i][j];
			}
		}


		for (int j = 0; j < columna; j++)
		{
			nueva[fila][j] = value;
		}


		for (int i = 0; i < fila; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;


		matrix = mNueva;


		fila++;

	}

	void addColumn(E value)
	{

		E** mNueva = new E * [fila];

		for (int i = 0; i < fila; i++)
		{
			mNueva[i] = new E[columna + 1];
		}

		
		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
			{
				mNueva[i][j] = matrix[i][j];
			}
		}

		
		for (int i = 0; i < fila; i++)
		{
			mNueva[i][columna] = value;
		}

		
		for (int i = 0; i < fila; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;

		
		matrix = mNueva;

		columna++;

	}

	void removeRow(int row)
	{
		if (row < 0 || row >= fila)
		{
			throw runtime_error("fila no valida.");
		}


		E** mNueva = new E * [fila - 1];

		for (int i = 0; i < fila - 1; i++)
		{
			mNueva[i] = new E[columna];
		}

		int filaNueva = 0;

		for (int i = 0, i < fila; i++)
		{
			if (i != row)
			{
				for (int j = 0; j < columna; j++)
				{
					mNueva[filaNueva][j] = matrix[i][j];
				}
			}
			
			filaNueva++;
		}


		for (int i = 0; i < fila; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;


		matrix = mNueva;

		fila--;
	}

	void removeColumn(int col)
	{

		if (col < 0 || col >= columna)
		{
			throw runtime_error("columna no valida.");
		}


		E** mNueva = new E * [fila];

		for (int i = 0; i < fila; i++)
		{
			mNueva[i] = new E[columna - 1];
		}


		for (int i = 0; i < fila; i++)
		{

			int columnaNueva = 0;

			for (int j = 0; j < columna; j++)
			{

				if (j != col)
				{
					mNueva[i][columnaNueva] = matrix[i][j];
					columnaNueva++;
				}

			}

		}

		for (int i = 0; i < fila; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;


		matrix = mNueva;
		columna--;

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

