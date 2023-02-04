#include <bits/stdc++.h>
using namespace std;

struct train {
    int train_no;
    train *next;
};

struct station {
    int station_no;
    train *first;
    train *last;
};

void station_N(station **that_station, int train_no) {
    station *tmp = *that_station;
    train *new_train = (train *)malloc(sizeof(train *)), *tmp2;
    new_train->train_no = train_no;
    new_train->next = NULL;
    //if that station has no train
    if (tmp->first == NULL) {
        tmp->first = new_train;
        tmp->last = new_train;
    }
    else {
        tmp2 = tmp->last;
        tmp2->next = new_train;

        tmp->last = new_train;
    }
}
//move all train in station1 to station2
int station_M(station **station1, station **station2) {
    station *s1 = *station1, *s2 = *station2;
    //check if there exist train in s1
    if (s1->first == NULL) return 0;
    train *t1 = s1->first;
    //go to where we will put train in s1 to s2
    //s2 has no train
    if (s2->first == NULL) {
        s2->first = t1;
        s2->last = s1->last;
    }
    //s2 has train
    else {
        train *t2 = s2->last;
        t2->next = s1->first;
        s2->last = s1->last;
    }
    s1->first = NULL;
    s1->last = NULL;
    return 0;
}

int sprint(station *sx) {
    //if there is no train in station end here
    if (sx->first == NULL) return 0;
    train *tx = sx->first;
    while (tx != NULL) {
        cout << tx->train_no << "\n";
        tx = tx->next;
    }
    return 0;
}




int main() {
    int M, i, a, b;
    cin >> M;
    char command;
    set<int, less<int> > used;
    int used2[100000] = {0};
    station **All = (station **)malloc(sizeof(station *) * 100000);
    //new station*;    

    for (i=0;i<M;i++) {
        cin >> command >> a >> b;
        if (!used2[b - 1]) {
            used.insert(b - 1);
            used2[b - 1] = 1;

            station *sta = (station *)malloc(sizeof(station *));
            //new station;
            sta->station_no = b;
            sta->first = NULL;
            sta->last = NULL;
            All[b - 1] = sta;
        }

        if (command == 'N') {
            station_N(&All[b - 1], a);
        }
        else if (command == 'M') {
            if (!used2[a - 1]) {
                used.insert(a - 1);
                used2[a - 1] = 1;
                
                station *sta = (station *)malloc(sizeof(station *));
                //new station;
                sta->station_no = a;
                sta->first = NULL;
                sta->last = NULL;
                All[a - 1] = sta;
            }
            station_M(&All[a - 1], &All[b - 1]);
        }
    }
    set<int>::iterator itr;
    for (itr = used.begin();itr != used.end(); itr++){
        //cout << "delta\n";
        //cout << *itr << "\n";
        sprint(All[*itr]);
    }
}