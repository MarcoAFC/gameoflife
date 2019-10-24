#include <iostream>
#include "life.h"
#include <map>
#include <string>

void copiarMat(std::vector<std::vector<int>> &mat, std::vector<std::vector<int>> &mat2, int nlinhas, int ncol);
void iniciarBorda(int nlinhas, int ncol, std::vector<std::vector<int>> &mat);
void printMat(int nlinhas, int ncol,std::vector<std::vector<int>> &mat);