#ifndef Life_H

#define Life_H

#include <map>
#include <bits/stdc++.h>
#include <string>
#include <vector>

class Life{
    public:
        std::string hash;
        void set_alive(std::vector<std::vector<int>> &mat, int nlinhas, int ncol,std::multimap <int, int> &map);
        void contar_vizinho(std::vector<std::vector<int>> &mat,std::vector<std::vector<int>> &mat2,std::multimap <int, int> &map);
        void guardar_vizinhos(std::vector<std::vector<int>> &mat,std::vector<std::vector<int>> &mat2, std::multimap <int, int> &map,std::multimap <int, int> &map2);
        int pararExec(std::vector<std::string> &chave, int ligado);

};

#endif