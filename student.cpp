#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    string fname;
    string lname;
    int roll;
    float cgpa;
    vector<int> cid;

    Student(string firstName, string lastName, int rollNumber, float cgpaValue, vector<int> courseIds)
        : fname(firstName), lname(lastName), roll(rollNumber), cgpa(cgpaValue), cid(courseIds) {}
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        string fname, lname;
        int roll;
        float cgpa;
        vector<int> cid(5);

        cout << "Add the Student Details" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter the first name of student: ";
        cin >> fname;
        cout << "Enter the last name of student: ";
        cin >> lname;
        cout << "Enter the Roll Number: ";
        cin >> roll;
        cout << "Enter the CGPA: ";
        cin >> cgpa;

        cout << "Enter the course IDs of each course: ";
        for (int &id : cid) {
            cin >> id;
        }

        students.emplace_back(fname, lname, roll, cgpa, cid);
        cout << "Student added successfully!" << endl;
    }

    void findStudentByRoll() {
        int roll;
        cout << "Enter the Roll Number of the student: ";
        cin >> roll;
        for (const Student &student : students) {
            if (student.roll == roll) {
                printStudentDetails(student);
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found." << endl;
    }

    void findStudentByFirstName() {
        string fname;
        cout << "Enter the First Name of the student: ";
        cin >> fname;
        bool found = false;
        for (const Student &student : students) {
            if (student.fname == fname) {
                printStudentDetails(student);
                found = true;
            }
        }
        if (!found) {
            cout << "Student with First Name " << fname << " not found." << endl;
        }
    }

    void findStudentsByCourseId() {
        int courseId;
        cout << "Enter the course ID: ";
        cin >> courseId;
        bool found = false;
        for (const Student &student : students) {
            if (find(student.cid.begin(), student.cid.end(), courseId) != student.cid.end()) {
                printStudentDetails(student);
                found = true;
            }
        }
        if (!found) {
            cout << "No students found for Course ID " << courseId << "." << endl;
        }
    }

    void printTotalStudents() {
        cout << "The total number of students is: " << students.size() << endl;
        cout << "You can have a max of 50 students." << endl;
        cout << "You can add " << 50 - students.size() << " more students." << endl;
    }

    void deleteStudentByRoll() {
        int roll;
        cout << "Enter the Roll Number which you want to delete: ";
        cin >> roll;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->roll == roll) {
                students.erase(it);
                cout << "The Roll Number " << roll << " is removed successfully." << endl;
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found." << endl;
    }

    void updateStudentByRoll() {
        int roll;
        cout << "Enter the Roll Number to update the entry: ";
        cin >> roll;
        for (Student &student : students) {
            if (student.roll == roll) {
                int choice;
                cout << "1. First name\n2. Last name\n3. Roll number\n4. CGPA\n5. Courses\nEnter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter the new first name: ";
                        cin >> student.fname;
                        break;
                    case 2:
                        cout << "Enter the new last name: ";
                        cin >> student.lname;
                        break;
                    case 3:
                        cout << "Enter the new roll number: ";
                        cin >> student.roll;
                        break;
                    case 4:
                        cout << "Enter the new CGPA: ";
                        cin >> student.cgpa;
                        break;
                    case 5:
                        cout << "Enter the new courses: ";
                        for (int &id : student.cid) {
                            cin >> id;
                        }
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        return;
                }
                cout << "UPDATED SUCCESSFULLY." << endl;
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found." << endl;
    }
private:
    void printStudentDetails(const Student &student) {
        cout << "The Student Details are:" << endl;
        cout << "First Name: " << student.fname << endl;
        cout << "Last Name: " << student.lname << endl;
        cout << "Roll Number: " << student.roll << endl;
        cout << "CGPA: " << student.cgpa << endl;
        cout << "Course IDs: ";
        for (int id : student.cid) {
            cout << id << " ";
        }
        cout << endl;
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    while (true) {
        cout << "The Task that you want to perform" << endl;
        cout << "1. Add the Student Details" << endl;
        cout << "2. Find the Student Details by Roll Number" << endl;
        cout << "3. Find the Student Details by First Name" << endl;
        cout << "4. Find the Student Details by Course ID" << endl;
        cout << "5. Find the Total number of Students" << endl;
        cout << "6. Delete the Student Details by Roll Number" << endl;
        cout << "7. Update the Student Details by Roll Number" << endl;
        cout << "8. To Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.findStudentByRoll();
                break;
            case 3:
                sms.findStudentByFirstName();
                break;
            case 4:
                sms.findStudentsByCourseId();
                break;
            case 5:
                sms.printTotalStudents();
                break;
            case 6:
                sms.deleteStudentByRoll();
                break;
            case 7:
                sms.updateStudentByRoll();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
