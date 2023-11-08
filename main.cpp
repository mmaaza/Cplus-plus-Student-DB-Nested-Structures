//Program: Student Database Using Structures
//Programmer: Muhammad Maaz Ahmad
//Compiler: Microsoft Visual Studio 2022 Community Edition

#include <iostream>
#include <string>
#define MAX 70
using namespace std;

struct nameType {
    string fname;
    string lname;
};

struct dateType {
    string dob;
    string doa;
};

struct marksType {
    int marks[5];
    int totalMarks;
    double percentage;
};

struct Student {
    int regNo;
    nameType name;
    dateType date;
    marksType record;
};

void readData(Student students[], int& nn) {
    cout << "Enter the number of students you want to enter: ";
    cin >> nn;
    if (nn > 0 && nn < MAX) {
        cin.ignore(); // Add this line to clear newline character left after nn input
        for (int i = 0; i < nn; i++) {
            cout << endl << "Enter student " << i + 1 << " registration number: ";
            cin >> students[i].regNo;

            cout << endl << "Enter student " << i + 1 << " First Name: ";
            cin.ignore(); // to ignore newline character left in the buffer by cin
            getline(cin, students[i].name.fname);

            cout << endl << "Enter student " << i + 1 << " Last Name: ";
            getline(cin, students[i].name.lname);
            cout << students[i].name.lname << endl;

            cout << endl << "Enter student " << i + 1 << " Date of Birth (dd-mm-yyyy): ";
            getline(cin, students[i].date.dob);

            cout << endl << "Enter student " << i + 1 << " Date of Admission (dd-mm-yyyy): ";
            getline(cin, students[i].date.doa);
            
            for (int j = 0; j < 5; j++) {
                do {
                    int tempMks;
                    cout << endl << "Enter student " << i + 1 << " Subject " << j + 1 << " marks: ";
                    cin >> tempMks;
                    cin.ignore(); // Add this line to clear newline character
                    if (tempMks >= 0 && tempMks <= 100) {
                        students[i].record.marks[j] = tempMks;
                        break;
                    }
                    else
                        cout << "Invalid Marks. Enter marks between 0-100";
                } while (true);
            }
            cout << endl << "===================================================";
        }
        cout << endl;
    }
    else {
        nn = 0;
        cout << "Invalid Number of students!";
    }
}


void appendData(Student students[], int& nn) {
    cout << endl << "Enter student " << nn + 1 << " registration number: ";
    cin >> students[nn].regNo;
    cout << endl << "Enter student " << nn + 1 << " First Name: ";
    cin.ignore(); // to ignore whitespace character left in the buffer by cin
    getline(cin, students[nn].name.fname);

    cout << endl << "Enter student " << nn + 1 << " Last Name: ";
    getline(cin, students[nn].name.lname);
    for (int j = 0; j < 5; j++) {
        do {
            int tempMks;
            cout << endl << "Enter student " << nn + 1 << " Subject " << j + 1 << " marks: ";
            cin >> tempMks;
            if (tempMks >= 0 && tempMks <= 100) {
                students[nn].record.marks[j] = tempMks;
                break;
            }
            else
                cout << "Invalid Marks. Enter marks between 0-100";
        } while (true);
    }
    cout << endl << "===================================================";
    nn++;
}

void resultGen(Student students[], int nn) {
    if (nn == 0)
        cout << "No Data available. Please, insert some data.";
    else {
        for (int i = 0; i < nn; i++) {
            int mksSum = 0;
            for (int j = 0; j < 5; j++) {
                mksSum += students[i].record.marks[j];
            }
            students[i].record.totalMarks = mksSum;
            students[i].record.percentage = (mksSum / 500.0) * 100;
        }
    }
}

void resultShow(Student students[], int nn) {
    if (nn == 0)
        cout << "No Data available. Please, insert some data.";
    else {
        cout << "Name\t" << "\t\t\tReg #\t" << "Subj 1\t" << "Subj 2\t" << "Subj 3\t" << "Subj 4\t" << "Subj 5\t"
            << "MKS OBT\t" << "Percentage" << endl
            << "----------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < nn; i++) {
            cout << students[i].name.fname << " " << students[i].name.lname << "\t\t\t\t" << students[i].regNo << "\t" << students[i].record.marks[0] << "\t"
                << students[i].record.marks[1] << "\t" << students[i].record.marks[2] << "\t" << students[i].record.marks[3] << "\t"
                << students[i].record.marks[4] << "\t" << students[i].record.totalMarks << "\t" << students[i].record.percentage << "%\t" << endl;
        }
    }
}

int searchRec(Student students[], int nn) {
    int sInfo;
    int sPos = -1;
    if (nn == 0)
        cout << "No Data available. Please, insert some data." << endl;
    else {
        cout << endl << "Enter reg no. of student: ";
        cin >> sInfo;
        for (int i = 0; i < nn; i++) {
            if (sInfo == students[i].regNo) {
                sPos = i;
                break;
            }
        }
        return sPos;
    }
}

