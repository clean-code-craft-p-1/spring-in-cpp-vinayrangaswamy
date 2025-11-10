#include "stats.h"
#include <limits>
#include <cmath>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& values) noexcept {
    Stats result;
    
    // Handle empty input by returning NaN values
    if (values.empty()) {
        result.average = std::numeric_limits<float>::quiet_NaN();
        result.max = std::numeric_limits<float>::quiet_NaN();
        result.min = std::numeric_limits<float>::quiet_NaN();
        return result;
    }
    
    // Initialize with first value to handle edge cases
    float sum = 0.0f;
    result.max = values[0];
    result.min = values[0];
    
    // Single pass through the data for efficiency
    for (const float v : values) {
        sum += v;
        if (v > result.max) result.max = v;
        if (v < result.min) result.min = v;
    }
    
    result.average = sum / static_cast<float>(values.size());
    return result;
}

Statistics::Stats Statistics::ComputeStatistics(const std::vector<TemperatureFahrenheit>& fahrenheit_temperatures) noexcept {
    // Convert type-safe temperatures to raw values for processing
    std::vector<float> values;
    values.reserve(fahrenheit_temperatures.size());
    
    for (const auto& temp : fahrenheit_temperatures) {
        values.push_back(temp.value);
    }
    
    return ComputeStatistics(values);
}

Statistics::Stats Statistics::ComputeStatistics(const std::vector<TemperatureCelsius>& celsius_temperatures) noexcept {
    // Convert type-safe temperatures to Fahrenheit for consistent output
    std::vector<float> values;
    values.reserve(celsius_temperatures.size());
    
    for (const auto& temp : celsius_temperatures) {
        values.push_back(temp.toFahrenheit());
    }
    
    return ComputeStatistics(values);
}
