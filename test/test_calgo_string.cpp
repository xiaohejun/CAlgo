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


