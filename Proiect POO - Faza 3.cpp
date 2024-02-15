#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include<vector>
#include<set>
#include<list>
#include<map>
using namespace std;

class ClasaAbstracta {
	virtual float calculPretComandaFaraTVA() = 0;
	virtual float calculPretComandaEuro(float cursValutar) = 0;
};

class Ifile
{
public:

	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;
	virtual void writeToTextFile(ofstream& out) = 0;
	virtual void readFromTextFile(ifstream& in) = 0;
	virtual void writeToCSVFile(ofstream& out) = 0;

};

class Angajat :public Ifile
{

private:

	static int index;
	const int id;
	char* nume;
	int varsta = 0;
	float salariu = 0;
	bool Experienta = 0;
	string mail = "Anonim";
	string telefon = "Anonim";
	int nrComisioane = 0;
	float comision[30];
	int nrFunctii = 0;
	string* istoricFunctii = NULL;


public:

	//1.0) Functii accesor 
	//1.1.1)GET
	char* getNume()
	{
		char* copie = new char[strlen(nume) + 1];
		strcpy(copie, nume);
		return copie;
	}
	const int getId()
	{
		return this->id;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	float getSalariu()
	{
		return this->salariu;
	}
	string getMail()
	{
		return this->mail;
	}
	string getTelefon()
	{
		return this->telefon;
	}
	bool getExperienta()
	{
		return this->Experienta;
	}
	int getNrFunctii()
	{
		return this->nrFunctii;
	}
	string* getIstoricFunctii()
	{
		return this->istoricFunctii;
	}
	int getNrComisioane()
	{
		return this->nrComisioane;
	}
	float* getComisioane()
	{
		return this->comision;
	}

	//1.1.2) SET
	void setNume(const char* nume) {

		if (strlen(nume) > 2)
		{
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}

	}
	void setVarsta(int varsta)
	{
		if (varsta >= 18)
		{
			this->varsta = varsta;
		}
	}
	void setSalariu(float salariu)
	{
		if (salariu >= 2550)
		{
			this->salariu = salariu;
		}
	}
	void setMail(string mail)
	{
		if (mail.size() >= 10)
		{
			this->mail = mail;
		}
	}
	void setTelefon(string telefon)
	{
		if (telefon.size() == 10) {
			this->telefon = telefon;
		}
	}
	void setExperienta(bool Experienta)
	{
		if (Experienta == 0 || Experienta == 1)
			this->Experienta = Experienta;
	}
	void setFunctii(int nrFunctii, string* istoricFunctii)
	{
		delete[] this->istoricFunctii;

		this->nrFunctii = nrFunctii;
		this->istoricFunctii = new string[this->nrFunctii];
		for (int i = 0; i < this->nrFunctii; i++)
		{
			this->istoricFunctii[i] = istoricFunctii[i];
		}

	}
	void setComisioane(int nrComisioane, float* comison)
	{
		if (nrComisioane > 0)
		{
			this->nrComisioane = nrComisioane;
			for (int i = 0; i < this->nrComisioane; i++)
			{
				this->comision[i] = comision[i];
			}
		}
	}

	//1.2) Metode
	void cursValutar(float cursValutar)
	{
		float val = this->salariu / cursValutar;
		cout << val;
	}
	float SumaComisioane()
	{
		float suma = 0;
		for (int i = 0; i < this->nrComisioane; i++)
		{
			suma = suma + this->comision[i];
		}
		return suma;
	}

	//1.3Constructuri, destructor si operator =
	//1.3.1) Constructor fara parametrii
	Angajat() : id(++index)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
	}

	//1.3.2) Constructor cu toti parametrii
	Angajat(const char* nume, int varsta, float salariu, string mail, string telefon, string* istoricFunctii, int nrFunctii, int nrComisioane, float* comision, bool Experienta) : id(++index)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->salariu = salariu;
		this->mail = mail;
		this->telefon = telefon;
		this->Experienta = Experienta;
		if (nrComisioane > 0)
		{
			this->nrComisioane = nrComisioane;
			for (int i = 0; i < this->nrComisioane; i++)
			{
				this->comision[i] = comision[i];
			}
		}
		if (nrFunctii > 0 && istoricFunctii != NULL)
		{
			this->nrFunctii = nrFunctii;
			this->istoricFunctii = new string[this->nrFunctii];
			for (int i = 0; i < this->nrFunctii; i++)
			{
				this->istoricFunctii[i] = istoricFunctii[i];
			}
		}

	}

	//1.3.3) Constructor cu cativa parametrii
	Angajat(const char* nume, int varsta) :id(++index)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
	}

	//1.3.4) Constructor copy
	Angajat(const Angajat& a) : id(a.id)
	{
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->varsta = a.varsta;
		this->salariu = a.salariu;
		this->mail = a.mail;
		this->telefon = a.telefon;
		this->Experienta = a.Experienta;
		if (a.nrComisioane > 0)
		{
			this->nrComisioane = a.nrComisioane;
			for (int i = 0; i < this->nrComisioane; i++)
			{
				this->comision[i] = a.comision[i];
			}
		}
		if (a.nrFunctii > 0 && a.istoricFunctii != NULL)
		{
			this->nrFunctii = a.nrFunctii;
			this->istoricFunctii = new string[this->nrFunctii];
			for (int i = 0; i < this->nrFunctii; i++)
			{
				this->istoricFunctii[i] = a.istoricFunctii[i];
			}
		}
		else
		{
			this->nrFunctii = 0;
			this->istoricFunctii = NULL;
		}

	}

	//1.3.5)Destructor
	~Angajat()
	{

		delete[] this->nume;
		if (istoricFunctii != NULL)
		{
			delete[] this->istoricFunctii;
		}

	}

	//1.3.6)Operator=
	Angajat& operator=(const Angajat& a)
	{
		delete[] this->nume;
		if (this != &a)
		{
			if (istoricFunctii != NULL)
			{
				delete[] this->istoricFunctii;
			}

			this->nume = new char[strlen(a.nume) + 1];
			strcpy(this->nume, a.nume);
			this->varsta = a.varsta;
			this->salariu = a.salariu;
			this->mail = a.mail;
			this->telefon = a.telefon;
			this->Experienta = a.Experienta;
			if (a.nrComisioane > 0)
			{
				this->nrComisioane = a.nrComisioane;
				for (int i = 0; i < this->nrComisioane; i++)
				{
					this->comision[i] = a.comision[i];
				}
			}
			if (a.nrFunctii > 0 && a.istoricFunctii != NULL)
			{
				this->nrFunctii = a.nrFunctii;
				this->istoricFunctii = new string[this->nrFunctii];
				for (int i = 0; i < this->nrFunctii; i++)
				{
					this->istoricFunctii[i] = a.istoricFunctii[i];
				}
			}

		}
		return *this;
	}

	//1.4.1)Operator<<
	friend ostream& operator<< (ostream& out, const Angajat& a)
	{
		out << endl << "-------------------------------------------------";
		out << endl << "Nume angajat: " << a.nume << endl;
		out << "ID angajat: " << a.id << endl;
		out << "Varsta angajat: " << a.varsta << endl;
		out << "Salariu angjat: " << a.salariu << endl;
		out << "Mail angajat: " << a.mail << endl;
		out << "Telefon angajat: " << a.telefon << endl;
		out << "Angajatul are experienta? ";
		if (a.Experienta == 1)
			out << "Da!" << endl;
		else
			out << "Nu!" << endl;

		if (a.nrComisioane > 0)
		{
			out << "Numar comisioane angajat: " << a.nrComisioane << endl;
			out << "Comisioanele angajatului sunt: " << endl;
			for (int i = 0; i < a.nrComisioane; i++)
				out << "Anagatul a avut comisionul cu numarul " << i + 1 << " in valoare de " << a.comision[i] << endl;
		}
		else
		{
			out << "Angajatul nu a avut niciun comision momentan!" << endl;
		}

		if (a.nrFunctii > 0)
		{
			out << "Numar functii trecute: " << a.nrFunctii << endl;
			out << "Istoric functii angajat: ";
			for (int i = 0; i < a.nrFunctii; i++)
				out << a.istoricFunctii[i] << " ";
		}
		else
		{
			out << "Angajatul nu a mai detinut nicio functie momentan!";
		}
		out << endl << "-------------------------------------------------";
		return out;
	}

	//1.4.2)Operator>>
	friend istream& operator>>(istream& in, Angajat& a)
	{
		cout << "Introduceti datele cerute despre angajat:" << endl;
		cout << endl << "Nume angajat: " << endl;
		in >> ws;
		delete[] a.nume;
		char aux[100];
		in.getline(aux, 99);
		a.nume = new char[strlen(aux) + 1];
		strcpy(a.nume, aux);
		cout << "Varsta angajat: " << endl;
		in >> a.varsta;
		cout << "Salariu angajat: " << endl;
		in >> a.salariu;
		cout << "Mail angajat: " << endl;
		in >> ws;
		getline(in, a.mail);
		cout << "Telefon angajat: " << endl;
		in >> ws;
		getline(in, a.telefon);
		cout << "Are angajatul experinta? (Introduceti: 1-Da/ 0-Nu)";
		in >> a.Experienta;
		cout << "Numar comisioane angajat: " << endl;
		in >> a.nrComisioane;
		cout << "Comisioane: " << endl;
		for (int i = 0; i < a.nrComisioane; i++)
		{
			cout << "Anagatul a avut comisionul cu numarul " << i + 1 << " in valoare de ";
			in >> a.comision[i];
		}

		cout << "Numar functii: " << endl;
		in >> a.nrFunctii;
		delete[] a.istoricFunctii;
		a.istoricFunctii = new string[a.nrFunctii];
		cout << "Istoric functii angajat: ";
		for (int i = 0; i < a.nrFunctii; i++)
		{
			in >> ws;
			getline(in, a.istoricFunctii[i]);
		}

		return in;
	}

	//1.5.1) Operator de indexare
	string operator[](int pozitie)
	{
		cout << endl << "----- Apel operator de indexare[] ------" << endl;
		if (pozitie >= 0 && pozitie < this->nrFunctii)
		{
			return this->istoricFunctii[pozitie];
		}
		else
			cout << "Pozitia nu a fost gasita";

	}

	//1.5.2) Operatorul +
	Angajat operator+(float val) {
		cout << endl << "----- Apel operator + -----" << endl;
		Angajat copie1 = *this;
		copie1.salariu += val;
		return copie1;
	}

	//1.5.3) Operator ++
	//1.5.3.1)preincrementare
	Angajat operator++()
	{
		cout << endl << "----- Apel operator ++ preincrementare ------" << endl;
		this->varsta++;
		return *this;
	}
	//1.5.3.2)postincrementare
	Angajat& operator++(int)
	{
		cout << endl << "----- Apel operator ++ postincrementare ------" << endl;
		Angajat copie = *this;
		this->varsta++;
		return copie;
	}

	//1.5.4) Operatorul cast
	explicit operator string ()
	{
		cout << endl << "----- Apel operator cast ------" << endl;
		return this->nume;
	}

	//1.5.5) Operator !
	bool operator!()
	{
		cout << endl << "----- Apel operator ! ------" << endl;
		if (Experienta == 1)
		{
			Experienta = 0;
			return true;
		}
		else
		{
			Experienta = 1;
			return false;
		}
	}

	//1.5.6) Operatorul >
	bool operator>(Angajat a)
	{
		cout << endl << "----- Apel operator > ------" << endl;

		return this->salariu > a.salariu;
	}

	friend bool operator<(const Angajat& a1, const Angajat& a2)
	{
		if (a1.varsta > a2.varsta)
			return true;
		else
			return false;
	}

	//1.5.7) Operatorul ==
	bool operator==(const Angajat& a)
	{
		cout << endl << "----- Apel operator == -----" << endl;
		if (strcmp(this->nume, a.nume) == 0 && this->id == a.id && this->varsta == a.varsta && this->salariu == a.salariu && this->Experienta == a.Experienta && this->mail == a.mail && this->telefon == a.telefon && this->nrFunctii == a.nrFunctii && this->istoricFunctii == a.istoricFunctii && this->nrComisioane == a.nrComisioane && this->comision == a.comision)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//2.1.1) Scrierea in fisier text
	void writeToTextFile(ofstream& out)
	{
		out << this->nume << endl;
		out << this->varsta << endl;
		out << this->salariu << endl;
		out << this->mail << endl;
		out << this->telefon << endl;
		out << this->Experienta << endl;
		out << this->nrComisioane << endl;

		for (int i = 0; i < this->nrComisioane; i++)
			out << this->comision[i] << endl;

		out << this->nrFunctii << endl;
		for (int i = 0; i < this->nrFunctii; i++)
			out << this->istoricFunctii[i] << " ";
	}

	//2.1.2) Citirea in fisier text
	void readFromTextFile(ifstream& in)
	{
		in >> ws;
		delete[] this->nume;
		char aux[100];
		in.getline(aux, 99);
		this->nume = new char[strlen(aux) + 1];
		strcpy(this->nume, aux);
		in >> this->varsta;
		in >> this->salariu;
		in >> ws;
		getline(in, this->mail);
		in >> ws;
		getline(in, this->telefon);
		in >> this->Experienta;
		in >> this->nrComisioane;
		for (int i = 0; i < this->nrComisioane; i++)
		{

			in >> this->comision[i];
		}
		in >> this->nrFunctii;
		delete[] this->istoricFunctii;
		this->istoricFunctii = new string[this->nrFunctii];
		for (int i = 0; i < this->nrFunctii; i++)
		{
			in >> ws;
			getline(in, this->istoricFunctii[i]);
		}

	}

	//2.2.1) Scriere in fisiere binare
	void writeToFile(fstream& f)
	{
		int lgNume = strlen(this->nume) + 1;
		f.write((char*)&lgNume, sizeof(int));
		f.write(this->nume, lgNume);

		f.write((char*)&this->varsta, sizeof(this->varsta));
		f.write((char*)&this->salariu, sizeof(this->salariu));

		int lgMail = (this->mail.length() + 1);
		f.write((char*)&lgMail, sizeof(int));
		f.write(this->mail.data(), lgMail * sizeof(char));
		int lgTelefon = (this->telefon.length() + 1);
		f.write((char*)&lgTelefon, sizeof(int));
		f.write(this->telefon.data(), lgTelefon * sizeof(char));
		f.write((char*)&this->Experienta, sizeof(this->Experienta));
		f.write((char*)&this->nrComisioane, sizeof(this->nrComisioane));
		for (int i = 0; i < this->nrComisioane; i++)
		{
			f.write((char*)&this->comision[i], sizeof(this->comision[i]));
		}

		f.write((char*)&this->nrFunctii, sizeof(this->nrFunctii));
		for (int i = 0; i < this->nrFunctii; i++)
		{
			int lgFunctie = this->istoricFunctii[i].length() + 1;
			f.write((char*)&lgFunctie, sizeof(int));
			f.write(this->istoricFunctii[i].data(), lgFunctie);
		}
	}

	//2.2.2) Citire din fisiere binare
	void readFromFile(fstream& f) {

		int lgNume;
		f.read((char*)&lgNume, sizeof(int));
		char* bufferNume = new char[lgNume];
		f.read(bufferNume, lgNume);
		delete[] this->nume;
		this->nume = new char[strlen(bufferNume) + 1];
		strcpy(this->nume, bufferNume);

		f.read((char*)&this->varsta, sizeof(this->varsta));
		f.read((char*)&this->salariu, sizeof(this->salariu));

		int lgMail = 0;
		f.read((char*)&lgMail, sizeof(int));
		char* bufferMail = new char[lgMail];
		f.read(bufferMail, lgMail);
		this->mail = bufferMail;
		delete[] bufferMail;

		int lgTelefon = 0;
		f.read((char*)&lgTelefon, sizeof(int));
		char* bufferTelefon = new char[lgTelefon];
		f.read(bufferTelefon, lgTelefon);
		this->telefon = bufferTelefon;
		delete[] bufferTelefon;
		f.read((char*)&this->Experienta, sizeof(this->Experienta));

		f.read((char*)&this->nrComisioane, sizeof(this->nrComisioane));
		for (int i = 0; i < this->nrComisioane; i++)
		{
			f.read((char*)&comision[i], sizeof(this->comision[i]));
		}

		delete[] this->istoricFunctii;
		f.read((char*)&this->nrFunctii, sizeof(this->nrFunctii));
		this->istoricFunctii = new string[this->nrFunctii];
		for (int i = 0; i < this->nrFunctii; i++)
		{
			int lgfFunctie;
			f.read((char*)&lgfFunctie, sizeof(int));
			char* bufferFunctie = new char[lgfFunctie];
			f.read(bufferFunctie, lgfFunctie);
			this->istoricFunctii[i] = bufferFunctie;
			delete[] bufferFunctie;
		}
	}

	//2.3.1) Scriere în fișiere CSV
	void writeToCSVFile(ofstream& out)
	{
		out << this->nume << ",";
		out << this->varsta << ",";
		out << this->salariu << ",";
		out << this->mail << ",";
		out << this->telefon << ",";
		out << this->Experienta << ",";
		out << this->nrComisioane << ",";

		for (int i = 0; i < this->nrComisioane; i++)
			out << this->comision[i] << ",";

		out << this->nrFunctii << ",";
		for (int i = 0; i < this->nrFunctii; i++)
			out << this->istoricFunctii[i] << ",";
	}
};

int Angajat::index = 0;

class Animal
{
protected:
	const int id;
	char* tipAnimal;
	int varstaAnimal = 0;
	float pret = 0;
	bool estePui = 0;
	int nrAlimentePermise = 0;
	string* alimentePermise = NULL;
	float* gramajMaximAliment = NULL;
	int nrVaccinuriNecesare = 0;
	string vaccinuriNecesare[30];

public:
	//1.0 Functii accesor
	//1.0.1 Get
	const char* getTipAnimal()
	{
		char* copie = new char[strlen(tipAnimal) + 1];
		strcpy(copie, tipAnimal);
		return copie;
	}
	const int getId()
	{
		return this->id;
	}
	int getVarsta()
	{
		return this->varstaAnimal;
	}
	float getPret()
	{
		return this->pret;
	}
	bool getEstePui()
	{
		return this->estePui;
	}
	int getNrAlimente()
	{
		return this->nrAlimentePermise;
	}
	string* getAlimentePermise()
	{
		return this->alimentePermise;
	}
	float* getGramajMaxAlimente()
	{
		return this->gramajMaximAliment;
	}
	int getNrVaccinuri()
	{
		return this->nrVaccinuriNecesare;
	}
	string* getVaccinuriNecesare()
	{
		return this->vaccinuriNecesare;
	}
	//1.1.1 Set
	void setTipAnimal(const char* tipAnimal)
	{
		if (strlen(tipAnimal) > 2)
		{
			this->tipAnimal = new char[strlen(tipAnimal) + 1];
			strcpy(this->tipAnimal, tipAnimal);
		}
	}
	void setVarsta(int varstaAnimal)
	{
		if (varstaAnimal > 0)
		{
			this->varstaAnimal = varstaAnimal;
		}
	}
	void setPret(float pret)
	{
		if (pret > 0)
		{
			this->pret = pret;
		}
	}
	void setPui(bool estePui)
	{
		if (estePui == 1 || estePui == 0)
		{
			this->estePui = estePui;
		}
	}
	void setAlimente(int nrAlimentePermise, string* alimentePermise, float* gramajMaximAliment)
	{
		delete[] this->alimentePermise;
		delete[] this->gramajMaximAliment;
		if (nrAlimentePermise > 0 && alimentePermise != NULL && gramajMaximAliment != NULL)
		{
			this->nrAlimentePermise = nrAlimentePermise;
			this->alimentePermise = new string[this->nrAlimentePermise];
			this->gramajMaximAliment = new float[this->nrAlimentePermise];
			for (int i = 0; i < this->nrAlimentePermise; i++)
			{
				this->alimentePermise[i] = alimentePermise[i];
			}
			for (int i = 0; i < this->nrAlimentePermise; i++)
			{
				this->gramajMaximAliment[i] = gramajMaximAliment[i];
			}
		}
	}
	void setVaccinuri(int nrVaccinuriNecesare, string* vaccinuriNecesare)
	{
		if (nrVaccinuriNecesare > 0)
		{
			this->nrVaccinuriNecesare = nrVaccinuriNecesare;
			for (int i = 0; i < this->nrVaccinuriNecesare; i++)
			{
				this->vaccinuriNecesare[i] = vaccinuriNecesare[i];
			}
		}
	}

