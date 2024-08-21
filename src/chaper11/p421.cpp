#include <map>
#include <string>
#include <cstddef>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    string relativePathToCurrentCppFile = "../../data/chapter11/p421.txt";
    // cause we execute the binary file in root dir
    ifstream inputFile(relativePathToCurrentCppFile.substr(4, relativePathToCurrentCppFile.size()));
    if (!inputFile.is_open()) {
        cerr << "Failed to open input data file." << endl;
        return 2;
    }

    //
    // core codes begins
    //
    streambuf *cinbuf = cin.rdbuf(); // save original buf
    cin.rdbuf(inputFile.rdbuf());

    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word)
        ++word_count[word];          // fetch and increment the counter for word
    for (const auto &w : word_count) // for each element in the map
        // print the results
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    //
    // core codes ends here
    //

    // resume the original cin buf
    cin.rdbuf(cinbuf);
    return 0;
}
