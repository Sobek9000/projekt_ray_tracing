#pragma once

#include "HitRecord.h"
#include "Ray.h"
// tworzymy klasa na obiekty
class Object {
public:
  // destruktor
  virtual ~Object() = default;
  // sprawdzamy czy trafiamy w obiekt i zapisujemy informacje do rekord
  virtual bool przeciecie(const Ray &promien, double tMin, double tMax,
                          HitRecord &rekord) const = 0;
};
