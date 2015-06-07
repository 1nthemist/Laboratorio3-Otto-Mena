// Lab 3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ArbolBinario.h"
#include "ElementoPersona.h"
#include "Persona.h"
#include "Elemento.h"
#include "ElementoInt.h"
#include "ElementoDouble.h"

int _tmain(int argc, _TCHAR* argv[])
{

	double PI = 3.14159265359; //Hay una mejor forma de implementar pi con math.h pero preferi no complicarme
	srand((unsigned int)time(NULL));

	ArbolBinario a;
	for (int i = 0; i < 10; ++i) {
		a.insertarElemento(new ElementoInt(rand() % 100));
	}
	cout << "Arbol de int" << endl;
	cout << "" << endl;
	cout << a << endl;
	cout << "" << endl;

	ArbolBinario b;
	for (int i = 0; i < 10; ++i) {
		b.insertarElemento(new ElementoDouble((rand() % 100) / PI));
	}
	cout << "Arbol de Doubles" << endl;
	cout << "" << endl;
	cout << b << endl;
	cout << "" << endl;

	cout << "Arbol de Personas" << endl;
	cout << "" << endl;
	ArbolBinario c;
	Persona * array[20];
	string nombreAleatorio;

	for (int i = 0; i < 20; i++)
	{
		if (i % 4 == 0)
		{
			nombreAleatorio = "Mario";
		}
		if (i % 4 == 1)
		{
			nombreAleatorio = "Andrea";
		}
		if (i % 4 == 2)
		{
			nombreAleatorio = "Sofia";
		}
		if (i % 4 == 3)
		{
			nombreAleatorio = "Gustavo";
		}

		array[i] = new Persona(nombreAleatorio, i + 1);
	}
	for (int k = 0; k < 100; ++k) {
		swap(array[rand() % 20], array[rand() % 20]);
	}

	for (int i = 0; i < 20; i++)
	{
		c.insertarElemento(new ElementoPersona(array[i]));
	}
	cout << c << endl;
	for (int i = 0; i < 20; i++)
	{

		delete array[i];
	}

	system("pause");
	return 0;
}

