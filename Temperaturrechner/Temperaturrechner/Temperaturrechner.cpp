//Aufgabe 1: Temperaturrechner PE

#define _CRT_SECURE_NO_WARNINGS 1


#include <stdlib.h>// Standartbibliothek "Standardlibrary" wird inkludiert. Ebenfalls benötigt um rand() zu nutzen.
#include <stdio.h> //Standartbibliothek "Standardlibrary" (i)nput (o)utput wird inkludiert. Ebenfalls benötigt um printf() zu nutzen.

void draw_thermostat(float temp, int unit) {//Hier wird eine neue Funktion namens draw_thermostat erstellt. Welche dazu dient im späteren verlauf der main-Funktion das Thermometer auszugeben.
	int bar, i; // Hier werden integer "bar"&"i" deklariert. Genauere erläuterung finden sie in der "main"-Funktion.

	for (i = 0; i <= 49; i++) { //Hier wird die obere Abgrenzung des Thermometers, bestehend aus 50 Strichen '-', gezeichnet
		printf("-");
	}
	printf("\n");
	switch (unit)  //Hier wird mithilfe einer Fallunterscheidung die Thermometer-Beschreibung ausgesucht. Die Unterscheidung richtet sich nach der Variable Unit (vorher unitOut).
	{
	case 1: bar = (temp / 100) * 50;
		for (i = 0; i <= bar - 1; i++) { //Hier wird jeweils immer die untere Abgrenzung gezeichnet
			printf("*"); //Hiermit werden die Sterne innerhalb des Thermometers gezeichnet.
		}
		printf("\n");
		for (i = 0; i <= 49; i++) {
			printf("-");
		}
		printf("\n0°C");
		for (i = 0; i <= 41; i++) {
			printf(" ");
		};
		printf("100°C");
		break;
	case 2: bar = (temp / 212) * 50;
		for (i = 0; i <= bar - 1; i++) {
			printf("*");
		}
		printf("\n");
		for (i = 0; i <= 49; i++)
		{
			printf("-");
		}
		printf("\n32°F");
		for (i = 0; i <= 40; i++) {
			printf(" ");
		};
		printf("212°F");
		break;
	case 3: bar = (temp / 373.15) * 50;
		for (i = 0; i <= bar - 1; i++) {
			printf("*");
		}
		printf("\n");
		for (i = 0; i <= 49; i++) {
			printf("-");
		}
		printf("\n273.15°K");
		for (i = 0; i <= 33; i++) {
			printf(" ");
		};
		printf("373.15°K");
		break;
	case 4: bar = (temp / 60) * 50;
		for (i = 0; i <= bar - 1; i++) {
			printf("*");
		}
		printf("\n");
		for (i = 0; i <= 49; i++) {
			printf("-");
		}
		printf("\n7,5°Rø");
		for (i = 0; i <= 38; i++) {
			printf(" ");
		};
		printf("60°Rø");
		break;
	}
}
int main()

