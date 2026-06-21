#include "Renderer.h"
#include "Color.h"
#include "Material.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>

// tworzymy renderer wymiary i poziom reku
Renderer::Renderer(int szerokosc, int wysokosc, int glebokosc)
    : szerokoscObrazu(szerokosc), wysokoscObrazu(wysokosc),
      maxGlebokosc(glebokosc) {}
// prosty gradient nieba ciemniej na gorze
Color Renderer::kolorNieba(const Ray &promien) const {
  // normalizujemy kierunek
  Vec3 kierunek = promien.kierunek.normalizuj();
  // mapujemy y na t
  double t = 0.5 * (kierunek.y + 1.0);
  // interpolacja liniowa i tworzy sie gradient koloru
  Color biel(1.0, 1.0, 1.0);
  Color blekitne(0.5, 0.7, 1.0);
  return biel * (1.0 - t) + blekitne * t;
}
// sledzimy promien rekurencyjnie
Color Renderer::sledz(const Ray &promien, const Scene &scena,
                      int glebokosc) const {
  if (glebokosc <= 0) {
    return Color(0.0, 0.0,
                 0.0); // jak max glebokosc osiagnieta, zwracamy czarny
  }
  HitRecord rekord;
  if (scena.przeciecie(promien, 0.001, std::numeric_limits<double>::max(),
                       rekord)) {
    Ray odbity = promien; // placeholder do nadpisania
    if (rekord.material != nullptr &&
        rekord.material->odbij(promien, rekord, odbity)) {
      // kolor koncowy to kolor materialu razy kolor odbitego promienia
      return rekord.material->albedo() * sledz(odbity, scena, glebokosc - 1);
    }
    // jak material pochlonie to zwraca czarny
    return Color(0.0, 0.0, 0.0);
  }
  // jak promien nie uderza to niebo
  return kolorNieba(promien);
}
// renderuje scenke i zapisuje jako ppm 16-bit (P3 format)
void Renderer::renderuj(const Scene &scena, const Camera &kamera,
                        const std::string &nazwaPliku) const {
  std::ofstream plik(nazwaPliku);

  if (!plik.is_open()) {
    std::cerr << "Blad: nie mozna otworzyc pliku " << nazwaPliku << "\n";
    return;
  }

  // naglowek pliku
  plik << "P3\n";
  plik << szerokoscObrazu << " " << wysokoscObrazu << "\n";
  plik << "65535\n";

  std::cout << "Renderowanie " << szerokoscObrazu << "x" << wysokoscObrazu
            << " pikseli...\n";

  // petla po wierszach od gory do dolu
  for (int j = wysokoscObrazu - 1; j >= 0; --j) {

    for (int i = 0; i < szerokoscObrazu; ++i) {
      // normalizacja
      double u = static_cast<double>(i) / (szerokoscObrazu - 1);
      double v = static_cast<double>(j) / (wysokoscObrazu - 1);

      Ray promien = kamera.generujPromien(u, v);
      Color kolor = sledz(promien, scena, maxGlebokosc);

      // zmiana na 16-bitowe liczby
      int r = zaokraglij16bit(std::clamp(kolor.x, 0.0, 1.0));
      int g = zaokraglij16bit(std::clamp(kolor.y, 0.0, 1.0));
      int b = zaokraglij16bit(std::clamp(kolor.z, 0.0, 1.0));

      plik << r << " " << g << " " << b << "\n";
    }
  }

  std::cout << "\nZapisano: " << nazwaPliku << "\n";
}
