# tSchedule
Schedule in the terminal for students
* Requires ```boost``` library
* Requires ```colors.txt``` (color schedule), ```times.txt``` (school's time schedule)
* Optionally include ```rooms.txt``` (room schedule)
  * Optionally display rooms in schedule
* Check schedule of future dates
  * Tomorrow: view by using ```tom``` or ```tomorrow``` as an argument
  * Days ahead: view by using the number of days ahead as an argument (ex: ```sched 1``` for tomorrow's schedule)
* Add additional student/faculty schedules
  * Add additional schedules (```name.txt```) to the ```schedules``` folder
  * View by using the name as an argument (first *or* second argument)
  * Can also check schedule of future dates
  * Can also optionally display rooms (```namerooms.txt```)