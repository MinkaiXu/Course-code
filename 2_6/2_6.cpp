//Encoding GB2312
//���Ա��˳��ʵ��

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class elemType>
class list
{
  public:
    virtual void clear();
    virtual int length() const = 0;
    virtual void insert(int i, const elemType &x) = 0;
};

template <class elemType>
class seqList : public list<elemType>
{
  private:
    eleType *data;
};