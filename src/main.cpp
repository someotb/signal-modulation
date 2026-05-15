#include "common.hpp"

#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    std::vector<float> sin = sin_gen(1.0f, 1.0f, 0.0f);
    std::vector<int16_t> sin_int16_t = quantize(sin);
    float err = quantize_error(sin_int16_t, sin);
    std::vector<float> sin_up = upsampler(sin);

    for (size_t i = sin.size() - 5; i < sin.size(); ++i)
        std::cout << sin[i] << " | " << sin_int16_t[i] << std::endl;

    for (size_t i = sin.size() - 6; i < sin.size(); ++i)
        std::cout << sin_up[2 * i] << " | " << sin[i] << "\n" << sin_up[2 * i + 1] << std::endl;

    std::cout << "MAE: " << err << std::endl;
}
