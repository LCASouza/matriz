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

    Matriz TranspostaA(A.getC(), A.getL());
    TranspostaA.transposta(A);
    printf("\nMatriz Transposta de A:\n");

    for (int i = 0; i < TranspostaA.getL(); i++)
    {
        for (int j = 0; j < TranspostaA.getC(); j++)
        {
            printf("%d ", TranspostaA.getValor(i, j));

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

    Matriz OpostaA(A.getL(), A.getC());
    OpostaA.oposta(A);
    printf("\nMatriz Oposta de A:\n");

    for (int i = 0; i < OpostaA.getL(); i++)
    {
        for (int j = 0; j < OpostaA.getC(); j++)
        {
            printf("%d ", OpostaA.getValor(i, j));
        }
        printf("\n");
    }

    Matriz OpostaB(B.getL(), B.getC());
    OpostaB.oposta(B);
    printf("\nMatriz Oposta de B:\n");

    for (int i = 0; i < OpostaB.getL(); i++)
    {
        for (int j = 0; j < OpostaB.getC(); j++)
        {
            printf("%d ", OpostaB.getValor(i, j));
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
  
    if (A.diffEqual(B))
    {
        printf("\nA matriz A e B sao iguais!\n");
    }
    else
    {
        printf("\nA matriz A e B sao diferentes!\n");
    }




    printf("\n\nMatriz A:\n");

    if (TranspostaA.simetrica(A))
    {
        printf("\n  A Matriz A e Simetrica!\n");
    }
    else
    {
        printf("\n  A Matriz A nao e Simetrica!\n");
    }

    if (OpostaA.aSimetrica(TranspostaA))
    {
        printf("\n  A Matriz A e Antissimetrica!\n");
    }
    else
    {
        printf("\n  A Matriz A nao e Antissimetrica!\n");
    }

    if (A.triangularS())
    {
        printf("\n  A Matriz A e Triangular Superior!\n");
    }
    else
    {
        printf("\n  A Matriz A nao e Triangular Superior!\n");
    }



    printf("\n\nMatriz B:\n");

    if (TranspostaB.simetrica(B))
    {
        printf("\n  A Matriz B e Simetrica!\n");
    }
    else
    {
        printf("\n  A Matriz B nao e Simetrica!\n");
    }

    if (OpostaB.aSimetrica(TranspostaB))
    {
        printf("\n  A Matriz B e Antissimetrica!\n");
    }
    else
    {
        printf("\n  A Matriz B nao e Antissimetrica!\n");
    }

    if (B.triangularS())
    {
        printf("\n  A Matriz B e Triangular Superior!\n");
    }
    else
    {
        printf("\n  A Matriz B nao e Triangular Superior!\n");
    }
}