#ifndef ___STOCK_H___
#define ___STOCK_H___
///////////////////////
#include "antheaderPlusPlus.h"
#include "utilities.h"
#include <fstream>
///////////////////////
helper _hp;
class stock{
	
	public:
		int barcode;
		char name[30];
		char unit[10];
		char category[30];
		int qty = 0;
		double price;
		
	public:
		
		double getAmount() const {
			return qty * price;
		}
		
		bool isFileExist(const char* fileName){
			fstream infile(fileName);
			return infile.good();
		}
		
	public: 
		static void header(){
			cout << left;
			gotoxy(22, 2); foreColor(6); cout << setw(15) << "Barcode";
			foreColor(2); cout << setw(20) << "Item";                  
			foreColor(7); cout << setw(10) << "Unit";
			foreColor(5); cout << setw(20) << "Category";
			foreColor(3); cout << setw(15) << "Quantity";
			foreColor(11); cout << setw(15) << "Price";
			foreColor(14); cout << setw(10) << "Total";
			cout << endl;
		}
		
	public:
	
		void RegisterProduct(){
				
				setcursor(true, 20);
				drawBoxDoubleLineWithBG(40, 3, 70, 25, 142);
				drawBoxDoubleLineWithBG(42, 4, 66, 23, 142);
				drawBoxDoubleLineWithBG(57, 5, 37, 1, 142);
				gotoxy(60,6); cout << "R E G I S T E R  P R O D U C T";
				
				drawBoxDoubleLineWithBG(50, 10, 50, 1, 142);
				gotoxy(52, 11); cout << "Register Barcode of Product: ";
				cin >> barcode; fflush(stdin); cin.clear();
				
				drawBoxDoubleLineWithBG(50, 13, 50, 1, 142);
				do {
				    backtoinputname:
				    gotoxy(52, 14); cout << "Register Name of Product   : ";
				    cin.get(name, 30); fflush(stdin); cin.clear();
				    if (strlen(name) == 0) {
				        goto backtoinputname;
				    }
				} while (strlen(name) == 0);
				drawBoxDoubleLineWithBG(50, 16, 50, 1, 142);
				do {
				    backtoinputunit:
				    gotoxy(52, 17); cout << "Register Unit of Product: ";
				    cin.get(unit, 10); fflush(stdin); cin.clear();
				    if (strlen(unit) == 0) {
				        goto backtoinputunit;
				    }
				} while (strlen(unit) == 0);
				drawBoxDoubleLineWithBG(50, 19, 50, 1, 142);
				do {
				    backtoinputcategory:
					gotoxy(52, 20); cout << "Register Category of Product: ";
					cin.get(category,30); fflush(stdin); cin.clear();
				    if (strlen(category) == 0) {
				        goto backtoinputcategory;
				    }
				} while (strlen(category) == 0);
				drawBoxDoubleLineWithBG(50, 22, 50, 1, 142);
				gotoxy(52,23); cout << "Register Price of Product   : $";
				cin >> price; fflush(stdin); cin.clear();
				setcursor(false, 0);
				gotoxy(68, 26); cout << "Saved success";
		}
		
		void ImportStock(){
			int importqty;
			drawBoxDoubleLineWithBG(50, 13, 45, 1, 38);
			gotoxy(50, 14); cout << "Enter Quantity of Product: ";
			cin >> importqty; fflush(stdin); cin.clear();
			qty += importqty;
		}

		void Output(){
			cout << left;
			foreColor(6); cout << setw(15) << barcode;
			foreColor(2); cout << setw(20) << name;
			foreColor(7); cout << setw(10) << unit;
			foreColor(5); cout << setw(20) << category;
			foreColor(3); cout << setw(15);
			if (qty == 0){
				foreColor(12); cout << "Out-of-Stock";
			}
			else{
				foreColor(3); cout << int_string(qty) + " " + unit ;
			}
			cout  << fixed << setprecision(2);
			foreColor(11); cout << setw(1) << "$" << setw(14) << price;
			foreColor(14); cout << setw(1) << "$" << setw(9) << getAmount();
			cout << endl;
		}
	
};
/////////////////////////
stock st_check, st;
fstream file_stock;
/////////////////////////
bool isFile_Douplicate(int bar){
	
	file_stock.open("data\\stock.bin", ios::in | ios::binary);
	while(file_stock.eof() != true){
		file_stock.read((char*)&st_check.barcode, sizeof(st_check.barcode));
		if(st_check.barcode == bar){
			file_stock.close();
			return true;
		}
			
	}
	file_stock.close();
	return false;
}

