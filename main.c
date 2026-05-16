
// Write your code in this file

// stdio.h behövs för att vi ska kunna använda scanf och printf.
// scanf används för att läsa in data från användaren och printf används för att skriva ut resultat i terminalen.
//
// ctype.h behövs för funktionerna toupper och tolower.
// De används för att ändra stora och små bokstäver i namnen.
#include <stdio.h>
#include <ctype.h>

// Här definieras konstanter som används flera gånger i programmet.
// På så sätt slipper vi skriva siffrorna direkt i koden och gör koden lättare att ändra senare.
//
// NUMBER_OF_STUDENTS = antal elever programmet hanterar.
// NUMBER_OF_TESTS = antal prov varje elev har gjort.
// MAX_NAME_LENGTH = max antal tecken ett namn får innehålla.
#define NUMBER_OF_STUDENTS 5
#define NUMBER_OF_TESTS 13
#define MAX_NAME_LENGTH 11

// Den här funktionen används för att formatera elevens namn.
//
// Första bokstaven i namnet görs stor.
// Alla andra bokstäver görs små.
//
// Exempel: "aNNA" blir "Anna"
void format_name(char name[])
{
  // Kontrollerar först att namnet inte är tomt.
  if (name[0] != '\0')
  {
    // Gör första bokstaven stor.
    name[0] = toupper(name[0]);

    // Loopen går igenom resten av bokstäverna i namnet.
    for (int i = 1; name[i] != '\0'; i++)
    {
      // Gör resten av bokstäverna små.
      name[i] = tolower(name[i]);
    }
  }
}

// Den här funktionen räknar ut medelvärdet för en elevs alla provresultat.
float calculate_average(int test_results[])
{
  // Variabel som används för att spara summan av elevens alla provresultat.
  int student_score_sum = 0;

  // Loopen går igenom elevens 13 provresultat.
  for (int test = 0; test < NUMBER_OF_TESTS; test++)
  {
    // Varje provresultat läggs till i summan.
    student_score_sum += test_results[test];
  }

  // Summan delas med antal prov för att få fram medelvärdet.
  //
  // (float) används för att divisionen ska ge decimaler och inte bara heltal.
  return student_score_sum / (float)NUMBER_OF_TESTS;
}

// Här börjar huvudprogrammet.
int main()
{
  // Tvådimensionell array som lagrar elevernas namn.
  //
  // Första indexet representerar eleverna.
  // Andra indexet representerar bokstäverna i namnet.
  //
  // Programmet kan lagra 5 namn och varje namn kan vara max 10 tecken långt.
  char student_names[NUMBER_OF_STUDENTS][MAX_NAME_LENGTH];

  // Tvådimensionell array som lagrar alla provresultat.
  //
  // Första indexet representerar eleven.
  // Andra indexet representerar elevens provresultat.
  //
  // Varje elev har 13 provresultat.
  int test_results[NUMBER_OF_STUDENTS][NUMBER_OF_TESTS];

  // Array som används för att spara varje elevs medelvärde.
  float student_averages[NUMBER_OF_STUDENTS];

  // Variabel som sparar summan av ALLA provresultat  från alla elever tillsammans.
  int total_score_sum = 0;

  // Den här loopen går igenom alla elever.
  //
  // För varje elev:
  // => Läser programmet in elevens namn.
  // => Formaterar namnet.
  // => Läser in elevens provresultat.
  // => Räknar ut elevens medelvärde.
  for (int student = 0; student < NUMBER_OF_STUDENTS; student++)
  {
    // Läser in elevens namn.
    //
    // %10s betyder att max 10 tecken läses in, vilket skyddar arrayen från att få för lång input.
    scanf("%10s", student_names[student]);

    // Formaterar namnet direkt efter inmatningen.
    format_name(student_names[student]);

    // Den här loopen går igenom elevens 13 provresultat.
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
      // Läser in ett provresultat och sparar det på rätt plats i arrayen.
      scanf("%d", &test_results[student][test]);

      // Provresultatet läggs samtidigt till i totalsumman.
      total_score_sum += test_results[student][test];
    }

    // När alla provresultat för eleven är inlästa räknas elevens medelvärde ut och sparas.
    student_averages[student] = calculate_average(test_results[student]);
  }

  // Här räknas gruppens genomsnitt ut.
  //
  // Totalsumman delas med totalt antal provresultat.
  //
  // Antal provresultat totalt: 5 elever * 13 prov = 65 resultat.
  float group_average = total_score_sum / (float)(NUMBER_OF_STUDENTS * NUMBER_OF_TESTS);

  // Programmet börjar med att anta att första eleven har högst medelvärde.
  //
  // Därför sätts index till 0.
  int best_student_index = 0;

  // Den här loopen jämför alla elevers medelvärden för att hitta den elev som har högst resultat.
  //
  // Loopen börjar från index 1 eftersom index 0 redan används som första jämförelse.
  for (int student = 1; student < NUMBER_OF_STUDENTS; student++)
  {
    // Om den aktuella eleven har högre medelvärde än den elev som just nu är "bäst",
    if (student_averages[student] > student_averages[best_student_index])
    {
      best_student_index = student; // uppdateras best_student_index.
    }
  }

  // Skriver ut namnet på eleven som hade högst medelvärde.
  printf("%s\n", student_names[best_student_index]);

  // Den här loopen går igenom alla elever igen.
  //
  // Vi ska hitta de elever som ligger under gruppens genomsnitt.
  for (int student = 0; student < NUMBER_OF_STUDENTS; student++)
  {
    // Om elevens medelvärde är lägre än gruppens genomsnitt skrivs namnet ut.
    if (student_averages[student] < group_average)
    {
      printf("%s\n", student_names[student]);
    }
  }

  // return 0 betyder att programmet avslutas.
  return 0;
}

