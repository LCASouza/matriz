#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    int l, c, x;

    printf("Digite as dimensoes da Matriz A: ");
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

    printf("\nDigite as dimensoes da Matriz B: ");
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

    if (A.triangularS())
    {
        printf("\nA matriz A e triangular superior!\n");
    }
    else
    {
        printf("\nA matriz A nao e triangular superior!\n");
    }

    if (B.triangularS())
    {
        printf("\nA matriz B e triangular superior!\n");
    }
    else
    {
        printf("\nA matriz B nao e triangular superior!\n");
    }

    Matriz Transposta(A.getC(), A.getL());
    Transposta.transposta(A);
    printf("\nMatriz Transposta de A:\n");

    for (int i = 0; i < Transposta.getL(); i++)
    {
        for (int j = 0; j < Transposta.getC(); j++)
        {
            printf("%d ", Transposta.getValor(i, j));
        }
        printf("\n");
    }

    Matriz TranspostaB(B.getC(), B.getL());
    TranspostaB.transposta(B);
    printf("\nMatriz Transposta de B:\n");

    for (int i = 0; i < TranspostaB.getL(); i++)
    {
        for (int j = 0; j < TranspostaB.getC(); j++)
        {
            printf("%d ", TranspostaB.getValor(i, j));
        }
        printf("\n");
    }

    Matriz result(B.getL(), B.getC());

    if (result.soma(A, B))
    {
        printf("\nResultado da soma da Matriz A e B:\n");
        for (int i = 0; i < result.getL(); i++)
        {
            for (int j = 0; j < result.getC(); j++)
            {
                printf("%d ", result.getValor(i, j));
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nNao e possivel somar essas matrizes!\n");
    }

    if (result.subtracao(A, B))
    {
        printf("\nResultado da subtracao da Matriz A e B:\n");

        for (int i = 0; i < result.getL(); i++)
        {
            for (int j = 0; j < result.getC(); j++)
            {
                printf("%d ", result.getValor(i, j));
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nNao e possivel subtrair essas matrizes!\n");
    }

    if (result.multiplicacao(A, B))
    {
        printf("\nResultado da Multiplicacao da Matriz A e B:\n");

        for (int i = 0; i < result.getL(); i++)
        {
            for (int j = 0; j < result.getC(); j++)
            {
                printf("%d ", result.getValor(i, j));
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nNao e possivel multiplicar essas matrizes!\n");
    }
}