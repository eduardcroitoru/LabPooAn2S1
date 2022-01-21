#include <iostream>
#include "Singer.h"
#include "Song.h"
#include "Playlist.h"
#include "ListaCantece.h"
#include "Album.h"
#include<bits/stdc++.h>
#include <typeinfo>
#include "SingletoneMenu.h"

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

SingletoneMenu* SingletoneMenu::object=0;

int main() {
    try{
        SingletoneMenu* m = m->getInstance();
        m->meniu();
    }
    catch(...){
        cout<<"Meniu invalid";
    }
    return 0;
}
