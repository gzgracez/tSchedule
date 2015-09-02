#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  //ostringstream ss;
  string colors[6][8];
  ifstream readColorFile;
  readColorFile.open("colors.txt");
  int count = 0;
  while(!readColorFile.eof() && count/8<6)
    {
      getline(readColorFile, colors[count/8][count%8]);
      cout << count/8 << ", " << count%8 << ": " << colors[count/8][count%8] << "\n" <<endl;
      count++;
    }
  readColorFile.close();

  //times
  string times[6][8];
  ifstream readTimeFile;
  readTimeFile.open("times.txt");
  int tCount = 0;
  while(! readTimeFile.eof() && tCount/8<6)
    {
      getline(readTimeFile, times[tCount/8][tCount%8]);
      cout << tCount/8 << ", " << tCount%8 << ": " << times[tCount/8][tCount%8] << "\n" <<endl;
      tCount++;
    }
  readTimeFile.close();

  cout << "End\n"<<endl;
  
  return 0;
}
