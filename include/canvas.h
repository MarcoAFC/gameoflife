#pragma once
#include <iostream>
#include <fstream>
#include <vector>
    /*!
     * Class to store a color variable in RGB format.
     * \param red the value of red from 0 to 255.
     * \param green the value of green from 0 to 255.
     * \param blue the value of blue from 0 to 255.
     */

class Color{
    private:
        int rgba[3];
    public:
        //defines the color channels in rgb order. Sets alpha to 1
        Color(int red, int green, int blue){
            rgba[0] = red;
            rgba[1] = green;
            rgba[2] = blue;
        }
        Color(){
            rgba[0] = 0;
            rgba[1] = 0;
            rgba[2] = 0;
        }
        void operator= (const Color &copied){
            this->rgba[0] = copied.rgba[0];
            this->rgba[1] = copied.rgba[1];
            this->rgba[2] = copied.rgba[2];
        }

        void setColor(int red, int green, int blue){
            this->rgba[0] = red;
            this->rgba[1] = green;
            this->rgba[2] = blue;
        }
        void setRed(int red){
            this->rgba[0] = red;
        }
        void setGreen(int green){
            this->rgba[1] = green;
        }
        void setBlue(int blue){
            this->rgba[2] = blue;
        }
        int getRed(){
            return this->rgba[0];
        }
        int getGreen(){
            return this->rgba[1];
        }
        int getBlue(){
            return this->rgba[2];
        }
};
    /*!
     * Class to store a pixel block with variable size.
     * \param w the width dimension of the block.
     * \param h the heigth dimension of the block. If not given, is set to be equal to w.
     * \param color a color object to set the color of the block.
     */

class Block{
    private:
        int w;
        int h;
        Color color;
    public:
        //for non-square blocks
        Block(int w, int h, Color color){
            this->w = w;
            this->h = h;
            this->color = color;
        }
        //for square blocks
        Block(int size, Color color){
            this->w = size;
            this->h = size;
            this->color = color;
        }
        Block(){
            w = 1;
            h = 1;
            color.setColor(255,255,255);
        }
        Block(const Block &copied){
            std::cout<<"OK\n";
            w = copied.w;
            h = copied.h;
            color = copied.color;                
        }
        int hSize(){
            return h;
        }
        int wSize(){
            return w;
        }
        void setColor(Color color){
            this->color = color;
        }
        void setSize(int size){
            this->w = size;
            this->h = size;
        }
        Color getColor(){
            return this->color;
        }
        friend std::ostream& operator<<(std::ostream& os, const Block& printed){
            Color temp = printed.color;
            os<<temp.getRed()<<" "<< temp.getGreen()<< " "<<temp.getBlue()<<" ";
            return os;
        }
};

    /*!
     * Class to store and implement functions related to the entire board.
     * \param block a default block that will also be used to represent dead cells.
     * \param wBlockCount the ammount of blocks that will be fit in the width dimension.
     * \param hBlockCount the ammount of blocks that will be fit in the heigth dimension.
     */

class Board{
    private:
        int w;
        int h;
        std::vector<std::vector<Block>> blockArray;
    public:
        Board(Block& block, int wBlockCount, int hBlockCount){
            this->w = wBlockCount*block.wSize();
            this->h = hBlockCount*block.hSize();
            blockArray.resize(wBlockCount);
            for(size_t i{0}; i < wBlockCount; i++){
                blockArray[i].resize(hBlockCount);
                for (size_t j{0}; j < hBlockCount; j++){
                    blockArray[i][j] = block;                    
                }   
            }
        }
        /*!
        * Member function that sets the color of a block to a Color object input.
        * \param w the position of the block in the width dimension.
        * \param h the position of the block in the heigth dimension.
        * \param color the color to be set.
        */
        void setBlockColor(int posW, int posH, Color color){
            blockArray[posW][posH].setColor(color);
        }
        /*!
        * Member function that prints the board to a ppm file according to filename received.
        * \param w the position of the block in the width dimension.
        * \param h the position of the block in the heigth dimension.
        * \param color the color to be set.filename a string containing the name and directory to save the file.
        */
        bool printBoard(std::string & filename){
            std::ofstream file(filename, std::ios::out);
            if(not file.is_open()){
                return false;
            }
            file << "P3\n" << w << " " << h << "\n" << "255\n";
            size_t hblock = blockArray[0][0].hSize();
            size_t wblock = blockArray[0][0].wSize();
            for(size_t i{0}; i < w; i++){
                for(size_t j{0}; j < h; j++){
                    file<<blockArray[(i-i%wblock)/wblock][(j-j%hblock)/wblock];
                }
                file<<std::endl;
            }
            auto result = not file.fail();
            file.close();
            return result;
        }
};
