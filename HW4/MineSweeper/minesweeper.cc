#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include "minesweeper.h"

using namespace std;

Minesweeper::Minesweeper(){}
Minesweeper::~Minesweeper(){}

// return false when input is incorrect
bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map){
    width_ = _width;
    height_ = _height;
    map_ = _map;
    
    return true;
}
bool Minesweeper::toggleMine(int _x, int _y) {
    if(map_[_y][_x] != '*') map_[_y][_x] = '*';
    else map_[_y][_x] = '.';
    return true;
}

// return map width, height, and char
size_t Minesweeper::width() const {
    return width_;
}
size_t Minesweeper::height() const {
    return height_;
}
char Minesweeper::get(int _x, int _y) const {
    if(_x<=0||_x>width_||_y<=0||_y>height_) return ' ';
    else return map_[_y][_x];
} // return ' ' if input is illegal

////////// 4-3-2 (3 score) //////////
bool Minesweeper::setPlay(){
    if(map_.empty() == true) return false;
    else {
        return true;
    }
} // return false when map is not set
bool Minesweeper::touchMap(int _x, int _y){
    if(map_[_y][_x] == '*') return true;
    else {
        touchCount_++;
        map2[_y][_x] = map1[_y][_x];
        
        return false;
    }
}// return true when dead

int Minesweeper::touchCount() const {
    return touchCount_;
}
int Minesweeper::mineCount(int _x, int _y){
    mineCount_ = 0;
    
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    if(map_[_y][_x] == '*') mineCount_++;
    
    return mineCount_;
}

