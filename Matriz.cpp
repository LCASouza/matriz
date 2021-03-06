#include "Matriz.h"
#include <iostream>
#include <fstream>

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

void Matriz::setValor(int x, int i, int j)
{
	M[i][j] = x;
}

int Matriz::getValor(int i, int j)
{
	return M[i][j];
}

int Matriz::getL()
{
	return L;
}

int Matriz::getC()
{
	return C;
}

void Matriz::setMatriz()
{
	int x;
	for (int i = 0; i < this->L; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			scanf("%d", &x);

			this->M[i][j] = x;
		}
	}
}

void Matriz::getMatriz()
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

bool Matriz::diffEqual(Matriz &x)
{
	int aux = 0;
	if (this->L == x.getL() && this->C == x.getC())
	{
		for (int i = 0; i < this->L; i++)
		{
			for (int j = 0; j < this->C; j++)
			{
				if (this->M[i][j] == x.getValor(i, j))
				{
					aux++;
				}
			}
		}
		if (aux == this->L * this->C)
		{
			return true;
		}
	}
	return false;
}

bool Matriz::soma(Matriz &x, Matriz &y)
{
	if (x.L != y.L || x.C != y.C)
	{
		return false;
	}

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			this->M[i][j] = x.M[i][j] + y.M[i][j];
		}
	}
	return true;
}

bool Matriz::subtracao(Matriz &x, Matriz &y)
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

bool Matriz::multiplicacao(Matriz &x, Matriz &y)
{
	if (y.C != x.L || this-> L < x.L || this-> C < y.C)
	{
		return false;
	}

	for (int i=0; i<x.L; i++)
	{
		for (int j=0; j<y.C; j++)
		{
			this->M[i][j] = 0;

			for (int k=0; k<y.L; k++)
			{
				this->M[i][j] += x.M[i][k] * y.M[k][j];
			}
		}
	}
	return true;
}

void Matriz::multiplicacaoK(int n)
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			M[i][j] *= n;
		}
	}
}

bool Matriz::potencia(Matriz &x, int n)
{
	if (this->L != this-> C)
	{
		return false;
	}

	Matriz ANS(this->L, this->C);

	for (int a=0; a<n-1; a++)
	{
		for (int i = 0; i < this->L; i++)
		{
			for (int j = 0; j < this->C; j++)
			{
				ANS.M[i][j] = 0;
				for (int k = 0; k < x.L; k++)
				{
					ANS.M[i][j] += this->M[i][k] * x.M[k][j];
				}
			}
		}
		igual(ANS);
	}
	return true;
}

void Matriz::transposta(Matriz &x)
{
	for (int i=0; i<L; i++)
	{
		for (int j=0; j<C; j++)
		{
			this->M[i][j] = x.M[j][i];
		}
	}
}

void Matriz::oposta(Matriz &x)
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			this->M[i][j] = x.M[i][j] * -1;
		}
	}
}

bool Matriz::triangularS()
{
	if (L != C)
	{
		return false;
	}
	
	int aux = 0;

	for (int i=0; i<L; i++)
	{
		for (int j=i+1; j<C; j++)
		{
			if (M[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Matriz::triangularI()
{
	if (L != C)
	{
		return false;
	}

	int aux = 0;

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (M[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Matriz::simetrica(Matriz &x)
{
	if (L != C || this->L != x.L || this->C != x.C)
	{
		return false;
	}

	int aux = 0;
	
	for (int i=0; i<this->L; i++)
	{
		for (int j=0; j<this->C; j++)
		{
			if (this->M[i][j] == x.getValor(i, j))
			{
				aux++;
			}
		}
	}
	if (aux == this->L * this->C)
	{
		return true;
	}
	return false;
}

bool Matriz::aSimetrica(Matriz &x)
{
	if (L != C || this->L != x.L || this->C != x.C)
	{
		return false;
	}

	int aux = 0;

	for (int i=0; i<this->L; i++)
	{
		for (int j=0; j<this->C; j++)
		{
			if (this->M[i][j] == x.getValor(i, j))
			{
				aux++;
			}
		}
	}
	if (aux == this->L * this->C)
	{
		return true;
	}
	return false;
}

bool Matriz::identidade()
{
	int aux = 0;

	if (L != C)
	{
		return false;
	}

	for (int i=0; i<L; i++)
	{
		for (int j=0; j<C; j++)
		{
			if (i == j && M[i][j] == 1)
			{
				aux++;
			}
			else if (i != j && M[i][j] == 0)
			{
				aux++;
			}
		}
	}
	if (aux == L * C)
	{
		return true;
	}
	return false;
}

void Matriz::igual(Matriz &x)
{
	for (int i=0; i<x.L; i++)
	{
		for (int j=0; j<x.C; j++)
		{
			this->M[i][j] = x.M[i][j];
		}
	}
}