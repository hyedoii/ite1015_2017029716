#ifndef minesweeper_h
#define minesweeper_h

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Minesweeper
{
public:
    vector<string> map_; // getline
    vector<string> map1; // minecount
    vector<string> map2; // ___
    ////////// 4-3-1 (7 score) //////////
    Minesweeper();
    ~Minesweeper();
    
    // return false when input is incorrect
    bool setMap(size_t _width, size_t _height, vector<string>& _map);
    bool toggleMine(int _x, int _y);
    
    // return map width, height, and char
    size_t width() const;
    size_t height() const;
    char get(int _x, int _y) const; // return ' ' if input is illegal
    
    ////////// 4-3-2 (3 score) //////////
    bool setPlay(); // return false when map is not set
    bool touchMap(int _x, int _y); // return true when dead
    
    int touchCount() const;
    int mineCount(int _x, int _y);
    
private:
    // add private member variables and functions if it is needed.
    int width_, height_, touchCount_, mineCount_, stautus_;

    
};

#endif /* minesweeper_h */