{

	/*
	Hauptfunktion/Startfunktion "main()" wird beim Start des Programmes initiiert.
	int main() ist equivalent zu int main(void).
	Beide benötigen keineswegs Argumente als Parameter zum ausführen.
	Um von einer Softwareanwendung etwas eindeutig berechenn zu lassen werden,
	werden in der Informatik funktionen gebraucht.
	Wichtige Datentypen sowie deren Größe in Bits.
	Desweiteren ist Anzumerken, dass jeder Datentyp seine ganz eigenen Anwendungsbereich hat.
	__________________

	integer: 16/32Bits - ganze zahlen           (%d)
	char: 8Bits        - Buchstabe              (/c)
	double: 64 Bits    - Zahlen mit Nachkomma   (%lf) -> genauer als "float"
	float: 32Bits      - Zahlen mit Nachkomma   (%f)
	__________________

	(Die oben genannten Datentypen werden im laufe des Programms teils genutzt.)
	*/

	float tempIn, tempOut;
	/*
   es werden zwei Mal Variablen vom Typ "float" deklariert.
   float = Datentyp
   "tempIn, tempOut" = Name der Variablen
   Wertebreich von +/- 10^38
	*/
	int unitIn, unitOut;
	/*
	es werden zwei Variablen vom Typ "int"/integer deklariert
	int = Datentyp "unitIn,unitOut"= Name der Variablen
	Dieser Datentyp hat einen Wertebereich von -32768 bis 32767 bei 16 Bit.
	unitIn bewirkt:
	unitOut bewirkt:
	*/

	int desiredConversion;
	/* es wird eine neue Variable vom Typ integer deklariert, welche den Namen "desiredConversation" trägt.
	Dieser hätte jedoch auch in der gleiche Zeile wie die beiden anderen deklariert werden können.
	Dies würde dann ca so aussehen: "int unitIn,unitOut,desiredConversation".
	*/

	char response = 0;
	/*
	Eine Variable des Datentyps "char" namens "response" wurde deklariert.
	Dieser Datentyp hat einen Wertebereich von -128 bis 127
	*/

	printf("\n\nProgramm zur Umrechnung von Temperaturen\n");
	printf("----------------------------------------\n");
	/*
	Hier wird die Ausgabefunktion "printf" verwendet.
	Diese nimmt eine sogenannte Zeichenkette, sprich eine endliche
	Folge von Zeichen, mit Text und Formatierungs hinweisen sowie mit einem oder mehreren
	Werten entgegen.
	Wird diese Zeichenkette ausgegeben, so wird diese in die richtige Schreibweise(
	Formatierung eingefügt).
	Abgesehen davon ist "\n" für die Formatierung sehr wichtig, da diese ebenso wie
	"::std::endl" (endline). Beide Sorgen dafür das die Ausgabe in einer neuen Zeile stattfindet.
	"::std::endl" hingegen sogt zusätzlich noch für das ausgeben zwischengespeicherter Daten, was
	den Prozess verlangsamert.
	*/

	do {
		/*
		In der oberen Zeile wurde eine "do-while" Schleife erstellt, und wird in den Folgenden genutzt
		Den Aufbau kann man sich wie folgt vorstellen:
		{for (Anfangswert; Prüfe Bedingung; Veränderung des Anfangswertes) }
			Anweisungen
		*/
		do {
			printf("\nAus welchem Einheitensystem soll umgerechnet werden?\n");
			printf("1: Grad C     2: Grad F     3: Kalvin   4: Romer\n\n");
			printf("Ihre Wahl: ");
			scanf("%i", &unitIn); //unitIn ist der Wert aus welchem umgerechnet werden soll.
			if (unitIn != 1 && unitIn != 2 && unitIn != 3 && unitIn != 4) {     //In dieser Zeile wird die Eingabe des Einheitensystems auf eine Zahl zwischen 1 und 4 blockiert.
				printf("\nBitte geben Sie eine Zahl zwischen 1 und 4 ein.");
			}
		} while (unitIn != 1 && unitIn != 2 && unitIn != 3 && unitIn != 4); // In dieser Zeile wird dieser Vorgang wiederholt, bis eine Eingabe zwischen 1 und 4 eingegeben wird.

		/*
		Hier wird nun gebrauch von der Funktion "scanf" gemacht.
		Djese besitzt eine ähnliche Syntax wie die zu vor genutzte
		Funktion "printf".
		"scanf" ist dazu da um einen Wert einzulesen und diesen in angegebene Variablen
		zu speichern.
		Dazu jedoch ist das nutzen der Variablen.
		Sonst:
		scanf("%i", x); = Fehler
		Richtig ist: scanf("%i",&x); .
		*/

		/*
		In der unteren Zeile wird "while" genutzt.
		Dies steht für die Nutzung eines Loops, welche einem die Notwendigkeit nimmt
		Teile seines codes immer wieder neu schreiben zu müssen.
		*/
		while (getchar() != '\n');

		/*
		In der oberen Zeile wird das erste Mal der Befehl
		"getchar" genutzt. Dieser hat die Funktion, das Programm
		anzuhalten und erst nach einer Tastatureingabe weiter laufen zu lassen.
		Das beim betätigen der Tastatur genutzte Zeichen wird somit als
		"char-Variable gespeicher".
		*/

		printf("\nBitte geben Sie die umzurechnende Temperatur an: ");
		scanf("%f", &tempIn);

		//Aufgabe 3 - keine Werte unter dem totalen Nullpunkt

		do {
			while (getchar() != '\n');
			printf("\nIn welches Einheitensystem soll umgerechnet werden?\n\n");
			printf("1: Grad C     2: Grad F     3: Kalvin   4:Romer \n\n");
			printf("Ihre Wahl: ");//printf gibt hier ihnen nun die Möglichgeit hinter den Doppelpunkt Ihre Wahl des Einheitensystems einzutippen
			scanf("%i", &unitOut);//unitOut ist der Wert in welche die Temperatur gerechnet werden soll.
			while (getchar() != '\n');

			if (unitOut != 1 && unitOut != 2 && unitOut != 3 && unitOut != 4) {     //In dieser Zeile wird die Eingabe des Einheitensystems auf eine Zahl zwischen 1 und 4 blockiert.
				printf("\nBitte geben Sie eine Zahl zwischen 1 und 4 ein.");
			}
		} while (unitOut != 1 && unitOut != 2 && unitOut != 3 && unitOut != 4); // In dieser Zeile wird dieser Vorgang wiederholt, bis eine Eingabe zwischen 1 und 4 eingegeben wird.

		desiredConversion = unitIn * 10 + unitOut;
		switch (desiredConversion)
		{
			/*
			In der obrigen Zeile wird ein Switch Case genutzt.
			Dieser gilt ähnlich wie eine "if" Anweisung zum ausführen
			unterschiedlicher Aktionen in verschiedenen Fällen.
			In den Klammern "()" nach dem "switch" wird der Ausdruck reingeschrieben,
			welchen wir mit der hilfe eines Switch Case's auswerten wollen.

			Im Anschluss darauf, wie in den unteren Zeilen zu erkennen, folgt das Schlüsselwort
			"case" welches die verschiedenen Fälle kennzeichnet.
			Nach dem Doppelpunkt, welcher nach dem "case" folgt, kommen die auszuführenden Befehle.
			Mit "break" wird beim gelungenen Ausführen eines Falles, die switch-Anweisung
			verlassen.
			*/

			// Umrechnung von Celsius in Fahrenheit
		case 12:
			if (tempIn >= -273.15) {
				tempOut = tempIn * 1.8 + 32.0;
				printf("\n\n%.2fgrad C = %.2fgrad F\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut); // Hier wird nun das Thermostat ausgegeben, welches wir zuvor, vor der main-Funktion, erstellt haben.
				break;
			}
			/*
			In den Folgenden Zeilen wird nach dem in den oberen zeilen "if" genutzt wird, "else" verwendet.
			So fern ein Wert, in diesem Falle (für Celsius) unter -273,15, eingegeben wird, so wird "printf" ausgeführt.
			Dieser dient dazu den Text "Wert unter Nullpunkt" auszugeben.
			*/
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}
			// Umrechung von Celsius in Kelvin
		case 13:
			if (tempIn >= 0) {
				tempOut = tempIn + 273.15;
				printf("\n\n%.2fgrad C = %.2f K\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}
			// Umrechnung von Celsius in Romer
		case 14:
			if (tempIn >= 0) {
				tempOut = (tempIn * 0.52500) + 7.5;
				printf("\n\n%.2fgrad C = %.2f R\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}
			// Umrechnung Fahrenheit in Celsius
		case 21:
			if (tempIn >= 0) {
				tempOut = (tempIn - 32.0) / 1.8;
				printf("\n\n%.2fgrad F = %.2fgrad C\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}

			// Umrechnen von Fahrenheit in Kelvin
		case 23:
			if (tempIn >= 0) {
				tempOut = (tempIn + 459.67) / 1.8;
				printf("\n\n%.2fgrad F = %.2fK\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}

			//Umrechnung von Fahrenheit in Romer
		case 24:
			if (tempIn >= 0) {
				tempOut = (tempIn - 32.0) * 0.29167 + 7.5;
				printf("\n\n%.2fgrad F = %.2f R\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}
			// Umrechnung von Kelvin in Celsius
		case 31:
			if (tempIn >= 0) {
				tempOut = tempIn - 273.15;
				printf("\n\n%.2fK = %.2fgrad C\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}

			// Umrechnung von Kelvin in Fahrenheit
		case 32:
			if (tempIn >= 0) {
				tempOut = (tempIn * 1.8) - 459.67;
				printf("\n\n%.2fK = %.2fgrad F\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");

			}

			// Umrechnung von Kelvin in Romer
		case 34:
			if (tempIn >= 0) {
				tempOut = (tempIn - 273.15) * 0.52500 + 7.5;
				printf("\n\n%.2fgrad K = %.2f R\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
				break;
			}
			else {
				printf("Wert unter Nullpunkt.");
				break;
			}
			// Umrechnung von Réaumur in Celsius
		case 41:
			if (tempIn >= 0) {
				tempOut = (tempIn * -7.5) / 0.52500;
				printf("\n\n%.2fR = %.2fgrad C\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);
			}
			else {
				printf("Wert unter Nullpunkt.");
			}
			break;
			// Umrechnung von Réaumur in Kelvin
		case  43:
			if (tempIn >= 0) {
				tempOut = (tempIn - 7.5) / 52500 + 273.15;
				printf("\n\n%.2fR = %.2fgrad K\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);

			}
			else {
				printf("Wert unter Nullpunkt.");
			}
			break;

			// Umrechnung von Réaumur in Fahrenheit
		case 42:
			if (tempIn >= 0) {
				tempOut = (tempIn - 7.5) * 3.4286 + 32;
				printf("\n\n%.2fR = %.2fgrad F\n\n", tempIn, tempOut);
				draw_thermostat(tempOut, unitOut);

			}
			else {
				printf("Wert unter Nullpunkt.");
			}
			break;

		}
		printf("\n\nerneute Berechnung? (j/n)"); // Hier ist nun die Berechnung sowie die Anzeige des Thermostats vorbei. Desweiteren wird gefragt ob eine erneute Rechnung gewünscht sei
		scanf("%c", &response);
		while (getchar() != '\n');
	} while (response == 'j' || response == 'J');

}