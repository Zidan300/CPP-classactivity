#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

/**
 * @class GraphMatrix
 * @brief Represents a graph using a 2D adjacency matrix.
 * 
 * This class supports both directed/undirected and weighted/unweighted graphs.
 * It uses a 2D vector to store edge weights or binary connectivity.
 */
class GraphMatrix {
private:
    int num_vertices;
    bool directed;
    bool weighted;
    std::vector<std::vector<int>> matrix;

public:
    /**
     * @brief Constructor for GraphMatrix.
     * @param vertices Number of vertices in the graph.
     * @param is_directed True if the graph is directed, false otherwise.
     * @param is_weighted True if the graph is weighted, false otherwise.
     */
    GraphMatrix(int vertices, bool is_directed, bool is_weighted) 
        : num_vertices(vertices), directed(is_directed), weighted(is_weighted) {
        // Initialize the matrix with 0s. 
        // For unweighted graphs, 1 represents an edge, 0 represents no edge.
        // For weighted graphs, the value is the weight, 0 represents no edge.
        matrix.resize(num_vertices, std::vector<int>(num_vertices, 0));
    }

    /**
     * @brief Adds an edge between vertex u and vertex v.
     * @param u Source vertex (0-indexed).
     * @param v Destination vertex (0-indexed).
     * @param weight Weight of the edge (default is 1 for unweighted graphs).
     */
    void add_edge(int u, int v, int weight = 1) {
        // Basic bounds checking
        if (u < 0 || u >= num_vertices || v < 0 || v >= num_vertices) {
            std::cerr << "Error: Vertex index out of bounds (" << u << ", " << v << ")\n";
            return;
        }

        // If not weighted, we ignore the weight parameter and use 1
        int actual_weight = weighted ? weight : 1;

        matrix[u][v] = actual_weight;

        // If undirected, add the symmetric edge
        if (!directed) {
            matrix[v][u] = actual_weight;
        }
    }

    /**
     * @brief Prints the adjacency matrix with formatting.
     * @param label A string to describe the graph being printed.
     */
    void print_matrix(const std::string& label) const {
        std::cout << "\n--- " << label << " ---\n";
        std::cout << "Type: " << (directed ? "Directed" : "Undirected") 
                  << ", " << (weighted ? "Weighted" : "Unweighted") << "\n\n";

        // Print column headers
        std::cout << "    ";
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << std::setw(3) << i << " ";
        }
        std::cout << "\n    " << std::string(num_vertices * 4, '-') << "\n";

        // Print matrix rows
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << std::setw(2) << i << " |";
            for (int j = 0; j < num_vertices; ++j) {
                std::cout << std::setw(3) << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

/**
 * @brief Demonstrates the four types of graphs.
 */
int main() {
    int vertices = 5;

    // 1. Undirected & Unweighted
    // Edges: (0-1), (0-4), (1-2), (1-3), (1-4), (2-3), (3-4)
    GraphMatrix g1(vertices, false, false);
    g1.add_edge(0, 1);
    g1.add_edge(0, 4);
    g1.add_edge(1, 2);
    g1.add_edge(1, 3);
    g1.add_edge(1, 4);
    g1.add_edge(2, 3);
    g1.add_edge(3, 4);
    g1.print_matrix("Graph 1: Undirected & Unweighted");

    // 2. Directed & Unweighted
    // Edges: 0->1, 1->2, 2->3, 3->4, 4->0, 1->4
    GraphMatrix g2(vertices, true, false);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    g2.add_edge(2, 3);
    g2.add_edge(3, 4);
    g2.add_edge(4, 0);
    g2.add_edge(1, 4);
    g2.print_matrix("Graph 2: Directed & Unweighted");

    // 3. Undirected & Weighted
    // Edges: (0-1, w:5), (0-4, w:10), (1-2, w:2), (1-3, w:15), (3-4, w:7)
    GraphMatrix g3(vertices, false, true);
    g3.add_edge(0, 1, 5);
    g3.add_edge(0, 4, 10);
    g3.add_edge(1, 2, 2);
    g3.add_edge(1, 3, 15);
    g3.add_edge(3, 4, 7);
    g3.print_matrix("Graph 3: Undirected & Weighted");

    // 4. Directed & Weighted
    // Edges: 0->1 (8), 0->2 (3), 1->2 (4), 2->3 (12), 3->4 (6), 4->0 (1)
    GraphMatrix g4(vertices, true, true);
    g4.add_edge(0, 1, 8);
    g4.add_edge(0, 2, 3);
    g4.add_edge(1, 2, 4);
    g4.add_edge(2, 3, 12);
    g4.add_edge(3, 4, 6);
    g4.add_edge(4, 0, 1);
    g4.print_matrix("Graph 4: Directed & Weighted");

    return 0;
}
