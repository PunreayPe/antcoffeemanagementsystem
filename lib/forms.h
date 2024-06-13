#ifndef ___FORMS_H___
#define ___FORMS_H___
//////////////////////////////////
#include "antheaderPlusPlus.h"
//////////////////////////////////

class Forms{
	
	public:
		void UIMain(){
			setcursor(false, 0);
			// right design
			drawBoxDoubleLineWithBG(37, 6, 1, 15, 55);
			drawBoxDoubleLineWithBG(40, 3, 1, 19, 151);
			// center
			drawBoxDoubleLineWithBG(43, 1, 60, 23, 39);
			drawBoxDoubleLineWithBG(44, 2, 58, 21, 39);
			// left design
			drawBoxDoubleLineWithBG(105, 3, 1, 19, 151);
			drawBoxDoubleLineWithBG(108, 6, 1, 15, 55);
			drawBoxDoubleLineWithBG(45, 3, 56, 1, 39);// header box
			gotoxy(46,4); cout << "A N T  C O F F E E  M A N A G E M E N T S  S Y S T E M";	// content
			foreColor(47); gotoxy(54,7); cout << "Welcome to Ant Coffee Management System";
			drawBoxDoubleLineWithBG(50, 9, 46, 1, 46);// admin box
			foreColor(39); gotoxy(56,10); cout << " [1] ==> Login as A D M I N <==";
			drawBoxDoubleLineWithBG(50, 12, 46, 1, 35);// staff box
			foreColor(39); gotoxy(56,13); cout << " [2] ==> Login as S T A F F <==";
			drawBoxDoubleLineWithBG(50, 15, 46, 1, 39);// About dev
			foreColor(39); gotoxy(56,16); cout << " [3] - A B O U T  D E V E L O P E R";
			drawBoxDoubleLineWithBG(50, 18, 46, 1, 44);// Exit
			foreColor(39); gotoxy(56,19); cout << " [4] - E X I T  P R O G R A M";
			foreColor(43); gotoxy(53,22); cout << "Choosing any option just click by number";
		}
		
		void AdminControlUI(){
			
			drawBoxDoubleLineWithBG(30, 5, 80, 18, 27);
			drawBoxDoubleLineWithBG(32, 6, 76, 16, 27);
			drawBoxSingleLineWithBG(50, 7, 39, 1, 27);
			gotoxy(52,8); cout << " =|=| A D M I N  C O N T R O L |=|=";
			drawBoxDoubleLineWithBG(33, 12, 35, 3, 55);
			gotoxy(34,14); cout << "|==|[1]. | PRODUCTS CONTROL |==|";
			drawBoxDoubleLineWithBG(72, 12, 35, 3, 103);
			gotoxy(73,14); cout << "|==|[2]. | EMPLOYEES CONTROL |==|";
			drawBoxDoubleLineWithBG(54, 18, 35, 1, 71);
			gotoxy(59,19); cout << "|==|[3]. | LOGOUT |==|";
			foreColor(30); gotoxy(56,22); cout << "Please follow number into option";
			
		}
		
