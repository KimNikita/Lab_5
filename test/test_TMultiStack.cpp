#include "MultiStack.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TMultiStack, can_create_multistack_positive_size)
{
  ASSERT_NO_THROW();
}



//доп задачи

TEST(TMultiStack, can_find_min_stack)
{
  const int size = 9;
  TMultiStack<int> MS(size);
  
  EXPECT_EQ(0, MS.GetMinStack());
}

TEST(TMultiStack, can_write_multistack_to_file)
{
  const int size = 9;
  TMultiStack<int> MS(size);
  
  MS.WriteToFile("output_s.txt");
  string expS = "";
  string MultiStack = "";
  ifstream fin("output_s.txt");
  fin >> MultiStack;
  fin.close();
  EXPECT_EQ(expS, MultiStack);
}