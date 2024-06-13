#ifndef ___MENU_H___
#define ___MENU_H___
/////////////////////
#include "staff.h"
#include <shellapi.h>
#include "invoices.h"
#include "utilities.h" 
#include "forms.h"
/////////////////////
Forms _frm;
loadingScreens _ls;
tools _tools;
//helper _hp;
/////////////////////
void MainMenu(){
	_MainAgain:
	setcursor(false, 0);	
	foreColor(7);  
	cls();  
	char mainOption;
	cout << _tools.getCurrentDate();
	_frm.UIMain();
	mainOption = getch();
	switch(mainOption){
		case '1':{
			_loginAdmin:
			foreColor(7);  
			cls();  
			if(!_hp.loginAdmin()){
				goto _loginAdmin;
			}
			foreColor(7);  
			cls();  
			_ls.LoadingADMINScreen();
			foreColor(7);  
			cls();  
			ChoiceAdmin:
			foreColor(7);  
			cls();  
			cout << "Logged at : " << _tools.getCurrentDate();
			char admin_op;	
			_frm.AdminControlUI();
			admin_op = getch();
			switch(admin_op){
				case '1':{
					chooseAgain:
					foreColor(7);  
					cls();  
					
					setcursor(false,0);
					char op; 
					_frm.ProductControlUI();
					op = getch();
					switch (op){
						case '0':{
							do{
								foreColor(7);  
								cls();  
								_revenue();
							}while(!getch());
							foreColor(7);  
							cls();
							goto chooseAgain;
							
							break;
						}
						case '1':{
							do{
								foreColor(7);  
								cls();  
								setcursor(true,20);
								_register();
								delay(700); gotoxy(41, 31); foreColor(7);
								cout << "Press any key to register product again or press [ESC] back to menu";
							}while(getch() != 27);
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						case '2':{
							
							do{
								foreColor(7);  
								cls();  
								setcursor(true,20);
								import_qty();
								
							}while(getch() != 27);
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						case '3':{
							
							do{
								foreColor(7);  
								cls();  
								setcursor(false,0);
								view_data();
							}while(!getch());
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						case '4':{
							_searchProPanel:
							foreColor(7);  
							cls();  
							char searchPro;
							_frm.SearchProductPanel();
							searchPro = getch();
							switch(searchPro){
								case '1':{
									do{
										foreColor(7);  
										cls();  
										setcursor(true,20);
										_searchProBar();
									}while(!getch());
									foreColor(7);  
									cls(); 
									goto _searchProPanel;
									break;
								}
								case '2':{
									do{
										foreColor(7);  
										cls();  
										_SearchCategory();
									}while(!getch());
									
									foreColor(7);  
									cls();  
									goto _searchProPanel;
									break;
								}
									
								case '3':{
									goto chooseAgain;
									foreColor(7);  
									cls();
									break;
								}
									
								default:{
									
									setcursor(false, 0);
									foreColor(7);  
									cls();  	
									_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
									foreColor(7);  
									cls();
									goto _searchProPanel;
									break;
								}	
									
							}
							
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						case '5':{
							do{
								foreColor(7);  
								cls();  
								setcursor(true,20);
								_update();
							}while(getch() != 27);
							
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						case '6':{
							
							do{
								foreColor(7);  
								cls();  
								setcursor(true,20);
								_delete();
							}while(getch() != 27);
							
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						case '7':{
							
							do{
								foreColor(7);  
								cls();  
								setcursor(true,20);
								_saleproduct();
							}while(getch() != 27);
							
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						case '8':{
							
							do{
								foreColor(7);  
								cls();  
								setcursor(false,0);
								view_invoice_history();
							}while(getch() != 27);
							
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
								
						case '-':{
							foreColor(7);  
							cls(); 
							goto ChoiceAdmin;
							break;
						}
						
						case '9':{
							
							do{
								foreColor(7);  
								cls();  
								sort_by_barcode();
								delay(1000); gotoxy(60, 18); cout << "Press any key back to menu";
							}while(!getch());
							
							foreColor(7);  
							cls(); 
							goto chooseAgain;
							
							break;
						}
						
						default:{
							foreColor(7);  
							cls();  	
							_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
							foreColor(7);  
							cls();
							goto chooseAgain;
							break;
						}
						
					}
					
					break;
				}
				case '2':{
					foreColor(7);  
					cls(); 
					_StaffAgain:
					foreColor(7);  
					cls();  
					char main_op; 
					_frm.StaffControlUI();
					main_op = getch();
					
					switch(main_op){
						
						case '1':{
							do{
								foreColor(7);  
								cls();  
								setcursor(true, 20);
								_RegisterStaffInfo();
							}while(getch() != 27);
							cls();
							goto _StaffAgain;
							
							break;
						}
						case '2':{
							_vpChoosing:
							foreColor(7);  
							cls();  
							char vpchoice;
							_frm.ViewStaffPanelUI();
							vpchoice = getch();
							switch(vpchoice){
								case '1':{
									do{	
										foreColor(7);  
										cls();  
										_viewAllInfo();
									}while(!getch());
									cls();
									goto _vpChoosing;
									break;
								}
								case '2':{
									do{
										foreColor(7);  
										cls();  
										_viewUserAcc();
									}while(!getch());
									
									foreColor(7);  
									cls();  
									goto _vpChoosing;
									break;
								}
									
								case '3':{
									goto _StaffAgain;
									foreColor(7);  
									cls();
									break;
								}
									
								default:{
									foreColor(7);  
									cls();  	
									_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
									foreColor(7);  
									cls();
									goto _vpChoosing;
									break;
								}	
									
							}
							foreColor(7);  
							cls(); 
							break;
						}
						
						case '3':{
							do{
								foreColor(7);  
								cls();  
								_searchStaffInfo();
							}while(getch() != 27);
							foreColor(7);  
							cls();  
							goto _StaffAgain;
							
							break;
						}
						
						case '4':{
							_upChoosing:
							foreColor(7);  
							cls();
							char upchoice;
							_frm.UpdateStaffPanelUI();
							upchoice = getch();
							switch(upchoice){
									
								case '1':{
									do{	
										foreColor(7);  
										cls();  
										_updatePerInfo();
									}while(getch() != 27);
									foreColor(7);  
									cls();  
									goto _upChoosing;
									break;
								}
								case '2':{
									do{
										foreColor(7);  
										cls();  
										_updateStaffInfo();
									}while(getch() != 27);
									foreColor(7);  
									cls();  
									goto _upChoosing;
									break;
								}
								case '3':{
									do{
										foreColor(7);  
										cls();  
										_forgetUserAccount();
									}while(getch() != 27);
									foreColor(7);  
									cls();  
									goto _upChoosing;
									break;
								}
									
								case '4':{
									foreColor(7);  
									cls();  
									goto _StaffAgain;
									cls();
									break;
								}
									
								default:{
									foreColor(7);  
									cls();  	
									_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
									foreColor(7);  
									cls();
									goto _upChoosing;
									break;
								}	
									
							}
							foreColor(7);  
							cls(); 
							break;
						}
						
						case '5':{
							do{
								foreColor(7);  
								cls();  
								_StaffResignation();
							}while(getch() != 27);
							foreColor(7);  
							cls(); 
							goto _StaffAgain;
							foreColor(7);  
							cls(); 
							break;
						}
						
						case '6':{
							foreColor(7);  
							cls();  
							goto ChoiceAdmin;
							
							break;
						}
						
						default:{
							foreColor(7);  
							cls();  	
							_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
							foreColor(7);  
							cls();
							goto _StaffAgain;
							break;
						}
						
					}
					foreColor(7);  
					cls();
					goto ChoiceAdmin;
					break;
				}
				case '3':{
					logoutAdminagain:
					char exitChoice;
					foreColor(7); 
					cls();          
					_hp._DialogMessage("Logout Confirmation", " Are you sure you want to logout?", "    Press (Y or y) / (N or n)", 90);
					exitChoice = getch();
					    
					if (exitChoice == 'Y' || exitChoice == 'y') {
					    foreColor(7); 
					    cls();
						goto _MainAgain;
					
					} else if (exitChoice == 'N' || exitChoice == 'n') { 
					    cls();
					    goto ChoiceAdmin;
					} else {
					    setcursor(false, 0);
					    foreColor(7); 
					    cls();        
					    _hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
					    goto logoutAdminagain;
						foreColor(7); 
					    cls();
					}
					goto ChoiceAdmin;
					break;
				}
				default:{
					foreColor(7);  
					cls();  	
					_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
					foreColor(7);  
					cls();
					goto ChoiceAdmin;
					break;
				}
				
			}
			
			foreColor(7);  
			cls(); 
			goto _MainAgain;
			
			break;
		}
		
		case '2':{
			
			foreColor(7);  
			cls();  
			if(!_hp.loginStaff()){
				foreColor(7);  
				cls();
				gotoxy(57, 15); cout << "We're didn't see data of staff";
				gotoxy(56, 16); cout << "Press any key back to login menu";
				getch();
				goto _MainAgain;
			}
			foreColor(7);  
			cls();  
			_ls.LoadingStaffScreen();
			foreColor(7);  
			cls();  
			_stfMenuAgain:
			setcursor(false, 0);
			char staffMenu;
			_frm.StaffMenu();
			staffMenu = getch();
			switch(staffMenu){
				
				case '1':{
					do{
						
						foreColor(7);  
						cls();  
						setcursor(true,20);
						_saleproduct();
						
					}while(getch() != 27);
					cls();
					goto _stfMenuAgain;
					break;
				}
				case '2':{
					do{
						foreColor(7);  
						cls();  
						setcursor(false,0);
						view_data();
					}while(!getch());
					cls();
					goto _stfMenuAgain;
					break;
				}
				case '3':{
					_StaffsearchProPanel:
							foreColor(7);  
							cls();  
							char searchPro;
							_frm.SearchProductPanel();
							searchPro = getch();
							switch(searchPro){
								case '1':{
									do{
										foreColor(7);  
										cls();  
										setcursor(true,20);
										_searchProBar();
									}while(getch() != 27);
									cls();
									goto _StaffsearchProPanel;
									break;
								}
								case '2':{
									do{
										foreColor(7);  
										cls();  
										_SearchCategory();
									}while(!getch());
									
									foreColor(7);  
									cls();  
									goto _StaffsearchProPanel;
									break;
								}
									
								case '3':{
									goto _stfMenuAgain;
									foreColor(7);  
									cls();
									break;
								}
									
								default:{
									cls();
									setcursor(false, 0);
									foreColor(7);  
									cls();  	
									_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
									foreColor(7);  
									cls();
									goto _StaffsearchProPanel;
									break;
								}	
									
							}
					cls();
					goto _stfMenuAgain;
					break;
				}
				case '4':{
					do{
						foreColor(7);  
						cls();  
						setcursor(false,0);
						view_invoice_history();
					}while(!getch());
					cls();
					goto _stfMenuAgain;
					break;
				}
				case '5':{
					do{
						foreColor(7);  
						cls();  
						setcursor(false,0);
						_revenue();
					}while(!getch());
					cls();
					goto _stfMenuAgain;
					break;
				}
				case '6':{
					logoutStaffAgain:
					setcursor(false, 0);
					char exitChoice;
					foreColor(7);  
					cls();          
					_hp._DialogMessage("Logout Confirmation", " Are you sure you want to logout?", "    Press (Y or y) / (N or n)", 90);
					exitChoice = getch();
					    
					if (exitChoice == 'Y' || exitChoice == 'y') {
					    foreColor(7); 
					    cls();
						goto _MainAgain;
					
					} else if (exitChoice == 'N' || exitChoice == 'n') { 
						foreColor(7); 
					    cls();
					    goto _stfMenuAgain;
					} else {
					    setcursor(false, 0);
					    foreColor(7); 
					    cls();        
					    _hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
					    goto logoutStaffAgain;
						foreColor(7); 
					    cls();
					}
					foreColor(7); 
					cls();
					goto _stfMenuAgain;
					break;
					
				}				
				default:{
					
					foreColor(7); 
					cls();
					_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
					foreColor(7);
					cls();
						
					goto _stfMenuAgain;
					
					break;
				}
				
			}
			
			foreColor(7); 
			cls();  
			
			goto _MainAgain;
			
			break;
		}
		
		case '3':{
			
			ShellExecute(0, 0, "https://about-developer.netlify.app/", 0, 0 , SW_SHOW );
			foreColor(7);
			cls();
			goto _MainAgain;
			break;
		}
		case '4':{
			exitAgain:
			setcursor(false, 0);
			char exitChoice;
			foreColor(7);  
			cls();          
			_hp._DialogMessage("Exit Confirmation", "   Do you really want to exit?", "    Press (Y or y) / (N or n)", 38);
			exitChoice = getch();
					    
			if (exitChoice == 'Y' || exitChoice == 'y') {
			    foreColor(7); 
			    cls();
				_ls.LoadingExit();
				foreColor(7); 
			    cls();
			    foreColor(2); cout << R"(
					
		  _______ _                 _           __                       _                                                    
		 |__   __| |               | |         / _|                     (_)                                                   
		    | |  | |__   __ _ _ __ | | _____  | |_ ___  _ __   _   _ ___ _ _ __   __ _    ___  _   _ _ __    __ _ _ __  _ __  
		    | |  | '_ \ / _` | '_ \| |/ / __| |  _/ _ \| '__| | | | / __| | '_ \ / _` |  / _ \| | | | '__|  / _` | '_ \| '_ \ 
		    | |  | | | | (_| | | | |   <\__ \ | || (_) | |    | |_| \__ \ | | | | (_| | | (_) | |_| | |    | (_| | |_) | |_) |
		    |_|  |_| |_|\__,_|_| |_|_|\_\___/ |_| \___/|_|     \__,_|___/_|_| |_|\__, |  \___/ \__,_|_|     \__,_| .__/| .__/ 
		                                                                          __/ |                          | |   | |    
		                                                                         |___/                           |_|   |_|    				
				)";
			    delay(2000);
				exit(0);
					
			} else if (exitChoice == 'N' || exitChoice == 'n') { 
				foreColor(7); 
			    cls();
			    goto _MainAgain;
			} else {
			    setcursor(false, 0);
			    foreColor(7); 
				cls();        
			    _hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
			    goto exitAgain;
				foreColor(7); 
			    cls();
			}
			foreColor(7); 
			cls();
			goto _stfMenuAgain;
			break;
		}
		
		default:{
			foreColor(7);  
			cls();  	
			_hp._DialogMessage("Message Error", "        Wrong choice !!!", "       Please try again", 71);
			foreColor(7);  
			cls();		
			goto _MainAgain;
			break;
		}
		
	}
	
}

#endif