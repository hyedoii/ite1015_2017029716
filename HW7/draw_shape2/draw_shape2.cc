#include <iostream>
#include "draw_shape2.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col){
    row_ = row;
    col_ = col;
    canvas_.assign(col_, "");
    for(int i = 0; i < col_; i++){
        for(int j = 0; j < row_; j++){
            canvas_[i] += ".";
        }
    }
}

Canvas::~Canvas(){}

// canvas 크기를 w*h로 변경한다. 그려진 내용은 보존한다.
void Canvas::Resize(size_t w, size_t h){
    canvas_.assign(h, "");
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            canvas_[i] += ".";
        }
    }
    row_ = w;
    col_ = h;
}

// (x,y) 위치에 문자를 그린다. 범위 밖의 x,y는 무시한다.
bool Canvas::Draw(int x, int y, char brush){
    //if(x>row_||x<0||y>col_||y<0){ return false; }
    canvas_[x][y] = brush;
    return true;
}

// 그려진 내용을 모두 지운다. ('.'으로 초기화)
void Canvas::Clear(){
    for(int i= 0; i < col_; ++i){
        for(int j=0; j<row_; ++j){
            canvas_[i][j] = '.';
        }
    }
}

// 그려진 모양을 저장할 수 있도록 데이터멤버를 정의 ( resize 가능에 주의 )
ostream& operator<<(ostream& os, const Canvas& c){
    int count = 0;
    os << " ";
    for(int i = 0; i < c.row_; ++i){
        if(count > 9) { count = count - 10;}
        os << count;
        ++count;
    }
    os << endl;
    for(int i = 0; i < c.col_; ++i){
        os << i;
        for(int j = 0; j < c.row_ ; ++j){
            os << c.canvas_[i][j];
        }
        os << endl;
    }
    return os;
}
Shape::Shape() {}
Shape::~Shape() {}
void Shape::Draw(Canvas* canvas) const {}
int Shape::x() {
    return x_;
}
int Shape::y() {
    return y_;
}
int Shape::h() {
    return h_;
}
int Shape::w() {
    return w_;
}
char Shape::brush() {
    return brush_;
}
string Shape::type() {
    return type_;
}

Rectangle::Rectangle(int x, int y, int h, int w, char brush){
    x_ = x;
    y_ = y;
    h_ = h;
    w_ = w;
    brush_ = brush;
    type_ = "rect";
}
Rectangle::~Rectangle(){}
int Rectangle::x(){
    return x_;
}
void Rectangle::Draw(Canvas* canvas) const {
    for(int j = x_; j < x_ + w_; j++){
        for(int k = y_; k < y_ + h_; k++){
            canvas->Draw(j, k, brush_);
        }
    }
}
int Rectangle::y(){
    return y_;
}
int Rectangle::h(){
    return h_;
}
int Rectangle::w(){
    return w_;
}
char Rectangle::brush(){
    return brush_;
}
string Rectangle::type(){
    return type_;
}

UpTriangle::UpTriangle(int x, int y, int h, char brush){
    x_ = x;
    y_ = y;
    h_ = h;
    w_ = h;
    brush_ = brush;
    type_ = "tri_up";
}
UpTriangle::~UpTriangle(){}
void UpTriangle::Draw(Canvas* canvas) const{
    for(int j = y_ ; j < y_ + h_; ++j){
        for(int k = x_ - (j - y_); k <= x_ + (j - y_); ++k){
            canvas->Draw(j, k, brush_);
        }
    }
}
int UpTriangle::x(){
    return x_;
}
int UpTriangle::y(){
    return y_;
}
int UpTriangle::h(){
    return h_;
}
int UpTriangle::w(){
    return w_;
}
char UpTriangle::brush(){
    return brush_;
}
string UpTriangle::type(){
    return type_;
}

DownTriangle::DownTriangle(int x, int y, int h, char brush){
    x_ = x;
    y_ = y;
    h_ = h;
    w_ = h;
    brush_ = brush;
    type_ = "tir_down";
}
DownTriangle::~DownTriangle(){}
void DownTriangle::Draw(Canvas* canvas) const {
    for(int j = y_; j > y_ - h_; j--){
        for(int k = x_ - (-j + y_); k <= x_ + (-j + y_); k++){
            canvas->Draw(j, k, brush_);
        }
    }
}
int DownTriangle::x(){
    return x_;
}
int DownTriangle::y(){
    return y_;
}
int DownTriangle::h(){
    return h_;
}
int DownTriangle::w(){
    return w_;
}
char DownTriangle::brush(){
    return brush_;
}
string DownTriangle::type(){
    return type_;
}

Diamond::Diamond(int x, int y, int h, char brush){
    x_ = x;
    y_ = y;
    h_ = h;
    w_ = h;
    brush_ = brush;
    type_ = "diamond";
}
Diamond::~Diamond() {}
void Diamond::Draw(Canvas* canvas) const {
    for(int j = y_ ; j < y_ + h_ + 1 ; ++j){
        for(int k = x_ - (j - y_); k <= x_ + (j - y_); ++k){
            canvas->Draw(j, k, brush_);
        }
    }
    for(int j = y_ + 2*h_; j > y_ + h_; j--){
        for(int k = x_ -(-j + y_ + 2*h_); k <= x_ + (-j + y_ + 2*h_); k++){
            canvas->Draw(j, k, brush_);
        }
    }
}
int Diamond::x(){
    return x_;
}
int Diamond::y(){
    return y_;
}
int Diamond::h(){
    return h_;
}
int Diamond::w(){
    return w_;
}
char Diamond::brush(){
    return brush_;
}
string Diamond::type(){
    return type_;
}
