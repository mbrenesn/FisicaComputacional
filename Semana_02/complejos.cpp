#include <complex>
#include <iostream>

int main(){

  std::complex<double> a(3.0, 5.0); // <-- Esto invoca al constructor
  std::complex<double> b = a * a;

  std::cout << "a = " << a << " a.real() = " << a.real() << " a.imag() = " << a.imag() << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << " exp(b) = " << std::exp(b) << std::endl;

  return 0;
}


