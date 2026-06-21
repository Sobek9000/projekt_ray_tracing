#pragma once

#include "Vec3.h"

class Material;

// informacje o przecięciu
struct HitRecord {
  Vec3 punkt;
  Vec3 normalna;
  double t;           // dystans od kamery
  Material *material; // jaki material

  HitRecord() : t(0.0), material(nullptr) {}
};
