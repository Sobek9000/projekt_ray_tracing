#pragma once

#include "Ray.h"
#include "Vec3.h"

// tworzymy kamere
class Camera {
public:
  //-definiujemy zmienne rozmiary ekranu i polozenie
  double szerokoscEkranu;
  double wysokoscEkranu;
  double ogniskowa;
  Vec3 pozycja;
  Vec3 lewyDolnyRog;
  Vec3 poziomy;
  Vec3 pionowy;

  Camera();

  // generujemy promien dla kazdego piksela
  Ray generujPromien(double u, double v) const;
};