	//1.2 Metode
	float gramajSuma()
	{
		float suma = 0;
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			suma = suma + gramajMaximAliment[i];
		}
		return suma;
	}
	float gramajMediu()
	{
		float suma = 0;
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			suma = suma + gramajMaximAliment[i];
		}
		return suma / this->nrAlimentePermise;
	}

	//1.3.1Constructori fara parametrii
	Animal() :id(0)
	{
		this->tipAnimal = new char[strlen("Anonim") + 1];
		strcpy(this->tipAnimal, "Anonim");
	}
	//1.3.2Constructor cu un parametru
	Animal(int id) : id(id)
	{
		this->tipAnimal = new char[strlen("Anonim") + 1];
		strcpy(this->tipAnimal, "Anonim");
	}

	//1.3.3 Constructor cu toti parametrii
	Animal(const char* tipAnimal, int id, int varstaAnimal, float pret, int nrAlimentePermise, string* alimentePermise, float* gramajMaximAliment, int nrVaccinuriNecesare, string* vaccinuriNecesare, bool estePui) :id(id)
	{
		this->tipAnimal = new char[strlen(tipAnimal) + 1];
		strcpy(this->tipAnimal, tipAnimal);
		this->varstaAnimal = varstaAnimal;
		this->pret = pret;
		this->estePui = estePui;
		if (nrAlimentePermise > 0 && alimentePermise != NULL && gramajMaximAliment != NULL)
		{
			this->nrAlimentePermise = nrAlimentePermise;
			this->alimentePermise = new string[this->nrAlimentePermise];
			this->gramajMaximAliment = new float[this->nrAlimentePermise];
			for (int i = 0; i < this->nrAlimentePermise; i++)
			{
				this->alimentePermise[i] = alimentePermise[i];
			}
			for (int i = 0; i < this->nrAlimentePermise; i++)
			{
				this->gramajMaximAliment[i] = gramajMaximAliment[i];
			}
			if (nrVaccinuriNecesare > 0)
			{
				this->nrVaccinuriNecesare = nrVaccinuriNecesare;
				for (int i = 0; i < this->nrVaccinuriNecesare; i++)
				{
					this->vaccinuriNecesare[i] = vaccinuriNecesare[i];
				}
			}
		}

	}

	//1.3.4 Constructor copy
	Animal(const Animal& an) : id(an.id)
	{
		this->tipAnimal = new char[strlen(an.tipAnimal) + 1];
		strcpy(this->tipAnimal, an.tipAnimal);
		this->varstaAnimal = an.varstaAnimal;
		this->pret = an.pret;
		this->estePui = an.estePui;
		if (an.nrAlimentePermise > 0 && an.alimentePermise != NULL && an.gramajMaximAliment != NULL)
		{
			this->nrAlimentePermise = an.nrAlimentePermise;
			this->alimentePermise = new string[this->nrAlimentePermise];
			this->gramajMaximAliment = new float[this->nrAlimentePermise];
			for (int i = 0; i < this->nrAlimentePermise; i++)
			{
				this->alimentePermise[i] = an.alimentePermise[i];
			}
			for (int i = 0; i < this->nrAlimentePermise; i++)
			{
				this->gramajMaximAliment[i] = an.gramajMaximAliment[i];
			}
		}
		else {
			this->nrAlimentePermise = 0;
			this->alimentePermise = NULL;
			this->gramajMaximAliment = NULL;

		}
		if (an.nrVaccinuriNecesare > 0)
		{
			this->nrVaccinuriNecesare = an.nrVaccinuriNecesare;
			for (int i = 0; i < this->nrVaccinuriNecesare; i++)
			{
				this->vaccinuriNecesare[i] = an.vaccinuriNecesare[i];
			}
		}
	}

	//1.3.5 Destructor
	~Animal()
	{
		delete[] this->tipAnimal;
		if (this->alimentePermise != NULL)
		{
			delete[] this->alimentePermise;
		}
		if (this->gramajMaximAliment != NULL)
		{
			delete[] this->gramajMaximAliment;
		}
	}

	//1.3.6 Operator egal
	Animal& operator=(const Animal& an)
	{
		if (this != &an)
		{
			delete[] this->tipAnimal;
			if (this->alimentePermise != NULL)
			{
				delete[] this->alimentePermise;
			}
			if (this->gramajMaximAliment != NULL)
			{
				delete[] this->gramajMaximAliment;
			}

			this->tipAnimal = new char[strlen(an.tipAnimal) + 1];
			strcpy(this->tipAnimal, an.tipAnimal);
			this->varstaAnimal = an.varstaAnimal;
			this->pret = an.pret;
			this->estePui = an.estePui;
			if (an.nrAlimentePermise > 0 && an.alimentePermise != NULL && an.gramajMaximAliment != NULL)
			{
				this->nrAlimentePermise = an.nrAlimentePermise;
				this->alimentePermise = new string[this->nrAlimentePermise];
				this->gramajMaximAliment = new float[this->nrAlimentePermise];
				for (int i = 0; i < this->nrAlimentePermise; i++)
				{
					this->alimentePermise[i] = an.alimentePermise[i];
				}
				for (int i = 0; i < this->nrAlimentePermise; i++)
				{
					this->gramajMaximAliment[i] = an.gramajMaximAliment[i];
				}
			}
			else {
				this->nrAlimentePermise = 0;
				this->alimentePermise = NULL;
				this->gramajMaximAliment = NULL;

			}
			if (an.nrVaccinuriNecesare > 0)
			{
				this->nrVaccinuriNecesare = an.nrVaccinuriNecesare;
				for (int i = 0; i < this->nrVaccinuriNecesare; i++)
				{
					this->vaccinuriNecesare[i] = an.vaccinuriNecesare[i];
				}
			}
		}
		return *this;
	}

	//1.4.1 Operator<<
	friend ostream& operator<<(ostream& out, const Animal& an)
	{
		out << endl << "-----------------------------------------------------------------" << endl;
		out << "Tipul Animal: " << an.tipAnimal << endl;
		out << "ID Animal: " << an.id << endl;;
		out << "Pretul Animal: " << an.pret << endl;
		out << "Varsta Animal: " << an.varstaAnimal << endl;

		out << "Este animalul un pui? " << endl;
		if (an.estePui == 1)
			out << "Da!" << endl;
		else
			out << "Nu!" << endl;
		out << "Numarul de alimente permise: " << an.nrAlimentePermise << endl;
		out << "Alimentele permise sunt:" << endl;
		for (int i = 0; i < an.nrAlimentePermise; i++)
		{
			out << an.alimentePermise[i] << "  ";
		}
		out << endl;
		out << "Gramaj maxim:" << endl;
		for (int i = 0; i < an.nrAlimentePermise; i++)
		{
			out << "Gramajul maxim alocat pentru alimentul permis " << i + 1 << " este " << an.gramajMaximAliment[i] << endl;
		}
		out << "NrVaccinuriNecesare:" << an.nrVaccinuriNecesare << endl;
		out << "VaccinuriNecesare" << endl;
		for (int i = 0; i < an.nrVaccinuriNecesare; i++)
		{
			out << an.vaccinuriNecesare[i] << "  ";
		}
		out << endl << "-----------------------------------------------------------------" << endl;
		return out;
	}

	//1.4.2 Operator>>
	friend istream& operator>>(istream& in, Animal& an)
	{
		cout << endl << "----- Apel operator >> -----" << endl;
		cout << endl << "Introduceti datele cerute pentru un nou animal: " << endl;
		cout << "Tipul Animal: " << endl;
		in >> ws;
		delete[]an.tipAnimal;
		char aux[100];
		in.getline(aux, 99);
		an.tipAnimal = new char[strlen(aux) + 1];
		strcpy(an.tipAnimal, aux);
		cout << "Pretul Animal: " << endl;
		in >> an.pret;
		cout << "Varsta Animal: " << endl;
		in >> an.varstaAnimal;
		cout << "Este pui? " << endl;
		in >> an.estePui;
		cout << "Numarul de alimente permise: " << endl;
		in >> an.nrAlimentePermise;

		delete[] an.alimentePermise;
		an.alimentePermise = new string[an.nrAlimentePermise];

		cout << "Alimentele permise: " << endl;
		for (int i = 0; i < an.nrAlimentePermise; i++)
		{
			in >> ws;
			getline(in, an.alimentePermise[i]);
			cout << "  ";
		}
		delete[] an.gramajMaximAliment;
		an.gramajMaximAliment = new float[an.nrAlimentePermise];
		cout << "Gramajul maxim alocat pentru fiecare aliment permis: " << endl;
		for (int i = 0; i < an.nrAlimentePermise; i++)
		{
			in >> an.gramajMaximAliment[i];
			cout << "  ";
		}
		cout << "NrVaccinuriNecesare: " << endl;
		in >> an.nrVaccinuriNecesare;
		cout << "Vaccinuri Necesare: " << endl;
		for (int i = 0; i < an.nrVaccinuriNecesare; i++)
		{
			in >> ws;
			getline(in, an.vaccinuriNecesare[i]);
			cout << "  ";
		}

		return in;
	}

	//1.5.1 Operatorul de indexare
	string operator[](int pozitie)
	{
		cout << endl << "----- Apel operator [] -----" << endl;
		if (pozitie >= 0 && pozitie < this->nrAlimentePermise)
			return this->alimentePermise[pozitie];
	}

	//1.5.2 Operatorul +
	Animal operator+(float val) {
		cout << endl << "----- Apel operator + -----" << endl;
		Animal copie = *this;
		copie.pret += val;
		return copie;
	}

	//1.5.3 Operatorul ++
	Animal& operator++()
	{
		cout << endl << "----- Apel operator ++ preincrementare ------" << endl;
		this->pret++;
		return *this;
	}

	Animal operator++(int)
	{
		cout << endl << "----- Apel operator ++ post incrementare-----" << endl;
		Animal copie = *this;
		this->pret++;
		return copie;
	}

	//1.5.4 Operatorul Cast
	explicit operator int()
	{
		cout << endl << "----- Apel operator cast-----" << endl;
		return this->pret;
	}

	//1.5.5 Operatorul !
	bool operator!()
	{
		cout << endl << "----- Apel operator ! -----" << endl;
		if (this->estePui == 1)
		{
			this->estePui = 0;
			return false;
		}
		else
		{
			this->estePui = 1;
			return true;
		}
	}

	//1.5.6 Operatorul<
	bool operator<(Animal& a)
	{
		cout << endl << "----- Apel operator < -----" << endl;
		return this->pret < a.pret;
	}

	//1.5.7 Operatorul ==
	bool operator==(const Animal& a)
	{
		cout << endl << "----- Apel operator == -----" << endl;
		if (strcmp(this->tipAnimal, a.tipAnimal) == 0 && this->id == a.id && this->varstaAnimal == a.varstaAnimal && this->pret == a.pret && this->estePui == a.estePui && this->nrAlimentePermise == a.nrAlimentePermise && this->alimentePermise == a.alimentePermise && this->gramajMaximAliment == a.gramajMaximAliment && this->nrVaccinuriNecesare == a.nrVaccinuriNecesare && this->vaccinuriNecesare == a.vaccinuriNecesare)
		{
			return true;
		}
		else
			return false;
	}

	//2.1.1 Scrierea in fisier text
	void writeToTextFile(ofstream& out)
	{

		out << this->tipAnimal << endl;
		out << this->pret << endl;
		out << this->varstaAnimal << endl;
		out << this->estePui << endl;
		out << this->nrAlimentePermise << endl;
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			out << this->alimentePermise[i] << endl;
		}
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			out << this->gramajMaximAliment[i] << endl;
		}
		out << this->nrVaccinuriNecesare << endl;
		for (int i = 0; i < this->nrVaccinuriNecesare; i++)
		{
			out << this->vaccinuriNecesare[i] << endl;
		}

	}

	//2.1.2 Citirea din fisier text
	void readFromTextFile(ifstream& in)
	{

		in >> ws;
		delete[]this->tipAnimal;
		char aux[100];
		in.getline(aux, 99);
		this->tipAnimal = new char[strlen(aux) + 1];
		strcpy(this->tipAnimal, aux);
		in >> this->pret;
		in >> this->varstaAnimal;
		in >> this->estePui;
		in >> this->nrAlimentePermise;
		delete[] this->alimentePermise;
		this->alimentePermise = new string[this->nrAlimentePermise];
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			in >> ws;
			getline(in, this->alimentePermise[i]);
		}
		delete[] this->gramajMaximAliment;
		this->gramajMaximAliment = new float[this->nrAlimentePermise];
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			in >> this->gramajMaximAliment[i];
		}
		in >> this->nrVaccinuriNecesare;
		for (int i = 0; i < this->nrVaccinuriNecesare; i++)
		{
			in >> ws;
			getline(in, this->vaccinuriNecesare[i]);
		}
	}

	//2.2.1 Scriere în fișier binar
	void writeToFile(fstream& f)
	{
		int lgTip = strlen(this->tipAnimal) + 1;
		f.write((char*)&lgTip, sizeof(int));
		f.write(this->tipAnimal, lgTip);

		f.write((char*)&this->varstaAnimal, sizeof(this->varstaAnimal));
		f.write((char*)&this->pret, sizeof(this->pret));
		f.write((char*)&this->estePui, sizeof(this->estePui));

		f.write((char*)&this->nrAlimentePermise, sizeof(this->nrAlimentePermise));
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			int lgAlimente = this->alimentePermise[i].length() + 1;
			f.write((char*)&lgAlimente, sizeof(int));
			f.write(this->alimentePermise[i].data(), lgAlimente);
		}
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			f.write((char*)&this->gramajMaximAliment[i], sizeof(this->gramajMaximAliment[i]));
		}
		f.write((char*)&this->nrVaccinuriNecesare, sizeof(this->nrVaccinuriNecesare));
		for (int i = 0; i < this->nrVaccinuriNecesare; i++)
		{
			int lgVaccin = this->vaccinuriNecesare[i].length() + 1;
			f.write((char*)&lgVaccin, sizeof(int));
			f.write(this->vaccinuriNecesare[i].data(), lgVaccin);
		}
	}

	//2.2.2 Citire din fișier binar
	void readFromFile(fstream& f)
	{
		int lgTip;
		f.read((char*)&lgTip, sizeof(int));
		char* bufferTip = new char[lgTip];
		f.read(bufferTip, lgTip);
		delete[] this->tipAnimal;
		this->tipAnimal = new char[strlen(bufferTip) + 1];
		strcpy(this->tipAnimal, bufferTip);

		f.read((char*)&this->varstaAnimal, sizeof(this->varstaAnimal));
		f.read((char*)&this->pret, sizeof(this->pret));
		f.read((char*)&this->estePui, sizeof(this->estePui));

		f.read((char*)&this->nrAlimentePermise, sizeof(this->nrAlimentePermise));
		delete[] this->alimentePermise;
		this->alimentePermise = new string[this->nrAlimentePermise];
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			int lgAlimente;
			f.read((char*)&lgAlimente, sizeof(int));
			char* bufferAlimente = new char[lgAlimente];
			f.read(bufferAlimente, lgAlimente);
			this->alimentePermise[i] = bufferAlimente;
			delete[] bufferAlimente;
		}
		delete[] this->gramajMaximAliment;
		this->gramajMaximAliment = new float[this->nrAlimentePermise];
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			f.read((char*)&this->gramajMaximAliment[i], sizeof(this->gramajMaximAliment[i]));
		}
		f.read((char*)&this->nrVaccinuriNecesare, sizeof(this->nrVaccinuriNecesare));
		int lgVaccin;
		for (int i = 0; i < this->nrVaccinuriNecesare; i++)
		{
			f.read((char*)&lgVaccin, sizeof(int));
			char* bufferVaccin = new char[lgVaccin];
			f.read(bufferVaccin, lgVaccin);
			this->vaccinuriNecesare[i] = bufferVaccin;
			delete[] bufferVaccin;
		}
	}

	//2.3.1 Scriere în fișier CSV
	void writeToCSVFile(ofstream& out) {
		out << this->tipAnimal << ",";
		out << this->pret << ",";
		out << this->varstaAnimal << ",";
		out << this->estePui << ",";
		out << this->nrAlimentePermise << ",";
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			out << this->alimentePermise[i] << ",";
		}
		for (int i = 0; i < this->nrAlimentePermise; i++)
		{
			out << this->gramajMaximAliment[i] << ",";
		}
		out << this->nrVaccinuriNecesare << ",";
		for (int i = 0; i < this->nrVaccinuriNecesare; i++)
		{
			out << this->vaccinuriNecesare[i] << ",";
		}

	}
};

enum UM
{
	Litru = 1, Kg = 2, Bucati = 3
};

class Produs : public Ifile
{
private:
	const int idProdus;
	static int index;
	static int TVA;
protected:
	UM um = UM::Kg;
	string nume = "Anonim";
	char* producator;
	float pret = 0;
	int nrIngrediente = 0;
	string* compozitie = NULL;
	int nrZile = 0;
	float istoricPreturi[30];
	bool esteMancare = 0;


public:
	//1.0
	//1.1.1 Get
	int getIdProdus()
	{
		return this->idProdus;
	}
	static int getTVA()
	{
		return Produs::TVA;
	}
	string getNume()
	{
		return this->nume;
	}
	UM getUM()
	{
		return this->um;
	}
	char* getProducator()
	{
		char* copie = new char[strlen(producator) + 1];
		strcpy(copie, producator);
		return copie;
	}
	float getPret()
	{
		return this->pret;
	}
	bool getEsteMancare()
	{
		return this->esteMancare;
	}
	int getNrIngrediente()
	{
		return this->nrIngrediente;
	}
	string* getCompozitie()
	{
		return this->compozitie;
	}
	int getNrZile()
	{
		return this->nrZile;
	}
	float* getIstoricPreturi()
	{
		return this->istoricPreturi;
	}
	//1.1.2 Set
	void setNume(string nume)
	{
		if (nume.size() > 2)
		{
			this->nume = nume;
		}
	}
	void setUM(UM um)
	{
		if (um < 3 && um >= 0)
		{
			this->um = um;
		}
	}
	void setProducator(const char* producator)
	{
		if (strlen(producator) > 2)
		{
			delete[] this->producator;
			this->producator = new char[strlen(producator) + 1];
			strcpy(this->producator, producator);
		}

	}
	void setPret(float pret)
	{
		if (pret > 0)
		{
			this->pret = pret;
		}
	}
	void seteEsteMancare(bool esteMancare)
	{
		if (esteMancare == 1 || esteMancare == 0)
		{
			this->esteMancare = esteMancare;
		}
	}
	void setCompozitie(int nrIngrediente, string* compozitie)
	{
		if (this->compozitie != NULL)
		{
			delete[] this->compozitie;
		}
		if (compozitie != NULL && nrIngrediente > 0)
		{
			this->nrIngrediente = nrIngrediente;
			this->compozitie = new string[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->compozitie[i] = compozitie[i];
			}
		}

	}
	void setIstoricPreturi(int nrZile, float* istoricPreturi)
	{
		if (nrZile > 0)
		{
			this->nrZile = nrZile;
			for (int i = 0; i < this->nrZile; i++)
				this->istoricPreturi[i] = istoricPreturi[i];
		}
	}

	//1.2 Metode
	float pretFaraTVA()
	{
		return this->pret - TVA / 100.0 * this->pret;
	}
	float	mediaPreturilor()
	{
		float suma = 0;
		for (int i = 0; i < this->nrZile; i++)
		{
			suma = suma + istoricPreturi[i];
		}
		return suma / this->nrZile;
	}

	//1.3.1 Constructor fara parametrii
	Produs() : idProdus(++index)
	{
		this->producator = new char[strlen("Anonim") + 1];
		strcpy(this->producator, "Anonim");
	}

	//1.3.2Constructor cu 1 parametru 
	Produs(const char* nume) : idProdus(++index)
	{
		this->producator = new char[strlen(nume) + 1];
		strcpy(this->producator, nume);
	}

	//1.3.3 Constructor cu toti parametrii
	Produs(string nume, const char* producator, UM um, float pret, int nrIngrediente, string* compozitie, int nrZile, float* istoricPreturi, bool esteMancare) : idProdus(++index)
	{
		this->nume = nume;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->um = um;
		this->pret = pret;
		this->esteMancare = esteMancare;
		if (nrIngrediente > 0 && compozitie != NULL)
		{
			this->nrIngrediente = nrIngrediente;
			this->compozitie = new string[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				this->compozitie[i] = compozitie[i];
			}

		}
		if (nrZile > 0)
		{
			this->nrZile = nrZile;
			for (int i = 0; i < this->nrZile; i++)
				this->istoricPreturi[i] = istoricPreturi[i];
		}
	}
	//1.3.4Constructorul copy
	Produs(const Produs& p) : idProdus(p.idProdus)
	{
		this->nume = p.nume;
		this->producator = new char[strlen(p.producator) + 1];
		strcpy(this->producator, p.producator);
		this->um = p.um;
		this->pret = p.pret;
		this->esteMancare = p.esteMancare;
		if (p.nrIngrediente > 0 && p.compozitie != NULL)
		{
			this->nrIngrediente = p.nrIngrediente;

			this->compozitie = new string[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				this->compozitie[i] = p.compozitie[i];
			}

		}
		else
		{
			this->nrIngrediente = NULL;
			this->compozitie = NULL;
		}
		if (p.nrZile > 0)
		{
			this->nrZile = p.nrZile;
			for (int i = 0; i < this->nrZile; i++)
				this->istoricPreturi[i] = p.istoricPreturi[i];
		}
	}

	//1.3.5 Destructor
	~Produs()
	{
		delete[] this->producator;
		if (this->compozitie != NULL)
		{
			delete[] this->compozitie;
		}

	}

	//1.3.6 Operatorul egal
	Produs& operator=(const Produs& p)
	{
		if (this != &p)
		{
			delete[] this->producator;
			if (this->compozitie != NULL)
			{
				delete[] this->compozitie;
			}
			this->nume = p.nume;
			this->producator = new char[strlen(p.producator) + 1];
			strcpy(this->producator, p.producator);
			this->um = p.um;
			this->pret = p.pret;
			this->esteMancare = p.esteMancare;
			if (p.nrIngrediente > 0 && p.compozitie != NULL)
			{
				this->nrIngrediente = p.nrIngrediente;

				this->compozitie = new string[this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++)
				{
					this->compozitie[i] = p.compozitie[i];
				}

			}
			if (p.nrZile > 0)
			{
				this->nrZile = p.nrZile;
				for (int i = 0; i < this->nrZile; i++)
					this->istoricPreturi[i] = p.istoricPreturi[i];
			}
		}
		return *this;
	}

