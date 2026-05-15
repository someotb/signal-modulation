#include "common.hpp"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
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

std::vector<float> upsampler(const std::vector<float> &signal)
{
    std::vector<float> signal_up(signal.size() * 2);

    for (size_t i = 0; i < signal.size() - 1; ++i)
    {
        float p0 = signal[i];
        float p1 = signal[i + 1];
        float internal_sample = (p0 + p1) / 2.0f;
        signal_up[2 * i] = p0;
        signal_up[2 * i + 1] = internal_sample;
    }

    signal_up[signal_up.size() - 2] = signal.back();
    signal_up[signal_up.size() - 1] = signal.back();

    return signal_up;
}

std::vector<int16_t> quantize(const std::vector<float> &signal)
{
    if (signal.empty())
        throw std::invalid_argument("Data empty");

    std::vector<int16_t> signal_int16_t(signal.size());
    for (size_t i = 0; i < signal.size(); ++i)
        signal_int16_t[i] = static_cast<int16_t>(signal[i] * 32767.0f);

    return signal_int16_t;
}

float quantize_error(const std::vector<int16_t> &signal_int16_t, const std::vector<float> &signal_float)
{
    if (signal_int16_t.empty())
        throw std::invalid_argument("Data empty");
    if (signal_float.empty())
        throw std::invalid_argument("Data empty");

    float error = 0.0f;
    for (size_t i = 0; i < signal_int16_t.size(); ++i)
    {
        float sample = static_cast<float>(signal_int16_t[i]) / 32767.0f;
        error += std::abs(signal_float[i] - sample);
    }

    return error / signal_float.size();
}
