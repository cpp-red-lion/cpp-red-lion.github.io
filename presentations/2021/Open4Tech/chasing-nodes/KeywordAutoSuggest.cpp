#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

// stores unique keywords from input source
using KeywordSet = unordered_set<string>;

// a search phrase is composed of a pair/tuple of keywords (from our set)
struct KeywordTuple
{
  KeywordSet::const_iterator firstWord;
  KeywordSet::const_iterator secondWord;
  
  // BinaryPredicate for sorting keyword tuples lexicographically
  friend bool operator< (const KeywordTuple & kt1, const KeywordTuple & kt2)
  {
    // compare by first keyword
    if ( *kt1.firstWord < *kt2.firstWord ) return true;
    if ( *kt2.firstWord < *kt1.firstWord ) return false;
    // compare by second keyword
    return *kt1.secondWord < *kt2.secondWord;
  }

  friend bool operator> (const KeywordTuple & kt1, const KeywordTuple & kt2)
  {
    return ! operator< (kt1, kt2);
  }
};

// stores unique keyword tuples and their frequency (count)
using KeywordTupleCounts = map<KeywordTuple, size_t>;

// BinaryPredicate for sorting keyword tuples by frequency
struct CompareKeywordTupleCount
{
  template<typename Iter>
  bool operator()(Iter i, Iter j) const // applied on KeywordTupleCounts iterators
  {
    // compare by frequency (count)
    if ( i->second > j->second ) return true;
    if ( j->second > i->second ) return false;
    // compare by keyword tuple (when the count is equal)
    return i->first > j->first; // KeywordTuple::operator >
  }
};

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

  // stores unique keywords from input source
  KeywordSet keywords;

  // stores unique keyword tuples and their frequency
  KeywordTupleCounts tupleCounts;

  auto prevWordIt = end(keywords); // initially invalid
  string word;
  while ( inFile >> word ) // read each keyword until EOF
  {
    // insert/retrieve current word to/from our keyword set
    auto currWordIt = keywords.insert(word).first;

    // increment frequency for this keyword tuple: {prevWordIt, currWordIt}
    if ( prevWordIt != end(keywords) )
      ++tupleCounts[ {prevWordIt, currWordIt} ];

    prevWordIt = currWordIt; // update previous iterator
  }
  
  cout << "Keyword database loaded successfully (unique keywords: " << keywords.size() 
    << " -> keyword tuples: " << tupleCounts.size() << ")." << endl;
  cout << "Ranking keyword database..." << endl;

  // sort keyword tuples by frequency, using our defined custom predicate
  set<KeywordTupleCounts::const_iterator, CompareKeywordTupleCount> topKeywordTuples;
  for ( auto it = begin(tupleCounts), endIt = end(tupleCounts); it != endIt; ++it )
    topKeywordTuples.insert(it);

  ofstream outFile("top1000.out", ios_base::out);

  int cnt = 1000;
  for ( auto it = begin(topKeywordTuples), endIt = end(topKeywordTuples); it != endIt && cnt > 0; ++it, --cnt )
  {
    const auto & tuple = (*it)->first;
    outFile << *tuple.firstWord << " " << *tuple.secondWord << " # " << (*it)->second << "\n";
  }

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
      const auto & tuple = (*it)->first;

      if ( *tuple.firstWord == inputKeyword || *tuple.secondWord == inputKeyword )
      {
        cout << "   -> " << *tuple.firstWord << " " << *tuple.secondWord << " # " << (*it)->second << "\n";
        --matchCount;
      }
    }
  }

  return 0;
}