void delRecord(Student students[], int& nn) {
    if (nn == 0)
        cout << endl << "No Data available. Please, insert some data." << endl;
    else {
        int delPos = searchRec(students, nn);
        if (delPos == -1)
            cout << endl << "Not found for Deletion" << endl;
        else {
            for (int i = delPos; i < nn - 1; i++) {
                students[i] = students[i + 1];
            }
            nn--;
            cout << endl << "Operation Successful!" << endl;
        }
    }
}

void updateRegNo(Student students[], int uPos) {
    cout << "Enter new registration number for " << students[uPos].name.fname << " " << students[uPos].name.lname << ": ";
    cin >> students[uPos].regNo;
    cout << endl;
}

void updateName(Student students[], int uPos) {
    cout << "Enter new name for " << students[uPos].name.fname << " " << students[uPos].name.lname << ": ";
    cout << endl << "Enter First Name (New): ";
    cin.ignore();
    getline(cin, students[uPos].name.fname);

    cout << endl << "Enter Last Name (New): ";
    getline(cin, students[uPos].name.lname);
    cout << endl;
}

void updateMarks(Student students[], int uPos) {
    for (int j = 0; j < 5; j++) {
        do {
            int tempMks;
            cout << endl << "Enter Subject " << j + 1 << " marks (new): ";
            cin >> tempMks;
            cin.ignore(); // Add this line to clear newline character
            if (tempMks >= 0 && tempMks <= 100) {
                students[uPos].record.marks[j] = tempMks;
                break;
            }
            else
                cout << "Invalid Marks. Enter marks between 0-100";
        } while (true);
    }
}

void updateDob (Student students[], int uPos) {
    cout << "Enter date of Birth (New): ";
    cin.ignore();
    getline(cin, students[uPos].date.dob);
    cout << endl;
}

void updateDoa(Student students[], int uPos) {
    cout << "Enter date of Admission (New): ";
    cin.ignore();
    getline(cin, students[uPos].date.doa);
    cout << endl;
}

void updateRecord(Student students[], int nn) {

    char ch;

    int updatePos = searchRec(students, nn);

    if (updatePos == -1) {
        cout << "Record not found." << endl;
        return;
    }

    do {
        cout << endl << "----------------** Update Menu **----------------" << endl
            << "1. Update Student Registration No" << endl
            << "2. Update Student Name" << endl
            << "3. Update Student Subjects" << endl
            << "4. Update Student Admission Date" << endl
            << "5. Update Student Date of Birth" << endl
            << "6. Return to Previous Menu" << endl
            << "----------------** ----------- **----------------" << endl;

        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch) {
        case '1':
            updateRegNo(students, updatePos);
            break;
        case '2':
            updateName(students, updatePos);
            break;
        case '3':
            updateMarks(students, updatePos);
            break;
        case '4':
            updateDoa(students, updatePos);
            break;
        case '5':
            updateDob(students, updatePos);
            break;
        case '6':
            return;
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (true);

}

void showBio(Student students[], int nn) {
    int userPos = searchRec(students, nn);
    if (userPos == -1)
        cout << "User doesnot exist";
    else {
        cout << "First Name: " << students[userPos].name.fname << endl;
        cout << "Last Name: " << students[userPos].name.lname << endl;
        cout << "Date of Birth: " << students[userPos].date.dob << endl;
        cout << "Date of Admission: " << students[userPos].date.doa << endl;
    }
}

int main() {
    Student students[MAX];
    int n = 0;
    char ch;

    do {
        cout << endl << "----------------** Menu **----------------" << endl
            << "1. Add or Append Data" << endl
            << "2. Display Result Card" << endl
            << "3. Search a particular Record" << endl
            << "4. Delete a Record" << endl
            << "5. Update Record" << endl
            << "6. Students Bio" << endl
            << "7. Exit" << endl
            << "----------------** ---- **----------------" << endl;

        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch) {
        case '1':
            if (n > 0)
                appendData(students, n);
            else
                readData(students, n);
            break;
        case '2':
            if (n > 0)
            {
                resultGen(students, n);
                resultShow(students, n);
            }
            else
                cout << "No data avaiable, please insert data first." << endl;
            break;
        case '3':
            int sPos;
            resultGen(students, n);
            sPos = searchRec(students, n);
            if (n != 0) {
                if (sPos != -1) {
                    cout << "Name\t" << "\t\t\t\t\tReg #\t" << "Subj 1\t" << "Subj 2\t" << "Subj 3\t" << "Subj 4\t" << "Subj 5\t"
                        << "MKS OBT\t" << "Percentage" << endl
                        << "----------------------------------------------------------------------------------------------------------" << endl;
                    cout << students[sPos].name.fname << " " << students[sPos].name.lname << "\t\t\t\t" << students[sPos].regNo << "\t" << students[sPos].record.marks[0] << "\t"
                        << students[sPos].record.marks[1] << "\t" << students[sPos].record.marks[2] << "\t" << students[sPos].record.marks[3] << "\t"
                        << students[sPos].record.marks[4] << "\t" << students[sPos].record.totalMarks << "\t" << students[sPos].record.percentage << "%\t" << endl;
                }
                else {
                    cout << "No result matched!";
                }
            }
            break;
        case '4':
            delRecord(students, n);
            break;
        case '5':
            
            updateRecord(students, n);
            break;
        case '6':
            showBio(students, n);
            break;
        case '7':
            exit(-1);
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (true);
}

