#include <iostream>
#include "Viktor.h"

class A
{
public:
    int a = 3;
    double b = 4.5;

    A(){
        std::cout << "A default constructor is working now" << std::endl;
    };
    A(int aa, double bb) :
        a(aa), b(bb) 
    {
        std::cout << "A cousnturct is working now" << std::endl;
    };
    ~A()
    {
        std::cout << "A destructor is working now" << std::endl;
    };


    

    friend std::ostream& operator<< (std::ostream& out, const A& a);
};

std::ostream& operator<< (std::ostream& out, const A& a)
{
    out << "int a= " << a.a << " double b= " << a.b << std::endl;
    return out;

}


int main()
{
    Viktor<int> a = { 0,1,2,3 };
    a.memoryAddress(0);
    a.memoryAddress(1);
    a.memoryAddress(2);
    a.memoryAddress(3);


    Viktor<A> b = { {1,1.1},{2,2.2},{3,3.3},{4,4.4} };
    std::cout << sizeof(A) << std::endl;
    std::cout << "Size of b: " << b.m_numberOfElements << " capacity of b:" << b.m_capacity << std::endl;
    b.memoryAddress(0);
    b.memoryAddress(1);
    b.memoryAddress(2);
    b.memoryAddress(3);

    Viktor<int> bbb;




    std::cout << a[2] << std::endl;

    std::cout << "String tests: " << std::endl;

    Viktor<std::string> stringTest = { "Armor", "Balance", "Cry" };

    std::cout << stringTest[0] << std::endl;
    std::cout << stringTest[1] << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    int a11 = 5;
    int& b11 = a11;
    std::cout << &a11 << std::endl;
    std::cout << &b11 << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    Viktor<A> c = b;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    Viktor <int> c1= { 0,1,2,3,4 };


    c1.printElements();

    Viktor <int> c2 = c1;
    



    


}

