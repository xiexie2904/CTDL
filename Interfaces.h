#pragma once


char thucdon [so_item][50] = {  "1.Quan Li Cac May Bay",
					   "2.Quan Li Cac Chuyen Bay",
					   "3.Dang Ky Ve May Bay",
					   "4.Huy Bo Ve May Bay",
					   "5.Xem Danh Sach Hanh Khach Chi Tiet",
					   "6.Xem So Do Cho Ngoi & Danh Sach Ve Con Trong",
					   "7.Xem Chi Tiet So Lan Thuc Hien Chuyen Bay",
					   "8.Xem Cac Chuyen Bay Di Toi Cac Dia Danh",
					   "0. Thoat chuong trinh"};
			          

void MenuCenter() {
	
	ReadAirplaneFile(planeList);
	int chon = 0;
//	int vitri;
	FlightList FL; 
	initFlightList(FL);
	
	ReadFlightFromFile(FL);
	bool Exit =false;
	
	while (!Exit) {
		chon = MenuDong (thucdon);

		clrscr();
		switch(chon) {
				
			case 1:
				MenuManageAirplane(planeList);
				break;
				
			case 2 :
				ManageFlightPlane(FL);
				break;
			case 3:
//				Chinh_Sua_MB(planeList);
				break;
			case 4:
//				SaveFile(planeList, filename);
				break;
			case 5:
				break;
			case so_item:
				WriteFlightToFile(FL);
				WriteAirplaneToFile(planeList);
				Exit = true;
				break;
				
			
			
			
		}
		
	}
	
//	do {
//		
//		chon = MenuDong (thucdon);
//
//		clrscr();
//		switch(chon) {
//				
//			case 1:
//				MenuManageAirplane(planeList);
//				break;
//				
//			case 2 :
//				ManageFlightPlane(FL);
//				break;
//			case 3:
////				Chinh_Sua_MB(planeList);
//				break;
//			case 4:
////				SaveFile(planeList, filename);
//				break;
//			case 5:
//				break;
//			case so_item:
//				
//				break;
//			
//			
//			
//		}
//		
//		
//	}
//	while(1);
//	
	
	
	}
