#include "maxFlow.h"
#include <string>
#include <fstream>
#include <queue>
#include <algorithm>
vector<long long> getPath(vector<long long>& prior, long long dest, long long origin)
{
    vector<long long> ans;
    if(prior[dest] == -1){
        return ans;
    }
    for (int v = dest; v != origin; v = prior[v])  // Проходим по пути из конца в начало
    {
        ans.push_back(v);  // Запоминаем вершину
    }
    ans.push_back(origin);
    reverse(ans.begin(), ans.end());  // Переворачиваем путь
    return ans;
}
vector<long long> BFS(vector<vector<long long>>&_data, long long origin, long long dest){
    queue<long long> queue;
    queue.push(origin);
    vector<bool> visited(_data.size());
    vector<long long>prior(_data.size());
    for (long long i = 0; i < _data.size(); ++i) {
        prior[i] = -1;
    }
    long long current = origin;
    prior[origin] = origin;
    while (!queue.empty()) {
        current = queue.front();
        queue.pop();
        if (!visited[current]) {
            visited[current] = true;
            for(long i = 0; i < _data.size(); ++i){
                if(_data[current][i] != 0){
                    queue.push(i);
                    prior[i] = !visited[i] ? current : prior[i];
                }
            }
        }
    }
    return prior;
}
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
