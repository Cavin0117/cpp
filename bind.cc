#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

int add(int x,int y)
{
    cout << "int add(int, int) " << endl;
    return x + y;
}
int multiply(int x, int y, int z)
{
    cout << "int multiply(int, int, int)" << endl;
    return x * y * z;
}


class Example
{
public:
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
};
void test()
{
  auto f=bind(add,1,2);
  cout<<"f() ="<<f()<<endl;
  auto f2=bind(&multiply,3,4,5);
  cout<<"f2()="<<f2()<<endl;

  Example ex;
  auto f3=bind(&Example::add,ex,10,30);
 cout<<"f3()="<<f3()<<endl;
 using namespace std::placeholders;
    auto f4 = bind(add, 10, _1);
 cout << "f4(20, 40) = " << f4(20, 40) << endl;
}





int main(int argc, char *argv[])
{
    test();
    return 0;
}

