#include <vector>
#include <iostream>

template<typename T, size_t N>
std::vector<T> arrayToVector(const T (&w)[N]){
    return std::vector<T>(w, w+N);
}

int main(int argc, const char** argv) {
    int pole [] = {0, 4, 7};
    std::vector<int> a = arrayToVector(pole);

    for (std::vector<int>::iterator wrap_iter = a.begin(); wrap_iter != a.end(); ++wrap_iter) {
        std::cout << *wrap_iter << std::endl;
    }
}
