//
// Created by Dmitry Morozov on 8/6/22.
//

#include <gtest/gtest.h>
#include <Demo_Math.hpp>


TEST(Demo_Math, Add) {
    EXPECT_EQ(DemoMath::add(1, 1), 2);
    EXPECT_NE(DemoMath::add(1, 1), 3);
    EXPECT_EQ(DemoMath::add(1, 1), 8);
}

