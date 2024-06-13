#ifndef ___Utilities_H___
#define ___Utilities_H___
//////////////////////////////////
#include <fstream>
#include "antheaderPlusPlus.h"
#include "antheaderInput.h"
#include "staff.h"
//////////////////////////////////
//////////////////////////////////

class loadingScreens{
	
	public: 
		void LoadingADMINScreen(){
			setcursor(false, 0);
			
			foreColor(3); gotoxy(40, 6); cout << R"(
											   	   ADMIN
					  ____  ____   ______         __   ___   _____  _____  ___    ___ 
					 /    ||    \ |      |       /  ] /   \ |     ||     |/  _]  /  _]
					|  o  ||  _  ||      |      /  / |     ||   __||   __/  [_  /  [_ 
					|     ||  |  ||_|  |_|     /  /  |  O  ||  |_  |  |_|    _]|    _]
					|  _  ||  |  |  |  |      /   \_ |     ||   _] |   _]   [_ |   [_ 
					|  |  ||  |  |  |  |      \     ||     ||  |   |  | |     ||     |
					|__|__||__|__|  |__|       \____| \___/ |__|   |__| |_____||_____|
								
								Welcome to ANT Coffee Managements System	                                                                                                                                                                                         
			)";
		
			gotoxy(41, 20); cout << "Loading...";
			char x = 219;
			foreColor(2); gotoxy(41, 18);
			for(int i = 0; i <= 63; i++){
				Sleep(35);
				cout << x;
			}
		}
		
		void LoadingSorting(){
			
			setcursor(false, 0);
			foreColor(3); gotoxy(40, 6); cout << R"(
					

					 _______  _______ _________ _______ __________________ _        _______          
					(  ____ \(  ___  )\__   __/(  ____ )\__   __/\__   __/( (    /|(  ____ \         
					| (    \/| (   ) |   ) (   | (    )|   ) (      ) (   |  \  ( || (    \/        
					| (_____ | |   | |   | |   | (____)|   | |      | |   |   \ | || |               
					(_____  )| |   | |   | |   |     __)   | |      | |   | (\ \) || | ____          
					      ) || |   | |   | |   | (\ (      | |      | |   | | \   || | \_  )         
					/\____) || (___) |   | |   | ) \ \__   | |   ___) (___| )  \  || (___) | _  _  _ 
					\_______)(_______)   )_(   |/   \__/   )_(   \_______/|/    )_)(_______)(_)(_)(_)

                                          
			)";
		
			gotoxy(41, 20); cout << "Loading...";
			char x = 219; 
			foreColor(3); gotoxy(41, 18);
			for(int i = 0; i <= 60; i++){
				Sleep(50);
				cout << x;
			}
			
		}
		
		void LoadingStaffScreen(){
			setcursor(false, 0);
			
			foreColor(4); gotoxy(40, 6); cout << R"(
											   	    STAFF
					  ____  ____   ______         __   ___   _____  _____  ___    ___ 
					 /    ||    \ |      |       /  ] /   \ |     ||     |/  _]  /  _]
					|  o  ||  _  ||      |      /  / |     ||   __||   __/  [_  /  [_ 
					|     ||  |  ||_|  |_|     /  /  |  O  ||  |_  |  |_|    _]|    _]
					|  _  ||  |  |  |  |      /   \_ |     ||   _] |   _]   [_ |   [_ 
					|  |  ||  |  |  |  |      \     ||     ||  |   |  | |     ||     |
					|__|__||__|__|  |__|       \____| \___/ |__|   |__| |_____||_____|
								
								Welcome to ANT Coffee Managements System	                                                                                                                                                                                         
			)";
		
			gotoxy(41, 20); cout << "Loading...";
			char x = 219;
			foreColor(4); gotoxy(41, 18);
			for(int i = 0; i <= 63; i++){
				Sleep(35);
				cout << x;
			}
		}
		
		void LoadingExit(){
			
			setcursor(false, 0);
			foreColor(4); gotoxy(40, 6); cout << R"(
					
					
					
							  ______      _ _   _                   
							 |  ____|    (_) | (_)                  
							 | |__  __  ___| |_ _ _ __   __ _       
							 |  __| \ \/ / | __| | '_ \ / _` |      
							 | |____ >  <| | |_| | | | | (_| |_ _ _ 
							 |______/_/\_\_|\__|_|_| |_|\__, (_|_|_)
							                             __/ |      
							                            |___/       
							                    
												        
							                                                            
			)";
		
			gotoxy(57, 21); cout << "Loading...";
			char x = 219; 
			foreColor(4); gotoxy(57, 19);
			for(int i = 0; i <= 38; i++){
				Sleep(100);
				cout << x;
			}
			
		}
		
};

