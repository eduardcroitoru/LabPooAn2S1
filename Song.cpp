#include "Song.h"
#include <string>
using namespace std;


const string &Song::getName() const {
    return name;
}

void Song::setName(const string &name) {
    Song::name = name;
}

int Song::getIdSong() const {
    return idSong;
}


float Song::getDurata() const {
    return durata;
}

void Song::setDurata(float durata) {
    Song::durata = durata;
}


Song::Song(): idSong(counter++), name("defaultsong"), durata(0.01) {}

Song::Song(const string &name, float durata) : idSong(counter++), name(name), durata(durata) {}

Song::Song(const Song &s) {
    idSong = s.idSong;
    name = s.name;
    durata = s.durata;
}


ostream &operator<<(ostream &os, const Song &song) {
    os << "idSong: " << song.idSong << " name: " << song.name << " durata: "
       << song.durata;

    return os;
}

Song::~Song() {

}

bool Song::operator<(const Song &rhs) const {
    if (durata < rhs.durata)
        return true;
    if (rhs.durata < durata)
        return false;
}

bool Song::operator>(const Song &rhs) const {
    return rhs < *this;
}

bool Song::operator<=(const Song &rhs) const {
    return !(rhs < *this);
}

bool Song::operator>=(const Song &rhs) const {
    return !(*this < rhs);
}

bool Song::operator==(const Song &rhs) const {
    return idSong == rhs.idSong &&
           name == rhs.name &&
           durata == rhs.durata;
}



