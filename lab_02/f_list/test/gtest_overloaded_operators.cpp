#include "gtest/gtest.h"

#include "f_list/f_list"


TEST(overloaded_eq, true)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_copy = {1, 2, 3};

    ASSERT_TRUE(list == list_copy);
}

TEST(overloaded_eq, false)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_another = {3, 2, 1};

    ASSERT_FALSE(list == list_another);
}

TEST(overloaded_ne, false)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_copy = {1, 2, 3};

    ASSERT_FALSE(list != list_copy);
}

TEST(overloaded_ne, true)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_another = {3, 2, 1};

    ASSERT_TRUE(list != list_another);
}

TEST(overloaded_sum_list_el, empty)
{
    f_list<int> list;
    f_list<int> list_sum = list + 0;

    f_list<int> res_list;
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_list_el, not_empty)
{
    f_list<int> list = {0};
    f_list<int> list_sum = list + 1;

    f_list<int> res_list = {0};
    f_list<int> res_list_sum = {0, 1};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_el_list, empty)
{
    f_list<int> list;
    f_list<int> list_sum = 0 + list;

    f_list<int> res_list;
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_el_list, not_empty)
{
    f_list<int> list = {1};
    f_list<int> list_sum = 0 + list;

    f_list<int> res_list = {1};
    f_list<int> res_list_sum = {0, 1};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_list_list, empty_first)
{
    f_list<int> list_l;
    f_list<int> list_r = {0};
    f_list<int> list_sum = list_l + list_r;

    f_list<int> res_list_l;
    f_list<int> res_list_r = {0};
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_list_list, empty_second)
{
    f_list<int> list_l = {0};
    f_list<int> list_r;
    f_list<int> list_sum = list_l + list_r;

    f_list<int> res_list_l = {0};
    f_list<int> res_list_r;
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_list_list, not_empty_both)
{
    f_list<int> list_l = {0};
    f_list<int> list_r = {1};
    f_list<int> list_sum = list_l + list_r;

    f_list<int> res_list_l = {0};
    f_list<int> res_list_r = {1};
    f_list<int> res_list_sum = {0, 1};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_sum_list_el_el_list_el, not_empty_both)
{
    f_list<int> list_1 = {0, 1};
    int value_1 = 2;
    int value_2 = 3;
    f_list<int> list_2 = {4};
    int value_3 = 5;
    f_list<int> list_sum = list_1 + value_1 + value_2 + list_2 + value_3;

    f_list<int> res_list_1 = {0, 1};
    f_list<int> res_list_2 = {4};
    f_list<int> res_list_sum = {0, 1, 2, 3, 4, 5};

    ASSERT_EQ(res_list_1, list_1);
    ASSERT_EQ(res_list_2, list_2);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(overloaded_push_back, to_empty)
{
    f_list<int> list;
    int value = 1;
    list += value;

    f_list<int> res_list = {1};

    ASSERT_EQ(res_list, list);
}

TEST(overloaded_push_back, to_not_empty)
{
    f_list<int> list = {1, 2};
    int value = 3;
    list += value;

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(overloaded_push_back_list, empty_l)
{
    f_list<int> list_l;
    f_list<int> list_r = {1, 2};
    list_l += list_r;

    f_list<int> res_list_l = {1, 2};
    f_list<int> res_list_r = {1, 2};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(overloaded_push_back_list, empty_r)
{
    f_list<int> list_l = {1, 2};
    f_list<int> list_r;
    list_l += list_r;

    f_list<int> res_list_l = {1, 2};
    f_list<int> res_list_r;

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(overloaded_push_back_list, empty_both)
{
    f_list<int> list_l;
    f_list<int> list_r;
    list_l += list_r;

    f_list<int> res_list_l;
    f_list<int> res_list_r;

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(overloaded_push_back_list, not_empty)
{
    f_list<int> list_l = {1, 2, 3};
    f_list<int> list_r = {4, 5};
    list_l += list_r;

    f_list<int> res_list_l = {1, 2, 3, 4, 5};
    f_list<int> res_list_r = {4, 5};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}
