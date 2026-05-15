#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"
using namespace std;
using std::exception;
using std::endl;
using std::cout;
using std::cin;
using std::runtime_error;


void verificarIndiceFila(int fila, int filas)
{
	if (fila < 0 || fila >= filas)
	{
		throw runtime_error ("Indice de fila fuera de rango.");
	}
}


void verificarIndiceColumna(int columna, int columnas)
{
    if (columna < 0 || columna >= columnas)
    {
        throw runtime_error("Indice de columna fuera de rango.");
    }
}



int main()
{

    srand(time(0));

    int filas;
    int columnas;

	cout << "Ingrese las dimensiones de la matriz:" << endl;

    cout << "Cantidad de filas: ";
    cin >> filas;

    cout << "Cantidad de columnas: ";
    cin >> columnas;

    Matrix<int> matriz(filas, columnas);

    int opc;

    do
    {
		cout << "**-*-*-*-*-*-*-*-*-*-*-*-*-*- Matriz -*-*-*-*-*-*-*-*-*-*-*-*-*-**" << "\n" << endl;
		matriz.print();
		cout << "\n" << endl;


        cout << "**-*-*-*-*-*-*-*-*-*-*-*-*-*- MENU -*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
        cout << "1. llenar matriz con numeros aleatorios" << endl;
        cout << "2. getValue" << endl;
        cout << "3. setValue" << endl;
        cout << "4. getRows" << endl;
        cout << "5. getColumns" << endl;
        cout << "6. setAll" << endl;
        cout << "7. transpose" << endl;
        cout << "8. addRow" << endl;
        cout << "9. addColumn" << endl;
        cout << "10. removeRow" << endl;
        cout << "11. removeColumn" << endl;
        cout << "12. salir" << endl;
        cout << "Ingrese opcion: ";
		cin >> opc;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Valor no valido\n";
            cout << "Ingrese un valor numerico de las opciones: ";
            cin >> opc;
        }

        try
        {
            
            switch (opc)
            {

            case 1:
            {

                for (int i = 0; i < matriz.getFilas(); i++)
                {
                    for (int j = 0; j < matriz.getColumnas(); j++)
                    {
                        matriz.setValue(i, j, rand() % 100);
                    }
                }

                cout << "Matriz llenada con exito." << endl;
                break;

            }
            


            case 2:
            {

                int fila;
                int columna;

                cout << "Ingrese la fila del valor a buscar: ";
                cin >> fila;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la fila nuevamente: ";
                    cin >> fila;
                }

                verificarIndiceFila(fila, matriz.getFilas());


                cout << "Ingrese la columna del valor a buscar: ";
                cin >> columna;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la columna nuevamente: ";
                    cin >> columna;
                }

                verificarIndiceColumna(columna, matriz.getColumnas());

                cout << "Elemento: " << matriz.getValue(fila, columna) << endl;
                break;
            }


            case 3:
            {

                int row;
                int column;
                int valor;

                cout << "Ingrese la fila del valor a modificar: ";
                cin >> row;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la fila nuevamente: ";
                    cin >> row;
                }

                verificarIndiceFila(row, matriz.getFilas());


                cout << "Ingrese la columna del valor a modificar: ";
                cin >> column;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la columna nuevamente: ";
                    cin >> column;
                }

                verificarIndiceColumna(column, matriz.getColumnas());


                cout << "Nuevo valor: ";
                cin >> valor;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Valor no valido\n";
                    cout << "Ingrese un valor numerico entero: ";
                    cin >> valor;
                }

                matriz.setValue(row, column, valor);
                break;

            }


            case 4:
            {

                cout << "Cantidad de filas: " << matriz.getFilas() << endl;
                break;

            }


            case 5:
            {

                cout << "Cantidad de columnas: " << matriz.getColumnas() << endl;
                break;

            }


            case 6:
            {

                int value;

                cout << "Ingrese el valor que se le asignara a toda la matriz: ";
                cin >> value;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Valor no valido\n";
                    cout << "Ingrese un valor numerico entero: ";
                    cin >> value;
                }

                matriz.setAll(value);
                break;

            }


            case 7:

            {

                cout << "Matriz transpuesta: " << endl;
                matriz.transpose();
                break;

            }


            case 8:

            {

                int filanueva;

                cout << "Ingrese el valor para la nueva fila: ";
                cin >> filanueva;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la fila nuevamente: ";
                    cin >> filanueva;
                }


                matriz.addRow(filanueva);
                break;

            }



            case 9:
            {

                int columnanueva;

                cout << "Ingrese el valor para la nueva columna: ";
                cin >> columnanueva;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la columna nuevamente: ";
                    cin >> columnanueva;
                }


                matriz.addColumn(columnanueva);
                break;

            }



            case 10:
            {

                int filaeliminada;

                cout << "Ingrese el valor de la fila a eliminar: ";
                cin >> filaeliminada;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la fila a eliminar nuevamente: ";
                    cin >> filaeliminada;
                }

                verificarIndiceFila(filaeliminada, matriz.getFilas());


                matriz.removeRow(filaeliminada);
                break;

            }



            case 11:
            {
                int columnaeliminada;

                cout << "Ingrese el valor de la columna a eliminar: ";
                cin >> columnaeliminada;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nValor no valido.\n";
                    cout << "Ingrese el valor de la columna a eliminarnuevamente: ";
                    cin >> columnaeliminada;
                }

                verificarIndiceColumna(columnaeliminada, matriz.getColumnas());


                matriz.removeColumn(columnaeliminada);
                break;
            }


            case 12:
            {

                cout << "Saliendo del sistema" << endl;
                break;

            }


            default:
            {
                cout << "Opcion no valida." << endl;
                break;
            }


            }
            
        }

        catch (exception& e)
        {
            cout << e.what() << endl;
        }

	} while (opc != 12);
}















//Golden Brown - The Stranglers