/** ****************************************************************************************
* \mainpage retangolo
*
* @brief prova funzioni di file di record
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Zeng oscar hao
* @date 19/1/2022
* @version 1.0 <19/1/2022>  Versione iniziale
*/

#include<iostream>
#include<math.h>

using namespace std;
class Rettangolo {
	private:
		double base;
		double altezza;
	public:
		Rettangolo() {
			base = 1;
			altezza = 1;
		}
		Rettangolo(double x,double y) {
			base = x;
			altezza = y;
		}
		void setBase(double x) {
			base = x;
		}
		void setAltezza(double x) {
			altezza = x;
		}
		double getBase() {
			return base;
		}
		double getAltezza() {
			return altezza;
		}
		double calcolaArea() {
			return base*altezza;
		}
		double calcolaPerimetro() {
			return (base+altezza)*2;
		}
		double calcolaDiagonale() {
			return sqrt(pow(base,2)+pow(altezza,2));
		}
};

int main() {
	Rettangolo R1;
	double base = R1.getBase();
	double altezza = R1.getAltezza();
	cout<< base << " " << altezza << endl;
	Rettangolo R2(2,3);
	base = R2.getBase();
	altezza = R2.getAltezza();
	cout<< base << " " << altezza << endl;
	R1.setBase(6);
	R1.setAltezza(3);
	base = R1.getBase();
	altezza = R1.getAltezza();
	cout<< base << " " << altezza << endl;
	double area = R1.calcolaArea();
	double perimetro = R1.calcolaPerimetro();
	double diagonale = R1.calcolaDiagonale();
	cout<< area << " " << perimetro << " " << diagonale << endl;
}
