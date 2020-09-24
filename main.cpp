#include <iostream>
#include <fstream>
#include "maxFlow.h"
using namespace std;

int main() {
    ifstream file;
    file.open("../maxFlowTests/test2.in", ios_base::in);
    vector<vector<long long>> c = std::move(processing(&file));
    vector<vector<long long>>f(c.size());
    const long long s = 0, t = 1;
    //заполним матрицу потока нулями
    for (long long i = 0; i < c.size(); ++i) {
        for(long long j = 0; j < c.size(); ++j)
            f[i].push_back(0);
    }
    vector<long long> prior = move(BFS(c, 0, 1));
    vector<long long> way = move(getPath(prior, 1, 0));
    while (!way.empty()){
        long long prev_point = 0, min_flow = 0;
        for(const auto el : way){
            if(c[prev_point][el] < min_flow || min_flow == 0){
                min_flow = c[prev_point][el];
            }
            prev_point = el;
        }
        for(int i = 0; i < way.size() - 1; ++i){
            long long a = way[i], b = way[i+1];
            f[a][b] += min_flow;
            f[b][a] -= min_flow;
            c[a][b] -= min_flow;
            c[b][a] += min_flow;
        }
        prior = move(BFS(c, 0, 1));
        way = move(getPath(prior, 1, 0));
        min_flow = 0;
    }
    for(const auto el : f){
        for (const auto e: el){
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
