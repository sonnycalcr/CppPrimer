#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class QueryResult; // declaration needed for return type in the query function
class TextQuery {
  public:
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string &) const;

  private:
    shared_ptr<vector<string>> file; // input file
    // map of each word to the set of the lines in which that word appears
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {   // for each line in the file
        file->push_back(text);    // remember this line of text
        int n = file->size() - 1; // the current line number
        istringstream line(text); // seperate the line into words
        string word;
        while (line >> word) { // for each word in that line
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word];            // lines is a shared_ptr
            if (!lines)                        // that pointer is null the first time we see wrod
                lines.reset(new set<line_no>); // allocate a new set
            lines->insert(n);                  // insert this line number
        }
    }
}

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);

  public:
    using line_no = TextQuery::line_no;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {}

  private:
    std::string sought;                             // word this query represents
    std::shared_ptr<std::set<line_no>> lines;       // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
};
