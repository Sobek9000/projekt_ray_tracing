#include "Vec3.h"
#include <cmath>

// konstruktor z wyzerowanym wektorem
Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}
// konstruktor z podanymi wartosciami
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

// operacje wektorowe zdefiniowane wczesniej
Vec3 Vec3::operator+(const Vec3 &inny) const {
  return Vec3(x + inny.x, y + inny.y, z + inny.z);
}
Vec3 Vec3::operator-(const Vec3 &inny) const {
  return Vec3(x - inny.x, y - inny.y, z - inny.z);
}
Vec3 Vec3::operator*(double skalar) const {
  return Vec3(x * skalar, y * skalar, z * skalar);
}
Vec3 Vec3::operator/(double skalar) const {
  return Vec3(x / skalar, y / skalar, z / skalar);
}
Vec3 Vec3::operator*(const Vec3 &inny) const { // mnozenie po kolei do kolorow
  return Vec3(x * inny.x, y * inny.y, z * inny.z);
}
Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }
// dot product
double Vec3::dot(const Vec3 &inny) const {
  return x * inny.x + y * inny.y + z * inny.z;
}
// dlugosc wektora
double Vec3::dlugosc() const { return std::sqrt(x * x + y * y + z * z); }
// normalizacja
Vec3 Vec3::normalizuj() const {
  double dl = dlugosc();
  return *this / dl;
}
Vec3 operator*(double skalar, const Vec3 &v) { return v * skalar; }
