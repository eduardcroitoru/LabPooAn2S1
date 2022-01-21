#ifndef DESKTOP_LISTACANTECE_H
#define DESKTOP_LISTACANTECE_H
#include <string>
#include <vector>
#include <ostream>
#include "Song.h"

class ListaCantece {
protected:
    std::vector<Song> songs;
    float durata;

public:
    ListaCantece();
    ListaCantece(const vector<Song> &songs, float durata);

    friend ostream &operator<<(ostream &os, const ListaCantece &cantece);

    virtual Song playRandom() = 0;
};


#endif