void _register(){
	
	st.qty = 0;
	st.RegisterProduct();
	
	if(st.isFileExist("data\\stock.bin")){
		
		if(!isFile_Douplicate(st.barcode)){
			
			file_stock.open("data\\stock.bin", ios::out | ios::app | ios::binary);
			file_stock.write((char*)&st, sizeof(stock));
			file_stock.close();
		}
		else{
			foreColor(7);
			cls();
			foreColor(4); gotoxy(49,11); 
			cout << "Sorry Barcode already taken";
			
		}
		
	}
	else{
		
		mkdir("data");
		file_stock.open("data\\stock.bin", ios::out | ios::binary);
		file_stock.write((char*)&st, sizeof(stock));
		file_stock.close();
	}
	
}

void view_data(){
	setcursor(false, 0);
	int Col = 1;
	stock::header();
	file_stock.open("data\\stock.bin", ios::in | ios::binary);
	if(file_stock.fail()){
		_hp.MessageFileError("  File not found", 4);
	}
	
	if(file_stock.good()){
		file_stock.read((char*)&st, sizeof(stock));
		while(file_stock.eof() != true){
			gotoxy(22,3+Col);  st.Output();
			file_stock.read((char*)&st, sizeof(stock));
			Col+=2;
			HLine(21, 2+Col, 105, 3, '=');
		}
		DrawRectangle(20, 1, 107, Col, 3);
		HLine(21, 3, 105, 3, '=');
		DrawRectangle(59, 2+Col, 31, 1, 3);
		gotoxy(62,3+Col); cout << "Press any key to continue";
	}
	file_stock.close();
}

void import_qty(){
	
	int sBarcode;
	bool isFoundBar;
	
	ofstream file_qty;
	file_stock.open("data\\stock.bin", ios::in | ios::binary);
	file_qty.open("data\\stock_backup_qty.bin", ios::out | ios::binary);
	
	if(file_stock.fail()){
		cls();
		setcursor(false, 0);
		drawBoxSingleLineWithBG(50, 10, 40, 1, 4);
		foreColor(4); gotoxy(52,11); 
		cout << "Don't have stock for import qauntity"; 
	}
	
	if(file_stock.good()){
		
		drawBoxDoubleLineWithBG(45, 4, 55, 15, 217);
		drawBoxDoubleLineWithBG(47, 5, 51, 13, 29);
		drawBoxDoubleLineWithBG(50, 7, 45, 1, 87);
		gotoxy(50, 8); cout << "Enter Barcode for import stock : ";
		cin >> sBarcode; fflush(stdin); cin.clear();
		file_stock.read((char*)&st, sizeof(stock));
		
		while(file_stock.eof() != true){
			
			if(sBarcode == st.barcode){
				drawBoxSingleLineWithBG(50, 10, 45, 1, 22);
				gotoxy(52, 11); cout << "Import this product ==> " << st.name ;
				st.ImportStock();
				file_qty.write((char*)&st, sizeof(stock));
				isFoundBar = true;
			}
			if(sBarcode != st.barcode){
				file_qty.write((char*)&st, sizeof(stock));
			}
			
			file_stock.read((char*)&st, sizeof(stock));
		}
		
		if(isFoundBar == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(62, 16, 20, 1, 198);
			gotoxy(64,17); cout << "Please Try again";
		}
		if(isFoundBar == true){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(62, 16, 20, 1, 47);
			gotoxy(65, 17); cout << "Import success";
			foreColor(2); gotoxy(46, 20); cout << "Press any key to import again or Press [ESC] back to menu";
		}	
	}
	file_stock.close();
	file_qty.close();
	
	remove("data\\stock.bin");
	rename("data\\stock_backup_qty.bin", "data\\stock.bin");
}

