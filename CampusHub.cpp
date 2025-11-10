#include <iostream>       // To Be Able To Use Input And Output Without Their Actual prefix

#include <string>        // Allows Us To Use Many String Methods

#include <algorithm>    // Gives Access To Already Made Functions

#include <vector>      // Gives Access To Vector Datatypes 

#include <iomanip>    // Used To format input and output  

#include <limits>    // Gives Infomation about the limits of data types

using namespace std;


//  A Student class To Display the normally asked questions
class Student{
	public:
	string firstName,departmentName,lastName,courseName,address,teleNumber,studentID;
	int age;
	double gpa;
	
	Student(string firstName,string lastName,string departmentName,
	string courseName,string address,string teleNumber,int age,string studentID,
	double gpa){
	this->firstName = firstName;
	this->lastName = lastName;
	this->departmentName = departmentName;
	this->courseName = courseName;
	this->address = address;
	this->teleNumber = teleNumber;
	this->age = age;
	this->studentID = studentID;
	this->gpa = gpa;
	
			
	}
	

};

// Creating A Function For Every Specefic Needs
void displayAll(const vector<Student> &database);
void addNewStudent( vector<Student> &database);
void searchStudent(const vector<Student> &database);
void updateStudent( vector<Student> &database);
void deleteStudent( vector<Student> &database);
void exitSystem();


