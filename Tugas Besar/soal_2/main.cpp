#include "DLLPlaylist.h"

int main()
{
    List songList;
    createList(songList);

    Song A;
    A.Artist = "Harvest";
    A.Title = "Nozomu";
    A.DurationSec = 180;
    A.PlayCount = 200;
    A.Rating = 4.5;
    insertFirst(songList, A);
    A.Title = "Fantasi Depresi";
    A.Artist = "Rina Hime";
    A.DurationSec = 120;
    A.PlayCount = 140;
    A.Rating = 4.4;
    insertFirst(songList, A);
    A.Title = "Kataomoi";
    A.Artist = "Nekodachi";
    A.DurationSec = 140;
    A.PlayCount = 150;
    A.Rating = 4.2;
    insertFirst(songList, A);

    viewList(songList);

    Song B;
    cout << "Delete Last" << endl;
    deleteLast(songList, B);
    viewList(songList);

    cout << "Update song" << endl;
    updateAtPosition(songList, 2);
    viewList(songList);

    cout << "Insert before" << endl;
    A.Title = "Scope";
    A.Artist = "Aimer";
    A.DurationSec = 185;
    A.PlayCount = 250;
    A.Rating = 4.5;
    insertBefore(songList, songList.tail->next, A);

    cout << "Insert before" << endl;
    A.Title = "Scope";
    A.Artist = "Aimer";
    A.DurationSec = 185;
    A.PlayCount = 250;
    A.Rating = 4.5;
    insertBefore(songList, songList.tail->next, A);

    cout << "updateBefore" << endl;
    updateBefore(songList, songList.head->next);
    viewList(songList);

    cout
        << "Delete before" << endl;
    deleteBefore(songList, songList.tail->next, A);
    viewList(songList);

    cout << "Search by Popularity Score Range" << endl;
    searchByPopularityRange(songList, 150, 300);

    return 0;
}