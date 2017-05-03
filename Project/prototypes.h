#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <math.h>
#include <float.h>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

void parse(string&, vector<vector<string> >&);				// Parses a single line from the input file and stores the information into a vector of vector of strings
int gini_functie(vector<vector<string> > tabel);
map<vector<vector<string>>, string> split_table(vector<vector<string> > tabel);
bool uniform(vector < vector<string>>);
void basicPrint(vector<vector<string> >);
map<string, int> posibilities(vector<vector<string>> tabel, int kolom);
void processMap(map<vector<vector<string>>, string> inputTable);

