// add colored text for schedule comparison 
// cout << "\033[1;32mbold colored text\033[0m" << endl; 
#include <iostream>
#include <fstream>
#include <string>
#include "boost/date_time/gregorian/gregorian_types.hpp"
using namespace std;

bool noSchool(boost::gregorian::date day, bool colors)
{
  if (
      (day) ==  boost::gregorian::date(2015, boost::gregorian::Sep, 23)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 6) //trip day
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 12)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 13)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Oct, 14) //PSAT
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 6)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 26)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 27)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 18)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 19)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 20)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 21)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 22)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 23)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 24)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 25)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 26)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 27)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 28)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 29)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 30)
      || (day) ==  boost::gregorian::date(2015, boost::gregorian::Dec, 31)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Jan, 1)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Jan, 18)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Feb, 15)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 21)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 22)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 23)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 24)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 25)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 26)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 27)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 28)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 29)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 30)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Mar, 31)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Apr, 1)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::Apr, 8)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::May, 20)
      || (day) ==  boost::gregorian::date(2016, boost::gregorian::May, 30)
      ) return true;
  if (colors)
    {
      if ((day) ==  boost::gregorian::date(2015, boost::gregorian::Nov, 24))//Yellow Day 1
	return true;
      else return false;
    }
  else return false;
}

int weekdayDifference(boost::gregorian::date start, boost::gregorian::date end)
{
  if (end < start) 
    {
      cout << "School has not started yet!" << endl;
      return -1;
    }
  int count = 0;
  for (boost::gregorian::day_iterator iter=start; iter!=end; ++iter)
    {
      if (iter->day_of_week() != 0 && iter->day_of_week() != 6) 
        {
          if (noSchool(*iter,true))
            {
              // cout << "No School" << endl;
            }
          else count++;
        }
    }
  return count;
}

