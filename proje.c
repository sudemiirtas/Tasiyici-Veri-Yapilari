#include <algorithm>   //algoritma kütüphanesi
#include <chrono> //zaman kütühanesi
#include <fstream> //dosya kütüphanesi
#include <iostream> //giriş-çıkış kütüphanesi
#include <queue>. //sınıf şablonları kütüphanesi
#include <sstream> //ayrılmış dizi kütüphanesi
#include <string> //dizi kütüphanesi
#include <tuple>  //nesneleri tutan kütüphane
#include <utility> //nesne çiftleri oluşturma kütüphane
#include <vector> //vektör kütüphanesi

using DataType = int;   //veri tipi
using DataStructure = std::queue<DataType>;

//nanosaniyeye dönüştürme
auto current_time()
{
  return std::chrono::duration_cast<std::chrono::nanoseconds>(
             std::chrono::high_resolution_clock::now().time_since_epoch())
      .count();
}