void sort_by_barcode() {
    file_stock.open("data\\stock.bin", ios::in | ios::out | ios::binary);

    if (!file_stock) {
    	foreColor(7);
		cls();
		setcursor(false, 0);
		drawBoxSingleLineWithBG(50, 10, 40, 1, 4);
		foreColor(4); gotoxy(56,11); 
		cout << "Don't have item for sorting "; 
        return;
    }
    
    file_stock.seekg(0, ios::end);
    int num_records = file_stock.tellg() / sizeof(stock);
    file_stock.seekg(0, ios::beg);

    stock* stocks = new stock[num_records];
    file_stock.read((char*)stocks, sizeof(stock) * num_records);

    for (int i = 0; i < num_records - 1; i++) {
        for (int j = 0; j < num_records - i - 1; j++) {
            if (stocks[j].barcode > stocks[j + 1].barcode) {
                stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }

    file_stock.seekp(0, ios::beg);
    file_stock.write((char*)stocks, sizeof(stock) * num_records);
    loadingScreens lsSt;
    foreColor(2);
	cls();
	lsSt.LoadingSorting();
    delete[] stocks;
    file_stock.close();
	foreColor(2);
	cls();
	gotoxy(10, 10); cout << R"(             

			       _____            __           __                                       ____      ____     
			      / ___/____  _____/ /____  ____/ /  _______  _______________  __________/ __/_  __/ / /_  __
			      \__ \/ __ \/ ___/ __/ _ \/ __  /  / ___/ / / / ___/ ___/ _ \/ ___/ ___/ /_/ / / / / / / / /
			     ___/ / /_/ / /  / /_/  __/ /_/ /  (__  ) /_/ / /__/ /__/  __(__  |__  ) __/ /_/ / / / /_/ / 
			   /____/\____/_/   \__/\___/\__,_/  /____/\__,_/\___/\___/\___/____/____/_/  \__,_/_/_/\__, /  
			                                                                                        /____/   


	)";
    
}

void _searchProBar(){
	
	view_data();
	getch();
	foreColor(7);
	cls();
	
	int Col = 1;
	file_stock.open("data\\stock.bin", ios::in | ios::binary);
	
	if(file_stock.fail()){
		foreColor(7);
		_hp.MessageFileError("  File not found", 4);
	}
	
	if(file_stock.good()){
		setcursor(true, 20);
		int _searchbar;
		bool isbarFound;
		
		drawBoxDoubleLineWithBG(53, 4, 33, 1, 55);
		gotoxy(54,5); cout << "Enter Barcode to search : ";
		cin >> _searchbar; fflush(stdin); cin.clear();
		file_stock.read((char*)&st, sizeof(st)); 
		
		while(file_stock.eof() != true){
			
			if(_searchbar == st.barcode){
				setcursor(false, 0);
				foreColor(7);
				cls();
				stock::header();
				gotoxy(22,4+Col); st.Output();
				isbarFound = true;
				Col++;
				DrawRectangle(20, 1, 107, 3+Col, 3);
				HLine(21, 3, 105, 3, '=');
				DrawRectangle(59, 5+Col, 31, 1, 3);
				gotoxy(61,6+Col); cout << "Press any key back to Menu";
			}
			file_stock.read((char*)&st, sizeof(st)); 
		}
		if(isbarFound == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
			foreColor(4); gotoxy(64,11); 
			cout << "Barcode Not found";
		}
	}
	
	file_stock.close();
}

void _SearchCategory(){
	
	view_data();
	getch();
	foreColor(7);
	cls();
	
	int Col = 1;
	file_stock.open("data\\stock.bin", ios::in | ios::binary);
	
	if(file_stock.fail()){
		_hp.MessageFileError("  File not found", 4);
	}
	
	if(file_stock.good()){
		
		char _searcateg[30];
		bool _iscategFound = false;
		setcursor(true, 20);
		drawBoxDoubleLineWithBG(48, 4, 50, 10, 55);
		drawBoxDoubleLineWithBG(50, 5, 46, 8, 70);
		drawBoxDoubleLineWithBG(55, 4, 36, 1, 87);
		gotoxy(56,5); cout << "Please provide category to search ";
		drawBoxDoubleLineWithBG(52, 9, 42, 1, 23);
		gotoxy(55,10); cin.get(_searcateg, 30); fflush(stdin);
		file_stock.read((char*)&st, sizeof(st)); 
		foreColor(7); 
		cls();
		
		while(file_stock.eof() != true){
			if(!strcmp(_searcateg, st.category)){
				stock::header();
				gotoxy(22,3+Col); st.Output();
				Col+=2;
				HLine(21, 2+Col, 105, 3, '=');
				_iscategFound = true;
			}
			file_stock.read((char*)&st, sizeof(st));
		}
		DrawRectangle(19, 1, 109, Col, 3);
		HLine(21, 3, 105, 3, '=');
		DrawRectangle(59, 2+Col, 31, 1, 3);
		gotoxy(62,3+Col); cout << "Press any key to continue";
		if(_iscategFound == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
			foreColor(4); gotoxy(65,11); 
			cout << "Wrong Category";
		}	
	}
	file_stock.close();
}

void _update(){
	
	view_data();
	getch();
	foreColor(7);
	cls();
	
	file_stock.open("data\\stock.bin", ios::out | ios::in | ios::binary);
	if(file_stock.fail()){
		foreColor(7);
		cls();
		_hp.MessageFileError("  File not found", 4);
	}
	
	if(file_stock.good()){
		
		int updateByBar;
		bool isUpdated;
		
		drawBoxDoubleLineWithBG(55, 5, 37, 1, 155);
		gotoxy(56, 6); cout << "Enter barcode for update: ";
		cin >> updateByBar; fflush(stdin); cin.clear();
		foreColor(7);
		cls();
		file_stock.read((char*)&st, sizeof(stock));
		while(file_stock.eof() != true){
			
			if(updateByBar == st.barcode){
				
				int lastbytes = file_stock.tellg();
				
				setcursor(true, 20);
				drawBoxDoubleLineWithBG(40, 3, 70, 25, 142);
				drawBoxDoubleLineWithBG(42, 4, 66, 23, 142);
				drawBoxDoubleLineWithBG(57, 5, 37, 1, 142);
				gotoxy(60,6); cout << " U P D A T E  P R O D U C T";
				
				drawBoxDoubleLineWithBG(50, 10, 50, 1, 142);
				gotoxy(52, 11); cout << "Update New Barcode: ";
				cin >> st.barcode; fflush(stdin); cin.clear();
				drawBoxDoubleLineWithBG(50, 13, 50, 1, 142);
				gotoxy(52,14); cout << "Update New Name's Product   : ";
				cin.get(st.name,30); fflush(stdin);
				drawBoxDoubleLineWithBG(50, 16, 50, 1, 142);
				gotoxy(52, 17); cout << "Update New Unit : ";
				cin.get(st.unit, 10); fflush(stdin);
				drawBoxDoubleLineWithBG(50, 19, 50, 1, 142);
				gotoxy(52, 20); cout << "Update New Category: ";
				cin.get(st.category,30); fflush(stdin);
				drawBoxDoubleLineWithBG(50, 22, 50, 1, 142);
				gotoxy(52,23); cout << "Change Price of Product ? : $";
				cin >> st.price; fflush(stdin); cin.clear();
				file_stock.seekp(lastbytes - sizeof(stock));
				file_stock.write((char*)&st, sizeof(stock));
				isUpdated = true;
			}
			file_stock.read((char*)&st, sizeof(stock));	
		}
		if(isUpdated == false){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(62, 10, 20, 1, 4);
			foreColor(4); gotoxy(65,11); 
			cout << "Wrong Barcode";
			foreColor(2); gotoxy(46, 13); cout << "Press any key to update again or Press [ESC] back to menu";
		}
		if(isUpdated == true){
			foreColor(7);
			cls();
			setcursor(false, 0);
			drawBoxDoubleLineWithBG(62, 10, 20, 1, 2);
			foreColor(2); gotoxy(63,11); 
			cout << "Updated success!!!";
			foreColor(2); gotoxy(46, 13); cout << "Press any key to update again or Press [ESC] back to menu";
		}
	}
	file_stock.close();
}

void _delete(){
	
	view_data();
	getch();
	foreColor(7);
	cls();
	
	ofstream fileBackup;
	file_stock.open("data\\stock.bin", ios::out | ios::in | ios::binary);
	fileBackup.open("data\\stockBackup.bin", ios::binary);
	if(file_stock.fail()){
		foreColor(7);
		cls();
		_hp.MessageFileError("  File not found", 4);
	}
	if(file_stock.good()){
		
		int _deleteByBar;
		bool isFound;
		
		drawBoxDoubleLineWithBG(53, 4, 33, 1, 55);
		gotoxy(54,5); cout << "Enter barcode to delete : ";
		cin >> _deleteByBar; fflush(stdin); cin.clear();
		
		file_stock.read((char*)&st, sizeof(stock));
		while(file_stock.eof() != true){
			
			if(_deleteByBar == st.barcode){
				isFound = true;
			}
			if(_deleteByBar != st.barcode){
				fileBackup.write((char*)&st, sizeof(stock));
			}
			
			file_stock.read((char*)&st, sizeof(stock));	
		}
		if(isFound == true){
			foreColor(7);
			cls();
			setcursor(false,0);
			drawBoxDoubleLineWithBG(63, 6, 10, 1, 39);
			gotoxy(64,7); cout << "Deleted";
			foreColor(2); gotoxy(46, 9); cout << "Press any key to delete again or Press [ESC] back to menu";
		}
		if(isFound == false){
			foreColor(7);
			cls();
			setcursor(false,0);
			drawBoxDoubleLineWithBG(60, 6, 15, 1, 71);
			gotoxy(61,7); cout << " Wrong Barcode";
			foreColor(2); gotoxy(46, 9); cout << "Press any key to delete again or Press [ESC] back to menu";
		}
		
	}
	
	file_stock.close();
	fileBackup.close();
	
	remove("data\\stock.bin");
	rename("data\\stockBackup.bin","data\\stock.bin");
	
}
///////////////////////
#endif