#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

// DFS Traversal
void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS Traversal
void BFS(int start)
{
    int q[10], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int v = q[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int choice, start;

    cout << "Enter number of vertices (max 10): ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    do
    {
        cout << "\n\n1. DFS";
        cout << "\n2. BFS";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
                visited[i] = 0;

            cout << "DFS Traversal: ";
            DFS(start);
            cout << endl;
            break;

        case 2:
            cout << "BFS Traversal: ";
            BFS(start);
            cout << endl;
            break;

        case 3:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice.";
        }

    } while (choice != 3);

    return 0;
}