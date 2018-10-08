//Encoding GB2312
//线性表的顺序实现

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &a,
                            const seqList<elemType> &b) //加法运算符重载函数
{
  seqList<elemType> c(a.length() + b.length());
  int i;
  for (i = 0; i < a.currentLength; ++i)
    c.data[i] = a.data[i];
  for (int j = 0; j < b; ++j)
    c.data[i++] = b.data[j];
  c.currentLength = i;
  return c;
}

template <class elemType>
seqList<elemType>::seqList(const seqList<elemType> &other) //复制构造函数
{
  currentLength = other.currentLength;
  maxSize = other.maxSize;
  data = new elemType[maxSize];
  for (int i = 0; i < currentLength; ++i)
    data[i] = other.data[i];
}

template <class elemType>
seqList<elemType> &seqList<elemType>::operator=(const seqList<elemType> &other) //赋值运算符重载函数
{
  if (this *= = &other)
    return *this;
  delete[] data;

  currentLength = other.currentLength;
  maxSize = other.maxSize;
  data = new elemType[maxSize];
  for (int i = 0; i < currentLength; ++i)
    data[i] = other.data[i];

  return *this;
}




template <class elemType> //顺序表类实现
class seqList : public list<elemType>
{
  friend seqList<elemType> operator+(const seqList<elemType> &a,
                                     const seqList<elemType> &b); //加法运算符重载函数
  seqList(const seqList<elemType> &other);                        //重载的复制构造函数
  seqList<elemType> &operator=(const seqList<elemType> &other);   //赋值运算符重载函数

private:
  eleType *data;      //动态数组起始位置
  int currentLength;  //表长
  int maxSize;        //顺序表的容量
  void doubleSpace(); //顺序表的容量扩大一倍
public:
  seqList(int initsize = 10);
  ~seqlist() { delete[] data; }
  void clear() { currentLength = 0; }    //清楚一个线性表中的所有数据元素
  int length() { return currentLength; } //求线性表的长度
  void insert(int i, const elemType &x); //在第i个位置插入一个元素
  void remove(int i);                    //删除第i个位置的元素
  int search(const elemType &x) const;   //搜索某个元素在线性表中是否出现并返回其位置
  elemType visit(int i) { return data[i]; }
  void traverse() const;
};




template <class elemType> //线性表的抽象类
class list
{
public:
  virtual void clear() = 0;                          //清楚一个线性表中的所有数据元素
  virtual int length() const = 0;                    //求线性表的长度
  virtual void insert(int i, const elemType &x) = 0; //在第i个位置插入一个元素
  virtual void remove(int i) = 0;                    //删除第i个位置的元素
  virtual int search(const elemType &x) const = 0;   //搜索某个元素在线性表中是否出现并返回其位置
  virtual elemType visit(int i) const = 0;
  virtual void traverse() const = 0;
  virtual ~list(){};
};
