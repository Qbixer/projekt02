#include "Listy.h"

void ruch(int *okno,int *pole_x, int *pole_y, int tmp_pole_x, int tmp_pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2] ,bool *kolor_ruchu, bool stan_wiez_krola[6]);

void dostepne_ruchy(int *okno, bool *kolor_ruchu, int *szach, int *pole_x, int *pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool czy_szach[8][8], bool czyszczenie);

void roszada(int *okno, bool *kolor_ruchu, int *szach, int *pole_x, int *pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool czy_szach[8][8], bool stan_wiez_krola[6]);

void bicie_w_przelocie(int *okno, bool *kolor_ruchu, int *szach, int *pole_x, int *pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool czy_szach[8][8], lista *glowa);

void komp(int *okno, int *komputer, bool *kolor_ruchu, int *pole_x, int *pole_y, int *szach, int plansza[8][8], bool czy_szach[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool stan_wiez_krola[6], lista *glowa);