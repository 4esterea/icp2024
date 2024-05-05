Jednoduchý 2D simulátor mobilních robotů

Autoři: Sniehovskyi Nikita (xsnieh00), Zhdanovich Iaroslav (xzhdan00)


Spouštění: make run


Kratký popis:
Simulátor mobilních robotů je program, který umožňuje simulovat pohyb mobilních robotů v 2D prostoru. Roboti se pohybují v prostoru a vyhýbají se překážkám.
Různé parametry simulace, jako například rychlost robotů, jejich pozice, velikost prostoru a další, lze nastavit v GUI.


Pokyny pro ovladání GUI:

- Pomoci tlačítka "Edit" lze přepnout do režimu editace.
- Pomoci tlačítka "Start" lze spustit simulaci.
- Pomoci tlačítka "Pause" lze pozastavit simulaci.
- Pomoci tlačítka "Play" lze pokračovat v simulaci.
- Pomoci tlačítka "Stop" lze zastavit simulaci.
- Pomoci tlacitek "Load" a "Save" lze nahrát a uložit konfiguraci simulace.
- Pomoci tlačítka "New" lze vytvořit novou konfiguraci simulace.

--Režim editace:

- Levým tlačítkem myši v lze přidat vybrané objekty do prostoru.
- Dvojitým kliknutím levým tlačítkem myši na objekt lze změnit jeho vlastnosti.
- Dvojitým kliknutím pravým tlačítkem myši na objekt lze objekt smazat.
- Dvojitým kliknutím levým tlačítkem myši a přetažením lze objekt přesunout.


Implementační detaily:

- Pro implementaci byl použit jazyk C++ a knihovna Qt.
- Vlastní model aplikace je oddělen od GUI: implementace modelu je v src/common, src/headers, a src/interfaces, implementace elementů GUI je v src/ui.
- Na vytvoření GUI byla použita IDE Qt Creator.