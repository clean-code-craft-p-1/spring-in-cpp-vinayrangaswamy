#include "stats.h"

#include "gtest/gtest.h"
#include <cmath>

TEST(Statistics, ReportsAverageMinMax) {
    auto computedStats = Statistics::ComputeStatistics({98.6, 98.2, 97.8, 102.2});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 99.2), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 102.2), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 97.8), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    auto computedStats = Statistics::ComputeStatistics({});
    // All fields of computedStats (average, max, min) must be
    // NAN (not-a-number), as defined in math.h
    
    // Specify the EXPECT statement here.
    // Use http://www.cplusplus.com/reference/cmath/isnan/
}
