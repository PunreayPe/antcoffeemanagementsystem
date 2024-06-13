#ifndef ___STAFF_H___
#define ___STAFF_H___
///////////////////////
#include "antheaderPlusPlus.h"
#include "antheaderInput.h"
#include "forms.h"
#include <fstream>
#include<direct.h>
///////////////////////
class person{
	
	public:
		// personal info
		char fullname[25];
		char address[14];
		char phonN[10];
		char dob[12];
		char nation[10]; 
		char gender[10];
	public:
		
		void _register_pers_info(){
			
				setcursor(true, 20);
				drawBoxDoubleLineWithBG(40, 2, 75, 25, 87);
				drawBoxDoubleLineWithBG(41, 3, 73, 23, 87);
				drawBoxDoubleLineWithBG(60, 4, 35, 1, 87);
				foreColor(87); gotoxy(63,5); cout << "Register Personal Information";
				HLine(50, 10, 58, 94, '-');
				foreColor(87); gotoxy(54, 9); cout << "-  Register Full name       : ";
				cin.get(fullname,25); fflush(stdin);
				HLine(50, 12, 45, 94, '-');
				foreColor(87); gotoxy(54, 11); cout << "-  Register Gender          : ";
				cin.get(gender,10); fflush(stdin);
				HLine(50, 14, 58, 94, '-');
				foreColor(87); gotoxy(54, 13); cout << "-  Register Date-of-birth   : ";
				foreColor(88); gotoxy(84,13); cout << "DD/MMM/YYYY";
				foreColor(87); gotoxy(84,13); cin.get(dob,12); fflush(stdin);
				HLine(50, 16, 58, 94, '-');
				foreColor(87); gotoxy(54, 15); cout << "-  Register Address         : ";
				cin.get(address,14); fflush(stdin);
				HLine(50, 18, 58, 94, '-');
				foreColor(87); gotoxy(54, 17); cout << "-  Register Phone number    : ";
				cin.get(phonN,10); fflush(stdin);
				HLine(50, 20, 58, 94, '-');
				foreColor(87); gotoxy(54, 19); cout << "-  Register Nationality     : ";
				cin.get(nation,10); fflush(stdin);
				gotoxy(50,23); cout << "Before click enter you have to make sure that information";
		}
		
		void _formUpdatePerInfo(){
				setcursor(true, 20);
				drawBoxDoubleLineWithBG(40, 2, 75, 25, 94);
				drawBoxDoubleLineWithBG(41, 3, 73, 23, 94);
				drawBoxDoubleLineWithBG(60, 4, 35, 1, 94);
				foreColor(87); gotoxy(63,5); cout << "Update Personal Information";
				HLine(50, 10, 58, 92, '-');
				foreColor(87); gotoxy(54, 9); cout << "-  Update Full name       : ";
				cin.get(fullname,25); fflush(stdin);
				HLine(50, 12, 45, 92, '-');
				foreColor(87); gotoxy(54, 11); cout << "-  Update Gender          : ";
				cin.get(gender,10); fflush(stdin);
				HLine(50, 14, 58, 92, '-');
				foreColor(87); gotoxy(54, 13); cout << "-  Update Date-of-birth   : ";
				cin.get(dob,12); fflush(stdin);
				HLine(50, 16, 58, 92, '-');
				foreColor(87); gotoxy(54, 15); cout << "-  Update Address         : ";
				cin.get(address,14); fflush(stdin);
				HLine(50, 18, 58, 92, '-');
				foreColor(87); gotoxy(54, 17); cout << "-  Update Phone number    : ";
				cin.get(phonN,10); fflush(stdin);
				HLine(50, 20, 58, 92, '-');
				foreColor(87); gotoxy(54, 19); cout << "-  Update Nationality     : ";
				cin.get(nation,10); fflush(stdin);
				foreColor(90); gotoxy(50,23); cout << "Before click enter you have to make sure that information";	
				foreColor(90); gotoxy(50,24); cout << "         Update personal infomation successfully";	
		}
};

class staff : public person{
	
	public:
		// user account register
		char username[10];
		char password[10];
		// staff info
		int id;
		char position[15];
		double salary;
		string start_work;
		
