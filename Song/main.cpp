#include "Song.h"

using namespace upgrade; 


int main(){

    Song song("title", "artist", 120, "energetic"); 

    Song song2("woo", "Rihanna", 130, "rave"); 

    song.play();
    song.play();
    song.play();

    song2.play();

    song.markFavourite();
    song.display();
    song2.display();


    return 0;
}