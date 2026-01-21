/*
 * @Author: Xiaoqiuu xiaoqiuuu@gmail.com
 * @Date: 2026-01-13 15:35:54
 * @LastEditors: Xiaoqiuu xiaoqiuuu@gmail.com
 * @LastEditTime: 2026-01-18 17:37:35
 * @FilePath: /workspace/mihoyo/virtual.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using std::cin;
using std::cout;

#define akitama return 0

class Person {
    private:
    int age;
    public:
    Person(){};
    explicit Person(int age) : age(age) {
        age = this->age;
    }
    virtual void fuck(void) {
        cout << "Uhh." << std::endl;
    }
};

class Student : Person {
    public:
    virtual void fuck() override {
        cout << "Fuck you, girl." << std::endl;
    }
    virtual void doFuck() {
        cout << "Fuck is completely done.\n";
    }
};

class Qiuyu : Student {
    public:
    virtual void fuck() override {
        cout << "Fuck you Bitch." << std::endl;
    }
    virtual void doFuck() override {
        cout << "Can not fuck.\n";
    }
};


signed main() {
    // 野指针
    Qiuyu* q;

    // 栈上的对象 A 被分配在堆上，并被初始化
    Qiuyu* w = new Qiuyu();
    
    // 堆上的对象 A 依然存在，但你弄丢了它的地址！你再也无法 delete 它了。这就是内存泄漏
    Qiuyu y = *new Qiuyu();
    q = w;
    q = &y;
    q->doFuck();
    q->fuck();
    q->doFuck();
    delete q;
    akitama;

}