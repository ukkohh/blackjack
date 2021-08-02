#include "deck.h"

void showBlackjack(const Card[], int);
bool bustBlackjack(const Card[], int);
bool bustVentti(const Card[], const Card[], int, int);
void winBlackjack(Card[], const Card[], int, int, Deck);
void winVentti(Card[], const Card[], int, int, Deck);

// Käy läpi pelin kulun vaihe vaiheelta (Ventti rakennettu Blackjackin päälle)

int main() {
    Deck blackjack;
    blackjack.randomDeck();

    int game;
    cout<<"Haluatko pelata Blackjackia vai Venttia? (1 Blackjack / 2 Ventti): ";
    while (cin>>game) {
        switch (game) {
            case 1:
                break;
            case 2:
                break;
            default:
                cout<<"Kayta oikeita numeroita.\nHaluatko pelata Blackjackia vai Venttia? (1 Blackjack / 2 Ventti): ";
                continue;
        }
        static int countp, countd;

        Card dealer[12], player[12];
        countp=0;
        countd=0;
        cout<<"[Korttien jako alkaa]"<<endl;
        while (countp<2) {
            dealer[countd++] = blackjack.dealDeck();
            player[countp++] = blackjack.dealDeck();
        }

        cout<<"[Jakaja]";
        showBlackjack(dealer, countd);
        cout<<endl;
        cout<<"[Pelaaja]";
        showBlackjack(player, countp);
        cout<<endl;

        char ch;
        cout<<"Nostatko lisaa kortteja? (K nostaa / E lopettaa): ";

        while (cin>>ch) {
            if (!isalpha(ch)) {
                cout<<"Kayta kirjaimia.\nNostatko lisaa kortteja? (K nostaa / E lopettaa): ";
                continue;
            }
            switch (ch) {
                case 'K':
                    player[countp++] = blackjack.dealDeck();
                    cout<<"[Jakaja]";
                    showBlackjack(dealer, countd);
                    cout<<endl;
                    cout<<"[Pelaaja]";
                    showBlackjack(player, countp);
                    cout<<endl;

                    if (game==1 && bustBlackjack(player, countp)) break;
                    if (game==2 && bustVentti(dealer, player, countd, countp)) break;

                    cout<<"Nostatko lisaa kortteja? (K nostaa / E lopettaa): ";
                    continue;

                case 'E':
                    if (game==1) {
                        winBlackjack(dealer, player, countd, countp, blackjack); break;
                    } else {
                        winVentti(dealer, player, countd, countp, blackjack); break;
                    }
                default:
                    cout<<"Kayta oikeita kirjaimia.\nNostatko lisaa kortteja? (K nostaa / E lopettaa): ";
                    continue;
                }
            cout<<"Pelataanko uudestaan? (K pelaa / E lopettaa): ";
            if (cin>>ch&&ch=='K'){
                countp=0;
                countd=0;
                cout<<"[Korttien jako alkaa]"<<endl;
                while (countp<2) {
                    dealer[countd++] = blackjack.dealDeck();
                    player[countp++] = blackjack.dealDeck();
                }

                cout<<"[Jakaja]";
                showBlackjack(dealer, countd);
                cout<<endl;
                cout<<"[Pelaaja]";
                showBlackjack(player, countp);
                cout<<endl;

                cout<<"Nostatko lisaa kortteja? (K nostaa / E lopettaa): ";
                continue;
            } else if (ch=='E') break;
        }
        system("pause");
        return 0;
    }
}

// Näyttää käden molemmissa peleissä

void showBlackjack(const Card c[], int n) {
    for (int i=0;i<n;i++) {
        cout<<c[i].mark<<c[i].point<<'\0';
    }
}

// Tarkistaa räjähtikö pelaaja Blackjackissä

bool bustBlackjack(const Card c[], int n) {
    int count_c=0;
    for (int i=0;i<n;i++) {
        if (c[i].point=="A") {
            count_c+=1;
        } else if (c[i].point=="2") {
            count_c+=2;
        } else if (c[i].point=="3") {
            count_c+=3;
        } else if (c[i].point=="4") {
            count_c+=4;
        } else if (c[i].point=="5") {
            count_c+=5;
        } else if (c[i].point=="6") {
            count_c+=6;
        } else if (c[i].point=="7") {
            count_c+=7;
        } else if (c[i].point=="8") {
            count_c+=8;
        } else if (c[i].point=="9") {
            count_c+=9;
        } else if (c[i].point=="10" || c[i].point=="J" || c[i].point=="Q" || c[i].point=="K") {
            count_c+=10;
        }
    }
    if (count_c>21) {
        cout<<"[Pelaaja]"<<count_c<<" pistetta.\n"<<"Pelaaja rajahti. Jakaja voitti.\n";
        return true;
    }
    return false;
}

// Tarkistaa räjähtikö pelaaja tai jakaja Ventissä

