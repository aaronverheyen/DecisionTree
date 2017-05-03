#include "prototypes.h"


void parse(string& s, vector<vector<string> > &a)
{
	vector<string>  vectorOfStrings;

	while (s.length() != 0 && s.find(',') != string::npos)
	{
		size_t pos;
		string singleAttribute;
		pos = s.find_first_of(',');
		singleAttribute = s.substr(0, pos);
		vectorOfStrings.push_back(singleAttribute);
		s.erase(0, pos + 1);
	}

	
	a.push_back(vectorOfStrings);
	vectorOfStrings.push_back(s);
	vectorOfStrings.clear();
}




map<string, int> posibilities(vector<vector<string>> tabel, int kolom) {

	map<string, int> posibilitiesToAmount;

	for (unsigned i = 1; i < tabel.size(); i++) {

		if (posibilitiesToAmount.count(tabel.at(i).at(kolom)) != 0) {
			continue;
		}
		posibilitiesToAmount[tabel.at(i).at(kolom)];
	}

	return posibilitiesToAmount;
}


int gini_functie(vector<vector<string>> tabel) {

	double Si = 0;
	double breuk = 0;
	double gini = 0;
	double tussenhaakjes = 1;
	vector<double> breuk_vector;
	vector<double> gini_vector;
	vector<double> tussenhaakjes_vector;

	vector<string> gebruikt;
	string comparator;
	map<string, int> posibilitiesToAmount;

	posibilitiesToAmount = posibilities(tabel, tabel.at(0).size() - 1);

	for (unsigned j = 0; j < tabel.at(0).size() - 1; j++) { // slaat resultaten over

		for (unsigned k = 1; k < tabel.size(); k++) { //slaat bovenste rij over

			comparator = tabel.at(k).at(j);

			if (find(gebruikt.begin(), gebruikt.end(), comparator) != gebruikt.end()) { // kijkt op comparator reeds gebruikt is
				continue;
			}

			gebruikt.push_back(comparator);

			for (unsigned i = 1; i < tabel.size(); i++) {

				if (tabel.at(i).at(j) == comparator) {
					Si++;			// telt het aantal keer een specifiek woord voorkomt

					for (auto &ent1 : posibilitiesToAmount) {
						if (tabel.at(i).back() == ent1.first) {
							ent1.second++;
						}
					}

				}
			}


			for (auto &ent1 : posibilitiesToAmount) {
				tussenhaakjes = tussenhaakjes * ent1.second / Si;
				ent1.second = 0;
			}

			tussenhaakjes_vector.push_back(tussenhaakjes);

			breuk = breuk + Si / (tabel.size() - 1); //-1 : zonder bovenste rij      
			breuk_vector.push_back(breuk);

			breuk = 0;

			tussenhaakjes = 1;
			Si = 0;

		}

		for (unsigned i = 0; i < tussenhaakjes_vector.size(); i++) {
			gini = gini + breuk_vector.at(i)*tussenhaakjes_vector.at(i); // sommatie van alle "sub"-gini waardes
		}

		gini_vector.push_back(gini); // Maakt een lijst van alle gini waardes

		gini = 0;	//reset gini waarde voor volgende kolom	

		tussenhaakjes_vector.clear();	// reset alle vectors voor volgende kolom	
		gebruikt.clear();
		breuk_vector.clear();
	}


	//cout << tabel.at(0).at(distance(gini_vector.begin(), min_element(gini_vector.begin(), gini_vector.end()))) << endl;

	return distance(gini_vector.begin(), min_element(gini_vector.begin(), gini_vector.end()));

}

map<vector<vector<string>>, string> split_table(vector<vector<string> > tabel) {
	int kolom;
	vector<string> start;
	//vector<vector<vector<string>>> tabellen;
	vector<vector<string>> temp_tabel;
	//vector<string> mogelijke_resultaten;
	map<string, int> mogelijkheden;
	map<vector<vector<string>>, string> out;

	kolom = gini_functie(tabel);



	mogelijkheden = posibilities(tabel, kolom);

	for (auto &ent1 : mogelijkheden) {

		temp_tabel.push_back(start);

		for (unsigned i = 0; i < tabel.at(0).size(); i++) {
			temp_tabel.at(0).push_back(tabel.at(0).at(i));
		}


		for (unsigned j = 1; j < tabel.size(); j++) {
			if (tabel.at(j).at(kolom) == ent1.first) {
				temp_tabel.push_back(tabel.at(j));
			}
		}

		for (unsigned i = 0; i < temp_tabel.size(); i++) {
			temp_tabel.at(i).erase(temp_tabel.at(i).begin() + kolom);
		}

		out.insert({ temp_tabel, tabel.at(0).at(kolom) + ": " + ent1.first });
		temp_tabel.clear();

	}
	return out;
}


bool uniform(vector<vector<string>> tabel) {
	for (unsigned i = 1; i, i < tabel.size(); i++) {
		if (tabel.at(1).back() != tabel.at(i).back()) {
			return false;
		}
	}
	return true;
}

//Code Stef (werking) en Aäron (lay-out)
void basicPrint(vector<vector<string> > tabel) {


	for (unsigned i = 0; i < tabel.size(); i++) {

		for (unsigned j = 0; j < tabel.at(0).size(); j++) {

			if (j == tabel.at(0).size() - 1) {
				cout << "|";
			}
			
			cout << setw(15) << tabel.at(i).at(j) << " ";

		}
		cout << endl;
		if (i == 0) {
			for (unsigned k = 0; k < tabel.at(0).size(); k++) {
				cout << "_________________";
			}
			cout << endl;
		}
	}
	cout << endl;
}
//Code Stef(basiswerking) en Aäron (recursie)
void processMap(map<vector<vector<string>>, string> inputTable) {
	
	list<string> nodeChildren;
	int i = 0;
	for (auto &ent1 : inputTable) {
		uniform(ent1.first);			//returnt boolean om aan te geven of de deeltabel uniform is of niet
		cout << ent1.second << endl;
		nodeChildren.push_back(ent1.second);
		cout << endl;
		basicPrint(ent1.first);
		cout << endl;
		if (!uniform(ent1.first) && (ent1.first.at(0).size()>2)) { //Controleert of de tabel al dan niet uniform is en verhindert dat een niet-deelbare tabel nog verder wordt opgesplitst
			
				processMap(split_table(ent1.first));
			
		}

	}
	//makeTree();
}

