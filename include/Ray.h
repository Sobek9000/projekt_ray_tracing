#pragma once

#include "Vec3.h"

// Promien ma punkt startowy i kierunek
class Ray {
public:
  Vec3 poczatek;
  Vec3 kierunek;
  Ray(const Vec3 &poczatek, const Vec3 &kierunek);
  Vec3 punkt(double t) const; // punkt na promieniu w odleglosci t
};
