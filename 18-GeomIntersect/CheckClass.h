#include <iostream>
using namespace std;
//рассмотреть случай, когда прямоугольники не пересекаются
class cRect {
    private:
        const double x11, x12, y12, y11, x21, x22, y21, y22;
        
    public:
        cRect(const double x1L, const double x1R, const double y1D, const double y1U, 
        const double x2L, const double x2R, const double y2D, const double y2U) : 
        x11(x1L), x12(x1R), y11(y1D), y12(y1U), x21(x2L), x22(x2R), y21(y2D), y22(y2U) {}

        void BorderInter (){

            if ((x12 > x22 && x11 > x22) || (x21 > x12 && x22 > x12) || (x12 < x21 && x11 < x21) || (x21 < x11 && x22 < x11))
                cout << "не пересекаются" << endl;
            
            else if ((y11 > y22 && y12 > y22) || (y21 > y12 && y22 > y12) || (y11 < y21 && y12 < y21) || (y21 < y11 && y22 < y11))
                cout << "не пересекаются" << endl;
            
            else cout << "пересекаются" << endl;

        }

};