#include "Camera.h"

// kamera wzdluz Z
// parametry ekranu
Camera::Camera()
    : szerokoscEkranu(4.0), wysokoscEkranu(2.0), ogniskowa(1.0),
      pozycja(0.0, 0.0, 0.0) {
  // wektory plaszczyzny rzutowania
  poziomy = Vec3(szerokoscEkranu, 0.0, 0.0);
  pionowy = Vec3(0.0, wysokoscEkranu, 0.0);

  // ustalamy pozycje  poczatkowa
  lewyDolnyRog =
      pozycja - poziomy / 2.0 - pionowy / 2.0 + Vec3(0.0, 0.0, ogniskowa);
}

// Generuje promień dla znormalizowanych współrzędnych (u, v)
// u, v ∈ [0,1], gdzie (0,0) to lewy dolny róg obrazu
Ray Camera::generujPromien(double u, double v) const {
  // Punkt na płaszczyźnie rzutowania
  Vec3 cel = lewyDolnyRog + poziomy * u + pionowy * v;

  // Kierunek od kamery do celu
  Vec3 kierunek = cel - pozycja;

  return Ray(pozycja, kierunek);
}
