#include <iostream>
#include "../include/life.h"
#include "../include/matriz.h"
#include <fstream>

int main()
{
    int nlinhas, ncol;
    int ligado = 1;
    int geracao = 0;
    std::ofstream myfile;

    nlinhas = 10 + 4;
    ncol = 10 + 4;

    //mapas para armazenamento de pontos
    std::multimap <int, int> vivos;
    std::multimap <int, int> vivosVizinhos;
    
    //Criação das matrizes
    std::vector<std::vector<int>> mat;
    mat.resize(nlinhas, std::vector<int>(ncol));
    std::vector<std::vector<int>> mat2;
    mat2.resize(nlinhas, std::vector<int>(ncol));
    //criação do vetor de hash
    std::vector<std::string> chave;

    //iniciando ela com zero
    for(int i = 0;i < nlinhas; ++i)
    {
        for(int j = 0;j < ncol; ++j)
        {
            mat[i][j] = 0;
        }
    }

    iniciarBorda(nlinhas, ncol, mat);
    

    //determina que aguns pontos da matriz serão um (implementado apenas para teste)
    mat[5][5] = 1;
    mat[5][2] = 1;
    mat[6][5] = 1;
    mat[4][5] = 1;
    mat[9][5] = 1;
    mat[4][6] = 1;
    mat[4][7] = 1;
    mat[4][9] = 1;
    mat[9][9] = 1;
    mat[4][9] = 1;


    copiarMat(mat2, mat, nlinhas, ncol);

    //abre o arquivo com a primeira geração (estado inicial)
    myfile.open (std::string("../data/output.txt"), std::ios::trunc);
    printMat(nlinhas, ncol, mat, myfile, geracao);
    printMat(nlinhas, ncol, mat);

    Life* jogo = new Life();

    while (ligado == 1){
        geracao ++;
        jogo->set_alive(mat, nlinhas, ncol,vivos);
        jogo->contar_vizinho(mat, mat2,vivos);
        jogo->guardar_vizinhos(mat,mat2,vivos, vivosVizinhos);
        jogo->contar_vizinho(mat,mat2,vivosVizinhos);
        copiarMat(mat, mat2, nlinhas, ncol);
        std::cout << "\n";
        ligado = jogo->pararExec(chave, ligado);
        if (ligado == 1){
            myfile.open (std::string("../data/output.txt"), std::ios::app);
            printMat(nlinhas, ncol, mat, myfile, geracao);
            printMat(nlinhas,ncol,mat);
        }

    }
    return 0;
}
