

coord buttons[N_BUTTONS];

void create_bg(const char* file){
   IMAGE *image = loadBMP(file);
   putimage(0, 0, image, COPY_PUT);
   freeimage(image);
}

void create_button(int n, int x, int y, const char* file){
   IMAGE *image = loadBMP(file);
   buttons[n].x1 = ;
   buttons[n].y1 = ;
   _abracadabra_cast(buttons[n]);