#include <iostream>
#include <fstream> // untuk membuat program bisa membaca file 
#include <string>
#include <iomanip>
using namespace std;

const int MAX_CLASS_SIZE = 20;

struct studentType {
  string studentFName;
  string studentLName;
  int testScore;
  char grade;
};

//fungsi untuk memeriksa apakah file input (input_Tugas1.txt) bisa dibuka
void readStudentDataFromFile(studentType students[], int& size, const string& filename){
  //membuka file utnuk dibaca
  ifstream inputFile(filename);

  //memeriksa apakah file bisa dibuka 
  if(!inputFile){
    cout << "Error: Tidak dapat membuka file " << filename <<endl;
    return;
  }

  //membaca data dari awal hingga akhir file atau mencapai nilai maksimum
  size = 0;
  while (size < 20 && inputFile >> students[size].studentFName >> students[size].studentLName >> students[size]. testScore)
  {
    //memvalidasi nilai 
    if(students[size].testScore >= 0 && students[size].testScore <= 100){
      size++;
    } else{
      cout << "Warning: Nilai tidak valid untuk siswa " << students[size].studentFName << " " << students[size].studentLName <<endl;
    }
  }
  //mengekuarkan keluaran ke terminal bahwa input data berhasil dilakukan
  inputFile.close();
  cout << "Berhasil membaca " << size << " data siswa dari file" <<endl;
}

//fungsi untuk menentukan grade
void assignGrades (studentType students[], int size){
  for(int i = 0; i < size; i++){
    if(students->testScore >= 90) students[i].grade = 'A';
    else if(students[i].testScore >= 80) students[i].grade = 'B';
    else if(students[i].testScore >= 70) students[i].grade = 'C';
    else if(students[i].testScore >= 60) students[i].grade = 'D';
    else students[i].grade = 'F';
  }
}

//fungsi untuk mencari nilai tertinggi
int findHighestScore(studentType students[], int size){
  int highestScore = students[0].testScore;
  for(int i = 1; i < size; i++){
    if(students[i].testScore > highestScore){
      highestScore = students[i].testScore;
    }
  }
  return highestScore;
}

//fungsi untuk menentukan siswa dengan nilai tertinggi
void printHighestScorers(studentType students[], int size){
  int highestScore = findHighestScore(students, size);
  cout << "\nNama Siswa dengan Nilai Tertinggi adalah ";
  for(int i = 0; i < size; i++){
    if (students[i].testScore == highestScore)
    {
      cout << students[i].studentLName << ", " << students[i].studentFName << " dengan Nilai" << " (" << highestScore << ")"<<endl;
    }
    
  }
}

int main(){
  studentType students[MAX_CLASS_SIZE];
  int actualSize = 0;
  string filename = "input_Tugas1.txt"; //nama file yang 

  cout << "Program Untuk Menentukan Grade dan Nilai Terbesar\n";
  cout << "=================================================\n\n";

  //program membaca data dari file dengan nama input_Tugas1.txt
  readStudentDataFromFile(students, actualSize, filename);

  if(actualSize > 0){
    //menentukan grade dari masing-masing siswa
    assignGrades(students, actualSize);

    //mencetak data siswa
    cout << "\nDaftar Nilai Siswa:\n";
    cout << "=================================================\n";
    cout << left << setw(25) << "Nama" << setw(3) << "Nilai" << setw(15) << right << "Grade\n";
    for(int i = 0; i < actualSize; i++){
      cout << left << setw(25) << (students[i].studentLName + ", " + students[i].studentFName) << setw(3) << right << students[i].testScore << setw(14) << students[i].grade << "\n";
    }

    //mencetak siswa yang memiliki nilai tertinggi
    printHighestScorers(students, actualSize);
    cout <<endl;
  }

  return 0;
}
