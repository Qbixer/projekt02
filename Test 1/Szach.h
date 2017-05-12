int czy_moge_biale(int *pole_x, int *pole_y, int plansza[8][8], int pionki[16][2]);

int czy_moge_czarne(int *pole_x, int *pole_y, int plansza[8][8], int pionki[16][2]);

void sprawdzenie_szachu(int *okno,int plansza[8][8], bool czy_szach[8][8], int pionki_czarne[16][2], int pionki_biale[16][2], bool *kolor_ruchu, int *szach);

void szach_mat(int *okno, int plansza[8][8], bool czy_szach[8][8], bool *kolor_ruchu, int pionki_czarne[16][2], int pionki_biale[16][2], int *szach, int *pole_x, int *pole_y);
