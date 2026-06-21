#include "Scene.h"
#include <utility>

// dodaje object do sceny unique ptr pilnuje pamieci
void Scene::dodaj(std::unique_ptr<Object> obiekt) {
  obiekty.push_back(std::move(obiekt));
}

// Lecimy po wszystkich obiektach
bool Scene::przeciecie(const Ray &promien, double tMin, double tMax,
                       HitRecord &rekord) const {
  HitRecord tymczasowyRekord;
  bool trafiono = false;
  double najblizsze = tMax;
  // sprawdzamy przeciecie z kazdym obiektem
  for (const auto &obiekt : obiekty) {
    if (obiekt->przeciecie(promien, tMin, najblizsze, tymczasowyRekord)) {
      trafiono = true;
      najblizsze = tymczasowyRekord.t;
      rekord = tymczasowyRekord;
    }
  }

  return trafiono;
}
