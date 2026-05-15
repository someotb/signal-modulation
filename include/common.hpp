#pragma once

#include <cstdint>
#include <vector>

std::vector<float> sin_gen(const float freq, float ampl, float phase);
std::vector<float> upsampler_float(const std::vector<float> &signal);
std::vector<int16_t> upsampler_int16_t(const std::vector<int16_t> &signal);
std::vector<int16_t> quantize(const std::vector<float> &signal);
float quantize_error(const std::vector<int16_t> &signal_int16_t, const std::vector<float> &signal_float);
float rate_upsampler_float(const std::vector<float> &signal_up, const float freq, const int fs, float ampl, float phase);
float rate_upsampler_int16_t(const std::vector<int16_t> &signal_up, const float freq, const int fs, float ampl, float phase);
