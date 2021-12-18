#include<bits/stdc++.h>
using namespace std;

class SORTracker {
public:
    set<pair<int, string>> places;
    set<pair<int, string>>::iterator it = places.end();

    void add(string name, int score) {
        auto it1 = places.insert({ -1 * score,name }).first;

        if (it == end(places) || *it1 < *it) --it;
    }

    string get() {
        return (it++)->second;
    }
};

int main() {
    SORTracker tracker; // Initialize the tracker system.
    tracker.add("bradford", 2); // Add location with name="bradford" and score=2 to the system.
    tracker.add("branford", 3); // Add location with name="branford" and score=3 to the system.
    cout << tracker.get() << endl;             // The sorted locations, from best to worst, are: branford, bradford.
                                // Note that branford precedes bradford due to its higher score (3 > 2).
                                // This is the 1st time get() is called, so return the best location: "branford".
    tracker.add("alps", 2);     // Add location with name="alps" and score=2 to the system.
    cout << tracker.get() << endl;                // Sorted locations: branford, alps, bradford.
                                // Note that alps precedes bradford even though they have the same score (2).
                                // This is because "alps" is lexicographically smaller than "bradford".
                                // Return the 2nd best location "alps", as it is the 2nd time get() is called.
    tracker.add("orland", 2);   // Add location with name="orland" and score=2 to the system.
    cout << tracker.get() << endl;                // Sorted locations: branford, alps, bradford, orland.
                                // Return "bradford", as it is the 3rd time get() is called.
    tracker.add("orlando", 3);  // Add location with name="orlando" and score=3 to the system.
    cout << tracker.get() << endl;                // Sorted locations: branford, orlando, alps, bradford, orland.
                                // Return "bradford".
    tracker.add("alpine", 2);   // Add location with name="alpine" and score=2 to the system.
    cout << tracker.get() << endl;                // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                                // Return "bradford".
    cout << tracker.get() << endl;                // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                                // Return "orland".

    return 0;
}