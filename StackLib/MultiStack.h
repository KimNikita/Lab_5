#pragma once

#include "Stack.h"

template <class T>
class TMultiStack
{
protected:
  int length;
  T* data;
  int stackCount;
  TStack<T>* stacks;
public:
  TMultiStack(int size = 1, int stackCount = 1);
  TMultiStack(const TMultiStack<T>& ms);
  ~TMultiStack();

  TMultiStack<T>& operator=(const TMultiStack<T>& ms);

  void Push(T n, int ind);
  void Pop(int ind);
  T Get(int ind);

  bool IsEmpty(int ind);
  bool IsFull(int ind);

  int Length();
  void Resize(int size = 1, int stackCount = 1);

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TMultiStack<T1>& MS);
  template <class T1>
  friend istream& operator>>(istream& istr, TMultiStack<T1>& MS);

  // доп задачи

  int GetMinStack();
  void WriteToFile(string name);
  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, const TMultiStack<T1>& MS);
};

template<class T>
inline TMultiStack<T>::TMultiStack(int size, int stackCount)
{
  if (size < 0 || stackCount < 0)
    throw exception();

  this->length = size;
  this->stackCount = stackCount;

  data = new T[size];
  for (int i = 0; i < size; i++)
    data[i] = 0;

  int count = size / stackCount;
  int* sizes = new int[stackCount];
  for (int i = 0; i < (stackCount - 1); i++)
    sizes[i] = count;
  sizes[stackCount - 1] = size - count * (stackCount - 1);

  stacks = new TStack<T>[stackCount];
  int k = 0;
  for (int i = 0; i < stackCount; i++)
  {
    stacks[i].SetData(&data[k], sizes[i], -1);
    k += sizes[i];
  }
}

template<class T>
inline TMultiStack<T>::TMultiStack(const TMultiStack<T>& ms)
{
  this->length = ms.length;
  this->stackCount = ms.stackCount;

  this->data = new T[length];
  for (int i = 0; i < length; i++)
    this->data[i] = ms.data[i];

  this->stacks = new TStack<T>[stackCount];
  for (int i = 0; i < stackCount; i++)
    this->stacks[i] = ms.stacks[i][i];
}

template<class T>
inline TMultiStack<T>::~TMultiStack()
{
  length = 0;
  stackCount = 0;

  if (data != 0)
  {
    delete[] data;
    delete[] stacks;
  }
  data = 0;
}

template<class T>
inline TMultiStack<T>& TMultiStack<T>::operator=(const TMultiStack<T>& ms)
{
  if (this == &ms)
    return *this;

  if (this->length != ms.length || this->stackCount != ms.stackCount)
  {
    this->length = ms.length;
    this->stackCount = ms.stackCount;
    delete[] this->data;
    delete[] this->stacks;
    this->data = new T[length];
    this->stacks = new TStack<T>[stackCount];
  }

  for (int i = 0; i < length; i++)
    this->data[i] = ms.data[i];
  for (int i = 0; i < stackCount; i++)
    this->stacks[i] = ms.stacks[i];

  return *this;
}

template<class T>
inline void TMultiStack<T>::Push(T n, int ind)
{
  if (ind < 0 || ind >= stackCount)
    throw - 1;

  stacks[ind].Push(n);
}

template<class T>
inline void TMultiStack<T>::Pop(int ind)
{
  if (ind < 0 || ind >= stackCount)
    throw - 1;

  stacks[ind].Pop();
}

template<class T>
inline T TMultiStack<T>::Get(int ind)
{
  if (ind < 0 || ind >= stackCount)
    throw - 1;

  return stacks[ind].Get();
}

template<class T>
inline bool TMultiStack<T>::IsEmpty(int ind)
{
  if (ind < 0 || ind >= stackCount)
    throw - 1;

  return stacks[ind].IsEmpty();
}

template<class T>
inline bool TMultiStack<T>::IsFull(int ind)
{
  if (ind < 0 || ind >= stackCount)
    throw - 1;

  return stacks[ind].IsFull();
}

template<class T>
inline int TMultiStack<T>::Length()
{
  return length;
}

template<class T>
inline void TMultiStack<T>::Resize(int size, int stackCount)
{
  *this = TMultiStack(size, stackCount);
}

template <class T1>
ostream& operator<<(ostream& ostr, const TMultiStack<T1>& MS)
{
  for (int i = 0; i < MS.stackCount; i++)
    ostr << MS.stacks[i] << endl;
  return ostr;
}

template <class T1>
istream& operator>>(istream& istr, TMultiStack<T1>& MS)
{
  int stCount = 0;
  istr >> stCount;
  int size = 0;
  istr >> size;
  MS.Resize(size, stCount);
  for (int i = 0; i < stCount; i++)
    istr >> MS.stacks[i] << endl;
  return istr;
}

// доп задачи

template<class T>
inline int TMultiStack<T>::GetMinStack()
{
  int mins = 0;
  for (int i = 1; i < stackCount; i++)
    if (stacks[i].Count() < mins)
      mins = stacks[i].Count();
  return mins;
}

template<class T>
inline void TMultiStack<T>::WriteToFile(string name)
{
  ofstream fout(name.c_str());
  fout << *this;
  fout.close();
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, const TMultiStack<T1>& MS)
{
  for (int i = 0; i < MS.stackCount; i++)
    ofstr << MS.stacks[i];
  return ofstr;
}