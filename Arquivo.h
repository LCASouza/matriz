#pragma once
#include <iostream>
#include <fstream>
#include "Matriz.h"

using namespace std;

class Arquivo
{
	private:
		ofstream file;

	public:
		Arquivo();
		void gravarMatriz(Matriz &x);
		void gravarFrase(string texto);
};

