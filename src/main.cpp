#include "common.hpp"

#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    std::vector<float> sin = sin_gen(15.0f, 1.0f, 0.0f);
    std::vector<int16_t> sin_int16_t = quantize(sin);
    float err = quantize_error(sin_int16_t, sin);

    for (size_t i = 0; i < 25; ++i)
        std::cout << sin[i] << " | " << sin_int16_t[i] << std::endl;

    std::cout << "MAE: " << err << std::endl;
}
