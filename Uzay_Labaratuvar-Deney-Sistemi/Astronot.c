#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define PLANET_COUNT 8

/* --- Yardımcı Fonksiyonlar --- */
void menu_goster();
void tampon_temizle();
double guvenli_double_al(char *mesaj);
int guvenli_int_al(char *mesaj);
void bilgi_mesaji(double orijinal, double mutlak);

/* --- Deney Fonksiyonları --- */
void serbest_dusme(double *g_ptr, char (*names)[10], char *scientist);
void yukari_atis(double *g_ptr, char (*names)[10], char *scientist);
void agirlik_deneyi(double *g_ptr, char (*names)[10], char *scientist);
void potansiyel_enerji(double *g_ptr, char (*names)[10], char *scientist);
void hidrostatik_basinc(double *g_ptr, char (*names)[10], char *scientist);
void arsimet_kaldirma(double *g_ptr, char (*names)[10], char *scientist);
void basit_sarkac(double *g_ptr, char (*names)[10], char *scientist);
void ip_gerilmesi(double *g_ptr, char (*names)[10], char *scientist);
void asansor_deneyi(double *g_ptr, char (*names)[10], char *scientist);

int main() {
    char bilim_insani[50];
    int secim;

    double gravities[PLANET_COUNT] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};
    char planet_names[PLANET_COUNT][10] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

    printf("************************************************\n");
    printf("* UZAY SIMULASYON MERKEZI             *\n");
    printf("************************************************\n\n");

    printf("Lutfen Bilim Insaninin Adini Giriniz: ");
    scanf(" %[^\n]s", bilim_insani);
    tampon_temizle();

    while(1) {
        menu_goster();
        secim = guvenli_int_al("\nLutfen bir secim yapiniz (-1 cikis): ");

        if (secim == -1) {
            printf("\nGule gule Sayin %s. Sistem kapatiliyor.\n", bilim_insani);
            break;
        }

        switch(secim) {
            case 1: serbest_dusme(gravities, planet_names, bilim_insani); break;
            case 2: yukari_atis(gravities, planet_names, bilim_insani); break;
            case 3: agirlik_deneyi(gravities, planet_names, bilim_insani); break;
            case 4: potansiyel_enerji(gravities, planet_names, bilim_insani); break;
            case 5: hidrostatik_basinc(gravities, planet_names, bilim_insani); break;
            case 6: arsimet_kaldirma(gravities, planet_names, bilim_insani); break;
            case 7: basit_sarkac(gravities, planet_names, bilim_insani); break;
            case 8: ip_gerilmesi(gravities, planet_names, bilim_insani); break;
            case 9: asansor_deneyi(gravities, planet_names, bilim_insani); break;
            default: printf("\n[!] Gecersiz secim! Lutfen listedeki rakamlardan birini girin.\n");
        }
    }
    return 0;
}

/* --- Fonksiyon Tanımları --- */

void tampon_temizle() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double guvenli_double_al(char *mesaj) {
    double deger;
    printf("%s", mesaj);
    while (scanf("%lf", &deger) != 1) {
        tampon_temizle();
        printf("[!] HATA: Gecersiz giris! Lutfen sayisal bir deger giriniz: ");
    }
    tampon_temizle();
    return deger;
}

int guvenli_int_al(char *mesaj) {
    int deger;
    printf("%s", mesaj);
    while (scanf("%d", &deger) != 1) {
        tampon_temizle();
        printf("[!] HATA: Gecersiz giris! Lutfen tam sayi giriniz: ");
    }
    tampon_temizle();
    return deger;
}

void bilgi_mesaji(double orijinal, double mutlak) {
    printf(">> Bilgilendirme: Girilen (%.2f) degeri negatif oldugu icin mutlak degeri olan (%.2f) baz alinmistir.\n", orijinal, mutlak);
}

void menu_goster() {
    printf("\n------------------------------------------------\n");
    printf("DENEY PROTOKOLLERI:\n");
    printf("1. Serbest Dusme  2. Yukari Atis   3. Agirlik\n");
    printf("4. Potansiyel E.  5. Hidrostatik   6. Arsimet\n");
    printf("7. Basit Sarkac   8. Ip Gerilmesi  9. Asansor\n");
    printf("------------------------------------------------\n");
}

/* 2.1 Serbest Dusme: h = 1/2 * g * t^2 */
void serbest_dusme(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: SERBEST DUSME DENEYI <<<\n");
    double t = guvenli_double_al("Sureyi (t) saniye (s) cinsinden giriniz: ");
    double t_abs = (t < 0) ? -t : t;
    (t < 0) ? bilgi_mesaji(t, t_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double h = 0.5 * *(g_ptr + i) * t_abs * t_abs;
        printf("%-10s -> h = %.2f m\n", *(names + i), h);
    }
}

/* 2.2 Yukari Atis: h_max = (v0^2) / (2g) */
void yukari_atis(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: YUKARI ATIS DENEYI <<<\n");
    double v0 = guvenli_double_al("Ilk hizi (v0) m/s cinsinden giriniz: ");
    double v0_abs = (v0 < 0) ? -v0 : v0;
    (v0 < 0) ? bilgi_mesaji(v0, v0_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double h_max = (v0_abs * v0_abs) / (2 * *(g_ptr + i));
        printf("%-10s -> h_max = %.2f m\n", *(names + i), h_max);
    }
}

