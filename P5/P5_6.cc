#include <iostream>

template <class T>
void print_vector(T *v, const int n){
    for(int i = 0; i < n; i++){
        if (i == n - 1){
            std::cout << v[i] << std::endl;
        }
        else{
            std::cout << v[i] << " | ";
        }
    }
}


int main(void){
    int a[5] = {1,3,5,7,9};
    float b[4] = {5.6, 7.8, 3.9, 1.2};
    char c[5] = "hola";

    std::cout << "Vector de enteros\n";
    print_vector(a,5);

    std::cout << "Vector de floats\n";
    print_vector(b,4);

    std::cout << "Vector de char\n";
    print_vector(c,4);
    }