#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for an item with a value and weight
struct Item {
    int value, weight;
    
    // Constructor to initialize the item
    Item(int v, int w){
        value=v;
        weight=w;
    }
};

// Comparison function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items based on the value-to-weight ratio
    sort(items.begin(), items.end(), compare);
    
    double maxValue = 0.0;
    
    // Loop through each item
    for (Item& item : items) {
        if (W == 0) break; // If knapsack is full, break
        
        // Check if the item can be fully added
        if (item.weight <= W) {
            W -= item.weight;
            maxValue += item.value;
        } else {
            
            // Add a fraction of the item
            maxValue += item.value * ((double)W / item.weight);
            W = 0; // Knapsack is full
        }
    }
    
    return maxValue;
}

int main() {
    int W = 50; // Knapsack capacity
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} }; // {value, weight}

    double maxValue = fractionalKnapsack(W, items);
    
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}