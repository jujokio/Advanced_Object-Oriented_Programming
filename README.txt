Tässä työssä on käytetty hyväksi tiedostoa Catch.hpp
https://github.com/philsquared/Catch

VT 1 tehtävänanto:

Kirjoita ohjelma, joka tulostaa matriisin. 
Matriisin alkiot ovat muotoa ij, missä i on 
rivinumero ja j sarakenumero. Käyttäjä voi
 antaa matriisin rivien määrän ja sarakkeiden 
määrän komentoriviparametreina. Mikäli parametri 
puuttuu, ohjelma kysyy sitä käyttäjältä. 
Toteuta matriisin (tai sen osan) tulostus 
funktio(i)na, jo(t)ka toteutetaan erillisessä 
tiedostossa.

VT 2 Tehtävänanto:

Toteuta 2x2-neliömatriisi-luokka, SquareMatrix, 
sekä kokonaisluvun kapseloiva matriisin alkio -luokka, 
IntElement. Toteuta IntElement-luokalle myös 
laskuoperaattorit +, -, * sekä tulostusoperaattori 
<<. Luokkiin saa toteuttaa muitakin funktioita. 
Kirjoita Doxygen-dokumentaatio ja catch-yksikkötestit 
luokkien jäsenfunktioille. 

VT 3 Tehtävänanto:

Toteuta neliömatriisi-luokka, SquareMatrix, 
sekä kokonaisluvun kapseloiva matriisin alkio -luokka,
IntElement. Parametrillisen muodostimen tulee heittää 
poikkeus, mikäli parametri ei ole neliömatriisi. 
Luokkiin saa toteuttaa muitakin funktioita. 
Käytä iteraattoreita, joukkopohjaisia silmukoita, 
standardikirjaston algoritmeja sekä lambda-funktioita. 
Kirjoita Doxygen-dokumentaatioa ja catch-yksikkötestit 
luokkien jäsenfunktioille. Ohjelman tulee 
käynnistettäessä suorittaa vain pelkät testit esimerkin 
mukaisesti. Main-funktiota ei siten tarvitse toteuttaa, 
jos määrittelee catchin vakion CATCH_CONFIG_MAIN. 


VT 4 Tehtävänanto:

Muuta edellisen viikkotehtävän neliömatriisi-luokkaa, 
SquareMatrix, sillä tavalla että IntElement-olioiden 
sijaan std::vectoriin tallennetaan osoittimet näihin 
olioihin. Älykkäiden osoittimien (smart pointers) 
käyttö on suositeltavaa. Toteuta parametrillinen 
muodostin, joka tekee neliömatriisin 
merkkijonoesityksestä. Toteuta myös kopio- ja 
siirtokopiomuodostimet, sijoitus- ja 
siirtosijoitusoperaattorit sekä clone()-funktio 
IntElement-luokkaan. Funktio clone() toimii kuten 
kopiomuodostin, mutta palauttaa osoittimen luotuun 
olioon. Kirjoita Doxygen-dokumentaatio ja catch-yksikkötestit 
luokkien jäsenfunktioille. Tarkastele testien koodikattavuutta 
gcov-työkalulla. Aja cppcheck, ja pyri korjamaan sen raportoimat 
ongelmat. Varmista valgrindillä tai vastaavalla työkalulla, 
ettei ohjelmassasi ole muistivuotoja. 


VT 5 Tehtävänanto:

