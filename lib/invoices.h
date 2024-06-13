#ifndef ___INVOICES_H___
#define ___INVOICES_H___
///////////////////////
#include "stock.h"
#include <vector>
///////////////////////
class invoice : public stock{
	
	public:
		int invoiceNumber; 
		char invoiceTime[50];
    	invoice() : invoiceNumber(0) {}

	    void setInvoiceNumber(int number) {
	        invoiceNumber = number;
	    }
	    
	    char* getCurrentDate() {
			time_t now = time(0);
			struct tm* timeinfo = localtime(&now);
			static char _recordtime[50];
			strftime(_recordtime, sizeof(_recordtime), "%d/%m/%Y | %H:%M:%S", timeinfo);
			return _recordtime;
		}
		
		int findHighestInvoiceNumber() {
		    ifstream invoiceFile("data\\invoices.bin", ios::in | ios::binary);
		
		    if (!invoiceFile.is_open()) {
		        return 0;
		    }
		
		    invoice inv;
		    int highestInvoiceNumber = 0;
		
		    while (invoiceFile.read((char*)&inv, sizeof(invoice))) {
		        if (inv.invoiceNumber > highestInvoiceNumber) {
		            highestInvoiceNumber = inv.invoiceNumber;
		        }
		    }
		
		    invoiceFile.close();
		
		    return highestInvoiceNumber;
		}
	
};

invoice inv;

bool _saleproduct(){
	
    int sellbarcode, sellQty;
    fstream stockFile("data\\stock.bin", ios::out | ios::in | ios::binary);

    if (!stockFile.is_open()) {
    	setcursor(false,0);
        foreColor(4); gotoxy(60, 16); cout << "Error: Cannot open stock file.";
        return false;
    }

    ofstream invoiceFile("data\\invoices.bin", ios::out | ios::app | ios::binary);

    if (!invoiceFile.is_open()) {
        foreColor(4); gotoxy(60, 16);cout << "Error: Cannot open invoices file.";
        return false;
    }

    char addMore;
    bool cartEmpty = true;
    vector<stock> cart;
    vector<int>QTYSELL;

    int highestInvoiceNumber = inv.findHighestInvoiceNumber();
    int currentInvoiceNumber = highestInvoiceNumber + 1;

    do {
		cls();
        view_data();
        getch();
        cls();
        setcursor(true,20);
        drawBoxDoubleLineWithBG(40, 3, 70, 18, 155);
        drawBoxDoubleLineWithBG(40, 11, 70, 10, 155);
        drawBoxDoubleLineWithBG(57, 4, 35, 1, 55);
        gotoxy(58,5);cout << "Enter Barcode for purchase: ";
        cin >> sellbarcode; fflush(stdin); cin.clear();

        if (sellbarcode == 0) {
            break; 
        }

        bool isFound = false;

        stockFile.seekg(0);
        stockFile.read((char*)&st, sizeof(stock));

        while (!stockFile.eof()) {
            if (st.barcode == sellbarcode) {
                isFound = true;
                break;
            }
            stockFile.read((char*)&st, sizeof(stock));
        }

        if (!isFound) {
        	setcursor(false,0);
        	drawBoxDoubleLineWithBG(61, 13, 25, 1, 55);
            gotoxy(65,14); cout << "Product not found";
            foreColor(155); gotoxy(53,16); cout << "Press any key try again or [ESC] get back";
            continue;
        }
		
		setcursor(true,20);
        drawBoxDoubleLineWithBG(57, 4, 35, 1, 103);
        gotoxy(58,5); cout << "Enter quantity for purchase: ";
        cin >> sellQty; fflush(stdin); cin.clear();

        if (sellQty <= 0) {
        	setcursor(false,0);
            drawBoxDoubleLineWithBG(61, 13, 25, 1, 55);
            gotoxy(66,14); cout << "Invalid quantity.";
            continue;
        }

        if (sellQty <= st.qty) {
        	
            st.qty -= sellQty;
            int pos = stockFile.tellg();
            stockFile.seekp(pos - sizeof(stock));
            stockFile.write((char*)&st, sizeof(stock));
			
            cart.push_back(st);
			QTYSELL.push_back(sellQty); 

            cartEmpty = false;
            setcursor(false,0);
            foreColor(155); gotoxy(45,16); cout << "Add to cart. Add more items to the current invoice? (y/n)";
            foreColor(7);
            addMore = getch();
        } else {
        	drawBoxDoubleLineWithBG(64, 7, 20, 1, 71);
            gotoxy(65, 8);cout << "Insufficient Stock!";
            drawBoxDoubleLineWithBG(61, 14, 25, 1, 54);
			gotoxy(63, 15);cout << "Current stock: " << st.qty;
			foreColor(155); gotoxy(53,18); cout << "Press any key try again or [ESC] get back";
        }
    } while (addMore == 'y' || addMore == 'Y');

    stockFile.close();

    if (!cartEmpty) {
    	int index = 0;
        for (stock& item : cart) {
        	
            strcpy(inv.invoiceTime, inv.getCurrentDate());
            inv.barcode = item.barcode;
            strcpy(inv.name, item.name);
            strcpy(inv.unit, item.unit);
            inv.qty = QTYSELL[index++];
            inv.price = item.price;
            inv.invoiceNumber = currentInvoiceNumber;
            invoiceFile.write((char*)&inv, sizeof(invoice));
            
        }
		
        currentInvoiceNumber++;
        setcursor(false,0);
		drawBoxDoubleLineWithBG(59, 8, 31, 1, 39);
        gotoxy(60,9); cout << "Invoice recorded successfully.";
        foreColor(155); gotoxy(54,13); cout << "Press any key try again or [ESC] get back";
    }

    invoiceFile.close();
    return true;
}

