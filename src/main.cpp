#include <iostream>
#include "../include/life.h"
#include "../include/matriz.h"
#include <fstream>
#include "../include/canvas.h"
#include <string>
#include <sys/stat.h>
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    int nlinhas, ncol;
    //entrada do arquivo

    int ligado = 1;
    int geracao = 0;
    int maxGen = -1;
    int fps = 60;
    bool img =false;
    int blocksize = 5;
    
    Color green(0,255,0);
    Color red(255,0,0);
    Color black(0,0,0);
    Color crimsom(153,0,0);
    Color dark_green(0,100,0);
    Color deep_sky_blue(0,191,255);
    Color dodger_blue(30,144,255);
    Color light_blue(173,216,230);
    Color light_grey(211,211,211);
    Color light_yellow(255,255,224);
    Color steel_blue(70,130,180);
    Color yellow(255,255,0);
    Color white(255,255,255);
    
    std::string outfile = "output.txt";
    std::string path = "vazio";
    std::string imgdir = "../data/";
    Color bkgcolor = green;
    Color alivecolor = red;
    std::string cor;
    std::ofstream myfile;

if(argc > 14){
        std::cout<<"Too many arguments, please refer to the following argument usage:\n\n";
        std::cout<< "--help -> Print this help text.\n";
        std::cout<< "--path -> Specifies the input file";
        std::cout<< "--imgdir <path> -> Specify directory where output images are written to.\n";
        std::cout<< "--maxgen <num> -> Maximum number of generations to simulate.\n";
        std::cout<< "--fps <num> -> Number of generations presented per second.\n";
        std::cout<< "--bkgcolor <color> -> Color name for the background. Default GREEN.\n";
        std::cout<< "--blocksize <num> -> Pixel size of a cell. Default = 5.\n";
        std::cout<< "--alivecolor <color> -> Color name for representing alive cells. Default RED.\n";
        std::cout<< "--outfile <filename> -> Write the text representation of the simulation ";
        std::cout<< "to the given filename.:\n";
        std::cout<< "Available colors are:\n\n";
        std::cout<< "BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE \n";
        std::cout<< "GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE \n";
        std::cout<< "WHITE YELLOW\n\n";
        ligado = 0;
    }
    else{
        for(auto i{1}; i < argc; i++){
            std::string str = argv[i];
            for (char & c : str){
                c = std::tolower(c);
            }
            //caminho
            if (str == "--path"|| str == "-path"){
                if (i+1 == argc){
                    std::cout<<"Please insert the path!\n";
                    ligado = 0;
                }
                else{
                    path = argv[++i];
                }
                try {
                     std::ifstream input(path);
                }
                catch( const std::invalid_argument& e ){
                    std::cout<<"Invalid path!\n";
                    ligado =0;
                }
            }
            if (str == "--imgdir"|| str == "-imgdir"){
                if (i+1 == argc){
                    std::cout<<"Please insert the path for the imgdir!\n";
                    ligado = 0;
                }
                else{
                    imgdir = argv[++i];
                    img = true;
                }
            }
            else if (str == "--maxgen" || str == "-maxgen"){
                if (i+1 == argc){
                    std::cout<<"Please insert the corresponding number of max generetions!\n";
                    ligado =0;
                }
                try {
                    maxGen = std::stoi( argv[++i] );
                }
                catch( const std::invalid_argument& e ){
                    std::cout<<"Invalid value for max gen!\n";
                    ligado = 0;
                }
                if (maxGen < 1){
                    std::cout<<"Number of max gen is to low!\n";
                    ligado = 0;
                }
            }
            else if (str == "--fps" || str == "-fps"){
                if (i+1 == argc){
                    std::cout<<"Please insert the corresponding number of FPS!\n";
                    ligado = 0;
                }
                try {
                    fps = std::stoi( argv[++i] );
                }
                catch( const std::invalid_argument& e ){
                    std::cout<<"Invalid value for FPS!\n";
                }
                if (fps < 1){
                    std::cout<<"Number of FPS is to low!\n";
                    ligado = 0;
                }
            }
            else if (str == "--outfile" || str == "-outfile"){
                if (i+1 == argc){
                    std::cout<<"Please insert the corresponding name for the outfile!\n";
                    ligado = 0;
                }
                else{
                    outfile = argv[++i];
                }
            }
            else if (str == "--alivecolor" || str == "-alivecolor"){
                if (i+1 == argc){
                    std::cout<<"Please insert the color!\n";
                    ligado = 0;
                }
                else{
                    cor = argv[++i];
                        if (cor == "green"){
                            alivecolor = green;
                        }
                        else if (cor == "red"){
                            alivecolor = red;
                        }
                        else if( cor== "white" ){
                            alivecolor = white;
                        }
                        else if( cor== "black" ){
                            alivecolor = black;
                        }
                        else if( cor== "crimsom"){
                            alivecolor =crimsom;
                        }
                        else if( cor== "deep_sky_blue" ){
                            alivecolor = deep_sky_blue;
                        }
                        else if( cor== "yellow" ){
                            alivecolor = yellow;
                        }
                        else if( cor== "light_yellow"){
                            alivecolor = light_yellow;
                        }
                        else if( cor== "light_blue" ){
                            alivecolor = light_blue;
                        }
                        else if( cor== "dodger_blue" ){
                            alivecolor = dodger_blue;
                        }
                        else if( cor==  "light_grey"){
                            alivecolor = light_grey;
                        }
                        else if( cor== "steel_blue" ){
                            alivecolor = steel_blue;
                        }
                        else if( cor== "dark_green"){
                            alivecolor = dark_green;
                        }
                        else{
                            std::cout << "Please enter an available color!\n";
                            ligado = 0;
                        }
                }
            }
            else if (str == "--bkgcolor" || str == "-bkgcolor"){
                if (i+1 == argc){
                    std::cout<<"Please insert the color for the BKG!\n";
                    ligado = 0;
                }
                else{
                    cor = argv[++i];
                        if (cor == "green"){
                            bkgcolor = green;
                        }
                        else if (cor == "red"){
                            bkgcolor = red;
                        }
                        else if( cor== "white" ){
                            bkgcolor = white;
                        }
                        else if( cor== "black" ){
                            bkgcolor = black;
                        }
                        else if( cor== "crimsom"){
                            bkgcolor =crimsom;
                        }
                        else if( cor== "deep_sky_blue" ){
                            bkgcolor = deep_sky_blue;
                        }
                        else if( cor== "yellow" ){
                            bkgcolor = yellow;
                        }
                        else if( cor== "light_yellow"){
                            bkgcolor = light_yellow;
                        }
                        else if( cor== "light_blue" ){
                            bkgcolor = light_blue;
                        }
                        else if( cor== "dodger_blue" ){
                            bkgcolor = dodger_blue;
                        }
                        else if( cor==  "light_grey"){
                            bkgcolor = light_grey;
                        }
                        else if( cor== "steel_blue" ){
                            bkgcolor = steel_blue;
                        }
                        else if( cor== "dark_green"){
                            bkgcolor = dark_green;
                        }
                        else{
                            std::cout << "Please enter an available color!\n";
                            ligado = 0;
                        }
                }
            }
            else if(str == "-help" || str == "--help"){
                std::cout<< "--help -> Print this help text.\n";
                std::cout<< "--path -> Specifies the input file";
                std::cout<< "--imgdir <path> -> Specify directory where output images are written to.\n";
                std::cout<< "--maxgen <num> -> Maximum number of generations to simulate.\n";
                std::cout<< "--fps <num> -> Number of generations presented per second.\n";
                std::cout<< "--bkgcolor <color> -> Color name for the background. Default GREEN.\n";
                std::cout<< "--blocksize <num> -> Pixel size of a cell. Default = 5.\n";
                std::cout<< "--alivecolor <color> -> Color name for representing alive cells. Default RED.\n";
                std::cout<< "--outfile <filename> -> Write the text representation of the simulation ";
                std::cout<< "to the given filename.:\n\n";
                std::cout<< "Available colors are:\n";
                std::cout<< "BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE \n";
                std::cout<< "GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE \n";
                std::cout<< "WHITE YELLOW\n\n";
            }
            else if (str == "--blocksize" || str == "-blocksize"){
                if (i+1 == argc){
                    std::cout<<"Please insert the corresponding number of block size!\n";
                    ligado =0;
                }
                try {
                    blocksize = std::stoi( argv[++i] );
                }
                catch( const std::invalid_argument& e ){
                    std::cout<<"Invalid value for block size!\n";
                    ligado = 0;
                }
                if (blocksize < 1){
                    std::cout<<"Number of block size is to low!\n";
                    ligado = 0;
                }
            }
        }    
    }

    int ms = 1000/fps;
    nlinhas = 10 + 4;
    ncol = 10 + 4;

    //mapas para armazenamento de pontos
    std::multimap <int, int> vivos = readInputFile(path, nlinhas, ncol);
    std::multimap <int, int> vivosVizinhos;
    
    //Criação das matrizes

    Block deadBlock(blocksize, bkgcolor);
    
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

    //determina que aguns pontos da matriz serão um
    for(std::pair<int,int> p : vivos){
        mat[p.first][p.second] = 1;
    }

    iniciarBorda(nlinhas, ncol, mat);

    copiarMat(mat2, mat, nlinhas, ncol);

    //abre o arquivo com a primeira geração (estado inicial)
    myfile.open (std::string("../data/" + outfile), std::ios::trunc);
    if (path != "vazio"){
        printMat(nlinhas, ncol, mat, myfile, geracao);
        if (img == false){
            printMat(nlinhas, ncol, mat);
        }
    }
    Life* jogo = new Life();

    while (ligado == 1){
        Board board(deadBlock, ncol-4, nlinhas-4);
        geracao++;
        jogo->set_alive(mat, nlinhas, ncol,vivos);
        jogo->contar_vizinho(mat, mat2,vivos);
        jogo->guardar_vizinhos(mat,mat2,vivos, vivosVizinhos);
        jogo->contar_vizinho(mat,mat2,vivosVizinhos);
        copiarMat(mat, mat2, nlinhas, ncol);
        std::cout << "\n";
        ligado = jogo->pararExec(chave, ligado, maxGen, geracao);
        for(std::pair<int,int> vivo : vivos){
            board.setBlockColor(vivo.first-2, vivo.second-2, alivecolor);
        }
        std::string filename = imgdir + "generation_" + std::to_string(geracao)+".ppm";
        if (img == true ){
            board.printBoard(filename);
        }
        if (ligado == 1){
            myfile.open (std::string("../data/" + outfile), std::ios::app);
            printMat(nlinhas, ncol, mat, myfile, geracao);
            if (img == false){
                printMat(nlinhas,ncol,mat);
                //delay do fps
                std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            }
        }
    }
    return 0;
}
