#include "list.h"

#include <gtest.h>

TEST(list, can_create_list_with_positive_length) {
	ASSERT_NO_THROW(List<int> l(5));
}

TEST(list, cant_create_list_with_negative_length) {
	ASSERT_ANY_THROW(List<int> l(-5));
}

TEST(list, can_create_copied_list) {
	List<int> l1(5, 2);
	ASSERT_NO_THROW(List<int> l2(l1));
}

TEST(list, can_set_and_get_elements) {
	List<int> l(5);
	l[0] = 10;
	EXPECT_EQ(l[0], 10);
}

TEST(list, copied_list_has_its_own_memory) {
	List<int> l1(5, 2);
	List<int> l2(l1);
	l2[3] = 10;
	EXPECT_EQ(l2[0], 2);
	EXPECT_EQ(l2[3], 10);
	EXPECT_EQ(l1[3], 2);
}

TEST(list, can_assign_list_to_itself) {
	List<int> l(5);
	ASSERT_NO_THROW(l = l);
}

TEST(list, can_assign_lists_of_different_sizes_1) {
	List<int> l1(5, 2);
	List<int> l2(7, 3);

	ASSERT_NO_THROW(l1 = l2);
}

TEST(list, can_assign_lists_of_different_sizes_2) {
	List<int> l1(5, 2);
	List<int> l2(7, 3);

	ASSERT_NO_THROW(l2 = l1);
}

TEST(list, can_get_size) {
	List<int> l(5);
	EXPECT_EQ(l.size(), 5);
}

TEST(list, can_insert_front) {
	List<int> l(1);
	ASSERT_NO_THROW(l.insert_front(2));
}