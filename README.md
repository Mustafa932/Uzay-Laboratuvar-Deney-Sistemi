# Uzay-Laboratuvar-Deney-Sistemi

Bu projeyi, klasik fizik kurallarının Güneş Sistemi'ndeki farklı kütleçekim ortamlarında nasıl sonuçlar verdiğini gözlemlemek için geliştirdim. Temel amacım; Dünya'da alışık olduğumuz fiziksel olayların (serbest düşme, sarkaç periyodu, basınç vb.) Merkür'den Neptün'e kadar diğer gezegenlerde nasıl değiştiğini birim bazında analiz eden bir simülasyon motoru oluşturmaktı.

## Projenin Amacı ve Mantığı
Projenin çıkış noktası, teorik fizik formüllerini dinamik bir yazılım haline getirmekti. Program, kullanıcıyı bir "Bilim İnsanı" olarak sisteme dahil ediyor ve seçilen 9 farklı deney protokolü üzerinden tüm gezegenler için eş zamanlı hesaplama yapıyor. Bu sayede yerçekimi ivmesinin ($g$) ağırlık, enerji ve zaman üzerindeki dramatik etkilerini somut verilerle görebiliyoruz.

## Teknik Detaylar ve Kodun Yapısı
Kodun mimarisini kurgularken sadece sonuca odaklanmadım, aynı zamanda C dilinin zorlayıcı teknik kurallarını (özellikle pointer yönetimi) projeye tam olarak yedirdim:

### 1. Pointer (İşaretçi) Aritmetiği
Proje yönergesine uygun olarak, kodun hiçbir yerinde dizilere erişmek için klasik indisleme (`dizi[i]`) yöntemini kullanmadım. Bunun yerine tamamen **pointer aritmetiği** (`*(ptr + i)`) kullandım. Gezegen ivmelerine ve isimlerine bu yöntemle erişmek, bellek adresleri üzerindeki hakimiyetimi geliştirmemi sağladı.



### 2. Modüler Fonksiyon Yapısı
Her deney (Serbest Düşme, Yukarı Atış, Asansör vb.) kendi fonksiyonu içerisinde çalışıyor. Fonksiyonlara parametre aktarırken bellek adreslerini kullandım (pass-by-reference). Bu sayede `main` fonksiyonu oldukça sade kalarak sadece menü yönetimini ve ana döngüyü kontrol ediyor.

### 3. Hata Yönetimi ve Güvenli Giriş
C dilinde `scanf` kullanırken sayı yerine harf girildiğinde programın sonsuz döngüye girmesi en büyük sorundur. Bu projede, her veri girişinden sonra çalışan bir **tampon temizleme (buffer clearing)** mekanizması kurdum. Kullanıcı geçersiz bir karakter girdiğinde program çökmek yerine kullanıcıyı uyarıp yeni bir giriş talep ediyor.

### 4. Ternary Operatör ve Mutlak Değer
Fiziksel kütle, süre veya uzunluk gibi değerlerin negatif olması simülasyonu bozar. Kodda bu değerleri kontrol ederken `if` blokları yerine daha kompakt olan **ternary operatörleri** tercih ettim:
`deger = (deger < 0) ? -deger : deger;`
Bu sayede girilen hatalı verileri anında mutlak değerine çevirerek fiziksel gerçekliği korudum.

## Kullanılan Fiziksel Modeller
Simülasyon içerisinde aşağıdaki formüller, 8 farklı gezegenin yerçekimi ivmesi parametre alınarak çözülmektedir:

* **Atış Mekaniği:** Serbest düşme $$h = \frac{1}{2}gt^2$$ve yukarı atış$$h_{max} = \frac{v_0^2}{2g}$$
* **Enerji ve Statik:** Potansiyel enerji $E_p = mgh$ ve ağırlık $G = mg$
* **Akışkanlar:** Hidrostatik basınç $P = \rho gh$ ve Arşimet kaldırma kuvveti $F_k = \rho gV$
* **Dinamik:** Sarkaç periyodu $$T = 2\pi\sqrt{\frac{L}{g}}$$ve asansör sistemleri için etkin ağırlık$$N = m(g \pm a)$$

---
Bu proje, hem fiziksel yasaların görselleştirilmesi hem de C dilinde bellek yönetimi ve hata yönetimi konularındaki yetkinliğimi sergilemek adına önemli bir çalışmadır.
