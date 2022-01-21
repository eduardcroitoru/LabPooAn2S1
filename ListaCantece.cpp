#include "ListaCantece.h"

ListaCantece::ListaCantece() : durata(0){}

ListaCantece::ListaCantece(const vector<Song> &songs, float durata) : songs(songs), durata(durata) {}

ostream &operator<<(ostream &os, const ListaCantece &cantece) {
    os << " durata: " << cantece.durata<<"songs: ";
    for(unsigned int i=0; i<cantece.songs.size(); i++)
        os<<cantece.songs[i].getName()<<" ";
    return os;
}
