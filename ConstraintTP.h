#pragma once

void ConstraintLetterAndNumber(string &chuoi, int order,bool &Save, int width) {
	int lenght = (int)chuoi.length();
	gotoxy(x_add+width,order*3+y_add);
	cout << chuoi;
	int count = lenght;
	int signal;
	while(true)
	{
			signal = getch();
			if(signal != 224 && signal != BACKSPACE && signal !=0) {
			
						if( ( 65 <= signal && signal <= 90 ) || ( 97 <= signal && signal <= 122 ) || ( 48 <= signal && signal <= 57 ) )
						{
							
							if( count < 15 )
							{
								count++; 
								cout << (char)signal;// hien thi
								chuoi += (char)signal;// cap nhat 
							}
						}
						
						else if(signal == ESC){
							Save= false;
							return ;
							
						
							}
						else if(signal == ENTER) {
						
							return;
						}
					
					}
					
	
			else if(signal == BACKSPACE && count >0) {
				putch('\b');
				putch(' ');
				putch('\b');
				chuoi.erase(chuoi.length()-1, 1);
				count--;
			}
	

}
}


void ConstraintLetter(string &chuoi, int order, bool &Save,int width) {
	int lenght = (int)chuoi.length();
//	gotoxy(x_add + width,order * 3 + y_add);
	gotoxy(x_add+width,order*3+y_add);
	cout << chuoi;
	int count = lenght;

	while(true)
	{
			int signal = _getch();
			if(signal != 224 && signal != BACKSPACE && signal !=0) {
			
						if( ( 65 <= signal && signal <= 90 ) || ( 97 <= signal && signal <= 122 ) )
						{
							
							if( count < 15 )
							{
								count++; 
								cout << (char)signal;// hien thi
								chuoi += (char)signal;// cap nhat 
							}
						}
						
						else if(signal == ESC){
							Save = false;
							return ;
							
						
							}
						else if(signal == ENTER) {
							return;
						}
					
					}
					
	
			else if(signal == BACKSPACE && count >0) {
				putch('\b');
				putch(' ');
				putch('\b');
				chuoi.erase(chuoi.length()-1, 1);
				count--;
			}
	

}
}


void ConstraintNumber(int &num, int order,bool &Save, int width, int limitseats) {
	gotoxy(x_add+width,order*3+y_add);
	if (num > 0) cout<<num;
	
	int count= 0; // backspace fn
	
	do {
		num /= 10;
		count++;
	} while(num!=0);
	
	while(true)
	{
			int signal = _getch();
			if(signal != 224 && signal != BACKSPACE && signal !=0) {
			
						if(  48 <= signal && signal <= 57 )
						{
							
							int result = signal - 48;
							if(signal == 48 && count == 0) {
								continue;	
							}
							else if((num*10+ result) <= limitseats ) {
								cout<<result;
								num = num * 10 +result;
								count++;
							
							}
						}
						
						else if(signal == ESC){
							Save = false;
							return ;
							
						
							}
						else if(signal == ENTER) {
							return;
						}
					
			}
			else if(signal == BACKSPACE && count >0 ) {
				cout << (char)BACKSPACE<<" "<<(char)BACKSPACE;
				num /=10;
				count--;
			}
					
	
}
	
}

void ConstraintsForLetterAndSpace(string &destination,bool &Save,int order,int width) {
	ShowCur(true);
	int signal;
	int lens = (int) destination.length();
	gotoxy(x_add+width,order*3+y_add);

	
	while(true) {
		
		while(kbhit()) {
			
			while(true) {
				signal = getch();
				if(signal != 224 && signal != BACKSPACE && signal !=0 ) {
					if( ( 65 <= signal && signal <= 90 ) || ( 97 <= signal && signal <= 122 ) || signal == SPACE)
						{
							if(lens <= 20 )
							{
								lens++; 
								cout << (char)signal;
								destination += (char)signal;
							}
						}
					else if(signal == ESC) {
						Save = false;
						return;
						
					}
					else if(signal == ENTER){
						return;
					}
			
				}
				else if(signal == BACKSPACE && lens >0)	 {
					
					cout << (char)BACKSPACE<<" "<<(char)BACKSPACE;
					destination.erase(destination.length() - 1, 1);
					lens--;
				}
			
			
			}
			
		}
	}
	
}	

