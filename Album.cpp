#include "Album.h"
#include <ctime>
using namespace std;
Album::Album(const vector<Song> &songs, float durata, const string &albumname, const Singer &cantaret) : ListaCantece(songs,
                                                                                                                  durata),
                                                                                                         albumname(
                                                                                                                 albumname),
                                                                                                         cantaret(
                                                                                                                 cantaret) {}

Album::Album() : ListaCantece() {}



Album::~Album() {

}

ostream &operator<<(ostream &os, const Album &album) {
    os  << " albumname: " << album.albumname <<endl<< " cantaret: "<< album.cantaret<<endl;
    os << static_cast<const ListaCantece &>(album);
    return os;
}

Song Album::playRandom() {
    srand (time(NULL));

    return songs[rand()%songs.size()];
}

Album Album::operator+(const Song &p) {
    this->songs.push_back(p);
    this->durata += p.getDurata();

    return *this;
}

void Album::setAlbumname(const string &albumname) {
    Album::albumname = albumname;
}

void Album::setCantaret(const Singer &cantaret) {
    Album::cantaret = cantaret;
}

const string &Album::getAlbumname() const {
    return albumname;
}

const Singer &Album::getCantaret() const {
    return cantaret;
}