void view_invoice_history() {
	
    double riel = 4000;
    ifstream invoiceFile("data\\invoices.bin", ios::in | ios::binary);

    if (!invoiceFile.is_open()) {
    	foreColor(7);
    	cls();
        foreColor(4); gotoxy(59,15); cout << "No invoice history available.";
        return;
    }

    invoice inv;
    double total;
	vector<invoice> invcart;
	int r, c;
    cout << "\n\t\t\t\t\t======================== Invoice history ========================\n";  
    
	while (invoiceFile.read((char*)&inv, sizeof(invoice)))
	{
		invcart.push_back(inv);		
	}
	
	for(r = 0; r<invcart.size(); r++){
		total = 0;
		cout << "\t\t\t\t\t------------------------------------------------------------------"; 
    	cout << "\n\t\t\t\t\tInvoice: #INV/000" << invcart[r].invoiceNumber;
        cout << "\n\t\t\t\t\tDate & Time: " << invcart[r].invoiceTime;
        cout << "\n\t\t\t\t\t=================================================================="; 
        cout << "\n\t\t\t\t\t" << left;
        cout << setw(10) << "Barcode";
        cout << setw(20) << "Item";
        cout << setw(8) << "Unit";
        cout << setw(10) << "Quantity";
        cout << setw(10) << "Price";
        cout << setw(10) << "Amount";
        cout << "\n\n\t\t\t\t\t==================================================================\n"; 
        
        for(c = r; c<invcart.size(); c++)
        {
        	if(invcart[r].invoiceNumber == invcart[c].invoiceNumber)
        	{
		        cout << "\n\t\t\t\t\t" << left << fixed << setprecision(2);
		        cout << setw(10) << invcart[c].barcode;
		        cout << setw(20) << invcart[c].name;
		        cout << setw(8) << invcart[c].unit;
		        cout << setw(10) << invcart[c].qty;
		        cout << setw(1)  << "$" << setw(10) << invcart[c].price;
		        cout << setw(1)  << "$" << setw(10) << invcart[c].getAmount();
		        total += invcart[c].getAmount(); 
			}
			else
			{
				r = c-1;
				break;
			}
		}

    	cout << "\n\n\t\t\t\t\t==================================================================\n\n";
    	cout << setw(80) << " " << "Total($)     : " << total << endl;
    	cout << setw(80) << " " << "Total(Riels) : " << total* riel << endl;
    	cout << "\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@ \3Thank You\3 @@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
    	
    	if(c == invcart.size()){
			r = c-1;
		}
	}
    invoiceFile.close();
	cout << "\t\t\t\t\tPress [ESC] key to go back to the main menu.";
}


void _revenue() {
	
    ifstream invoiceFile("data\\invoices.bin", ios::in | ios::binary);

    if (!invoiceFile.is_open()) {
    	foreColor(7);
		cls();
    	setcursor(false,0);
        foreColor(4); gotoxy(60, 16); cout << "No invoice history for revenue.";
        return;
    }
	cout << fixed << setprecision(2);
    invoice inv;
    double totalRevenue = 0;
    double riel = 4000;
    int totalqty = 0;
	
    while (invoiceFile.read((char*)&inv, sizeof(invoice))){
        double invoiceTotal = 0;
        double amount = inv.getAmount();
        invoiceTotal += amount;
        totalqty += inv.qty;
        totalRevenue += invoiceTotal;
    }
    
	setcursor(false,0);
	drawBoxDoubleLineWithBG(40, 2, 60, 20, 151);
	drawBoxDoubleLineWithBG(53, 3, 33, 2, 167);
	drawBoxDoubleLineWithBG(55, 4, 29, 1, 151);
	gotoxy(58,5);cout << "\3 R  E  V  E  N  U  E \3";
	
	drawBoxDoubleLineWithBG(49, 8, 40, 1, 151);
    gotoxy(50, 9); cout << "Total quantity sold out : " << totalqty << " items";
    HLine(41, 12, 58, 151, '-');
    gotoxy(45, 13); cout << "Exchange rate dollar to riel $1.00 = " << riel <<" riels";
    drawBoxDoubleLineWithBG(53, 14, 33, 1, 151);
    gotoxy(54, 15);cout << "Total Revenue   : " << "$" << totalRevenue;
    drawBoxDoubleLineWithBG(50, 17, 39, 1, 151);
    gotoxy(52, 18);cout << "Total Revenue   : " << totalRevenue * riel << " riels";
    foreColor(151); gotoxy(57,21); cout << "Press any key back to menu";
    invoiceFile.close();
}
///////////////////////
#endif