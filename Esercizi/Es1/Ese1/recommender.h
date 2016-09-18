
#include "list_pointer.h"

template<class T>
using List = List_pointer<T>;
using namespace std;

class Rating{
public:
    string utente;
    string prodotto;
    int rating;

    bool operator == (const Rating &r) const;
};


class recommender{
public:

// inserisce nella lista ratings una nuovo rating
// <user, item, rating>
void insert(string user, string item, int rating);
// restituisce la media dei rating dell’utente user
double meanUser(string user);
// restituisce la media dei rating per il prodotto item
double meanItem(string item);
// restituisce la lista dei prodotti votati dall’utente user
List<string> rated(string user);
// restituisce la lista dei prodotti votati sia dall’utente user1
// che dall’utente user2
List<string> common(string user1, string user2);
// usando il metodo common, calcola quanti prodotti sono stati votati
// allo stesso modo sia dall’utente user1 che dall’utente user2
int commonEqual(string user1, string user2);
private:
List<Rating> ratings;
};

bool Rating::operator == (const Rating &r) const{
    return (utente == r.utente && prodotto == r.prodotto && rating == r.rating);
}


void recommender::insert(string user, string item, int rat){
    Rating new_rating;
    new_rating.utente = user;
    new_rating.prodotto = item;
    new_rating.rating = rat;
    auto p = ratings.begin();
    ratings.insert(new_rating, p);
}

double recommender::meanUser(string user){
    auto p = ratings.begin();
    int sum = 0; int n = 0;
    while(!ratings.end(p)){
        if(ratings.read(p).utente == user){
            sum = sum + ratings.read(p).rating;
            n++;
        }
        p = ratings.next(p);
    }
    return (double)sum/n;
}

double recommender::meanItem(string item){
    auto p = ratings.begin();
    int sum = 0; int n = 0;
    while(!ratings.end(p)){
        if(ratings.read(p).prodotto == item){
            sum = sum + ratings.read(p).rating;
            n++;
        }
        p = ratings.next(p);
    }
    return (double)sum/n;
}

List<string> recommender::rated(string user){
    List<string> ratedP;
    auto p = ratings.begin();
    auto pr = ratedP.begin();
    int sum = 0; int n = 0;
    while(!ratings.end(p)){
        if(ratings.read(p).utente == user){
            ratedP.insert(ratings.read(p).prodotto,pr);
        }
        p = ratings.next(p);
    }
    return ratedP;
}

List<string> recommender::common(string user1, string user2){
    List<string> ratedUser1 = rated(user1);
    List<string> ratedUser2 = rated(user2);
    List<string> commonRated;
    auto p3 = commonRated.begin();
    auto p1 = ratedUser1.begin();
    while(!ratedUser1.end(p1)){
        string targetProd = ratedUser1.read(p1);
        auto p2 = ratedUser2.linear_search(targetProd);
        if(p2 != NULL)
            commonRated.insert(targetProd,p3);
        p1 = ratedUser1.next(p1);
    }
    return commonRated;
}

int recommender::commonEqual(string user1, string user2){
    List<string> commonRated = common(user1,user2);
    auto p1 = commonRated.begin();
    int n = 0;
    while(!commonRated.end(p1)){
        int found = 0;
        auto p2 = ratings.begin();
        int tempRating1 = -1; int tempRating2 = -1;
        while(!ratings.end(p2) && found < 2){
            Rating r = ratings.read(p2);
            if(r.utente == user1 && r.prodotto == commonRated.read(p1)){
                tempRating1 = r.rating;
                found++;
            }
            if(r.utente == user2 && r.prodotto == commonRated.read(p1)){
                tempRating2 = r.rating;
                found++;
            }
            if(found == 2)
                if(tempRating1 == tempRating2)
                    n++;
            p2 = ratings.next(p2);
        }
        p1 = commonRated.next(p1);
    }
    return n;
}