bool bustVentti(const Card d[], const Card p[], int nd, int np) {
    int count_p=0;
    int count_d=0;
    for (int i=0;i<np;i++) {
        if (p[i].point=="A") {
            count_p+=1;
        } else if (p[i].point=="2") {
            count_p+=2;
        } else if (p[i].point=="3") {
            count_p+=3;
        } else if (p[i].point=="4") {
            count_p+=4;
        } else if (p[i].point=="5") {
            count_p+=5;
        } else if (p[i].point=="6") {
            count_p+=6;
        } else if (p[i].point=="7") {
            count_p+=7;
        } else if (p[i].point=="8") {
            count_p+=8;
        } else if (p[i].point=="9") {
            count_p+=9;
        } else if (p[i].point=="10") {
            count_p+=10;
        } else if (p[i].point=="J") {
            count_p+=11;
        } else if (p[i].point=="Q") {
            count_p+=12;
        } else if (p[i].point=="K") {
            count_p+=13;
        }
    }
    for (int i=0;i<nd;i++) {
        if (d[i].point=="A") {
            count_d+=1;
        } else if (d[i].point=="2") {
            count_d+=2;
        } else if (d[i].point=="3") {
            count_d+=3;
        } else if (d[i].point=="4") {
            count_d+=4;
        } else if (d[i].point=="5") {
            count_d+=5;
        } else if (d[i].point=="6") {
            count_d+=6;
        } else if (d[i].point=="7") {
            count_d+=7;
        } else if (d[i].point=="8") {
            count_d+=8;
        } else if (d[i].point=="9") {
            count_d+=9;
        } else if (d[i].point=="10") {
            count_d+=10;
        } else if (d[i].point=="J") {
            count_d+=11;
        } else if (d[i].point=="Q") {
            count_d+=12;
        } else if (d[i].point=="K") {
            count_d+=13;
        }
    }
    if (count_p>21) {
        cout<<"[Pelaaja]"<<count_p<<" pistetta.\n"<<"Pelaaja rajahti. Jakaja voitti.\n";
        return true;
    } else if (count_d>21) {
        cout<<"[Jakaja]"<<count_d<<" pistetta.\n"<<"Jakaja rajahti. Pelaaja voitti.\n";
        return true;
    }
    return false;
}

/* Tarkistaa pelaajan ja jakajan pisteet ja tarvitsseeko jakajan nostaa lisää kortteja.
 * Jakajan korttien noston jälkeen tarkistaa kumpi voitti pelin Blackjackissä */

void winBlackjack(Card d[12], const Card p[], int nd, int np, Deck blackjack) {
    int count_p1=0;
    int count_p2=0;
    int count_d1=0;
    int count_d2=0;
    for (int i=0;i<np;i++) {
        if (p[i].point=="A") {
            count_p1+=1; count_p2+=11;
        } else if (p[i].point=="2") {
            count_p1+=2; count_p2+=2;
        } else if (p[i].point=="3") {
            count_p1+=3; count_p2+=3;
        } else if (p[i].point=="4") {
            count_p1+=4; count_p2+=4;
        } else if (p[i].point=="5") {
            count_p1+=5; count_p2+=5;
        } else if (p[i].point=="6") {
            count_p1+=6; count_p2+=6;
        } else if (p[i].point=="7") {
            count_p1+=7; count_p2+=7;
        } else if (p[i].point=="8") {
            count_p1+=8; count_p2+=8;
        } else if (p[i].point=="9") {
            count_p1+=9; count_p2+=9;
        } else if (p[i].point=="10" || p[i].point=="J" || p[i].point=="Q" || p[i].point=="K") {
            count_p1+=10; count_p2+=10;
        }
    }
    if (count_p1<count_p2 && count_p2<=21) count_p1 = count_p2;
    for (int i=0;i<nd;i++) {
        if (d[i].point=="A") {
            count_d1+=1; count_d2+=11;
        } else if (d[i].point=="2") {
            count_d1+=2; count_d2+=2;
        } else if (d[i].point=="3") {
            count_d1+=3; count_d2+=3;
        } else if (d[i].point=="4") {
            count_d1+=4; count_d2+=4;
        } else if (d[i].point=="5") {
            count_d1+=5; count_d2+=5;
        } else if (d[i].point=="6") {
            count_d1+=6; count_d2+=6;
        } else if (d[i].point=="7") {
            count_d1+=7; count_d2+=7;
        } else if (d[i].point=="8") {
            count_d1+=8; count_d2+=8;
        } else if (d[i].point=="9") {
            count_d1+=9; count_d2+=9;
        } else if (d[i].point=="10" || d[i].point=="J" || d[i].point=="Q" || d[i].point=="K") {
            count_d1+=10; count_d2+=10;
        }
        if (i==nd-1 && count_p1<=21 && count_d2<count_p1) {
            d[nd++] = blackjack.dealDeck();
            nd++;
            cout<<"[Jakaja]";
            showBlackjack(d, nd);
            cout<<endl;
        } else if (i==nd-1 && count_d2>21 && count_d1<count_p1) {
            d[nd++] = blackjack.dealDeck();
            nd++;
            cout<<"[Jakaja]";
            showBlackjack(d, nd);
            cout<<endl;
        }
    }
    if (count_d1<count_d2&&count_d2<=21) count_d1 = count_d2;
    if (count_d1>21){
        cout<<"[Jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Jakaja rajahti. Pelaaja voitti.\n";
    } else if (count_d1>=count_p1) {
        cout<<"[Jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Jakaja voitti.\n";
    } else if (count_d1<count_p1) {
        cout<<"[jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Pelaaja voitti.\n";
    }
}

