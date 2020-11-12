#include "Arquivo.h"
#include "Matriz.h"
#include <fstream>
#include <iostream>

using namespace std;

Arquivo::Arquivo()
{
	file.open("Matrizes.txt", ios::out);

	if (!file)
	{
		printf("\nNao foi possivel acessar o arquivo!\n");
	}
}

void Arquivo::gravarFrase(string texto)
{
	file << texto;
}

void Arquivo::gravarMatriz(Matriz &x)
{
	for (int i=0; i<x.getL(); i++)
	{
		for (int j=0; j<x.getC(); j++)
		{
			file << x.getValor(i, j) << " ";
		}
		file << endl;
	}
}