#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKSIMUM_NOKTA 100
#define BANDWIDTH 2.0
#define EPSILON 0.0001

struct Nokta {
    double x;
    double y;
};

// Noktalarýn öklidyen mesafesini hesaplayan fonksiyon
double euclideanMesafe(struct Nokta n1, struct Nokta n2) {
    double dx = n1.x - n2.x;
    double dy = n1.y - n2.y;
    return sqrt(dx * dx + dy * dy);
}

// Ortalama kaydýrmalý kümeleme algoritmasý
void meanShiftKumeleme(struct Nokta* noktalar, int noktaSayisi) {
    int i, j, iterasyon;
    double kaymaX, kaymaY, toplamKayma, mesafe;
    struct Nokta eskiMerkez, yeniMerkez;

    // Her bir nokta için iteratif olarak merkezi güncelleme
    for (i = 0; i < noktaSayisi; i++) {
        eskiMerkez = noktalar[i];
        iterasyon = 0;

        // Merkez güncellemesi
        do {
            kaymaX = 0.0;
            kaymaY = 0.0;
            toplamKayma = 0.0;

            // Merkezden etkilenen noktalarýn aðýrlýklý toplamýný hesaplama
            for (j = 0; j < noktaSayisi; j++) {
                mesafe = euclideanMesafe(noktalar[j], eskiMerkez);
                if (mesafe <= BANDWIDTH) {
                    kaymaX += noktalar[j].x;
                    kaymaY += noktalar[j].y;
                    toplamKayma += 1.0;
                }
            }

            // Yeni merkezi hesaplama
            yeniMerkez.x = kaymaX / toplamKayma;
            yeniMerkez.y = kaymaY / toplamKayma;

            // Merkez deðiþimini hesaplama
            toplamKayma = euclideanMesafe(eskiMerkez, yeniMerkez);
            eskiMerkez = yeniMerkez;

            iterasyon++;
        } while (toplamKayma > EPSILON && iterasyon < 100);

        // Sonuçlarý ekrana yazdýrma
        printf("Kume %d Merkezi: (%lf, %lf)\n", i + 1, eskiMerkez.x, eskiMerkez.y);
    }
}

int main() {
    struct Nokta noktalar[MAKSIMUM_NOKTA];
    int noktaSayisi, i;

    // Kullanýcýdan nokta girdisi alma
    printf("Nokta sayisini girin: ");
    scanf("%d", &noktaSayisi);

    printf("Noktalari girin:\n");
    for (i = 0; i < noktaSayisi; i++) {
        printf("Nokta %d x koordinatini girin: ", i + 1);
        scanf("%lf", &noktalar[i].x);

        printf("Nokta %d y koordinatini girin: ", i + 1);
        scanf("%lf", &noktalar[i].y);
    }

    // Ortalama kaydýrmalý kümeleme algoritmasýný çaðýrma
    meanShiftKumeleme(noktalar, noktaSayisi);

    return 0;
}

