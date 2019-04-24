#include <iostream>
#include <string>
#include "mes_defs.h"




int main(int argc, char* argv[]) {





	std::cout << "the forecast letter scale" << std::endl;
	for (int i=0; i<26; i++){
		std::cout << forecast[i].letter << "  " << forecast[i].description << std::endl;
	}


	std::cout << "\nbarometer falling" << std::endl;
	for (int i=1; i<FALLING_SIZE ; i++){
		std::cout << falling[i].letter << " " << falling[i].text << " " << falling[i].pressure << std::endl;
	}

	std::cout << "\nbarometer steady" << std::endl;
	for (int i=1; i<STEADY_SIZE ; i++){
		std::cout << steady[i].letter << " " << steady[i].text << " " << steady[i].pressure << std::endl;
	}

	std::cout << "\nbarometer rising" << std::endl;
	for (int i=1; i<RISING_SIZE ; i++){
		std::cout << rising[i].number << " " << rising[i].letter << " " << rising[i].text << " " << rising[i].pressure << std::endl;
	}

	/***************************************** TODO *****************************************/

	/*
	 * A Winter falling generally results in a Z value lower by 1 unit compared with a Summer falling pressure. 
	 * Similarly a Summer rising, improves the prospects by 1 unit over a Winter rising.
	 *
	 */ 


	

	int p=1015;
	int deltaP;
	Season season = SUMMER;
	Tendance tendance=A_LA_HAUSSE;
	char letter='\0';


	


	switch(tendance) {

		case A_LA_HAUSSE:	
			letter=p_to_letter_in_rising(p);
			std::cout << "p_to_letter_in_rising(" << p << ") -> " << letter << std::endl;
			if (season == SUMMER) {
				// letter++ dans le tableau rising
				letter=correction_ete(letter);
				std::cout << "correction_ete --> " << letter << std::endl; 
			}			
			break;

		case STABLE:
			letter=p_to_letter_in_steady(p);
			break;

		case A_LA_BAISSE:
			letter=p_to_letter_in_falling(p);
			if (season == WINTER) {
				// letter-- dans le tableau falling
				letter=correction_hiver(letter);
			}	
			break;
	}

	std::cout << "pression = " << p << "   -> lettre : " << letter << std::endl;





	return 0;
}

//entree: la lettre
//sortie: la lettre+1 dans le tableau rising
//-------------------------------------------
char correction_ete(char letter) {
	char z='\0';

	// on trouve la lettre dans le tableau
	int j=0;
	for (int i=1; i<RISING_SIZE; i++) {
		j=i;
		z = rising[i].letter;
		if ( letter == rising[i].letter ) { break; }
	}
	// on applique la correction
	z = rising[j+1].letter;

	return z;
}


//entree: la lettre
//sortie: la lettre-1 dans le tableau falling
//-------------------------------------------
char correction_hiver(char letter) {
	char z='\0';

	// on trouve la lettre dans le tableau
	int j=0;
	for (int i=1; i<RISING_SIZE; i++) {
		j=i;
		z = falling[i].letter;
		if ( letter == falling[i].letter ) { break; }
	}
	// on applique la correction
	z = falling[j-1].letter;

	return z;
}


//entree: la pression 
//sortie: la lettre correspondant dans le tableau rissing
//-------------------------------------------------------
char p_to_letter_in_rising(int p) {
	char z = '\0';

	//TODO : check p entre MIN et MAX

	for (int i=1; i<RISING_SIZE ; i++){
		z = rising[i].letter;
		if ( p >= rising[i].pressure ) { break; }
	}
	return z;
}

//entree: la pression 
//sortie: la lettre correspondant dans le tableau steady
//-------------------------------------------------------
char p_to_letter_in_steady(int p) {
	char z = '\0';

	//TODO : check p entre MIN et MAX

	for (int i=1; i<STEADY_SIZE ; i++){
		z = steady[i].letter;
		if ( p >= steady[i].pressure ) { break; }
	}
	return z;
}

//entree: la pression 
//sortie: la lettre correspondant dans le tableau falling
//-------------------------------------------------------
char p_to_letter_in_falling(int p) {
	char z = '\0';

	//TODO : check p entre MIN et MAX

	for (int i=1; i<FALLING_SIZE ; i++){
		z = falling[i].letter;
		if ( p >= falling[i].pressure ) { break; }
	}
	return z;
}







//entree : la pression du capteur
//sortie : la pression au niveau de la mer
//----------------------------------------
int p_to_p0 (int p){
	// TODO
	return p;
}

//entree: la pression 
//	  la temperature 
//	  l altitude
//sortie: la pression au niveau de la mer
//--------------------------------------------------
float p_to_p0(float p, float t, float h) {
	float p0=0.0f;
	
	p0 = p * pow(1-((0.0065*h)/(t*0.0065*h+273.15)),-5.257)

	return p0;
}

