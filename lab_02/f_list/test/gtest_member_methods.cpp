#include "gtest/gtest.h"

#include "f_list/f_list"


TEST(constructors, default)
{
    f_list<int> list;

    ASSERT_EQ(0, list.size());
}

TEST(constructors, copy_empty)
{
    f_list<int> list;
    f_list<int> list_another(list);

    ASSERT_EQ(list, list_another);
}

TEST(constructors, copy)
{
    f_list<int> list = {1, 2};
    f_list<int> list_another(list);

    ASSERT_EQ(list, list_another);
}

TEST(constructors, by_count_zero)
{
    f_list<int> list(0);

    ASSERT_EQ(0, list.size());
}

TEST(constructors, by_count)
{
    f_list<int> list(10);

    ASSERT_EQ(10, list.size());
}

TEST(constructors, by_array_empty)
{
    int arr[] = {};

    f_list<int> list(arr, 0);

    f_list<int> exp_list;

    ASSERT_EQ(exp_list, list);
}

TEST(constructors, by_array)
{
    int arr[3] = {1, 2, 3};

    f_list<int> list(arr, 3);

    f_list<int> exp_list = {1, 2, 3};

    ASSERT_EQ(exp_list, list);
}

TEST(constructors, by_init_list_empty)
{
    size_t list_size = 5;
    f_list<int> list = {};

    ASSERT_EQ(0, list.size());
}

TEST(constructors, by_init_list)
{
    size_t list_size = 5;
    f_list<int> list = {1, 2, 3, 4, 5};

    ASSERT_EQ(5, list.size());

    auto it = list.begin();

    for (size_t i = 0; i < list_size; ++i)
    {
        ASSERT_EQ(i + 1, *it);

        ++it;
    }
}

TEST(constructors, by_iterators_vector)
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    f_list<int> list(v.begin(), v.end());

    ASSERT_EQ(5, list.size());

    auto it = list.begin();
    for (size_t i = 0; i < list.size(); ++i)
    {
        ASSERT_EQ(i + 1, *it);

        ++it;
    }
}

TEST(constructors, by_iterators_own)
{
    f_list<int> list = {1, 2, 3, 4, 5, 6, 7};

    f_list_iter<int> it_begin = list.begin();
    std::advance(it_begin, 1);

    f_list_iter<int> it_end = list.begin();
    std::advance(it_end, 4);

    f_list<int> slice(it_begin, it_end);

    f_list<int> exp_slice = {2, 3, 4};

    ASSERT_EQ(exp_slice, slice);
}

TEST(move_constructors, empty)
{
    f_list<int> list((f_list<int>()));
    f_list<int> list_another;

    ASSERT_EQ(list, list_another);
}

TEST(move_constructors, not_empty)
{
    std::vector<int> v = {1, 2, 3, 4};
    f_list<int> list( f_list<int>(v.begin(), v.end()) );
    f_list<int> list_another(v.begin(), v.end());

    ASSERT_EQ(list, list_another);
}

TEST(operator_assing, copy_empty)
{
    f_list<int> list;
    f_list<int> list_another = {1};
    list_another = list;

    f_list<int> empty_list;

    ASSERT_EQ(empty_list, list);
    ASSERT_EQ(empty_list, list_another);
}

TEST(operator_assing, copy_not_empty)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_another = {4, 5};
    list_another = list;

    f_list<int> res_list = {1, 2, 3};
    f_list<int> res_list_another = {1, 2, 3};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_another, list_another);
}

TEST(operator_assing, move_empty)
{
    f_list<int> list;
    f_list<int> list_another;

    f_list<int> bucket = std::move(list);
    list = std::move(list_another);
    list_another = std::move(bucket);

    f_list<int> empty;

    ASSERT_EQ(empty, list);
    ASSERT_EQ(empty, list_another);
}

TEST(operator_assing, move_not_empty)
{
    f_list<int> list = {1, 2, 3};
    f_list<int> list_another = {4, 5};

    f_list<int> bucket = std::move(list);
    list = std::move(list_another);
    list_another = std::move(bucket);

    f_list<int> res_list = {4, 5};
    f_list<int> res_list_another = {1, 2, 3};

    ASSERT_EQ(res_list, list);
    ASSERT_EQ(res_list_another, list_another);
}