// The Main User Interface
int main(){
	// A CampusHub Management System
	
	
	// Including Vectors so it serves as a storage...
	vector <Student> database;
	int option;
	
	do{
	
	cout << "******************************************************************" << endl;
	cout << "*****            CAMPUSHUB MANAGEMENT SYSTEM                  ****" << endl;
    cout << "*****                      C B G                              ****" << endl;
	cout << "******************************************************************" << endl;
	cout << endl;
	cout << "1. Add New Student \n";
	cout << "2. Display All Student \n";
	cout << "3. Search For Student \n";
	cout << "4. Update Student \n";
	cout << "5. Delete Student \n";
	cout << "6 Exit \n";
	cout << endl;
	
	cout << "Please enter an option \n";
	cin >> option;
	cout << endl;
	
	// If user Input is not valid enter an error
	 while( cin.fail()){
	 	cin.clear();
	 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 	cout << " Enter A Valid Option \n";
	 	cin >> option;
	 	
	 }
	
	
	 // Using Switch Case To Determine The User Option
	 switch(option){
	 	
		 case 1:{ 
	 	addNewStudent(database);
	 	cout << endl;
			break;
		 }
		 case 2:{
		 	displayAll(database);
		 	cout << endl;
			break;
		 }
		 case 3:{
		 	searchStudent(database);
		 	cout << endl;
			break;
		 }
		 case 4:{
		 	updateStudent(database);
		 	cout << endl;
			break;
		 }
		 case 5:{
		 	deleteStudent(database);
		 	cout << endl;
			break;
		 }
		 case 6:{
		   exitSystem();
		 	cout << endl;
			break;
		 }
		 default :{
		 	cout << " Please Enter A Valid Input  ";
		 	cout << endl;
			break;
		 }
	 	
	 	
	 }
       }while( option != 6 );
	
	return 0;
}

   // A Function That Displays All The Saved And Avalaible Students
	void displayAll(const vector<Student> &database){
		
		// First Checking To Know The Number Of Student In The Database
			int total = database.size();
			  
		// Checking To Handle Empty Database
		if (database.empty() ){
			cout << " || No Student Available Yet ... || \n";
			cout << " Available - Students = " << total << endl;
			
		}
		else{
		
					
		cout << "******************************************************* \n";
		cout << "            DISPLAYING AVAILABLE DATA  ...               \n";
		cout << "******************************************************* \n";
		cout << endl;	
			
		for (const Student &students : database) {
			
			// Making Sure User Inputs Valid Info and Applying Indentation [ apperance ]
			
			cout << " Personal Details : " << endl;
			cout << " First Name      || " << (students.firstName.empty() ? " Not Available " : students.firstName)  << endl; 
		    cout << " Last Name       || " << (students.lastName.empty() ? " Not Available " : students.lastName )  << endl;
			cout << " Age             || " << (students.age < 0 ? " Not Available " : to_string(students.age) )  << endl;
			cout << endl;
			
			cout << " Academic Details : " << endl;
		    cout << " Department Name || " << (students.departmentName.empty() ? " Not Available " : students.departmentName) << endl; 
			cout << " Course Name     || " << (students.courseName.empty() ? " Not Available " : students.courseName) << endl;
			cout << " Student ID      || " << (students.studentID.empty() ? " Not Available " : students.studentID ) << endl;
			
			if (students.gpa < 0 || students.gpa > 5.0 ){
			cout << " Gpa             ||   Not Available " << endl; 
			}
			else{
			cout << " Gpa             || " << fixed << setprecision(2) << students.gpa << endl;
			}
			cout << endl;
			
			cout << " Home Details : " << endl;
			cout << " Address         || " << (students.address.empty() ? " Not Available " : students.address) << endl;
			cout << " Tele Number     || " << (students.teleNumber.empty() ? " Not Available " : students.teleNumber) << endl; 
			cout << endl;
			cout <<"======================================================================================== \n";
			cout << endl;	
		
		}
		
		if( total > 0){
			cout << " Total Students  || " << total << endl;
		
		}
		
	}
	};	
	
	
	
	// A Function That Adds A New Student 
	void addNewStudent(vector<Student> &database){
		
		// Declaring Variables
		string firstName,departmentName,lastName,courseName,address,teleNumber,studentID;
	    int age;
	    double gpa;
		
		// The UI For Declaring The Add New Student
		cout << " ********************************************************** \n";
		cout << "                     NEW STUDENT TEMPLATE                   \n";
		cout << " ********************************************************** \n";
		cout << endl;
		
		// Accepting First Name
		cout << " Please Enter Your First Name \n";
		cin >> firstName;
		cout << endl;
		
		// Accepting Last Name
		cout << " Please  Enter Your Last Name \n";
		cin >> lastName;
		cout << endl;
		
		// Clears any leftover line beofre getline...happens when switching from cin to getline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		// Accepting Course Name
		cout << " Enter Your Course Name \n";
		getline(cin,courseName);
		cout << endl;
		
		// Accepting Student ID
		cout << " Enter Student ID \n";
		cin >> studentID;
	    cout << endl;
		
		// Clears any leftover line beofre getline...vhappens when switching from cin to getline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		// Accepting Department Name
		cout << " Enter Department Name \n";
		getline(cin,departmentName);
		cout << endl;
		
		// Accepting Address
		cout << " Enter Your Address \n";
		getline(cin,address);
		cout << endl;
		
		// Accepting Age
		cout << " Enter Your Age \n";
		cin >> age;
	   cout << endl;
	   
		// Throwing An Error If The User Types Unessary Inputs			
		while(true){
			
		if( cin.fail() ){
			cin.clear();
			cin.ignore(10000,'\n');
			cout << " Enter A Valid Age \n ";
			cin >> age;
			cout << endl;
					}
					
		else break;			
					
		};
		
		// Clears any leftover line beofre getline...vhappens when switching from cin to getline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		// Accepting Telephone Number
	 	cout << " Enter Your Telephone Number \n";
		getline(cin,teleNumber);
		cout << endl;
	
	    // Accepting GPA
		cout << " Enter Your GPA \n";
		cin >> gpa;
		cout << endl;
					
		// Throwing An Error If The User Inputs Unessary Inputs		
			while(true){
				
			if( cin.fail() ){
			cin.clear();
			cin.ignore(10000,'\n');
			cout << " Enter A Valid Gpa \n ";
			cin >> gpa;
			cout << endl;
				
		}
		else break;
			}
		
		// Making Sure Stdents Should Be Added
		char opt;
		cout << " Confirm Adding This Student ? ( Y / N ) \n";
		cin >> opt;
		cout << endl;
		
		// Using Switch Case To Determine Each User Input
		switch(opt){
			
			// If The User Choose No
			case 'n': 
			case 'N':{
			
			cout << " Student Addition Failed \n";
			cout << endl;
			break;
			
			};
			
			// If The User Choose Yes
			case 'Y':
			case 'y':{
		
			database.push_back(Student(firstName,lastName,departmentName,courseName,address,teleNumber,age,studentID,gpa));
		
		   cout << " || ----  New Student Added ---- || \n";
		   cout << endl;
			
			break;
			};
			
			// If User Types Unessary Inputs 
		default:{
	        while(true){
	        	cin.clear();
	        	cin.ignore(10000,'\n');
	        	cout << " Invalid Input. Please Enter Y or N \n";
	        	cin >> opt;
	        	cout << endl;
	        	
	        	if (opt == 'Y' || opt == 'y'){
		
	        database.push_back(Student(firstName,lastName,departmentName,courseName,address,teleNumber,age,studentID,gpa));
		   cout << " || ----  New Student Added ---- || \n";
		   cout << endl;
		   break;
	        		
				}
				else if (opt == 'N' || opt == 'n'){
					cout << " Student Addition Cancelled \n";
					cout << endl;
					break;
				}
			}
			break;
		}
	
	};
	
}

	
    // A Function That Search For A New Student
    void searchStudent(const vector<Student> &database){
	
	string studentNO;
	bool working = false;
	
	
	cout << "********************************************************** \n";
	cout << "                   SEARCH FOR A STUDENT                    \n";
	cout << "********************************************************** \n";
	cout << "Enter Student ID Number \n";
	cin >> studentNO;
	cout << endl;
	
	
	for( const Student &findID : database ){
		if( studentNO == findID.studentID ){
			
			cout << "************************************************* \n";
			cout << "                  STUDENT FOUND                   \n";
			cout << "************************************************* \n";
			
			cout << " Personal Details : " << endl;
			cout << " First Name      || " << findID.firstName  << endl; 
		    cout << " Last Name       || " << findID.lastName  << endl;
			cout << " Age             || " << findID.age << endl;
			cout << endl;
			
			cout << " Academic Details : " << endl;
		    cout << " Department Name || " << findID.departmentName << endl; 
			cout << " Course Name     || " << findID.courseName << endl;
			cout << " Student ID      || " << findID.studentID  << endl;
			cout << " GPA             || " << findID.gpa << endl;
			cout << endl;
			
			cout << " Home Details : " << endl;
			cout << " Address         || " << findID.address << endl;
			cout << " Tele Number     || " << findID.teleNumber << endl; 
			cout << endl;
			cout <<"======================================================================================== \n";
			cout << endl;	
			
            working = true;
			break;
		}
		
		 	}
		 	
		 	if(!working){
		
		cout <<  " Student Cannot Be Found In School Management System \n";
		cout << endl;
		
	}

}

    // A Function That Updates The Student 
    void updateStudent( vector<Student> &database){
    	
    	// Declaring Variables
		string firstName,departmentName,lastName,courseName,address,teleNumber,studentID;
	    int age,option;
	    double gpa; 
	    
	       
    // Using A do while - loop To Display The Elements Unless The User Exits
           
           do{
		    
    	cout << "************************************************************ \n";
    	cout << "                     UPDATING THE STUDENT                    \n";
		cout << "                            SYSTEM                           \n";
       	cout << "                                                             \n";
		cout << "************************************************************ \n";
    	cout << "1.First Name || " << endl;
    	cout << "2.Last Name || " << endl;
    	cout << "3.Department Name || "  << endl;
    	cout << "4.Course Name || "  << endl;
    	cout << "5.Address Name || " << endl;
    	cout << "6.Telephone Number || "  << endl;
    	cout << "7.Age || "  << endl;
    	cout << "8.Student ID || "  << endl;
    	cout << "9.Gpa || "  << endl;
    	cout << "10. Exit \n";
    	cout << "Choose Option To Modify \n";
    	cin >> option;
    	cout << endl;
    	     	
			 for( Student &storage : database ){
			 
    	switch(option){
    		case 1:{
    			cout << "Modify First Name \n";
    			cin >> firstName;
    			storage.firstName = firstName;
				break;
			}
			case 2:{
				cout << "Modify Last Name \n";
				cin >> lastName;
				storage.lastName = lastName;
				break;
			}
			case 3:{
				cout << "Modify Department Name \n";
				cin >> departmentName;
			storage.departmentName = departmentName;
				break;
			}
			case 4:{
				cout << "Modify Course Name \n";
				cin >> courseName;
				 storage.courseName = courseName;
				break;
			}
			case 5:{
				cout << "Modify Address Name \n";
				cin >> address;
			 storage.address  = address;
				break;
			}
			case 6:{
				cout << "Modify Telephone Number \n";
				cin >> teleNumber;
			storage.teleNumber = teleNumber;
				break;
			}
			case 7:{
				cout << "Modify Age \n";
				cin >> age;
			storage.age = age;
				break;
			}
			case 8:{
				cout << "Modify Student ID \n";
				cin >> studentID;
			storage.studentID = studentID;
				break;
			}
			case 9:{
				cout << "Modify GPA \n";
				cin >> gpa;
				storage.gpa = gpa;
				break;
			}
			case 10:{
				cout << "Student Modify Successfully \n";
				cout << "Come Back Later ...... \n";
				break;
			}
			default: {
				cout << "Please Enter A Valid Input ... \n";
				break;
			}
			
    		
		}}
    	}while( option != 10);
    	
	}
	
	// A Function Used To Delete Students
	void deleteStudent( vector<Student> &database){
		
		// Using The Student ID To Know The Specific Student To Delete
		string studentID;
		
		// Used For Confirmation Of Deleltion
		int option;
		
		//The User Interface Of The Delete Section
		cout << "****************************************************** \n";
		cout << "                DELETE STUDENT INFORMATION             \n";
		cout << "****************************************************** \n";
		cout << endl;
		
		cout << "Enter Student ID Of The Student \n";
		cin >> studentID;
		
		for( int i = 0; i < database.size(); i++ ){
			if( studentID == database[i].studentID ){
				
				// Confirming From the user FIrst
				cout << " 1 - Confirm Delete \n";
				cout << " 2- Cancel Process \n";
				cin >> option;
				
				if ( option == 1 ){
					database.erase(database.begin() + i );
					cout << " Process Confirmed Successfully \n";
				}
				else{
					cout << " Process Cancelled Successfully \n";
					
				}
			 return;
			}
			}
			
				cout << "Student Not Found \n";
				cout << "Please Confirm Students ID Details Properply \n";
				
		
	}
	
	// A Function To Display If The User Exits
	void exitSystem(){
		cout << "Application Closed \n ";
		cout << " You Exited CampusHub Management System \n";
	}

