#pragma once

#include "Color.h"
#include "Material.h"

// lustro
class MirrorMaterial : public Material {
public:
  Color kolor; // kolor lustra z materialu
  MirrorMaterial(const Color &kolor);
  Color albedo() const override;

  // promien odbity startuje odrobine nad powierzchnia zeby nie trafil w siebie
  bool odbij(const Ray &padajacy, const HitRecord &rekord,
             Ray &odbity) const override;
};
