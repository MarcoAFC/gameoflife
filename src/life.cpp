#include "../include/life.h"
#include "../include/matriz.h"
    /*!
    * A function that seeks the alive cells and places them in a map, while generating a hash for rule verification.
    * \param mat the matrix representing the table.
    * \param nlinhas the number of lines in the matrix.
    * \param ncol the number of columns in the matrix.
    * \param map the map where the cells are stored.
    */
void Life::set_alive(std::vector<std::vector<int>> &mat, int nlinhas, int ncol,std::multimap <int, int> &map){
        hash = "a";
        map.clear();
        //iniciarBorda(nlinhas, ncol, mat);
        for(int i = 2;i < nlinhas - 2; ++i)
        {
            for (int j = 2;j < ncol - 2; ++j)
            {
                if(mat[i][j] == 1){
                    map.insert(std::pair<int,int>(i,j));
                    hash = std::string( hash + "l" + std::to_string(i) + "c" + std::to_string(j));
                }
            }
        }
        /*
        for(auto p : map) {
            std::cout << p.first << ", " << p.second << "\n";
        }*/
    }
    /*!
    * A function that counts the neighbours of alive cells and them and checks if they pass the rules to remain alive.
    * \param mat the matrix representing the table.
    * \param mat2 the matrix representing the new shape of the table.
    * \param map the map where the alive cells are stored.
    */    
void Life::contar_vizinho(std::vector<std::vector<int>> &mat,std::vector<std::vector<int>> &mat2,std::multimap <int, int> &map){
        for(auto p : map) {
            std::cout << p.first << ", " << p.second << "\n";
            int vizinhos = 0;
            if (mat[p.first-1][p.second-1] == 1){
                vizinhos++;
            }
            if (mat[p.first][p.second-1] == 1){
                vizinhos++;
            }
            if (mat[p.first+1][p.second-1] == 1){
                vizinhos++;
            }
            if (mat[p.first-1][p.second] == 1){
                vizinhos++;
            }
            if (mat[p.first+1][p.second] == 1){
                vizinhos++;
            }
            if (mat[p.first-1][p.second+1] == 1){
                vizinhos++;
            }
            if (mat[p.first][p.second+1] == 1){
                vizinhos++;
            }
            if (mat[p.first+1][p.second+1] == 1){
                vizinhos++;
            }
            
            //eventos para celula viva
            if(mat[p.first][p.second] == 1){
                if(vizinhos < 2){
                    //morre de solidão
                    mat2[p.first][p.second] = 0;
                }
                else if(vizinhos > 3){
                    //morre sufocada
                    mat2[p.first][p.second] = 0;
                }
                else{
                    mat2[p.first][p.second] = 1;
                }
            }
            //evento para celula morta
            else if(vizinhos == 3){
                mat2[p.first][p.second] = 1;
            }
        }
        std::cout<<"\n\n\n";
    }
   /*!
    * A function that stores the positions of cells with potential changes.
    * \param mat the matrix representing the table.
    * \param mat2 the matrix representing the new shape of the table.
    * \param map the map where the alive cells are stored.
    * \param map2 the map where the neighbours of the alive cells are stored.
    */   
void Life::guardar_vizinhos(std::vector<std::vector<int>> &mat,std::vector<std::vector<int>> &mat2, std::multimap <int, int> &map,std::multimap <int, int> &map2){
        map2.clear();
        for(auto p5 : map){
            for(int cont1=-1;cont1 <=1; cont1++){
                for (int cont2 = -1;cont2 <=1; cont2++){
                    if (cont1 !=0 && cont2 != 0){
                        map2.insert(std::pair<int,int>((p5.first+cont1),(p5.second+cont2)));
                    }
                }
            }
        }
        /*for(auto p : map2) {
            std::cout << p.first << ", " << p.second << "\n";
        }*/
    }
   /*!
    * A function that checks if the system has reached any of the conditions to stop execution.
    * \param chave a hash representing the current system. It is checked to see if the system has happened before.
    * \param ligado a verification to see if the system if working properly.
    * \param maxgen the user-set maximum number of iterations.
    * \param geracao the current number of iterations.
    */    
int Life::pararExec(std::vector<std::string> &chave, int ligado, int maxGen, int geracao){
        //primeira geração para abrir o vetor
        if (maxGen == geracao){
            return 0;
        }
        if (hash == "a"){
            return 0;
        }
        for(unsigned int i=0; i<chave.size(); i++)
        {
            if(chave[i] == hash){
                return 0;
            }
        }
        if(chave.size() == 0){
            chave.push_back(hash); 
            return 1;
        }
        chave.push_back(hash);
        return 1;
    }
