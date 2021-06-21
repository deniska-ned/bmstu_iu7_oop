#include "gtest/gtest.h"

#include "f_list/f_list"


TEST(iterator_increment_prefix, default_const)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    f_list_iter_const<int> res_it = list.cbegin();
    std::advance(res_it, 1);

    ASSERT_EQ(res_it, ++it);
    ASSERT_EQ(res_it, it);
}

TEST(iterator_increment_prefix, default)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    f_list_iter<int> res_it = list.begin();
    std::advance(res_it, 1);

    ASSERT_EQ(res_it, ++it);
    ASSERT_EQ(res_it, it);
}

TEST(iterator_increment_prefix, end)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.end();

    try
    {
        ++it;
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_inc_impossible & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_prefix, inc_expired)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    list.clear();

    try
    {
        ++it;
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_inc_impossible & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_prefix, get_data)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    int value = *it;

    ASSERT_EQ(0, value);
}

TEST(iterator_increment_prefix, get_ptr_to_data)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    int * value_ptr = it.operator->();

    ASSERT_EQ(0, *value_ptr);
}

TEST(iterator_increment_prefix, get_data_from_expired)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    list.clear();

    try
    {
        int value = *it;
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_expired & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_prefix, get_ptr_to_data_from_expired)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    list.clear();

    try
    {
        int * value_ptr = it.operator->();
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_expired & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_postfix, const_default)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    f_list_iter_const<int> res_it_before = list.cbegin();
    f_list_iter_const<int> res_it_after = list.cbegin();
    std::advance(res_it_after, 1);

    ASSERT_EQ(res_it_before, it++);
    ASSERT_EQ(res_it_after, it);
}

TEST(iterator_increment_postfix, default)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter<int> it = list.begin();

    f_list_iter<int> res_it_before = list.begin();
    f_list_iter<int> res_it_after = list.begin();
    std::advance(res_it_after, 1);

    ASSERT_EQ(res_it_before, it++);
    ASSERT_EQ(res_it_after, it);
}

TEST(iterator_increment_postfix, end)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cend();

    try
    {
        ++it;
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_inc_impossible & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_postfix, inc_expired)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    list.clear();

    try
    {
        ++it;
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_inc_impossible & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_postfix, get_data)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    int value = *it;

    ASSERT_EQ(0, value);
}

TEST(iterator_increment_postfix, get_ptr_to_data)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    const int * value_ptr = it.operator->();

    ASSERT_EQ(0, *value_ptr);
}

TEST(iterator_increment_postfix, get_data_from_expired)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    list.clear();

    try
    {
        const int value = *it;
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_expired & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_increment_postfix, get_ptr_to_data_from_expired)
{
    f_list<int> list = {0, 1, 2, 3};

    f_list_iter_const<int> it = list.cbegin();

    list.clear();

    try
    {
        const int * value_ptr = it.operator->();
        ASSERT_TRUE(false);
    }
    catch (const f_list_error_iter_expired & e)
    {}
    catch (...)
    {
        ASSERT_TRUE(false);
    }
}

TEST(iterator_bool, true)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter<int> it = list.begin();
    
    ASSERT_TRUE(it);
}

TEST(iterator_bool, false)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter<int> it = list.begin();

    list.clear();
    
    ASSERT_FALSE(it);
}

TEST(iterator_bool, const_true)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter_const<int> it = list.cbegin();
    
    ASSERT_TRUE(it);
}

TEST(iterator_bool, const_false)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter_const<int> it = list.cbegin();

    list.clear();
    
    ASSERT_FALSE(it);
}

TEST(iterator_eq, true)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter<int> it_l = list.begin();
    f_list_iter<int> it_r = list.begin();

    ASSERT_TRUE(it_l == it_r);
}

TEST(iterator_eq, true_const_it)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter_const<int> it_l = list.cbegin();
    f_list_iter_const<int> it_r = list.cbegin();

    ASSERT_TRUE(it_l == it_r);
}

TEST(iterator_eq, false)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter<int> it_l = list.begin();
    std::advance(it_l, 1);
    f_list_iter<int> it_r = list.begin();

    ASSERT_FALSE(it_l == it_r);
}

TEST(iterator_eq, false_const_it)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter_const<int> it_l = list.cbegin();
    std::advance(it_l, 1);
    f_list_iter_const<int> it_r = list.cbegin();

    ASSERT_FALSE(it_l == it_r);
}

TEST(iterator_ne, false)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter<int> it_l = list.begin();
    f_list_iter<int> it_r = list.begin();

    ASSERT_FALSE(it_l != it_r);
}

TEST(iterator_ne, false_const_it)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter_const<int> it_l = list.cbegin();
    f_list_iter_const<int> it_r = list.cbegin();

    ASSERT_FALSE(it_l != it_r);
}

TEST(iterator_ne, true)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter<int> it_l = list.begin();
    std::advance(it_l, 1);
    f_list_iter<int> it_r = list.begin();

    ASSERT_TRUE(it_l != it_r);
}

TEST(iterator_ne, true_const_it)
{
    f_list<int> list = {0, 1, 2, 3};
    f_list_iter_const<int> it_l = list.cbegin();
    std::advance(it_l, 1);
    f_list_iter_const<int> it_r = list.cbegin();

    ASSERT_TRUE(it_l != it_r);
}

TEST(iterator_loop, for)
{
    f_list<int> list = {0, 1, 2, 3, 4, 5};

    int number = 0;
    for (int & value: list)
        ASSERT_EQ(number++, value);
}

TEST(iterator_loop, const_for)
{
    f_list<int> list = {0, 1, 2, 3, 4, 5};

    int number = 0;
    for (const int & value: list)
        ASSERT_EQ(number++, value);
}

TEST(iterator_loop, for_const_list)
{
    const f_list<int> list = {0, 1, 2, 3, 4, 5};

    int number = 0;
    for (const int & value: list)
        ASSERT_EQ(number++, value);
}

TEST(iterator_loop, for_mutable)
{
    f_list<int> list = {0, 1, 2, 3, 4, 5};

    for (int & value: list)
        value *= 2;

    int number = 0;
    for (const int & value: list)
    {
        ASSERT_EQ(number, value);
        number += 2;
    }
}
