#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    string category;
};

int main() {
    vector<Item> items = {
        {"The Alchemist", "Book"},
        {"Harry Potter", "Book"},
        {"Inception", "Movie"},
        {"Interstellar", "Movie"},
        {"Laptop", "Technology"},
        {"Smartphone", "Technology"},
        {"Football", "Sports"},
        {"Cricket Bat", "Sports"}
    };

    string preference;

    cout << "=================================\n";
    cout << "      Recommendation System\n";
    cout << "=================================\n";

    cout << "Available Categories:\n";
    cout << "Book\nMovie\nTechnology\nSports\n";

    cout << "\nEnter your favorite category: ";
    cin >> preference;

    cout << "\nRecommended Items:\n";

    bool found = false;

    for (int i = 0; i < items.size(); i++) {
        if (items[i].category == preference) {
            cout << "- " << items[i].name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No recommendations found for this category." << endl;
    }

    return 0;
}