// =============================================================
// ToDo:

// Examination - Elevhanteringssystem

// Välkommen till detta prov i Programmering i C! Din uppgift är att skriva ett program som läser in provresultat, analyserar statistik och presenterar data för läraren.
// VIKTIGT: LÄS DETTA FÖRST

// För att din inlämning ska fungera och rättas korrekt måste du följa dessa regler:

//     Rör ej systemfiler: Du får inte göra ändringar i mappen .github, test.sh eller makefile. Om du ändrar dessa filer kan ditt prov ogiltigförklaras.
//     Registrering: Du måste fylla i ditt ID i student.json innan du börjar (se nedan).
//     Inlämningsstatus: Du styr själv när du är "klar" genom en inställning i student.json.

// Steg 1: Setup & ID

// Innan du börjar koda måste du ställa in ditt projekt. Om du inte gör detta kommer inga av dina tester att köras.

// Så här hittar du ditt ID:

//     Logga in på antagningssidan (yh-antagning.se).
//     Under "Inlämnade ansökningar", klicka på rutan för denna utbildning.
//     Scrolla längst ner på sidan till sektionen "Mina personuppgifter" (klicka på pilen för att fälla ut om det behövs).
//     Kopiera koden som står vid Ansökningsnummer (t.ex. FSAEFSAD).

// Så här ställer du in repot:

//     Öppna filen student.json i din kodeditor.
//     Byt ut texten "SKRIV_DITT_ID_HÄR" mot ditt ID.
//     Låt "submitted": false vara kvar. Detta betyder att du jobbar på ett utkast.
//     Spara filen.

// {
//   "student_id": "SKRIV_DITT_ID_HÄR",
//   "submitted": false
// }

// Uppgiftsbeskrivning

// Fil att arbeta i: main.c

// Du ska skapa ett system som hanterar 5 elever och deras resultat från 13 olika prov under ett läsår. Programmet ska läsa in namn och poäng, räkna ut medelvärden och filtrera ut specifika resultat.

// Specifikation i korthet:

//     Indata: 5 rader. Varje rad har formatet: Namn p1 p2 p3 ... p13.
//     Namn: Engelska förnamn (a-z), max 10 tecken.
//     Poäng: Heltal 0-10.

