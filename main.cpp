#include <iostream>
#include <array>

using namespace std;

// Define physical data variables
const double L = 1.0;   // Length of the channel
const double H = 1.0;   // Width of the channel
const double D = 1.0;   // Number of cells in the channel
const double vin = 1.0; // Inlet velocity
const double rho = 1.0; // Density of the fluid

// Define numerical data variables
const int N = 100;            // Number of horizontal cells in the channel
const int M = 100;            // Number of vertical cells in the channel
const double error = 0.01;    // Error tolerance
const double psi_start = 0.0; // Initial value of psi

// Define the Node class
class Node
{
public:
    bool is_boundary; // True if the node is a boundary node
    bool is_fluid;    // True if the node is a fluid node
    double x;
    double y;
    double psi;
    double u;
    double v;
    double p;
    double rhs;
    double ap;
    double aw;
    double ae;
    double as;
    double an;
    double b;
};

//  Define the Mesh class
template <class T, size_t rows, size_t cols>
class Matrix
{
    std::array<T, rows * cols> m_Data;

public:
    T &operator()(size_t y, size_t x)
    {
        return m_Data[y * cols + x];
    }
};

// Main function
int main()
{

    cout << "Hola";

    // Defining mesh matrix
    Matrix<Node, N, M> mesh;

    // Mesh dimensions
    double dx = L / (N - 1);
    double dy = H / (M - 1);

    // FIlling mesh with nodes
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < M; j++)
        {
            mesh(i, j) = Node();
            mesh(i, j).x = dx * (0.5 + i);
            mesh(i, j).y = dy * (0.5 + j);
        }
    }

    // Plotting mesh
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mesh(i, j).x << " " << mesh(i, j).y << "\n";
        }
    }

    return 0;
};
