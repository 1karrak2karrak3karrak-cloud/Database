#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char nazwisko[50];
    char imie[50];
    int rok_urodzenia;

    struct Person* next_wiek;
    struct Person* next_nazwisko;
} Person;

void dodaj_do_listy_wiek(Person** head, Person* nowa) {
    if (*head == NULL || nowa->rok_urodzenia < (*head)->rok_urodzenia) {
        nowa->next_wiek = *head;
        *head = nowa;
    } else {
        Person* current = *head;
        while (current->next_wiek != NULL && current->next_wiek->rok_urodzenia <= nowa->rok_urodzenia) {
            current = current->next_wiek;
        }
        nowa->next_wiek = current->next_wiek;
        current->next_wiek = nowa;
    }
}

void dodaj_do_listy_nazwisko(Person** head, Person* nowa) {
    if (*head == NULL || strcmp(nowa->nazwisko, (*head)->nazwisko) < 0) {
        nowa->next_nazwisko = *head;
        *head = nowa;
    } else {
        Person* current = *head;
        while (current->next_nazwisko != NULL &&
               strcmp(current->next_nazwisko->nazwisko, nowa->nazwisko) <= 0) {
            current = current->next_nazwisko;
        }
        nowa->next_nazwisko = current->next_nazwisko;
        current->next_nazwisko = nowa;
    }
}

void dodaj_osobe(Person** head_wiek, Person** head_nazwisko, Person* nowa) {
    nowa->next_wiek = NULL;
    nowa->next_nazwisko = NULL;
    dodaj_do_listy_wiek(head_wiek, nowa);
    dodaj_do_listy_nazwisko(head_nazwisko, nowa);
}

void wypisz_wedlug_wieku(Person* head) {
    printf("\nOsoby posortowane według wieku:\n");
    while (head != NULL) {
        printf("%s %s, %d\n", head->nazwisko, head->imie, head->rok_urodzenia);
        head = head->next_wiek;
    }
}

void wypisz_wedlug_nazwiska(Person* head) {
    printf("\nOsoby posortowane alfabetycznie według nazwiska:\n");
    while (head != NULL) {
        printf("%s %s, %d\n", head->nazwisko, head->imie, head->rok_urodzenia);
        head = head->next_nazwisko;
    }
}

Person* stworz_osobe(const char* nazwisko, const char* imie, int rok) {
    Person* nowa = (Person*)malloc(sizeof(Person));
    strcpy(nowa->nazwisko, nazwisko);
    strcpy(nowa->imie, imie);
    nowa->rok_urodzenia = rok;
    nowa->next_wiek = NULL;
    nowa->next_nazwisko = NULL;
    return nowa;
}

int main() {
    Person* head_1 = NULL; //wiek
    Person* head_2 = NULL; //nazw

    FILE* plik = fopen("dane.txt", "r");
    if (plik == NULL) {
        perror("Nie można otworzyć pliku!");
        return 1;
    }

    char nazwisko[50], imie[50];
    int rok;

    while (fscanf(plik, "%s", nazwisko) == 1 &&
           fscanf(plik, "%s", imie) == 1 &&
           fscanf(plik, "%d", &rok) == 1) {
        Person* nowa = stworz_osobe(nazwisko, imie, rok);
        dodaj_osobe(&head_1, &head_2, nowa);
    }

    fclose(plik);

    wypisz_wedlug_nazwiska(head_2);
    wypisz_wedlug_wieku(head_1);

    return 0;
}