		void ProductControlUI(){
			
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(35, 1, 80, 25, 23);
			drawBoxDoubleLineWithBG(37, 2, 76, 23, 55);
		// title
			drawBoxDoubleLineWithBG(60, 3, 31, 1, 55);
			drawBoxDoubleLineWithBG(48, 3, 10, 1, 55);
			drawBoxDoubleLineWithBG(93, 3, 10, 1, 55);
			gotoxy(60, 4); cout << "P R O D U C T S  C O N T R O L ";
			gotoxy(51, 4); cout << "A N T";
			gotoxy(95, 4); cout << "A N T";
		// right menu
			drawBoxDoubleLineWithBG(40, 6, 31, 1, 39);
			gotoxy(41, 7); cout << "   [0] - Revenue";
			drawBoxDoubleLineWithBG(40, 9, 31, 1, 87);
			gotoxy(41, 10); cout << "   [2] - Import Stock";
			drawBoxDoubleLineWithBG(40, 12, 31, 1, 183);
			gotoxy(41, 13); cout << "   [4] - Search Product";
			drawBoxDoubleLineWithBG(40, 15, 31, 1, 103);
			gotoxy(41, 16); cout << "   [6] - Remove Product";
			drawBoxDoubleLineWithBG(40, 18, 31, 1, 199);
			gotoxy(41, 19); cout << "   [8] - View invoice history";
			/*column devide menu*/
			int col = 1;
			foreColor(55); gotoxy(74, 6); cout << "||";
			for(int i = 1; i<=15; i++){
				gotoxy(74, 6+col); cout << "||";
				col++;
			}
		// left menu
			drawBoxDoubleLineWithBG(79, 6, 31, 1, 39);
			gotoxy(80, 7); cout << "   [1] - Register Product";
			drawBoxDoubleLineWithBG(79, 9, 31, 1, 87);
			gotoxy(80, 10); cout << "   [3] - View all Products";
			drawBoxDoubleLineWithBG(79, 12, 31, 1, 183);
			gotoxy(80, 13); cout << "   [5] - Update Product";
			drawBoxDoubleLineWithBG(79, 15, 31, 1, 103);
			gotoxy(80, 16); cout << "   [7] - Sale Product";
			drawBoxDoubleLineWithBG(79, 18, 31, 1, 199);
			gotoxy(80, 19); cout << "   [9] - Sort items ";
			drawBoxDoubleLineWithBG(53, 22, 42, 1, 71);
			gotoxy(55, 23); cout << "Press [-] Minus sign back to main menu ";
			foreColor(56); gotoxy(56, 25); cout << "Please press following the option key";
			
		}
		
		void StaffControlUI(){
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(45, 1, 60, 20, 23);
			drawBoxDoubleLineWithBG(46, 2, 58, 18, 103);
			drawBoxDoubleLineWithBG(55, 3, 5, 1, 103);
			drawBoxDoubleLineWithBG(61, 3, 30, 1, 103);
			drawBoxDoubleLineWithBG(66, 3, 18, 1, 103);
			drawBoxDoubleLineWithBG(90, 3, 5, 1, 103);
			gotoxy(59, 4); cout << "E M P L O Y E E S  C O N T R O L";
			// right menu
			drawBoxDoubleLineWithBG(47, 7, 26, 1, 103);
			gotoxy(48, 8); cout << "[1] - Register Staff";
			drawBoxDoubleLineWithBG(47, 10, 26, 1, 103);
			gotoxy(48, 11); cout << "[3] - Search info staff";
			drawBoxDoubleLineWithBG(47, 13, 26, 1, 103);
			gotoxy(48, 14); cout << "[5] - Resignation";
			// left menu
			drawBoxDoubleLineWithBG(77, 7, 26, 1, 103);
			gotoxy(78, 8); cout << "[2] - View";
			drawBoxDoubleLineWithBG(77, 10, 26, 1, 103);
			gotoxy(78, 11); cout << "[4] - Update";
			drawBoxDoubleLineWithBG(77, 13, 26, 1, 103);
			gotoxy(78, 14); cout << "[6] - Back to main menu";
			gotoxy(51, 18); cout << "View and Update it's have more sub menu in there";
			gotoxy(47, 19); cout << "Resignation option it's about for remove staff from list";
			
		}
		
