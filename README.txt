T�ss� ty�ss� on k�ytetty hyv�ksi tiedostoa Catch.hpp
https://github.com/philsquared/Catch

VT 1 teht�v�nanto:

Kirjoita ohjelma, joka tulostaa matriisin. 
Matriisin alkiot ovat muotoa ij, miss� i on 
rivinumero ja j sarakenumero. K�ytt�j� voi
 antaa matriisin rivien m��r�n ja sarakkeiden 
m��r�n komentoriviparametreina. Mik�li parametri 
puuttuu, ohjelma kysyy sit� k�ytt�j�lt�. 
Toteuta matriisin (tai sen osan) tulostus 
funktio(i)na, jo(t)ka toteutetaan erillisess� 
tiedostossa.

VT 2 Teht�v�nanto:

Toteuta 2x2-neli�matriisi-luokka, SquareMatrix, 
sek� kokonaisluvun kapseloiva matriisin alkio -luokka, 
IntElement. Toteuta IntElement-luokalle my�s 
laskuoperaattorit +, -, * sek� tulostusoperaattori 
<<. Luokkiin saa toteuttaa muitakin funktioita. 
Kirjoita Doxygen-dokumentaatio ja catch-yksikk�testit 
luokkien j�senfunktioille. 

VT 3 Teht�v�nanto:

Toteuta neli�matriisi-luokka, SquareMatrix, 
sek� kokonaisluvun kapseloiva matriisin alkio -luokka,
IntElement. Parametrillisen muodostimen tulee heitt�� 
poikkeus, mik�li parametri ei ole neli�matriisi. 
Luokkiin saa toteuttaa muitakin funktioita. 
K�yt� iteraattoreita, joukkopohjaisia silmukoita, 
standardikirjaston algoritmeja sek� lambda-funktioita. 
Kirjoita Doxygen-dokumentaatioa ja catch-yksikk�testit 
luokkien j�senfunktioille. Ohjelman tulee 
k�ynnistett�ess� suorittaa vain pelk�t testit esimerkin 
mukaisesti. Main-funktiota ei siten tarvitse toteuttaa, 
jos m��rittelee catchin vakion CATCH_CONFIG_MAIN. 


VT 4 Teht�v�nanto:

Muuta edellisen viikkoteht�v�n neli�matriisi-luokkaa, 
SquareMatrix, sill� tavalla ett� IntElement-olioiden 
sijaan std::vectoriin tallennetaan osoittimet n�ihin 
olioihin. �lykk�iden osoittimien (smart pointers) 
k�ytt� on suositeltavaa. Toteuta parametrillinen 
muodostin, joka tekee neli�matriisin 
merkkijonoesityksest�. Toteuta my�s kopio- ja 
siirtokopiomuodostimet, sijoitus- ja 
siirtosijoitusoperaattorit sek� clone()-funktio 
IntElement-luokkaan. Funktio clone() toimii kuten 
kopiomuodostin, mutta palauttaa osoittimen luotuun 
olioon. Kirjoita Doxygen-dokumentaatio ja catch-yksikk�testit 
luokkien j�senfunktioille. Tarkastele testien koodikattavuutta 
gcov-ty�kalulla. Aja cppcheck, ja pyri korjamaan sen raportoimat 
ongelmat. Varmista valgrindill� tai vastaavalla ty�kalulla, 
ettei ohjelmassasi ole muistivuotoja. 


VT 5 Teht�v�nanto:

Toteuta ConcreteSquareMatrix-, SymbolicSquareMatrix-, Element-, 
IntElement- ja VariableElement-luokat, eli muokkaa edellist� 
viikkoteht�v�� sill� tavalla, ett� matriisin alkio voi olla 
luku (IntElement) tai muuttuja (VariableElement) 
(muuttujat ovat k�yt�nn�ss� kirjainmerkkej�). Symbolisessa 
matriisissa voi siis k�ytt�� muuttujia tyyliin [[1,x][y,2]], 
konkreettinen matriisi vastaa edellisen viikkoteht�v�n matriisia. 
Muuttujat ja niiden arvot tallennetaan valuaatio-olioon, joka 
toteutetaan std::map-tietorakenteena. Kun alkio evaluoidaan 
valuaatiota k�ytt�en, tuloksena saadaan kokonaisluku 
(tai poikkeus, jos muuttujaa ei ole m��ritelty). Toteuta 
alkio-luokkiin Prototype-suunnittelumallin mukainen clone()-funktio 
ja Element-luokalle tulostusoperaattori. Vastaavasti kun symbolinen 
matriisi evaluoidaan valuaatiota k�ytt�en, tuloksena saadaan 
konkreettinen matriisi tai poikkeus