	//1.4.1 Operatorul <<
	friend ostream& operator<<(ostream& out, const Produs& p)
	{
		out << endl << "----------------------------------------------------------------------------------" << endl;
		out << "Numele produsului este: " << p.nume << endl;
		out << "Id-ul produsului este: " << p.idProdus << endl;
		out << "Numele producatorului este: " << p.producator << endl;
		out << "Pretul produsului este: " << p.pret << endl;
		out << "TVA-ul asociat produsului este: " << p.TVA << endl;
		out << "Unitatea de masura a produsului este: ";
		if (p.um == 1)
			out << "Litri" << endl;
		else if (p.um == 2)
			out << "Kg" << endl;
		else if (p.um == 3)
			out << "Bucati" << endl;
		out << "Nr de ingrediente asociate produsului este: " << p.nrIngrediente << endl;
		out << "Numele ingredientelor asociate produsului este:" << endl;
		for (int i = 0; i < p.nrIngrediente; i++)
		{
			out << p.compozitie[i] << "  ";
		}
		out << endl << "Nr de zile pe care studiem preturile asociate produsului este: " << p.nrZile << endl;
		out << "Istoricul preturilor asociate produsului este:" << endl;
		for (int i = 0; i < p.nrZile; i++)
		{
			out << p.istoricPreturi[i] << "  ";
		}
		out << endl << "Este produsul de mancare pentru animale? ";
		if (p.esteMancare == 1)
			out << "Da!" << endl;
		else
			out << "Nu!" << endl;
		out << "----------------------------------------------------------------------------------" << endl;
		return out;
	}

	//1.4.2 Operatorul >>
	friend istream& operator>>(istream& in, Produs& p)
	{
		cout << "Introduceti datele cerute pentru un nou produse!";
		cout << "Numele produsului este: ";
		in >> ws;
		getline(in, p.nume);
		cout << "Numele producatorului este: ";
		in >> ws;
		delete[]p.producator;
		char aux[100];
		in.getline(aux, 99);
		p.producator = new char[strlen(aux) + 1];
		strcpy(p.producator, aux);
		cout << "Unitatea de masura a produsului este(folositi cifre: 1-litrii,2-kg, 3-bucati): ";
		int opt;
		in >> opt;
		switch (opt) {
		case 1: p.um = Litru; break;
		case 2:p.um = Kg; break;
		case 3: p.um = Bucati; break;
		default:p.um = Bucati; break;
		}
		cout << "Pretul produsului este: ";
		in >> p.pret;
		cout << "Nr de ingrediente asociate produsului este: ";
		in >> p.nrIngrediente;
		cout << "Numele ingredientelor asociate produsului este:" << endl;
		delete[] p.compozitie;
		p.compozitie = new string[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++)
		{
			in >> ws;
			getline(in, p.compozitie[i]);
		}
		cout << endl << "Nr de zile pe care studiem preturile asociate produsului este: ";
		in >> p.nrZile;
		cout << "Istoricul preturilor asociate produsului este:" << endl;
		for (int i = 0; i < p.nrZile; i++)
			in >> p.istoricPreturi[i];
		cout << endl << "Este produsul de mancare pentru animale? (0 pt nu, 1 pt da)";
		in >> p.esteMancare;

		return in;
	}

	//1.5.1 Operatorul pentru indexare
	string operator[](int pozitie) {
		cout << "----- Apel operator  [] -----" << endl;
		if (pozitie >= 0 && pozitie < this->nrIngrediente)
			return this->compozitie[pozitie];
		else
			return "Pozitia respectiva nu exista";
	}

	//1.5.2 Operatorul +
	Produs operator+(float val) {
		cout << endl << "Apel operator +" << endl;
		Produs copie = *this;
		copie.pret += val;
		return copie;
	}
	//1.5.3 Operatorul ++
	Produs& operator++()
	{
		cout << endl << "----- Apel operator ++ preincrementare -----" << endl;
		this->pret++;
		return *this;
	}

	Produs operator++(int)
	{
		cout << endl << "----- Apel operator ++ postincrementare -----" << endl;
		Produs copie = *this;
		this->pret++;
		return copie;
	}

	//1.5.4 Operator cast
	explicit operator string() {
		cout << endl << "----- Apel operator cast -----" << endl;
		return this->nume;
	}

	//1.5.5 Opeartor negatie
	bool operator!() {
		cout << endl << "----- Apel operator ! -----" << endl;
		if (this->esteMancare == true)
		{
			this->esteMancare = false;
			return true;
		}
		else
		{
			this->esteMancare = true;
			return false;
		}
	}

	//1.5.6 Operator bool
	bool operator>=(Produs p) {
		cout << endl << "----- Apel operator >= -----" << endl;
		return this->pret >= p.pret;
	}

	friend bool operator<(const Produs& p1, const Produs& p2)
	{
		if (p1.pret < p2.pret)
			return true;
		else
			return false;
	}
	//1.5.7 Operator ==
	bool operator==(const Produs& p)
	{
		cout << endl << "----- Apel operator == -----" << endl;
		if (this->idProdus == p.idProdus && this->um == p.um && this->nume == p.nume && this->idProdus == p.idProdus && strcmp(this->producator, p.producator) == 0 && this->nrIngrediente == p.nrIngrediente && this->compozitie == p.compozitie && this->nrZile == p.nrZile && this->istoricPreturi == p.istoricPreturi && this->esteMancare == p.esteMancare)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//2.1.1 Scrierea in fisier text
	void writeToTextFile(ofstream& out)
	{
		out << this->nume << endl;
		out << this->producator << endl;
		out << this->pret << endl;
		out << this->um << endl;
		out << this->nrIngrediente << endl;
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			out << this->compozitie[i] << endl;
		}
		out << this->nrZile << endl;
		for (int i = 0; i < this->nrZile; i++)
		{
			out << this->istoricPreturi[i] << endl;
		}
		out << this->esteMancare << endl;
	}

	//2.1.1 Citirea din fisier text
	void readFromTextFile(ifstream& in)
	{

		in >> ws;
		getline(in, this->nume);
		in >> ws;
		delete[]this->producator;
		char aux[100];
		in.getline(aux, 99);
		this->producator = new char[strlen(aux) + 1];
		strcpy(this->producator, aux);
		in >> this->pret;
		int opt;
		in >> opt;
		switch (opt) {
		case 1: this->um = Litru; break;
		case 2:this->um = Kg; break;
		case 3: this->um = Bucati; break;
		default:this->um = Bucati; break;
		}

		in >> this->nrIngrediente;
		delete[] this->compozitie;
		this->compozitie = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			in >> ws;
			getline(in, this->compozitie[i]);
		}
		in >> this->nrZile;
		for (int i = 0; i < this->nrZile; i++)
		{
			in >> this->istoricPreturi[i];
		}
		in >> this->esteMancare;
	}

	//2.2.1 Scrierea in fisier binar
	void writeToFile(fstream& f)
	{
		int lgNume = this->nume.length() + 1;
		f.write((char*)&lgNume, sizeof(lgNume));
		f.write(this->nume.data(), lgNume * sizeof(char));

		int lgProducator = strlen(this->producator) + 1;
		f.write((char*)&lgProducator, sizeof(int));
		f.write(this->producator, lgProducator);

		f.write((char*)&this->pret, sizeof(this->pret));
		f.write((char*)&this->um, sizeof(this->um));
		f.write((char*)&this->nrIngrediente, sizeof(this->nrIngrediente));
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			int lgCompozitie = this->compozitie[i].length() + 1;
			f.write((char*)&lgCompozitie, sizeof(int));
			f.write(this->compozitie[i].data(), lgCompozitie);
		}
		f.write((char*)&this->nrZile, sizeof(this->nrZile));
		for (int i = 0; i < this->nrZile; i++)
		{
			f.write((char*)&this->istoricPreturi[i], sizeof(this->istoricPreturi[i]));
		}
		f.write((char*)&this->esteMancare, sizeof(this->esteMancare));
	}

	//2.2.2 Citirea din fisier binar
	void readFromFile(fstream& f)
	{
		int lgNume;
		f.read((char*)&lgNume, sizeof(int));
		char* bufferNume = new char[lgNume];
		f.read(bufferNume, lgNume);
		this->nume = bufferNume;
		delete[] bufferNume;

		int lgProducator;
		f.read((char*)&lgProducator, sizeof(int));
		char* bufferProducator = new char[lgProducator];
		f.read(bufferProducator, lgProducator);
		delete[] this->producator;
		this->producator = new char[strlen(bufferProducator) + 1];
		strcpy(this->producator, bufferProducator);

		f.read((char*)&this->pret, sizeof(this->pret));
		f.read((char*)&this->um, sizeof(this->um));
		f.read((char*)&this->nrIngrediente, sizeof(this->nrIngrediente));
		delete[] this->compozitie;
		this->compozitie = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			int lgProduse;
			f.read((char*)&lgProduse, sizeof(int));
			char* bufferProduse = new char[lgProduse];
			f.read(bufferProduse, lgProduse);
			this->compozitie[i] = bufferProduse;
			delete[] bufferProduse;
		}

		f.read((char*)&this->nrZile, sizeof(this->nrZile));
		for (int i = 0; i < this->nrZile; i++)
		{
			f.read((char*)&this->istoricPreturi[i], sizeof(this->istoricPreturi[i]));
		}
		f.read((char*)&this->esteMancare, sizeof(this->esteMancare));
	}

	//2.3.1 Scrierea in fisier CSV
	void writeToCSVFile(ofstream& out) {
		out << this->nume << ",";
		out << this->producator << ",";
		out << this->pret << ",";
		out << this->um << ",";
		out << this->nrIngrediente << ",";
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			out << this->compozitie[i] << ",";
		}
		out << this->nrZile << ",";
		for (int i = 0; i < this->nrZile; i++)
		{
			out << this->istoricPreturi[i] << ",";
		}
		out << this->esteMancare << ",";

	}
	//3.3 Metode virtuale
	virtual float calculPretProdusEuro(float cursValutarEuro) 
	{
		return this->pret / cursValutarEuro;
	}

	virtual float calculPretProdusFaraTVA()
	{
		return (this->pret - this->pret * 0.19);
	}
};

int Produs::index = 0;
int Produs::TVA = 0;

class Comanda : public Ifile,public ClasaAbstracta
{
	string idComanda = "Anonim";
	char* numeClient;
	float pretComanda = 0;
	int nrProduse = 0;
	string* produseComanda = NULL;
	int nrReduceri = 0;
	float valReduceri[30];
	bool contineAnimal = 0;

public:

	//1.1
	//1.1.1 Get 
	string getID()
	{
		return this->idComanda;
	}
	char* getNumeClient()
	{
		char* copie = new char[strlen(numeClient) + 1];
		strcpy(copie, numeClient);
		return copie;
	}
	float getPretComanda()
	{
		return this->pretComanda;
	}
	int getNrProduse()
	{
		return this->nrProduse;
	}
	int getNrReduceri()
	{
		return this->nrReduceri;
	}
	string* getProduse()
	{
		return this->produseComanda;
	}
	float* getReduceri()
	{
		return this->valReduceri;
	}
	bool getContineAnimal()
	{
		return this->contineAnimal;
	}

	//1.1.2 Set 
	void setID(string idComanda)
	{
		if (idComanda.size() > 2)
		{
			this->idComanda = idComanda;
		}
	}
	void setNumeClient(const char* numeClient)
	{
		if (strlen(numeClient) > 2) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}
	}
	void setPret(float pretComanda)
	{
		if (pretComanda > 0)
		{
			this->pretComanda = pretComanda;
		}
	}
	void setContineAnimal(bool contineAnimal)
	{
		if (contineAnimal == 0 || contineAnimal == 1)
		{
			this->contineAnimal = contineAnimal;
		}
	}
	void setProduse(int nrProduse, string* produseComanda)
	{
		delete[] this->produseComanda;
		if (nrProduse > 0 && produseComanda != NULL)
		{
			this->nrProduse = nrProduse;
			this->produseComanda = new string[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->produseComanda[i] = produseComanda[i];
			}
		}
	}
	void setReduceri(int nrReduceri, float* valReduceri)
	{
		if (nrReduceri > 0)
		{
			this->nrReduceri = nrReduceri;
			for (int i = 0; i < this->nrReduceri; i++)
			{
				this->valReduceri[i] = valReduceri[i];
			}
		}
	}

	//1.2
	float SumaReduceri()
	{
		float suma = 0;
		for (int i = 0; i < this->nrReduceri; i++)
		{
			suma = suma + this->valReduceri[i];
		}

		return suma;
	}
	float mediaReduceri()
	{
		float suma = 0;
		for (int i = 0; i < this->nrReduceri; i++)
		{
			suma = suma + this->valReduceri[i];
		}

		return suma / this->nrReduceri;
	}

	//1.3.1 - Constructor fara parametrii
	Comanda()
	{
		this->numeClient = new char[strlen("Anonim") + 1];
		strcpy(this->numeClient, "Anonim");
	}

	//1.3.2 - Constructor cu un parametru
	Comanda(string idComanda, const char* numeClient, float pretComanda, bool contineAnimal, int nrProduse, string* produseComanda, int nrReduceri, float* valReduceri)
	{
		this->idComanda = idComanda;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy(this->numeClient, numeClient);
		this->pretComanda = pretComanda;
		this->contineAnimal = contineAnimal;
		if (nrProduse > 0 && produseComanda != NULL)
		{
			this->nrProduse = nrProduse;
			this->produseComanda = new string[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->produseComanda[i] = produseComanda[i];
			}
		}
		if (nrReduceri > 0)
		{
			this->nrReduceri = nrReduceri;
			for (int i = 0; i < this->nrReduceri; i++)
			{
				this->valReduceri[i] = valReduceri[i];
			}
		}

	}

	//1.3.3 Constructor cu toti parametrii
	Comanda(string idComanda, const char* numeClient)
	{
		this->idComanda = idComanda;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy(this->numeClient, numeClient);
	}

	//1.3.4 Constructor copy
	Comanda(const Comanda& c)
	{
		this->idComanda = c.idComanda;
		this->numeClient = new char[strlen(c.numeClient) + 1];
		strcpy(this->numeClient, c.numeClient);
		this->pretComanda = c.pretComanda;
		this->contineAnimal = c.contineAnimal;
		if (c.nrProduse > 0 && c.produseComanda != NULL)
		{
			this->nrProduse = c.nrProduse;
			this->produseComanda = new string[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->produseComanda[i] = c.produseComanda[i];
			}
		}
		if (c.nrReduceri > 0)
		{
			this->nrReduceri = c.nrReduceri;
			for (int i = 0; i < this->nrReduceri; i++)
			{
				this->valReduceri[i] = c.valReduceri[i];
			}
		}
	}

	//1.3.5 Operator =
	Comanda& operator=(const Comanda& c)
	{
		if (this != &c)
		{
			delete[] this->numeClient;
			if (produseComanda != NULL)
			{
				delete[] this->produseComanda;
			}
			this->idComanda = c.idComanda;
			this->numeClient = new char[strlen(c.numeClient) + 1];
			strcpy(this->numeClient, c.numeClient);
			this->pretComanda = c.pretComanda;
			this->contineAnimal = c.contineAnimal;
			if (c.nrProduse > 0 && c.produseComanda != NULL)
			{
				this->nrProduse = c.nrProduse;
				this->produseComanda = new string[this->nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					this->produseComanda[i] = c.produseComanda[i];
				}
			}
			if (c.nrReduceri > 0)
			{
				this->nrReduceri = c.nrReduceri;
				for (int i = 0; i < this->nrReduceri; i++)
				{
					this->valReduceri[i] = c.valReduceri[i];
				}
			}
		}
		return *this;
	}

	//1.3.6 Destructor
	~Comanda()
	{
		delete[] this->numeClient;
		if (produseComanda != NULL)
		{
			delete[] this->produseComanda;
		}
	}

	//1.4.1 Operator <<
	friend ostream& operator<<(ostream& out, const Comanda& c)
	{
		out << endl << "------------------------------------------------------------" << endl;
		out << "Id Comanda: " << c.idComanda << endl;
		out << "Nume Client: " << c.numeClient << endl;
		out << " Pret Comanda: " << c.pretComanda << endl;
		out << "Numar Produse din Comanda: " << c.nrProduse << endl;
		out << "Exista in comanda si un animal?" << c.contineAnimal << endl;
		out << "Produsele din comanda: " << endl;
		for (int i = 0; i < c.nrProduse; i++)
		{
			out << c.produseComanda[i] << "  ";
		}
		out << endl;
		out << "Numar Reduceri per Comanda: " << c.nrReduceri << endl;
		out << "Reducerile din comanda: " << endl;
		for (int i = 0; i < c.nrReduceri; i++)
		{
			out << c.valReduceri[i] << "   ";
		}
		out << endl;
		out << endl << "------------------------------------------------------------" << endl;
		return out;
	}

	//1.4.2 Operator >>
	friend istream& operator>>(istream& in, Comanda& c)
	{
		cout << "Introduceti datele cerute pentru a crea o noua comanda: " << endl;
		cout << "Id Comanda: " << endl;
		in >> ws;
		getline(in, c.idComanda);
		cout << "Nume Client: " << endl;
		in >> ws;
		delete[] c.numeClient;
		char aux[100];
		in.getline(aux, 99);
		c.numeClient = new char[strlen(aux) + 1];
		strcpy(c.numeClient, aux);
		cout << " Pret Comanda: " << endl;
		in >> c.pretComanda;
		cout << "Exista in comanda si un animal?" << endl;
		in >> c.contineAnimal;
		cout << "Numar Produse din Comanda: " << endl;
		in >> c.nrProduse;
		cout << " Produsele din comanda: " << endl;
		c.produseComanda = new string[c.nrProduse];
		for (int i = 0; i < c.nrProduse; i++)
		{
			in >> ws;
			getline(in, c.produseComanda[i]);
		}
		cout << "Numar Reduceri per Comanda: " << endl;
		in >> c.nrReduceri;
		cout << " Reducerile din comanda: " << endl;
		for (int i = 0; i < c.nrReduceri; i++)
			in >> c.valReduceri[i];

		return in;
	}

	//1.5.1 Operator []
	string operator[](int pozitie) {
		cout << endl << "----- Apel operator[] -----" << endl;
		if (pozitie >= 0 && pozitie < this->nrProduse)
			return this->produseComanda[pozitie];
		else
			return "Eroare";
	}

	//1.5.2 Operator +
	Comanda operator+(float val) {
		cout << endl << "----- Apel operator + -----" << endl;
		Comanda copie = *this;
		copie.pretComanda += val;
		return copie;
	}

	//1.5.3Operat0r ++
	Comanda& operator++()
	{
		cout << endl << "----- Apel operator ++ preincrementare -----" << endl;
		this->pretComanda++;
		return *this;
	}
	Comanda operator++(int)
	{
		cout << endl << "----- Apel operator ++ postincrementare -----" << endl;
		Comanda copie = *this;
		this->pretComanda++;
		return copie;

	}

	//1.5.4 Operator cast
	explicit operator int()
	{
		cout << endl << "----- Apel operator cast -----" << endl;
		return this->pretComanda;
	}

	//1.5.5 Operator <=
	bool operator<=(Comanda c)
	{
		cout << endl << "----- Apel operator<= -----" << endl;
		return this->pretComanda < c.pretComanda;
	}

	friend bool operator<(const Comanda& c1, const Comanda& c2)
	{
		if (c1.nrReduceri < c2.nrReduceri)
			return true;
		else
			return false;
	}

	//1.5.6 Operator !
	bool operator!()
	{
		cout << endl << "----- Apel operator ! -----" << endl;
		if (this->contineAnimal == 1)
		{
			this->contineAnimal = 0;
			return true;
		}
		else
		{
			this->contineAnimal = 1;
			return false;
		}
	}

	//1.5.7 Operator ==
	bool operator==(const Comanda& c)
	{
		cout << endl << "----- Apel operator == -----" << endl;
		if (this->idComanda == c.idComanda && strcmp(this->numeClient, c.numeClient) == 0 && this->pretComanda == c.pretComanda && this->nrProduse == c.nrProduse && this->produseComanda == c.produseComanda && this->nrReduceri == c.nrReduceri && this->valReduceri == c.valReduceri && this->contineAnimal == c.contineAnimal) {
			return true;
		}

		else
		{
			return false;
		}
	}

	//2.1.1 Scrierea in fisiere text
	void writeToTextFile(ofstream& out)
	{

		out << this->idComanda << endl;
		out << this->numeClient << endl;
		out << this->pretComanda << endl;
		out << this->contineAnimal << endl;
		out << this->nrProduse << endl;

		for (int i = 0; i < this->nrProduse; i++)
		{
			out << this->produseComanda[i] << endl;
		}

		out << this->nrReduceri << endl;

		for (int i = 0; i < this->nrReduceri; i++)
		{
			out << this->valReduceri[i] << endl;
		}
	}

	//2.1.2 Citirea din fisiere text
	void readFromTextFile(ifstream& in)
	{

		in >> ws;
		getline(in, this->idComanda);
		in >> ws;
		delete[] this->numeClient;
		char aux[100];
		in.getline(aux, 99);
		this->numeClient = new char[strlen(aux) + 1];
		strcpy(this->numeClient, aux);
		in >> this->pretComanda;
		in >> this->contineAnimal;
		in >> this->nrProduse;
		this->produseComanda = new string[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			in >> ws;
			getline(in, this->produseComanda[i]);
		}
		in >> this->nrReduceri;
		for (int i = 0; i < this->nrReduceri; i++)
			in >> this->valReduceri[i];

	}

	//2.2.1 Scrierea in fisiere binare
	void writeToFile(fstream& f)
	{
		int lgID = this->idComanda.length() + 1;
		f.write((char*)&lgID, sizeof(int));
		f.write(this->idComanda.data(), lgID * sizeof(char));

		int lgNume = strlen(this->numeClient) + 1;
		f.write((char*)&lgNume, sizeof(int));
		f.write(this->numeClient, lgNume);


		f.write((char*)&this->pretComanda, sizeof(this->pretComanda));
		f.write((char*)&this->contineAnimal, sizeof(this->contineAnimal));

		f.write((char*)&this->nrProduse, sizeof(this->nrProduse));
		for (int i = 0; i < this->nrProduse; i++)
		{
			int lgProd = this->produseComanda[i].length() + 1;
			f.write((char*)&lgProd, sizeof(int));
			f.write(this->produseComanda[i].data(), lgProd);
		}
		f.write((char*)&this->nrReduceri, sizeof(this->nrReduceri));
		for (int i = 0; i < this->nrReduceri; i++)
		{
			f.write((char*)&this->valReduceri[i], sizeof(this->valReduceri[i]));
		}
	}

	//2.2.2 Citirea din fisiere binare
	void readFromFile(fstream& f)
	{
		int lgID = 0;
		f.read((char*)&lgID, sizeof(int));
		char* bufferID = new char[lgID];
		f.read(bufferID, lgID);
		this->idComanda = bufferID;
		delete[] bufferID;

		int lgNume;
		f.read((char*)&lgNume, sizeof(int));
		char* bufferNume = new char[lgNume];
		f.read(bufferNume, lgNume);
		delete[] this->numeClient;
		this->numeClient = new char[strlen(bufferNume) + 1];
		strcpy(this->numeClient, bufferNume);

		f.read((char*)&this->pretComanda, sizeof(this->pretComanda));
		f.read((char*)&this->contineAnimal, sizeof(this->contineAnimal));
		f.read((char*)&this->nrProduse, sizeof(this->nrProduse));
		delete[] this->produseComanda;
		this->produseComanda = new string[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			int lgProduse;
			f.read((char*)&lgProduse, sizeof(int));
			char* bufferProduse = new char[lgProduse]; 
			f.read(bufferProduse, lgProduse);
			this->produseComanda[i] = bufferProduse;
			delete[] bufferProduse;
		}
		f.read((char*)&this->nrReduceri, sizeof(this->nrReduceri));
		for (int i = 0; i < this->nrReduceri; i++)
		{
			f.read((char*)&this->valReduceri[i], sizeof(this->valReduceri[i]));
		}
	}

	//2.3.1 Scrierea in fisiere CSV
	void writeToCSVFile(ofstream& out) {

		out << this->idComanda << ",";
		out << this->numeClient << ",";
		out << this->pretComanda << ",";
		out << this->contineAnimal << ",";
		out << this->nrProduse << ",";

		for (int i = 0; i < this->nrProduse; i++)
		{
			out << this->produseComanda[i] << ",";
		}

		out << this->nrReduceri << ",";

		for (int i = 0; i < this->nrReduceri; i++)
		{
			out << this->valReduceri[i] << ",";
		}
	}

	float calculPretComandaFaraTVA() {
		return (this->pretComanda - 0.19 * this->pretComanda);
	}

	float calculPretComandaEuro(float cursValutar) {
		return this->pretComanda /cursValutar;
	}


};