		bool isFileExistS(const char* fileName){
			fstream infile(fileName);
			return infile.good();
		}
		
	public:
		void _register_staff_info(){
			
			_register_pers_info(); 
			
			drawBoxDoubleLineWithBG(40, 2, 75, 25, 23);
			drawBoxDoubleLineWithBG(43, 7, 69, 19, 180);
			drawBoxDoubleLineWithBG(42, 3, 71, 3, 75);
			drawBoxDoubleLineWithBG(50, 4, 55, 1, 75);
			gotoxy(50, 5); cout << "R-E-G-I-S-T-E-R  E-M-P-L-O-Y-E-E  I-N-F-O-R-M-A-T-I-O-N";
			drawBoxDoubleLineWithBG(48, 9, 59, 1, 185);
			foreColor(183); gotoxy(50,10); cout << "Register ID's staff : ";
			cin >> id; fflush(stdin); cin.clear();
			drawBoxDoubleLineWithBG(48, 12, 59, 1, 185);
			foreColor(183); gotoxy(50,13); cout << "Register Position   : ";
			cin.get(position,15); fflush(stdin);
			drawBoxDoubleLineWithBG(48, 15, 59, 1, 185); 
			foreColor(183); gotoxy(50,16); cout << "Register Start Work : ";
			getline(cin, start_work); fflush(stdin);
			drawBoxDoubleLineWithBG(48, 18, 59, 1, 185);
			foreColor(183); gotoxy(50,19); cout << "Enter Salary's Staff: ";
			cin >> salary; fflush(stdin); cin.clear();
			gotoxy(64,21); cout << "Accept Terms and Conditions";
			drawBoxDoubleLineWithBG(70, 22, 15, 1, 188);
			setcursor(false, 0);
			gotoxy(74,23); cout << "Confirm";
			getch();
			drawBoxDoubleLineWithBG(70, 22, 15, 1, 75);
			gotoxy(74,23); cout << "Confirm";
			delay(1300);
			foreColor(7);
			cls();
			///
			drawBoxDoubleLineWithBG(40, 2, 75, 18, 23);
			drawBoxDoubleLineWithBG(43, 7, 69, 12, 156);
			drawBoxDoubleLineWithBG(42, 3, 71, 3, 75);
			drawBoxDoubleLineWithBG(50, 4, 55, 1, 75);
			gotoxy(50,5); cout << " @@@@@@@@@@@@@@@@@ \3 Create Account \3 @@@@@@@@@@@@@@@@@";
			setcursor(true, 20);
			drawBoxDoubleLineWithBG(50, 9, 55, 1, 124);
			gotoxy(60,10); cout << " Create Username : "; cin.get(username,10); fflush(stdin); cin.clear();
			drawBoxDoubleLineWithBG(50, 13, 55, 1, 124);
			gotoxy(60,14); cout << " Create Password : "; cin.get(password,10); fflush(stdin); cin.clear();
			setcursor(false, 0);
			foreColor(151); gotoxy(56, 18); cout << "This account you can login as staff option";
		}
		
		void _formUpdateStaffInfo(){
			setcursor(true, 20);
			drawBoxDoubleLineWithBG(40, 2, 75, 25, 23);
			drawBoxDoubleLineWithBG(43, 7, 69, 19, 180);
			drawBoxDoubleLineWithBG(42, 3, 71, 3, 75);
			drawBoxDoubleLineWithBG(50, 4, 55, 1, 75);
			gotoxy(52, 5); cout << "U-P-D-A-T-E  E-M-P-L-O-Y-E-E  I-N-F-O-R-M-A-T-I-O-N";
			drawBoxDoubleLineWithBG(48, 9, 59, 1, 185);
			foreColor(183); gotoxy(50,10); cout << "Update ID's Staff    : ";
			cin >> id; fflush(stdin); cin.clear();
			drawBoxDoubleLineWithBG(48, 12, 59, 1, 185);
			foreColor(183); gotoxy(50,13); cout << "Update Position      : ";
			cin.get(position,15); fflush(stdin);
			drawBoxDoubleLineWithBG(48, 15, 59, 1, 185); 
			foreColor(183); gotoxy(50,16); cout << "Update Start Work    : ";
			getline(cin, start_work); fflush(stdin);
			drawBoxDoubleLineWithBG(48, 18, 59, 1, 185);
			foreColor(183); gotoxy(50,19); cout << "Update Salary's Staff: ";
			cin >> salary; fflush(stdin); cin.clear();
//			setcursor(false, 0);
//			gotoxy(64,22); cout << "Accept Terms and Conditions";
//			drawBoxDoubleLineWithBG(70, 23, 15, 1, 188);
//			gotoxy(73,24); cout << "Confirm";
//			getch();
//			drawBoxDoubleLineWithBG(70, 23, 15, 1, 75);
//			gotoxy(73,24); cout << "Confirm";
//			delay(1300);
		}
		
