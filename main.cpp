
#include <iostream>
#include <vector>
using namespace std;

/*
 Data Structures - IA-3 Question 2
 PRN: 202501100185
 Seed: 185
 Scenario: Mango Varieties
 Hash Function: Mid-Square Method
 Collision Handling: Separate Chaining
 Table Size: 23
*/

const int SEED = 185;
const int SIZE = 23;
const int TOTAL = 20;

class HashTable {
private:
    vector<int> table[SIZE];

public:
    // Mid-square hash function
    int hashFunction(int key) {
        int square = key * key;
        int middle = (square / 10) % 100;
        return middle % SIZE;
    }

    // Insert using separate chaining
    void insert(int key) {
        int index = hashFunction(key);

        if (!table[index].empty()) {
            cout << "Collision for " << key
                 << " at index " << index << endl;
        }

        table[index].push_back(key);

        cout << "Inserted " << key
             << " at index " << index << endl;
    }

    // Search for a value
    bool search(int key) {
        int index = hashFunction(key);

        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    // Display hash table
    void display() {
        cout << "\nFinal Hash Table:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (int value : table[i]) {
                    cout << value << " -> ";
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int values[TOTAL];

    cout << "IA-3 Question 2\n";
    cout << "PRN: 202501100185\n";
    cout << "Scenario: Mango Varieties\n";
    cout << "Hash: Mid-Square Method\n";
    cout << "Collision: Separate Chaining\n";

    cout << "\nGenerated Dataset:\n";

    for (int i = 0; i < TOTAL; i++) {
        values[i] = (SEED + 13 * i) % 100;
        cout << values[i] << " ";
    }

    cout << "\n\nInsertion Process:\n";

    for (int i = 0; i < TOTAL; i++) {
        ht.insert(values[i]);
    }

    ht.display();

    int key = values[5];

    cout << "\nSearching for " << key << endl;

    if (ht.search(key)) {
        cout << "Value Found!" << endl;
    } else {
        cout << "Value Not Found!" << endl;
    }

    return 0;
}
