#include <gtest/gtest.h>
#include <stdio.h>
#include "new.h"
#include "object.h"
#include "set.h"

const void * g_set;
const void * g_object;

TEST(test_set, testcase01)
{
    void *s = New(g_set);
    void *a = Add(s, New(g_object));
    void *b = Add(s, New(g_object));
    void *c = New(g_object);

    EXPECT_EQ(Contains(s, a), 1);
    EXPECT_EQ(Contains(s, b), 1);
    EXPECT_EQ(Contains(s, c), 0);
    // TODO..

}