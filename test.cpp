#include <iostream>
#include <cmath>
#include "fanno.h"

int main() {
	
	double M1 = 0.08;
	double guess = 0.00001;
	double Length = 9.0;
	double f = 0.003;
	double D = 0.02;
	double gama = 1.4;
	double P1 = 100000;
	double T1 = 290;
	double rho1 = 160;
	
	double M2 = 0.0;
	double P2 = 0.0;
	double T2 = 0.0;
	double rho2 = 0.0;
	
	// Mach2
	// (
	// 	M1,   // inlet mach number
	// 	M2 ,// outlet mach number which is going to be calculated (output of the function)
	// 	Length,    // total length of the pipe in meters
	// 	f,    // friction factor
	//     D,    // diameter of the pipe in meters
	// 	gama, // specific heat ratio
	// 	guess // guess value for M2; if subsonic, choose 0.000001
	// );
	// std::cout << "M2 = " << M2 << std::endl;
	
	// Pressure2
	// (
	// 	P1,   //  pressure at the beginning of the pipe
 //       P2,  //  pressure at the end of the pipe (output of the function)
 //       M1,   //  Mach number at the beginning of the pipe
 //       M2,   //  Mach number at the end of the pipe
 //       gama
	// );
	// std::cout << "P2 = " << P2 << std::endl;
	
	// temperature2
	// (
	// 	T1,  // temperature at the beginning of the pipe
 //   	T2,  // temperature at the end of the pipe (output of the function)
 //   	gama, // specific heat ratio
 //   	M1,   // Mach number at the beginning of the pipe
 //   	M2    // Mach number at the end of the pipe
	// );
	// std::cout << "T2 = " << T2 << std::endl;
	
	// density2
	// (
	// 	rho1,   // density at the beginning of the pipe
	// 	rho2,   // density at the end of the pipe (output of the funciton)
	// 	gama,   // specific heat ratio
 //       M1,     // Mach number at the beginning of the pipe
 //       M2      // Mach number at the end of pipe
	// );
	// std::cout << "rho2 = " << rho2 << std::endl;

	int error = fanno::fanno_flow
	(
		M1,   // inlet mach number
		M2,   // outlet mach number which is going to be calculated (output)
		P1,   // pressure at the beginning of the pipe
		P2,   // pressure at the end of the pipe (output)
		rho1, // density at the beginiing of the pipe
		rho2, // density at the end of the pipe (output)
		T1,   // temperature at the beginning of the pipe
		T2,   // temperature at the end of the pipe (output)
		Length,    // total length of the pipe in meters
		f,    // friction factor
		D,    // diameter of the pipe in meters
		gama, // specific heat ratio
		guess // guess value for M2; if subsonic, choose 0.000001
	);
	if (error == 1) 
	{
		std::cout << "Mach 1 is reached before the end of pipe length." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "M2 = " << M2 << std::endl;
		std::cout << "P2 = " << P2 << std::endl;
		std::cout << "T2 = " << T2 << std::endl;
		std::cout << "rho2 = " << rho2 << std::endl;
	}
	
	
return 0;
}