VT 6 Teht�v�nanto:

T�ydenn� edellisen viikon teht�v�� sill� tavalla, ett� 
symbolisista matriiseista voi muodostaa laskulausekkeita 
peruslaskutoimituksille. K�yt� Composite- ja 
Interpreter-suunnittelumalleja kaavion mukaisesti. Toisin sanoen 
luo abstrakti SquareMatrix-kantaluokka, ja kuvaa laskulausekkeet 
CompositeSquareMatrix-aliluokan olioina. Kun t�llaisen lausekkeen 
arvo lasketaan (evaluoidaan) kutsumalla evaluate-funktiota 
rekursiivisesti, muuttujat korvataan kokonaislukuarvoilla valuaation 
mukaisesti ja laskuoperaatiot suoritetaan, jolloin tuloksena on 
konkreettinen kokonaislukumatriisi (tai poikkeus). Toteuta my�s 
tulostusoperaattori SquareMatrix-luokkalle. Tee lis�ksi 
ConcreteSquareMatrix-luokalle muodostin, joka luo satunnaisesti 
alustetun neli�matriisin. Tutki ohjelman suorituskyky� suorittamalla 
kertolaskuja suurille matriiseille. Tutki gprof-ohjelman avulla, 
miten ohjelman suorituskyky� voisi parantaa.


VT 7 Teht�v�nanto:

Korvaa edellisen teht�v�n IntElement ja VariableElement malliluokalla 
TElement<T>, ja m��rittele IntElement- ja VariableElement- luokat sen 
avulla:

	using IntElement = TElement<int>;
	using VariableElement = TElement<char>;

Tee sama ConcreteSquareMatrix- and SymbolicSquareMatrix-luokille, eli 
m��rittele malliluokka ElementarySquareMatrix<T> ja ConcreteSquareMatrix 
ja SymbolicSquareMatrix sen avulla

	using ConcreteSquareMatrix = ElementarySquareMatrix<IntElement>;
	using SymbolicSquareMatrix = ElementarySquareMatrix<Element>;

Tee matriisilaskimelle k�ytt�liittym�. Matriisilaskin koostuu 
matriisipinosta (std::stack) (aluksi tyhj�) sek� valuaatiosta 
(aluksi tyhj�) ja toimii seuraavasti:

	K�ytt�j� voi antaa mink� tahansa symbolisen nxn-neli�matriisin 
	muodossa "[[1,y][2,x]]", jolloin matriisi tallennetaan pinoon.

    	K�ytt�j� voi sy�tt�� laskuoperaation '+', '-' tai '*', jolloin 
	kaksi p��llimm�ist� matriisia otetaan pinosta, niist� 
	muodostetaan sy�tteen mukainen matriisilaskukaava 
	(CompositeSquareMatrix), ja kaava tulostetaan n�yt�lle ja
	 tallennetaan pinoon.

    	K�ytt�j� voi asettaa mink� tahansa muuttujan arvon sy�tt�m�ll� 
	muotoa "x=5" olevan lausekkeen, jolloin muuttujan x arvo 
	valuaatiossa asetetaan arvoon 5.
   
	Kun k�ytt�j� antaa yht�suuruusmerkin '=', pinossa p��llimm�isen� 
	oleva matriisi evaluoidaan ja tulos n�ytet��n k�ytt�j�lle. 
	Pinosta ei poisteta mit��n.
    
	Kun k�ytt�j� sy�tt�� "quit", ohjelma p��ttyy.