Toteuta ConcreteSquareMatrix-, SymbolicSquareMatrix-, Element-, 
IntElement- ja VariableElement-luokat, eli muokkaa edellistä 
viikkotehtävää sillä tavalla, että matriisin alkio voi olla 
luku (IntElement) tai muuttuja (VariableElement) 
(muuttujat ovat käytännössä kirjainmerkkejä). Symbolisessa 
matriisissa voi siis käyttää muuttujia tyyliin [[1,x][y,2]], 
konkreettinen matriisi vastaa edellisen viikkotehtävän matriisia. 
Muuttujat ja niiden arvot tallennetaan valuaatio-olioon, joka 
toteutetaan std::map-tietorakenteena. Kun alkio evaluoidaan 
valuaatiota käyttäen, tuloksena saadaan kokonaisluku 
(tai poikkeus, jos muuttujaa ei ole määritelty). Toteuta 
alkio-luokkiin Prototype-suunnittelumallin mukainen clone()-funktio 
ja Element-luokalle tulostusoperaattori. Vastaavasti kun symbolinen 
matriisi evaluoidaan valuaatiota käyttäen, tuloksena saadaan 
konkreettinen matriisi tai poikkeus

VT 6 Tehtävänanto:

Täydennä edellisen viikon tehtävää sillä tavalla, että 
symbolisista matriiseista voi muodostaa laskulausekkeita 
peruslaskutoimituksille. Käytä Composite- ja 
Interpreter-suunnittelumalleja kaavion mukaisesti. Toisin sanoen 
luo abstrakti SquareMatrix-kantaluokka, ja kuvaa laskulausekkeet 
CompositeSquareMatrix-aliluokan olioina. Kun tällaisen lausekkeen 
arvo lasketaan (evaluoidaan) kutsumalla evaluate-funktiota 
rekursiivisesti, muuttujat korvataan kokonaislukuarvoilla valuaation 
mukaisesti ja laskuoperaatiot suoritetaan, jolloin tuloksena on 
konkreettinen kokonaislukumatriisi (tai poikkeus). Toteuta myös 
tulostusoperaattori SquareMatrix-luokkalle. Tee lisäksi 
ConcreteSquareMatrix-luokalle muodostin, joka luo satunnaisesti 
alustetun neliömatriisin. Tutki ohjelman suorituskykyä suorittamalla 
kertolaskuja suurille matriiseille. Tutki gprof-ohjelman avulla, 
miten ohjelman suorituskykyä voisi parantaa.


VT 7 Tehtävänanto:

Korvaa edellisen tehtävän IntElement ja VariableElement malliluokalla 
TElement<T>, ja määrittele IntElement- ja VariableElement- luokat sen 
avulla:

	using IntElement = TElement<int>;
	using VariableElement = TElement<char>;

Tee sama ConcreteSquareMatrix- and SymbolicSquareMatrix-luokille, eli 
määrittele malliluokka ElementarySquareMatrix<T> ja ConcreteSquareMatrix 
ja SymbolicSquareMatrix sen avulla

	using ConcreteSquareMatrix = ElementarySquareMatrix<IntElement>;
	using SymbolicSquareMatrix = ElementarySquareMatrix<Element>;

Tee matriisilaskimelle käyttöliittymä. Matriisilaskin koostuu 
matriisipinosta (std::stack) (aluksi tyhjä) sekä valuaatiosta 
(aluksi tyhjä) ja toimii seuraavasti:

	Käyttäjä voi antaa minkä tahansa symbolisen nxn-neliömatriisin 
	muodossa "[[1,y][2,x]]", jolloin matriisi tallennetaan pinoon.

    	Käyttäjä voi syöttää laskuoperaation '+', '-' tai '*', jolloin 
	kaksi päällimmäistä matriisia otetaan pinosta, niistä 
	muodostetaan syötteen mukainen matriisilaskukaava 
	(CompositeSquareMatrix), ja kaava tulostetaan näytölle ja
	 tallennetaan pinoon.

    	Käyttäjä voi asettaa minkä tahansa muuttujan arvon syöttämällä 
	muotoa "x=5" olevan lausekkeen, jolloin muuttujan x arvo 
	valuaatiossa asetetaan arvoon 5.
   
	Kun käyttäjä antaa yhtäsuuruusmerkin '=', pinossa päällimmäisenä 
	oleva matriisi evaluoidaan ja tulos näytetään käyttäjälle. 
	Pinosta ei poisteta mitään.
    
	Kun käyttäjä syöttää "quit", ohjelma päättyy.
