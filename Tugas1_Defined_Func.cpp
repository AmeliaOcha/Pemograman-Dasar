#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//mendeklarasikan const phi karena nilai phi tidak akan berubah
const double phi = 3.1416;

//membuat fungsi distance yang digunakan untuk menentukan jarak dari titik
//pusat (Xp, Yp) dengan titik di tepi lingkatan (Xn, Yn)
double distance(double centerX, double centerY, double pointX, double pointY){
	return sqrt(pow(centerX - pointX, 2) + pow(centerY - pointY, 2));
}

//membuat fungsi radius yang digunakan untuk menentuka radius dari lingkaran
double radius(double centerX, double centerY, double pointX, double pointY){
	return distance(centerX, centerY, pointX, pointY);
}

//membuat fungsi keliling lingkaran dengan diketahui nilai r 
//nilai r diketahui dengan memanggil fungsi radius pada line 16-18
//pemanggilan fungsi radius dilakukan di int main
double circumate(double r){
	return 2 * phi * r;
}

//membuat fungsi yang digunakan untuk menghitung luas area dari lingkaran 
//nilai r diketahui dengan memanggil fungsi radius pada line 16-18
//pemanggilan fungsi radius dilakukan di int main
double area(double r){
	return phi * pow(r, 2);
}

int main(){
	double centerX, centerY, pointX, pointY; //mendeklarasikan nilai dari (Xp, Yp) dengan (Xn, Yn)
	
    //melakukan input data
	cout << "Program Menghitung Properti Lingkaran\n";
    cout << "=====================================\n\n";
    cout << "Masukkan koordinat titik pusat lingkaran:\n";
    cout << "Koordinat x: ";
    cin >> centerX;
    cout << "Koordinat y: ";
    cin >> centerY;
	cout << "\nMasukkan koordinat titik pada lingkaran:\n";
    cout << "Koordinat x: ";
	cin >> pointX;
	cout << "Koordinat y: ";
	cin >> pointY;
	
    //pemanggilan fungsi radius
    //digunakan untuk menentukan circumate dan are dari lingkaran
	double r = radius(centerX, centerY, pointX, pointY);
	
    //memberikan keluaran pada program
	cout << "\nHasil Perhitungan Properti Lingkaran:\n";
    cout << "=====================================\n";
    cout << fixed << setprecision(4); //untuk memastikan ada 4 angka di belakang koma
    cout << "Jari-jari     : " << r << " satuan\n";
    cout << "Diameter      : " << 2 * r << " satuan\n";
    cout << "Keliling      : " << circumate(r) << " satuan\n";
    cout << "Luas          : " << area(r) << " satuan persegi\n";
    
    return 0;
	
}
