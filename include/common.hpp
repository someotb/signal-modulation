#pragma once

#include <cstdint>
#include <vector>

std::vector<float> sin_gen(const float freq, float ampl, float phase);
std::vector<int16_t> quantize(const std::vector<float> &signal);
float quantize_error(const std::vector<int16_t> &signal_int16_t, const std::vector<float> &signal_float);
