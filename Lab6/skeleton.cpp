#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

void printSetUsingIterator(const set<string>& s) {
   // TODO: Print a set of string using iterator
	cout<<"{";
	for (set<string>::iterator p = s.begin(); p != s.end(); p++)
	{
		cout<<*p<<",";
	}
	cout<<"}"<<endl;
}

void printListUsingIterator(const list<string>& s) {
   // TODO: Print a list of string using iterator
	cout<<"{";
	for (list<string>::const_iterator p = s.begin(); p != s.end(); p++) //set is const
	{
		cout<<*p<<",";
	}
	cout<<"}"<<endl;
}

void printMapUsingIterator(const map<string,int>& s) {
   // TODO: Print a map using iterator
	for (map<string,int>::const_iterator p = s.begin(); p != s.end(); p++)
	{
		cout<<"key: "<<p->first<<"    Value: "<<p->second<<endl;
	}
}


//TODO: You may need to define a comparator function yourself here (for the sorting task)
bool name_len (const std::string& first, const std::string& second)
{
  return ( first.length() < second.length() );
}

int main() {

	cout << endl;
	cout << "************************** Part1: set **************************";
	cout << endl;

	set<string> Fictions, Movies;
	Fictions.insert("The Time Machine");
	Fictions.insert("Harry Potter");
	Fictions.insert("The Lord of the Rings");

	Movies.insert("The Shawshank Redemption");
	Movies.insert("City of God");
	Movies.insert("The Lord of the Rings");
	Movies.insert("Harry Potter");

	cout << "Set Fictions Content =" ;
	printSetUsingIterator(Fictions);
	cout << "Set Movies Content =" ;
	printSetUsingIterator(Movies);

    // Part 1 TODO: Complete the set operations: intersection
	set<string> interSet;

   // ADD YOUR CODE HERE
	for(set<string>::iterator i = Fictions.begin(); i != Fictions.end(); i++)
		for(set<string>::iterator j = Movies.begin(); j != Movies.end(); j++)
		{
			if (*j == *i) interSet.insert(*i);
		}

   cout << "Fictions intersect Movies Content = ";
   printSetUsingIterator(interSet);

   cout << endl;
	cout << "************************** Part2: list **************************";
   cout << endl;

	// Merge Fictions and Movies to listR
	list<string> listR ;
   
   // Part 2 TODO: Merge Fictions and Movies to listR
   // ADD YOUR CODE HERE
	for(set<string>::iterator i = Fictions.begin(); i != Fictions.end(); i++)
		listR.push_front(*i);
	for(set<string>::iterator j = Movies.begin(); j != Movies.end(); j++)
		listR.push_front(*j);
	listR.sort();

	cout << "List R Content = ";
	printListUsingIterator(listR);

	// Part 2 TODO: 
    //Add a new string "Saw" at the end of the list
    //Add a new string "Avenger" at the head of the list
    // ADD YOUR CODE HERE
	listR.push_front("Avenger");
	listR.push_back("Saw");


	cout << "New R Content = ";
	printListUsingIterator(listR);

	 // Sort listR by movie name length ascendingly
    // ADD YOUR CODE HERE
    listR.sort(name_len);

	cout << "Sorted R Content = ";
	printListUsingIterator(listR);

   cout << endl;
	cout << "************************** Part3: map **************************";
   cout << endl;

    //map
	map<string,int> mapMovie;
	mapMovie.insert(make_pair("The Shawshank Redemption",1994));
	mapMovie.insert(make_pair("City of God",2002));
	mapMovie.insert(make_pair("The Lord of the Rings", 2002));
	mapMovie.insert(make_pair("Star Wars", 1977));
	mapMovie.insert(make_pair("Forest Gump", 1994));
	cout << "mapMovie Content: "<<endl;
	printMapUsingIterator(mapMovie);

   //Part3 TODO : Complete element search and deletion in mapMovie here
    // search "Star Wars" in map
    // ADD YOUR CODE HERE
    for (map<string,int>::const_iterator p = mapMovie.begin(); p != mapMovie.end(); p++)
    {
    	if (p->first == "Star Wars")
    		cout<<"Key found, the value is "<< p->second<<endl;
    }


    // delete "City of God" in map
    // ADD YOUR CODE HERE
    mapMovie.erase("City of God");

	cout << "mapMovie Content after deletion: "<<endl;
	printMapUsingIterator(mapMovie);



	return 0;
}
