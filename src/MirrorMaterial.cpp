#include "MirrorMaterial.h"

// zapamietujemy kolor lustra
MirrorMaterial::MirrorMaterial(const Color &kolor) : kolor(kolor) {}

// zwracamy kolor lustra
Color MirrorMaterial::albedo() const { return kolor; }
// odbijamy promień zgodnie z prawem odbicia
bool MirrorMaterial::odbij(const Ray &padajacy, const HitRecord &rekord,
                           Ray &odbity) const {
  Vec3 normalna = rekord.normalna;
  Vec3 kierunek = padajacy.kierunek;
  Vec3 odbitoKierunek =
      kierunek - normalna * (2.0 * kierunek.dot(normalna)); // prawo odbicia

  // odbity promień startuje nad powierzchnią zeby nie trafil w siebie
  Vec3 poczatek = rekord.punkt + normalna * 0.001;

  odbity = Ray(poczatek, odbitoKierunek);
  return true;
}
