#ifndef _DRAW_SHAPE2_H_
#define _DRAW_SHAPE2_H_
#include <vector>

using namespace std;

class Canvas
{
public:
    Canvas(size_t row, size_t col);
    ~Canvas();
    
    // canvas 크기를 w*h로 변경한다. 그려진 내용은 보존한다.
    void Resize(size_t w, size_t h);
    
    // (x,y) 위치에 문자를 그린다. 범위 밖의 x,y는 무시한다.
    bool Draw(int x, int y, char brush);
    
    // 그려진 내용을 모두 지운다. ('.'으로 초기화)
    void Clear();
    
private:
    size_t row_, col_;
    vector<string> canvas_;
    // 그려진 모양을 저장할 수 있도록 데이터멤버를 정의 ( resize 가능에 주의 )
    friend ostream& operator<<(ostream& os, const Canvas& c);
};

class Shape {
public:
    Shape();
    virtual ~Shape();
    virtual void Draw(Canvas* canvas) const = 0;
    virtual int x();
    virtual int y();
    virtual int h();
    virtual int w();
    virtual char brush();
    virtual string type();
protected:
    int x_, y_, h_, w_;
    char brush_;
    string type_;
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int h, int w, char brush);
    ~Rectangle();
    void Draw(Canvas* canvas) const;
    int x();
    int y();
    int h();
    int w();
    char brush();
    string type();
    
protected:
    int x_, y_, h_, w_;
    char brush_;
    string type_;
};
class UpTriangle : public Shape {
public:
    UpTriangle(int x, int y, int h, char brush);
    ~UpTriangle();
    void Draw(Canvas* canvas) const;
    int x();
    int y();
    int h();
    int w();
    char brush();
    string type();
    
protected:
    int x_, y_, h_, w_;
    char brush_;
    string type_;
};
class DownTriangle : public Shape {
public:
    DownTriangle(int x, int y, int h, char brush);
    ~DownTriangle();
    void Draw(Canvas* canvas) const;
    int x();
    int y();
    int h();
    int w();
    char brush();
    string type();
    
protected:
    int x_, y_, h_, w_;
    char brush_;
    string type_;
};
class Diamond : public Shape {
public:
    Diamond(int x, int y, int h, char brush);
    ~Diamond();
    void Draw(Canvas* canvas) const;
    int x();
    int y();
    int h();
    int w();
    char brush();
    string type();
    
protected:
    int x_, y_, h_, w_;
    char brush_;
    string type_;
};

//istream& operator>>(istream& is, Rectangle& r);
//istream& operator>>(istream& is, UpTriangle& t);
//istream& operator>>(istream& is, DownTriangle& d);
//istream& operator>>(istream& is, Diamond& dm);

#endif