class Furnizor : public Ifile
{
private:
	char* numeFurnizor = 0;
	const string codFurnizor;
	float totalComanda = 0;
	int nrProduse = 0;
	float* cantitatiProduse = NULL;
	string* numeProduse = NULL;
	int nrModalitatiDePlata = 0;
	string modalitati[30];
	bool platit = 0;

public:
	//1.1.1 Get
	char* getNumeFurnizor()
	{
		char* copie = new char[strlen(this->numeFurnizor) + 1];
		strcpy(copie, this->numeFurnizor);
		return copie;
	}
	string getCodFurnizor() {
		return this->codFurnizor;
	}
	float getTotalComanada()
	{
		return this->totalComanda;
	}
	int getNrProduse() {
		return this->nrProduse;
	}
	float* getCantitate()
	{
		return this->cantitatiProduse;
	}
	string* getNumeProduse() {
		return this->numeProduse;
	}
	int getNrModalitati() {
		return this->nrModalitatiDePlata;
	}
	string* getModalitati()
	{
		return this->modalitati;
	}
	bool getPlatit() {
		return this->platit;
	}

	//1.1.2 Set
	void setNumeFurnizor(const char* numeFurnizor) {
		if (strlen(numeFurnizor) > 2)
		{
			this->numeFurnizor = new char[strlen(numeFurnizor) + 1];
			strcpy(this->numeFurnizor, numeFurnizor);
		}
	}
	void setPlatit(bool platit)
	{
		if (platit == 1 || platit == 0)
		{
			this->platit = platit;
		}
	}
	void setTotalComanda(float TotalComanda)
	{
		if (totalComanda > 0)
		{
			this->totalComanda = totalComanda;
		}
	}
	void setProduse(int nrProduse, string* numeProduse, float* cantitatiProduse)
	{
		if (this->cantitatiProduse != NULL)
		{
			delete[] this->cantitatiProduse;
		}
		if (this->numeProduse != NULL)
		{
			delete[] this->numeProduse;
		}
		if (nrProduse > 0 && numeProduse != NULL && cantitatiProduse != NULL)
		{
			this->nrProduse = nrProduse;
			this->numeProduse = new string[nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->numeProduse[i] = numeProduse[i];
			}
			this->cantitatiProduse = new float[nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->cantitatiProduse[i] = cantitatiProduse[i];
			}
		}
	}
	void setPlata(int nrModalitatiDePlata, string* modalitati)
	{
		if (nrModalitatiDePlata > 0) {
			this->nrModalitatiDePlata = nrModalitatiDePlata;
			for (int i = 0; i < this->nrModalitatiDePlata; i++)
			{
				this->modalitati[i] = modalitati[i];
			}
		}
	}
	//1.2 Metode
	float sumaCantitate()
	{
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++)
		{
			suma = suma + this->cantitatiProduse[i];
		}
		return suma;
	}
	float mediaCantitate() {
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++)
		{
			suma = suma + this->cantitatiProduse[i];
		}
		return suma / this->nrProduse;
	}


	//1.3.1 Constructor fara parametrii
	Furnizor() : codFurnizor("AAAAAAA")
	{
		this->numeFurnizor = new char[strlen("Anonim") + 1];
		strcpy(this->numeFurnizor, "Anonim");
	}

	//1.3.2Constructor cu un parametru
	Furnizor(string codFurnizor) :codFurnizor(codFurnizor)
	{
		this->numeFurnizor = new char[strlen("Anonim") + 1];
		strcpy(this->numeFurnizor, "Anonim");
	}

	//1.3.3 Constructor cu toti parametrii
	Furnizor(string codFurnizor, const char* numeFurnizor, float totalComanda, int nrProduse, float* cantitatiProduse, string* numeProduse, int nrModalitatiDePlata, string* modalitati, bool platit) :codFurnizor(codFurnizor)
	{
		this->numeFurnizor = new char[strlen(numeFurnizor) + 1];
		strcpy(this->numeFurnizor, numeFurnizor);
		this->platit = platit;
		this->totalComanda = totalComanda;

		if (nrProduse > 0 && numeProduse != NULL && cantitatiProduse != NULL)
		{
			this->nrProduse = nrProduse;
			this->numeProduse = new string[nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->numeProduse[i] = numeProduse[i];
			}
			this->cantitatiProduse = new float[nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->cantitatiProduse[i] = cantitatiProduse[i];
			}
		}
		if (nrModalitatiDePlata > 0) {
			this->nrModalitatiDePlata = nrModalitatiDePlata;
			for (int i = 0; i < this->nrModalitatiDePlata; i++)
			{
				this->modalitati[i] = modalitati[i];
			}
		}
	}

	//1.3.4 Constructor copy
	Furnizor(const Furnizor& f) : codFurnizor(f.codFurnizor)
	{
		this->numeFurnizor = new char[strlen(f.numeFurnizor) + 1];
		strcpy(this->numeFurnizor, f.numeFurnizor);
		this->platit = f.platit;
		this->totalComanda = f.totalComanda;

		if (f.nrProduse > 0 && f.numeProduse != NULL && f.cantitatiProduse != NULL)
		{
			this->nrProduse = f.nrProduse;
			this->numeProduse = new string[f.nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->numeProduse[i] = f.numeProduse[i];
			}
			this->cantitatiProduse = new float[f.nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->cantitatiProduse[i] = f.cantitatiProduse[i];
			}
		}
		if (f.nrModalitatiDePlata > 0) {
			this->nrModalitatiDePlata = f.nrModalitatiDePlata;
			for (int i = 0; i < this->nrModalitatiDePlata; i++)
			{
				this->modalitati[i] = f.modalitati[i];
			}
		}
	}

	//1.3.5 Destructor
	~Furnizor()
	{
		delete[] this->numeFurnizor;
		if (this->cantitatiProduse != NULL)
		{
			delete[] this->cantitatiProduse;
		}
		if (this->numeProduse != NULL)
		{
			delete[] this->numeProduse;
		}

	}

	//1.3.6 Operator =
	Furnizor& operator=(const Furnizor& f)
	{
		if (this != &f) {
			delete[] this->numeFurnizor;
			if (this->cantitatiProduse != NULL)
			{
				delete[] this->cantitatiProduse;
			}
			if (this->numeProduse != NULL)
			{
				delete[] this->numeProduse;
			}


			this->numeFurnizor = new char[strlen(f.numeFurnizor) + 1];
			strcpy(this->numeFurnizor, f.numeFurnizor);
			this->platit = f.platit;
			this->totalComanda = f.totalComanda;
			if (f.nrProduse > 0 && f.numeProduse != NULL && f.cantitatiProduse != NULL)
			{
				this->nrProduse = f.nrProduse;
				this->numeProduse = new string[f.nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					this->numeProduse[i] = f.numeProduse[i];
				}
				this->cantitatiProduse = new float[f.nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					this->cantitatiProduse[i] = f.cantitatiProduse[i];
				}
			}
			if (f.nrModalitatiDePlata > 0) {
				this->nrModalitatiDePlata = f.nrModalitatiDePlata;
				for (int i = 0; i < this->nrModalitatiDePlata; i++)
				{
					this->modalitati[i] = f.modalitati[i];
				}
			}
		}
		return *this;
	}

	//1.4.1 Operator <<
	friend ostream& operator<<(ostream& out, const Furnizor& f)
	{
		out << endl << "---------------------------------------------------------------" << endl;
		out << "Nume furnizor: " << f.numeFurnizor << endl;
		out << "Cod furnizor: " << f.codFurnizor << endl;
		out << "Total comanda: " << f.totalComanda << endl;
		out << "A fost acest furnizor platit? ";
		if (f.platit == 1)
		{
			out << "DA!" << endl;
		}
		else
		{
			out << "NU!" << endl;
		}
		out << "Nr Produse: " << f.nrProduse << endl;
		out << "Nume produse: " << endl;
		for (int i = 0; i < f.nrProduse; i++)
		{
			out << f.numeProduse[i] << endl;
		}
		out << "Cantitati produse: " << endl;
		for (int i = 0; i < f.nrProduse; i++)
		{
			out << f.cantitatiProduse[i] << "  ";
		}
		out << endl;
		out << "Nr Modalitati de plata: " << f.nrModalitatiDePlata << endl;
		out << "Nume Modalitati de plata: " << endl;
		for (int i = 0; i < f.nrModalitatiDePlata; i++)
		{
			out << f.modalitati[i] << "  ";
		}
		out << endl << "---------------------------------------------------------------" << endl;
		return out;
	}

	//1.4.2 Operator >>
	friend istream& operator>>(istream& in, Furnizor& f)
	{
		cout << " Introduceti datele cerute pentru a adauga un nou furnizor: " << endl;
		cout << "Nume furnizor: " << endl;
		in >> ws;
		delete[] f.numeFurnizor;
		char aux[100];
		in.getline(aux, 99);
		f.numeFurnizor = new char[strlen(aux) + 1];
		strcpy(f.numeFurnizor, aux);
		cout << "A fost acest furnizor platit?(introduceti 0 - nu sau 1 - da)";
		in >> f.platit;
		cout << "Total comanda:" << endl;
		in >> f.totalComanda;
		cout << "Nr Produse: " << endl;
		in >> f.nrProduse;
		cout << "Nume produse: " << endl;
		delete[] f.numeProduse;
		f.numeProduse = new string[f.nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			in >> ws;
			getline(in, f.numeProduse[i]);
		}
		delete[] f.cantitatiProduse;
		cout << "Cantitati produse: " << endl;
		f.cantitatiProduse = new float[f.nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			in >> f.cantitatiProduse[i];
		}

		cout << "Nr Modalitati de plata: " << endl;
		in >> f.nrModalitatiDePlata;
		cout << "Nume Modalitati de plata: " << endl;
		for (int i = 0; i < f.nrModalitatiDePlata; i++)
		{
			in >> ws;
			getline(in, f.modalitati[i]);
		}
		return in;
	}

	//1.5.1 Operator []
	string operator[](int pozitie)
	{
		if (pozitie < this->nrModalitatiDePlata && pozitie >= 0)
			return this->modalitati[pozitie];
		else
			return "Eroare";
	}
	//1.5.2 Operator +
	Furnizor operator+(float val) {
		cout << endl << "----- Apel operator + -----" << endl;
		Furnizor copie = *this;
		copie.totalComanda += val;
		return copie;
	}

	//1.5.3 Operator ++
	Furnizor& operator++()
	{
		cout << endl << "----- Apel operator ++ preincrementare -----" << endl;
		this->totalComanda++;
		return *this;
	}
	Furnizor operator++(int)
	{
		cout << endl << "----- Apel operator ++ postincrementare -----" << endl;
		Furnizor copie = *this;
		this->totalComanda++;
		return copie;
	}

	//1.5.4 Operator cast
	explicit operator int()
	{
		cout << endl << "----- Apel operator cast -----" << endl;
		return this->totalComanda;
	}

	//1.5.4 Operator !
	bool operator!()
	{
		cout << endl << "----- Apel operator ! -----" << endl;
		if (this->platit == 1)
		{
			this->platit = 0;
			return true;
		}
		else
		{
			this->platit = 1;
			return false;
		}
	}

	//1.5.5 Operator >
	bool operator>(Furnizor f)
	{
		cout << endl << "----- Apel operator > -----" << endl;
		return this->nrProduse > f.nrProduse;
	}

	//1.5.6
	bool operator==(const Furnizor& f) {
		cout << endl << "----- Apel operator == -----" << endl;
		if (this->codFurnizor == f.codFurnizor && strcmp(this->numeFurnizor, f.numeFurnizor) == 0 && this->totalComanda == f.totalComanda && this->nrProduse == f.nrProduse && this->numeProduse == f.numeProduse && this->cantitatiProduse == f.cantitatiProduse && this->nrModalitatiDePlata == f.nrModalitatiDePlata && this->modalitati == f.modalitati && this->platit == f.platit)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//2.1.1 Scrierea in fisier text
	void writeToTextFile(ofstream& out)
	{
		out << this->numeFurnizor << endl;
		out << this->totalComanda << endl;
		out << this->platit << endl;
		out << this->nrProduse << endl;
		out << endl;
		for (int i = 0; i < this->nrProduse; i++)
		{
			out << this->numeProduse[i] << endl;
		}
		for (int i = 0; i < this->nrProduse; i++)
		{
			out << this->cantitatiProduse[i] << endl;
		}
		out << this->nrModalitatiDePlata << endl;
		for (int i = 0; i < this->nrModalitatiDePlata; i++)
		{
			out << this->modalitati[i] << endl;
		}
	}

	//2.1.2.Citirea din fisier text
	void readFromTextFile(ifstream& in)
	{
		in >> ws;
		delete[] this->numeFurnizor;
		char aux[100];
		in.getline(aux, 99);
		this->numeFurnizor = new char[strlen(aux) + 1];
		strcpy(this->numeFurnizor, aux);
		in >> this->totalComanda;
		in >> this->platit;
		in >> this->nrProduse;
		delete[] this->numeProduse;
		this->numeProduse = new string[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			in >> ws;
			getline(in, this->numeProduse[i]);
		}
		delete[] this->cantitatiProduse;
		this->cantitatiProduse = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			in >> this->cantitatiProduse[i];
		}
		in >> this->nrModalitatiDePlata;
		for (int i = 0; i < this->nrModalitatiDePlata; i++)
		{
			in >> ws;
			getline(in, this->modalitati[i]);
		}
	}

	//2.2.1 Scrierea in fisier binar
	void writeToFile(fstream& f)
	{
		int lgNume = strlen(this->numeFurnizor) + 1;
		f.write((char*)&lgNume, sizeof(int));
		f.write(this->numeFurnizor, lgNume);


		f.write((char*)&this->totalComanda, sizeof(this->totalComanda));
		f.write((char*)&this->platit, sizeof(this->platit));

		f.write((char*)&this->nrProduse, sizeof(this->nrProduse));
		for (int i = 0; i < this->nrProduse; i++)
		{
			int lgProduse = this->numeProduse[i].length() + 1;
			f.write((char*)&lgProduse, sizeof(int));
			f.write(this->numeProduse[i].data(), lgProduse);
		}
		for (int i = 0; i < this->nrProduse; i++)
		{
			f.write((char*)&this->cantitatiProduse[i], sizeof(this->cantitatiProduse[i]));
		}

		f.write((char*)&this->nrModalitatiDePlata, sizeof(this->nrModalitatiDePlata));
		for (int i = 0; i < this->nrModalitatiDePlata; i++)
		{
			int lgPlata = this->modalitati[i].length() + 1;
			f.write((char*)&lgPlata, sizeof(int));
			f.write(this->modalitati[i].data(), lgPlata);

		}
	}

	//2.2.2 Citirea din fisier binar
	void readFromFile(fstream& f)
	{
		int lgNume;
		f.read((char*)&lgNume, sizeof(int));
		char* bufferNume = new char[lgNume];
		f.read(bufferNume, lgNume);
		delete[] this->numeFurnizor;
		this->numeFurnizor = new char[strlen(bufferNume) + 1];
		strcpy(this->numeFurnizor, bufferNume);

		f.read((char*)&this->totalComanda, sizeof(this->totalComanda));
		f.read((char*)&this->platit, sizeof(this->platit));
		f.read((char*)&this->nrProduse, sizeof(this->nrProduse));
		delete[] this->numeProduse;
		this->numeProduse = new string[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			int lgProduse;
			f.read((char*)&lgProduse, sizeof(int));
			char* bufferProduse = new char[lgProduse];
			f.read(bufferProduse, lgProduse);
			this->numeProduse[i] = bufferProduse;
			delete[] bufferProduse;
		}
		delete[] this->cantitatiProduse;
		this->cantitatiProduse = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			f.read((char*)&this->cantitatiProduse[i], sizeof(this->cantitatiProduse[i]));
		}

		f.read((char*)&this->nrModalitatiDePlata, sizeof(this->nrModalitatiDePlata));
		for (int i = 0; i < this->nrModalitatiDePlata; i++)
		{
			int lgPlata;
			f.read((char*)&lgPlata, sizeof(int));
			char* bufferPlata = new char[lgPlata];
			f.read(bufferPlata, lgPlata);
			this->modalitati[i] = bufferPlata;
			delete[] bufferPlata;
		}
	}
	//2.3.1 Scrierea in fisier CSV
	void writeToCSVFile(ofstream& out) {
		out << this->numeFurnizor << ",";
		out << this->totalComanda << ",";
		out << this->platit << ",";
		out << this->nrProduse << ",";
		for (int i = 0; i < this->nrProduse; i++)
		{
			out << this->numeProduse[i] << ",";
		}
		for (int i = 0; i < this->nrProduse; i++)
		{
			out << this->cantitatiProduse[i] << ",";
		}
		out << this->nrModalitatiDePlata << ",";
		for (int i = 0; i < this->nrModalitatiDePlata; i++)
		{
			out << this->modalitati[i] << ",";
		}
	}
};

template< class Tip>
class ColectieAngajati {
	int nrObiecte = 0;
	Tip* listaObiecte = NULL;
public:
	ColectieAngajati()
	{};

	ColectieAngajati(int nrObiecte, Tip* listaObiecte)
	{
		this->nrObiecte = nrObiecte;
		this->listaObiecte = new Tip[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			this->listaObiecte[i] = listaObiecte[i];
		}
	}

