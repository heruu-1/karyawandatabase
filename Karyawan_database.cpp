#include <iostream>
#include <string>

using namespace std;

long long db_nip[5000] = {
   221001, 221002,221003
};
long long nip_gen = 221004;
string db_name[5000] = {
   "Muhammad Heru","Cakrawangsa Veda","Aldo Pratama"
};
string db_phone[5000] = {
   "0811 212 212","0811 777 777","0811 222 222"
};
string db_address[5000] = {
   "tanjung senang","kemiling","kedaton"
};
string db_position[5000] = {
   "direktur utama","komisaris utama","hrd"
};

int size = 3;

int query(long long nip) {
   for (int i = 0; i < size; i++) {
      if (db_nip[i] == nip) return i;
   }

   return -1;
}

int main() {
   string username, password;
   bool login_success = false;
   
   cout << "**********************************************************************\n";
   cout << "\tWelcome to Database Employee of SnapDragon Corporation ltd\n";
   cout << "\tto continue you have to enter your username and password\n";
   cout << "**********************************************************************\n";

   for (int t = 0; t < 3 && !login_success; t++) {
      cout << "username: ";
      getline(cin, username);
      cout << "password: ";
      getline(cin, password);

      if (username == "admin" && password == "qwerty") {
         login_success = true;
      } else {
         cout << "\n\t[WARNING] Access denied!\n";
         cout << t + 1 << "/3 chance reached Please enter valid credential!\n\n";
      }
   }

   if (login_success) {
      cout << "\n>>> ACCESS GRANTED! <<<\n\n\n";
      cout << "INFORMATION!!!\n";
      cout << "type [--search] [nomor-induk-pegawai] to search for employee\n";
      cout << "type [--add] to add new employee\n";
      cout << "type [--quit] to close databse\n";

      bool quit = false;
      while (!quit) {
		 cout << "\n\nENTER COMMAND : ";
         string command;
         long long nip;
         cin >> command;
         getchar();

         if (command == "--search") {
            cin >> nip;
            getchar();
            int id = query(nip);
            if (id >= 0) {
               cout << "Employee with nip: " << db_nip[id] << " was found!\n";
               cout << "Name : " << db_name[id] << endl;
               cout << "Phone : " << db_phone[id] << endl;
               cout << "Address : " << db_address[id] << endl;
               cout << "Position : " << db_position[id] << endl;
            } else {
               cout << "Employee with nip: " << nip << " was not found!\n";
            }

         } else if (command == "--add") {
            if (size < 5000) {
               cout << "Adding New Employee! Please type credential required\n";
               cout << "Name : ";
               getline(cin, db_name[size]);
               cout << "Phone : ";
               getline(cin, db_phone[size]);
               cout << "Address : ";
               getline(cin, db_address[size]);
               cout << "Position : ";
               getline(cin, db_position[size]);
               db_nip[size] = nip_gen++;
               
			   size++;
               cout << "SUCCESSFULLY ADDED NEW EMPLOYEE!\n";
            } else {
               cout << "PANIC! database full!\n";
            }

         } else if (command == "--quit") {
        	quit = true;
		 }else {
            cout << "invalid command : " << command << endl;
         }
      }

   } else {
      cout << "\n\t>>> [you have been banned!] <<<\n";
   }
	
   cout << "\n\n**********************************************************************\n";
   cout << "\t\t\tClosing database!\n";
   cout << "**********************************************************************\n";

}
