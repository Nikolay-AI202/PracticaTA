#include <iostream>
#include <cstring>

using namespace std;
#define INF 9999999
#define V 8
int G[V][V] = {
        {INF, 5,   2,   4,   INF, INF, INF, INF},
        {5,   INF, INF, INF, 7,   3,   INF, INF},
        {2,   INF, INF, 8,   INF, 5,   INF, INF},
        {3,   INF, 8,   INF, 1,   INF, INF, INF},
        {INF, 7,   INF, 1,   INF, INF, 4,   INF},
        {INF, 3,   5,   INF, INF, INF, 6,   INF},
        {INF, INF, INF, INF, 4,   6,   INF, 5},
        {INF, INF, INF, INF, INF, INF, 5,   INF},
};

int main() {
    int no_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x;
    int y;
    cout << "Edge" << " : " << "Weight";
    cout << endl;
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x + 1 << " - " << y + 1 << " : " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}