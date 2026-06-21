#pragma once

// klasa trójwymiarowego wektora czy do promieni czy do koloru czy do punktu
class Vec3 {
public:
  double x, y, z;
  // konstruktory
  Vec3();
  Vec3(double x, double y, double z);

  // operatory
  Vec3 operator+(const Vec3 &inny) const;
  Vec3 operator-(const Vec3 &inny) const;
  Vec3 operator*(double skalar) const;
  Vec3 operator/(double skalar) const;
  Vec3 operator*(const Vec3 &inny) const;
  Vec3 operator-() const;             // negacja
  double dot(const Vec3 &inny) const; //(dot product)
  double dlugosc() const;
  Vec3 normalizuj() const; // wektor jednostkowy
};
// mnozenie skalara przez wektor
Vec3 operator*(double skalar, const Vec3 &v);
