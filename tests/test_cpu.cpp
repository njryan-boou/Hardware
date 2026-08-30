#include <thread>

#include <gtest/gtest.h>

#include "hardwarey/cpu.hpp"

TEST(CpuTest, ReportsHardwareConcurrency) {
    EXPECT_EQ(hardwarey::threads(), std::thread::hardware_concurrency());
}
