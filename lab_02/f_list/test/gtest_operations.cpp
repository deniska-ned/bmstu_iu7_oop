#include "gtest/gtest.h"

#include "f_list/f_list"


TEST(splice, empty_first)
{
    f_list<int> first;
    f_list<int> last = {1, 2, 3};

    first.splice(last);

    f_list<int> res = {1, 2, 3};
    f_list<int> empty;

    ASSERT_EQ(res, first);
    ASSERT_EQ(empty, last);
}

TEST(splice, empty_last)
{
    f_list<int> first = {1, 2, 3};
    f_list<int> last;

    first.splice(last);

    f_list<int> res = {1, 2, 3};
    f_list<int> empty;

    ASSERT_EQ(res, first);
    ASSERT_EQ(empty, last);
}

TEST(splice, empty_both)
{
    f_list<int> first;
    f_list<int> last;

    first.splice(last);

    f_list<int> empty;

    ASSERT_EQ(empty, first);
    ASSERT_EQ(empty, last);
}

TEST(splice, not_empty_both)
{
    f_list<int> first = {1, 2};
    f_list<int> last = {3, 4, 5};

    first.splice(last);

    f_list<int> res = {1, 2, 3, 4, 5};
    f_list<int> empty;

    ASSERT_EQ(res, first);
    ASSERT_EQ(empty, last);
}

TEST(swap, first_empty)
{
    f_list<int> first;
    f_list<int> second = {4, 5};

    first.swap(second);

    f_list<int> res_first = {4, 5};
    f_list<int> res_second;

    ASSERT_EQ(res_first, first);
    ASSERT_EQ(res_second, second);
}

TEST(swap, second_empty)
{
    f_list<int> first = {1, 2, 3};
    f_list<int> second;

    first.swap(second);

    f_list<int> res_first;
    f_list<int> res_second = {1, 2, 3};

    ASSERT_EQ(res_first, first);
    ASSERT_EQ(res_second, second);
}

TEST(swap, not_empty_both)
{
    f_list<int> first = {1, 2, 3};
    f_list<int> second = {4, 5};

    first.swap(second);

    f_list<int> res_first = {4, 5};
    f_list<int> res_second = {1, 2, 3};

    ASSERT_EQ(res_first, first);
    ASSERT_EQ(res_second, second);
}

TEST(sum_list_el, empty)
{
    f_list<int> list;
    f_list<int> list_sum = list.unite(0);

    f_list<int> res_list;
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_list_el, not_empty)
{
    f_list<int> list = {0};
    f_list<int> list_sum = list.unite(1);

    f_list<int> res_list = {0};
    f_list<int> res_list_sum = {0, 1};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_el_list, empty)
{
    f_list<int> list;
    f_list<int> list_sum = unite(0, list);

    f_list<int> res_list;
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_el_list, not_empty)
{
    f_list<int> list = {1};
    f_list<int> list_sum = unite(0, list);

    f_list<int> res_list = {1};
    f_list<int> res_list_sum = {0, 1};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_list_list, empty_first)
{
    f_list<int> list_l;
    f_list<int> list_r = {0};
    f_list<int> list_sum = list_l.unite(list_r);

    f_list<int> res_list_l;
    f_list<int> res_list_r = {0};
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_list_list, empty_second)
{
    f_list<int> list_l = {0};
    f_list<int> list_r;
    f_list<int> list_sum = list_l.unite(list_r);

    f_list<int> res_list_l = {0};
    f_list<int> res_list_r;
    f_list<int> res_list_sum = {0};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_list_list, not_empty_both)
{
    f_list<int> list_l = {0};
    f_list<int> list_r = {1};
    f_list<int> list_sum = list_l.unite(list_r);

    f_list<int> res_list_l = {0};
    f_list<int> res_list_r = {1};
    f_list<int> res_list_sum = {0, 1};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
    ASSERT_EQ(res_list_sum, list_sum);
}

TEST(sum_list_el_el_list_el, not_empty_both)
{
    f_list<int> list_1 = {0, 1};
    int value_1 = 2;
    int value_2 = 3;
    f_list<int> list_2 = {4};
    int value_3 = 5;
    f_list<int> list_sum =
            list_1.unite(value_1).unite(value_2).unite(list_2).unite(value_3);

    f_list<int> res_list_1 = {0, 1};
    f_list<int> res_list_2 = {4};
    f_list<int> res_list_sum = {0, 1, 2, 3, 4, 5};

    ASSERT_EQ(res_list_1, list_1);
    ASSERT_EQ(res_list_2, list_2);
    ASSERT_EQ(res_list_sum, list_sum);
}
