#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

main()
{
  //ostringstream ss;
  string colors[6][7];
  ifstream readFile;
  readFile.open("colors.txt");
  int count = 0;
  while(!readFile.eof() && count/7<6)
    {
      getline(readFile, colors[count/7][count%7]);
      cout << count/7 << ", " << count%7 << ": " << colors[count/7][count%7] << "\n" <<endl;
      count++;
    }
  readFile.close();
  cout << "End\n"<<endl;
  
  return 0;
}
