#include <iostream>
#include <fstream>
#include <string>
#include "boost/date_time/gregorian/gregorian_types.hpp"
using namespace std;

int weekdayDifference(boost::gregorian::date start, boost::gregorian::date end)
{
    int count = 0;
    for (boost::gregorian::day_iterator iter=start; iter!=end; ++iter)
      {
        if (iter->day_of_week() != 0 && iter->day_of_week() != 6) count++;
      }
    return count;
}

int main()
{
  // colors
  string colors[6][8];
  ifstream readColorFile;
  readColorFile.open("colors.txt");
  int cCount = 0;
  while(!readColorFile.eof() && cCount/8<6)
    {
      getline(readColorFile, colors[cCount/8][cCount%8]);
      // cout << cCount/8 << ", " << cCount%8 << ": " << colors[cCount/8][cCount%8] << "\n" <<endl;
      cCount++;
    }
  readColorFile.close();

  // times
  string times[5][8];
  ifstream readTimeFile;
  readTimeFile.open("times.txt");
  int tCount = 0;
  while(! readTimeFile.eof() && tCount/8<5)
    {
      getline(readTimeFile, times[tCount/8][tCount%8]);
      // cout << tCount/8 << ", " << tCount%8 << ": " << times[tCount/8][tCount%8] << "\n" <<endl;
      tCount++;
    }
  readTimeFile.close();

  // date
  // boost::gregorian::date startDate(2015, boost::gregorian::Sep, 15);
  boost::gregorian::date startDate(2015, boost::gregorian::Sep, 15);
  // boost::gregorian::date today(boost::gregorian::day_clock::local_day());
  boost::gregorian::date today(2015, boost::gregorian::Sep,22);
  int dayDiff = weekdayDifference(startDate, today);
  // int dayDiff = (today - startDate).days();
  // cout << dayDiff << endl;
  // cout << today.day_of_week() << endl;

  if (startDate.day_of_week() == 0 || startDate.day_of_week() == 6)
    {
      cout << "Weekend!" << endl;
    }
  else 
    {
      for (int i=0; i<8; i++)
      	{
          if (i == 0)
            {
              cout << colors[dayDiff%6][i] << endl;
            }
          else 
            {
              cout << times[today.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << endl;
            }
      	}
    }
  
  cout << "Yay!" << endl;
  
  return 0;
}