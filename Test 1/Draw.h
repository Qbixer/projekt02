void draw_menu(int *okno, bool *fullscreen, int *pos_x, int *pos_y, int szerokosc, int wysokosc, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36);

void draw_board(int *okno, bool *done, bool *down, bool *undo, bool *redo, int *szach, int szerokosc, int wysokosc, int *pos_x, int *pos_y, ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36);

void draw_tips(int *okno, int szerokosc, int wysokosc, bool mozliwy_ruch[8][8]);

void draw_chess_pieces(int *okno, int szerokosc, int wysokosc, int *pos_x, int *pos_y, int tab[8][8], ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36, ALLEGRO_BITMAP *kingw, ALLEGRO_BITMAP *queenw, ALLEGRO_BITMAP *rookw, ALLEGRO_BITMAP *bishopw, ALLEGRO_BITMAP *knightw, ALLEGRO_BITMAP *pawnw, ALLEGRO_BITMAP *kingb, ALLEGRO_BITMAP *queenb, ALLEGRO_BITMAP *rookb, ALLEGRO_BITMAP *bishopb, ALLEGRO_BITMAP *knightb, ALLEGRO_BITMAP *pawnb);

void menu(int *okno, bool *done, bool *down, bool *fullscreen, int *kolor, int szerokosc, int wysokosc, int *pos_x, int *pos_y, ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36);

void wybrane_pole(int *okno, int szerokosc, int wysokosc, int *pos_x, int *pos_y, int *pole_x, int *pole_y, ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue);