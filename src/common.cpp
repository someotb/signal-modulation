#include "common.hpp"
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <vector>

std::vector<float> sin_gen(const float freq, float ampl, float phase)
{
    if (freq <= 0.0f or freq > 50.0f)
        throw std::invalid_argument("Choose 0.0 < freq <= 50.0");
    if (ampl <= 0.0f)
        throw std::invalid_argument("Choose Amplitude > 0.0");
    if (phase < -M_PIf or phase > M_PIf)
        throw std::invalid_argument("Choose Phase [-Pi; Pi]");

    const int fs = 100;
    const float fs_step = 1.0f / fs;
    std::vector<float> sinus;

    for (size_t i = 0; i < fs; ++i)
        sinus.push_back(ampl * std::sin(2 * M_PIf * freq * i * fs_step + phase));

    return sinus;
}
