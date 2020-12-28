#include "MultiStack.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TMultiStack, can_create_multistack)
{
  ASSERT_NO_THROW(TMultiStack<int>(1, 1));
}

TEST(TMultiStack, can_push_any_elements)
{
  TMultiStack<int>MS(6, 3);
  MS.Push(1, 0);
  MS.Push(2, 0);
  MS.Push(3, 1);
  MS.Push(4, 2);
  EXPECT_EQ(2, MS.Get(0));
}

TEST(TMultiStack, can_pop_any_elements)
{
  TMultiStack<int>MS(6, 3);
  MS.Push(1, 0);
  MS.Push(2, 0);
  MS.Push(3, 1);
  MS.Push(4, 2);
  MS.Pop(2);
  MS.Pop(1);
  MS.Pop(0);
  EXPECT_EQ(1, MS.Get(0));
}

TEST(TMultiStack, can_repack)
{
  TMultiStack<int>MS(9, 3);
  MS.Push(1, 0);
  MS.Push(2, 0);
  MS.Push(3, 1);
  MS.Push(4, 1);
  MS.Push(5, 2);
  MS.Push(6, 0);
  MS.Push(7, 0);
  MS.Push(8, 0);
  MS.Push(9, 0);
  string expMS = "126789345";
  EXPECT_EQ(expMS, MS.GetMultiStack());
}

//доп задачи

TEST(TMultiStack, can_find_min_stack)
{
  TMultiStack<int>MS(9, 3);
  MS.Push(1, 0);
  MS.Push(2, 0);
  MS.Push(3, 0);
  MS.Push(4, 1);
  MS.Push(5, 1);
  MS.Push(6, 2);
  MS.Push(7, 2);
  MS.Push(8, 2);

  EXPECT_EQ(1, MS.GetMinStack());
}

TEST(TMultiStack, can_write_multistack_to_file)
{
  TMultiStack<int>MS(9, 3);
  MS.Push(1, 0);
  MS.Push(2, 0);
  MS.Push(3, 0);
  MS.Push(4, 1);
  MS.Push(5, 1);
  MS.Push(6, 1);
  MS.Push(7, 2);
  MS.Push(8, 2);
  MS.Push(9, 2);
  MS.WriteToFile("output_s.txt");
  string expS = "123456789";
  string MultiStack = "";
  ifstream fin("output_s.txt");
  fin >> MultiStack;
  fin.close();
  EXPECT_EQ(expS, MultiStack);
}