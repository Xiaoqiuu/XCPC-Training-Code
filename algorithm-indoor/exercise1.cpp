#include <iostream>
#include <cmath>
//using namespace std;

//const int const_var = 10;

public:
    static int static_var;

    static void static_function() {
        std::cout << "Static function" << std::endl;
    };

private:
    int private_var;

protected:
    int protected_var;
int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int a[] = {1, 5, 7, 5, 3, 6, 8, 8, 4, 2, 6, 8, 3, 7, 9, 4, 7, 3, 5};
    std::sort (a, a+19);
    for (int i = 0; i < 19; i++) {
        std::cout << a[i] << " ";
    }

    return 0;    
}


//System.out::print