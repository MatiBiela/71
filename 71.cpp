#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class file
{
        ifstream inFile;
    	int dokladnosc = 0.00001;
    	double A, B, C, D;
    	
        public:
        	double f(double x, double A, double B, double C, double D);
                file();
                ~file();
                void loop(); 
                void max();
};


file::file()
{
        inFile.open("funkcja.txt"); 
        if (!inFile.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}

file::~file()
{
        inFile.close();
}


void file::loop()
{
        while (!inFile.eof())  
        {
                inFile >> A >> B >> C >> D;
               cout << this->f(2 , A, B, C, D);
        }
}
double file::f(double x, double A, double B, double C, double D){
	return ((A*x+B)*x+C)*x+D * dokladnosc;

}
void file::max(){
	
}

int main()
{
        file f;
        f.loop();
        f.f();
        return 0;
}
