#include "random.hpp"
#include <random>

using uniform_int = std::uniform_int_distribution<>;
using uniform_real = std::uniform_real_distribution<float>;

static std::random_device random_dev;
static std::mt19937 generator(random_dev());


int random(int min, int max) {
        return uniform_int(min, max)(generator);
}

float randomf(float min, float max) {
        return uniform_real(min, max)(generator);
}
