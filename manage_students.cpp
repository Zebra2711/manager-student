#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include<stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
class scores
{
public:
	double math;
	double english;
	double phisics;
	double chemistry;
	double literature;
};
class students
{
public:
	char id[20];
	char name[50];
	char sex[10];
	char year_of_birth[4];
};
class list_students{
	public:
		students *student_[100];
		unsigned int x;
};
void setTable(list_students *list);
void input_inf_students(list_students *list);
void input_inf_students_to_file(list_students *list);
void output_inf_students(list_students *list);
int main(void){
	char input;
	scores score;
	list_students list;
	list.x = 0;
	while(input!='0'){
		cout<<".........................................."<<endl;
		cout<<"1. Add New Students\n";
		cout<<"2. Output inf_students\n";
		cout<<"Enter 0 to stop program\n";
		cin>>input;
		switch(input){
			case '1':{
				students *student = new students;
				input_inf_students(&list);
				list.student_[list.x] = student;
				list.x++;
				break;
			}
			case '2':{
				output_inf_students(&list);
				break;
			}
			case '0': break;
			default:
				cout<<"Input invalid\n";
		}
	}
	return 0;
}
/* int main()
{
	int values[] = {1341,12341,362,841,79,11,434,29,152,178,1};
	std::sort(std::begin(values),std::end(values));
	for (int i = 0; i < sizeof(values)/sizeof(int); i++) {
		std::cout << values[i] << " ";
	}
	return 0;
} */
void setTable(list_students *list)    {
    const int n=40;
		int counter = 0;
		//******************************MA ASCII******************************
    char row = 196, col = 179, cornerL = 198, cornerR = 181, midd = 197,cornerLU = 218;
    char cornerRU = 188, middU = 193, cornerRR = 191, cornerLL = 218, middleSingle = 194;
    char cornerLE=212, cornerRE=190; 

    for (int f = 0; f < n+1; f++) {
      if (f == 0) cout << cornerLL;
      else if (f == n) cout << cornerRR;
      else if (f == 4) cout << middleSingle;    
      else cout << row;
    }
    for (int i = 0; i < 3; i++) {
        cout << "\n";
        cout << col;            
        for (int j = 0; j < 2; j++) {
            string str=list->student_[i]->name;
            if (j==0) cout << counter++;
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
					case 4: cout << middU;   continue;
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
void input_inf_students_to_file(list_students *list){
	// FILE *file;
	
	// file=fopen("D:\\Project\\students.txt", "a");
	// if(file == NULL){
	// 	cout<<"Can not open file";
	// 	exit(1);
	// }
	// fprintf(file, "\n%s\n%s\n%s\n%s\n%f\n%f\n%f\n%f\n%f\n", student.name, student.id, student.sex, student.year_of_birth, score.math, score.english, score.phisics, score.chemistry, score.literature);
	// fclose(file);
	std::ofstream file;
	file.open("D:\\Project\\students.txt", std::ios_base::app );
	file<<list->student[0]->name<<endl;
	file<<student->id<<endl;
	file<<student->sex<<endl;
	file<<student->year_of_birth<<endl;
	file<<score.math<<endl;
	file<<score.english<<endl;
	file<<score.phisics<<endl;
	file<<score.chemistry<<endl;
	file<<score.literature;
	file.close();
}
void input_inf_students(list_students *list){
	fflush(stdin);
	cout<<"ID of students:\t";
	gets(list.student[0]->id);
	fflush(stdin);
	cout<<"Name:\t";
	gets(student->name);
	fflush(stdin);
	cout<<"Sex:\t";
	gets(student->sex);
	cout<<"Year of Birth:\t";
	fflush(stdin);
	cin>>student->year_of_birth;
	cout<<"Score of math:\t";
	cin>>score.math;
	cout<<"Score of english:\t";
	cin>>score.english;
	cout<<"Score of phisics:\t";
	cin>>score.phisics;
	cout<<"Score of chemistry:\t";
	cin>>score.chemistry;
	cout<<"Score of literature:\t";
	cin>>score.literature;
}
void output_inf_students(list_students *list){
	// FILE *file;
	// file=fopen("D:\\Project\\students.txt", "r");
	// while(!feof(file)){
	// 	char str[100];
	// 	fgets(str,100,file);
	// 	fscanf(file,"%s\n%s\n%s\n%lf\n%lf\n%lf\n%lf\n%lf\n",&student.id,&student.sex,&student.year_of_birth,&score.math,&score.english,&score.phisics,&score.chemistry,&score.literature);
	// 	cout<<"............................................\n";
	// 	cout<<"Name: "<<str<<"\n";  //student.name
	// 	cout<<"ID: "<<student.id<<"\n";
	// 	cout<<"Sex: "<<student.sex<<"\n";
	// cout<<"Year of Birth: "<<student.year_of_birth<<"\n";
	// cout<<"Math: "<<score.math<<"\n";
	// cout<<"English: "<<score.english<<"\n";
	// cout<<"Phisics: "<<score.phisics<<"\n";
	// cout<<"Chemistry: "<<score.chemistry<<"\n";
	// cout<<"Literature: "<<score.literature<<"\n";
	// }
	// fclose(file);
	ifstream file;
	file.open("D:\\Project\\students.txt", std::ios_base::in );
	while(!file.eof()){
			string str;
			cout<<"............................................\n";
			getline(file,str);
 
    char *strs;
		strcpy(strs, str.c_str());// string to char array
		int counter = 0;
		strs-->list->student_[counter++]->name;
		cout << "Name: " << str << "\n";
		getline(file, str);
		cout << "ID: " << str << "\n";
		getline(file, str);
		cout << "Sex: " << str << "\n";
		getline(file, str);
		cout << "Year of Birth: " << str << "\n";
		getline(file, str);
		cout << "Math: " << str << "\n";
		getline(file, str);
		cout << "English: " << str << "\n";
		getline(file, str);
		cout << "Phisics: " << str << "\n";
		getline(file, str);
		cout << "Chemistry: " << str << "\n";
		std::getline(file, str);
		cout << "Literature: " << str << "\n";
}
}