/* 2.3 Agirlik: G = m * g */
void agirlik_deneyi(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: AGIRLIK DENEYI <<<\n");
    double m = guvenli_double_al("Kutleyi (m) kg cinsinden giriniz: ");
    double m_abs = (m < 0) ? -m : m;
    (m < 0) ? bilgi_mesaji(m, m_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double G = m_abs * *(g_ptr + i);
        printf("%-10s -> G = %.2f N\n", *(names + i), G);
    }
}

/* 2.4 Potansiyel Enerji: Ep = m * g * h */
void potansiyel_enerji(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: KUTLECEKIMSEL POTANSIYEL ENERJI DENEYI <<<\n");
    double m = guvenli_double_al("Kutleyi (m) kg cinsinden giriniz: ");
    double m_abs = (m < 0) ? -m : m;
    (m < 0) ? bilgi_mesaji(m, m_abs) : 0;

    double h = guvenli_double_al("Yuksekligi (h) metre (m) cinsinden giriniz: ");
    double h_abs = (h < 0) ? -h : h;
    (h < 0) ? bilgi_mesaji(h, h_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double Ep = m_abs * *(g_ptr + i) * h_abs;
        printf("%-10s -> Ep = %.2f J\n", *(names + i), Ep);
    }
}

/* 2.5 Hidrostatik Basinc: P = rho * g * h */
void hidrostatik_basinc(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: HIDROSTATIK BASINC DENEYI <<<\n");
    double rho = guvenli_double_al("Sivi yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
    double rho_abs = (rho < 0) ? -rho : rho;
    (rho < 0) ? bilgi_mesaji(rho, rho_abs) : 0;

    double h = guvenli_double_al("Derinligi (h) metre (m) cinsinden giriniz: ");
    double h_abs = (h < 0) ? -h : h;
    (h < 0) ? bilgi_mesaji(h, h_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double P = rho_abs * *(g_ptr + i) * h_abs;
        printf("%-10s -> P = %.2f Pa\n", *(names + i), P);
    }
}

/* 2.6 Arsimet Kaldirma: Fk = rho * g * V */
void arsimet_kaldirma(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: ARSIMET KALDIRMA KUVVETI DENEYI <<<\n");
    double rho = guvenli_double_al("Sivi yogunlugunu (rho) kg/m^3 cinsinden giriniz: ");
    double rho_abs = (rho < 0) ? -rho : rho;
    (rho < 0) ? bilgi_mesaji(rho, rho_abs) : 0;

    double V = guvenli_double_al("Batan hacmi (V) m^3 cinsinden giriniz: ");
    double V_abs = (V < 0) ? -V : V;
    (V < 0) ? bilgi_mesaji(V, V_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double Fk = rho_abs * *(g_ptr + i) * V_abs;
        printf("%-10s -> Fk = %.2f N\n", *(names + i), Fk);
    }
}

/* 2.7 Basit Sarkac: T = 2 * PI * sqrt(L / g) */
void basit_sarkac(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: BASIT SARKAC PERIYODU DENEYI <<<\n");
    double L = guvenli_double_al("Sarkac uzunlugunu (L) metre (m) cinsinden giriniz: ");
    double L_abs = (L < 0) ? -L : L;
    (L < 0) ? bilgi_mesaji(L, L_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double T = 2 * PI * sqrt(L_abs / *(g_ptr + i));
        printf("%-10s -> T = %.2f s\n", *(names + i), T);
    }
}

/* 2.8 Sabit Ip Gerilmesi: T = m * g */
void ip_gerilmesi(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: SABIT IP GERILMESI DENEYI <<<\n");
    double m = guvenli_double_al("Kutleyi (m) kg cinsinden giriniz: ");
    double m_abs = (m < 0) ? -m : m;
    (m < 0) ? bilgi_mesaji(m, m_abs) : 0;

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double T_ten = m_abs * *(g_ptr + i);
        printf("%-10s -> T = %.2f N\n", *(names + i), T_ten);
    }
}

/* 2.9 Asansor: N = m(g+a) veya N = m(g-a) */
void asansor_deneyi(double *g_ptr, char (*names)[10], char *scientist) {
    printf("\n>>> SECILEN DENEY: ASANSOR DENEYI <<<\n");
    double m = guvenli_double_al("Kutleyi (m) kg cinsinden giriniz: ");
    double m_abs = (m < 0) ? -m : m;
    (m < 0) ? bilgi_mesaji(m, m_abs) : 0;

    double a = guvenli_double_al("Asansor ivmesini (a) m/s^2 cinsinden giriniz: ");
    double a_abs = (a < 0) ? -a : a;
    (a < 0) ? bilgi_mesaji(a, a_abs) : 0;

    printf("\nHareket Yonu:\n1. Yukari Hizlanma (g+a)\n2. Asagi Hizlanma (g-a)\n");
    int yon = guvenli_int_al("Secim: ");

    printf("\n*** %s'nin bilimsel rapor sonuclari ***\n", scientist);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double N = (yon == 1) ? m_abs * (*(g_ptr + i) + a_abs) : m_abs * (*(g_ptr + i) - a_abs);
        printf("%-10s -> N = %.2f N\n", *(names + i), N);
    }
}