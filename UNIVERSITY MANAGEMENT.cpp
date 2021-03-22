#include<iostream>
#include<stdlib.h>
using namespace std;

int fakeMain();

class University
{
private:
    string loc = "Cumilla Cantonment, Cumilla, Bangladesh" ;
public:
    static void f()
    {
        cout<< "                Welcome to BAIUST" << endl;
    }
    void dept()
    {
        cout<< "Department of CSE\n";
    }
    int history()
    {
        cout << "\tBangladesh Army International University of Science and Technology (BAIUST),\n"
             << "a pioneer university of Bangladesh Army, started its journey from 14 February 2015 with the \n"
             << "motto of \"Knowledge, Wisdom and Technology\". It is established temporarily at the serene and \n"
             << "secured environment of Comilla Cantonment with the mission to provide State of the Art education\n"
             << "and research in science, engineering, Business Administration and other relevant programs. It\n"
             << "expects to run its affairs in permanent location from 2022.\n";
        return 0;
    }
    int location()
    {
        cout << loc<<endl;
        return 0;
    }
    int transport()
    {
        cout << "Fall semester will start from April.\n"
             << "For more information call-01756436655\n";
        return 0;
    }
};

class Student: public University
{
private:
    string fullName;
    int id;
    string dept;
public:
    Student()
    {
        //cout<<"Enter parameters"<<endl;
    }
    Student(string fullName, int id,string dept)
    {
        this->fullName = fullName;
        this->id = id;
        this->dept = dept;
    }
    /*void dept()
    {
        cout<< "Department of CSE\n";
    }*/
    int displayStudent();
};

int Student :: displayStudent()
{
    cout << "\nName: " << fullName
         << "\nId: " << id
         << "\nDepartment: " << dept << endl;
    return 0;
}

class Course : public Student
{
public:
    double score;
    string courseCode;
    int display()
    {
        cout << "Course code: " << courseCode
             << "\tCGPA: " << score << endl;
        return 0;
    }
    Course& setCC(string CC)
    {
        courseCode = CC;
        return *this;
    }
    Course& setS(double S)
    {
        score = S;
        return *this;
    }
    friend Course operator+ (const Course&, const Course&);
};

inline double cgpa(double a)
{
    return a/5;
}

Course operator+(const Course& c1, const Course& c2)
{
    Course c;
    c.score = c1.score + c2.score;
    return c;
}

class Result : public Course
{
public:
    double score;
    Result(double score)
    {
        this->score = score;
    }
    friend class VC;
};

class Faculty: public University
{
public:
    string name;
    mutable string des;
    void dept()
    {
        cout<< "Department of CSE\n";
    }
    Faculty(string s1,string s2)
    {
        name=s1;
        des=s2;
        cout<<"Name: "<<name<<endl;
        cout<<"Designation: "<<des<<endl;
        dept();
        cout<<"--------------------------"<<endl;

    }
};
int forFacultyInfo()
{
    const Faculty f1("Asaduzzaman","Associate Professor & HOD"),f2("Sabina Zaman","Lecturer"),f3("Fazle Rabbi","Lecturer");
}
int forUniversity()
{
    University uni1;
    int option;
    cout << "Choose an option from below:\n";
    cout << "1)Check university history\n";
    cout << "2)Check location of BAIUST\n";
    cout << "3)Check admission info\n";
    cout << "10) to go to Main menu\n";
    cout << "0)To close the program\n";
    cout << "You choose: ";
    while(cin >> option)
    {
        cout << "\n";
        if(option == 1)
        {
            uni1.history();
        }
        else if(option == 2)
        {
            uni1.location();
        }
        else if(option == 3)
        {
            uni1.transport();
        }
        else if(option == 10)
        {
            fakeMain();
        }
        else if(option == 0)
        {
            exit(0);
        }
        else
            cout<< "Enter a valid option\n";
        cout << "\nChoose an option form above:\n";
        cout << "You choose: ";
    }
    return 0;
}

int topperOfCSE()
{
    Student Tania("Tania Sultana", 1109003, "CSE");
    Tania.displayStudent();
    Course c1, c2, c3, c4, c5, total;
    c1.courseCode = "CSE-201";
    c1.score = 4;
    c2.courseCode = "CSE-203";
    c2.score = 4;
    c3.courseCode = "CSE-205";
    c3.score = 4;
    c4.courseCode = "MATH-245";
    c4.score = 4;
    c5.courseCode = "EEE-269";
    c5.score = 4;
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();
    total = c1 + c2 + c3 + c4 + c5;
    Result resTania = cgpa(total.score);
    cout << "\tTotal CGPA: " << resTania.score << endl;
    return 0;
}

int tooperOfEEE()
{
    string name;
    int id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter id: ";
    cin >> id;
    try
    {
        if(id > 1200000 && id <= 1299999){}
        else
        {
            throw 'a';
        }
    }
    catch(char a)
    {
        cout << "Enter a valid Id";
        cout << "Enter id: ";
        cin >> id;
    }
    Student someone(name, id, "EEE");
    Course c1, c2, c3;
    string CC;
    double S;
    cout << "Courrse Code: ";
    cin  >> CC;
    cout << "CGPA: ";
    cin >> S;
    c1.setCC(CC).setS(S);
    cout << "Courrse Code: ";
    cin  >> CC;
    cout << "CGPA: ";
    cin >> S;
    c2.setCC(CC).setS(S);
    cout << "Courrse Code: ";
    cin  >> CC;
    cout << "CGPA: ";
    cin >> S;
    c3.setCC(CC).setS(S);
    double Total;
    Total = c1.score + c2.score + c3.score;
    cout << "Total CGPA : " << Total/3;
    return 0;
}
int forStudentInfo()
{
    int option;
    cout << "Choose an option from below:\n";
    cout << "1)Topper of this semester final of CSE department.\n";
    cout << "2)Add topper of this semester final of EEE department.\n";
    cout << "10) to go to Main menu\n";
    cout << "0)To exit program\n";
    cout << "You choose: ";
    while(cin >> option)
    {
        if(option == 1)
        {
            topperOfCSE();
        }
        else if(option == 2)
        {
            tooperOfEEE();
        }
        else if(option == 10)
        {
            fakeMain();
        }
        else if(option == 0)
        {
            terminate();
        }
        else
            cout<< "Enter a valid option\n";
        cout << "\nChoose an option form above:\n";
        cout << "You choose: ";
    }
    return 0;
}

int fakeMain()
{
    int option;
    cout << "Choose an option from below:\n";
    cout << "1)To check BAIUST information\n";
    cout << "2)To check student information\n";
    cout << "3)To check faculty information\n";
    cout << "0)To exit program\n";
    cout << "You choose: ";
    while(cin >> option)
    {
        cout << "\n";
        if(option == 1 )
        {
            forUniversity();
        }
        else if (option == 2)
        {
            forStudentInfo();
        }
        else if( option == 3)
        {
            forFacultyInfo();
        }
        else if(option == 0)
        {
            unexpected();
        }
        else
            cout << "Enter a valid option\n";
    }
    return 0;
}

int main()
{
    University :: f();
    fakeMain();
}