/* Tarkistaa pelaajan ja jakajan pisteet ja tarvitsseeko jakajan nostaa lisää kortteja.
 * Jakajan korttien noston jälkeen tarkistaa kumpi voitti pelin Ventissä */

void winVentti(Card d[12], const Card p[], int nd, int np, Deck blackjack) {
    int count_p1=0;
    int count_p2=0;
    int count_d1=0;
    int count_d2=0;
    for (int i=0;i<np;i++) {
        if (p[i].point=="A") {
            count_p1+=1; count_p2+=14;
        } else if (p[i].point=="2") {
            count_p1+=2; count_p2+=2;
        } else if (p[i].point=="3") {
            count_p1+=3; count_p2+=3;
        } else if (p[i].point=="4") {
            count_p1+=4; count_p2+=4;
        } else if (p[i].point=="5") {
            count_p1+=5; count_p2+=5;
        } else if (p[i].point=="6") {
            count_p1+=6; count_p2+=6;
        } else if (p[i].point=="7") {
            count_p1+=7; count_p2+=7;
        } else if (p[i].point=="8") {
            count_p1+=8; count_p2+=8;
        } else if (p[i].point=="9") {
            count_p1+=9; count_p2+=9;
        } else if (p[i].point=="10") {
            count_p1+=10; count_p2+=10;
        } else if (p[i].point=="J") {
            count_p1+=11; count_p2+=11;
        } else if (p[i].point=="Q") {
            count_p1+=12; count_p2+=12;
        } else if (p[i].point=="K") {
            count_p1+=13; count_p2+=13;
        }
    }
    if (count_p1<count_p2 && count_p2<=21) count_p1 = count_p2;
    for (int i=0;i<nd;i++) {
        if (d[i].point=="A") {
            count_d1+=1; count_d2+=14;
        } else if (d[i].point=="2") {
            count_d1+=2; count_d2+=2;
        } else if (d[i].point=="3") {
            count_d1+=3; count_d2+=3;
        } else if (d[i].point=="4") {
            count_d1+=4; count_d2+=4;
        } else if (d[i].point=="5") {
            count_d1+=5; count_d2+=5;
        } else if (d[i].point=="6") {
            count_d1+=6; count_d2+=6;
        } else if (d[i].point=="7") {
            count_d1+=7; count_d2+=7;
        } else if (d[i].point=="8") {
            count_d1+=8; count_d2+=8;
        } else if (d[i].point=="9") {
            count_d1+=9; count_d2+=9;
        } else if (d[i].point=="10") {
            count_d1+=10; count_d2+=10;
        } else if (d[i].point=="J") {
            count_d1+=11; count_d2+=11;
        } else if (d[i].point=="Q") {
            count_d1+=12; count_d2+=12;
        } else if (d[i].point=="K") {
            count_d1+=13; count_d2+=13;
        }
        if (i==nd-1 && count_p1<=21 && count_d2<count_p1) {
            d[nd++] = blackjack.dealDeck();
            nd++;
            cout<<"[Jakaja]";
            showBlackjack(d, nd);
            cout<<endl;
        } else if (i==nd-1 && count_d2>21 && count_d1<count_p1) {
            d[nd++] = blackjack.dealDeck();
            nd++;
            cout<<"[Jakaja]";
            showBlackjack(d, nd);
            cout<<endl;
        }
    }
    if (count_d1<count_d2&&count_d2<=21) count_d1 = count_d2;
    if (count_p1>21){
        cout<<"[Jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Pelaaja rajahti. Jakaja voitti.\n";
    } else if (count_d1>21) {
        cout<<"[Jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Jakaja rajahti. Pelaaja voitti.\n";
    }else if (count_d1>=count_p1) {
        cout<<"[Jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Jakaja voitti.\n";
    } else if (count_d1<count_p1) {
        cout<<"[jakaja]"<<count_d1<<" Pistetta,\n"<<"[Pelaaja]"<<count_p1<<" Pistetta.\n"<<"Pelaaja voitti.\n";
    }
}
