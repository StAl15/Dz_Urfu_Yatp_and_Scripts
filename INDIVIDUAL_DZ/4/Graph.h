#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
#include "fstream"

using namespace std;

// Класс для представления графа
class Graph {
private:
    int V; // Количество вершин
    int E; // Количество ребер
    int **incidenceMatrix; // Матрица инцидентности
public:
    // Конструктор
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        // Создаем матрицу инцидентности
        incidenceMatrix = new int *[V];
        for (int i = 0; i < V; ++i) {
            incidenceMatrix[i] = new int[E];
            for (int j = 0; j < E; ++j) {
                incidenceMatrix[i][j] = 0;
            }
        }
    }

    // Добавление ребра
    void addEdge(int v1, int v2, int e) {
        incidenceMatrix[v1][e] = 1;
        incidenceMatrix[v2][e] = 1;
    }

    void printM() {
        for (int i = 0; i < V; ++i) {
            cout << "Vershina " << i << ": ";
            for (int j = 0; j < E; ++j) {
                cout << incidenceMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Вывод графа
    void printGraph() {
        for (int e = 0; e < E; ++e) {
            cout << "Ребро " << e << " инцендентно к: ";
            int v1 = -1, v2 = -1;
            for (int v = 0; v < V; ++v) {
                if (incidenceMatrix[v][e] == 1) {
                    if (v1 == -1) {
                        v1 = v;
                    } else {
                        v2 = v;
                        break;
                    }
                }
            }
            cout << v1 << " " << v2 << endl;
        }
    }

    // Поиск в ширину и построение дерева поиска
    LinkedList BFS(int start, int numEdges) {
        // Инициализируем массив visited и очередь q
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        int *parent = new int[V];
        for (int i = 0; i < V; ++i) {
            parent[i] = -1;
        }
        Queue q;

        // Помечаем начальную вершину как посещенную и добавляем ее в очередь
        visited[start] = true;
        q.push(start);

//        std::pair<int, int>* treeEdges = new std::pair<int, int>[V - 1]; // Список ребер дерева поиска
        LinkedList treeEdges;


        // Пока очередь не пуста
        while (!q.empty()) {
            // Извлекаем вершину из очереди
            int current = q.getFront()->data;
            q.pop();

            // Для каждого ребра, инцидентного текущей вершине
            for (int e = 0; e < E; ++e) {
                if (incidenceMatrix[current][e] != 0) {
                    int neighbor = -1;
                    // Находим смежную вершину
                    for (int v = 0; v < V; ++v) {
                        if (incidenceMatrix[v][e] != 0 && v != current) {
                            neighbor = v;
                            break;
                        }
                    }
                    if (!visited[neighbor]) {
                        // Помечаем ее как посещенную, добавляем в очередь, добавляем ребро в список и устанавливаем родителя
                        visited[neighbor] = true;
                        q.push(neighbor);
                        treeEdges.append(current, neighbor);
                        parent[neighbor] = current;
                    }
                }
            }
        }

        return treeEdges;
    }
};

void fileOpen(string fileName, ifstream &f) {
    f.open(fileName);
}

Graph readFile(ifstream &f) {
    while (!f.eof()) {
        int V, E;
        f >> V;
        f >> E;
        Graph g(V, E);
        int v1, v2, e;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < E; j++) {
                f >> e;
                if (e == 1) {
                    if (v1 == 0) {
                        v1 = i + 1;
                    } else {
                        v2 = i + 1;
                        g.addEdge(v1, v2, j + 1);
                        v1 = 0;
                    }
                }
            }
        }

        f.close();
        return g;
    }
}