#include "Color.h"
#include <algorithm>
#include <cmath>

// Konwertuje wartość z [0,1] na liczbę całkowitą z zakresu [0, 65535]
int zaokraglij16bit(double wartosc) {
    // Clampujemy na wszelki wypadek i mnożymy przez 65535
    return static_cast<int>(std::round(std::clamp(wartosc, 0.0, 1.0) * 65535.0));
}