// Totalt kan du få 100 poäng på den automatiska rättningen.
// Regler & Begränsningar (Viktigt!)

// För att det automatiska rättningssystemet ska fungera måste du följa dessa regler strikt:

//     Ingen extra text: Programmet får INTE skriva ut text som "Mata in namn:" eller "Resultatet är:". Endast namnen på eleverna ska skrivas ut.
//     Exakt utskrift: Varje namn ska skrivas ut på en egen rad.
//     Versaler: Alla namn ska skrivas ut med Stor Begynnelsebokstav (t.ex. "Alice"), oavsett hur de matades in.
//     Inläsning: Använd med fördel scanf() för att hantera inmatningen.

// Funktionella Krav & Poängsättning

// Din kod rättas i steg. Även om du har småfel (t.ex. fel stor bokstav) kan du få poäng för logiken.
// 1. Grundläggande funktionalitet (20p)

//     (20p) Koden ska kompilera och köra utan att krascha när testdata matas in.

// 2. Analys: Högst medelpoäng (30p)

//     (15p) Logik: Programmet identifierar korrekt vilken elev som har högst medelpoäng (oavsett stor/liten bokstav).
//     (15p) Format: Namnet skrivs ut korrekt med stor begynnelsebokstav (t.ex. "Charlie").

// 3. Analys: Under gruppens snitt (30p)

//     (15p) Logik: Programmet räknar ut totala medelvärdet och identifierar vilka elever som ligger under detta (oavsett stor/liten bokstav).
//     (15p) Format: Namnen skrivs ut med stor begynnelsebokstav och i samma ordning som de matades in (t.ex. "Bob" och "Dave").

// Inlämning & Video (20p)

// Förutom koden ska du spela in en kort skärminspelning där du demonstrerar din lösning.

//     Spela in när du visar din lösning och berättar om hur den fungerar.
//     Döp filen till exakt: videoprov.mp4.
//     Lägg filen i rotmappen (samma ställe som denna README).
//     OBS: Filen får inte vara större än 100MB.

// Hur du testar din kod

// Detta projekt använder automatisk rättning. Du har två sätt att se dina poäng:
// Alternativ 1: Köra testerna lokalt (Rekommenderas!)

// Du kan köra exakt samma tester som GitHub använder direkt i din terminal. Detta ger dig snabbast feedback.

//     Öppna en terminal i mappen.
//     Skriv följande kommando:

// make test

// Detta kommer att kompilera din kod och köra alla deltester. Du ser direkt vilka delar som är "Pass" eller "Fail".
// Alternativ 2: Testa manuellt

// Om du vill felsöka och mata in egna värden manuellt:

//     Kompilera: gcc main.c -o main.out
//     Kör: ./main.out
//     Klistra in följande testdata:

// alice 8 9 7 6 10 9 8 7 10 10 9 10 8
// Bob 5 5 6 4 5 6 5 5 4 6 5 5 4
// Charlie 10 9 9 10 10 9 9 10 9 10 10 9 10
// david 4 3 5 4 4 5 4 5 4 3 5 4 4
// Eve 7 6 7 8 7 6 7 7 6 7 8 7 6

// Förväntat resultat:

// Charlie
// Bob
// David

// (Ingen annan text får förekomma!)
// Alternativ 3: GitHub Feedback

// När du gör en git push kommer GitHub att köra testerna. Resultatet syns under fliken Actions eller som en kommentar i din Pull Request.

//     OBS: Så länge submitted är false kommer GitHub visa ett Rött Kryss (Failed) på inlämningen för att visa att den ej är inlämnad. Detta är normalt.

// Steg 2: Inlämning

// När du känner dig klar och har fått de poäng du satsar på:

//     Öppna student.json.
//     Ändra "submitted": false till "submitted": true.
//     Spara, committa och pusha till GitHub.

// {
//   "student_id": "SKRIV_DITT_ID_HÄR",
//   "submitted": true
// }

// Nu (om du klarat alla obligatoriska krav) ska du få en Grön Bock på GitHub och botten kommer skriva "INLÄMNING MOTTAGEN".
