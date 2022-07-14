#pragma once
#include<math.h>
#include "ConstraintTP.h"
#include <sstream>

string titleDisplay[] ={"So hieu", "Loai MB", "So cho ngoi"};
int x_Pos[7] = {1,20,45,63,80,95, 107};
int TotalPage = 0;
int CurrentPage = 0; 

struct DetailInfo {
	
	char serialPlane[15];
	char typePlane[40];
	int seats;
};


struct Plane {
	
	int n=0;
	DetailInfo *planes[MAXLIST];
}  ;

typedef struct Plane listPlane;


listPlane planeList;

void WriteAirplaneToFile(listPlane &list)
{
	ofstream fileout;
	fileout.open("DSMB.TXT",ios_base::out);// ios_base::out la de ghi vao file
	if( fileout.is_open() )
	{
		for( int i = 0 ; i <= (list.n-1) ; i++)
		{
			
		
			fileout << list.planes[i]->serialPlane <<" "<<list.planes[i]->typePlane<<" "<<list.planes[i]->seats<<endl;
			
		}
	}
	else
	{
		gotoxy(X_Notification,Y_Notification+1);
		cout << " Ket noi file de ghi vao that bai";
	}
	fileout.close();
}


void ReadAirplaneFile(listPlane &list)
{
	ifstream filein;
	filein.open("DSMB.TXT", ios_base::in);// ios_base::in la de doc
 string lines[3];
 string line;
 string serial; string type;
 int i=0;
 int seat;

	if( filein.is_open() )
	{
	
	
	 while(!filein.eof())
        {
			DetailInfo *plane = new DetailInfo;
            filein >> plane->serialPlane;
            filein >> plane->typePlane;
            filein >> plane->seats;
            
            if(filein == NULL) {
            	break;
			}
		 
            list.planes[i++] = plane;
			list.n++;
        }
	 
	
	}
	filein.close();
}




int Check_Trung(listPlane &list, const char *serialNum) {
	
	for(int i=0; i< list.n; i++) {
	
		int response = strcmp(((list.planes[i])->serialPlane), serialNum);
		if(response == 0) return i;
	
	}
	return -1 ;	
	
}


void RemoveFormComplete()
{
	system("color 0E");
	for( int i = 0 ; i < 20 ; i++)
	{
		gotoxy(x_add - 2 , y_add - 1 + i );
		printf("%-32s", " ");
	}
	//ShowCur(false);
}


void Display(string content[], int numContent) {
	
	
// mau vang
	system("color 0E");
	Normal(14,0);
	for(int i=0; i< numContent; i++) {
		gotoxy(x_Pos[i] + 3, 4);
		cout<<content[i];
	}
	
	gotoxy(x_hd,y_hd);
	cout << " Huong dan " ;
	gotoxy(x_hd-1,y_hd + 2);
	cout << "  Up:Len || Down:Xuong ";
	gotoxy(x_hd,y_hd + 3);
	cout << " Insert:Them || Del:Xoa ";
	gotoxy(x_hd,y_hd + 4);
	cout << " Home:Chinh Sua || ESC : thoat" ;
	

}



//DetailInfo *addPlane(DetailInfo &plane) {
//	
//	DetailInfo *t = new DetailInfo;
//	*t = plane;
//	return t;
//	
//}


 

void show_one_plane(DetailInfo *plane, int position) {

	gotoxy(x_Pos[0] + 3, Y_Display + 3 + position*3);printf("%-15s",plane->serialPlane);
	gotoxy(x_Pos[1] + 3, Y_Display + 3 + position*3);printf("%-15s",plane->typePlane);
	gotoxy(x_Pos[2] + 3, Y_Display + 3 + position*3);printf("%-15d",plane->seats);
	
	
}

void Xuat_DS_MB(listPlane list, int startIndex) {
	
	system("cls");
	Display(titleDisplay,3);
	gotoxy(40,1);
	cout<<"Danh sach may bay";
	gotoxy(1,2);
	cout << " So luong may bay : " <<list.n;
	
	
	for(int i=0; i +startIndex < list.n && i< NumberPerPage; i++) {
		
		show_one_plane(list.planes[i+startIndex],i);
		
	}
	

}

void ChangePage(listPlane list) {
	
	
	
	Xuat_DS_MB(list, (CurrentPage-1)* NumberPerPage);
}


void CreateRow(int x, int y, string content, int length) {
	gotoxy(x,y);
	cout<<content;
}


void CreateForm(string content[], int numContent, int length) {
	
	int y = y_add;
	
	for(int i=0; i< numContent; i++) {
	
		
		CreateRow(x_add,y,content[i], length);
		y = y+ 3;
	
	}
	

}

int FindIndexAirplane(listPlane LA, const char *ma) {


	for(int i=0; i< LA.n; i++) {
	
		if(strcmp(LA.planes[i]->serialPlane, ma) ==0 ) {
			return i;		
		}
	
	}
	return -1;


}

bool RemoveAirplane(listPlane &list, int vitri) {
	
	if(vitri<0) return false;
	
	for(int i = vitri; i< list.n; i++) {
		list.planes[i] = list.planes[i+1];
	}

	list.n--;
	return true;
}

//void Nhap_DS_MB(listPlane &list ) {
//	DetailInfo plane;
//
//	while(list.n < MAXLIST) {
//	
//		if(Nhap_Thong_Tin_MB(list,plane) == 0) return;
//		list.planes[list.n] = addPlane(plane);
//		*list.planes[list.n] = plane;
//		list.n++;
//		
//	}
//		
//}


