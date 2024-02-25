#include <bits/stdc++.h>
using namespace std;

struct Course{
    string name;
    int hoursPerWeek;
};

struct Slot{
    string day;
    string time;
};

Course takeCourseInput(){
    Course course;
    cout << "Enter course name: ";
    cin >> course.name;
    cout << "Enter hours per week for " << course.name << ": ";
    cin >> course.hoursPerWeek;
    return course;
}

Slot takeSlotInput(){
    Slot slot;
    cout << "Enter day for the slot: ";
    cin >> slot.day;
    cout << "Enter time for the slot: ";
    cin >> slot.time;
    return slot;
}

void saveTimetableToFile(const vector<pair<Course, Slot>>& timetable, const string& filename){
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : timetable) {
            file << "Course: " << entry.first.name << ", Hours Per Week: " << entry.first.hoursPerWeek
                 << ", Slot: " << entry.second.day << " " << entry.second.time << endl;
        }
        cout << "Timetable saved to " << filename << endl;
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void showAllCourses(const vector<pair<Course, Slot>>& timetable){
    cout << "All Entered Courses:" << endl;
    for (const auto& entry : timetable) {
        cout << "Course: " << entry.first.name << ", Hours Per Week: " << entry.first.hoursPerWeek << endl;
    }
}

int main(){
    vector<pair<Course, Slot>> timetable;

    // Take input for courses and slots
    char choice;
    do {
        Course course = takeCourseInput();
        Slot slot = takeSlotInput();
        timetable.push_back({course, slot});

        cout << "Do you want to add another course and slot? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    showAllCourses(timetable);

    string filename;
    cout << "Enter file name to save timetable: ";
    cin >> filename;
    saveTimetableToFile(timetable, filename);

    return 0;
}
