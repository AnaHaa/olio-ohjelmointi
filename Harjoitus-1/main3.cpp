#include <iostream>
using namespace std;

class Osoite
{
public:
    // Parametriton rakentaja (oletusrakentaja)
    Osoite()
    {
        std::cout << "Empty Osoite created!" << endl;
    }

    // Parametriton tuhoaja
    ~Osoite()
    {
        std::cout << "Osoite destroyed!" << endl;
    }

    // Parametrillinen rakentaja (katuosoite ja paikkakunta annetaan oliota luodessa)
    Osoite(const string setKatuosoite, const string setPaikkakunta)
    {
        std::cout << "Parameter Osoite created!" << endl;
        katuosoite = setKatuosoite;
        paikkakunta = setPaikkakunta;
    }

    // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
    Osoite(const Osoite &origin)
    {
        std::cout << "Copy Osoite created!" << endl;
        katuosoite = origin.katuosoite;
        paikkakunta = origin.paikkakunta;
    }

    // Setter for katuosoite
    void setKatuosoite(const string setKatuosoite)
    {
        katuosoite = setKatuosoite;
    }

    // Getter for katuosoite
    string getKatuosoite()
    {
        return katuosoite;
    }

    // Setter for paikkakunta
    void setPaikkakunta(const string setPaikkakunta)
    {
        paikkakunta = setPaikkakunta;
    }

    // Getter for paikkakunta
    string getPaikkakunta()
    {
        return paikkakunta;
    }

    void tulostaTiedot()
    {
        std::cout << "Osoite: " << getKatuosoite() << " " << getPaikkakunta() << endl;
    }

private:
    // Attribuutit
    string katuosoite;
    string paikkakunta;
};

class Person
{
public:
    // Parametriton rakentaja (oletusrakentaja)
    Person()
    {
        std::cout << "Empty person created!" << endl;
    }

    // Parametriton tuhoaja
    ~Person()
    {
        std::cout << "Person destroyed!" << endl;
    }

    // Parametrillinen rakentaja
    Person(const string setName, const int setAge)
    {
        std::cout << "Parameter person created!" << endl;
        name = setName;
        age = setAge;
    }

    // Parametrillinen rakentaja
    Person(const string setName, const int setAge, const string katuosoite, const string paikkakunta)
    {
        std::cout << "Parameter person created!" << endl;
        name = setName;
        age = setAge;
        osoitetieto = {katuosoite, paikkakunta};
    }

    // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
    Person(const Person &origin)
    {
        std::cout << "Copy person created!" << endl;
        name = origin.name;
        age = origin.age;
        osoitetieto = origin.osoitetieto;
    }

    // Setter for name
    void setName(const string setName)
    {
        name = setName;
    }

    // Getter for name
    string getName()
    {
        return name;
    }

    // Setter for age
    void setAge(const int setAge)
    {
        age = setAge;
    }

    // Getter for age
    int getAge()
    {
        return age;
    }

    virtual void tulostaTiedot()
    {
        std::cout << "Person: " << getName() << " " << getAge() << " " << osoitetieto.getKatuosoite() << " " << osoitetieto.getPaikkakunta() << endl;
    }

private:
    // Attribuutit
    string name;
    int age;
    Osoite osoitetieto;
};

class Opiskelija : public Person
{
public:
    // Parametriton rakentaja (oletusrakentaja)
    Opiskelija()
    {
        std::cout << "Empty Opiskelija created!" << endl;
    }

    // Parametriton tuhoaja
    ~Opiskelija()
    {
        std::cout << "Opiskelija destroyed!" << endl;
    }

    // Parametrillinen rakentaja
    Opiskelija(const string name, const int age, const int opintopisteet)
    {
        std::cout << "Parameter Opiskelija created!" << endl;
        setName(name);
        setAge(age);
        setOpintopisteet(opintopisteet);
    }

    // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
    Opiskelija(Opiskelija &origin) : Person(origin)
    {
        std::cout << "Copy person created!" << endl;
        setName(origin.getName());
        setAge(origin.getAge());
        setAge(origin.getAge());
        setOpintopisteet(origin.getOpintopisteet());
    }

    // Setter for opintopisteet
    void setOpintopisteet(const int setOpintopisteet)
    {
        opintopisteet = setOpintopisteet;
    }

    // Getter for opintopisteet
    int getOpintopisteet()
    {
        return opintopisteet;
    }

    void tulostaTiedot()
    {
        std::cout << "Opiskelija: " << getName() << " " << getAge() << " " << getOpintopisteet() << endl;
    }

private:
    // Attribuutit
    int opintopisteet;
};

int main()
{
    Person kalle("Kalle", 30);
    kalle.tulostaTiedot();
    Opiskelija pekka("Pekka", 20, 45);
    pekka.tulostaTiedot();
    Person *maija = new Person("Maija", 24, "Hämeenpuisto 20", "Tampere");
    maija->tulostaTiedot();
    delete maija;

    Person persons[10] = {
        {"1", 1},
        {"2", 2},
        {"3", 3, "3", "3"},
        {"4", 4},
        {"5", 5, "5", "5"},
        {"6", 6},
        {"7", 7, "7", "7"},
        {"8", 8},
        {"9", 9, "9", "9"},
        {"10", 10}};

    for (int i = 0; i < 10; i++)
    {
        persons[i].tulostaTiedot();
    }

    Person *test = new Opiskelija("Menetan opintopisteet", 20, 45);
    test->tulostaTiedot();

    /*  Kysymys: Jos osoittimen takana oleva henkilö on opiskelija, kutsutaanko tällöin henkilön vain
    *   opiskelijan tulostaTiedot() -metodia? Miten virtual -sanan käyttö kantaluokassa metodin edessä
    *   vaikuttaa tilanteeseen ja miksi?
    *
    *   Vastaus: Kutsutaan kantaluokan, eli henkilön tulostaTiedot(), joka johtaa slice - tapaukseen
    *   Eli opiskelija - luokan dataa menetetään, tässä tapauksessa opintopisteet.
    *   Virtual taas estää tapahtuman ja sallii opiskelija - luokan tulostaTiedot() tapahtuvan
    */

    return 0;
}