		void StaffMenu(){
			drawBoxDoubleLineWithBG(35, 1, 80, 21, 23);
			drawBoxDoubleLineWithBG(37, 2, 76, 19, 55);
			// title
			drawBoxDoubleLineWithBG(60, 3, 31, 1, 151);
			drawBoxDoubleLineWithBG(48, 3, 10, 1, 201);
			drawBoxDoubleLineWithBG(93, 3, 10, 1, 201);
			foreColor(151); gotoxy(66, 4); cout << "S T A F F  M E N U ";
			foreColor(201); gotoxy(51, 4); cout << "A N T";
			foreColor(201); gotoxy(95, 4); cout << "A N T";
			// Menu right
			drawBoxDoubleLineWithBG(48, 8, 26, 1, 23);
			gotoxy(49, 9); cout << "[1]-Sale product";
			drawBoxDoubleLineWithBG(48, 11, 26, 1, 39);
			gotoxy(49, 12); cout << "[3]-Search products";
			drawBoxDoubleLineWithBG(48, 14, 26, 1, 87);
			gotoxy(49, 15); cout << "[5]-View Revenue";
			// Menu left
			drawBoxDoubleLineWithBG(77, 8, 26, 1, 135);
			gotoxy(78, 9); cout << "[2]-View all products";
			drawBoxDoubleLineWithBG(77, 11, 26, 1, 103);
			gotoxy(78, 12); cout << "[4]-View invoice history";
			drawBoxDoubleLineWithBG(77, 14, 26, 1, 71);
			gotoxy(78, 15); cout << "[6]-Logout";
			// fill for username staff after login
//			drawBoxDoubleLineWithBG(40, 19, 30, 1, 55);
//			gotoxy(41,20); cout << "Staff name: ";
//			drawBoxDoubleLineWithBG(80, 19, 30, 1, 55);
//			gotoxy(81,20); cout << "Logged at: ";
		}
		
		void ViewStaffPanelUI(){
			setcursor(false,0);
			drawBoxDoubleLineWithBG(40, 3, 70, 18, 219);
			drawBoxDoubleLineWithBG(42, 4, 66, 16, 222);
			drawBoxDoubleLineWithBG(60, 5, 30, 1, 217);
			foreColor(223); gotoxy(62, 6); cout << "View Employees Info Panel";
			drawBoxDoubleLineWithBG(55, 10, 39, 1, 223);
			gotoxy(58, 11); cout << "[1]. - View all info staff";
			drawBoxDoubleLineWithBG(55, 13, 39, 1, 223);
			gotoxy(58, 14); cout << "[2]. - View user account";
			drawBoxDoubleLineWithBG(55, 16, 39, 1, 223);
			gotoxy(58, 17); cout << "[3]. - Back to menu";
		}
		
		void SearchProductPanel(){
			setcursor(false,0);
			drawBoxDoubleLineWithBG(40, 3, 70, 18, 55);
			drawBoxDoubleLineWithBG(42, 4, 66, 16, 38);
			drawBoxDoubleLineWithBG(60, 5, 30, 1, 38);
			foreColor(38); gotoxy(62, 6); cout << "Search Product Info Panel";
			drawBoxDoubleLineWithBG(55, 10, 39, 1, 38);
			gotoxy(58, 11); cout << "[1]. - Search product by Barcode";
			drawBoxDoubleLineWithBG(55, 13, 39, 1, 38);
			gotoxy(58, 14); cout << "[2]. - Search product by Category";
			drawBoxDoubleLineWithBG(55, 16, 39, 1, 71);
			gotoxy(58, 17); cout << "[3]. - Back to menu";
		}
		
		void UpdateStaffPanelUI(){
			
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(40, 3, 70, 18, 155);
			drawBoxDoubleLineWithBG(42, 4, 66, 16, 154);
			drawBoxDoubleLineWithBG(60, 5, 30, 1, 151);
			foreColor(159); gotoxy(62, 6); cout << "Update Employees Info Panel";
			drawBoxDoubleLineWithBG(55, 9, 40, 1, 151);
			gotoxy(58, 10); cout << "[1]. - Update Personal information";
			drawBoxDoubleLineWithBG(55, 12, 40, 1, 151);
			gotoxy(58, 13); cout << "[2]. - Update staff information";
			drawBoxDoubleLineWithBG(55, 15, 40, 1, 151);
			gotoxy(58, 16); cout << "[3]. - Change username and password";
			drawBoxDoubleLineWithBG(55, 18, 40, 1, 151);
			gotoxy(58, 19); cout << "[4]. - Back to menu";
			
		}
		
};

//////////////////////////////////
#endif