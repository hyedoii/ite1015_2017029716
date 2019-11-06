#include <iostream>
#include <string>
#include "draw_shape.h"


using namespace std;

int main()
{
    int row, col;
    cin>>col>>row;
    Canvas canvas(row, col);
    canvas.Draw(cout);
    Shape shape;
    
    while(true)
    {
        string word;
        
        cin>>word;
        
        if(word=="add")
        {
            cin>>word;
            
            if(word=="rect")
            {
                shape.type = RECTANGLE;
                cin >> shape.y >> shape.x >> shape.height >> shape.width >> shape.brush;
                int a = canvas.AddShape(shape);
                if(a == -1 || a == -2){
                    if(a == -1) cout << "error out of canvas" << endl;
                    if(a == -2) cout << "error invalid input" << endl;
                }
            }
            
            else if(word=="tri_up")
            {
                shape.type = TRIANGLE_UP;
                cin >> shape.y >> shape.x >> shape.width >> shape.brush;
                int a = canvas.AddShape(shape);
                if(a == -1 || a == -2){
                    if(a == -1) cout << "error out of canvas" << endl;
                    if(a == -2) cout << "error invalid input" << endl;
                }
            }
            
            else if(word=="tri_down")
            {
                shape.type = TRIANGLE_DOWN;
                cin >> shape.y >> shape.x >> shape.width >> shape.brush;
                int a = canvas.AddShape(shape);
                if(a == -1 || a == -2){
                    if(a == -1) cout << "error out of canvas" << endl;
                    if(a == -2) cout << "error invalid input" << endl;
                }
            }
            else
                break;
        }
        
        else if(word=="delete")
        {
            int index;
            cin >> index;
            canvas.DeleteShape(index);
        }
        
        else if(word=="draw")
        {
            canvas.Draw(cout);
        }
        else if(word=="dump")
        {
            canvas.Dump(cout);
        }
        
        else
            break;
    }
}
