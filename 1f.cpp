#include <iostream>

using namespace std;

const int MAX_CITIES = 100; // Maximum number of cities

class FlightManagementSystem {
private:
    string cityIndex[MAX_CITIES]; // Array to map city indices to names
    int nextIndex = 0;

    int adjacencyMatrix[MAX_CITIES][MAX_CITIES] = {0};
    struct Node {
        int destination;
        int cost;
        Node* next;
    };
    Node* adjacencyList[MAX_CITIES] = {nullptr};

public:
    void addFlight(string source, string destination, int cost) {
        int sourceIndex = getCityIndex(source);
        int destinationIndex = getCityIndex(destination);

        // Update adjacency matrix
        adjacencyMatrix[sourceIndex][destinationIndex] = cost;

        // Update adjacency list
        Node* newNode = new Node{destinationIndex, cost, adjacencyList[sourceIndex]};
        adjacencyList[sourceIndex] = newNode;
    }

    bool areCitiesConnected(string source, string destination) {
        int sourceIndex = getCityIndex(source);
        int destinationIndex = getCityIndex(destination);

        // Check adjacency matrix
        if (adjacencyMatrix[sourceIndex][destinationIndex] > 0) {
            cout << "Cities are connected via flight.\n";
            return true;
        } else {
            cout << "Cities are not connected via flight.\n";
            return false;
        }
    }

    void printAdjacencyMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < nextIndex; ++i) {
            for (int j = 0; j < nextIndex; ++j) {
                cout << adjacencyMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void printAdjacencyList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < nextIndex; ++i) {
            cout << i << " -> ";
            Node* current = adjacencyList[i];
            while (current) {
                cout << "(" << current->destination << ", " << current->cost << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }

private:
    int getCityIndex(string city) {
        // Find the index of the city, or add it if not found
        for (int i = 0; i < nextIndex; ++i) {
            if (cityIndex[i] == city) {
                return i;
            }
        }

        // City not found, add it to the array
        cityIndex[nextIndex] = city;
        return nextIndex++;
    }
};

int main() {
    FlightManagementSystem flightSystem;

    int choice;
    do {
        cout << "\nFlight Management System Menu:\n";
        cout << "1. Add Flight\n";
        cout << "2. Check Cities Connection\n";
        cout << "3. Print Adjacency Matrix\n";
        cout << "4. Print Adjacency List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string source, destination;
                int cost;
                cout << "Enter source city: ";
                cin >> source;
                cout << "Enter destination city: ";
                cin >> destination;
                cout << "Enter flight cost: ";
                cin >> cost;
                flightSystem.addFlight(source, destination, cost);
                break;
            }
            case 2: {
                string source, destination;
                cout << "Enter source city: ";
                cin >> source;
                cout << "Enter destination city: ";
                cin >> destination;
                flightSystem.areCitiesConnected(source, destination);
                break;
            }
            case 3:
                flightSystem.printAdjacencyMatrix();
                break;
            case 4:
                flightSystem.printAdjacencyList();
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
