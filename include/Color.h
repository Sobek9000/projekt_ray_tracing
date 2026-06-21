#pragma once

#include "Vec3.h"

// Kolor RGB to wektor x y z odpowiada red green blue
using Color = Vec3;

// zamieniamy na liczbe calkowita 0 do 65535 ppm 16 bit
int zaokraglij16bit(double wartosc);
