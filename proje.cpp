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
    double latitude; //enlem 
    double longitude; //boylam
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

//******* ADD_BACK
//Bu fonksiyon, verilen 'vec' adki double turunde bir vektor ve 'value' adki degiskenin degerini alir. 
//'vec.push_back(value)' komutu ile 'vec' vektorunun sonuna 'value' degerini ekler.
//Bu sayede verilen 'value' degerinin vektorun sonuna eklenmis olmasi saglanmis olur.
void add_back_double(std::vector<double>& vec, double value) {
    vec.push_back(value);
}
void add_back_int(std::vector<int>& vec, int value) {
    vec.push_back(value);
}
void add_back_longint(std::vector<long int>& vec, long int value) {
    vec.push_back(value);
}
void add_back_string(std::vector<std::string>& vec, std::string value) {
    vec.push_back(value);
}
//******* ADD_FRONT
//"add_front_double" fonksiyonu, verilen double turunde bir degerin tasiyicinin veri yapisinin basina eklenmesini saglar.
//Bu islem icin "insert" fonksiyonu kullanilmistidir. "vec.begin()" ile tasiyicinin veri yapisinin bagi belirlenir ve "value" degeri bu konuma eklenir.
//Bu sekilde tasiyicinin veri yapisinin basina yeni bir eleman eklenmis olur.
void add_front_double(std::vector<double>& vec, double value) {
    vec.insert(vec.begin(), value);
}
void add_front_int(std::vector<int>& vec, int value) {
    vec.insert(vec.begin(), value);
}
void add_front_string(std::vector<std::string>& vec, std::string value) {
    vec.insert(vec.begin(), value);
}
void add_front_longint(std::vector<long int>& vec, long int value) {
    vec.insert(vec.begin(), value);
}
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

//******* IF_EXISTS_REMOVE_FIRST
//Bu kod, verilen bir degerin tasiyici veri yapisinin ilk ocurrence'ini arar ve eger bulursa, o elemani tasiyici veri yapisindan kaldirir. 
//Bu islem std::find fonksiyonu kullanilarak gerceklestirilir. Eger aranan deger tasiyici veri yapisinda bulunursa, 
//std::find fonksiyonu o degerin pozisyonunu dondurur ve vec.erase(it) komutu ile o eleman tasiyici veri yapisindan silinir. 
//Eger aranan deger tasiyici veri yapisinda bulunmazsa, std::find fonksiyonu vec.end() dondurur ve hicbir islem yapilmaz.
void if_exists_remove_first_double(std::vector<double>& vec, double value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        vec.erase(it);
    }
}
void if_exists_remove_first_int(std::vector<int>& vec, int value)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it == value)
        {
            vec.erase(it);
            break;
        }
    }
}
void if_exists_remove_first_longint(std::vector<long int>& vec, long int value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        vec.erase(it);
    }
}
void if_exists_remove_first_string(std::vector<std::string>& vec, std::string value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        vec.erase(it);
    }
}

//******* IF_EXISTS_REMOVE_LAST
//Bu kod, verilen degerin tasiyici veri yapisinda(vector) son ocurrensini arar ve eger bulursa ocurrensi siler.Bu islem, 
//vector icinde arama yaparken tersten dolasarak gerceklestirilir.Bu sayede vector icinde son ocurrens bulunur ve silinir.
void if_exists_remove_last_double(std::vector<double>& vec, double value) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] == value) {
            vec.erase(vec.begin() + i);
            break;
        }
    }
}
void if_exists_remove_last_int(std::vector<int>& vec, int value) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] == value) {
            vec.erase(vec.begin() + i);
            break;
        }
    }
}
void if_exists_remove_last_longint(std::vector<long int>& vec, long int value) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] == value) {
            vec.erase(vec.begin() + i);
            break;
        }
    }
}
void if_exists_remove_last_string(std::vector<std::string>& vec, std::string value) {
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] == value) {
            vec.erase(vec.begin() + i);
            break;
        }
    }
}

