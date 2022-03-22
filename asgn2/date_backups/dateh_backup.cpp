#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
private:
	int month, day, year;
	// format is declared as single char for ease of access
	// 'D' = default, 'T' = two-digit, 'L' = long-form
	// 'J' = Julian
	char format = 'D';
public:
	// primary functions 
	void Input();
	void Show();
	bool Set(int m, int d, int y);
	bool SetFormat(char f);
	void Increment(int numDays = 1);
	int Compare (const Date& day);
	
	// getter functions
	int GetMonth() {return month; }
	int GetDay() {return day; }
	int GetYear() {return year; }

	// constructor
	Date();
	Date(int m, int d, int y);
};

#endif
