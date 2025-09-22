Features
1. Dual-Linked List Structure
- Age-sorted list: Maintains persons sorted by birth year (ascending order)
- Lastname-sorted list: Maintains persons sorted alphabetically by last name
- Each person exists in both lists simultaneously through different pointer chains

2. Data Persistence
- Reads person data from a text file (dane.txt)
- File format: lastname firstname birthyear on each line
- Automatic parsing and insertion into both sorted lists

3. Multiple Sorting Criteria
- Chronological sorting: By birth year (age-based)
- Alphabetical sorting: By last name (lexicographical order)


Algorithms
- Insertion Sort Implementation
- The program uses custom insertion algorithms for both sorting criteria:

Age-Based Insertion: void dodaj_do_listy_wiek(Person** head, Person* nowa)
- Inserts persons in ascending order of birth year
- Maintains chronological ordering
- Time complexity: O(n) per insertion

Lastname-Based Insertion: void dodaj_do_listy_nazwisko(Person** head, Person* nowa)
- Inserts persons in lexicographical order using strcmp()
- Maintains alphabetical ordering
- Time complexity: O(n) per insertion


Dual List Synchronization
void dodaj_osobe(Person** head_wiek, Person** head_nazwisko, Person* nowa)
- Coordinates insertion into both lists simultaneously
- Ensures data consistency across both sorting criteria


File Format

The program expects dane.txt in the following format:

Kowalski Jan 1985

Nowak Anna 1990

Wisniewski Piotr 1978

Each line contains:
- Last name (single word)
- First name (single word)
- Birth year (integer)

Compilation and Execution 
To compile and run the program: gcc database.c -o database
