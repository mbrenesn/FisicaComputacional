#include <iostream>
#include <cmath>

class MyVector
{
  private:
    int m_n; // Tamaño local del vector
    MyVector(); // Constructor base privado para evitar construcción
                // indefinida
  public:
    MyVector(int n); // Constructor personalizado
    ~MyVector(); // Destructor! 
    MyVector(const MyVector &obj); // Constructor copia
    float *data; // Los datos del vector
    int get_n(); // Una función miembro para obtener el tamaño del vector
    float norm(); // Una función miembro para calcular la norma
};

// Constructor personalizado
// El constructor base no necesita ser implementado
MyVector::MyVector(int n){
  m_n = n;
  data = new float[m_n]; // Solicito n floats para mi vector y los ubico en el heap
}

// Destructor personalizado
// El destructor debe limpiar la memoria solicitada!!
MyVector::~MyVector(){
  delete [] data; // El "[]" después de "delete" borra todos los "n" bloques
                  // de memoria solicitados
}

// Constructor copia profundo
// Un nuevo bloque de datos es creado y copiado!
MyVector::MyVector(const MyVector &obj){
  std::cout << "Copy constructor invoked!" << std::endl;
  m_n = obj.m_n;
  data = new float[m_n];
  for(int i = 0; i < m_n; ++i){
    data[i] = obj.data[i];
  }
}

// No vamos a dejar que el tamaño se modifique, solo accesarse
// mediante esta función
// Porqué??
int MyVector::get_n(){
  return m_n;
}

// Función que calcula la norma
// Ojo con el acumulador "sum"!
float MyVector::norm(){
  float sum = 0.0;
  for(int i = 0; i < m_n; ++i){
    sum += data[i] * data[i];
  }

  return std::sqrt(sum);
}

int main(){

  // Construyo un vector
  MyVector a(2);
  // Le pongo la información que quiero
  for(int i = 0; i < a.get_n(); ++i){
    a.data[i] = 1.0;
  }

  MyVector b = a; // Esto invoca el constructor copia
  std::cout << b.norm() << std::endl;

  a.data[0] = 0.0;
  std::cout << b.norm() << std::endl; // La norma de b se mantiene igual porque 
                                      // sus datos corresponden a los de un objeto 
                                      // nuevo

  return 0;
}
