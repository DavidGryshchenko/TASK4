#include <vector>
using std::vector;
vector < vector<int> > g;
vector<char> cl;
vector<int> p;

int cycle_st, cycle_end;

bool dfs(int v) {
    cl[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (cl[to] == 0) {
            p[to] = v;
            if (dfs(to))  return true;
        }
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}