	ColectieAngajati(const ColectieAngajati& cA)
	{
		this->nrObiecte = cA.nrObiecte;
		this->listaObiecte = new Tip[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			this->listaObiecte[i] = cA.listaObiecte[i];
		}
	}

	ColectieAngajati& operator=(const ColectieAngajati& cA) {
		if (this != &cA)
		{
			this->nrObiecte = cA.nrObiecte;
			this->listaObiecte = new Tip[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->listaObiecte[i] = cA.listaObiecte[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const ColectieAngajati& cA)
	{
		out << "Nr obiecte" << cA.nrObiecte << endl;
		for (int i = 0; i < cA.nrObiecte; i++)
			out << cA.listaObiecte[i] << " ";
		return out;
	}

	~ColectieAngajati()
	{
		delete[] this->listaObiecte;
	}
};

template <class Tip>
class ColectieProduse
{
	int nrObiecte = 0;
	Tip* listaObiecte = NULL;
public:
	ColectieProduse()
	{};

	ColectieProduse(int nrObiecte, Tip* listaObiecte)
	{
		this->nrObiecte = nrObiecte;
		this->listaObiecte = new Tip[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			this->listaObiecte[i] = listaObiecte[i];
		}
	}

	ColectieProduse(const ColectieProduse& cP)
	{
		this->nrObiecte = cP.nrObiecte;
		this->listaObiecte = new Tip[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			this->listaObiecte[i] = cP.listaObiecte[i];
		}
	}

	ColectieProduse& operator=(const ColectieProduse& cP) {
		if (this != &cP)
		{
			this->nrObiecte = cP.nrObiecte;
			this->listaObiecte = new Tip[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->listaObiecte[i] = cP.listaObiecte[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const ColectieProduse& cP)
	{
		out << "Nr obiecte" << cP.nrObiecte << endl;
		for (int i = 0; i < cP.nrObiecte; i++)
			out << cP.listaObiecte[i] << " ";
		return out;
	}

	~ColectieProduse()
	{
		delete[] this->listaObiecte;
	}
};

class FisiereBinare : public Angajat, public Animal, public Produs, public Comanda, public Furnizor
{
public:
	void meniuBinar()
	{
		{
			system("cls");
			cout << endl << endl;
			cout << "----------------------------------------------------------------------------";
			cout << endl << endl << "----------------- MENIU FISIERE BINARE----------------------" << endl << endl;
			cout << "----------------------------------------------------------------------------";
			cout << endl << endl;
			cout << "Meniu Fisiere Binare:" << endl;
			cout << "1 - Salvarea datelor unui obiect de tip Angajat:" << endl;
			cout << "2 - Salvarea datelor unui obiect de tip Animal:" << endl;
			cout << "3 - Salvarea datelor unui obiect de tip Produs:" << endl;
			cout << "4 - Salvarea datelor unui obiect de tip Comanda:" << endl;
			cout << "5 - Salvarea datelor unui obiect de tip Furnizor:" << endl;
			cout << "6 - Parasiti aplicatia!" << endl;
			cout << "Intoduceti de la tastatura optiunea dorita:" << endl;

			int opt;
			cin >> opt;

			switch (opt)
			{
			case 1:
			{system("cls");
			cout << " Alegeti modalitatea prin care au fost incarcate datele:" << endl;
			cout << "1 - Tastatura" << endl;
			cout << "2 - Fisier Text" << endl;
			int optIncarcare;
			cin >> optIncarcare;
			switch (optIncarcare)
			{
			case 1:
			{
				cout << "Introduceti un Angajat nou!";
				Angajat aMeniu;
				cin >> aMeniu;
				fstream AOut("AngajatB.txt", ios::out | ios::binary);
				aMeniu.writeToFile(AOut);
				AOut.close();
				cout << "S-a realizat scrierea in fisier binar!" << endl;
				fstream CIn("ComandaB.txt", ios::in | ios::binary);
				Comanda comandaBinar;
				if (CIn.is_open())
				{
					comandaBinar.readFromFile(CIn);
					CIn.close();
					cout << "S-a realizat citirea in fisierul binar" << endl;

				}
				else
				{
					cout << "Fisierul nu a putut fi localizat!" << endl;
				}
				cout << comandaBinar;


				break;
			}

			case 2:
			{Angajat angajatText;
			cout << angajatText;
			ofstream Afile("Angajat.txt", ios::out);
			angajatText.writeToTextFile(Afile);
			Afile.close();
			cout << "Scrierea in fisierul text a fost realizata!" << endl;
			ifstream afile("Angajat.txt", ios::in);
			if (afile.is_open())
			{
				angajatText.readFromTextFile(afile);
				afile.close();
				cout << endl << "S-a realizat citirea din fisier text!" << endl;
			}
			else
			{
				cout << "Fisierul text nu a fost localizat. Incercati un alt fisier!";
			}
			cout << angajatText;
			cout << endl << endl;
			cout << "----- Fisiere binare -----" << endl;
			fstream AOut("AngajatB.txt", ios::out | ios::binary);
			angajatText.writeToFile(AOut);
			AOut.close();
			cout << "S-a realizat scrierea in fisier binar!" << endl;
			fstream AIn("AngajatB.txt", ios::in | ios::binary);
			Angajat angajataBinar;
			if (AIn.is_open())
			{
				angajataBinar.readFromFile(AIn);
				AIn.close();
				cout << "S-a realizat citirea din fisier binar!" << endl;
			}
			else
			{
				cout << "Fisierul binar nu a fost localizat. Incercati un alt fisier!";
			}
			cout << angajataBinar;
			cout << endl << endl;

			break;
			}

			default:
				cout << "Comanda invalida!" << endl;
				break;
			}
			break;
			}

			case 2:
			{system("cls");
			cout << " Alegeti modalitatea prin care au fost incarcate datele:" << endl;
			cout << "1 - Tastatura" << endl;
			cout << "2 - Fisier Text" << endl;
			int optIncarcare2;
			cin >> optIncarcare2;
			switch (optIncarcare2)
			{
			case 1:
			{
				cout << "Introduceti un Animal nou!";
				Animal anMeniu;
				cin >> anMeniu;
				fstream AnOut("AnimalB.txt", ios::out | ios::binary);
				anMeniu.writeToFile(AnOut);
				AnOut.close();
				cout << "S-a realizat scrierea in fisierul binar" << endl;
				fstream AnIn("AnimalB.txt", ios::in | ios::binary);
				Animal animalBinar;
				if (AnIn.is_open())
				{
					animalBinar.readFromFile(AnIn);
					AnIn.close();
					cout << "S-a realizat citirea in fisierul binar" << endl;
				}
				else
				{
					cout << "Fisierul nu a putut fi localizat!" << endl;
				}
				cout << animalBinar;
				break;
			}

			case 2:
			{	Animal animalText;
			cout << animalText << endl;
			ofstream Anfile("Animal.txt", ios::out);
			animalText.writeToTextFile(Anfile);
			Anfile.close();
			cout << "S-a realizat scrierea in fisier text!" << endl;
			ifstream anfile("Animal.txt", ios::in);
			if (anfile.is_open()) {
				animalText.readFromTextFile(anfile);
				anfile.close();
				cout << "S-a realizat citirea in fisier text!" << endl;
			}
			else {
				cout << "Fisierul cautat nu a fost localizat!" << endl;
			}
			cout << animalText << endl;
			cout << endl << endl;
			cout << "----- Fisiere binare -----" << endl;
			fstream AnOut("AnimalB.txt", ios::out | ios::binary);
			animalText.writeToFile(AnOut);
			AnOut.close();
			cout << "S-a realizat scrierea in fisierul binar" << endl;
			fstream AnIn("AnimalB.txt", ios::in | ios::binary);
			Animal animalBinar;
			if (AnIn.is_open())
			{
				animalBinar.readFromFile(AnIn);
				AnIn.close();
				cout << "S-a realizat citirea in fisierul binar" << endl;
			}
			else
			{
				cout << "Fisierul nu a putut fi localizat!" << endl;
			}
			cout << animalBinar;

			break;
			}

			default:

				cout << "Comanda invalida!" << endl;
				break;
			}
			break;
			}

			case 3:
			{system("cls");
			cout << " Alegeti modalitatea prin care au fost incarcate datele:" << endl;
			cout << "1 - Tastatura" << endl;
			cout << "2 - Fisier Text" << endl;
			int optIncarcare3;
			cin >> optIncarcare3;
			switch (optIncarcare3)
			{
			case 1:
			{
				cout << "Introduceti un Produs nou!";
				Produs pMeniu;
				cin >> pMeniu;
				fstream POut("ProdusB.txt", ios::out | ios::binary);
				pMeniu.writeToFile(POut);
				POut.close();
				cout << "S-a realizat scrierea in fisierul binar!" << endl;
				fstream PIn("ProdusB.txt", ios::in | ios::binary);
				Produs produsBinar;
				if (PIn.is_open())
				{
					produsBinar.readFromFile(PIn);
					PIn.close();
					cout << "S-a realizat citirea in fisierul binar" << endl;

				}
				else
				{
					cout << "Fisierul nu a putut fi localizat!" << endl;
				}
				cout << produsBinar;
				break;
			}
			case 2:
			{ofstream Pfile("Produs.txt", ios::out);
			Produs produsText;
			cout << produsText << endl;
			produsText.writeToTextFile(Pfile);
			Pfile.close();
			cout << "S-a realizat scrierea in fisier text!" << endl;

			ifstream pfile("Produs.txt", ios::in);
			if (pfile.is_open()) {
				produsText.readFromTextFile(pfile);
				pfile.close();
				cout << "S-a realizat citirea in fisier text!" << endl;
			}
			else {
				cout << "Fisierul cautat nu a fost localizat!" << endl;
			}
			cout << produsText << endl;
			cout << endl << endl;
			cout << "----- Fisiere binare -----" << endl;
			fstream POut("ProdusB.txt", ios::out | ios::binary);
			produsText.writeToFile(POut);
			POut.close();
			cout << "S-a realizat scrierea in fisierul binar!" << endl;
			fstream PIn("ProdusB.txt", ios::in | ios::binary);
			Produs produsBinar;
			if (PIn.is_open())
			{
				produsBinar.readFromFile(PIn);
				PIn.close();
				cout << "S-a realizat citirea in fisierul binar" << endl;

			}
			else
			{
				cout << "Fisierul nu a putut fi localizat!" << endl;
			}
			cout << produsBinar;
			cout << endl << endl;
			break;
			}
			default:
				cout << "Comanda invalida!" << endl;
				break;

				break;
			}
			}


			case 4:
			{system("cls");
			cout << " Alegeti modalitatea prin care au fost incarcate datele:" << endl;
			cout << "1 - Tastatura" << endl;
			cout << "2 - Fisier Text" << endl;
			int optIncarcare4;
			cin >> optIncarcare4;
			switch (optIncarcare4)
			{
			case 1:
			{
				cout << "Introduceti o Comanda noua!";
				Comanda cMeniu;
				cin >> cMeniu;
				fstream COut("ComandaB.txt", ios::out | ios::binary);
				cMeniu.writeToFile(COut);
				COut.close();
				cout << "S-a realizat scrierea in fisierul binar" << endl;
				fstream CIn("ComandaB.txt", ios::in | ios::binary);
				Comanda comandaBinar;
				if (CIn.is_open())
				{
					comandaBinar.readFromFile(CIn);
					CIn.close();
					cout << "S-a realizat citirea in fisierul binar" << endl;

				}
				cout << comandaBinar;
				break;
			}
			case 2:
			{Comanda comandaText;
			cout << comandaText;
			ofstream Cfile("Comanda.txt", ios::out);
			comandaText.writeToTextFile(Cfile);
			Cfile.close();
			cout << "S-a realizat scrierea in fisierul text" << endl;

			ifstream cfile("Comanda.txt", ios::in);
			if (cfile.is_open())
			{
				comandaText.readFromTextFile(cfile);
				cfile.close();
				cout << "S-a realizat citirea in fisierul text" << endl;
			}
			else
			{
				cout << "Fisierul nu a putut fi localizat!" << endl;
			}
			cout << comandaText << endl;
			cout << endl << endl;
			cout << "----- Fisiere binare -----" << endl;
			fstream COut("ComandaB.txt", ios::out | ios::binary);
			comandaText.writeToFile(COut);
			COut.close();
			cout << "S-a realizat scrierea in fisierul binar" << endl;
			fstream CIn("ComandaB.txt", ios::in | ios::binary);
			Comanda comandaBinar;
			if (CIn.is_open())
			{
				comandaBinar.readFromFile(CIn);
				CIn.close();
				cout << "S-a realizat citirea in fisierul binar" << endl;

			}
			else
			{
				cout << "Fisierul nu a putut fi localizat!" << endl;
			}
			cout << comandaBinar;
			cout << endl << endl;
			break;

			}

			default:
				cout << "Comanda invalida!" << endl;
				break;
			}
			break;
			}

			case 5:
			{system("cls");
			cout << " Alegeti modalitatea prin care au fost incarcate datele:" << endl;
			cout << "1 - Tastatura" << endl;
			cout << "2 - Fisier Text" << endl;
			int optIncarcare5;
			cin >> optIncarcare5;
			switch (optIncarcare5)
			{
			case 1:
			{
				cout << "Introduceti un furnizor nou!";
				Furnizor fMeniu;
				cin >> fMeniu;
				fstream FOut("FurnizorB.txt", ios::out | ios::binary);
				fMeniu.writeToFile(FOut);
				FOut.close();
				cout << "S-a realizat scrierea in fisierul binar!" << endl;
				fstream FIn("FurnizorB.txt", ios::in | ios::binary);
				Furnizor furnizorBinar;
				if (FIn.is_open())
				{
					furnizorBinar.readFromFile(FIn);
					FIn.close();
					cout << "S-a realizat citirea in fisierul binar" << endl;

				}
				else
				{
					cout << "Fisierul nu a putut fi localizat!" << endl;
				}
				cout << furnizorBinar;
				break;
			}

			case 2:
			{
				Furnizor furnizorText;
				cout << furnizorText;
				ofstream Ffile("Furnizor.txt", ios::out);
				furnizorText.writeToTextFile(Ffile);
				Ffile.close();
				cout << "S-a realizat scrierea in fisierul text!" << endl;
				ifstream ffile("Furnizor.txt", ios::in);
				if (ffile.is_open())
				{
					furnizorText.readFromTextFile(ffile);
					ffile.close();
					cout << "S-a realizat citirea in fisierul text!" << endl;
				}
				else
				{
					cout << "Fisierul nu a putut fi localizat!" << endl;
				}
				cout << furnizorText << endl;
				cout << "----- Fisiere binare -----" << endl;
				fstream FOut("FurnizorB.txt", ios::out | ios::binary);
				furnizorText.writeToFile(FOut);
				FOut.close();
				cout << "S-a realizat scrierea in fisierul binar!" << endl;
				fstream FIn("FurnizorB.txt", ios::in | ios::binary);
				Furnizor furnizorBinar;
				if (FIn.is_open())
				{
					furnizorBinar.readFromFile(FIn);
					FIn.close();
					cout << "S-a realizat citirea in fisierul binar" << endl;

				}
				else
				{
					cout << "Fisierul nu a putut fi localizat!" << endl;
				}
				cout << furnizorBinar;
				break;
			}

			default:
				cout << "Comanda invalida!" << endl;
				break;
			}

			break;
			}

			case 6:
				cout << "Ati ales sa parasiti meniul!" << endl;
				break;

			default:
				cout << "Comanda invalida!" << endl;
				break;

			}
		}
	}
};

class Meniu :public Angajat, public Animal, public Comanda, public Furnizor, public Produs, public FisiereBinare
{
protected:

	//raport 
	void afisareSalariu(vector<int>& salariuAngajati)
	{
		int s = 0;

		for (int i = 0; i < salariuAngajati.size(); i++)
		{
			cout << "Salariul anagajatului " << i + 1 << " este:" << salariuAngajati[i] << endl;
			s = s + salariuAngajati[i];

		}
		float m = s / salariuAngajati.size();
		cout << "Salariul mediu al unui angajat este" << m << endl;

		ofstream afisare1("afisareSalariu.txt");
		for (int i = 0; i < salariuAngajati.size(); i++)
		{
			afisare1 << "Salariul anagajatului " << i + 1 << " este:" << salariuAngajati[i] << endl;
		}
		afisare1 << "Salariul mediu al unui angajat este" << m << endl;
		afisare1.close();

	}

	//raport 
	void afisareProduse(vector<string>& numeProduse) {

		for (int i = 0; i < numeProduse.size(); i++)
		{
			cout << "Numele pordusul " << i + 1 << " este: " << numeProduse[i] << endl;
		}

		ofstream afisare2("afisareProduse.txt");
		for (int i = 0; i < numeProduse.size(); i++)
		{
			afisare2 << "Numele pordusul " << i + 1 << " este: " << numeProduse[i] << endl;
		}
		afisare2.close();

	}

	//raport 
	void afisarePretMediu(vector<float>& pretMediuProduse)
	{
		int s = 0;
		for (int i = 0; i < pretMediuProduse.size(); i++)
		{
			cout << "Pretu produsului " << i + 1 << " din magazin este : " << endl;
			cout << pretMediuProduse[i] << endl;
			s = s + pretMediuProduse[i];
		}
		cout << "Pretul mediu al produselor din magazin este:" << endl;
		float m = s / pretMediuProduse.size();
		cout << m;

		ofstream afisare3("afisarePret.txt");
		for (int i = 0; i < pretMediuProduse.size(); i++)
		{
			afisare3 << "Pretu produsului " << i + 1 << " din magazin este : " << endl;
			afisare3 << pretMediuProduse[i] << endl;
		}
		afisare3 << "Pretul mediu al produselor din magazin este:" << m << endl;
		afisare3.close();
	}

	//raport 
	void afisareTotiAngajatii(set<Angajat>& sAng, set<Angajat>::iterator& itSet1)
	{
		for (itSet1 = sAng.begin(); itSet1 != sAng.end(); itSet1++)
			cout << *itSet1;
		ofstream afisare4("afisareAngajati(toti).txt");
		for (itSet1 = sAng.begin(); itSet1 != sAng.end(); itSet1++)
			afisare4 << *itSet1;
		afisare4.close();
	}

	//raport 
	void afisareToateProduse(set<Produs>& sProd, set<Produs>::iterator& itSet2)
	{
		for (itSet2 = sProd.begin(); itSet2 != sProd.end(); itSet2++)
			cout << *itSet2;
		ofstream afisare5("afisareProduse(toate).txt");
		for (itSet2 = sProd.begin(); itSet2 != sProd.end(); itSet2++)
			afisare5 << *itSet2;
		afisare5.close();
	}

public:
	void meniu(vector<string>& numeProduse, vector<int>& salariuAngajati, vector<float>& pretMediuProduse, set<Angajat>& sAng, set<Angajat>::iterator& itSet1, set<Produs>& sProd, set<Produs>::iterator& itSet2)
	{
		cout << "----------------------------------------------------------------------------";
		cout << endl << endl << "--------------------- MENIU PRINCIPAL ----------------------" << endl << endl;
		cout << "----------------------------------------------------------------------------";
		cout << endl << "Selectati o optiune:" << endl;
		cout << "1 - Afisati numele tuturor produselor din magazin!" << endl;
		cout << "2 - Afisati salariile si salariul mediu pentru toti angajatii magazinului!" << endl;
		cout << "3 - Afisati preturile si pretul mediu pentru toate produsele magazinului!" << endl;
		cout << "4 - Afisati toate produsele magazinului!" << endl;
		cout << "5 - Afisati toati angajatii magazinului!" << endl;
		cout << "6 - FAQ" << endl;
		cout << "7 - Gestionare fisierelor binare!" << endl;
		cout << "8 - Parasiti meniul!" << endl;
		cout << endl << "-----------------------------------------------------------" << endl;
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			system("cls");
			cout << "Afisarea tuturor numelor produselor in consola si in fisier text!" << endl;
			Meniu::afisareProduse(numeProduse);
			Sleep(4000);
			Meniu meniu;
			meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
			break;
		}

		case 2:
		{
			system("cls");
			cout << "Afisarea salariile tuturor angajatilor si a salariului mediu in consola si in fisier text!" << endl;
			Meniu::afisareSalariu(salariuAngajati);
			Sleep(4000);
			Meniu meniu;
			meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
			break;
		}

		case 3:
		{
			system("cls");
			cout << "Afisarea pretului mediu al produselor, dar si al pretului individual al acestora in consola si in fisier text!" << endl;
			Meniu::afisarePretMediu(pretMediuProduse);
			Sleep(4000);
			Meniu meniu;
			meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Afisarea tuturor angjatilor magazinului in consola, dar si in fisier text!" << endl;
			Meniu::afisareTotiAngajatii(sAng, itSet1);
			Sleep(6000);
			Meniu meniu;
			meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
			break;
		}
		case 5:
		{	system("cls");
		cout << "Afisarea tuturor produselor magazinului in consola, dar si in fisier text!" << endl;
		Meniu::afisareToateProduse(sProd, itSet2);
		Sleep(6000);
		Meniu meniu;
		meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
		break;
		}
		case 6:
			system("cls");
			cout << "FAQ";
			cout << "Numarul de angajati din magazin!" << endl;
			cout << "Numarul de produse din magazin!" << endl;
			cout << "Intorceti-va la sectiunea anterioara!" << endl;
			cout << "Parasiti meniul!" << endl;

			int optFAQ;
			cin >> optFAQ;
			switch (optFAQ)
			{
			case 1:
			{
				system("cls");
				cout << "Magazinul are " << salariuAngajati.size() << " angajati." << endl;
				ofstream f("nrSalariati.txt");
				f << "Magazinul are " << salariuAngajati.size() << " angajati." << endl;
				f.close();
				Sleep(3000);
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Magazinul vinde " << numeProduse.size() << " produse." << endl;
				ofstream ff("nrProduse.txt");
				ff << "Magazinul vinde " << numeProduse.size() << " produse." << endl;
				ff.close();
				Sleep(3000);
				break;
			}
			case 3:
			{
				Meniu meniu;
				meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
				break;
			}
			case 4:
				system("cls");
				cout << "Multumim pentru interesul acordat!" << endl;
				break;
			default:
				system("cls");
				cout << "Comanda invalida" << endl;
				break;
			}
			break;
		case 7:
		{
			FisiereBinare meniu;
			meniu.meniuBinar();
			break;
		}
		case 8:
			cout << "Ati ales sa parasiti meniul!";
			break;
		default:
			cout << "Comanda Invalida! Incercati din nou!" << endl;
			Sleep(4000);
			Meniu meniu;
			meniu.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);
			break;
		}
	}
};

class Pisica : public Animal
{
private:
	string rasa = "N/A";
public:
	Pisica()
	{}

	Pisica(const char* tipAnimal, int id, int varstaAnimal, float pret, int nrAlimentePermise, string* alimentePermise, float* gramajMaximAliment, int nrVaccinuriNecesare, string* vaccinuriNecesare, bool estePui, string rasa) : Animal(tipAnimal, id, varstaAnimal, pret, nrAlimentePermise, alimentePermise, gramajMaximAliment, nrVaccinuriNecesare, vaccinuriNecesare, estePui)
	{
		this->rasa = rasa;
		
	}

	Pisica(const Pisica& ps) : Animal(ps)
	{
		
		this->rasa = ps.rasa;
	}

	~Pisica()
	{}

	Pisica& operator=(const Pisica& ps)
	{
		this->Pisica::operator=(ps);
		this->rasa = ps.rasa;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Pisica& ps)
	{
		out << (Animal)ps;
		out << "Rasa: " << ps.rasa << endl;
		return out;
	}
};

class Caine : public Animal
{
protected:
	string rasa = "N/A";

public:
	Caine():Animal()
	{
	}

	Caine(const char* tipAnimal, int id, int varstaAnimal, float pret, int nrAlimentePermise, string* alimentePermise, float* gramajMaximAliment, int nrVaccinuriNecesare, string* vaccinuriNecesare, bool estePui, string rasa): Animal(tipAnimal,id,varstaAnimal,pret,nrAlimentePermise,alimentePermise,gramajMaximAliment,nrVaccinuriNecesare,vaccinuriNecesare,estePui)
	{		this->rasa = rasa;
	}

	Caine(const Caine& cn) : Animal(cn)
	{
		this->rasa = cn.rasa;
	}

	~Caine()
	{
	}

	friend ostream& operator<<(ostream& out, const Caine& cn)
	{
		out << (Animal)cn;
		out << "Rasa: " << cn.rasa;
		return out;
	}

	Caine& operator=(const Caine& cn)
	{
		this->Animal::operator=(cn);
		this->rasa = cn.rasa;
		return *this;
	}
};

class Pasare : public Animal
{
protected:
	string tipPasare = "N/A";

public:
	Pasare(): Animal()
	{
	}

	Pasare(const char* tipAnimal, int id, int varstaAnimal, float pret, int nrAlimentePermise, string* alimentePermise, float* gramajMaximAliment, int nrVaccinuriNecesare, string* vaccinuriNecesare, bool estePui, string tipPasare) : Animal(tipAnimal, id, varstaAnimal, pret, nrAlimentePermise, alimentePermise, gramajMaximAliment, nrVaccinuriNecesare, vaccinuriNecesare, estePui)
	{
		this->tipPasare = tipPasare;
	}

	Pasare(const Pasare& psa) : Animal(psa)
	{
		this->tipPasare = psa.tipPasare;
	}

	~Pasare()
	{
	}

	friend ostream& operator<<(ostream& out, const Pasare& psa)
	{
		out << (Animal)psa;
		out << "Rasa: " << psa.tipPasare;
		return out;
	}

	Pasare& operator=(const Pasare& psa)
	{
		this->Animal::operator=(psa);
		this->tipPasare =psa.tipPasare;
		return *this;
	}
};

class Papagal : public Pasare
{
protected:
	string rasa = "N/A";

public:
	Papagal() :Pasare()
	{
	}

	Papagal(const char* tipAnimal, int id, int varstaAnimal, float pret, int nrAlimentePermise, string* alimentePermise, float* gramajMaximAliment, int nrVaccinuriNecesare, string* vaccinuriNecesare, bool estePui,string tipPasare, string rasa) : Pasare(tipAnimal, id, varstaAnimal, pret, nrAlimentePermise, alimentePermise, gramajMaximAliment, nrVaccinuriNecesare, vaccinuriNecesare, estePui,tipPasare)
	{
		this->rasa = rasa;
	}

	Papagal(const Papagal& pp) : Pasare(pp)
	{
		this->rasa = pp.rasa;
	}

	~Papagal()
	{
	}

	friend ostream& operator<<(ostream& out, const Papagal& pp)
	{
		out << (Pasare)pp;
		out << "Rasa: " << pp.rasa;
		return out;
	}

	Papagal& operator=(const Papagal& pp)
	{
		this->Pasare::operator=(pp);
		this->rasa = pp.rasa;
		return *this;
	}
};

class HranaAnimale : public Produs
{
private:
	string animalDestinat="N/A";
public:
	HranaAnimale(): Produs()
	{}
	HranaAnimale(string nume, const char* producator, UM um, float pret, int nrIngrediente, string* compozitie, int nrZile, float* istoricPreturi, bool esteMancare, string animalDestinat) :Produs(nume, producator, um, pret, nrIngrediente, compozitie, nrZile, istoricPreturi, esteMancare)
	{
		this->animalDestinat = animalDestinat;
	}
	HranaAnimale(const HranaAnimale& m) : Produs(m)
	{
		this->animalDestinat = m.animalDestinat;
	}
	HranaAnimale operator=(const HranaAnimale& m)
	{
		if (this != &m)
		{
			this->animalDestinat = m.animalDestinat;
		}
	}
	~HranaAnimale()
	{}

	friend ostream& operator<<(ostream& out, const HranaAnimale& m)
	{
		out << (Produs)m;
		out << "Animal destinat:" << m.animalDestinat;
		return out;
	}
};

class ListaFurnizori {
	int nrFurnizori=0;
	Furnizor** listaFurnizori=NULL;

public:
	ListaFurnizori()
	{
	}

	ListaFurnizori(int nrFurnizori, Furnizor** listaFurnizori)
	{
		this->nrFurnizori = nrFurnizori;
		this->listaFurnizori = new Furnizor*[this->nrFurnizori];
		for (int i = 0; i < this->nrFurnizori; i++)
		{
			this->listaFurnizori[i] = new Furnizor (* listaFurnizori[i]);
		}
	}

	ListaFurnizori(const ListaFurnizori& lf)
	{
		this->nrFurnizori = lf.nrFurnizori;
		this->listaFurnizori = new Furnizor*[this->nrFurnizori];
		for (int i = 0; i < this->nrFurnizori; i++)
		{
			this->listaFurnizori[i] = new Furnizor(*lf.listaFurnizori[i]);
		}
	}

	~ListaFurnizori()
	{
		delete[] this->listaFurnizori;
	}

	ListaFurnizori& operator=(const ListaFurnizori& lf)
	{
		if (this != &lf)
		{
			delete[] this->listaFurnizori;
		}
		this->nrFurnizori = lf.nrFurnizori;
		this->listaFurnizori = new Furnizor*[this->nrFurnizori];
		for (int i = 0; i < this->nrFurnizori; i++)
		{
			this->listaFurnizori[i] = new Furnizor(*lf.listaFurnizori[i]);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const ListaFurnizori& lf)
	{
		out <<endl<< "----------------------------------------------" << endl;
		out << "Numar furnizori: " << lf.nrFurnizori<<endl;
		out << "Furnizori: " << endl;
		for (int i = 0; i < lf.nrFurnizori; i++)
		{
			out << *lf.listaFurnizori[i] << endl;;
		}
		out <<endl<< "----------------------------------------------" << endl;
		return out;
	}
};

class ListaAnimale {
private:
	int nrAnimale = 0;
	int nrPisici = 0;
	int nrCaini = 0;
	int nrPasari = 0;
	int nrPapagali = 0;
	Animal** listaAnimale = NULL;
	Pisica** listaPisici = NULL;
	Caine** listaCaini = NULL;
	Pasare** listaPasari = NULL;
	Papagal** listaPapagali = NULL;

public:
	ListaAnimale()
	{
	}

	ListaAnimale(int nrAnimale,int nrPisici,int nrCaini,int nrPasari,int nrPapagali, Animal** listaAnimale, Pisica ** listaPisici, Caine **listaCaini, Pasare** listaPasari, Papagal** listaPapagali)
	{
		this->nrAnimale = nrAnimale;
		this->nrPisici = nrPisici;
		this->nrCaini = nrCaini;
		this->nrPasari = nrPasari;
		this->nrPapagali = nrPapagali;
		this->listaAnimale = new Animal * [this->nrAnimale];
		this->listaPisici = new Pisica * [this->nrPisici];
		this->listaCaini = new Caine * [this->nrCaini];
		this->listaPasari = new Pasare * [this->nrPasari];
		this->listaPapagali = new Papagal * [this->nrPapagali];
		for (int i = 0; i < this->nrAnimale; i++)
		{
			this->listaAnimale[i] = new Animal(*listaAnimale[i]);
		}
		for (int i = 0; i < this->nrPisici; i++)
		{
			this->listaPisici[i] = new Pisica(*listaPisici[i]);
		}
		for (int i = 0; i < this->nrCaini; i++)
		{
			this->listaCaini[i] = new Caine(*listaCaini[i]);
		}
		for (int i = 0; i < this->nrPasari; i++)
		{
			this->listaPasari[i] = new Pasare(*listaPasari[i]);
		}
		for (int i = 0; i < this->nrPapagali; i++)
		{
			this->listaPapagali[i] = new Papagal(*listaPapagali[i]);
		}
	}

	ListaAnimale(const ListaAnimale& la)
	{
		this->nrAnimale = la.nrAnimale;
		this->nrPisici = la.nrPisici;
		this->nrCaini = la.nrCaini;
		this->nrPasari = la.nrPasari;
		this->nrPapagali = la.nrPapagali;
		this->listaAnimale = new Animal * [this->nrAnimale];
		this->listaPisici = new Pisica * [this->nrPisici];
		this->listaCaini = new Caine * [this->nrCaini];
		this->listaPasari = new Pasare * [this->nrPasari];
		this->listaPapagali = new Papagal * [this->nrPapagali];
		for (int i = 0; i < this->nrAnimale; i++)
		{
			this->listaAnimale[i] = new Animal(*la.listaAnimale[i]);
		}
		for (int i = 0; i < this->nrPisici; i++)
		{
			this->listaPisici[i] = new Pisica(*la.listaPisici[i]);
		}
		for (int i = 0; i < this->nrCaini; i++)
		{
			this->listaCaini[i] = new Caine(*la.listaCaini[i]);
		}
		for (int i = 0; i < this->nrPasari; i++)
		{
			this->listaPasari[i] = new Pasare(*la.listaPasari[i]);
		}
		for (int i = 0; i < this->nrPapagali; i++)
		{
			this->listaPapagali[i] = new Papagal(*la.listaPapagali[i]);
		}
	}

	~ListaAnimale()
	{
		delete[] this->listaAnimale;
		delete[] this->listaPisici;
		delete[] this->listaCaini;
		delete[] this->listaPasari;
		delete[] this->listaPapagali;
	}

	ListaAnimale& operator=(const ListaAnimale& la)
	{
		if (this != &la	)
		{
			delete[] this->listaAnimale;
			delete[] this->listaPisici;
			delete[] this->listaCaini;
			delete[] this->listaPasari;
			delete[] this->listaPapagali;

		}
		this->nrAnimale = nrAnimale;
		this->nrPisici = la.nrPisici;
		this->nrCaini = la.nrCaini;
		this->nrPasari = nrPasari;
		this->nrPapagali = nrPapagali;
		this->listaPisici = new Pisica * [this->nrPisici];
		this->listaCaini = new Caine * [this->nrCaini];
		this->listaAnimale = new Animal * [this->nrAnimale];
		this->listaPasari = new Pasare * [this->nrPasari];
		this->listaPapagali = new Papagal * [this->nrPapagali];
		for (int i = 0; i < this->nrAnimale; i++)
		{
			this->listaAnimale[i] = new Animal(*listaAnimale[i]);
		}
		for (int i = 0; i < this->nrPisici; i++)
		{
			this->listaPisici[i] = new Pisica(*la.listaPisici[i]);
		}
		for (int i = 0; i < this->nrCaini; i++)
		{
			this->listaCaini[i] = new Caine(*la.listaCaini[i]);
		}
		for (int i = 0; i < this->nrPasari; i++)
		{
			this->listaPasari[i] = new Pasare(*la.listaPasari[i]);
		}
		for (int i = 0; i < this->nrPapagali; i++)
		{
			this->listaPapagali[i] = new Papagal(*la.listaPapagali[i]);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const ListaAnimale& la)
	{
		out << endl << "----------------------------------------------" << endl;
		out << "------Gestiune animale ------" << endl;
		out << "Numar animale: " << la.nrAnimale << endl;
		out << "Animale: " << endl;
		for (int i = 0; i < la.nrAnimale; i++)
		{
			out << *la.listaAnimale[i] << endl;;
		}
		out << "------Gestiune pisici ------" << endl;
		out << "Numar Pisici: " << la.nrPisici << endl;
		out << "Pisici: " << endl;
		for (int i = 0; i < la.nrPisici; i++)
		{
			out << *la.listaPisici[i] << endl;
		}
		out << "------Gestiune caini ------" << endl;
		out << "Numar Caini: " << la.nrCaini << endl;
		out << "Caini: " << endl;
		for (int i = 0; i < la.nrCaini; i++)
		{
			out << *la.listaCaini[i] << endl;
		}
		out << "------Gestiune pasari ------" << endl;
		out << "Numar Pasari: " << la.nrPasari << endl;
		out << "Pasari: " << endl;
		for (int i = 0; i < la.nrPasari; i++)
		{
			out << *la.listaPasari[i] << endl;
		}
		out << "------Gestiune papagali ------" << endl;
		out << "Numar Papagali: " << la.nrPapagali << endl;
		out << "Papagali: " << endl;
		for (int i = 0; i < la.nrPapagali; i++)
		{
			out << *la.listaPapagali[i] << endl;
		}
		out << endl << "----------------------------------------------" << endl;
		return out;
	}
};

void Cale()
{
	cout << "Preluarea fisierelor prin cale" << endl;
	string cale = "C:/Users/alexa/source/repos/Proiect POO - Faza 3/ProdusB.txt";

	//cout << "Indicati calea spre fisier:";
	//cin >>cale;
	ifstream file(cale, ios::in);
	//file.open;
	if (file.is_open())
	{	cout <<endl<< "Da, fisierul a fost localizat!"<<endl;
	cout <<endl<< "Alegeti ce tip de date contine fisierul respectiv:" << endl;
	cout << "----- Text -----" << endl;
	cout << "1 - date aferente unui obiect de tip Angajat" << endl;
	cout << "2 - date aferente unui obiect de tip Animal" << endl;
	cout << "3 - date aferente unui obiect de tip Produs" << endl;
	cout << "4 - date aferente unui obiect de tip Comanda" << endl;
	cout << "5 - date aferente unui obiect de tip Furnizor" << endl;
	cout << "----- Binar -----" << endl;
	cout << "6 - date aferente unui obiect de tip Angajat" << endl;
	cout << "7 - date aferente unui obiect de tip Animal" << endl;
	cout << "8 - date aferente unui obiect de tip Produs" << endl;
	cout << "9 - date aferente unui obiect de tip Comanda" << endl;
	cout << "10 - date aferente unui obiect de tip Furnizor" << endl;
	cout << "11 - parasiti Meniul" << endl;
	int opt;
	cin >> opt;
	switch (opt)
	{
	case 1: {
		Angajat angajatText;
		ifstream afile(cale, ios::in);
		if (afile.is_open())
		{
			angajatText.readFromTextFile(afile);
			afile.close();
			cout << endl << "S-a gasit un obiect de tip Angajat!" << endl;
		}
		else
		{
			cout << "Nu a fost gasit un obiect de tip Angajat!";
		}
		cout << angajatText;
		ofstream Afile("AngajatPath.txt", ios::app); //app-append
		angajatText.writeToTextFile(Afile);
		Afile.close();
		cout << endl << endl;
		break;
	}
	case 2: {
		cout << endl;
		Animal animalText;
		ifstream anfile(cale, ios::in);
		if (anfile.is_open()) {
			animalText.readFromTextFile(anfile);
			anfile.close();
			cout << "S-a gasit un obiect de tip Animal!" << endl;
		}
		else {
			cout << "Nu a fost gasit un obiect tip Animal!" << endl;
		}
		cout << animalText << endl;
		ofstream Anfile("AnimalPath.txt", ios::app);
		animalText.writeToTextFile(Anfile);
		Anfile.close();
		
		cout << endl << endl;
		break;
	}
	case 3: {
		Produs produsText;
		ifstream pfile(cale, ios::in);
		if (pfile.is_open()) {
			produsText.readFromTextFile(pfile);
			pfile.close();
			cout << "S-a gasit un obiect de tip Produs!" << endl;
		}
		else {
			cout << "Nu a fost gasit un obiect tip Produs!" << endl;
		
		}
		cout << produsText << endl;
		ofstream Pfile("ProdusPath.txt", ios::app);
		produsText.writeToTextFile(Pfile);
		Pfile.close();
		cout << endl << endl;
		break;
	}
	case 4: {
		Comanda comandaText;
		ifstream cfile(cale, ios::in);
		if (cfile.is_open())
		{
			comandaText.readFromTextFile(cfile);
			cfile.close();
			cout << "S-a gasit un obiect de tip Comanda!" << endl;
		}
		else
		{
			cout << "Nu a fost gasit un obiect de tip Comanda!" << endl;
		}
		cout << comandaText << endl;
		ofstream Cfile("ComandaPath", ios::app);
		comandaText.writeToTextFile(Cfile);
		Cfile.close();
		cout << endl << endl;
		break;
	}
	case 5: {
		cout << "S-a realizat scrierea in fisierul text!" << endl;
		Furnizor furnizorText;
		ifstream ffile(cale, ios::in);
		if (ffile.is_open())
		{
			furnizorText.readFromTextFile(ffile);
			ffile.close();
			cout << "S-a gasit un obiect de tip Furnizor!" << endl;
		}
		else
		{
			cout << "Nu a fost gasit un obiect de tip Furnizor!" << endl;
		}
		cout << furnizorText << endl;
		ofstream Ffile("FurnizorPath.txt", ios::app);
		furnizorText.writeToTextFile(Ffile);
		Ffile.close();
		cout << endl;
		break;
	}
	case 6:
	{
		cout << endl;
		fstream AIn(cale, ios::in | ios::binary);
		Angajat angajataBinar;
		if (AIn.is_open())
		{
			angajataBinar.readFromFile(AIn);
			AIn.close();
			cout << "S-a gasit un obiect de tip Angajat!" << endl;
		}
		else
		{
			cout << "Nu s-a gasit un obiect de tip Angajat!";
		}
		cout << angajataBinar;
		cout << endl << endl;
		fstream AOut("AngajatBPath.txt", ios::app | ios::binary);
		angajataBinar.writeToFile(AOut);
		AOut.close();
		break;
	}
	case 7:
	{
		fstream AnIn(cale, ios::in | ios::binary);
		Animal animalBinar;
		if (AnIn.is_open())
		{
			animalBinar.readFromFile(AnIn);
			AnIn.close();
			cout << "S-a gasit un obiect de tip Animal!" << endl;
		}
		else
		{
			cout << "Nu s-a gasit un obiect de tip Animal!";
		}
		cout << animalBinar;
		fstream AnOut("AnimalBPath.txt", ios::app | ios::binary);
		animalBinar.writeToFile(AnOut);
		AnOut.close();
		cout << endl << endl;
		break;
	}
	case 8:
	{
		fstream PIn(cale, ios::in | ios::binary);
		Produs produsBinar;
		if (PIn.is_open())
		{
			produsBinar.readFromFile(PIn);
			PIn.close();
			cout << "S-a gasit un obiect de tip Produs!" << endl;
		}
		else
		{
			cout << "Nu s-a gasit un obiect de tip Produs!" << endl;
		}
		cout << produsBinar;
		fstream POut("ProdusBPath.txt", ios::app | ios::binary);
		produsBinar.writeToFile(POut);
		POut.close();
		cout << endl << endl;
		break;
	}
	case 9:
	{
		fstream CIn(cale, ios::in | ios::binary);
		Comanda comandaBinar;
		if (CIn.is_open())
		{
			comandaBinar.readFromFile(CIn);
			CIn.close();
			cout << "S-a gasit un obiect de tip Comanda!" << endl;
		}
		else
		{
			cout << "Nu s-a gasit un obiect de tip Comanda!" << endl;
		}
		cout << comandaBinar;
		fstream COut("ComandaBPath.txt", ios::app | ios::binary);
		comandaBinar.writeToFile(COut);
		COut.close();
		cout << endl << endl;
		break;
	}
	case 10:
	{
		cout << endl;
		fstream FIn("FurnizorB.txt", ios::in | ios::binary);
		Furnizor furnizorBinar;
		if (FIn.is_open())
		{
			furnizorBinar.readFromFile(FIn);
			FIn.close();
			cout << "S-a gasit un obiect de tip Furnizor!" << endl;
		}
		else
		{
			cout << "Nu s-a gasit un obiect de tip Angajat!" << endl;
		}
		cout << furnizorBinar;
		fstream FOut("FurnizorBPath.txt", ios::app | ios::binary);
		furnizorBinar.writeToFile(FOut);
		FOut.close();
		cout << endl << endl;
		break;
	}
	case 11:
		cout << "Ati ales sa parasiti meniul!" << endl;
		break;
	default:
		cout << "Comanda Invalida! Incercati din nou!" << endl;
		Cale();
		break;

	}
	file.close();
}
	else
	{
		cout << "Nu, fisierul nu a fost localizat!";
	}
	
}

int main()
{
		//CLASA ANGAJAT 

		cout << "----------------------------------------------------------------------------";
		cout << endl << endl << "---------------- CLASA ANGAJAT----------------------" << endl << endl;
		cout << "----------------------------------------------------------------------------";
		//1.3.1
		Angajat a1;
		cout << a1;
		//1.3.2
		float comision[] = { 0.2, 0.1, 0.3 };
		string istoricFunctii[] = { "vanzator","manager" };
		Angajat a2("Popescu Daniel", 24, 40000, "popescu.daniel@gmail.com", "0767412963", istoricFunctii, 2, 3, comision, 1);
		cout << a2;
		//1.3.3
		Angajat a3("Visan Gabriel", 25);
		cout << a3;
		//1.3.4
		Angajat a4(a2);
		Angajat a5(a2);
		cout << a4;
		//1.3.6
		a3 = a2;
		cout << a3;
		//1.4.1+1.4.2
		Angajat a8;
		//cin >> a8;
		cout << a8;
		//1.5.1
		cout << endl << "In urma folosirii functiei de indexare, functia corespunzatoare pozitiei cerute este: " << a2[1];
		//1.5.2
		cout << "In urma apelului operatorului +, salariul angajatului devine: ";
		Angajat a7 = a4 + 3333;
		cout << a4;
		cout << a7;
		//1.5.3
		cout << endl << "In urma folosirii operatorului ++, varsta finala este:" << endl;
		a3 = ++a4;
		a5 = a4++;
		cout << a3;
		cout << a5;
		//1.5.4
		cout << endl << "In urma folosirii operatorului cast, forma finala a numelui este:" << endl;
		string numeCast = (string)a3;
		cout << numeCast << endl;
		//1.5.5
		cout << endl << "In urma folosirii operatorului !, forma finala este:" << endl;
		!a3;
		cout << a3;
		//1.5.6
		cout << endl << "In urma folosirii operatorului >, s-a decis ca:" << endl;
		if (a2 > a4)
		{
			cout << endl << "Salariul angajatului 2 este mai mare decat salariul angajatului 4" << endl;
		}
		else
		{
			cout << endl << "Salariul angajatului 4 este mai mare decat salariul angajatului 2" << endl;
		}
		//1.5.7
		cout << endl << "In urma folosirii operatorului =, s-a decis ca:" << endl;
		if (a2 == a4)
		{
			cout << endl << "Cele 2 persoane sunt identice" << endl << endl;
		}
		else
		{
			cout << endl << "Persoanele nu sunt identice" << endl << endl;
		}
		//1.1.1+1.1.2
		cout << endl << "-----Getteri si setteri -----";
		a4.setNume("Florin Popescu");
		cout << endl << "Nume: " << a4.getNume() << endl;
		cout << "Id: " << a4.getId() << endl;
		a4.setVarsta(35);
		cout << "Varsta: " << a4.getVarsta() << endl;
		a4.setSalariu(800000);
		cout << "Salariu: " << a4.getSalariu() << endl;
		a4.setMail("florin.pop24");
		cout << "Mail: " << a4.getMail() << endl;
		a4.setTelefon("0767412964");
		cout << "Telefon: " << a4.getTelefon() << endl;
		a4.setExperienta(1);
		cout << "Are experienta? " << a4.getExperienta() << endl;
		string istoricFunctii3[] = { "Vanzator", "Call center", "Manager" };
		a4.setFunctii(3, istoricFunctii3);
		cout << "Nr functii: " << a4.getNrFunctii() << endl;
		cout << "Istoric Functii: " << endl;
		for (int i = 0; i < a4.getNrFunctii(); i++)
		{
			cout << a4.getIstoricFunctii()[i] << " ";
		}
		cout << endl;
		float comision3[] = { 1.2,1.3 };
		a4.setComisioane(2, comision3);
		cout << "Numar comisioane: " << a4.getNrComisioane() << endl;
		cout << "Valori comisioane: " << endl;
		for (int i = 0; i < a4.getNrComisioane(); i++)
		{
			cout << a4.getComisioane()[i] << "  ";
		}
		cout << endl;
		//1.3
		cout << "------ Metode ------" << endl;
		cout << "Metoda 1 - Salariul In Euro este: ";
		a4.cursValutar(4.98);
		cout << endl;
		cout << "Metoda 2 - Suma Comisionelor este:" << a4.SumaComisioane() << endl;
		//2.1.1 + 2.1.2
		cout << endl << endl;
		cout << "------------------ Fisiere text ------------------- " << endl;
		cout << endl;
		ofstream Afile("Angajat.txt", ios::out);
		a2.writeToTextFile(Afile);
		Afile.close();
		cout << "Scrierea in fisierul text a fost realizata!" << endl;
		Angajat angajatText;
		ifstream afile("Angajat.txt", ios::in);
		if (afile.is_open())
		{
			angajatText.readFromTextFile(afile);
			afile.close();
			cout << endl << "S-a realizat citirea din fisier text!" << endl;
		}
		else
		{
			cout << "Fisierul text nu a fost localizat. Incercati un alt fisier!";
		}
		cout << angajatText;
		cout << endl << endl;
		//2.2.1+2.2.2
		cout << "------------------ Fisiere binare ------------------- " << endl;
		cout << endl;
		fstream AOut("AngajatB.txt", ios::out | ios::binary);
		a3.writeToFile(AOut);
		AOut.close();
		cout << "S-a realizat scrierea in fisier binar!" << endl;
		fstream AIn("AngajatB.txt", ios::in | ios::binary);
		Angajat angajataBinar;
		if (AIn.is_open())
		{
			angajataBinar.readFromFile(AIn);
			AIn.close();
			cout << "S-a realizat citirea din fisier binar!" << endl;
		}
		else
		{
			cout << "Fisierul binar nu a fost localizat. Incercati un alt fisier!";
		}
		cout << angajataBinar;
		cout << endl << endl;
		//2.3
		cout << "------------------ Fisiere CSV ------------------- " << endl;
		cout << endl;
		ofstream ACSVfile("AngajatCSV.csv", ios::out);
		a2.writeToCSVFile(ACSVfile);
		ACSVfile.close();
		cout << "Scrierea in fisierul CSV a fost realizata!" << endl;
		cout << endl << endl;
		cout << "----------------------------------------------------------------------------";
		cout << endl << endl << "---------------- CLASA ANGAJAT----------------------" << endl << endl;
		cout << "----------------------------------------------------------------------------";

		//CLASA ANNIMAL 

		cout << "----------------------------------------------------------------------------";
		cout << endl << endl << "---------------- CLASA ANIMAL----------------------" << endl << endl;
		cout << "----------------------------------------------------------------------------";
		Animal an0;
		cout << an0;
		//1.3.2
		Animal an1(1);
		cout << an1;
		//1.3.3
		string alimentePermise1[] = { "Carne de porc","Carne de pui","Carne de vita" };
		float gramajMaximAliment1[] = { 222,221.2,403.2 };
		string vaccinuriNecesare1[] = { "Parvoviroza", "Antirabic" };
		Animal an2("Caine", 2, 2, 300.99, 3, alimentePermise1, gramajMaximAliment1, 2, vaccinuriNecesare1, 1);
		cout << an2;
		//1.3.4
		Animal an3(an2);
		cout << an3;
		//1.5
		Animal an4(4);
		an4 = an2;
		cout << an4;
		//1.4.1 +1.4.2
		Animal an5;
		//cin >> an5;
		cout << an5;
		//1.5.1
		cout << endl << "In urma folosirii functiei de indexare, alimentul corespunzatoare pozitiei cerute este: " << an2[1];
		//1.5.2
		cout << endl << "In urma folosirii operatorului +, pretul final este:" << endl;
		Animal an7 = an5 + 200;
		cout << an5;
		cout << an7;
		//1.5.3
		cout << endl << "In urma folosirii operatorului ++, pretul final este:" << endl;
		an4 = an2++;
		cout << an4;
		an3 = ++an2;
		cout << an3;
		//1.5.4
		int pret = int(an4);
		cout << "In urma folosirii operatorului cast, pretul convertit din float in int este " << pret << endl;
		//1.5.5
		cout << endl << "In urma folosirii operatorului !, forma finala este:" << endl;
		!an4;
		cout << an4;
		//1.5.6
		cout << endl << "In urma folosirii operatorului <, s-a decis ca:" << endl;
		if (an3 < an4)
			cout << "Pretul animalului 3 este mai mic decat pretul animalului 4" << endl;
		else
			cout << "Pretul animalului 4 este mai mic decat pretul animalului 3" << endl;
		//1.5.7
		cout << endl << "In urma folosirii operatorului =, s-a decis ca:" << endl;
		if (an2 == an4)
		{
			cout << endl << "Cele 2 animale sunt identice" << endl << endl;
		}
		else
		{
			cout << endl << "Animalele nu sunt identice" << endl << endl;
		}
		//1.1
		//1.1.1 + 1.1.2 
		cout << endl << "----- Get si Set -----" << endl;
		an3.setTipAnimal("Pisica");
		cout << "Tipul Animal: " << an3.getTipAnimal() << endl;
		cout << "ID Animal: " << an3.getId() << endl;;
		an3.setPret(2000.4);
		cout << "Pretul Animal: " << an3.getPret() << endl;
		an3.setVarsta(3);
		cout << "Varsta Animal: " << an3.getVarsta() << endl;
		an3.setPui(0);
		cout << "Este pui?(0-nu, 1-da) " << an3.getEstePui() << endl;
		string alimenteSET[] = { "bobite","carne cruda","conserva","fructe" };
		float gramajSET[] = { 200,45,21,49 };
		an3.setAlimente(4, alimenteSET, gramajSET);
		cout << "Numarul de alimente permise: " << an3.getNrAlimente() << endl;
		cout << "Alimentele permise sunt:";
		for (int i = 0; i < an3.getNrAlimente(); i++)
		{
			cout << an3.getAlimentePermise()[i] << "  ";
		}
		cout << endl;
		cout << "Gramajul maxim alocat pentru fiecare aliment permis: " << endl;
		for (int i = 0; i < an3.getNrAlimente(); i++)
		{
			cout << an3.getGramajMaxAlimente()[i] << "  ";
		}
		cout << endl;
		string vaccinuriSET[] = { "AntiRabic", "Pentru Imunitate", "Deparazitare", "Parvoviroza" };
		an3.setVaccinuri(4, vaccinuriSET);
		cout << "Nr Vaccinuri Necesare: " << an3.getNrVaccinuri() << endl;
		cout << "Vaccinurile necesare sunt: " << endl;
		for (int i = 0; i < an3.getNrVaccinuri(); i++)
		{
			cout << an3.getVaccinuriNecesare()[i] << "  ";
		}
		cout << endl;
		//1.3 
		cout << "------ Metode ------" << endl;
		cout << "Metoda 1 - Suma gramajelor este: " << an3.gramajSuma() << endl;
		cout << "Metoda 2 - Gramajul Mediu este: " << an3.gramajMediu() << endl;
		cout << endl << endl;
		//2.1.1 + 2.1.2
		cout << "------------------- Fisiere text ---------------------" << endl;
		cout << endl;
		ofstream Anfile("Animal.txt", ios::out);
		an3.writeToTextFile(Anfile);
		Anfile.close();
		cout << "S-a realizat scrierea in fisier text!" << endl;
		Animal animalText;
		ifstream anfile("Animal.txt", ios::in);
		if (anfile.is_open()) {
			animalText.readFromTextFile(anfile);
			anfile.close();
			cout << "S-a realizat citirea in fisier text!" << endl;
		}
		else {
			cout << "Fisierul cautat nu a fost localizat!" << endl;
		}
		cout << animalText << endl;
		cout << endl << endl;
		//2.2.1 + 2.2.2
		cout << "------------------ Fisiere binare ------------------- " << endl;
		cout << endl;
		fstream AnOut("AnimalB.txt", ios::out | ios::binary);
		an3.writeToFile(AnOut);
		AnOut.close();
		cout << "S-a realizat scrierea in fisierul binar" << endl;
		fstream AnIn("AnimalB.txt", ios::in | ios::binary);
		Animal animalBinar;
		if (AnIn.is_open())
		{
			animalBinar.readFromFile(AnIn);
			AnIn.close();
			cout << "S-a realizat citirea in fisierul binar" << endl;
		}
		else
		{
			cout << "Fisierul nu a putut fi localizat!" << endl;
		}
		cout << animalBinar;
		cout << endl << endl;
		//2.3
		cout << "------------------ Fisiere CSV ------------------- " << endl;
		cout << endl;
		ofstream AnCSVfile("AnimalCSV.CSV", ios::out);
		an3.writeToCSVFile(AnCSVfile);
		AnCSVfile.close();
		cout << "S-a realizat scrierea in fisier CSV!" << endl;
		cout << endl << endl;
		cout << "----------------------------------------------------------------------------";
		cout << endl << endl << "---------------- CLASA ANIMAL----------------------" << endl << endl;
		cout << "----------------------------------------------------------------------------";


		//CLASA PRODUS

	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- CLASA PRODUS----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------";
	//1.3.1
	Produs p1;
	cout << p1;
	//1.3.2
	Produs p2("Litiera");
	cout << p2;
	//1.3.3
	string compozitie1[] = { "Apa","Carne","Conservant" };
	float istoricPreturi1[] = { 9.9, 11.9, 10.2 , 11.7 };
	Produs p3("Hrana uscata pentru pisici - Whiskas Sterile", "Whiskas SRL", UM::Kg, 10.99, 3, compozitie1, 4, istoricPreturi1, 1);
	cout << p3;
	//1.3.4
	Produs p4(p3);
	cout << p4;
	//1.3.6
	string compozitie2[] = { "Apa","Vitamine","Carne" };
	float istoricPreturi2[] = { 6.2, 5.9, 5.2 , 5.7 };
	Produs p5("Hrana uscata pentru caini - Pedigree Vital Protection", "Pedigree", UM::Kg, 8.5, 3, compozitie1, 4, istoricPreturi2, 1);
	p4 = p5;
	cout << p4 << endl;
	//1.4.1+1.4.2
	/*Produs p6;
	cin >> p6;
	cout << p6;*/
	//1.5.1
	cout << endl << "In urma folosirii functiei de indexare, alimentul corespunzatoare pozitiei cerute este: " << p5[2] << endl;
	//1.5.2
	Produs p7 = p5 + 0.25;
	cout << p5;
	cout << p7;
	//1.5.3
	cout << endl << "In urma folosirii operatorului ++, pretul final este:" << endl;
	p4 = p5++;
	cout << p4 << endl;
	p4 = ++p5;
	cout << p4 << endl;
	//1.5.4
	cout << endl << "In urma folosirii operatorului cast, conversia este:" << endl;
	string numeCast1 = (string)p5;
	cout << numeCast1 << endl;
	cout << (string)p5 << endl;
	//1.5.5
	cout << endl << "In urma folosirii operatorului !, forma finala este:" << endl;
	!p5;
	cout << p5;
	//1.5.6
	cout << endl << "In urma folosirii operatorului >=, s-a stabilit ca:" << endl;
	if (p3 >= p2)
		cout << "Pretul produsului 3 e mai mare e mai mare decat pretul produsului 2" << endl << endl;
	else
		cout << "Pretului produsului 2 e mai mare decat pretul produsului 3" << endl << endl;
	//1.5.7
	cout << endl << "In urma folosirii operatorului ==, s-a stabilit ca:" << endl;
	if (p3 == p2)
		cout << "Cele 2 produse sunt identice" << endl << endl;
	else
		cout << "Cele 2 produse nu sunt identice" << endl << endl;
	//1.1.1+1.1.2
	cout << endl << "Get si set" << endl;
	cout << "Id: " << p5.getIdProdus() << endl;
	cout << "TVA: " << p5.getTVA() << endl;
	p5.setNume("Litiera");
	cout << "Nume: " << p5.getNume() << endl;
	p5.setProducator("MegaPet");
	cout << "Producator: " << p5.getProducator() << endl;
	p5.setUM(UM::Bucati);
	cout << "UM: " << p5.getUM() << endl;
	p5.setPret(27.3);
	cout << "Pret: " << p5.getPret() << endl;
	p5.seteEsteMancare(0);
	cout << "Este mancare?(0-Nu / 1-Da) " << p5.getEsteMancare() << endl;
	string  compozitieSet[] = { "apa","materiale plastice","nisip","colorant" };
	p5.setCompozitie(4, compozitieSet);
	cout << "Nr de ingrediente din compozitia produsului este: " << p5.getNrIngrediente() << endl;
	for (int i = 0; i < p5.getNrIngrediente(); i++)
	{
		cout << p5.getCompozitie()[i] << "  ";
	}
	cout << endl;
	float istoricPreturiSet[] = { 22.1, 23.4,12.2 };
	p5.setIstoricPreturi(3, istoricPreturiSet);
	cout << "Nr de zile pe care studiem pretul este:" << p5.getNrZile() << endl;
	cout << "Istoricul preturilor este: " << endl;
	for (int i = 0; i < p5.getNrZile(); i++)
	{
		cout << p5.getIstoricPreturi()[i] << "  ";
	}
	cout << endl;
	//1.2
	cout << "------ Metode ------" << endl;
	cout << "Metoda 1 -Pretul fara TVA este: " << p5.pretFaraTVA() << endl;
	cout << "Metoda 2- Pretul mediu este: " << p5.mediaPreturilor() << endl;
	cout << endl << endl;
	//2.1.1+2.1.2
	cout << "------------------ Fisiere text ------------------- " << endl;
	cout << endl;
	ofstream Pfile("Produs.txt", ios::out);
	p3.writeToTextFile(Pfile);
	Pfile.close();
	cout << "S-a realizat scrierea in fisier text!" << endl;
	Produs produsText;
	ifstream pfile("Produs.txt", ios::in);
	if (pfile.is_open()) {
		produsText.readFromTextFile(pfile);
		pfile.close();
		cout << "S-a realizat citirea in fisier text!" << endl;
	}
	else {
		cout << "Fisierul cautat nu a fost localizat!" << endl;
	}
	cout << produsText << endl;
	cout << endl << endl;
	//2.2.1+2.2.2
	cout << "------------------ Fisiere binare ------------------- " << endl;
	cout << endl;
	fstream POut("ProdusB.txt", ios::out | ios::binary);
	p3.writeToFile(POut);
	POut.close();
	cout << "S-a realizat scrierea in fisierul binar!" << endl;
	fstream PIn("ProdusB.txt", ios::in | ios::binary);
	Produs produsBinar;
	if (PIn.is_open())
	{
		produsBinar.readFromFile(PIn);
		PIn.close();
		cout << "S-a realizat citirea in fisierul binar" << endl;
	}
	else
	{
		cout << "Fisierul nu a putut fi localizat!" << endl;
	}
	cout << produsBinar;
	cout << endl << endl;
	//2.3
	cout << "------------------ Fisiere CSV ------------------- " << endl;
	cout << endl;
	ofstream PCSVfile("ProdusCSV.csv", ios::out);
	p3.writeToCSVFile(PCSVfile);
	PCSVfile.close();
	cout << "S-a realizat scrierea in fisier CSV!" << endl;
	cout << endl << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- CLASA PRODUS----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------";

	//CLASA COMANDA  

	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- CLASA COMANDA----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------";
	//1.3.1
	Comanda c1;
	cout << c1;
	//1.3.2
	Comanda c2("1234NFOLE", "Popescu Ion");
	cout << c2;
	//1.3.3
	string produse1[] = { "Patut pentru pisici","Hrana umeda petru pisici - Whiskas Fortunate","Litiera" };
	float reduceri1[] = { 29.7,20 };
	Comanda c3("1K365M044", "Pica George", 2220.6, 0, 3, produse1, 2, reduceri1);
	cout << c3;
	//1.3.4
	Comanda c4(c3);
	cout << c4;
	//1.3.5
	Comanda c5;
	c5 = c3;
	cout << c5;
	//1.4.1+1.4.2
	/*Comanda c6;
	cin >> c6;
	cout << c6;*/
	//1.5.1
	cout << endl << "In urma folosirii functiei de indexare, produsul corespunzator pozitiei cerute este: " << c4[2] << endl;
	//1.5.2
	cout << endl << "In urma folosirii operatorului +, pretul final este:" << endl;
	Comanda c7 = c5 + 200;
	cout << c5;
	cout << c7;
	// 1.5.3
	cout << endl << "In urma folosirii operatorului ++, pretul final este:" << endl;
	c5 = c4++;
	cout << c5;
	c5 = ++c4;
	cout << c5;
	// 1.5.4
	//cast
	cout << endl << "In urma folosirii operatorului cast, conversia este:" << endl;
	cout << (int)c5;
	//1.5.5
	cout << endl << "In urma folosirii operatorului !, forma finala este:" << endl;
	!c5;
	cout << c5;
	//1.5.6
	cout << endl << "In urma folosirii operatorului <=, s-a stabilit ca:" << endl;
	if (c3 <= c4)
		cout << "Pretul comenzii 3 este mai mic decat pretul comenzii 4" << endl << endl;
	else
		cout << "Pretul comenzii 4 este mai mic decat pretul comenzii 3" << endl << endl;
	//1.5.7
	cout << endl << "In urma folosirii operatorului ==, s-a stabilit ca:" << endl;
	if (c3 == c5)
		cout << "Cele 2 produse sunt egale" << endl << endl;
	else
		cout << "Produsele nu sunt egale" << endl << endl;
	//1.1.1+1.1.2
	cout << "----- Get si set -----" << endl;
	c5.setID("argre2345d");
	cout << "Id Comanda: " << c5.getID() << endl;
	c5.setNumeClient("Vasile Lascar");
	cout << "Nume client: " << c5.getNumeClient() << endl;
	c5.setPret(3000.4);
	cout << "Pret Comanda: " << c5.getPretComanda() << endl;
	string produseSET[] = { "Litiera","Bobite pentru Caini","Jucarii","Pestisor auriu" };
	c5.setProduse(4, produseSET);
	cout << "Numar Produse din Comanda: " << c5.getNrProduse() << endl;
	cout << "Produsele din comanda: ";
	for (int i = 0; i < c5.getNrProduse(); i++)
	{
		cout << c5.getProduse()[i] << "  ";
	}
	cout << endl;
	float reduceriSET[] = { 23.2,50,10 };
	c5.setReduceri(3, reduceriSET);
	cout << "Numar Reduceri per Comanda: " << c5.getNrReduceri() << endl;
	cout << "Reducerile din comanda: " << endl;
	for (int i = 0; i < c5.getNrReduceri(); i++)
	{
		cout << c5.getReduceri()[i] << "  ";
	}
	cout << endl;
	//1.3 Metode
	cout << "Metoda 1 - Suma reducerilor este: " << c4.SumaReduceri() << endl;
	cout << "Metoda 2 -Media reducerilor este: " << c4.mediaReduceri() << endl;
	cout << endl << endl;
	// 2.1.1 + 2.1.2
	cout << "------------------ Fisiere text ------------------- " << endl;
	cout << endl;
	ofstream Cfile("Comanda.txt", ios::out);
	c3.writeToTextFile(Cfile);
	Cfile.close();
	cout << "S-a realizat scrierea in fisierul text" << endl;
	Comanda comandaText;
	cout << comandaText;
	ifstream cfile("Comanda.txt", ios::in);
	if (cfile.is_open())
	{
		comandaText.readFromTextFile(cfile);
		cfile.close();
		cout << "S-a realizat citirea in fisierul text" << endl;
	}
	else
	{
		cout << "Fisierul nu a putut fi localizat!" << endl;
	}
	cout << comandaText << endl;
	cout << endl << endl;
	//2.2.1 + 2.2.2
	cout << "------------------ Fisiere binare ------------------- " << endl;
	cout << endl;
	fstream COut("ComandaB.txt", ios::out | ios::binary);
	c3.writeToFile(COut);
	COut.close();
	cout << "S-a realizat scrierea in fisierul binar" << endl;
	fstream CIn("ComandaB.txt", ios::in | ios::binary);
	Comanda comandaBinar;
	if (CIn.is_open())
	{
		comandaBinar.readFromFile(CIn);
		CIn.close();
		cout << "S-a realizat citirea in fisierul binar!" << endl;
	}
	else
	{
		cout << "Fisierul nu a putut fi localizat!" << endl;
	}
	cout << comandaBinar;
	cout << endl << endl;
	// 2.3
	cout << "------------------ Fisiere CSV ------------------- " << endl;
	cout << endl;
	ofstream CCSVfile("ComandaCSV.csv", ios::out);
	c3.writeToCSVFile(CCSVfile);
	CCSVfile.close();
	cout << "S-a realizat scrierea in fisierul CSV" << endl;
	cout << endl << endl;
	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- CLASA COMANDA----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------";

	//	//CLASA FURNIZOR 

	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- CLASA FURNIZOR----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------";
	//1.3.1
	Furnizor f1;
	cout << f1;
	//1.3.2
	Furnizor f2("ABCERDG");
	cout << f2;
	//1.3.3
	float cantitati1[]{ 22.3,56.3,2.3 };
	string produse11[] = { "Mancare uscata", "Conserve animale","Nisip" };
	string modalitati1[] = { "Cash","Cec","Transfer Bancar" };
	Furnizor f3("ABFERFTR", "Whiskas SRL", 24000.5, 3, cantitati1, produse11, 3, modalitati1, 1);
	cout << f3;
	//1.3.4
	Furnizor f4(f3);
	cout << f4;
	//1.3.5
	Furnizor f5;
	f5 = f4;
	cout << f5;
	//1.4.1+1.4.2
	/*Furnizor f6;
	cin >> f6;
	cout << f6;*/
	//1.5.1
	cout << endl << "In urma folosirii functiei de indexare, modalitatea de plata corespunzator pozitiei cerute este: " << endl;
	cout << f4[2];
	//1.5.2
	Furnizor f7 = f5 + 200;
	cout << f5;
	cout << f7;
	//1.5.3
	cout << endl << "In urma folosirii operatorului ++, totalul final este:" << endl;
	f5 = f4++;
	cout << f5;
	f5 = ++f4;
	cout << f5;
	//1.5.4
	cout << endl << "In urma folosirii operatorului cast, conversia este:" << endl;
	cout << (int)f5;
	//1.5.5
	cout << endl << "In urma folosirii operatorului !, forma finala este:" << endl;
	!f5;
	cout << f5;
	//1.5.6
	cout << endl << "In urma folosirii operatorului >=, s-a stabilit ca:" << endl;
	if (f3 > f5)
		cout << "Totalul comenzii la furnizorul 3 este mai mic decat Totalul comenzii la furnizorul 4" << endl << endl;
	else
		cout << "Totalul comenzii la furnizorul 4 este mai mic decat Totalul comenzii la furnizorul 3" << endl << endl;
	//1.5.7
	cout << endl << "In urma folosirii operatorului ==, s-a stabilit ca:" << endl;
	if (f3 == f5)
		cout << endl << "Furnizorii sunt identici" << endl << endl;
	else
		cout << endl << "Furnizorii nu sunt identici" << endl << endl;
	//1.1.1+1.1.2
	cout << "----- Get si set -----";
	f5.setNumeFurnizor("MegaPet");
	cout << "Nume furnizor: " << f5.getNumeFurnizor() << endl;
	cout << "ID furnizor: " << f5.getCodFurnizor() << endl;
	f5.setPlatit(0);
	cout << "A fost furnizorul platit? (0 -nu / 1 - da)" << f5.getPlatit() << endl;
	f5.setTotalComanda(25000);
	cout << "Total comanda: " << f5.getTotalComanada() << endl;
	string numeSET[] = { "Litiere","Jucarii","Hrana Uscata","Mei" };
	float cantitatiSET[] = { 22,55,45,35.4 };
	f5.setProduse(4, numeSET, cantitatiSET);
	cout << "Nr produse: " << f5.getNrProduse() << endl;
	cout << "Nume produse: " << endl;
	for (int i = 0; i < f5.getNrProduse(); i++) {
		cout << f5.getNumeProduse()[i] << "  ";
	}
	cout << endl;
	cout << "Cantitate produse: " << endl;
	for (int i = 0; i < f5.getNrProduse(); i++) {
		cout << f5.getCantitate()[i] << "  ";
	}
	cout << endl;
	string modalitatiSET[] = { "Cash","Cec","Ordin de plata","Depunere in cont" };
	f5.setPlata(4, modalitatiSET);
	cout << "Nr modalitati de plata: " << f5.getNrModalitati() << endl;
	cout << "Modalitati de plata" << endl;
	for (int i = 0; i < f5.getNrModalitati(); i++) {
		cout << f5.getModalitati()[i] << " ";
	}
	cout << endl;
	cout << "----- Metode -----" << endl;
	cout << endl;
	cout << "Metoda 1 - Suma cantitatilor produselor este: " << f5.sumaCantitate() << endl;
	cout << "Metoda 2 - Media cantitatilor produselor este: " << f5.mediaCantitate() << endl;
	cout << endl << endl;
	// 2.1.1 + 2.1.2
	cout << "------------------ Fisiere text ------------------- " << endl;
	cout << endl;
	ofstream Ffile("Furnizor.txt", ios::out);
	f3.writeToTextFile(Ffile);
	Ffile.close();
	cout << "S-a realizat scrierea in fisierul text!" << endl;
	Furnizor furnizorText;
	ifstream ffile("Furnizor.txt", ios::in);
	if (ffile.is_open())
	{
		furnizorText.readFromTextFile(ffile);
		ffile.close();
		cout << "S-a realizat citirea in fisierul text!" << endl;
	}
	else
	{
		cout << "Fisierul nu a putut fi localizat!" << endl;
	}
	cout << furnizorText << endl;
	cout << endl;
	// 2.2.1 + 2.2.2
	cout << "------------------ Fisiere binare ------------------- " << endl;
	cout << endl;
	fstream FOut("FurnizorB.txt", ios::out | ios::binary);
	f3.writeToFile(FOut);
	FOut.close();
	cout << "S-a realizat scrierea in fisierul binar!" << endl;
	fstream FIn("FurnizorB.txt", ios::in | ios::binary);
	Furnizor furnizorBinar;
	if (FIn.is_open())
	{
		furnizorBinar.readFromFile(FIn);
		FIn.close();
		cout << "S-a realizat citirea in fisierul binar" << endl;
	}
	else
	{
		cout << "Fisierul nu a putut fi localizat!" << endl;
	}
	cout << furnizorBinar;
	cout << endl << endl;
	// 2.3
	cout << "------------------ Fisiere CSV ------------------- " << endl;
	cout << endl;
	ofstream FCSVfile("FurnizorCSV.csv", ios::out);
	f3.writeToCSVFile(FCSVfile);
	FCSVfile.close();
	cout << "S-a realizat scrierea in fisierul CSV!" << endl;
	Furnizor furnizorCSV;
	ifstream fCSVfile("FurnizorCSV.csv", ios::in);
	if (fCSVfile.is_open())
	{
		furnizorCSV.readFromTextFile(fCSVfile);
		fCSVfile.close();
		cout << "S-a realizat citirea in fisierul CSV!" << endl;
	}
	else
	{
		cout << "Fisierul nu a putut fi localizat!" << endl;
	}
	cout << furnizorCSV << endl;
	cout << endl << endl;
	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- CLASA FURNIZOR----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------";

		//Rapoarte - folosite in cadrul meniului principal
		//Raport nume produse magazin
		vector<string> numeProduse;
		vector<int>::iterator it1;
		numeProduse.push_back(p3.getNume());
		numeProduse.push_back(p4.getNume());
		numeProduse.push_back(p5.getNume());
		//Raport salariu angajati
		vector<int> salariuAngajati;
		salariuAngajati.push_back(a2.getSalariu());
		salariuAngajati.push_back(a3.getSalariu());
		salariuAngajati.push_back(a4.getSalariu());
		//Raport pret mediu
		vector<float> pretMediuProduse;
		pretMediuProduse.push_back(p3.getPret());
		pretMediuProduse.push_back(p4.getPret());
		pretMediuProduse.push_back(p5.getPret());
		//Raport angajati
		Angajat Ang[] = { a2,a3,a4 };
		ColectieAngajati<Angajat> cAng(3, Ang);
		set<Angajat>sAng;
		sAng.insert(a2);
		sAng.insert(a3);
		sAng.insert(a4);
		set<Angajat>::iterator itSet1;
		//Raport produse
		Produs Prod[] = { p3,p4,p5 };
		ColectieProduse<Produs> cProd(3, Prod);
		set<Produs>sProd;
		sProd.insert(p3);
		sProd.insert(p4);
		sProd.insert(p5);
		set<Produs>::iterator itSet2;
	
		//Meniuri
		cout << endl << endl;
		cout << "----------------------------------------------------------------------------";
		cout << endl << endl << "---------------- MENIURI----------------------" << endl << endl;
		cout << "----------------------------------------------------------------------------";
		//Meniu Fisiere Binare - se apeleaza in meniul principal
		FisiereBinare meniu;
		//meniu.meniuBinar();
		Meniu meniuPrincipal;
		meniuPrincipal.meniu(numeProduse, salariuAngajati, pretMediuProduse, sAng, itSet1, sProd, itSet2);

	//Compunerea claselor
	cout << endl<<"----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- COMPUNEREA CLASELOR----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------"<<endl;
	ListaFurnizori lf;
	cout << lf;
	Furnizor* vectFurnizori[] = { &f2,&f4,&f3 };
	ListaFurnizori lf2(3,vectFurnizori);
	cout << lf2;

	//Metode virtuale 
	cout << "Pretul produsului in euro este" << p3.calculPretProdusEuro(4.9) << endl;
	cout << "Pretul produsului fara TVA este:" << p3.calculPretProdusFaraTVA() << endl;

	//Metode virtuale pure
	cout << "Pretul comenzii fara TVA este:" << c3.calculPretComandaFaraTVA() << endl;
	cout << "Pretul comenzii in Euro este:" << c3.calculPretComandaEuro(4.9) << endl;

	//Extinderea claselor + ierarhie
	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- EXTINDEREA CLASELOR----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------"<<endl;

	//Pisica
	cout << endl << endl << "---------------- PISICA----------------------" << endl << endl;
	Pisica ps1;
	cout << ps1;
	string alimentePermisePS2[] = { "Hrana uscata","Conserva" };
	float gramajMaximAlimentPS2[] = { 106.8,300 };
	string vaccinuriNecesarePS2[] = { "Parvoviroza" };
	Pisica ps2("Pisica", 9, 4, 600.3, 2, alimentePermisePS2, gramajMaximAlimentPS2, 1, vaccinuriNecesarePS2, 1, "Siameza");
	cout << ps2;
	Pisica ps3(ps2);
	cout << ps3;

	//Caine
	cout << endl << endl << "---------------- CAINE ----------------------" << endl << endl;
	Caine cn1;
	cout << cn1;
	string alimentePermiseCN2[] = { "Carne de pui","Hrana Uscata","Conserve" };
	float gramajMaximAlimentCN2[] = { 232,111.2,203.2 };
	string vaccinuriNecesareCN2[] = { "Parvoviroza", "Antirabic" };
	Caine cn2("Caine", 10, 2, 33.3, 3, alimentePermiseCN2, gramajMaximAlimentCN2, 2, vaccinuriNecesareCN2, 1, "BullDog Francez");
	cout << cn2;
	Caine cn3(cn2);
	cout << cn3;

	//Pasare
	cout << endl << endl << "---------------- PASARE ----------------------" << endl << endl;
	Pasare psa1;
	cout << psa1;
	string alimentePermisePSA1[] = { "Mei","Fructe","Legume" };
	float gramajMaximAlimentPSA1[] = { 232,111.2,203.2 };
	string vaccinuriNecesarePSA1[] = { "Polimavirus" };
	Pasare psa2("Pasare", 300, 2, 45.3, 3, alimentePermisePSA1, gramajMaximAlimentPSA1, 1, vaccinuriNecesarePSA1, 1, "Papagal");
	cout << psa2;
	Pasare psa3(psa2);
	cout << psa3;

	//Papagal
	cout << endl << endl << "---------------- Papagal ----------------------" << endl << endl;
	Papagal pp1;
	cout << pp1;
	string alimentePermisePP1[] = { "Mei","Fructe","Legume" };
	float gramajMaximAlimentPP1[] = { 232,111.2,203.2 };
	string vaccinuriNecesarePP1[] = { "Polimavirus" };
	Papagal pp2("Pasare", 10, 2, 33.3, 3, alimentePermisePP1, gramajMaximAlimentPP1, 1, vaccinuriNecesarePP1, 1, "Papagal","Nimfa");
	cout << pp2;
	Pasare pp3(pp2);
	cout << pp3;
	ListaAnimale la;
	cout << la;
	Animal* vectAnimal[] = { &an2,&an4,&an3 };
	Pisica* vectPisica[] = { &ps2 };
	Caine* vectCaine[] = { &cn2 };
	Pasare* vectPasare[] = { &psa2 };
	Papagal* vectPapagal[] = { &pp2 };
	ListaAnimale la2(3, 1, 1, 1, 1, vectAnimal, vectPisica, vectCaine, vectPasare, vectPapagal);
	cout << la2;

	//HranaAnimal
	HranaAnimale h1;
	cout << h1;
	string compozitieM[] = { "Apa","Carne","Conservant" };
	float istoricPreturiM[] = { 10,10.99 };
	HranaAnimale h2("Whiskas Bobite", "Whiskas", UM::Kg, 5.5, 3, compozitie1, 2, istoricPreturi1, 1, "Caini");
	cout << h2;

	//STL-uri
	cout << "----------------------------------------------------------------------------";
	cout << endl << endl << "---------------- STL----------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------"<<endl;
	
	vector<Furnizor> vectorFurnizorSTL;
	list<Comanda> listComandaSTL;
	set<Produs> setProdusSTL;
	map<float, Comanda> mapComandaSTL;
	cout << "----- Gestiunea obiectelor cu ajutorul STL-urilor -----" << endl;
	void GestiuneObiecteSTL(vector<Furnizor>& vectorFurnizorSTL, list<Comanda>& listComandaSTL, set<Produs>& setProdusSTL, map<float, Comanda>& mapComandaSTL);
	{
		cout << " Alegeti optiunea dorita:" << endl;
		cout << "1 - Gestionarea furnizorilor - vector"<<endl;
		cout << "2 - Gestionarea comenzilor - list"<<endl;
		cout << "3 - Gestionarea produselor - set" << endl;
		cout << "4 - Gestionarea comenzilor si a preturilor acestora - map" << endl;
		cout << " 5- Parasirea meniului de gestiune!" << endl;
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			cout << endl << "----- VECTOR -----" << endl;
			vectorFurnizorSTL.push_back(f2);
			vectorFurnizorSTL.push_back(f3);
			vectorFurnizorSTL.push_back(f4);
			vectorFurnizorSTL.push_back(f5);
			cout << "Furnizorii magazinului sunt:" << endl;
			for (int i = 0; i < vectorFurnizorSTL.size(); i++)
			{
				cout << vectorFurnizorSTL[i] << endl;
			}
			Sleep(4000);
			break;
		}

		case 2:
		{
			cout << endl << "----- LIST -----" << endl;
			listComandaSTL.push_back(c2);
			listComandaSTL.push_back(c3);
			listComandaSTL.push_back(c4);
			listComandaSTL.push_back(c5);
			list<Comanda>::iterator itC1;
			cout << "Comenzile magazinului sunt:" << endl;
			for (itC1 = listComandaSTL.begin(); itC1 != listComandaSTL.end(); itC1++)
			{
				cout << *itC1 << endl;
			}
			Sleep(4000);
			break;
		}

		case 3:
		{
			cout << endl << "----- SET -----" << endl;
			cout << "Podusele magazinului sunt:" << endl;
			setProdusSTL.insert(p2);
			setProdusSTL.insert(p3);
			setProdusSTL.insert(p4);
			set<Produs>::iterator it2;
			for (it2 = setProdusSTL.begin(); it2 != setProdusSTL.end(); it2++)
			{
				cout << *it2 << endl;
			}
			Sleep(4000);
			break;
		}
		
		case 4:
		{
			cout << endl << "----- MAP -----" << endl;
			cout << "Comenzile magazinului si preturile acestora sunt:" << endl;
			mapComandaSTL.insert(pair<float, Comanda>(c2.getPretComanda(), c2));
			mapComandaSTL.insert(pair<float, Comanda>(c3.getPretComanda(), c3));
			mapComandaSTL.insert(pair<float, Comanda>(c5.getPretComanda(), c5));
			map<float, Comanda>::iterator it3;
			for (it3 = mapComandaSTL.begin(); it3 != mapComandaSTL.end(); it3++)
			{
				cout << it3->first << " " << it3->second << endl;
			}
			Sleep(4000);
			break;
		}
		case 5:
		{
			cout << "Ati ales sa parasiti acest meniu!" << endl;
			break;
		}
		
		default:
			cout << "Comanda invalida!";
			break;
		}
	}
	// indicarea unor fisiere cu date prin cale
	Cale();

	cout << endl << "--------------------------------- ! FINAL ! ------------------------------------" << endl;
	return 0;
}