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

	fileIn.open("lerMatrizes.txt", ios::in);

	if (!file)
	{
		printf("\nNao foi possivel acessar o arquivo!\n");
	}
}
Arquivo::~Arquivo()
{
	file.close();
	fileIn.close();
	remove("lerMatrizes.txt"); //removendo o arquivo que será lido.
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

void Arquivo::gravarMatrizParaLeitura(Matriz &x)
{
	for (int i = 0; i < x.getL(); i++)
	{
		for (int j = 0; j < x.getC(); j++)
		{
			fileIn << x.getValor(i, j) << " ";
		}
		fileIn << endl;
	}
}

void Arquivo::pegarMatriz(Matriz &x)
{
	int n;

	for (int i = 0; i < x.getL(); i++)
	{
		for (int j = 0; j < x.getC(); j++)
		{
			n = x.getValor(i, j);
			fileIn >> n;
		}
	}
}