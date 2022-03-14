 #include <iostream>
 #include <conio.h>
 #include <stdio.h>
 #include <windows.h>
 #include <string.h>
 #include <iomanip>
  #include <cmath>
 using namespace std;

void setTable();
string table[10][2] = {  { "STT", "    NAME" },  { " 1 ", "Hoang" },  { " 2 ", "Hoang Nghia Ai" },
  { " 3 ", "Dung xau trai" },  { " 4 ", "Nguyen hoang nam" },  { " 5 ", "Nguyen Tung lam" },  { " 6 ", "Le Van Son" },
  { " 7 ", "Nguyen Van A" },  { " 8 ", "Nguyen Thi B" },  { " 9 ", "Cao Phu Cuong" } };
   
int main() {
    setTable();
    cout<<"\n";
    getch();
    system("cls");
    return 0;
} 
void setTable()    {
    const int n=40;
    //******************************MA ASCII******************************
    char row = 196, col = 179, cornerL = 198, cornerR = 181, midd = 197, cornerLU = 218;
    char cornerRU = 188, middU = 193, cornerRR = 191, cornerLL = 218, middleSingle = 194;
    char cornerLE=212, cornerRE=190; 

    for (int f = 0; f < n+1; f++) {
       // if(f<0) 
      if (f == 0) cout << cornerLL;
      else if (f == n) cout << cornerRR;
      else if (f == 4) cout << middleSingle;    
      else cout << row;
    }
    for (int i = 0; i < 10; i++) {
        cout << "\n";
        cout << col;            
        for (int j = 0; j < 2; j++) {
            string str=table[i][j];
            if (j==0) cout << str;
            if(j==1){
                cout <<" "<<str<<setw(n-4-str.size()-1);
            }
            
            cout << col;
        }
        cout << "\n";
        for (int rd = 0; rd < n+1; rd++) {
        if(i==9){
            switch (rd) {
                    case 0: cout << cornerLE;continue;
                    case n: cout << cornerRE; continue;
                    case 4: cout << middU; continue;
                    default:cout << row;
                }
        }else
                switch (rd) {
                    case 0: cout << cornerL;continue;
                    case n: cout << cornerR; continue;
                    case 4: cout << midd;   continue;
                    default:cout << row;
                }  
    }
}
}      