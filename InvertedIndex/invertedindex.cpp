#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>
#include<iterator>
#include<fstream>

using namespace std;

map <string, vector < pair <int,int> > > mymap;
map <string, int> stoplistmap;
map <string, int>::iterator p1;
map <string, vector < pair <int,int> > >::iterator it;
pair<int, int> p;

void computestoplistmap() {

	ifstream infile; string line;
	
	string filename="stoplist.txt";
   	infile.open(filename.c_str()); 

	
   	//while (getline(infile, line)) {
	while (!infile.eof()) {

		infile >> line; 

		stoplistmap.insert(pair<string, int>(line,1));

	}

	/*for (p1 = stoplistmap.begin(); p1 != stoplistmap.end();p1++) {
		cout << p1->first << "-->" << p1->second << endl;
		
	}*/

	infile.close();
}


bool checkexists(string element) {

	if (stoplistmap.find(element) != stoplistmap.end()) { // found
		 return true;
	}	
	else { // not found
		return false;	
	}
}

void computemap(string str,int index) {

	transform(str.begin(), str.end(), str.begin(), ::tolower); // convert to lower case	

	istringstream in(str);
	vector<string> vec = vector<string>(istream_iterator<string>(in), istream_iterator<string>());
	for (int i = 0; i < vec.size(); i++) {

		if (!checkexists(vec[i])) {		
			
		if ( mymap.find(vec[i]) == mymap.end() ) {
  		// not found

			p.first =index;
			p.second = i;

			mymap[vec[i]].push_back(p);

			//mymap.insert(pair<char, int>(str[i],1));

		} else {
	  	// found
			p.first =index;
			p.second = i;
			mymap[vec[i]].push_back(p);
		}
		}
	}
}

void displayinverted() {

	for (it = mymap.begin(); it != mymap.end();it++) {
		cout << it->first << " ";
		
		for (int i = 0; i < (it->second).size(); i++) {
			cout << "(" << it->second[i].first << " " << it->second[i].second << ")" << " ";		
		}
	cout << endl;	
	}

}

void displayrecordlevel() {

	for (it = mymap.begin(); it != mymap.end();it++) {
		cout << it->first << " ";
		
		cout << "{" << " ";
		for (int i = 0; i < (it->second).size(); i++) {
			cout  << it->second[i].first << " ";		
		}
	cout << "}";
	cout << endl;	
	}


}

int main() {

	//string arr[3] = {"Turtles love pizza","I love my turtles","My pizza is good"};

	string str;

	computestoplistmap();

	string arr[20] = {"file01.txt","file02.txt","file03.txt","file04.txt","file05.txt","file06.txt","file07.txt","file08.txt",
	"file09.txt","file10.txt","file11.txt","file12.txt","file13.txt","file14.txt","file15.txt","file16.txt","file17.txt","file18.txt"
	"file19.txt","file20.txt"};

	for (int i = 0; i < 20;i++) {
	ifstream infile(arr[i].c_str());
	
	stringstream buffer;
	buffer << infile.rdbuf();
	str = buffer.str();

	computemap(str,i);

	infile.close();
	}

		

	cout << "Full Inverted" << endl;
	displayinverted();
	cout << "*********" << endl;
	cout << "Record Level" << endl;
	displayrecordlevel();
}