void ConstraintForOnlyNumber(int &num,int order,bool &Save,int width ,int maxTicket) {
	
	gotoxy(x_add+width,order*3+y_add);
	if(num >0)  cout<< num;
	
	int count= 0; // backspace fn
	
	do {
		num /= 10;
		count++;
	} while(num!=0);
	
	while(true)
	{
			int signal = _getch();
			if(signal != 224 && signal != BACKSPACE && signal !=0) {
			
						if(  48 <= signal && signal <= 57 )
						{
							
							int result = signal - 48;
							if(signal == 48 && count == 0) {
								continue;	
							}
							else if((num*10+ result) <= maxTicket ) {
								
								num = num * 10 +result;
								cout<<result;
								count++;
							
							}
						}
						
						else if(signal == ESC){
							Save = false;
							return ;
							
						
							}
						else if(signal == ENTER) {
							
							return;
						}
					
			}
			else if(signal == BACKSPACE && count>0  ) {
				cout << (char)BACKSPACE<<" "<<(char)BACKSPACE;
				count--;
				num /=10;
				
			}
					
	
}
	
}


void ConstraintForDateAndTime(int &result,int &dtOrder,int space , int limit) {
//	gotoxy(x_add + 13 + 11, order * 3 + y_add);
	gotoxy(x_add + space + dtOrder * 3 +1 , 3 *3  + y_add);
	if( result != 0 )
		cout << result;
	int num = result;
	int count = 0;
	
	while(num > 0) {
		count++;
		num/=10;
		
	}
	
	int signal;
	while(true) {
		signal = getch();
		
		if(signal != 224 && signal != BACKSPACE && signal !=0) {
			
						if(  48 <= signal && signal <= 57 )
						{
							
							int minus = signal - 48;
							if(result > limit) {
								continue;
							}
							else if((result*10+ minus) <= limit ) {
								
								count++;
								result = result *10 + minus;
								cout<<minus;
							
							}
						}
					
						else if(signal == ENTER) {
							if (result > limit || result ==0 ) continue;
							return;
						}
			}
						else if(signal == BACKSPACE && count >0  ) {
										cout << (char)BACKSPACE<<" "<<(char)BACKSPACE;
										count--;
										result /=10;
						}
	}
	
}

void ConstraintForOnlyGender(int &result, int order, bool &Save,int width) {
	
	gotoxy(x_add + width, y_add+ order*3);
	if(result !=0 ) cout<< result;
	
	int count = 0;
	
	while(true) {
		
			int signal = getch();
			if(signal != 224 && signal != SPACE) {
			
				if(48<=signal && signal <=49) {
					
					int sub = signal -48;
					
					if(-1< result*10+sub && result*10+sub<2) {
					
						cout<<sub;
						count++;
						result = result*10+sub;
					}
				}
				
				else if(signal == ESC) {
				
					Save = false;
					return;
				}
				
				else if(signal == 8 && count >=0) {
					cout << (char)BACKSPACE<<" "<<(char)BACKSPACE;
					
					result /=10;
					count--;
				
				}
				else if(signal == ENTER) {
					if(result>1) continue;
					
					return;
				
				}
			
			}
	
	}
	
}

void DelHeadOptimize(string &result) {
	int i = 0;
	while(true) {
		
		if(result[i] == ' ')
	 		result.erase(i,1);
	 	else break;
	
	}
}

void stringOptimize(string &result) {
	DelHeadOptimize(result);
	for(int i=1; i< result.length(); i++) {
		
		if(result[i-1] == ' ' && result[i]== ' ')  	{
			result.erase(i-1,1);
			i--;
		}
		else if (result[result.length()-1] == ' ') result.erase(result.length()-1, 1);	
	}


}



void StandardName(char* a) 
{
	a[0] = toupper(a[0]);
	for (int i = 1; i < strlen(a); i++)
	{
		if (a[i - 1] == ' ' && a[i] != ' ') a[i] = toupper(a[i]);
		else a[i] = tolower(a[i]);
	}
}

