/*
 * mes_defs.h
 */


struct Forecast {
        char letter;
        std::string description;
};


struct Barometer {
        int number;
        char letter;
        std::string text;
        int pressure;
};


#define RISING_SIZE 14
#define STEADY_SIZE 11
#define FALLING_SIZE 10

#define RISING_MIN 947
#define RISING_MAX 1030

#define STEADY_MIN 960
#define STEADY_MAX 1033

#define FALLING_MIN 995 
#define FALLING_MAX 1050

enum Season { WINTER, SUMMER };
enum Tendance { A_LA_BAISSE, STABLE, A_LA_HAUSSE };


/* prototypes de fonctions */
//char correction(enum Season, char letter);
int p_to_p0 (int);
float p_to_p0(float,float,float);
char p_to_letter_in_rising(int);
char p_to_letter_in_steady(int);
char p_to_letter_in_falling(int);
char correction_ete(char);
char correction_hiver(char);



struct Forecast forecast[26]={
                {'A',"Settled Fine"},
                {'B',"Fine Weather"},
                {'C',"Becoming Fine"},
                {'D',"Fine Becoming Less Settled"},
                {'E',"Fine, Possibly showers"},
                {'F',"Fairly Fine, Improving"},
                {'G',"Fairly Fine, Possibly showers, early"},
                {'H',"Fairly Fine Showery Later"},
                {'I',"Showery Early, Improving"},
                {'J',"Changeable Mending"},
                {'K',"Fairly Fine , Showers likely"},
                {'L',"Rather Unsettled Clearing Later"},
                {'M',"Unsettled, Probably Improving"},
                {'N',"Showery Bright Intervals"},
                {'O',"Showery Becoming more unsettled"},
                {'P',"Changeable some rain"},
                {'Q',"Unsettled, short fine Intervals"},
                {'R',"Unsettled, Rain later"},
                {'S',"Unsettled, rain at times"},
                {'T',"Very Unsettled, Finer at times"},
                {'U',"Rain at times, worse later."},
                {'V',"Rain at times, becoming very unsettled"},
                {'W',"Rain at Frequent Intervals"},
                {'X',"Very Unsettled, Rain"},
                {'Y',"Stormy, possibly improving"},
                {'Z',"Stormy, much rain"}
        };


struct Barometer falling[10]={
                {0,'\0',"",0},
                {1, 'A',"Settled Fine", 1050},
                {2, 'B',"Fine Weather", 1040},
                {3, 'D',"Fine Becoming Less Settled",1024},
                {4, 'H',"Fairly Fine Showery Later", 1018},
                {5, 'O',"Showery Becoming more unsettled",1010},
                {6, 'R',"Unsettled, Rain later",1004},
                {7, 'U',"Rain at times, worse later." , 998},
                {8, 'V',"Rain at times, becoming very unsettled",991},
                {9, 'X',"Very Unsettled, Rain", 985}
        };

struct Barometer steady[11]={
                {0,'\0',"",0},
                {1, 'A',"Settled Fine",         1033},
                {2, 'B',"Fine Weather",         1023},
                {3, 'E',"Fine, Possibly showers", 1014},
                {4, 'K',"Fairly Fine , Showers likely",1008},
                {5, 'N',"Showery Bright Intervals", 1000},
                {6, 'P',"Changeable some rain", 994},
                {7, 'S',"Unsettled, rain at times", 989},
                {8, 'W',"Rain at Frequent Intervals",981},
                {9, 'X',"Very Unsettled, Rain", 974},
                {10,'Z',"Stormy, much rain", 960}

        };


struct Barometer rising[14]={
                {0,'\0',"",0},
                {1, 'A',"Settled Fine", 1030},
                {2, 'B',"Fine Weather", 1022},
                {3, 'C',"Becoming Fine",1012},
                {4, 'F',"Fairly Fine, Improving",1007},
                {5, 'G',"Fairly Fine, Possibly showers, early", 1000},
                {6, 'I',"Showery Early, Improving", 995},
                {7, 'J',"Changeable Mending", 990},
                {8, 'L',"Rather Unsettled Clearing Later",984},
                {9, 'M',"Unsettled, Probably Improving", 978},
                {10, 'Q',"Unsettled, short fine Intervals",970},
                {11,'T',"Very Unsettled, Finer at times", 965},
                {12,'Y',"Stormy, possibly improving", 959},
                {13,'Z',"Stormy, much rain",947}

        };

