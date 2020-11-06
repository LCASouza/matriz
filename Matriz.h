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

		void setValor(int x, int l, int c);
		int getValor(int l, int c);

		int getL();
		int getC();

		void transposta(Matriz &x);
		bool soma(Matriz &x, Matriz &y);
		bool subtracao(Matriz &x, Matriz &y);
		bool multiplicacao(Matriz &x, Matriz &y);
		bool triangularS();
		bool triangularI();
		bool simetrica();
		bool aSimetrica();
		bool identidade();
};