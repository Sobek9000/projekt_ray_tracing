#pragma once

#include "Color.h"
#include "HitRecord.h"
#include "Ray.h"

// klasa materiału
class Material {
public:
  virtual ~Material() = default;
  virtual Color albedo() const = 0; // daje kolor
  virtual bool odbij(const Ray &padajacy, const HitRecord &rekord,
                     Ray &odbity) const = 0; // odbija
};
