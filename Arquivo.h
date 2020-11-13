#pragma once
#include <iostream>
#include <fstream>
#include "Matriz.h"

using namespace std;

class Arquivo
{
	private:
		ofstream file;
		fstream fileIn;

	public:
		Arquivo();
		~Arquivo();

		void gravarMatriz(Matriz &x);
		void gravarMatrizParaLeitura(Matriz &x);
		void gravarFrase(string texto);
		void pegarMatriz(Matriz &x);
};

