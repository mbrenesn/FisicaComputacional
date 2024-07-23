// Estos son macros de preprocesamiento
// La idea es que si incluimos este archivo en uno o más otros,
// no haya declaración doble de la clase!!
// Dobles declaraciones no son permitidas en C++
// Este archivo nada más contiene la declaración de la clase
#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

class MyVector
{
  private:
    int m_n;
    MyVector(); // Default constructor
  public:
    float *data;
    int get_n();
    float norm();
    MyVector(int n); // Custom constructor
    ~MyVector(); // Destructor
    // A esta implementación tiene un destructor que nosotros definimos
    // Le falta cumplir la regla de tres!!
};
#endif
