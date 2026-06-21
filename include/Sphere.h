#pragma once

#include "Object.h"
#include "Vec3.h"
#include <memory>

class Material;

// kula
class Sphere : public Object {
public:
  Vec3 srodek; // parametry kuli
  double promien;
  std::shared_ptr<Material> mat;

  Sphere(const Vec3 &srodek, double promien, std::shared_ptr<Material> mat);
  // obliczamy przecięcie promienia z kula
  bool przeciecie(const Ray &promien, double tMin, double tMax,
                  HitRecord &rekord) const override;
};
