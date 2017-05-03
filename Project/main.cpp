#include "prototypes.h"
//#include "prototypes2.h"

int main(int argc, const char *argv[])
{
	ifstream input;				    // Input file stream
	string rij;                     // Single line read from the input file
	vector<vector<string> > tabel;	// Input data in the form of a vector of vector of strings
	map<vector<vector<string>>, string>  test;
	//Tree<map<vector<vector<string>>, string>> tree;
	
		

	input.open("../train.dat");

	if (!input)
	{
		cerr << "File not found!" << endl;
		exit(-1);
	}

	while (getline(input, rij))	// Read from file, parse and store data
	{
		parse(rij, tabel);      // Last column is class (studeert of studeert niet))
	}

	input.close(); 			 // Close input file

	//Code Stef
	/*for (unsigned i = 0; i < tabel.size(); i++) {
		for (unsigned j = 0; j <tabel.at(0).size(); j++) {

			cout << tabel.at(i).at(j) << " ";

		}
		cout << endl;
	}*/
	cout << "This is your input\n\n";
	
	basicPrint(tabel);		//Toont de inputtabel

	cout << "====================================================================================" << endl << endl << "Starting the program..." << endl << endl << "====================================================================================" << endl << endl;
	
	test = split_table(tabel);
	processMap(test);

	cout << "End of program." << endl << endl << "====================================================================================";

	cin.get();

	return 0;










}
