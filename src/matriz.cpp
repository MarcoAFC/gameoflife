#include "../include/matriz.h"

    /*!
    * A function that copies a matrix to another.
    * \param mat the matrix receiving the copy.
    * \param mat2 the matrix being copied.
    * \param nlinhas the number of lines in the matrix.
    * \param ncol the number of columns in the matrix.
    */
void copiarMat(std::vector<std::vector<int>> &mat, std::vector<std::vector<int>> &mat2, int nlinhas, int ncol){
    for(int i = 0;i < nlinhas; ++i)
    {
        for (int j = 0;j < ncol; ++j)
        {
            mat[i][j] = mat2[i][j];
        }
    }
}
    /*!
    * Fills the buffer zone of the matrix with the number 3 to avoid errors in counting.
    * \param nlin the number of lines in the matrix.
    * \param ncol the number of columns in the matrix.
    * \param mat the matrix representing the board.
    */
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

    /*!
    * A function that prints the matrix to the terminal
    * \param nlin the number of lines in the matrix.
    * \param ncol the number of columns in the matrix.
    * \param mat the matrix representing the board.
    */
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

    /*!
    * A function that prints the matrix to a given file.
    * \param nlin the number of lines in the matrix.
    * \param ncol the number of columns in the matrix.
    * \param mat the matrix representing the board.
    * \param myfile the path to the file.
    * \param geracao the number of iterations.
    */
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
    /*!
    * A function that takes a file and generates a map with the position of the live cells.
    * \param filename the path to the file.
    * \param nlin the number of lines in the matrix, read from the file and stored in this variable.
    * \param ncol the number of columns in the matrix, read from the file and stored in this variable.
    */
std::multimap<int,int> readInputFile(std::string filename, int& nlin, int& ncol){
    std::ifstream input(filename);
    std::string line;
    std::multimap<int, int> alive;
    char marker;
    int i{0};
    if(input.is_open()){
        std::getline(input, line);
        std::istringstream linCol(line);
        linCol >> nlin >> ncol;
        nlin+=4;
        ncol+=4;
        std::getline(input, line);
        marker = line.at(0);
        while(std::getline(input, line) && (i < ncol)){
            int j{0};
            for(char& c : line){
                if(c == marker && j < ncol){
                    alive.insert(std::pair<int,int>(i+2,j+2));
                }
                j++;
            }
            i++;
        }
        return alive;
    }
    else{
        std::cout<<"UNABLE TO OPEN FILE!\n";
    }
}
