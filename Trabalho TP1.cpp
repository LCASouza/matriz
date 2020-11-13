#include <iostream>
#include "Matriz.h"
#include "Arquivo.h"

using namespace std;

int main()
{
    //Geracao de arquivos, no final do script.
    Arquivo archiveIn;

    int l, c, x; //Linhas da matriz, colunas e valores que serao inseridos.
    bool somaSub=false, mult=false, potA=false, potB=false; //Verificar se e possivel somar, subtrair, multplicar ou potenciar.

    printf("Digite as dimensoes da Matriz A: ");
    scanf("%d %d", &l, &c);

    Matriz A(l, c);

    printf("Insira os elementos da matriz A:\n");
    A.setMatriz();

    //Arquivo
    //A Matriz que sera lida de um arquivo, será igual a A * 2!

    Matriz matrizArquivo(A.getL(), A.getC());
    matrizArquivo.igual(A);
    matrizArquivo.multiplicacaoK(2);

    archiveIn.gravarMatrizParaLeitura(matrizArquivo);
    archiveIn.pegarMatriz(matrizArquivo);

    //Arquivo

    printf("\nDigite as dimensoes da Matriz B: ");
    scanf("%d %d", &l, &c);

    Matriz B(l, c);

    printf("Insira os elementos da matriz B:\n");
    B.setMatriz();

    //Instanciando as Matrizes:
    Matriz resultSoma(A.getL(), A.getC());
    Matriz resultSub(A.getL(), A.getC());
    Matriz resultMult(A.getC(), B.getL());
    Matriz transpostaA(A.getC(), A.getL());
    Matriz transpostaB(B.getC(), B.getL());
    Matriz opostaA(A.getL(), A.getC());
    Matriz opostaB(B.getL(), B.getC());
    Matriz potenciadaA(A.getL(), A.getC());
    Matriz potenciadaB(B.getL(), B.getC());
    Matriz multAK(A.getL(), A.getC());
    Matriz multBK(B.getL(), B.getC());

    transpostaA.transposta(A);
    transpostaB.transposta(B);
    opostaA.oposta(A);
    opostaB.oposta(B);
    potenciadaA.igual(A);
    potenciadaB.igual(B);
    multAK.igual(A);
    multBK.igual(B);

    printf("\nMatriz Transposta de A:\n");
    transpostaA.getMatriz();

    printf("\nMatriz Transposta de B:\n");
    transpostaB.getMatriz();

    printf("\nMatriz Oposta de A:\n");
    opostaA.getMatriz();

    printf("\nMatriz Oposta de B:\n");
    opostaB.getMatriz();


    if (resultSoma.soma(A, B))
    {
        printf("\nResultado da soma da Matriz A e B:\n");
        
        resultSoma.getMatriz();
        somaSub = true;
    }
    else
    {
        printf("\nNao e possivel somar essas matrizes!\n");
    }

    if (resultSub.subtracao(A, B))
    {
        printf("\nResultado da subtracao da Matriz A e B:\n");

        resultSub.getMatriz();
    }
    else
    {
        printf("\nNao e possivel subtrair essas matrizes!\n");
    }

    if (resultMult.multiplicacao(A, B))
    {
        printf("\nResultado da Multiplicacao da Matriz A e B:\n");

        resultMult.getMatriz();
        mult = true;
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

    printf("\nInsira um Numero Para Multiplicar a Matriz A: ");
    scanf("%d", &x);
    multAK.multiplicacaoK(x);

    printf("\nResultado da Matriz A Multiplicada por %d:\n", x);
    multAK.getMatriz();

    printf("\nInsira um Numero Para Multiplicar a Matriz B: ");
    scanf("%d", &x);
    multBK.multiplicacaoK(x);

    printf("\nResultado da Matriz B Multiplicada por %d:\n", x);
    multBK.getMatriz();

    printf("\nInsira um Numero Para Potenciar a Matriz A: ");
    scanf("%d", &x);

    if (potenciadaA.potencia(A, x))
    {
        printf("\nResultado da Matriz A Elevada a %d:\n", x);
        
        potenciadaA.getMatriz();
        potA = true;
    }
    else
    {
        printf("\nNao e Possivel Potenciar a Matriz B!\n");
    }

    printf("\nInsira um Numero Para Potenciar a Matriz B: ");
    scanf("%d", &x);

    if (potenciadaB.potencia(B, x))
    {
        printf("\nResultado da Matriz B Elevada a %d:\n", x);
        
        potenciadaB.getMatriz();
        potB = true;
    }
    else
    {
        printf("\nNao e Possivel Potenciar a Matriz B!\n");
    }

    printf("\n\nMatriz A:\n");

    if (transpostaA.simetrica(A))
    {
        printf("\n  A Matriz A eh Simetrica!\n");
    }
    else
    {
        printf("\n  A Matriz A nao eh Simetrica!\n");
    }

    if (opostaA.aSimetrica(transpostaA))
    {
        printf("\n  A Matriz A eh Antissimetrica!\n");
    }
    else
    {
        printf("\n  A Matriz A nao eh Antissimetrica!\n");
    }

    if (A.identidade())
    {
        printf("\n  A Matriz A eh Identidade!\n");
    }
    else
    {
        printf("\n  A Matriz A nao eh Identidade!\n");
    }

    if (A.triangularS())
    {
        printf("\n  A Matriz A eh Triangular Superior!\n");
    }
    else
    {
        printf("\n  A Matriz A nao eh Triangular Superior!\n");
    }

    if (A.triangularI())
    {
        printf("\n  A Matriz A eh Triangular Inferior!\n");
    }
    else
    {
        printf("\n  A Matriz A nao eh Triangular Inferior!\n");
    }


    printf("\n\nMatriz B:\n");

    if (transpostaB.simetrica(B))
    {
        printf("\n  A Matriz B eh Simetrica!\n");
    }
    else
    {
        printf("\n  A Matriz B nao eh Simetrica!\n");
    }

    if (opostaB.aSimetrica(transpostaB))
    {
        printf("\n  A Matriz B eh Antissimetrica!\n");
    }
    else
    {
        printf("\n  A Matriz B nao eh Antissimetrica!\n");
    }

    if (B.identidade())
    {
        printf("\n  A Matriz B eh Identidade!\n");
    }
    else
    {
        printf("\n  A Matriz B nao eh Identidade!\n");
    }

    if (B.triangularS())
    {
        printf("\n  A Matriz B eh Triangular Superior!\n");
    }
    else
    {
        printf("\n  A Matriz B nao eh Triangular Superior!\n");
    }

    if (B.triangularI())
    {
        printf("\n  A Matriz B eh Triangular Inferior!\n");
    }
    else
    {
        printf("\n  A Matriz B nao eh Triangular Inferior!\n");
    }

    //Arquivo -------------------------------------------------------------

    Arquivo archive;

    archive.gravarFrase("Matriz Recuperada do Arquivo lerMatrizes.txt, que foi deletado:\n");
    archive.gravarMatriz(matrizArquivo);
    archive.gravarFrase("Essa matriz eh a copia da matriz A * 2!\n");

    archive.gravarFrase("\nMatriz A:\n");
    archive.gravarMatriz(A);

    archive.gravarFrase("\nMatriz B:\n");
    archive.gravarMatriz(B);

    if (somaSub)
    {
        archive.gravarFrase("\nSoma da Matriz A e B:\n");
        archive.gravarMatriz(resultSoma);

        archive.gravarFrase("\nSubtracao da Matriz A e B:\n");
        archive.gravarMatriz(resultSub);
    }
    else
    {
        archive.gravarFrase("\nNao foi possivel somar ou subtrair essas matrizes!\n");
    }

    if (mult)
    {
        archive.gravarFrase("\nMultiplicacao da Matriz A e B:\n");
        archive.gravarMatriz(resultMult);
    }
    else
    {
        archive.gravarFrase("\nNao foi possivel multiplicar essas matrizes!\n");
    }

    if (potA)
    {
        archive.gravarFrase("\nPotencia da Matriz A por X:\n");
        archive.gravarMatriz(potenciadaA);
    }
    else
    {
        archive.gravarFrase("\nNao foi possivel potenciar a Matriz A!\n");
    }

    if (potB)
    {
        archive.gravarFrase("\nPotencia da Matriz B por X:\n");
        archive.gravarMatriz(potenciadaB);
    }
    else
    {
        archive.gravarFrase("\nNao foi possivel potenciar a Matriz B!\n");
    }

    archive.gravarFrase("\nMultiplicacao da Matriz A por K:\n");
    archive.gravarMatriz(multAK);

    archive.gravarFrase("\nMultiplicacao da Matriz B por K:\n");
    archive.gravarMatriz(multBK);

    archive.gravarFrase("\nMatriz Transposta de A:\n");
    archive.gravarMatriz(transpostaA);

    archive.gravarFrase("\nMatriz Transposta de B:\n");
    archive.gravarMatriz(transpostaB);

    archive.gravarFrase("\nMatriz Oposta de A:\n");
    archive.gravarMatriz(opostaA);

    archive.gravarFrase("\nMatriz Oposta de B:\n");
    archive.gravarMatriz(opostaB);

    //Arquivo -------------------------------------------------------------
}