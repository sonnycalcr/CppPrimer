#include <map>
#include <string>
#include <cstddef>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word)
        ++word_count[word];          // fetch and increment the counter for word
    for (const auto &w : word_count) // for each element in the map
        // print the results
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
