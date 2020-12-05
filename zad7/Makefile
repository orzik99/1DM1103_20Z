all:
	cc baza.c zad7.c -o mydb 

test_student: all
	./mydb baza.csv add_student testowy uczen 12345678 test@test

test_przedmiot: all
	./mydb baza.csv add_przedmiot przed_testowy 21312TEST 2020Z


test_ocena: all
	./mydb baza.csv add_ocena 12341414 2115TEST 5.0 test_wow