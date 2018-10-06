//Encoding GB2312
//���Ա��˳��ʵ��

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &a,
                            const seqList<elemType> &b) //�ӷ���������غ���
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
seqList<elemType>::seqList(const seqList<elemType> &other) //���صĸ��ƹ��캯��
{
  currentLength = other.currentLength;
  maxSize = other.maxSize;
  data = new elemType[maxSize];
  for (int i = 0; i < currentLength; ++i)
    data[i] = other.data[i];
}

template <class elemType>
seqList<elemType> &seqList<elemType>::operator=(const seqList<elemType> &other) //��ֵ��������غ���
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




template <class elemType> //˳�����ʵ��
class seqList : public list<elemType>
{
  friend seqList<elemType> operator+(const seqList<elemType> &a,
                                     const seqList<elemType> &b); //�ӷ���������غ���
  seqList(const seqList<elemType> &other);                        //���صĸ��ƹ��캯��
  seqList<elemType> &operator=(const seqList<elemType> &other);   //��ֵ��������غ���

private:
  eleType *data;      //��̬������ʼλ��
  int currentLength;  //��
  int maxSize;        //˳��������
  void doubleSpace(); //˳������������һ��
public:
  seqList(int initsize = 10);
  ~seqlist() { delete[] data; }
  void clear() { currentLength = 0; }    //���һ�����Ա��е���������Ԫ��
  int length() { return currentLength; } //�����Ա�ĳ���
  void insert(int i, const elemType &x); //�ڵ�i��λ�ò���һ��Ԫ��
  void remove(int i);                    //ɾ����i��λ�õ�Ԫ��
  int search(const elemType &x) const;   //����ĳ��Ԫ�������Ա����Ƿ���ֲ�������λ��
  elemType visit(int i) { return data[i]; }
  void traverse() const;
};


template <class elemType> //���Ա�ĳ�����
class list
{
public:
  virtual void clear() = 0;                          //���һ�����Ա��е���������Ԫ��
  virtual int length() const = 0;                    //�����Ա�ĳ���
  virtual void insert(int i, const elemType &x) = 0; //�ڵ�i��λ�ò���һ��Ԫ��
  virtual void remove(int i) = 0;                    //ɾ����i��λ�õ�Ԫ��
  virtual int search(const elemType &x) const = 0;   //����ĳ��Ԫ�������Ա����Ƿ���ֲ�������λ��
  virtual elemType visit(int i) const = 0;
  virtual void traverse() const = 0;
  virtual ~list(){};
};
