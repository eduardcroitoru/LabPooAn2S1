#include "Singer.h"
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Song.h"
#include <ctime>

using namespace std;

Singer::Singer(): idSinger(id++), nume("default"), an_lansare(2000), gen_muzical("default"){}

Singer::Singer(const string &nume, int anLansare, const string &genMuzical, const vector<Song> &songs) : idSinger(id++), nume(nume),an_lansare(anLansare),gen_muzical(genMuzical),songs(songs) {}


Singer::Singer(const Singer& s):idSinger(id++)
{
    nume=s.nume;
    an_lansare=s.an_lansare;
    gen_muzical=s.gen_muzical;
    songs = s.songs;
}

Singer::~Singer() {
    //std vector isi apeleaza propriul destructor
}

Singer &Singer::operator=(const Singer &s)
{
    if(this!=&s)
    {
        nume=s.nume;
        an_lansare=s.an_lansare;
        gen_muzical=s.gen_muzical;
        songs = s.songs;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Singer &singer) {
    os << "idSinger: " << singer.idSinger << " nume: " << singer.nume << " an_lansare: " << singer.an_lansare
       << " gen_muzical: " << singer.gen_muzical << " songs: ";

    for(unsigned int i=0; i<singer.songs.size(); i++)
        os<<singer.songs[i].getName()<<" ";

    return os;
}

int Singer::getIdSinger() const {
    return idSinger;
}

const string &Singer::getNume() const {
    return nume;
}

void Singer::setNume(const string &nume) {
    Singer::nume = nume;
}

int Singer::getAnLansare() const {
    return an_lansare;
}

void Singer::setAnLansare(int anLansare) {
    an_lansare = anLansare;
}

const string &Singer::getGenMuzical() const {
    return gen_muzical;
}

void Singer::setGenMuzical(const string &genMuzical) {
    gen_muzical = genMuzical;
}

const vector<Song> &Singer::getSongs() const {
    return songs;
}

void Singer::setSongs(const vector<Song> &songs) {
    Singer::songs = songs;
}

Singer Singer::operator+(const Song &s) {
    this->songs.push_back(s);
    return *this;
}

std::vector<Song> Singer::shuffle() {
    srand(time(NULL));

    std::random_shuffle(this->songs.begin(), this->songs.end());
    return this->songs;
}


