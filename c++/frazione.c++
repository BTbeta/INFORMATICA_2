/** ****************************************************************************************
* \mainpage frazione.c++
*
* @brief prova funzioni di file di record
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author Zeng oscar hao
* @date 12/1/2022
* @version 1.0 <19/1/2022>  Versione iniziale
*/

#include<iostream>
#include<iomanip>

using namespace std;
class Frazione
{
	private:
		int numeratore;
		int denominatore;
	public:
		frazione(){};
		void setNumeratore(int n)
		{
			numeratore=n;
		}
		void setDenominatore(int n)
		{
			denominatore=n;
		}
		int getNumeratore()
		{
			return numeratore;
		}
		int getDenominatore()
		{
			return denominatore;
		}
		void stampa()
		{
			cout<<numeratore<<"/"<<denominatore<<"="<<numeratore/denominatore;
		}
};

int main()
{
	Frazione a;
	a.setNumeratore(12);
	a.setDenominatore(3);
	a.stampa();
}