		void _form_forgetStaffAccount(){
			setcursor(true, 20);
			drawBoxDoubleLineWithBG(40, 2, 75, 18, 23);
			drawBoxDoubleLineWithBG(43, 7, 69, 12, 156);
			drawBoxDoubleLineWithBG(42, 3, 71, 3, 75);
			drawBoxDoubleLineWithBG(50, 4, 55, 1, 75);
			gotoxy(50,5); cout << " @@@@@@@@@@@@@@@ \3 Forget User Account \3 @@@@@@@@@@@@@@@";
			
			drawBoxDoubleLineWithBG(50, 9, 55, 1, 124);
			gotoxy(60,10); cout << " New Username : "; cin.get(username,10); fflush(stdin); cin.clear();
			drawBoxDoubleLineWithBG(50, 13, 55, 1, 124);
			gotoxy(60,14); cout << " New Password : "; cin.get(password,10); fflush(stdin); cin.clear();
			setcursor(false, 0);
			foreColor(151); gotoxy(70, 18); cout << "Successfully";

		}
		
		static void _StffHeaderInfo(){
			cout << left;
			cout << "   ";
			for(int i = 1; i <= 141; i++){
				cout << "=";
			}
			cout << "\n\n     ";
			foreColor(2); cout << setw(9) << "ID";
			foreColor(3); cout << setw(25) << "Full Name";
			foreColor(4); cout << setw(10) << "Gender";
			foreColor(5); cout << setw(16) << "Date of birth";
			foreColor(6); cout << setw(14) << "Address";
			foreColor(7); cout << setw(13) << "Nation";
			foreColor(8); cout << setw(15) << "Position";
			foreColor(9); cout << setw(15) << "Start Work";
			foreColor(10); cout << setw(10) << "Salary";
			foreColor(11); cout << setw(12) << "Phone";
			cout << "\n\n   ";
			for(int i = 1; i <= 141; i++){
				cout << "=";
			}
		}
		
		void _displayAllInfo(){
			
			cout << "\n\n     " << left << fixed << setprecision(2);
			foreColor(2); cout << setw(9) << id;
			foreColor(3); cout << setw(25) << fullname;
			foreColor(4); cout << setw(10) << gender;
			foreColor(5); cout << setw(16) << dob;
			foreColor(6); cout << setw(14) << address;
			foreColor(7); cout << setw(13) << nation;
			foreColor(8); cout << setw(15) << position;
			foreColor(9); cout << setw(15) << start_work;
			foreColor(10); cout << setw(1) << "$" << setw(9) << salary;
			foreColor(11); cout << setw(12) << phonN;
			cout << "\n\n   ";
			for(int i = 1; i <= 141; i++){
				cout << "=";
			}
			cout << endl;
		}
		
		static void _displayUserAccHeader(){
			cout << left;
			cout << "\t\t\t\t  ";
			for(int i = 1; i <= 72; i++){
				cout << "=";
			}
			cout << endl << endl;
			//////////////////////////////
			cout << "\t\t\t\t     ";
			foreColor(2); cout << setw(9) << "ID";
			foreColor(3); cout << setw(25) << "Full Name";
			foreColor(4); cout << setw(10) << "Position";
			foreColor(5); cout << setw(12) << "Username";
			foreColor(6); cout << setw(10) << "Password";
			//////////////////////////////
			foreColor(7); cout << "\n\n\t\t\t\t  ";
			for(int i = 1; i <= 72; i++){
				cout << "=";
			}
		}
		
