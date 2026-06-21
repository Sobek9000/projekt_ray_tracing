#include "Sphere.h"
#include "Material.h"
#include <cmath>

// Konstruktor kuli
Sphere::Sphere(const Vec3 &srodek, double promien,
               std::shared_ptr<Material> mat)
    : srodek(srodek), promien(promien), mat(mat) {}

// Obliczanie przecięcia promienia z kulą
bool Sphere::przeciecie(const Ray &ray, double tMin, double tMax,
                        HitRecord &rekord) const {
  Vec3 oc = ray.poczatek - srodek; // wektor od kuli do promienia
  // rownanie kwadratowe
  double a = ray.kierunek.dot(ray.kierunek);
  double b = 2.0 * oc.dot(ray.kierunek);
  double c = oc.dot(oc) - promien * promien;

  double delta = b * b - 4.0 * a * c;

  if (delta < 0.0) {
    // Brak rzeczywistych rozwiązań – promień nie trafia w kulę
    return false;
  }

  double pierwiastek = std::sqrt(delta);

  // Sprawdzamy mniejszy pierwiastek bo blizej
  double t = (-b - pierwiastek) / (2.0 * a);
  if (t < tMin || t > tMax) {
    // jak mniejszy nie dziala to wiekszy
    t = (-b + pierwiastek) / (2.0 * a);
    if (t < tMin || t > tMax) {
      return false;
    }
  }

  // Zapisujemy info o trafieniu
  rekord.t = t;
  rekord.punkt = ray.punkt(t);
  // Normalna skierowana na zewnatrz kuli
  rekord.normalna = (rekord.punkt - srodek) / promien;
  rekord.material = mat.get();

  return true;
}
