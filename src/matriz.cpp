#include "../include/matriz.h"

//faz uma cópia d euma matriz para a outra
void copiarMat(std::vector<std::vector<int>> &mat, std::vector<std::vector<int>> &mat2, int nlinhas, int ncol){
    for(int i = 0;i < nlinhas; ++i)
    {
        for (int j = 0;j < ncol; ++j)
        {
            mat[i][j] = mat2[i][j];
        }
    }
}
//iniciando os valores da borda da matriz com 3
void iniciarBorda(int nlinhas, int ncol, std::vector<std::vector<int>> &mat){
    for(int i = 0;i < 2; ++i)
    {
        for(int j = 0;j < ncol; ++j)
        {
            mat[i][j] = 3;
        }
    }
    for(int i = nlinhas -2;i < nlinhas; ++i)
    {
        for(int j = 0;j < ncol; ++j)
        {
            mat[i][j] = 3;
        }
    }
    for(int i = 0;i < nlinhas; ++i)
    {
        for(int j = 0;j < 2; ++j)
        {
            mat[i][j] = 3;
        }
    }
    for(int i = 0;i < nlinhas; ++i)
    {
        for(int j = ncol -2;j < ncol; ++j)
        {
            mat[i][j] = 3;
        }
    }

}

//printa a matriz no console com os valores interpretados pelo progama
void printMat(int nlinhas, int ncol,std::vector<std::vector<int>> &mat){
    for(int i = 0;i < nlinhas; ++i)
    {
        for (int j = 0;j < ncol; ++j)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//printa a matriz em um .txt, chamado output, com os valores para interpretação visual do usuário
void printMat(int nlinhas, int ncol,std::vector<std::vector<int>> &mat, std::ofstream &myfile, int geracao){
    myfile << "Generation " << geracao << std::endl;
    for(int i = 2;i < nlinhas - 2; ++i)
    {
        myfile << "[";
        for (int j = 2;j < ncol - 2; ++j)
        {
            if (mat[i][j] == 0){
                myfile << " ";
            }
            else if(mat[i][j] == 1){
                myfile << "*";
            }
        }
        myfile << "]";
        myfile << std::endl;
    }
    myfile.close();
}