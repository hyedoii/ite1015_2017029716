#include <iostream>
#include <string>
#include <vector>
#include "draw_shape.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col)
{
    row_ = row, col_ = col;
}

Canvas::~Canvas() {}

int Canvas::AddShape(const Shape &s)
{
    if(s.type == RECTANGLE){
        if(s.x + (s.width - 1) / 2 < 0 || s.x + (s.width - 1) / 2 >= row_) return -1;
        if(s.y + (s.height - 1) / 2 < 0 || s.y + (s.height - 1) / 2 >= col_) return -1;
        else if(s.width % 2 == 0 || s.height % 2 == 0) return -2;
    }
    else if(s.type == TRIANGLE_UP){
        if(s.y + s.height - 1 >= col_) return -1;
        if(s.x + s.width - 1 >= row_ || s.x - s.width + 1 < 0) return -1;
    }
    else if(s.type == TRIANGLE_DOWN){
        if(s.y - s.height + 1 < 0) return -1;
        if(s.x + s.width - 1 >= row_ || s.x - s.width + 1 < 0) return -1;
    }
    shapes_.push_back(s);
    return (shapes_.size() - 1);
}

void Canvas::DeleteShape(int index)
{
    if(index < shapes_.size())
        shapes_.erase(shapes_.begin() + index);
}

void Canvas::Draw(ostream& os)
{
    vector<string> canvas_;
    canvas_.assign(col_, "");
    int count = 0;
    for(int i = 0; i < col_; i++){
        for(int j = 0; j < row_; j++){
            canvas_[i] += ".";
        }
    }
    for(int i = 0; i < shapes_.size(); i++){
        if(shapes_[i].type == RECTANGLE){
            for(int j = shapes_[i].x - (shapes_[i].width - 1) / 2; j <= shapes_[i].x + (shapes_[i].width - 1) / 2; j++){
                for(int k = shapes_[i].y - (shapes_[i].height - 1) / 2; k <= shapes_[i].y + (shapes_[i].height - 1) / 2; k++){
                    canvas_[j][k] = shapes_[i].brush;
                }
            }
        }
        else if(shapes_[i].type == TRIANGLE_UP){
            for(int j = shapes_[i].y; j < shapes_[i].y + shapes_[i].height; j++){
                for(int k = shapes_[i].x - (j - shapes_[i].y); k <= shapes_[i].x + (j - shapes_[i].y); k++){
                    canvas_[k][j] = shapes_[i].brush;
                }
            }
        }
        else if(shapes_[i].type == TRIANGLE_DOWN){
            for(int j = shapes_[i].y; j > shapes_[i].y - shapes_[i].height; j--){
                for(int k = shapes_[i].x - (-j + shapes_[i].y); k <= shapes_[i].x + (-j + shapes_[i].y); k++){
                    canvas_[k][j] = shapes_[i].brush;
                }
            }
        }
        else break;
    }
    os << " ";
    for(int i = 0; i <col_; i++){
        if(count > 9){ count = count - 10; }
        os << count;
        count++;
    }
    os << endl;
    for(int i = 0; i < row_; i++){
        os << i;
        for(int j = 0; j < col_; j++){
            os << canvas_[j][i];
        }
        os << endl;
    }
}


void Canvas::Dump(ostream& os)
{
    for(int i = 0; i < shapes_.size(); i++){
        if(shapes_[i].type == 0) os << i << " " << "rect" << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        else if(shapes_[i].type == 1) os << i << " " << "tri_up" << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        else if(shapes_[i].type == 2) os << i << " " << "tri_down" << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
    }
}