void printSchedule(boost::gregorian::date schedDate) {
  // colors
  bool showRooms = true;
  string colors[6][8];
  ifstream readColorFile;
  readColorFile.open("schedules/colors.txt");
  int cCount = 0;
  while(!readColorFile.eof() && cCount/8<6)
    {
      getline(readColorFile, colors[cCount/8][cCount%8]);
      // cout << cCount/8 << ", " << cCount%8 << ": " << colors[cCount/8][cCount%8] << "\n" <<endl;
      cCount++;
    }
  readColorFile.close();

  // classrooms
  string rooms[6][8];
  ifstream readRoomFile;
  if (showRooms)
    {
      readRoomFile.open("schedules/rooms.txt");
      int rCount = 0;
      while(!readRoomFile.eof() && rCount/8<6)
	{
	  getline(readRoomFile, rooms[rCount/8][rCount%8]);
	  // cout << rCount/8 << ", " << rCount%8 << ": " << rooms[rCount/8][rCount%8] << "\n" <<endl;
	  rCount++;
	}
      readRoomFile.close();
    }
  
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

  boost::gregorian::date startDate(2015, boost::gregorian::Sep, 15);
  int dayDiff = weekdayDifference(startDate, schedDate);
  // int dayDiff = (schedDate - startDate).days();
  // cout << schedDate.day_of_week() << endl;
  
  if (dayDiff >= 0)
    {
      if (schedDate.day_of_week() == 0 || schedDate.day_of_week() == 6)
        {
          cout << "Weekend!" << endl;
        }
      else if (noSchool(schedDate,false))
        {
          cout << "No School" << " " << schedDate.month() << "/" << schedDate.day() << "/" <<schedDate.year() << endl;
        }
      else 
        {
          for (int i=0; i<8; i++)
	    {
              if (i == 0)
                {
                  cout << colors[dayDiff%6][i] << " " << schedDate.month() << "/" << schedDate.day() << "/" <<schedDate.year() << endl;
                }
              else 
                {
		  if (showRooms) 
		    {
		      if (rooms[dayDiff%6][i].length() == 0)
			cout << times[schedDate.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << endl;
		      else 
			cout << times[schedDate.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << ": " << rooms[dayDiff%6][i] << endl;
		    }
		  else
		    {
		      cout << times[schedDate.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << endl;
		    }
                }
	    }
        }
    }
  // cout << "Yay!" << endl;
}

// print specific schedule
void printSchedule(boost::gregorian::date schedDate, string name) {
  // colors
  bool showRooms = true;
  string colors[6][8];
  ifstream readColorFile;
  readColorFile.open("schedules/" + name + ".txt");
  int cCount = 0;
  while(!readColorFile.eof() && cCount/8<6)
    {
      getline(readColorFile, colors[cCount/8][cCount%8]);
      cCount++;
    }
  readColorFile.close();

  // classrooms
  string rooms[6][8];
  ifstream readRoomFile;
  if (showRooms)
    {
      readRoomFile.open("schedules/" + name + "rooms.txt");
      int rCount = 0;
      while(!readRoomFile.eof() && rCount/8<6)
  {
    getline(readRoomFile, rooms[rCount/8][rCount%8]);
    rCount++;
  }
      readRoomFile.close();
    }
  
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

  boost::gregorian::date startDate(2015, boost::gregorian::Sep, 15);
  int dayDiff = weekdayDifference(startDate, schedDate);
  // int dayDiff = (schedDate - startDate).days();
  // cout << schedDate.day_of_week() << endl;
  
  if (dayDiff >= 0)
    {
      if (schedDate.day_of_week() == 0 || schedDate.day_of_week() == 6)
        {
          cout << "Weekend!" << endl;
        }
      else if (noSchool(schedDate,false))
        {
          cout << "No School" << " " << schedDate.month() << "/" << schedDate.day() << "/" <<schedDate.year() << endl;
        }
      else 
        {
          for (int i=0; i<8; i++)
      {
              if (i == 0)
                {
                  cout << colors[dayDiff%6][i] << " " << schedDate.month() << "/" << schedDate.day() << "/" <<schedDate.year() << endl;
                }
              else 
                {
      if (showRooms) 
        {
          if (rooms[dayDiff%6][i].length() == 0)
      cout << times[schedDate.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << endl;
          else 
      cout << times[schedDate.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << ": " << rooms[dayDiff%6][i] << endl;
        }
      else
        {
          cout << times[schedDate.day_of_week()-1][i] << " " << colors[dayDiff%6][i] << endl;
        }
                }
      }
        }
    }
  // cout << "Yay!" << endl;
}

int main(int argc, char *argv[])
{
  // date
  // boost::gregorian::date startDate(2015, boost::gregorian::Sep, 15);
  boost::gregorian::date today(boost::gregorian::day_clock::local_day());
  boost::gregorian::date tomorrow = today + boost::gregorian::date_duration(1);
  // boost::gregorian::date today(2015, boost::gregorian::Sep, 15);
  if (argc <= 1) {
    printSchedule(today);
  }
  else if (argc == 2) {
    if (strcmp(argv[1], "tomorrow") == 0 || strcmp(argv[1], "tom") == 0) {
      printSchedule(tomorrow);
    }
    else if (isdigit(*argv[1])) {
      int temp = std::stoi(argv[1]);
      boost::gregorian::date newDate = today + boost::gregorian::date_duration(temp);
      printSchedule(newDate);
    }
    else {
      printSchedule(today, argv[1]);
    }
  }
  else if (argc == 3) {
    if (isdigit(*argv[2])) {
      int temp = std::stoi(argv[2]);
      boost::gregorian::date newPersonDate = today + boost::gregorian::date_duration(temp);
      printSchedule(newPersonDate, argv[1]);
    }
    else if (isdigit(*argv[1])) {
      int temp = std::stoi(argv[1]);
      boost::gregorian::date newPersonDate = today + boost::gregorian::date_duration(temp);
      printSchedule(newPersonDate, argv[2]);
    }
  }
  else {
    printSchedule(today);
  }
  return 0;
}
