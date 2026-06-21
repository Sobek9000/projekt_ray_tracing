#pragma once

#include "Object.h"
#include <memory>
#include <vector>

// lista wszystkich obiektów
class Scene {
public:
  // tablica wszystkich obiektów
  std::vector<std::unique_ptr<Object>> obiekty;
  void dodaj(std::unique_ptr<Object> obiekt);
  // sprawdzamy czy promień trafił w cos i zapisujemy informacje do rekord
  bool przeciecie(const Ray &promien, double tMin, double tMax,
                  HitRecord &rekord) const;
};
