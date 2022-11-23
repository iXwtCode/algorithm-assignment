/*
 * 求解所给图的最小生成树
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <functional>
#include "Graph.hpp"
using namespace std;


//并查集
int find(int x, vector<int> &p) {
    if (p[x] != x) p[x] = find(p[x], p);
    return p[x];
}

//最小生成树
Graph BST(const Graph g) {
    //mst初始化为一个顶点数量与g相同但没有变的树
    int n = g.nums_of_vec();
    Graph res(n);

    auto f = [&](const Graph::pos_E &a, const Graph::pos_E &b) {
        return g.len_E(a) <= g.len_E(b);
    };

    //未加入到最小生成树中的边集合, 按从小到大排序
    auto se = g.get_set_E();
    auto sv = g.get_set_V();
    vector<int> set_v(sv.begin(), sv.end());
    set<Graph::pos_E, decltype(f)> set_e(se.begin(), se.end(), f);
    se.clear(), sv.clear();

    // 初始化并查集
    vector<int> p(set_v.size());
    for(int i = 0; i < n; ++i) p[i] = i;

    for(auto it = set_e.begin(); it != set_e.end(); ++it) {
        int a = it->first, b = it->second;
        a = find(a, p), b = find(b, p);
        if(a !=b) {
            res.set_E(*it, g.len_E(*it));
            p[a] = b;
        }
    }

    return res;
}

//生成原始图
vector<vector<int>> set_resource() {
    vector<vector<int>> data(17, vector<int>(17, -1));
    vector<pair<int, int>>
            index{{0, 1}, {0, 4}, {1, 0}, {1, 2}, {1 ,3}, {2, 1}, {2, 3}, {2, 6}, {3, 1}, {3, 2}, {3, 4}, {3, 7},
                  {4, 0}, {4, 3}, {4, 5}, {4, 9}, {5, 8}, {5, 4}, {5, 9}, {6, 2}, {6, 7}, {6, 11}, {7, 3}, {7, 6},
                  {7, 8}, {7, 10}, {8, 5}, {8, 7}, {8 ,13}, {9, 4}, {9, 5}, {9, 16}, {10, 11},{10, 7},{10,13},
                  {11, 6}, {11, 10}, {11, 15}, {12, 10}, {12, 13}, {12, 14}, {13, 8}, {13, 12}, {13,16}, {14, 12},
                  {14, 15}, {14, 16}, {15, 11}, {15, 14}, {15, 16}, {16, 15}, {16, 14}, {16, 13}, {16, 9}};
    vector<int> v{12,18,12,3,5,3,4,19,3,4,7,21,18,17,18,31,3,18,12,19,4,7,21,4,13,6,3,13,9,
                  31,12,35,5,6,6,7,5,14,6,9,6,9,9,24,6,6,8,14,6,7,7,8,24,35};

    int n = v.size();
    for(int i = 0; i < n; ++i) {
        data[index[i].first][index[i].second] = v[i];
    }
    return {data.begin(), data.end()};
}

//打印结果
void print_result(vector<vector<int>> mat) {
    int n = mat.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << mat[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "-------------------------------------------------------\n";
}

int main() {
    vector<vector<int>> data = set_resource();
    Graph d(data);
    auto res = BST(d);
    auto mat = res.get_matrix();

    print_result(d.get_matrix());
    print_result(mat);
    return 0;
}