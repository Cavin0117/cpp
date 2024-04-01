#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::allocator;
template<typename T> 
class Vector 
{ 
public:
    using iterator =T*;
    iterator begin()
    {
      return _start;
    }
    iterator end()
    {
      return _finish;
    }
    Vector()
    :_start(nullptr)
    ,_finish(nullptr)
   , _end_of_storage(nullptr)
   {}
    ~Vector();

    void push_back(const T &);

    void pop_back();

    int size()const;

    int capacity()const; 
private:

    void reallocate();//重新分配内存,动态扩容要用的 
private:

    static std::allocator<T> _alloc;

    T *_start;                 //指向数组中的第一个元素

    T *_finish;                //指向最后一个实际元素之后的那个元素

    T *_end_of_storage;        //指向数组本身之后的位置 
};
template <typename T>
std:: allocator<T>Vector<T>::_alloc;
template <typename T>
Vector<T>::~Vector()
{
  if(_start);
  {
    while(_start!=_finish)
    {
      _alloc.destroy(--_finish);

    }
  
  _alloc.deallocate(_start,capacity());
  }
}
template <typename T>
void Vector<T>::push_back(const T &value)
{
  if(size()==capacity())
  {
    reallocate();

  }
  if(size()<capacity())
  {
    _alloc.construct(_finish++,value);
  }
}

template <typename T>
void Vector<T>::pop_back()
{
  if(size()>0)
  {
    _alloc.destroy(--_finish);
  }
}

template <typename T>
int Vector<T>::size() const
{
  return _finish - _start;
}
template <typename T>
int Vector<T>::capacity() const
{
    return _end_of_storage - _start;
}
template<typename T>
void Vector<T>::reallocate()
{
//申请新空间
int oldCapacity =capacity();
int newCapacity =oldCapacity> 0 ? 2*oldCapacity:1;
//暂存
T *ptmp=_alloc.allocate(newCapacity);
if(_start)
{

  std::uninitialized_copy(_start,_finish,ptmp);
while(_start!=_finish)
{
  _alloc.destroy(--_finish);
}
_alloc.deallocate(_start,oldCapacity);
}
_start = ptmp;
_finish = ptmp + oldCapacity;
_end_of_storage = ptmp + newCapacity;
}
void printCapacity(const Vector<int> &con)
{
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}

void test()
{
Vector<int>vec;
    printCapacity(vec);

    cout << endl;
    vec.push_back(1);
    printCapacity(vec);

    cout << endl;
    vec.push_back(2);
    printCapacity(vec);

    cout << endl;
    vec.push_back(3);
    printCapacity(vec);

    cout << endl;
    vec.push_back(4);
    printCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printCapacity(vec);

   for(auto &elem :vec)
   {
    cout<<elem<< " ";
   }
      cout << endl;
}

int main()
{
    test();
    return 0;
}
