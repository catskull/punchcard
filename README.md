# punchcard
A small utility to help you keep track of when you leave your desk

Windows only. Portability may be hard since it relies hevaliy on windows.h to monitor keypresses. This also must be built with C++ 11.

This will monitor your keyboard and mouse presses. Once you haven't typed anything for an amount of time (currently set to 5 seconds for testing), it will write the current time to a csv file. Once you start typing again, it will log that to the csv. The goal is to have a time you left and came back from lunch.

TO DO:
- Clean up csv writing
- Add a longer interval before logging
- Clean up code
