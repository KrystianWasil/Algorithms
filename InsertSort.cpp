#include <iostream>


struct Child {
    std::string code;
    double s;
    int d;
    int m;
};


void InsertSortForMSD(Child tab[],  int n){
    Child pom;
    int j;
    for ( int i=1; i<n; i++){
        if (tab[i].m > tab[i-1].m || (tab[i].m == tab[i-1].m && tab[i].s > tab[i-1].s) || (tab[i].m == tab[i-1].m && tab[i].s == tab[i-1].s && tab[i].d > tab[i-1].d)){
            pom = tab[i];
            for (j=i-1; (j>=0) && (tab[j].m < pom.m || (tab[j].m == pom.m && tab[j].s < pom.s) || (tab[j].m == pom.m && tab[j].s == pom.s && tab[j].d < pom.d));j--) tab[j + 1] = tab[j];
            tab[j + 1] = pom;
        }
    }
}
void InsertSortForMDS(Child tab[],  int n){
    Child pom;
    int j;
    for ( int i=1; i<n; i++){
        if (tab[i].m > tab[i-1].m || (tab[i].m == tab[i-1].m && tab[i].d > tab[i-1].d) || (tab[i].m == tab[i-1].m && tab[i].d == tab[i-1].d && tab[i].s > tab[i-1].s)){
            pom = tab[i];
            for (j=i-1; (j>=0) && (tab[j].m < pom.m || (tab[j].m == pom.m && tab[j].d < pom.d) || (tab[j].m == pom.m && tab[j].d== pom.d && tab[j].s < pom.s));j--) tab[j + 1] = tab[j];
            tab[j + 1] = pom;
        }
    }
}
void InsertSortForSDM(Child tab[],  int n){
    Child pom;
    int j;
    for ( int i=1; i<n; i++){
        if (tab[i].s > tab[i-1].s || (tab[i].s == tab[i-1].s && tab[i].d > tab[i-1].d) || (tab[i].s == tab[i-1].s  && tab[i].d == tab[i-1].d && tab[i].m > tab[i-1].m)){
            pom = tab[i];
            for (j=i-1; (j>=0) && (tab[j].s < pom.s || (tab[j].s == pom.s && tab[j].d < pom.d) || (tab[j].s == pom.s && tab[j].d== pom.d && tab[j].m < pom.m));j--) tab[j + 1] = tab[j];
            tab[j + 1] = pom;
        }
    }
}
void InsertSortForSMD(Child tab[],  int n){
    Child pom;
    int j;
    for ( int i=1; i<n; i++){
        if (tab[i].s > tab[i-1].s || (tab[i].s == tab[i-1].s && tab[i].m > tab[i-1].m) || (tab[i].s == tab[i-1].s  && tab[i].m == tab[i-1].m && tab[i].d > tab[i-1].d)){
            pom = tab[i];
            for (j=i-1; (j>=0) && (tab[j].s < pom.s || (tab[j].s == pom.s && tab[j].m < pom.m) || (tab[j].s == pom.s && tab[j].m == pom.m && tab[j].d < pom.d));j--) tab[j + 1] = tab[j];
            tab[j + 1] = pom;
        }
    }
}
void InsertSortForDSM(Child tab[],  int n){
    Child pom;
    int j;
    for ( int i=1; i<n; i++){
        if (tab[i].d > tab[i-1].d || (tab[i].d == tab[i-1].d && tab[i].s> tab[i-1].s) || (tab[i].d == tab[i-1].d && tab[i].s == tab[i-1].s && tab[i].m > tab[i-1].m)){
            pom = tab[i];
            for (j=i-1; (j>=0) && (tab[j].d < pom.d|| (tab[j].d == pom.d && tab[j].s < pom.s) || (tab[j].d == pom.d && tab[j].s == pom.s && tab[j].m < pom.m));j--) tab[j + 1] = tab[j];
            tab[j + 1] = pom;
        }
    }
}
void InsertSortForDMS(Child tab[],  int n){
    Child pom;
    int j;
    for ( int i=1; i<n; i++){
        if (tab[i].d > tab[i-1].d || (tab[i].d == tab[i-1].d && tab[i].m > tab[i-1].m) || (tab[i].d == tab[i-1].d && tab[i].m == tab[i-1].m && tab[i].s > tab[i-1].s)){
            pom = tab[i];
            for (j=i-1; (j>=0) && (tab[j].d < pom.d|| (tab[j].d == pom.d && tab[j].m < pom.m) || (tab[j].d == pom.d && tab[j].m == pom.m && tab[j].s< pom.s));j--) tab[j + 1] = tab[j];
            tab[j + 1] = pom;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::string letters;
    std::cin >> n;
    std::cin.ignore();
    Child *boys = new Child[n];
    Child *girls= new Child[n];
    getline(std::cin,letters);

    for (int i = 0; i < n; i++) {
        std::cin>>boys[i].code;
        std::cin>>boys[i].s;
        std::cin>>boys[i].d;
        std::cin>>boys[i].m;
        std::cin>>girls[i].code;
        std::cin>>girls[i].s;
        std::cin>>girls[i].d;
        std::cin>>girls[i].m;

    }

    if (letters == "m s d"){
        InsertSortForMSD(boys,n);
        InsertSortForMSD(girls,n);
    }
    else if (letters == "m d s"){
        InsertSortForMDS(boys,n);
        InsertSortForMDS(girls,n);

    }
    else if (letters == "s d m"){
        InsertSortForSDM(boys,n);
        InsertSortForSDM(girls,n);
    }
    else if (letters == "s m d"){
        InsertSortForSMD(boys,n);
        InsertSortForSMD(girls,n);

    }
    else if (letters == "d s m"){
        InsertSortForDSM(boys,n);
        InsertSortForDSM(girls,n);

    }
    else if (letters == "d m s"){
        InsertSortForDMS(boys,n);
        InsertSortForDMS(girls,n);
    }


    for (int i = 0 ; i < n; i++){
        std::cout << boys[i].code << " " << girls[i].code << " ";
    }

    delete [] boys;
    delete [] girls;


    return  0;
}
