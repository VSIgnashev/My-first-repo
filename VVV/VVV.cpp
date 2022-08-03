#include <iostream>
#include "Viktor.h"
#include <vector>
#include <string>

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
    //  Viktor<int> a = { 0,1,2,3 };
    //  a.memoryAddress(0);
    //  a.memoryAddress(1);
    //  a.memoryAddress(2);
    //  a.memoryAddress(3);
    //
    //
    //  Viktor<A> b = { {1,1.1},{2,2.2},{3,3.3},{4,4.4} };
    //  std::cout << sizeof(A) << std::endl;
    //  std::cout << "Size of b: " << b.m_numberOfElements << " capacity of b:" << b.m_capacity << std::endl;
    //  b.memoryAddress(0);
    //  b.memoryAddress(1);
    //  b.memoryAddress(2);
    //  b.memoryAddress(3);
    //
    //  Viktor<int> bbb;
    //
    //
    //
    //
    //  std::cout << a[2] << std::endl;
    //
    //  std::cout << "String tests: " << std::endl;
    //
    //  Viktor<std::string> stringTest = { "Armor", "Balance", "Cry" };
    //
    //  std::cout << stringTest[0] << std::endl;
    //  std::cout << stringTest[1] << std::endl;
    //
    //  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    //
    //  int a11 = 5;
    //  int& b11 = a11;
    //  std::cout << &a11 << std::endl;
    //  std::cout << &b11 << std::endl;
    //
    //  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    //
    //  Viktor<A> c = b;
    //  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    //
    //  Viktor <int> c1= { 0,1,2,3,4 };
    //
    //
    //  c1.printElements();
    //
    //  Viktor <int> c2 = c1;
    //  
    //
    //  std::cout << "++++++++++++++++Start of testing move assignment operator+++++++++++++++++++++++++" << std::endl;
    //
   //Viktor <int> c3 = Viktor <int>{ 0, 1, 2, 3, 4 };
   //
   //c3.printElements();
   //
   //c3 = { 5,6,7,8 };
   //c3.printElements();


    //Viktor<int> c4 = { 1,2,3 };
    //Viktor<int>::iterator c5;
    //Viktor<int>::iterator v1;
    //v1.m_pointer=reinterpret_cast<int*>(c4.m_buffer.get());
    //c5 = v1;
    //
    //for (size_t i = 0; i < 3; i++)
    //{
    //    std::cout << *v1++ << std::endl;
    //    
    //
    //
    //}
    //
    //
    //for (size_t i = 0; i < 3; i++)
    //{
    //    std::cout << *++c5 << std::endl;
    //
    //
    //
    //}

    //std::vector<int> a = { 0,1,2,3 };
    //std::vector<int>::iterator b = a.begin();
    //std::cout << *b--;
    //for (size_t i = 0; i < 5; i++)
    //{
    //    std::cout << *b++;
    //}

    //Viktor<int> a = { 0,1,2,3,4 };
    ////std::cout << "start: \n";
    ////for (size_t i = 0; i < 5; i++)
    ////{
    ////    std::cout << (reinterpret_cast<int*>(a.m_buffer.get())+i) << std::endl;
    ////}
    //Viktor<int>::iterator b = reinterpret_cast<int*>(a.m_buffer.get());
    //
    //b.tryToAccesNumberOfElements();

//  std::vector<int> a = { 0,1,2,3,4 };
//  std::vector<int>::iterator b;

  //Viktor<int> a = { 0,1,2,3,4,5 };
  //Viktor<int>::iterator b;
  //Viktor<int>::iterator b1;
  //Viktor<int>::iterator b2;
  //
  //b.m_pointer = a.data();
  //b1 = b;





   //for (size_t i = 0; i < 6; i++)
   //{
   //    std::cout << "*b[" << i << "] = " << *b++ << std::endl;
   //}
   //std::cout << b1.m_pointer << std::endl;
   //for (size_t i = 0; i < 5; i++)
   //{
   //    std::cout << "*b1[" << i << "] = " << *b1++ << std::endl;
   //    
   //}
   //std::cout << b1.m_pointer << std::endl;
   //b2 = b1;
   //std::cout << b2.m_pointer << std::endl;
   //
   //std::cout << *b2;
   // 
   //std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
   //std::cout << sizeof(std::vector<int>::iterator);


  //Viktor<int> a = { 0,1,2,3,4,5 };
  //Viktor<int>::iterator b = a.begin();
  //
  ///for (size_t i = 0; i < 6; i++)
  ///{
  ///    std::cout << *b++ << std::endl;
  ///}
  //b += 2;
  //std::cout << *(2+b) << std::endl;
   //std::cout << *(2+b) << std::endl;


   //std::cout << *b << std::endl;


    //long long a[5];
    //for (size_t i = 0; i < 5; i++)
    //{
    //    std::cout << "Memeory adress of element #" << i << ": " << &(a[i]) << std::endl;
    //
    //
    //}
    //
    //std::cout << "Memory of 4-3: " << (&(a[3])) - (&(a[4])) << std::endl;
    //
    //Viktor<int> a = { 0,1,2,3,4,5 };
    //Viktor<int>::iterator it1 = a.begin();
    //Viktor<int>::iterator it2 = it1;
    //std::cout << "it1:" << *it1 << std::endl;
    //std::cout << "it2:" << *it2 << std::endl;
    //it2++;
    //std::cout << "it2 after ++:" << *it2 << std::endl;
    //std::cout << "diff1:" << it2 - it1 << std::endl;
    //std::cout << "diff1.1:" << it1 - it2 << std::endl;
    //it2++;
    //std::cout << "diff 2:" << it2 - it1 << std::endl;
    //std::cout << "diff 2.1" << it1 - it2 << std::endl;

//Viktor<int> a = { 0,1,2,3,4,5,6 };
//Viktor<int>::iterator b = a.begin();
////std::cout << b << std::endl;
//std::cout << *b;
//*b = 77;
//std::cout << *b;
//std::vector<int> a = { 0,1,2,3,4,5,6,7,8,9 };
//std::vector<int>::const_iterator b = a.begin();
//*b = 88;


//Viktor<int> a = { 0,1,2,3 };
//Viktor<int>::const_iterator b = a.begin();
//*b = 77;

}

            
    //}

//template<typename T>
//typename T::value_type foo(T& vectorr) // когда ругается перед возврат.знач писать typename
//{
//
//
//    T::value_type x;
//    
//    return x;
//
//
//}


    




