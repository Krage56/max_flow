//
// Created by krage56 on 24.09.2020.
//

#ifndef MAX_FLOW_MAXFLOW_H
#define MAX_FLOW_MAXFLOW_H
#include <vector>
#include <fstream>
using namespace std;
vector<long long> getPath(vector<long long>& prior, long long dest, long long origin);
vector<long long> BFS(vector<vector<long long>>&_data, long long origin, long long dest);
vector<vector<long long>> processing(ifstream *file);
#endif //MAX_FLOW_MAXFLOW_H
