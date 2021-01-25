#include "pch.h"
#include <climits>
#include <stdexcept>
#include <algorithm>
#include "../Source/Source.h"

TEST(Add, AddsNumbersAndThrowsException) 
{
  EXPECT_EQ(11, add(5, 6));
  EXPECT_EQ(14, add(5, 9));
  EXPECT_EQ(0, add(0, 0));
  //EXPECT_EQ(-1, add(0, -1));
  //EXPECT_EQ(-5, add(5, -10));
  //EXPECT_EQ(-15, add(-5, -10));
  EXPECT_THROW(add(INT_MAX, 1), std::overflow_error);
}


TEST(FindLargestSum, FindsASum) 
{
	std::vector<uint32_t> I = { 2,3,5,9,13,15,18,20,35,47 };
	std::vector<uint32_t> expected = { 3, 5, 13 };
	uint32_t expSum = 21;
	std::vector<uint32_t> M;
	uint32_t S;
	find_largest_sum(21, I, M, S);
	std::sort(M.begin(), M.end());
	EXPECT_EQ(expSum, S);
	EXPECT_EQ(expected.size(), M.size());
	for (int i = 0; i < M.size(); ++i)
	{
		EXPECT_EQ(expected[i], M[i]);
	}
}

TEST(FindLargestSum, FindsASmallSum)
{
	std::vector<uint32_t> I = { 2,3,5,15,18,20,35,47 };
	std::vector<uint32_t> expected = { 15, 18 };
	uint32_t expSum = 33;
	std::vector<uint32_t> M;
	uint32_t S;
	find_largest_sum(34, I, M, S);
	std::sort(M.begin(), M.end());
	EXPECT_EQ(expSum, S);
	EXPECT_EQ(expected.size(), M.size());
	for (int i = 0; i < expected.size(); ++i)
	{
		EXPECT_EQ(expected[i], M[i]);
	}
}

TEST(FindLargestSum, FindsNoSum)
{
	std::vector<uint32_t> I = { 2,3,5,15,18,20,35,47 };
	std::vector<uint32_t> expected = { };
	uint32_t expSum = 0;
	std::vector<uint32_t> M;
	uint32_t S;
	find_largest_sum(0, I, M, S);
	std::sort(M.begin(), M.end());
	EXPECT_EQ(expSum, S);
	EXPECT_EQ(expected.size(), M.size());
	for (int i = 0; i < expected.size(); ++i)
	{
		EXPECT_EQ(expected[i], M[i]);
	}
}


TEST(FindLargestSum, FindsTooLargeSum)
{
	std::vector<uint32_t> I = { 2,3,5 };
	std::vector<uint32_t> expected = { 2, 3, 5};
	uint32_t expSum = 10;
	std::vector<uint32_t> M;
	uint32_t S;
	find_largest_sum(99, I, M, S);
	std::sort(M.begin(), M.end());
	EXPECT_EQ(expSum, S);
	EXPECT_EQ(expected.size(), M.size());
	for (int i = 0; i < expected.size(); ++i)
	{
		EXPECT_EQ(expected[i], M[i]);
	}
}