#include <iostream> // iostream ve fstream kütüphaneleri dosya okuma/yazma iþlemleri için kullanýlýr
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// LPS dizisini hesaplayan fonksiyon
void computeLPSArray(string aranacak, vector<int>& lps) { // aranacak:aranacak kelimeleri ifade eder. lps:verilen kalýp dizgisindeki her karakter için, en uzun ön ek son ek eþleþmelerini tutan bir dizidir.
    int m = aranacak.length(); // m, txt dizgisindeki karakterleri tararken takip edilen indis deðerini tutar.
    int lenght = 0; //lenght : aranacak kelimenin uzunluðunu tutar
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (aranacak[i] == aranacak[lenght]) {
            lenght++;
            lps[i] = lenght;
            i++;
        } else {
            if (lenght != 0) {
                lenght = lps[lenght - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Metin içinde aranan kelimenin sayýsýný hesaplayan fonksiyon
int Morrisarama(string aranacak, string txt) {
    int m = aranacak.length();
    int n = txt.length();
    int count = 0;

    vector<int> lps(m);

    computeLPSArray(aranacak, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (aranacak[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && aranacak[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }

    return count;
}

int main() {
    ifstream file("C:/Users/hp omen/OneDrive - klu.edu.tr/Masaüstü/metin.txt"); // Dosya yolu verilen dosya açýlýyor.
    string line;
    int upon_count = 0;
    int sigh_count = 0;
    int Dormouse_count = 0;
    int jury_box_count = 0;
    int swim_count = 0;

    // Dosyadaki her satýr için arama yapýlýyor
    while (getline(file, line)) {
        upon_count += Morrisarama("upon", line);
        sigh_count += Morrisarama("sigh", line);
        Dormouse_count += Morrisarama("Dormouse", line);
        jury_box_count += Morrisarama("jury-box", line);
        swim_count += Morrisarama("swim", line);
    }

    cout << "'upon' kelimesi " << upon_count << " kez tekrar ediliyor." << endl;
    cout << "'sigh' kelimesi " << sigh_count << " kez tekrar ediliyor." << endl;
    cout << "'Dormouse' kelimesi " << Dormouse_count << " kez tekrar ediliyor." << endl;
    cout << "'jury-box' kelimesi " << jury_box_count << " kez tekrar ediliyor." << endl;
    cout << "'swim' kelimesi " << swim_count << " kez tekrar ediliyor." << endl;

    return 0;
}

