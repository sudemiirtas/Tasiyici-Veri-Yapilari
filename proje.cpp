#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <vector>
//SUDE DEMİRTAŞ
class GPS {
public:
    double latitude;
    double longitude;
    std::string location_name;
};
 
std::chrono::high_resolution_clock::time_point start;

void start_timer() {
    // chrono kutuphanesi kullanarak zaman olcumunu icin saatin baslatilmasini gerceklestirir
    start = std::chrono::high_resolution_clock::now();
}
void stop_timer() {
    // chrono kutuphanesi kullanarak zaman olcumunu icin tamamlandigini belirtir
    // olculen zaman nano saniye olarak ekrana yazdirir
    //std::cout << "Stop Timer" << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    //Bu satirda, std::chrono kutuphanesi kullanilarak, high_resolution_clock sinifindan bir nesne olusturulur ve stop degiskenine atanir.
    //Bu nesnenin now() fonksiyonu cagirildiginde, sistem saatinden alinan en yuksek cozunurluklu zaman bilgisi dondurur.
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   /* Bu satirda, stop degiskeni ile start degiskeni arasindaki zaman farki, std::chrono::nanoseconds turune donusturulur ve duration degiskenine atanir.
    Bu sayede, olculen zaman nanosaniye cinsinden elde edilir.*/
    std::cout << "Elapsed time: " << duration.count() << " nanoseconds" << std::endl;
    /*Bu satirda, konsola yazdirilir ve elde edilen zaman bilgisi nanosaniye cinsinden ekrana yazdirilir.*/
}

//Bu kodlar, farkli veri turleri icin(double, int, long int, string ve GPS) derin klonlarının tutulacagı vekturleri tanımlanır.
//Bu vektorler, kulanıcının "CREATE_A_DEEP_CLONE" komutunu kullanarak olusturdugu vekturlerin kopyalarını saklar.
//Bu sayede kulanici, "RESTORE_FROM_CLONE" komutunu kullanarak vektorun orijinal haline geri donebilir.
std::vector<double> deepCloneVec_double;
std::vector<int> deepCloneVec_int;
std::vector<long int> deepCloneVec_longint;
std::vector<std::string> deepCloneVec_string;
std::vector<GPS> deepCloneVec_gps;
//İCLAL CENGEL 
//******* PRINT_FIRST_N_ELEMENTS
//Bu kod, bir double tipinde vector nesnesinin ilk n elemanini yazdirmak icin kullanilir.ilk olarak, 
//eger vec nesnesinin boyutu n'den kucukse, yazdirilacak eleman sayisini vec nesnesinin boyutuna esitler. 
//Daha sonra, for dongusu kullanilarak vec nesnesinin ilk n elemani yazdirilir.
void print_first_n_elements_double(std::vector<double>& vec, int n) {
    if (vec.size() < n) {
        n = vec.size();
    }
    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << std::endl;
    }
}
void print_first_n_elements_int(std::vector<int>& vec, int n) {
    if (n > vec.size()) {
        n = vec.size();
    }
    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
void print_first_n_elements_longint(std::vector<long int>& vec, int n) {
    if (n > vec.size()) {
        n = vec.size();
    }
    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << std::endl;
    }
}
void print_first_n_elements_string(std::vector<std::string>& vec, int n) {
    if (vec.size() < n) {
        n = vec.size();
    }
    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << std::endl;
    }
}

