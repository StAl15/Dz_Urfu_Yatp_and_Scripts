#include <iostream>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
    int to, length, speed;
};

struct Graph {
    int n;
    Edge* edges[100000];
    Graph(int n): n(n) {
        for (int i = 0; i < n; i++) {
            edges[i] = nullptr;
        }
    }
    void addEdge(int u, int v, int length, int speed) {
        edges[u] = new Edge({v, length, speed, edges[u]});
        edges[v] = new Edge({u, length, speed, edges[v]});
    }
};

int dist[100000];

void dijkstra(Graph& graph, int start) {
    for (int i = 0; i < graph.n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (Edge* e = graph.edges[u]; e != nullptr; e = e->next) {
            int v = e->to;
            int len = e->length;
            int speed = e->speed;
            int time = len / speed;
            if (dist[u] + time < dist[v]) {
                dist[v] = dist[u] + time;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, len, speed;
        cin >> u >> v >> len >> speed;
        graph.addEdge(u, v, len, speed);
    }
    dijkstra(graph, 0);
    int minTime = 0;
    for (int i = 0; i < n; i++) {
        minTime = max(minTime, dist[i]);
    }
    cout << "All cities will know about the Olympics in " << minTime << " hours." << endl;
    return 0;
}