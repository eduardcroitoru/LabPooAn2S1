#include "Playlist.h"
#include <vector>
#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

template < typename T>
std::pair<bool, int > findInVector(const std::vector<T>  & vecOfElements, const T  & element)
{
    std::pair<bool, int > result;
    auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
    if (it != vecOfElements.end())
    {
        result.second = distance(vecOfElements.begin(), it);
        result.first = true;
    }
    else
    {
        result.first = false;
        result.second = -1;
    }
    return result;
}





Playlist::Playlist(const vector<Song> &songs, float durata) : ListaCantece(songs, durata) {}

Playlist::Playlist() : ListaCantece() {}

Playlist::~Playlist() {
}

const vector<Song> &Playlist::getSongs() const {
    return songs;
}

void Playlist::setSongs(const vector<Song> &songs) {
    Playlist::songs = songs;
}

float Playlist::getDurata() const {
    return durata;
}

void Playlist::setDurata(float durata) {
    Playlist::durata = durata;
}

Playlist &Playlist::operator=(const Playlist& ob)
{
    if(this!=&ob)
    {
        songs = ob.songs;
        durata = ob.durata;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Playlist &playlist) {
    os <<" durata: " << playlist.durata<< " songs: ";

    for(unsigned int i=0; i<playlist.songs.size(); i++)
        os<<playlist.songs[i].getName()<<" ";

    return os;
}

Playlist Playlist::operator+(const Song &p) {
    this->songs.push_back(p);
    this->durata += p.getDurata();

    return *this;
}

Playlist Playlist::operator-(const Song &p) {
    std::pair<bool, int> result = findInVector<Song>(songs, p);
    if (result.first)
        this->songs.erase(songs.begin() + result.second);

    this->durata -= p.getDurata();

    return *this;
}

Song Playlist::playRandom() {
    srand (time(NULL));

    return songs[rand()%songs.size()];
}
