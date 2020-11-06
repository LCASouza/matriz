#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    int l, c, x;

    printf("Digite as dimensões da Matriz A: ");
    scanf("%d %d", &l, &c);

    Matriz A(l, c);

    printf("Insira os elementos da matriz A:\n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &x);

            A.setValor(x, i, j);
        }
    }

    for (int i=0; i<l; i++)
    {
        for (int j=0; j<c; j++)
        {
            printf("%d ", A.getValor(i, j));
        }
        printf("\n");
    }

    printf("Digite as dimensões da Matriz B: ");
    scanf("%d %d", &l, &c);

    Matriz B(l, c);

    printf("Insira os elementos da matriz B:\n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &x);

            B.setValor(x, i, j);
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", B.getValor(i, j));
        }
        printf("\n");
    }

    Matriz somado(B.getL(), B.getC());

    if (somado.soma(A, B))
    {
        for (int i = 0; i < somado.getL(); i++)
        {
            for (int j = 0; j < somado.getC(); j++)
            {
                printf("%d ", somado.getValor(i, j));
            }
            printf("\n");
        }
    }

    /*Matriz multiplicado(A.getC(), B.getL());

    if (multiplicado.multiplicacao(A, B))
    {
        for (int i = 0; i < multiplicado.getL(); i++)
        {
            for (int j = 0; j < multiplicado.getC(); j++)
            {
                printf("%d ", multiplicado.getValor(i, j));
            }
            printf("\n");
        }
    }
    */
}