//******* CREATE_A_DEEP_CLONE
//Bu kod, bir vector verisini klonlamak icin bir fonksiyon tanimlar.
//Bu fonksiyon, bir referans olarak verilen vector'un kopyasini dondurur. 
//Bu, "deep copy" olarak adlandirilan, orjinal ve klon arasinda herhangi bir baglanti olmamasi anlamina gelir. 
//Bu, orjinal verinin degistirilmesinden etkilenmemesini saglar. Bu fonksiyon "template" olarak yazilmistir, bu yuzden herhangi bir veri tipi ile kullanilabilir.
template <typename T>
std::vector<T> create_a_deep_clone(const std::vector<T>& vec) {
    return vec;
}


//SELİME SELİN CAN 
//******* SORT_ASCENDING_BY_USING_SELECTION_SORT 
//Bu kod, verilen bir double turunde vector icerisindeki elemanlari secim siralamasi yontemiyle kucukten buyuge siralar.
//Oncelikle, dizinin boyutunun biraz kucugunden baslayarak dongu baslatilir.Bu dongu, dizinin ilk elemanindan baslayarak
//dizinin sonuna kadar gecer ve her bir eleman icin en kucuk elemanin indeksini bulur.Dongu sonunda, en kucuk eleman ile
//dizinin ilk elemani yer degistirir.Bu islem dizinin boyutunun biraz kucuge kadar tekrar eder ve dizinin tum elemanlari siralanir.
void sort_ascending_using_selection_sort_double(std::vector<double>& vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[minIndex])
                minIndex = j;
        }
        std::swap(vec[minIndex], vec[i]);
    }
}
void sort_ascending_using_selection_sort_int(std::vector<int>& vec) {
    int minIndex, temp;
    for (int i = 0; i < vec.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        temp = vec[minIndex];
        vec[minIndex] = vec[i];
        vec[i] = temp;
    }
}
void sort_ascending_using_selection_sort_longint(std::vector<long int>& vec) {
    int minIndex, temp;
    for (int i = 0; i < vec.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        temp = vec[minIndex];
        vec[minIndex] = vec[i];
        vec[i] = temp;
    }
}
void sort_ascending_using_selection_sort_string(std::vector<std::string>& vec) {
    int minIndex;
    std::string temp;
    for (int i = 0; i < vec.size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j].compare(vec[minIndex]) < 0) {
                minIndex = j;
            }
        }
        temp = vec[minIndex];
        vec[minIndex] = vec[i];
        vec[i] = temp;
    }
}
//******* RESTORE_FROM_CLONE
//Bu kod, deepCloneVec_double adli vektorden vec adli vektorun icerigini geri yukler.
//Bu, vec vektorunun iceriginin deepCloneVec_double vektorune olan kopyasini almasi anlamina gelir.
//Bu fonksiyon, vec vektorunun icerigini degistirmek icin kullanilabilir ve eski icerigini geri yuklemek icin kullanilabilir.
void restore_from_clone_double(std::vector<double>& vec)
{
    vec = deepCloneVec_double;
}
void restore_from_clone_int(std::vector<int>& vec)
{
    vec = deepCloneVec_int;
}
void restore_from_clone_longint(std::vector<long int>& vec)
{
    vec = deepCloneVec_longint;
}
void restore_from_clone_string(std::vector<std::string>& vec)
{
    vec = deepCloneVec_string;
}

//******* SORT_DESCENDING_BY_USING_QUICK_SORT
//Bu kod, verilen double tipindeki vektorun icerigini hizli siralama algoritmasi kullanarak azalan sirada siralar.
//std::sort() fonksiyonu kullanilmistir ve bu fonksiyon, verilen iterator araligindaki elemanlari siralamak icin kullanilir.
//std::greater<double>() ise siralama islemi sirasinda kullanilacak olan kiyaslama fonksiyonudur ve
//bu fonksiyon double veri turunde kiyaslama yaparken buyukten kucuge dogru siralama yapmasini saglar.
void sort_descending_by_using_quick_sort_double(std::vector<double>& vec) {
    std::sort(vec.begin(), vec.end(), std::greater<double>());
}
void sort_descending_by_using_quick_sort_int(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end(), std::greater<int>());
}
void sort_descending_by_using_quick_sort_longint(std::vector<long int>& vec) {
    std::sort(vec.begin(), vec.end(), std::greater<long int>());
}
void sort_descending_by_using_quick_sort_string(std::vector<std::string>& vec) {
    //std::sort(vec.begin(), vec.end(), std::greaterstd::string());
}