		void _displayUserAccount(){
			
			cout << "\n\t\t\t\t     " << left;
			foreColor(2); cout << setw(9) << id; 
			foreColor(3); cout << setw(25) << fullname;
			foreColor(4); cout << setw(10) << position;
			foreColor(5); cout << setw(12) << username;
			foreColor(6); cout << setw(10) << password;
			//////////////////////////////
			foreColor(7); cout << "\n\n\t\t\t\t  ";
			for(int i = 1; i <= 72; i++){
				cout << "=";
			}
			
		}
		void _viewInfoSearch(){
			
			cout << fixed << setprecision(2);
			drawBoxDoubleLineWithBG(40, 4, 75, 20, 199);
			drawBoxDoubleLineWithBG(41, 5, 73, 19, 87);
			drawBoxDoubleLineWithBG(60, 4, 32, 1, 67);
			foreColor(23); gotoxy(60,5); cout <<" <<|| Employee Information ||>> ";
			drawBoxDoubleLineWithBG(42, 7, 34, 16, 121); // personal Column
			drawBoxDoubleLineWithBG(42, 7, 34, 1, 121); // personal Column title
			gotoxy(49,8); cout << "Personal Information";
			drawBoxDoubleLineWithBG(43, 9, 32, 4, 121);
			drawBoxDoubleLineWithBG(43, 9, 32, 1, 121);
			gotoxy(54, 10); cout << "Full Name";
			drawBoxDoubleLineWithBG(43, 11, 32, 1, 121);
			gotoxy(44, 12); cout << fullname;
			gotoxy(43, 16); cout << "Gender        : " << gender;
			gotoxy(43, 18); cout << "Date of birth : " << dob;
			gotoxy(43, 20); cout << "Nationality   : " << nation;
			gotoxy(43, 22); cout << "Phone Number  : " << phonN;
			drawBoxDoubleLineWithBG(79, 7, 34, 10, 30); // employee Columns
			drawBoxDoubleLineWithBG(80, 7, 32, 1, 30); // employee Column
			gotoxy(87,8); cout << "Employee Information";
			gotoxy(80, 11); cout << "Identity Docum : " << id;
			gotoxy(80, 13); cout << "Position       : " << position;
			gotoxy(80, 15); cout << "Start work     : " << start_work;
			gotoxy(80, 17); cout << "Salary         : ";
			drawBoxDoubleLineWithBG(97, 16, 16, 1, 30);
			gotoxy(99, 17); cout << "$" << salary;
			drawBoxDoubleLineWithBG(79, 19, 34, 4, 150); // user acc Column
			HLine(79, 20, 15, 150, '-');
			gotoxy(80, 19); cout << "User account";
			gotoxy(84, 21); cout << "Username : " << username;
			gotoxy(84, 23); cout << "Password : " << password;
		}
};

// initial object 
staff _stf, _stfCheck;
fstream file_stf;

bool isFile_Douplicate2(int Dou_id){
	
	file_stf.open("data\\staff.bin", ios::in | ios::binary);
	while(file_stf.eof() != true){
		file_stf.read((char*)&_stfCheck.id, sizeof(_stfCheck.id));
		if(_stfCheck.id == Dou_id){
			file_stf.close();
			return true;
		}
			
	}
	file_stf.close();
	return false;
	
}

void _RegisterStaffInfo(){
	
	_stf._register_staff_info();
	
	if(_stf.isFileExistS("data\\staff.bin")){
		if(!isFile_Douplicate2(_stf.id)){
			
			file_stf.open("data\\staff.bin", ios::out | ios::app | ios::binary);
			file_stf.write((char*)&_stf, sizeof(staff));
			file_stf.close();
		}
		else{
			setcursor(false, 0);
			foreColor(7);
			cls();
			drawBoxDoubleLineWithBG(53, 10, 30, 1, 4);
			gotoxy(54,11); cout << "Sorry! ID Staff already taken";
		}
		
	}
	
	else{
		mkdir("data");
		file_stf.open("data\\staff.bin", ios::out | ios::binary);
		file_stf.write((char*)&_stf, sizeof(staff));
		file_stf.close();
	}
	
}

