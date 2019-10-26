#include "../include/canvas.h"


int main(){
    Color red(255,0,0);
    Color blue(0,0,255);
    Color green(0,255,0);
    Color white(255,255,255);
    Color black;
    Block deadBlock(30, green);
    Board board(deadBlock, 20, 20);
    for(size_t i{0}; i < 20; i++){
        for(size_t j{0}; j < 20; j++){
            if((i+j)%5 == 0){
                board.setBlockColor(i,j,blue);
            }
            else if ((i+j)%2 == 0){
                board.setBlockColor(i,j,red);
            }
            
        }
    }
    std::string filename = "teste.ppm";
    board.printBoard(filename);

    return 0;
}