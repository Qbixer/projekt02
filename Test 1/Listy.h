struct lista
{
	lista *next;
	lista *prev;
	int pole_x;
	int pole_y;
	bool zmiana_stanu;
	int zbity;
	int prev_pole_x;
	int prev_pole_y;
};

void sprawy_z_lista(int *okno, int *pole_x, int *pole_y, int tmp_pole_x, int tmp_pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], lista *glowa, bool stan_wiez_krola[6], bool *czy_lista);

void do_undo(int *okno, int plansza[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool *kolor_ruchu, lista *glowa, bool *undo, bool *koniec, bool stan_wiez_krola[6]);

void do_redo(int *okno, int plansza[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool *kolor_ruchu, lista *glowa, bool *redo, bool *czy_undo, bool stan_wiez_krola[6]);