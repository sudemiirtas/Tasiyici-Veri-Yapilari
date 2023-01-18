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
//******* PRINT_LAST_N_ELEMENTS
//bu kod, bir double veri tipi tasiyicisi olan bir vektorun son n elemanini yazdirir.
//Eger vektorun boyutu n'den kucukse, tum vektor elemanlari yazdirilir ve vektor temizlenir. 
//Eger vektorun boyutu n'den buyukse, son n eleman yazdirilir ve son n eleman vektorden silinir.
void print_last_n_elements_double(std::vector<double>& vec, int n) {
    if (vec.size() < n) {
        for (auto& i : vec) {
            std::cout << i << std::endl;
        }
        vec.clear();
    }
    else {
        for (int i = vec.size() - n; i < vec.size(); i++) {
            std::cout << vec[i] << std::endl;
        }
        vec.erase(vec.end() - n, vec.end());
    }
}
void print_last_n_elements_int(std::vector<int>& vec, int n) {
    if (vec.size() < n) {
        for (int i : vec) {
            std::cout << i << " ";
        }
        vec.clear();
    }
    else {
        for (int i = vec.size() - n; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        vec.erase(vec.end() - n, vec.end());
    }
    std::cout << std::endl;
}
void print_last_n_elements_longint(std::vector<long int>& vec, int n) {
    int size = vec.size();
    if (n > size) {
        for (int i = 0; i < size; i++) {
            std::cout << vec[i] << std::endl;
        }
        vec.clear();
    }
    else {
        for (int i = size - n; i < size; i++) {
            std::cout << vec[i] << std::endl;
        }
        vec.erase(vec.begin() + size - n, vec.end());
    }
}
void print_last_n_elements_string(std::vector<std::string>& vec, int n) {
    if (vec.size() < n) {
        for (auto s : vec) {
            std::cout << s << std::endl;
        }
        vec.clear();
    }
    else {
        for (int i = vec.size() - n; i < vec.size(); i++) {
            std::cout << vec[i] << std::endl;
        }
        vec.erase(vec.end() - n, vec.end());
    }
}

//SELİN SELİME CAN 





//İREM AKYALCIN

//******* ADD_ORDERED
//Bu kod, verilen bir degerin(value) vektorun(vec) icinde sirali olarak yerlesecegi yerde eklemesini saglar.
//Bu islem icin lower_bound fonksiyonu kullanilir.lower_bound, verilen degerin vektorde gecerli olmasi durumunda, 
//o degerin ilk olarak yer alacagi indisi dondurur.Bu indis, verilen degerin sirali olarak yerlesecegi yerdir ve 
//insert fonksiyonu ile bu indise deger eklenir.Bu islem ile vektor sirali bir sekilde korunur.
template<typename T>
void add_ordered(std::vector<T>& vec, T value) {
    auto it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

//******* REMOVE_LAST_N_ITEMS
//Bu kod, verilen bir sayida son elemani verilen bir vektorden kaldirmak icin kullanilir.Ornegin, 
//remove_last_n_items_double(myVec, 2) cagrisi, myVec vektorunun son iki elemanini siler.Bu, 
//vec.erase(vec.end() - n, vec.end()) satiri tarafindan gerceklestirilir, bu satir, vec vektorunun 
//son n elemanini vec.end() iteraturune kadar siler.
void remove_last_n_items_double(std::vector<double>& vec, int n) {
    vec.erase(vec.end() - n, vec.end());
}
void remove_last_n_items_int(std::vector<int>& vec, int n) {
    vec.erase(vec.end() - n, vec.end());
}
void remove_last_n_items_longint(std::vector<long int>& vec, int n) {
    vec.erase(vec.end() - n, vec.end());
}
void remove_last_n_items_string(std::vector<std::string>& vec, int n) {
    vec.erase(vec.end() - n, vec.end());
}
