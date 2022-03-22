/* 
Functions are all declared within the "Date" class
in "date.h"

Main functions primarily as menu, calling other functions from
there.

Jackson McAfee, COP3330 Spr2022
*/
 
#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"

using namespace std;

// constant arrays used for logic & for Show()
const bool months_31 [13] = {false, true, false, true, false, true, false, true, true, false, true, false, true};
const string months_abrev [13] = {"blank", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
const int months_days [13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// Input function, isn't well defined in the assignment
// what should be done with the data once read???
void Date::Input() {

string userInput;

cout << "Input a date (m/d/y): " << endl;
cin >> userInput;
while(userInput.find(' ') != string::npos && userInput.find('/') != string::npos) {
cin >> userInput; }}

// default constructor
Date::Date() {
month = 1;
day = 1;
year = 2000; }

// standard constructor
Date::Date(int m, int d, int y) {

// initial validation checks
if(y < 1581) {
goto label; }

if(y == 1582 && m < 10) {
goto label; }

if(m == 2 && d > 28) {
if((y % 4 == 0) && (y % 100 == 0) && (y % 400 == 0)) {
goto valid; }
else if((y % 4 == 0) && (y % 100 == 0)) {
goto label; }
else if((y % 4 == 0)) {
goto valid; }
else {
goto label; }}

if(months_31[m] == false && d > 30) { 
goto label; }

valid:
// final validation checks
if((m > 0 && m < 13) && (d > 0 && d < 32) && (y > 1581)) {
month = m;
day = d;
year = y; }

// assigns default date if invalid
label:
if(month == 0 || day == 0 || year == 0) {
month = 1;
day = 1;
year = 2000; }}

void Date::Show() {

// assigns i a value based on format key
// essentially swaps char to int so that switch can be used
int i;
if(format == 'T') {
i = 1; }
if(format == 'L') {
i = 2; }
if(format == 'J') {
i = 3; }

switch(i) {

// 2 digit case, prints as mm/dd/yy or 01/01/00 for Jan1,2000
case 1: {
string yearstr = to_string(year);
cout << month  << "/" << day  << "/" << yearstr.at(2) << yearstr.at(3)  << endl;
break; }
// long-form case, prints as Month D, YYYY or Jan 1, 2000
case 2: {
cout << months_abrev[month] << ". "  << day << ", " << year << endl;
break; }
// julian case, prints as DDD, YYYY or 1, 2000 for Jan1, 2000
case 3: {
int jday = months_days[month] + day;
cout << jday << ", " << year << endl;
break; }
// default case
default: {
cout << month << "/" << day << "/" << year << endl;
break; }}}

bool Date::Set(int m, int d, int y) {

// date validation, passes to label if invalid
if(y < 1581) {
goto label; }
if(y == 1582 && m < 10) {
goto label; }

if(m == 2 && d > 28) {
if((y % 4 == 0) && (y % 100 == 0) && (y % 400 == 0)) {
goto valid; }
else if((y % 4 == 0) && (y % 100 == 0)) {
goto label; }
else if((y % 4 == 0)) {
goto valid; }
else {
goto label; }}

if(months_31[m] == false && d > 30) {
goto label; }

valid:
// final validation check
if((m > 0 && m < 13) && (d > 0 && d < 32) && (y > 1581)) {
month = m;
day = d;
year = y; 
return true; }

// applies if date was invalid
label:
month = 1;
day = 1;
year = 2000; 
return false; }


// SetFormat function, takes char for format
bool Date::SetFormat(char f) {
if(f == 'D' || f == 'T' || f == 'L' || f == 'J') {
format = f;
cout << "Format change successful. Changed to " << f << " format." << endl;
return true; }
else {
cout << "Format change unsuccessful. Defaulted to D." << endl;
return false; }}

void Date::Increment(int i) {
// declaring i = 1 above throws errors
// sets i = 1 when no other int is given
if(i == 0) {
i = 1; }

day = day + i;

// check for all possible errors
loop:

if(month == 2 && day > 28) {
if((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0)) {
day = day - 29;
month = 3; }
else if((year % 4 == 0) && (year % 100 == 0)) {
day = day - 28;
month = 3; }
else if((year % 4 == 0)) {
day = day - 29;
month = 3; }
else {
day = day - 28;
month = 3; }}

if(month == 12 && day > 31) {
day = day - 31;
month = 1;
year = year + 1; }
if(month != 2 && months_31[month] == false && day > 30) {
day = day - 30;
month = month + 1;
goto loop; }
if(month != 2 && months_31[month] == true && day > 31) {
day = day - 31;
month = month + 1;
goto loop; }

if((months_31[month] == false && day > 30) || (months_31[month] == true && day > 31) || (month == 2 && day > 29)) {
goto loop; }}

int Date::Compare(const Date& d) {
// if different
// returns -1 if calling obj > param obj and 1 otherwise
if(year > d.year) {
return -1; }
else if(d.year > year) {
return 1; }
if(year == d.year && month > d.month) {
return -1; }
else if (year == d.year && d.month > month) {
return 1; }
if(year == d.year && month == d.month && day > d.day) {
return -1; }
else if(year == d.year && month == d.month && d.day > day) {
return 1; }
// if same defaults to 0
return 0;
} 

int main() {
Date d1(2, 29, 2000);
d1.Show();
Date d2, d3;
}
