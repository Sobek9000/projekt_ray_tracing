#pragma once

#include "Camera.h"
#include "Color.h"
#include "Ray.h"
#include "Scene.h"
#include <string>

// robimy ray tracing i potem zapisujemy gotowy obraz
class Renderer {
public:
  int szerokoscObrazu;
  int wysokoscObrazu;
  int maxGlebokosc;

  Renderer(int szerokosc, int wysokosc, int glebokosc);
  // render sceny kamery i zapis do pliku
  void renderuj(const Scene &scena, const Camera &kamera,
                const std::string &nazwaPliku) const;

private:
  // robimy to rekursywnie i zwracamy kolory
  Color sledz(const Ray &promien, const Scene &scena, int glebokosc) const;

  // dodajemy kolory tla/nieba
  Color kolorNieba(const Ray &promien) const;
};