void _viewAllInfo(){
	
	file_stf.open("data\\staff.bin", ios::in | ios::binary);
	if(file_stf.fail()){
		foreColor(7);
		cls();
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "File not found";
	}
	if(file_stf.good()){
		
		staff::_StffHeaderInfo();
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			_stf._displayAllInfo();
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		
	}
	file_stf.close();
}

void _viewUserAcc(){
	
	file_stf.open("data\\staff.bin", ios::in | ios::binary);
	if(file_stf.fail()){
		foreColor(7);
		cls();
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "File not found";
	}
	if(file_stf.good()){
		
		staff::_displayUserAccHeader();
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			_stf._displayUserAccount();
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		
	}
	file_stf.close();
	
}

void _searchStaffInfo(){
	
	file_stf.open("data\\staff.bin", ios::in | ios::binary);
	if(file_stf.fail()){
		cls();
		setcursor(false, 0);
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "File not found";
	}
	
	if(file_stf.good()){
		
		int SearchID;
		bool isFoundStaff;
		
		cout << "Enter ID to search : ";
		cin >> SearchID; fflush(stdin); cin.clear();
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			if(SearchID == _stf.id){
				cls();
				_stf._viewInfoSearch();
				isFoundStaff = true;
			}
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		if(!isFoundStaff){
			cout << "Identity document's staff invalid! ";
		}
	}
	file_stf.close();
}

void _updatePerInfo(){
	
	file_stf.open("data\\staff.bin", ios::in | ios::out | ios::binary);
	if(file_stf.fail()){
		foreColor(7);
		cls();
		setcursor(false, 0);
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "File not found";
	}
	if(file_stf.good()){
		
		int searchBar;
		bool isPERupdate;
		setcursor(true, 20);
		drawBoxDoubleLineWithBG(50, 4, 40, 3, 23);
		drawBoxSingleLineWithBG(52, 5, 36, 1, 23);
		gotoxy(55, 6); cout << "Enter Id for update : "; 
		cin >> searchBar; fflush(stdin); cin.clear();
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			
			if(searchBar == _stf.id){
				int lastbytes = file_stf.tellg();
				_stf._formUpdatePerInfo();
				file_stf.seekp(lastbytes - sizeof(staff));
				file_stf.write((char*)&_stf, sizeof(staff));
				isPERupdate = true;
			}
			
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		
		if(isPERupdate == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxSingleLineWithBG(52, 8, 36, 1, 23);
			gotoxy(58, 9); cout << "Wrong Identity document";
			
		}
		if(isPERupdate == true){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(67, 27, 20, 1, 39);
			gotoxy(68, 28); cout << "Updated success!!!";
			
		}
	}
	
	file_stf.close();
}
void _updateStaffInfo(){
	
	file_stf.open("data\\staff.bin", ios::in | ios::out | ios::binary);
	if(file_stf.fail()){
		foreColor(7);
		cls();
		setcursor(false, 0);
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "File not found";
	}
	if(file_stf.good()){
		
		int searchBar;
		bool isPERupdate;
		setcursor(true, 20);
		drawBoxDoubleLineWithBG(50, 4, 40, 3, 23);
		drawBoxSingleLineWithBG(52, 5, 36, 1, 23);
		gotoxy(55, 6); cout << "Enter Id for update : "; 
		cin >> searchBar; fflush(stdin); cin.clear();
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			
			if(searchBar == _stf.id){
				int lastbytes = file_stf.tellg();
				_stf._formUpdateStaffInfo();
				file_stf.seekp(lastbytes - sizeof(staff));
				file_stf.write((char*)&_stf, sizeof(staff));
				isPERupdate = true;
			}
			
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		
		if(isPERupdate == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxSingleLineWithBG(52, 8, 36, 1, 23);
			gotoxy(58, 9); cout << "Wrong Identity document";
			
		}
		if(isPERupdate == true){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(67, 23, 20, 1, 39);
			gotoxy(68, 24); cout << "Updated success!!!";
			
		}
	}
	
	file_stf.close();
}

