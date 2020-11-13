#pragma once
#include <iostream>

using namespace std;

class Matriz
{
	private:
		int** M;
		int L, C;

	public:
		Matriz(int l, int c);
		~Matriz();

		void setValor(int x, int i, int j);
		int getValor(int i, int j);
		int getL();
		int getC();
		void setMatriz();
		void getMatriz();

		bool diffEqual(Matriz &x);
		bool soma(Matriz &x, Matriz &y);
		bool subtracao(Matriz &x, Matriz &y);
		bool multiplicacao(Matriz &x, Matriz &y);
		void multiplicacaoK(int n);
		bool potencia(Matriz &x, int n);
		void transposta(Matriz &x);
		void oposta(Matriz &x);
		bool triangularS();
		bool triangularI();
		bool simetrica(Matriz &x);
		bool aSimetrica(Matriz &x);
		bool identidade();
		void igual(Matriz &x);
};