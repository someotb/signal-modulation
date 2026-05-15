#include "common.hpp"

#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    std::vector<float> sin = sin_gen(50.0f, 1.0f, 0.0f);

    for (const auto &e : sin)
        std::cout << e << std::endl;

    std::cout << "Len" << sin.size() << std::endl;
}
