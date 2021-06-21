#include <vector>

#include "gtest/gtest.h"

#include "f_list/f_list"


TEST(push_front, to_empty)
{
    f_list<int> list;
    list.push_front(0);

    f_list<int> res_list = {0};

    ASSERT_EQ(res_list, list);
}

TEST(push_front, to_not_empty)
{
    f_list<int> list = {1, 2, 3, 4, 5};
    list.push_front(0);
    f_list<int> res_list = {0, 1, 2, 3, 4, 5};

    ASSERT_EQ(list, res_list);
}

TEST(push_front_list, empty_l)
{
    f_list<int> list_l;
    f_list<int> list_r = {1, 2};
    list_l.push_front(list_r);

    f_list<int> res_list_l = {1, 2};
    f_list<int> res_list_r = {1, 2};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_front_list, empty_r)
{
    f_list<int> list_l = {1, 2};
    f_list<int> list_r;
    list_l.push_front(list_r);

    f_list<int> res_list_l = {1, 2};
    f_list<int> res_list_r;

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_front_list, empty_both)
{
    f_list<int> list_l;
    f_list<int> list_r;
    list_l.push_front(list_r);

    f_list<int> res_list_l;
    f_list<int> res_list_r;

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_front_list, not_empty)
{
    f_list<int> list_l = {1, 2, 3};
    f_list<int> list_r = {4, 5};
    list_r.push_front(list_l);

    f_list<int> res_list_r = {1, 2, 3, 4, 5};
    f_list<int> res_list_l = {1, 2, 3};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_back, to_empty)
{
    f_list<int> list;
    list.push_back(0);

    f_list<int> res_list = {0};

    ASSERT_EQ(res_list, list);
}

TEST(push_back, to_not_empty)
{
    f_list<int> list = {1, 2, 3, 4, 5};
    list.push_back(6);

    f_list<int> res_list = {1, 2, 3, 4, 5, 6};

    ASSERT_EQ(res_list, list);
}

TEST(push_back_list, empty_l)
{
    f_list<int> list_l;
    f_list<int> list_r = {1, 2};
    list_l.push_back(list_r);

    f_list<int> res_list_l = {1, 2};
    f_list<int> res_list_r = {1, 2};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_back_list, empty_r)
{
    f_list<int> list_l = {1, 2};
    f_list<int> list_r;
    list_l.push_back(list_r);

    f_list<int> res_list_l = {1, 2};
    f_list<int> res_list_r;

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_back_list, empty_both)
{
    f_list<int> list_l;
    f_list<int> list_r;
    list_l.push_back(list_r);

    f_list<int> res_list_l;
    f_list<int> res_list_r;

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(push_back_list, not_empty)
{
    f_list<int> list_l = {1, 2, 3};
    f_list<int> list_r = {4, 5};
    list_l.push_back(list_r);

    f_list<int> res_list_l = {1, 2, 3, 4, 5};
    f_list<int> res_list_r = {4, 5};

    ASSERT_EQ(res_list_l, list_l);
    ASSERT_EQ(res_list_r, list_r);
}

TEST(insert_value, between)
{
    f_list<int> list = {1, 3};
    auto it = list.begin();

    list.insert_after(it, 2);

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(insert_value, to_end)
{
    f_list<int> list = {1, 2};
    auto it = list.begin();
    std::advance(it, 1);

    list.insert_after(it, 3);

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(insert_iter, empty)
{
    std::vector<int> v;

    f_list<int> list = {1, 2, 3};

    list.insert_after(list.begin(), v.begin(), v.end());

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(insert_iter, one_elem)
{
    std::vector<int> v = {2};

    f_list<int> list = {1, 3};

    list.insert_after(list.begin(), v.begin(), v.end());

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(insert_iter, two_elems)
{
    std::vector<int> v = {2, 3};

    f_list<int> list = {1, 4};

    list.insert_after(list.begin(), v.begin(), v.end());

    f_list<int> res_list = {1, 2, 3, 4};

    ASSERT_EQ(res_list, list);
}

TEST(insert_ilist, empty)
{
    f_list<int> list = {1, 2, 3};

    list.insert_after(list.begin(), {});

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(insert_ilist, one_elem)
{
    f_list<int> list = {1, 3};

    list.insert_after(list.begin(), {2});

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(insert_ilist, two_elems)
{
    f_list<int> list = {1, 4};

    list.insert_after(list.begin(), {2, 3});

    f_list<int> res_list = {1, 2, 3, 4};

    ASSERT_EQ(res_list, list);
}

TEST(erase_after_it, one_elem_const)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it = list.cbegin();
    ++it;
    list.erase_after(it);

    f_list<int> res_list = {1, 2, 4, 5};
    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it, one_elem)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter<int> it = list.begin();
    ++it;
    list.erase_after(it);

    f_list<int> res_list = {1, 2, 4, 5};
    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it_it, one_elem_by_2_args_const)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it_first = list.cbegin();
    advance(it_first, 1);

    f_list_iter_const<int> it_last = it_first;
    advance(it_last, 2);

    list.erase_after(it_first, it_last);

    f_list<int> res_list = {1, 2, 4, 5};
    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it_it, one_elem_by_2_args)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it_first = list.begin();
    advance(it_first, 1);

    f_list_iter_const<int> it_last = it_first;
    advance(it_last, 2);

    list.erase_after(it_first, it_last);

    f_list<int> res_list = {1, 2, 4, 5};
    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it_it, two_elem_const)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it_first = list.cbegin();
    advance(it_first, 1);

    f_list_iter_const<int> it_last = it_first;
    advance(it_last, 2);

    list.erase_after(it_first, it_last);

    f_list<int> res_list = {1, 2, 4, 5};

    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it_it, two_elem)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it_first = list.begin();
    advance(it_first, 1);

    f_list_iter_const<int> it_last = it_first;
    advance(it_last, 2);

    list.erase_after(it_first, it_last);

    f_list<int> res_list = {1, 2, 4, 5};

    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it_it, two_last_const)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it_first = list.cbegin();
    advance(it_first, 2);

    list.erase_after(it_first, list.cend());

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(list, res_list);
}

TEST(erase_after_it_it, two_last)
{
    f_list<int> list = {1, 2, 3, 4, 5};

    f_list_iter_const<int> it_first = list.begin();
    advance(it_first, 2);

    list.erase_after(it_first, list.end());

    f_list<int> res_list = {1, 2, 3};

    ASSERT_EQ(list, res_list);
}

TEST(pop, not_empty)
{
    f_list<int> list = {1, 2, 3};

    list.pop_front();

    f_list<int> res_list = {2, 3};

    ASSERT_EQ(res_list, list);
}

TEST(pop, empty)
{
    f_list<int> list;

    list.pop_front();
    // TODO: add exception catch

    f_list<int> res_list;

    ASSERT_EQ(res_list, list);
}

TEST(clear, empty)
{
    f_list<int> list;
    list.clear();

    f_list<int> empty_list;

    ASSERT_EQ(empty_list, list);
}

TEST(clear, not_empty)
{
    f_list<int> list = {1, 2, 3};
    list.clear();

    f_list<int> empty_list;

    ASSERT_EQ(empty_list, list);
}
