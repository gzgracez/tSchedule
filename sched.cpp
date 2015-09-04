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
        if (iter->day_of_week() != 0 && iter->day_of_week() != 6) 
          {
            if (
                 (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Sep, 23)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 12)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 13)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 6)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 26)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 27)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 17)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 18)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 19)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 20)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 21)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 22)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 23)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 24)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 25)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 26)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 27)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 28)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 29)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 30)
              || (*iter) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 31)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Jan, 1)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Jan, 18)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Feb, 15)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 21)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 22)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 23)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 24)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 25)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 26)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 27)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 28)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 29)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 30)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 31)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Apr, 1)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::Apr, 8)
              || (*iter) ==  boost::gregorian::date(2016, boost::gregorian::May, 20)
            )
              {
                // cout << "No School" << endl;
              }
            else count++;
          }
      }
    return count;
}

int main(int argc, char *argv[])
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
  boost::gregorian::date today(2015, boost::gregorian::Sep, 23);
  int dayDiff = weekdayDifference(startDate, today);
  // int dayDiff = (today - startDate).days();
  // cout << dayDiff << endl;
  // cout << today.day_of_week() << endl;

  if (startDate.day_of_week() == 0 || startDate.day_of_week() == 6)
    {
      cout << "Weekend!" << endl;
    }
  else if (
       (today) ==  boost::gregorian::date(2015, boost::gregorian::Sep, 23)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 12)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 13)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 6)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 26)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 27)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 17)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 18)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 19)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 20)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 21)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 22)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 23)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 24)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 25)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 26)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 27)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 28)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 29)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 30)
    || (today) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 31)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Jan, 1)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Jan, 18)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Feb, 15)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 21)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 22)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 23)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 24)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 25)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 26)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 27)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 28)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 29)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 30)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 31)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Apr, 1)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::Apr, 8)
    || (today) ==  boost::gregorian::date(2016, boost::gregorian::May, 20)
  )
    {
      cout << "No School" << " " << today.month() << "/" << today.day() << "/" <<today.year() << endl;
    }
  else 
    {
      for (int i=0; i<8; i++)
      	{
          if (i == 0)
            {
              cout << colors[dayDiff%6][i] << " " << today.month() << "/" << today.day() << "/" <<today.year() << endl;
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
