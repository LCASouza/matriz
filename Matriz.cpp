#include "Matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(int l, int c)
{
	M = new int* [l];

	for (int i=0; i<l; i++)
	{
		M[i] = new int[c];
	}
	L = l;
	C = c;
}

Matriz::~Matriz()
{
	for (int i=0; i<L; i++)
	{
		delete[] M[i];
	}
	delete[] M;
}

void Matriz::setValor(int x, int l, int c)
{
	M[l][c] = x;
}

int Matriz::getValor(int l, int c)
{
	return M[l][c];
}

int Matriz::getL()
{
	return L;
}

int Matriz::getC()
{
	return C;
}

bool Matriz::soma(Matriz x, Matriz y)
{
	if (x.L != y.L || x.C != y.C)
	{
		return false;
	}

	for (int i = 0; i < L; i++)
	{
		for (int j=0; j<C; j++)
		{
			this->M[i][j] = x.M[i][j] + y.M[i][j];
		}
	}
	return true;
}

bool Matriz::subtracao(Matriz x, Matriz y)
{
	if (x.L != y.L || x.C != y.C)
	{
		return false;
	}

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			this->M[i][j] = x.M[i][j] - y.M[i][j];
		}
	}
	return true;
}

bool Matriz::multiplicacao(Matriz x, Matriz y)
{
	if (y.C != x.L)
	{
		return false;
	}

	
}

bool Matriz::triangularS()
{
	return true;
}

bool Matriz::triangularI()
{
	return true;
}

bool Matriz::simetrica()
{
	return true;
}

bool Matriz::aSimetrica()
{
	return true;
}

bool Matriz::identidade()
{
	return true;
}