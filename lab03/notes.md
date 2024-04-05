### Co ma robić program?
- odczytywać z pliku linia po lini znak
- musimy przepisywać znaki od tyłu linia po lini do nowego pliku
- funkcja wyszukująca pliki .txt w podanym katalogu
- funkcja tworząca nowe pliki w podanym katalogu

#### Dodatkowo
- można sprawdzać czy katalog nie istnieje jeśli nie to go tworzyć na bieżąco

todo:
- How to use man

## Notatki
Funkcja strcspn()
Znajduje położenie pierwszego znaku w łańcuchu. Funkcja strcspn(line, "\n") szuka pierwszego wystąpienia znaku nowego wiersza ('\n') w ciągu zdefiniowanym zmienną line.
Zwraca indeks. Funkcja zwraca indeks (pozycję) pierwszego dopasowania. Jeżeli znak nowego wiersza nie zostanie znaleziony, zwracana jest długość ciągu line.

DIR - jest wskaźnikiem reprezentującym strumień katalogowy, przechowuje informacje o iteracji
przez zawartość katalogu używając funkcji readdir(). 
Inaczej struktura która pozwala pracować z podkatalogami i plikami w danym katalogu

struct dirent - przechowuje info o jedym katalogu lub pliku w strumieniu katalagowym
```c
DIR *dir;
struct dirent *entry;
```
Oto rozbicie kodu snprintf(file_path, sizeof(file_path), "%s/%s", source_dir, dir_entry->d_name); i jego działanie:

1. snprintf

snprintf to funkcja z biblioteki standardowej C, która formatuje ciąg znaków (formatuje tekst z użyciem danych) i zapisuje rezultat do bufora o określonym rozmiarze (jest bezpieczniejsza niż sprintf). Ma następujące argumenty:
file_path: Docelowy bufor, w którym będzie przechowywany wynikowy ciąg znaków.
sizeof(file_path): Maksymalna liczba znaków, jaką można zapisać w buforze file_path.
"%s/%s": Ciąg formatujący określający strukturę wynikowego ciągu.
source_dir, dir_entry->d_name: Wartości, które mają zostać wstawione do ciągu formatującego.