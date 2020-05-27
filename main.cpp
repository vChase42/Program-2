// main.cpp
// Andy Wu, Chase Alcorn
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
#include "movies.h"

#include "utility.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);
double findMedian(vector<int>);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << " arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag;
  flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
    
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  

  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file

  BST list;
  // Read each file and store the name and rating
  
 // ofstream dataFile ("Data.txt");
  //if(dataFile.fail()){
  //  cerr << "failed to open data file";
  //  exit(1);
  //}
  
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
      list.insert(movieName, movieRating);

      //creates a file Data.txt and places 
      //Node* P = list.getNodeFor(movieName);
      //dataFile << list.size() << " "<< P->depth << endl;

    // Use std::string movieName and double movieRating
    // to construct your Movie objects
  }
  //dataFile.close();
  movieFile.close();



  if(strcmp(argv[1], "true") == 0){
    list.printPreOrder();
    cout << endl;
    Node* movieNode = list.searchPrefix(argv[3]);
    cout << "Best movie is " << movieNode->movie_name << " with rating " << movieNode->rating << endl;
  }else if(strcmp(argv[1], "false") == 0){
    

    Node* dummy;
    clock_t t1, t2;
    clock_t difference;
    clock_t totalTime = 0;
    clock_t minimum=0;
    clock_t maximum=0;
    vector<int> timev;

    for(int i = 0; i < atoi(argv[3]); i++){
      t1 = clock();
      dummy = list.searchPrefix("");
      t2 = clock();
      
      difference = t2-t1;
      totalTime+=difference;
      timev.push_back(difference);

      if(!minimum){
        minimum = difference;
      }
      
      if(minimum>difference){
        minimum = difference;
      }
      if(maximum<difference){
        maximum = difference;
      }
      

    }

    

    cout << "Total time:  "<< totalTime/10 << " microseconds" << endl;
    cout << "Average Time: " << 1.0*(totalTime)/atoi(argv[3])/10 << " microseconds" << endl;
    cout << "Minimum Time: " << minimum/10 << " microseconds" << endl;
    cout << "Maximum Time: " << maximum/10 << " microseconds" << endl;
    cout << "Median Time: " << findMedian(timev)/10 << " microseconds" << endl;
  }

  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < int(line.length()); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

double findMedian(vector<int> arr){
  if(arr.size() == 0){
    return 0;
  }
  if(arr.size() == 2){
    return (arr.at(0) + arr.at(1))/2.0;
  }
  if(arr.size() == 1){
    return arr.at(0);
  }
  arr.erase(arr.begin()+arr.size()-1);
  arr.erase(arr.begin());
  findMedian(arr);
  
}