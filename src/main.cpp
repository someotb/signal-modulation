#include "common.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <ostream>

constexpr float FREQ = 1.0f;
constexpr float AMPL = 1.0f;
constexpr float PHAS = 0.0f;

int main()
{
    std::ofstream output("output.csv");
    if (!output.is_open())
        throw std::invalid_argument("Failed to open file");

    output << "1hz,5hz,10hz,20hz,49hz\n";

    std::vector<float> sin = sin_gen(FREQ, AMPL, PHAS);
    std::vector<int16_t> sin_int16_t = quantize(sin);
    float err = quantize_error(sin_int16_t, sin);

    std::cout << "MAE квантования(float -> int16_t): " << err << std::endl;

    std::cout << "\nЗависимость ошибки upsameple при разных значения частоты сигнала(float):\n";
    for (float freq : {1.0f, 5.0f, 10.0f, 20.0f, 49.0f})
    {
        auto s = sin_gen(freq, AMPL, PHAS);
        for (size_t j = 0; j < s.size(); ++j)
        {
            output << s[j];
            if (j < s.size() - 1) output << ",";
        }
        output << "\n";
        auto s_up = upsampler_float(s);
        for (size_t j = 0; j < s_up.size(); ++j)
        {
            output << s_up[j];
            if (j < s_up.size() - 1) output << ",";
        }
        output << "\n";
        float mae = rate_upsampler_float(s_up, freq, s_up.size(), AMPL, PHAS);
        std::cout << freq << " Hz -> MAE: " << mae << std::endl;
    }

    std::cout << "\nЗависимость ошибки upsameple при разных значения частоты сигнала(int16_t):\n";
    for (float freq : {1.0f, 5.0f, 10.0f, 20.0f, 49.0f})
    {
        auto s = sin_gen(freq, AMPL, PHAS);
        auto s_int16_t = quantize(s);
        for (size_t j = 0; j < s_int16_t.size(); ++j)
        {
            output << s_int16_t[j];
            if (j < s_int16_t.size() - 1) output << ",";
        }
        output << "\n";
        auto s_up_int16_t = upsampler_int16_t(s_int16_t);
        for (size_t j = 0; j < s_up_int16_t.size(); ++j)
        {
            output << s_up_int16_t[j];
            if (j < s_up_int16_t.size() - 1) output << ",";
        }
        output << "\n";
        float mae = rate_upsampler_int16_t(s_up_int16_t, freq, s_up_int16_t.size(), AMPL, PHAS);
        std::cout << freq << " Hz -> MAE: " << mae << std::endl;
    }
}