class tools{
	
	public:
		//
		void FullScreen(){
  			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		    CONSOLE_SCREEN_BUFFER_INFOEX csbi;
		    csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		    GetConsoleScreenBufferInfoEx(hOut, &csbi);
		    csbi.dwSize.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		    csbi.dwSize.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		    csbi.dwMaximumWindowSize.X = csbi.dwSize.X;
		    csbi.dwMaximumWindowSize.Y = csbi.dwSize.Y;
		    SetConsoleScreenBufferInfoEx(hOut, &csbi);
		    HWND hwnd = GetConsoleWindow();
		    ShowWindow(hwnd, SW_MAXIMIZE);
		}
	
	char* getCurrentDate() { 
		time_t now = time(0);
		struct tm* timeinfo = localtime(&now);
		static char _recordtime[50];
		strftime(_recordtime, sizeof(_recordtime), "%d/%m/%Y | %H:%M:%S", timeinfo);
		return _recordtime;
	}
	
	
};

class helper{
	
	public:
		void _DialogMessage(string ms_Title, string ms_Detail, string ms_tryAgain, int color){
			
			drawBoxDoubleLineWithBG(45, 5, 50, 12, color);	
			gotoxy(46, 5); cout << ms_Title;
			drawBoxDoubleLineWithBG(48, 7, 43, 3, color);	
			drawBoxDoubleLineWithBG(52, 8, 35, 1, color);	
			gotoxy(53, 9); cout << ms_Detail;
			drawBoxDoubleLineWithBG(48, 12, 43, 3, color);	
			drawBoxDoubleLineWithBG(52, 13, 35, 1, color);	
			gotoxy(53, 14); cout << ms_tryAgain;
			delay(1500);
		}
		
		void MessageFileError(string Message, int color){
			cls();
			drawBoxDoubleLineWithBG(62, 10, 20, 1, color);
			foreColor(color); gotoxy(63,11); 
			cout << Message;
				
		}
		
		bool loginAdmin(){
			
//			string admin, pass;
			drawBoxDoubleLineWithBG(43, 3, 60, 17, 249);
			drawBoxDoubleLineWithBG(45, 4, 56, 15, 142);
			drawBoxDoubleLineWithBG(58, 5, 29, 1, 142);
			gotoxy(60,6); cout << "L O G I N  A S  A D M I N";
			drawBoxDoubleLineWithBG(47, 5, 7, 13, 249);
			int col = 6;
			gotoxy(50,col); cout << "A";
			gotoxy(50,col+2); cout << "N";
			gotoxy(50,col+4); cout << "T";
			gotoxy(50,col+6); cout << "C";
			gotoxy(50,col+8); cout << "A";
			gotoxy(50,col+10); cout << "F";
			gotoxy(50,col+12); cout << "E";
			drawBoxDoubleLineWithBG(92, 5, 7, 13, 249);
			gotoxy(95,col); cout << "A";
			gotoxy(95,col+2); cout << "N";
			gotoxy(95,col+4); cout << "T";
			gotoxy(95,col+6); cout << "C";
			gotoxy(95,col+8); cout << "A";
			gotoxy(95,col+10); cout << "F";
			gotoxy(95,col+12); cout << "E";
			
			setcursor(true, 20);
			string admin, pass;
			drawBoxDoubleLineWithBG(57, 9, 32, 1, 135);
			gotoxy(60, 10); cout << "Username : ";
			gotoxy(72, 10); cin >> admin; fflush(stdin);			
			drawBoxDoubleLineWithBG(57, 13, 32, 1, 135);
			gotoxy(60, 14); cout << "Password : ";
			gotoxy(72, 14); pass = hidePassword(pass); fflush(stdin);
			
			if (admin == "admin" && pass == "1234") {
			    setcursor(false, 0);
			    foreColor(130); gotoxy(65, 17); cout << "LOGIN SUCCESSFUL";
			    delay(1200);
			    return true;
			    cls();
			}
			else {
			    setcursor(false, 0);
			    foreColor(132);
			    gotoxy(63, 17);
			    if (admin != "admin" && pass == "1234") {
			        cout << "Incorrect username";
			    }
			    else if(admin == "admin" && pass != "1234"){
			        cout << "Incorrect password";
			    }
			    else{
			    	gotoxy(58, 17); cout << "Incorrect Username and Password";	
				}
			    delay(1500);
			    cls();
			}
			
			return false;

			
//			drawBoxDoubleLineWithBG(57, 9, 32, 1, 135);
//			gotoxy(60,10); cout << "Username : ";
//			gotoxy(72,10); cin >> admin; fflush(stdin);
//			drawBoxDoubleLineWithBG(57, 13, 32, 1, 135);
//			gotoxy(60,14); cout << "Password : ";
//			gotoxy(72,14); pass = hidePassword(pass); fflush(stdin);
//			
//			if(admin == "admin" && pass == "1234"){
//				setcursor(false, 0);
//				foreColor(130); gotoxy(65,17); cout << "LOGIN SUCCESSFUL";
//				delay(1200);
//				// before return this value we're must alert message to user
//				return true;
//				cls();
//			}
//			else{
//				setcursor(false, 0);
//				foreColor(132); gotoxy(58,17); cout << "Incorrect password or username";
//				delay(1500);
//				cls();
//			}
//			return false;
		}
		
