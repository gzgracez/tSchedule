#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  //ostringstream ss;
  string colors[6][8];
  ifstream readFile;
  readFile.open("colors.txt");
  int count = 0;
  while(!readFile.eof() && count/8<6)
    {
      getline(readFile, colors[count/8][count%8]);
      cout << count/8 << ", " << count%8 << ": " << colors[count/8][count%8] << "\n" <<endl;
      count++;
    }
  readFile.close();
  cout << "End\n"<<endl;
  
  return 0;
}