//ZEYNEP İREM AKYALCIN

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

//******* REMOVE_FIRST_N_ITEMS
//remove_first_n_items_double fonksiyonu, verilen bir vektorun basindan verilen bir sayida elemani siler.
//Ornegin, vec vektorunun ilk 3 elemanini silmek icin remove_first_n_items_double(vec, 3) fonksiyonu kullanilabilir.
//Bu fonksiyon, vektorun basindan verilen n sayida elemanini silmek icin vektorun erase() metodunu kullanir.
void remove_first_n_items_double(std::vector<double>& vec, int n) {
    vec.erase(vec.begin(), vec.begin() + n);
}
void remove_first_n_items_int(std::vector<int>& vec, int n) {
    vec.erase(vec.begin(), vec.begin() + n);
}
void remove_first_n_items_longint(std::vector<long int>& vec, int n) {
    vec.erase(vec.begin(), vec.begin() + n);
}
void remove_first_n_items_string(std::vector<std::string>& vec, int n) {
    vec.erase(vec.begin(), vec.begin() + n);
}

//******* REMOVE_ALL_ITEMS
//Bu kod, verilen double veri tipinde bir vektorun ilerisini tamamen siler.
//Bu islemi gerceklestirmek icin std::vector sinifinin clear() fonksiyonu kullanilmistir.Bu fonksiyon, 
//vektorun icerigini sifirlar ve boyutunu 0'a esitler. Bu sayede vektor icinde hicbir eleman kalmaz ve 
//yeni elemanlar eklemek icin bos bir alan olusur.
void remove_all_items_double(std::vector<double>& vec) {
    vec.clear();
}
void remove_all_items_int(std::vector<int>& vec) {
    vec.clear();
}
void remove_all_items_longint(std::vector<long int>& vec) {
    vec.clear();
}
void remove_all_items_string(std::vector<std::string>& vec) {
    vec.clear();
}

//******* REMOVE_CLONE
//remove_clone_double() fonksiyonu, verilen double tipindeki vektorun deepCloneVec_double adli klonunu temizler.
//Bu, asil vektoru etkilemez ancak klonun icerigi silinir.Bu, klonun daha sonra geri yuklenemeyebilecegi anlamina gelir.
void remove_clone_double(std::vector<double>& vec) {
    vec.clear();
}
void remove_clone_int(std::vector<int>& vec) {
    vec.clear();
}
void remove_clone_longint(std::vector<long int>& vec) {
    vec.clear();
}
void remove_clone_string(std::vector<std::string>& vec) {
    vec.clear();
}


