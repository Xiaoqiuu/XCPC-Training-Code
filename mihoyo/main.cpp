#include <iostream>

using std::cin;
using std::cout;

#define akitama return 0

class box {
    virtual void print();
};

class Box : box {
    public:
        double len;
        double width;
        double height;
        void print(void);

        double getVolume() {
            return len * width * height;
        }

};

class virtualBox : Box {

};

 void Box::print() { cout << "This is a Mihoyo test.\n"; }

signed main() {
    Box b1;
    b1.print();
    // Box b2
    cout << "请输入长、宽、高：\n";
    cin >> b1.len >> b1.width >> b1.height;
    cout << "盒子的体积为：";
    cout << b1.getVolume() << std::endl;
    akitama;
}