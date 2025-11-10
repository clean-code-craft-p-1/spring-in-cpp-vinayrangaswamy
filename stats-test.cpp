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
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));
}

TEST(Statistics, SingleValueInput) {
    auto computedStats = Statistics::ComputeStatistics({98.6});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 98.6), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 98.6), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 98.6), epsilon);
}

TEST(Statistics, NegativeTemperatures) {
    auto computedStats = Statistics::ComputeStatistics({-10.0, -5.0, 0.0, 5.0});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - (-2.5)), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 5.0), epsilon);
    EXPECT_LT(std::abs(computedStats.min - (-10.0)), epsilon);
}

TEST(Statistics, FahrenheitTemperatures) {
    std::vector<Statistics::TemperatureFahrenheit> fahrenheit_temps = {
        Statistics::TemperatureFahrenheit(98.6),
        Statistics::TemperatureFahrenheit(98.2),
        Statistics::TemperatureFahrenheit(97.8),
        Statistics::TemperatureFahrenheit(102.2)
    };
    
    auto computedStats = Statistics::ComputeStatistics(fahrenheit_temps);
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 99.2), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 102.2), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 97.8), epsilon);
}

TEST(Statistics, CelsiusTemperatures) {
    std::vector<Statistics::TemperatureCelsius> celsius_temps = {
        Statistics::TemperatureCelsius(37.0),  // Normal body temperature
        Statistics::TemperatureCelsius(36.8),
        Statistics::TemperatureCelsius(36.5),
        Statistics::TemperatureCelsius(39.0)   // Fever
    };
    
    auto computedStats = Statistics::ComputeStatistics(celsius_temps);
    float epsilon = 0.01;
    // Expected values in Fahrenheit after conversion
    EXPECT_LT(std::abs(computedStats.average - 98.825), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 102.2), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 97.7), epsilon);
}

TEST(Statistics, TemperatureConversion) {
    Statistics::TemperatureFahrenheit temp_f(98.6);
    Statistics::TemperatureCelsius temp_c(37.0);
    
    float epsilon = 0.01;
    EXPECT_LT(std::abs(temp_f.toCelsius() - 37.0), epsilon);
    EXPECT_LT(std::abs(temp_c.toFahrenheit() - 98.6), epsilon);
}

TEST(Statistics, EmptyFahrenheitInput) {
    std::vector<Statistics::TemperatureFahrenheit> empty_temps;
    auto computedStats = Statistics::ComputeStatistics(empty_temps);
    
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));
}

TEST(Statistics, EmptyCelsiusInput) {
    std::vector<Statistics::TemperatureCelsius> empty_temps;
    auto computedStats = Statistics::ComputeStatistics(empty_temps);
    
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));
}