//MAİN
int main() {
    std::vector<double> doubleVec; // burada double veri turunu sakladigimiz bir vektor tanimliyoruz
    std::vector<long int> longIntVec; // burada long int veri turunu sakladigimiz bir vektor tanimliyoruz
    std::vector<int> intVec; // burada int veri turunu sakladigimiz bir vektor tanimliyoruz
    std::vector<std::string> stringVec; // burada string veri turunu sakladigmiz bir vektor tanimliyoruz
    std::vector<GPS> GPSVec; // burada GPS veri turunu sakladigimiz bir vektor tanimliyoruz

    std::string files[] = { "double.csv", "longInt.csv", "integer.csv", "string.csv", "GPS.csv" };// okunacak dosyalarin isimleri
    std::string file_path = "files/";// dosyalarin yolu
    std::string line;// okunan satirlari saklamak icin kullanilan string

    for (const std::string& file : files)// dosyalari tek tek okuma icin dongu
    {
        std::ifstream ifs(file_path + file);// okunacak dosya
        if (!ifs.good()) { // dosya asilamazsa hata ver
            std::cout << "Error: file " << file << " not found" << std::endl;
        }
        else {

            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Reading file: " << file_path + file << std::endl;
            std::cout << "{" << std::endl;

            std::string command;// okunan komutlar
            std::stringstream ssin(line);// okunan komutlarin streami
            std::getline(ssin, command, ',');// komutlarin virgul ile ayrilmasi
            std::transform(command.begin(), command.end(), command.begin(), ::toupper);//komutlari buyuk harfe cevirme
            std::string command_st;// komutlarin saklanmasi icin kullanilan string

    //Bu kod, "double.csv" dosyasindan okunan verileri islemek icin kullanilir.Kod, dosyadan satir satir okur ve okunan satirin basindaki komutu alir.
    //Komut, virgulle ayrilmis sekilde verilir ve komut, ilgili islemi gerceklestirmek icin kullanilir.ornegin,
    //"ADD_BACK" komutu tasiyici veri yapisinin sonuna bir eleman eklenmesi icin kullanilir.Bu komut,
    //virgulle ayrilmis sekilde eklenecek veriyi icerir.Eger komut gecerli bir komut degilse, "Invalid Command: [komut]" seklinde bir hata mesaji yazdirilir.
    //Bu kod, doubleVec adli bir vector kullanarak verileri saklar ve islemleri gerceklestirir.
      
             if (file == "double.csv")
            {
                while (std::getline(ifs, line))
                {
                    std::string command;
                    std::stringstream ssin(line); 
                    std::getline(ssin, command, ','); // CSV dosyasindaki satirdaki ilk veriyi ',' ile ayirarak command degiskenine atar
                    std::transform(command.begin(), command.end(), command.begin(), ::toupper);// Command degiskenini buyukk harfe cevirir
                    double value;
                    char comma;
                    ssin >> comma >> value;// CSV dosyasindaki satirdaki ikinci veriyi value degiskenine atar
                    doubleVec.push_back(value);
                    // "value" degiskeni doubleVec adli vektorun sonuna ekleniyor. Bu islem push_back metodu ile gerceklestiriliyor. Bu metodun amaci tasiyici veri yapisinin onune eleman eklemektir.

                    if (command_st != command) {
                        command_st = command;
                        std::cout << "Command: " << command << std::endl;
                    }

                    if (command == "START_TIMER") {

                        start_timer();
                    }
                    else if (command == "STOP_TIMER") {

                        stop_timer();
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;

                    }
                    else if (command == "ADD_BACK") {

                        add_back_double(doubleVec, value);
                    }

                    else if (command == "ADD_FRONT") {

                        add_front_double(doubleVec, value);
                    }
                    else if (command == "PRINT_FIRST_N_ELEMENTS") {

                        print_first_n_elements_double(doubleVec, value);
                    }
                    else if (command == "PRINT_LAST_N_ELEMENTS") {

                        print_last_n_elements_double(doubleVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_FIRST") {

                        if_exists_remove_first_double(doubleVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_LAST") {

                        if_exists_remove_last_double(doubleVec, value);
                    }
                    else if (command == "CREATE_A_DEEP_CLONE") {

                        deepCloneVec_double = create_a_deep_clone(doubleVec);
                    }
                    else if (command == "SORT_ASCENDING_BY_USING_SELECTION_SORT") {

                        sort_ascending_using_selection_sort_double(doubleVec);
                    }
                    else if (command == "RESTORE_FROM_CLONE") {

                        restore_from_clone_double(doubleVec);
                    }
                    else if (command == "sort_descending_by_usning_quick_sort_double") {

                        sort_descending_by_using_quick_sort_double(doubleVec);
                    }
                    else if (command == "ADD_ORDERED") {

                        add_ordered(doubleVec, value);
                    }
                    else if (command == "REMOVE_LAST_N_ITEMS") {

                        remove_last_n_items_double(doubleVec, value);
                    }
                    else if (command == "REMOVE_FIRST_N_ITEMS") {

                        remove_first_n_items_double(doubleVec, value);
                    }
                    else if (command == "REMOVE_ALL_ITEMS") {

                        remove_all_items_double(doubleVec);
                    }
                    else if (command == "REMOVE_CLONE") {

                        remove_clone_double(doubleVec);
                    }
                    else {
                        std::cout << "Invalid Command: " << command << std::endl;

                    }
                }
            }
            else if (file == "integer.csv")
            {
                while (std::getline(ifs, line))
                {
                    std::string command;
                    std::stringstream ssin(line);
                    std::getline(ssin, command, ',');
                    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
                    int value;
                    char comma;
                    ssin >> comma >> value;
                    intVec.push_back(value);

                    if (command_st != command) {
                        command_st = command;
                        std::cout << "Command: " << command << std::endl;
                    }

                    if (command == "START_TIMER") {

                        start_timer();
                    }
                    else if (command == "STOP_TIMER") {

                        stop_timer();
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;

                    }
                    else if (command == "ADD_BACK") {

                        add_back_int(intVec, value);
                    }

                    else if (command == "ADD_FRONT") {

                        add_front_int(intVec, value);
                    }
                    else if (command == "PRINT_FIRST_N_ELEMENTS") {

                        print_first_n_elements_int(intVec, value);
                    }
                    else if (command == "PRINT_LAST_N_ELEMENTS") {

                        print_last_n_elements_int(intVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_FIRST") {

                        if_exists_remove_first_int(intVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_LAST") {

                        if_exists_remove_last_int(intVec, value);
                    }
                    else if (command == "CREATE_A_DEEP_CLONE") {

                        deepCloneVec_int = create_a_deep_clone(intVec);
                    }
                    else if (command == "SORT_ASCENDING_BY_USING_SELECTION_SORT") {

                        sort_ascending_using_selection_sort_int(intVec);
                    }
                    else if (command == "RESTORE_FROM_CLONE") {

                        restore_from_clone_int(intVec);
                    }
                    else if (command == "sort_descending_by_usning_quick_sort") {

                        sort_descending_by_using_quick_sort_int(intVec);
                    }
                    else if (command == "ADD_ORDERED") {

                        add_ordered(intVec, value);
                    }
                    else if (command == "REMOVE_LAST_N_ITEMS") {

                        remove_last_n_items_int(intVec, value);
                    }
                    else if (command == "REMOVE_FIRST_N_ITEMS") {

                        remove_first_n_items_int(intVec, value);
                    }
                    else if (command == "REMOVE_ALL_ITEMS") {

                    }
                }

            }
            else if (file == "longInt.csv")
            {
                while (std::getline(ifs, line))
                {
                    std::string command;
                    std::stringstream ssin(line);
                    std::getline(ssin, command, ',');
                    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
                    long int value;
                    char comma;
                    ssin >> comma >> value;
                    longIntVec.push_back(value);

                    if (command_st != command) {
                        command_st = command;
                        std::cout << "Command: " << command << std::endl;
                    }

                    if (command == "START_TIMER") {

                        start_timer();
                    }
                    else if (command == "STOP_TIMER") {

                        stop_timer();
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;

                    }
                    else if (command == "ADD_BACK") {

                        add_back_longint(longIntVec, value);
                    }

                    else if (command == "ADD_FRONT") {

                        add_front_longint(longIntVec, value);
                    }
                    else if (command == "PRINT_FIRST_N_ELEMENTS") {

                        print_first_n_elements_longint(longIntVec, value);
                    }
                    else if (command == "PRINT_LAST_N_ELEMENTS") {

                        print_last_n_elements_longint(longIntVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_FIRST") {

                        if_exists_remove_first_longint(longIntVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_LAST") {

                        if_exists_remove_last_longint(longIntVec, value);
                    }
                    else if (command == "CREATE_A_DEEP_CLONE") {

                        deepCloneVec_longint = create_a_deep_clone(longIntVec);
                    }
                    else if (command == "SORT_ASCENDING_BY_USING_SELECTION_SORT") {

                        sort_ascending_using_selection_sort_longint(longIntVec);
                    }
                    else if (command == "RESTORE_FROM_CLONE") {

                        restore_from_clone_longint(longIntVec);
                    }
                    else if (command == "sort_descending_by_usning_quick_sort_double") {

                        sort_descending_by_using_quick_sort_longint(longIntVec);
                    }
                    else if (command == "ADD_ORDERED") {

                        add_ordered(longIntVec, value);
                    }
                    else if (command == "REMOVE_LAST_N_ITEMS") {

                        remove_last_n_items_longint(longIntVec, value);
                    }
                    else if (command == "REMOVE_FIRST_N_ITEMS") {

                        remove_first_n_items_longint(longIntVec, value);
                    }
                    else if (command == "REMOVE_ALL_ITEMS") {

                        remove_all_items_longint(longIntVec);
                    }
                    else if (command == "REMOVE_CLONE") {

                        remove_clone_longint(longIntVec);
                    }
                    else {
                        std::cout << "Invalid Command: " << command << std::endl;

                    }
                }

            }
            else if (file == "string.csv")
            {
                while (std::getline(ifs, line))
                {
                    std::string command;
                    std::stringstream ssin(line);
                    std::getline(ssin, command, ',');
                    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
                    std::string value;
                    char comma;
                    ssin >> comma >> value;
                    stringVec.push_back(value);

                    if (command_st != command) {
                        command_st = command;
                        std::cout << "Command: " << command << std::endl;
                    }

                    if (command == "START_TIMER") {

                        start_timer();
                    }
                    else if (command == "STOP_TIMER") {

                        stop_timer();
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;

                    }
                    else if (command == "ADD_BACK") {

                        add_back_string(stringVec, value);
                    }

                    else if (command == "ADD_FRONT") {

                        add_front_string(stringVec, value);
                    }
                    else if (command == "PRINT_FIRST_N_ELEMENTS") {

                        print_first_n_elements_string(stringVec, std::stoi(value));
                    }
                    else if (command == "PRINT_LAST_N_ELEMENTS") {

                        print_last_n_elements_string(stringVec, std::stoi(value));
                    }
                    else if (command == "IF_EXISTS_REMOVE_FIRST") {

                        if_exists_remove_first_string(stringVec, value);
                    }
                    else if (command == "IF_EXISTS_REMOVE_LAST") {

                        if_exists_remove_last_string(stringVec, value);
                    }
                    else if (command == "CREATE_A_DEEP_CLONE") {

                        deepCloneVec_string = create_a_deep_clone(stringVec);
                    }
                    else if (command == "SORT_ASCENDING_BY_USING_SELECTION_SORT") {

                        sort_ascending_using_selection_sort_string(stringVec);
                    }
                    else if (command == "RESTORE_FROM_CLONE") {

                        restore_from_clone_string(stringVec);
                    }
                    else if (command == "sort_descending_by_usning_quick_sort_double") {

                        sort_descending_by_using_quick_sort_string(stringVec);
                    }
                    else if (command == "ADD_ORDERED") {

                        add_ordered(stringVec, value);
                    }
                    else if (command == "REMOVE_LAST_N_ITEMS") {

                        remove_last_n_items_string(stringVec, std::stoi(value));
                    }
                    else if (command == "REMOVE_FIRST_N_ITEMS") {

                        remove_first_n_items_string(stringVec, std::stoi(value));
                    }
                    else if (command == "REMOVE_ALL_ITEMS") {

                        remove_all_items_string(stringVec);
                    }
                    else if (command == "REMOVE_CLONE") {

                        remove_clone_string(stringVec);
                    }
                    else {
                        std::cout << "Invalid Command: " << command << std::endl;

                    }
                }


            }
            else if (file == "GPS.csv")
            {

            }
            std::cout << "}" << std::endl;
        }
    }
}

