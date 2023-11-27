#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Begin
void DisplayMenu() {
      cout << "Menu options:" << endl;
      cout << "1. Display All Seats Status:" << endl;
      cout << "2. Total Number of Available Seats:" << endl;
      cout << "3. Display Available Seats: " << endl;
      cout << "4. Book Seat:" << endl;
      cout << "5. Cancel Seat:" << endl;
      cout << "6. Change Seat:" << endl;
      cout << "7. Quit:" << endl;
}
//number 1
void DisplayAllSeatsStatus(const vector<string> &seat, const vector<bool> &avail) {
   
      cout << "Seat" << "\t" << "Status" << endl;
   for(unsigned int i = 0; i < seat.size(); ++i) {
      cout << seat.at(i) << "\t" << avail.at(i) << endl;
   }
} 
//number 2
void DisplayAvailableSeats(const vector<string> &ok, const vector<bool> &maybe) { 
      int hello = ok.size();
   
         cout << "Number of available seats: ";
   for(unsigned int i = 0; i < ok.size(); ++i) {
      if(maybe.at(i) == true) {
         hello--;
      }
   }
         cout << hello << endl;
}
//number 3
int TotalNumberOfAvailableSeats(const vector<bool> &yellow) {
   int cnt = 0;
   
   for(unsigned int i = 0; i < yellow.size(); ++i) {
      if(yellow.at(i) == false) {
         cnt++;
      }
   }
   return cnt;
}
//number 4
void BookSeat(const string &yes, const vector<string> &no, vector<bool> &ok) {
   
    for(unsigned int i = 0; i < no.size(); ++i) {
       if(yes == no.at(i)) {
         ok.at(i) = true;
       }
    } 
         cout << "Seat" << "\t" << "Status" << endl;
   for(unsigned int i = 0; i < no.size(); ++i) {
         cout << no.at(i) << "\t" << ok.at(i) << endl;
   }
}
//number 5
void CancelSeat (const string &no, const vector<string> &yes, vector<bool> &ok) {
   
         cout << "Seat" << "\t" << "Status" << endl;
   for(unsigned int i = 0; i < yes.size(); ++i) {
      if(no == yes.at(i)) {
         ok.at(i) = false;
      }
   }
   for(unsigned int i = 0; i < yes.size(); ++i) {
         cout << yes.at(i) << "\t" << ok.at(i) << endl;
   }
}
//number 6
void ChangeSeat(const string &yes, const string &maybe, const vector<string> &ok, vector<bool> &no) {
   
         cout << "Seat" << "\t" << "Status" << endl; 
   for(unsigned int i = 0; i < ok.size(); ++i) {
      if(yes == ok.at(i)) {
         no.at(i) = false;
      }
   }
   for(unsigned int i = 0; i < ok.size(); ++i) {
      if(maybe == ok.at(i)) {
         no.at(i) = true;
      }
   }
   for(unsigned int i = 0; i < no.size(); ++i) {
         cout << ok.at(i) << "\t" << no.at(i) << endl;
   }
}

int main() {

vector<string> bruh;
vector<bool> hey(25);  
string temp = "";
string hello;
bool okay = false;

for(int i = 1; i <= 5; ++i) {
   for(char j = 'A'; j < 'A' + 5; ++j) {
      temp = ('0' + i);
      temp += j;
      hello = temp;
      bruh.push_back(hello);
      temp = "";      
   }
} 

for(unsigned int i = 0; i < 25; ++i) {
      hey.at(i) = false;
}

string seatSel;
string seatSel1;
int input;
int total;
   
 while(input != 7) {
            
      DisplayMenu();
      cout << endl;
      cout << "Please select an option: " << endl;
      cin >> input;
      cout << endl;
            
 if(input == 1) {
         DisplayAllSeatsStatus(bruh, hey);
         cout << endl;
}
else if(input == 2) {
         DisplayAvailableSeats(bruh, hey);
         cout << endl;
}
else if(input == 3) {
         cout << "Available seats:" << endl;
      total = TotalNumberOfAvailableSeats(hey);
       
   for(int i = 0; i < total + 1; ++i) {
      if(!(hey.at(i))) {
         cout << bruh.at(i) << endl;
      }
   }
         cout << endl;
}
else if(input == 4) {
         cout << "Enter seat to book: " << endl;
            cin >> seatSel;
         cout << endl;
         
   while(okay) {   
        if(okay) {
         cout << "That seat is already taken." << endl;
        }
      okay = false;
        
         cout << "Enter seat to book: " << endl;
            cin >> seatSel;
         cout << endl;
   }
      BookSeat(seatSel, bruh, hey);
         cout << endl;
       
   for(unsigned int i = 0; i < bruh.size(); ++i) {
      if(seatSel == bruh.at(i)) {
         okay = hey.at(i);
      }
   }
}
else if(input == 5) {
         cout << "Enter seat to cancel: " << endl;
            cin >> seatSel;
         cout << endl;
      CancelSeat(seatSel, bruh, hey);
         cout << endl;
}
else if(input == 6) {
         cout << "Enter seat to cancel: " << endl;
            cin >> seatSel; 
         cout << endl;
         cout << "Enter seat to book: " << endl;
            cin >> seatSel1;
         cout << endl;
      ChangeSeat(seatSel, seatSel1, bruh, hey);
         cout << endl;
}

   } 
      
   return 0;
}
