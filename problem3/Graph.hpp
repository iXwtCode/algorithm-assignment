#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
class Graph {
public:
    using GraphType = vector<vector<int>>;
    using pos_E = pair<int, int>;
    using pos_V = int;
    Graph(int n) : origin(vector<vector<int>>(n, vector<int>(n , -1))), V(n) , E(0) {}
    Graph(const GraphType &g);
    //获取图的的点集合
    set<pos_V> get_set_V() const;
    //获取图的边集合
    set<pos_E> get_set_E() const;
    //设置一条边，返回对象
    Graph set_E(pos_E pe, int l) {
        origin[pe.first][pe.second] = l;
        origin[pe.second][pe.first] = l;
        return *this;
    };
    //删除一条边
    Graph del_E(pos_E pe) {
        set_E(pe, -1);
        return *this;
    };
    //判断两顶点间是否有边
    bool has_e(const pos_V pv1, const pos_V pv2) const {
        return origin[pv1][pv2] > 0;
    };
    //返回边的长度
    int len_E(const pos_E &pe) const {
        return origin[pe.first][pe.second];
    };
    //返回边的数量
    int nums_of_edge() const {
        return E;
    }
    //返回点的数量
    int nums_of_vec() const {
        return V;
    }
    //返回邻接矩阵
    GraphType get_matrix() const {
        return {origin.begin(), origin.end()};
    }
private:
    GraphType origin;
    int E;
    int V;
};

#endif