void _forgetUserAccount(){
	
	file_stf.open("data\\staff.bin", ios::in | ios::out | ios::binary);
	if(file_stf.fail()){
		foreColor(7);
		cls();
		setcursor(false, 0);
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "file not found";
	}
	if(file_stf.good()){
		
		int searchBar;
		bool isPERupdate;
		setcursor(true, 20);
		drawBoxDoubleLineWithBG(50, 4, 40, 3, 23);
		drawBoxSingleLineWithBG(52, 5, 36, 1, 23);
		gotoxy(55, 6); cout << "Enter Id for update : "; 
		cin >> searchBar; fflush(stdin); cin.clear();
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			
			if(searchBar == _stf.id){
				int lastbytes = file_stf.tellg();
				_stf._form_forgetStaffAccount();
				file_stf.seekp(lastbytes - sizeof(staff));
				file_stf.write((char*)&_stf, sizeof(staff));
				isPERupdate = true;
			}
			
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		
		if(isPERupdate == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxSingleLineWithBG(52, 8, 36, 1, 23);
			gotoxy(58, 9); cout << "Wrong Identity document";
			
		}
		if(isPERupdate == true){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(60, 17, 35, 1, 39);
			gotoxy(63, 18);cout << "Change user account success!!!";
			
		}
	}
	
	file_stf.close();
	
}

void _StaffResignation(){
	
	ofstream _fileBackup;
	file_stf.open("data\\staff.bin",ios::in | ios::binary);
	_fileBackup.open("data\\staffBackup.bin",ios::out | ios::binary);
	
	if(file_stf.fail()){
		foreColor(7);
		cls();
		setcursor(false, 0);
		drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
		foreColor(4); gotoxy(65,11); 
		cout << "File not found";
	}
	if(file_stf.good()){
		int deleteid;
		bool isDeleted;
		setcursor(true, 20);
		drawBoxDoubleLineWithBG(40, 2, 70, 24, 70);
		drawBoxDoubleLineWithBG(42, 3, 66, 10, 70);
		drawBoxDoubleLineWithBG(50, 2, 50, 1, 70);
		gotoxy(63, 3); cout << "Resignation conditions";
		gotoxy(46, 6); cout << " - Many employment contracts specify a notice period "; 
		gotoxy(47, 7); cout << "   that an employee must provide before resigning. ";
		gotoxy(47, 8); cout << "   This allows the employer time to find a replacement.";
		gotoxy(46, 10); cout << " - Resignation conditions often include returning any "; 
		gotoxy(47, 11); cout << "   company property, such as laptops, access cards, ";
		gotoxy(47, 12); cout << "   or other equipment, upon departure.";
		drawBoxDoubleLineWithBG(42, 15, 66, 10, 70);
		drawBoxDoubleLineWithBG(44, 16, 62, 2, 70);
		gotoxy(44, 17); cout << "   If you already check and make sure for 2 conditions at the-";
		gotoxy(44, 18); cout << " top you can resign for employee. Good luck!!! (bro/sis)";
		drawBoxDoubleLineWithBG(44, 21, 62, 1, 70);
		foreColor(71); gotoxy(45, 22); cout << "Enter id to resignation staff from our shop :: "; 
		cin >> deleteid; fflush(stdin); cin.clear(); 
		
		file_stf.read((char*)&_stf, sizeof(staff));
		while(file_stf.eof() != true){
			
			if(deleteid == _stf.id){
				isDeleted = true;
			}
			if(deleteid != _stf.id){
				_fileBackup.write((char*)&_stf, sizeof(staff));
			}
			file_stf.read((char*)&_stf, sizeof(staff));
		}
		if(isDeleted == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			foreColor(68); gotoxy(63, 25);  cout << "Wrong identity document";
		}
		if(isDeleted == true){
			foreColor(7);
			cls();
			setcursor(false, 0);
			foreColor(74); gotoxy(65, 25); cout << "Resigned successfully";
		}
		
	}
	file_stf.close();
	_fileBackup.close();
	
	remove("data\\staff.bin");
	rename("data\\staffBackup.bin", "data\\staff.bin");
}

///////////////////////
#endif