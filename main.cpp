#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<long long>> processing(ifstream *file) {
    long long num_items;
    (*file) >> num_items;
    //Читаем матрицу
    vector<vector<long long>>transport_network_matrix(num_items);//матрица транспортной сети
    for (long long i = 0; i < num_items; ++i) {
        for(long long j = 0; j < num_items; ++j)
            transport_network_matrix[i].push_back(0);
    }
    for (long long i = 0; i < num_items; ++i) {
        for (long long j = 0; j < num_items; ++j) {
            (*file) >> transport_network_matrix[i][j];
        }
    }
    return transport_network_matrix;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