void Nhap_MB(listPlane &list, bool Edit, bool Del) {
	
		int order = 0;
 		string ID;
 		string typePlane;
 		int nchair = 0;
 		int target;
 	
 	bool quit = false;
 	while(!quit) {
 		
 		switch(order) {
 			case 0 : // nhap cho so hieu mb
 				{
 					
 					ConstraintLetterAndNumber(ID,order,12);
 					if(ID == "") {
						BaoLoi(" Vui Long Khong Bo Trong ");
						break;
					 }
					 target = FindIndexAirplane(list,ID.c_str());
					 if(Del) {
					
								if(!RemoveAirplane(list,FindIndexAirplane(list,ID.c_str())) ){
								
									BaoLoi("Fail !");
								
								}
								else {
									BaoLoi("Success !");
								}
								
								return;
					
						}
					if(target <0 && Edit) {
						BaoLoi("ID not exists !");
					}						
					if(Edit ) {
						ID = list.planes[target]->serialPlane;
						typePlane = list.planes[target]->typePlane;
						nchair = list.planes[target]->seats;
						
						gotoxy(x_add+12,0*3+y_add); cout<< ID;
						gotoxy(x_add+12,1*3+y_add); cout<< typePlane;
						gotoxy(x_add+12,2*3+y_add); cout<< nchair;
						
					}
					if(target < 0 && Edit == false) {
					 
					 	BaoLoi(" So hieu  trung trong ds ");
						break;
					 
					 }
				 }
				 order++;
				 break;
 			case 1: // nhap loai type
 				ConstraintLetter(typePlane,order,12);
 				
 				 				
 				if(typePlane == "") {
				 	
				 	BaoLoi(" Vui Long Khong Bo Trong ");
					break;
				 
				 }
				 
			
 				order++;	
 				break;
 			case 2: // nhap cho ngoi
 				ConstraintNumber(nchair,order,12,999);
 				
 				if(nchair <1) {
 					BaoLoi("Khong hop le");
					break;
				 }
				if(nchair< 20) {
					BaoLoi("So ghe >= 20");
					break;
				}
				order++;
 				break;
 			case 3:
 				if(Edit)  {
 					
 					strcpy(list.planes[target]->serialPlane, ID.c_str());
 					strcpy(list.planes[target]->typePlane, typePlane.c_str());
 					list.planes[target]->seats = nchair;
 					gotoxy(X_Notification,Y_Notification+1);
					cout << " Update successful ! ";
 					
				 }
 				{
 					list.planes[list.n] = new DetailInfo;
 					strcpy((list.planes[list.n]->serialPlane),ID.c_str());
					strcpy((list.planes[list.n]->typePlane),typePlane.c_str());
					list.planes[list.n]->seats = nchair;
					list.n++;
					gotoxy(X_Notification,Y_Notification+1);
					cout << " Added ! ";
				 }
				 
 				WriteAirplaneToFile(list);
// 				system("cls");
//				RemoveFormComplete();
 				quit = true;
 				break;
 				
 			
		 }
 		
 		
 		
	 }
	
	
}
 	
 
 	
 
void MenuManageAirplane(listPlane &list) {
	
	
	Xuat_DS_MB(list, 0);
	

	
	TotalPage = (int)ceil( (double)list.n/NumberPerPage );
	CurrentPage = 1;
	int signal;
	
	while(true) {
		while (kbhit()){
			
			signal = getch();
			
			if(signal == ESC) return;
			
			if(signal == 224) {
				
				signal = _getch();
				
				if(signal == PAGE_UP && CurrentPage > 1) {
					
					CurrentPage--;
					Xuat_DS_MB(list,(CurrentPage-1)*CurrentPage);
				}
				else if (signal == PAGE_DOWN && CurrentPage < TotalPage) {
					CurrentPage++;
					
					Xuat_DS_MB(list,(CurrentPage-1)*NumberPerPage);	
				}
			
				else if(signal == INSERT) {
				
					if(list.n == MAXLIST) {
						gotoxy(X_Notification,Y_Notification+1);cout <<"Danh sach day,khong the them";
						return;
					}
					else {
						system("cls");
						CreateForm(titleDisplay,3,27);
						gotoxy(115 + 12,0 * 3 + 4);
						Nhap_MB(list, false, false);
						TotalPage = (int) ceil((double)list.n/NumberPerPage);
						Xuat_DS_MB(list, (CurrentPage-1)*NumberPerPage);
						
					}
				
			
				} 
			
				else if(signal == DEL) {
					system("cls");
					CreateForm(titleDisplay,3,27);
					gotoxy(115 + 12,0 * 3 + 4);
					Nhap_MB(list,false,true);
					system("cls");
					TotalPage = (int) ceil((double)list.n/NumberPerPage);
					Xuat_DS_MB(list, (CurrentPage-1)*NumberPerPage);
				}
				
				else if(signal == HOME) {
					system("cls");
					CreateForm(titleDisplay,3,27);
					gotoxy(115 + 12,0 * 3 + 4);
					Nhap_MB(list,true,false);
					TotalPage = (int) ceil((double)list.n/NumberPerPage);
					Xuat_DS_MB(list, (CurrentPage-1)*NumberPerPage);
					
					
				}
			}
			
			
		}
	}
		


}


