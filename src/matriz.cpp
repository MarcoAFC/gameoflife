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
void iniciarBorda(int nlinhas, int ncol, std::vector<std::vector<int>> &mat){
    //iniciando os valores da borda com 3
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