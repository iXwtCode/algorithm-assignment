
#include "Graph.hpp"
set<Graph::pos_V> Graph::get_set_V() const {
    set<pos_V> res;
    for(int i = 0; i < V; ++i) {
        res.insert(i);
    }
    return res;
}

Graph::Graph(const GraphType &g)  : origin(g), V(g.size()) {
    int temp_e;
    for(auto &vec : g) {
        for(auto &v : vec) {
            if(v > 0) {
                ++temp_e;
            }
        }
    }
    E = temp_e / 2;
}

set<Graph::pos_E> Graph::get_set_E() const {
    set<pos_E> res;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            pos_E temp = make_pair(i, j);
            if(has_e(i, j) && res.count(make_pair(j, i)) == 0) {
                res.insert(temp);
            }
        }
    }
    return res;
}