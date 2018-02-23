#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <tuple>
#include <queue>

using namespace std;

#define NMax (10)
#define DMax (6)

typedef struct Node {
    int index;
    int time;
    vector<Node*> next;

    Node(int index) : index(index), time(-1) {
        next.push_back(nullptr);
    }
} Node;

typedef array<array<int, NMax>, NMax> Grid;
typedef array<array<Node*, NMax>, NMax> Graph;

void bfs(Node *start) {
    start->time = 0;
    queue<Node*> q;
    q.push(start);

    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        //cout << "at " << cur->index << " (" << cur->time << ")" << endl;
        if (cur->index == NMax * NMax - 1)
            break;
        for (int dt = 0; dt < cur->next.size(); ++dt) {
            Node *next = cur->next[dt];
            if (next != nullptr && next->time < 0) {
                next->time = cur->time + (dt == 0 ? 0 : 1);
                q.push(next);
            }
        }
    }
}

int main() {
    // setup indices for the graph
    Grid indices;
    unordered_map<int, pair<int, int>> ind2rc;
    int k = 0;
    bool left2right = true;
    for (int r = 0; r < NMax; ++r) {
        if (left2right)
            for (int c = 0; c < NMax; ++c) {
                indices[r][c] = k++;
                ind2rc[indices[r][c]] = make_pair(r, c);
            }
        else
            for (int c = NMax - 1; c >= 0; --c) {
                indices[r][c] = k++;
                ind2rc[indices[r][c]] = make_pair(r, c);
            }
        left2right = !left2right;
    }

    // read test cases
    int t;
    cin >> t;
    while (t--) {
        Graph graph;
        for (int r = 0; r < NMax; ++r)
            for (int c = 0; c < NMax; ++c)
                graph[r][c] = new Node(indices[r][c]);

        // set up the basic graph transitions
        for (int r = 0; r < NMax; ++r)
            for (int c = 0; c < NMax; ++c) {
                int ind = indices[r][c];
                for (int d = 1; d <= DMax; ++d) {
                    if (ind + d < NMax * NMax) {
                        int nr, nc;
                        tie(nr, nc) = ind2rc[ind + d];
                        graph[r][c]->next.push_back(graph[nr][nc]);
                    }
                }
            }

        // ladders & snakes
        for (int _t = 0; _t < 2; ++_t) {
            int n;
            cin >> n;
            while (n--) {
                int u, v;
                cin >> u >> v;
                --u, --v;
                int ru, cu, rv, cv;
                tie(ru, cu) = ind2rc[u];
                tie(rv, cv) = ind2rc[v];

                Node *nu = graph[ru][cu], *nv = graph[rv][cv];
                nu->next.clear();
                nu->next.push_back(nv);
            }
        }

        // look for the quickest path
        bfs(graph[0][0]);
        cout << graph[NMax - 1][0]->time << endl;
    }
    return 0;
}