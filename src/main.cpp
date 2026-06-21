#include <iostream>
#include <memory>

#include "Camera.h"
#include "MirrorMaterial.h"
#include "Renderer.h"
#include "Scene.h"
#include "Sphere.h"

int main() {
  // tworzenie calej sceny
  Scene scena;
  // materialy kolorowe do lusterek
  auto materialCzerwony =
      std::make_shared<MirrorMaterial>(Color(1.0, 0.3, 0.3));
  auto materialZielony = std::make_shared<MirrorMaterial>(Color(0.3, 1.0, 0.4));
  auto materialNiebieski =
      std::make_shared<MirrorMaterial>(Color(0.4, 0.6, 1.0));
  auto materialZloty = std::make_shared<MirrorMaterial>(Color(1.0, 0.85, 0.3));
  auto materialBialy = std::make_shared<MirrorMaterial>(Color(0.9, 0.9, 0.9));
  // dodajemy 4 kulki
  scena.dodaj(
      std::make_unique<Sphere>(Vec3(-1.5, 0.0, 4.0), 0.7, materialCzerwony));
  scena.dodaj(
      std::make_unique<Sphere>(Vec3(0.0, 0.0, 5.0), 0.7, materialZielony));
  scena.dodaj(
      std::make_unique<Sphere>(Vec3(1.5, 0.0, 4.0), 0.7, materialNiebieski));
  scena.dodaj(
      std::make_unique<Sphere>(Vec3(0.0, 0.5, 3.0), 0.5, materialZloty));
  // dodajemy podloge czyli duza kula
  scena.dodaj(
      std::make_unique<Sphere>(Vec3(0.0, -101.0, 4.0), 100.0, materialBialy));
  // ustawiamy kamere
  Camera kamera;
  // renderer 800x400, max glebokosc rekurencji to 10 odbic
  Renderer renderer(800, 400, 10);

  // render i zapis w ppm
  renderer.renderuj(scena, kamera, "obraz.ppm");

  std::cout << "Program zakonczony.\n";
  return 0;
}
