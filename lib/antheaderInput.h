/*
	Name: antheaderInput.h
	Copyright: ANT Technoloy Training Center
	Author: Hinsy Lasong
	Date: 30/06/21 15:59
	Description: this header file describe about create own input function
*/

#ifndef ___ANTHEADERINPU_H___
#define ___ANTHEADERINPU_H___
//////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>// Covert char array to number: atoi, atof,...
#include<iostream>
using namespace std;
//// add by me


int inputNumber()
{
	again :
	string std_string = "";
	char input;
	
	while(1)
	{
		
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 10)
		{
			break;
		}
	   	else if(input == 8)// key backspace
		{
			if(std_string.length() > 0)
			{
				printf("\b \b");
				
				std_string.erase(std_string.length() -1);
			}
		}
		else if(!(input>='0' && input<='9' || input == '.' || input == '-')  )
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add std::string
			std_string.push_back(input);
		}
	}
	
	// convert std_string to int
	if (std_string.empty()) {
	    
	    goto again;
//	    return 0;
	}
	int result = stoi(std_string);
	
	return result;
}

////////////////////////////////////////
// Char Array
//----------------------------------------------------------------------
char* inputNumber(char* charArray)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(!(input>='0' && input<='9' || input == '.' || input == '-')  )
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}
////////////////////////////////////////
char* inputLetter(char* charArray)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(!(input>='a' && input<='z' || input>='A' && input<='Z' || input == 32 ))
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}
////////////////////////////////////////
char* hidePassword(char* charArray)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(!(input>= 9  ||  input== 32)  )// tap and space
		{
			continue;
		}
		else
		{
			printf("*");
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}
////////////////////////////////////////
char* input4Tel(char* charArray)
{
	char input;
	int index = 0;
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(index>0)
			{
				printf("\b \b");
				
				index--;
				charArray[index] = '\0';
			}
		}
		else if(!(input>='0' && input<='9' || input == 32 || input == '+') )
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add char array
			charArray[index] = input;
			//next position
			index++;
		}
	}
	// set to NULL
	charArray[index] = '\0';//charArray[index] = NULL;
	
	return charArray;
}
////////////////////////////////////////
//----------------------------------------------------------------------
// std::string 
//----------------------------------------------------------------------
string inputNumber(string&  std_string)
{
	char input;
	std_string = "";
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
	   else if(input == 8)// key backspace
		{
			if(std_string.length() > 0)
			{
				printf("\b \b");
				
				std_string.erase(std_string.length() -1);
			}
		}
		else if(!(input>='0' && input<='9' || input == '.' || input == '-')  )
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add std::string
			std_string.push_back(input);
		}
	}
	
	return std_string;
}
////////////////////////////////////////
string inputLetter(string&  std_string)
{
	char input;
	std_string = "";
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(std_string.length() > 0)
			{
				printf("\b \b");
				std_string.erase(std_string.length() -1);
			}
		}
		else if(!(input>='a' && input<='z' || input>='A' && input<='Z' || input == 32 ))
		{
			continue;
		}
		else
		{
			printf("%c", input);
			// add std::string
			std_string.push_back(input);
		}
	}
	
	return std_string;
}
////////////////////////////////////////
string hidePassword(string&  std_string)
{
	char input;
	std_string = "";
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
		else if(input == 8)// key backspace
		{
			if(std_string.length() > 0)
			{
				printf("\b \b");
				
				std_string.erase(std_string.length() -1);
			}
		}
		else if(!(input>= 9  ||  input== 32)  )// tap and space
		{
			continue;
		}
		else
		{
			printf("*");
			// add std::string
			std_string.push_back(input);
		}
	}
	
	return std_string;
}
////////////////////////////////////////
string input4Tel(string& std_string)
{
	char input;
	std_string = "";
	
	while(1)
	{
		input = getch();   
		if(input == 13)
		{
			break;
		}
	   else if(input == 8)// key backspace
		{
			if(std_string.length() > 0)
			{
				printf("\b \b");
				
				std_string.erase(std_string.length() -1);
			}
		}
		else if(!(input>='0' && input<='9' || input == 32 || input == '+') )
		{
			continue;
		}
		else
		{
			printf("%c", input);
		   // add std::string
			std_string.push_back(input);
		}
	}
	
	return std_string;
}
////////////////////////////////////////
//----------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
#endif