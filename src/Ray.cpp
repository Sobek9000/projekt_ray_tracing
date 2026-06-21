#include "Ray.h"

// normalizujemy kierunek przy tworzeniu promienia
Ray::Ray(const Vec3 &poczatek, const Vec3 &kierunek)
    : poczatek(poczatek), kierunek(kierunek.normalizuj()) {}

// punkt na promieniu po jakims t
Vec3 Ray::punkt(double t) const { return poczatek + kierunek * t; }
