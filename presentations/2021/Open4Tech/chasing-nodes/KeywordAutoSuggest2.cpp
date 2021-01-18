#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

#define TUPLE_SEP   " "

// BinaryPredicate for sorting keyword tuples by frequency
// (lexicographical compare - by parts)
struct CompareKeywordTupleCount
{
  template<typename Iter>
  bool operator()(Iter i, Iter j) const // applied on KeywordTupleCounts iterators
  {
    // compare by frequency (count)
    if ( i->second > j->second ) return true;
    if ( j->second > i->second ) return false;
    // compare by keyword tuple string (when the count is equal)
    return i->first > j->first;
  }
};

// a keyword tuple is stored as a concatenated string "keyword1 keyword2"
using KeywordTupleCounts = unordered_map<string, size_t>;

// Input: "keywords.db" - 136 MB (143,157,546 bytes)
//   unique keywords = 292,191
//   keyword tuples = 4,967,228
// 
// Input: "keywords-big.db" - 478 MB (501,343,506 bytes)
//   unique keywords = 655,932
//   keyword tuples = 12,923,972
int main(int argc, char ** argv) 
{
  if (argc < 2)
  {
    cerr << "No keyword database specified as argument !" << endl;
    return 1;
  }

  const char * dbPath = argv[1];
  bool searchMode = (argc > 2) && string(argv[2]) == "/search"; 

  cout << "Loading keyword database: \"" << dbPath << "\"" << endl;
  
  ifstream inFile(dbPath, ios_base::in);
  if ( !inFile.is_open() )
  {
    cerr << "Failed to open keywords database !" << endl;
    return 1;
  }

  KeywordTupleCounts tupleCounts;

  string prevWord;
  string word;
  while ( inFile >> word ) // read each keyword until EOF
  {
    // increment frequency for this keyword tuple: {prevWordIt, currWordIt}
    if ( !prevWord.empty() )
      ++tupleCounts[ prevWord + TUPLE_SEP + word ];

    prevWord = word;
  }
  
  cout << "Keyword database loaded successfully (keyword tuples: " << tupleCounts.size() << ")." << endl;
  cout << "Ranking keyword database..." << endl;

  vector<KeywordTupleCounts::const_iterator> topKeywordTuples;
  topKeywordTuples.reserve( tupleCounts.size() );
  for (auto it = begin(tupleCounts), endIt = end(tupleCounts); it != endIt; ++it)
    topKeywordTuples.push_back(it);

  // sort keyword tuples by frequency, using our defined custom predicate
//std::sort( begin(topKeywordTuples), end(topKeywordTuples), CompareKeywordTupleCount() );
  std::sort( begin(topKeywordTuples), end(topKeywordTuples), 
             [](const auto & i, const auto & j) { return i->second > j->second; } );

  ofstream outFile("top1000.out", ios_base::out);
  
  int cnt = 1000;
  for ( auto it = begin(topKeywordTuples), endIt = end(topKeywordTuples); it != endIt && cnt > 0; ++it, --cnt )
    outFile << (*it)->first << " # " << (*it)->second << "\n";
  
  if (!searchMode)
    return 0;
  
  cout << "Keyword database ready for query." << endl;

  while ( !cin.eof() )
  {
    cout << "------------------------------------------------" << endl;
    cout << "Search keyword: ";
    string inputKeyword;
    cin >> inputKeyword;
    cout << "Suggested searches for keyword: \"" << inputKeyword << "\"" << endl;

    // auto-suggest related searches based on top search phrases containing the input keyword
    int matchCount = 10;
    for ( auto it = begin(topKeywordTuples), endIt = end(topKeywordTuples); it != endIt && matchCount > 0; ++it )
    {
      const string & tuple = (*it)->first;

      size_t sep = tuple.find(TUPLE_SEP);
      if ( tuple.compare(0, sep, inputKeyword) == 0 ||
           tuple.compare(sep + 1, tuple.size(), inputKeyword) == 0 )
      {
        cout << "   -> " << tuple << " # " << (*it)->second << "\n";
        --matchCount;
      }
    }
  }

  return 0;
}
