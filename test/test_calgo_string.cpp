#include <gtest/gtest.h>
#include "calgo_clazz.h"
#include "calgo_string.h"

TEST(calgo_string, give_new_string)
{
    void *a = New(CALGO_String, "a");
    CALGO_String_s *stringA = (CALGO_String_s *)a;
    
    EXPECT_STREQ("a", stringA->text);

    Delete(a);
}

TEST(calgo_string, clone_a_string)
{
    void *a = New(CALGO_String, "a");
    void *aa = Clone(a);
    void *b = New(CALGO_String, "b");
    
    EXPECT_EQ(Differ(a, b), -1);
    EXPECT_EQ(Differ(a, aa), 0);
    EXPECT_FALSE(a == aa);

    Delete(a);
    Delete(aa);
    Delete(b);
}
