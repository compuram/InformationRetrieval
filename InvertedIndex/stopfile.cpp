#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

int main() {

   ifstream infile; string str;
   cout << "Reading from the file" << endl; 
   infile.open("stoplist.txt"); 

   while (getline(infile, str)) {

	cout << str << endl;

}	   


	
   /*getline(infile, data);
   cout << data << endl; 
   getline(infile, data);
   cout << data << endl; */
   infile.close();
   return 0;

}
