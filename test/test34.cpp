//C++ 面向对象编程实验

#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        long long id;
        int age;
        double height;
        bool isMonitor;
        void set( string name, long long id, int age, double height, bool isMonitor );
        void show();

};

void Student::set(string name, long long id, int age, double height, bool isMonitor) 
{
    this->name = name;
    this->id = id;
    this->age = age;
    this->height = height;
    this->isMonitor = isMonitor;
}
void Student::show(void)
{
    cout << "检测到：\n学生姓名：" << name << "\n学生学号：" << id << endl;
    if(isMonitor)
    cout << "该学生担任班长一职。\n";
}

signed main(){
    Student stu1, stu2;
    stu1.set("Akitama", 20250001, 20, 60.2f, true);
    stu2.name = "Hprogq";
    stu2.id = 20240000 + 1;
    stu2.age = 20;
    stu2.height = 1;
    stu2.isMonitor = 0;

    stu1.show();
    stu2.show();
    return 0;
}