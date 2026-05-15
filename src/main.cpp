#include "common.hpp"

#include <cmath>
#include <iostream>
#include <vector>

constexpr float FREQ = 1.0f;
constexpr float AMPL = 1.0f;
constexpr float PHAS = 0.0f;

int main()
{
    std::vector<float> sin = sin_gen(FREQ, AMPL, PHAS);
    std::vector<int16_t> sin_int16_t = quantize(sin);
    float err = quantize_error(sin_int16_t, sin);

    std::cout << "MAE квантования(float -> int16_t): " << err << std::endl;

    std::cout << "\nЗависимость ошибки upsameple при разных значения частоты сигнала(float):\n";
    for (float freq : {1.0f, 5.0f, 10.0f, 20.0f, 49.0f})
    {
        auto s = sin_gen(freq, AMPL, PHAS);
        auto s_up = upsampler_float(s);
        float mae = rate_upsampler_float(s_up, freq, s_up.size(), AMPL, PHAS);
        std::cout << freq << " Hz -> MAE: " << mae << std::endl;
    }

    std::cout << "\nЗависимость ошибки upsameple при разных значения частоты сигнала(int16_t):\n";
    for (float freq : {1.0f, 5.0f, 10.0f, 20.0f, 49.0f})
    {
        auto s = sin_gen(freq, AMPL, PHAS);
        auto s_int16_t = quantize(s);
        auto s_up_int16_t = upsampler_int16_t(s_int16_t);
        float mae = rate_upsampler_int16_t(s_up_int16_t, freq, s_up_int16_t.size(), AMPL, PHAS);
        std::cout << freq << " Hz -> MAE: " << mae << std::endl;
    }
}
