#include <iostream>
using namespace std;
#define i32 int
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define f32 float
#define f64 double
#define akitama return 0

struct Test{
    static i32 point_x, point_y;
    void fuction1() { cout << "fuction1" << endl; }
    static void fuction2() { cout << "fuction2" << endl; }
};

i32 main() {
    Test a, b;
    a.point_x = 10;
    b.point_y = 20;
    cout << "point_x = " << Test::point_x << endl;
    Test::fuction2();
   akitama; 
}