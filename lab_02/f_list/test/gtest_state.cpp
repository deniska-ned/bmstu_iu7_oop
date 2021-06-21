#include "gtest/gtest.h"

#include "f_list/f_list"


TEST(size, 0)
{
    f_list<int> list;
    ASSERT_EQ(0, list.size());
}

TEST(size, not_0)
{
    f_list<int> list = {1, 2};
    ASSERT_EQ(2, list.size());
}

TEST(is_empty, true)
{
    f_list<int> list;
    ASSERT_TRUE(list.is_empty());
}

TEST(is_empty, false)
{
    f_list<int> list = {1, 2, 3};
    ASSERT_FALSE(list.is_empty());
}

TEST(eq, true)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_copy = {1, 2, 3};

    ASSERT_TRUE(list.eq(list_copy));
}

TEST(eq, false)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_another = {3, 2, 1};

    ASSERT_FALSE(list.eq(list_another));
}

TEST(ne, false)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_copy = {1, 2, 3};

    ASSERT_FALSE(list.ne(list_copy));
}

TEST(ne, true)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_another = {3, 2, 1};

    ASSERT_TRUE(list.ne(list_another));
}