		bool loginStaff(){
			setcursor(true, 20);
			ifstream _fileUser;
			char _userStaff[20], password[5];
			bool isFound = false;
			
			_fileUser.open("data\\staff.bin", ios::in | ios::binary);
			if(_fileUser.fail()){
				isFound = false;
			}else{
				drawBoxDoubleLineWithBG(43, 3, 60, 17, 55);
				drawBoxDoubleLineWithBG(45, 4, 56, 15, 55);
				drawBoxDoubleLineWithBG(58, 5, 29, 1, 55);
				gotoxy(60,6); cout << "L O G I N  A S  S T A F F";
				drawBoxDoubleLineWithBG(47, 5, 7, 13, 55);
				int col = 6;
				gotoxy(50,col); cout << "A";
				gotoxy(50,col+2); cout << "N";
				gotoxy(50,col+4); cout << "T";
				gotoxy(50,col+6); cout << "C";
				gotoxy(50,col+8); cout << "A";
				gotoxy(50,col+10); cout << "F";
				gotoxy(50,col+12); cout << "E";
				drawBoxDoubleLineWithBG(92, 5, 7, 13, 55);
				gotoxy(95,col); cout << "A";
				gotoxy(95,col+2); cout << "N";
				gotoxy(95,col+4); cout << "T";
				gotoxy(95,col+6); cout << "C";
				gotoxy(95,col+8); cout << "A";
				gotoxy(95,col+10); cout << "F";
				gotoxy(95,col+12); cout << "E";
				
				drawBoxDoubleLineWithBG(57, 9, 32, 1, 55);
				gotoxy(60,10); cout << "Username : ";
				gotoxy(72,10); cin >> _userStaff; fflush(stdin);
				drawBoxDoubleLineWithBG(57, 13, 32, 1, 55);
				gotoxy(60,14); cout << "Password : ";
				gotoxy(72,14); hidePassword(password); fflush(stdin);
				
				_fileUser.read((char*)&_stf, sizeof(staff));
				while(_fileUser.eof() != true){
					if(!strcmp(_userStaff, _stf.username) && !strcmp(password, _stf.password)){
						isFound = true;
						break;
					}
					_fileUser.read((char*)&_stf, sizeof(staff));
				}
				if(isFound == true){
					setcursor(false, 0);
					foreColor(58); gotoxy(65,17); cout << "LOGIN SUCCESSFUL";
					delay(1200);
					
					cls();
				}else {
					setcursor(false, 0);
					foreColor(52); gotoxy(58,17); cout << "Incorrect password or username";
					delay(1500);
					isFound = false;
					cls();
				}
			}
			_fileUser.close();
			return isFound;
		}
};

//////////////////////////////////
#endif