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
    std::vector<float> sin_up = upsampler(sin);

    std::cout << "MAE квантования(float -> int16_t): " << err << std::endl;

    std::cout << "\nЗависимость ошибки upsameple при разных значения частоты сигнала:\n";
    for (float freq : {1.0f, 5.0f, 10.0f, 20.0f, 49.0f})
    {
        auto s = sin_gen(freq, AMPL, PHAS);
        auto s_up = upsampler(s);
        float mae = rate_upsampler(s_up, freq, s_up.size(), AMPL, PHAS);
        std::cout << freq << " Hz -> MAE: " << mae << std::endl;
    }

}
