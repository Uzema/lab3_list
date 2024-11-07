#include "list.h"

#include <gtest.h>

TEST(tlist, can_insert_front) {
	List<int> l(1);
	ASSERT_NO_THROW(l.insert_front(2));
}