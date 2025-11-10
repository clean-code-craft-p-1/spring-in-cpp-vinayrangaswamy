#include <vector>

namespace Statistics {
    /**
     * @brief Temperature value in Fahrenheit with compile-time type safety
     * 
     * This type prevents accidental mixing of temperature units by requiring
     * explicit construction and providing conversion methods.
     */
    struct TemperatureFahrenheit {
        const float value;
        explicit TemperatureFahrenheit(const float fahrenheit_value) : value(fahrenheit_value) {}
        
        /**
         * @brief Convert Fahrenheit to Celsius
         * @return Temperature value in Celsius
         */
        float toCelsius() const noexcept {
            return (value - 32.0f) * 5.0f / 9.0f;
        }
    };
    
    /**
     * @brief Temperature value in Celsius with compile-time type safety
     * 
     * This type prevents accidental mixing of temperature units by requiring
     * explicit construction and providing conversion methods.
     */
    struct TemperatureCelsius {
        const float value;
        explicit TemperatureCelsius(const float celsius_value) : value(celsius_value) {}
        
        /**
         * @brief Convert Celsius to Fahrenheit
         * @return Temperature value in Fahrenheit
         */
        float toFahrenheit() const noexcept {
            return value * 9.0f / 5.0f + 32.0f;
        }
    };

    /**
     * @brief Statistical summary containing average, minimum, and maximum values
     */
    struct Stats {
        float average;  ///< Arithmetic mean of the dataset
        float max;      ///< Maximum value in the dataset
        float min;      ///< Minimum value in the dataset
    };

    /**
     * @brief Compute statistics for a vector of floating-point values
     * @param values Input dataset
     * @return Statistics (average, min, max) or NaN for empty input
     */
    Stats ComputeStatistics(const std::vector<float>& values) noexcept;
    
    /**
     * @brief Compute statistics for Fahrenheit temperature measurements
     * @param fahrenheit_temperatures Input temperature dataset in Fahrenheit
     * @return Statistics in Fahrenheit units
     */
    Stats ComputeStatistics(const std::vector<TemperatureFahrenheit>& fahrenheit_temperatures) noexcept;
    
    /**
     * @brief Compute statistics for Celsius temperature measurements
     * @param celsius_temperatures Input temperature dataset in Celsius
     * @return Statistics converted to Fahrenheit for consistency
     */
    Stats ComputeStatistics(const std::vector<TemperatureCelsius>& celsius_temperatures) noexcept;
}
