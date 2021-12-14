#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

// Tiedot luokka
// Hallitsee auton perustietoja
class Statistics
{
public:
  // Parametriton rakentaja
  Statistics()
  {
  }

  // Parametriton tuhoaja
  virtual ~Statistics()
  {
  }

  // Kopiorakentaja
  Statistics(const Statistics &pStatistics) = default;

  // Parametrillinen rakentaja (kilometrit ja kulutus annetaan oliota luodessa)
  Statistics(const float pKaupunki, const float pMaantie)
  {
    setKulutus(pKaupunki, pMaantie);
  }

  // Setter for kulutus
  void setKulutus(const float pKaupunki, const float pMaantie)
  {
    this->kulutus[0] = pKaupunki;
    this->kulutus[1] = pMaantie;
  }

  // Getter for kulutus
  float getKulutus(const int index) const
  {
    if (index == 0 || index == 1)
    {
      return this->kulutus[index];
    }
    else
    {
      throw std::invalid_argument("invalid index");
    }
  }

private:
  float kulutus[2];
};

// Moottori luokka
// Hallitsee auton moottorin tietoja
class Engine
{
public:
  // Parametriton rakentaja
  Engine()
  {
  }

  // Parametriton tuhoaja
  virtual ~Engine()
  {
  }

  // Kopiorakentaja
  Engine(const Engine &pEngine) = default;

  // Parametrillinen rakentaja (litramaara ja hevosvoimat annetaan oliota luodessa)
  Engine(const float pLitramaara, const int pHevosvoimat)
  {
    setLitramaara(pLitramaara);
    setHevosvoimat(pHevosvoimat);
  }

  // Setter for litramaara
  void setLitramaara(const float pLitramaara)
  {
    this->litramaara = pLitramaara;
  }

  // Getter for litramaara
  float getLitramaara() const
  {
    return this->litramaara;
  }

  // Setter for hevosvoimat
  void setHevosvoimat(const int pHevosvoimat)
  {
    this->hevosvoimat = pHevosvoimat;
  }

  // Getter for hevosvoimat
  int getHevosvoimat() const
  {
    return this->hevosvoimat;
  }

private:
  float litramaara;
  int hevosvoimat;
};

class Vehicle
    : public Engine,
      public Statistics
{
public:
  // Parametriton rakentaja
  Vehicle()
  {
  }

  // Parametriton tuhoaja
  // Derived class -> virtual
  virtual ~Vehicle()
  {
  }

  // Kopiorakentaja
  Vehicle(const Vehicle &pVehicle) = default;

  // Parametrillinen rakentaja (merkki, malli ja muut annetaan oliota luodessa)
  Vehicle(
      const std::string pMerkki, const std::string pMalli, const int pVuosimalli,
      const float pLitramaara, const int pHevosvoimat,
      const float pKaupunki, const float pMaantie)
      : Engine(pLitramaara, pHevosvoimat), Statistics(pKaupunki, pMaantie)
  {
    setMerkki(pMerkki);
    setMalli(pMalli);
    setVuosimalli(pVuosimalli);
  }

  // Setter for merkki
  void setMerkki(const std::string pMerkki)
  {
    this->merkki = pMerkki;
  }

  // Getter for merkki
  std::string getMerkki() const
  {
    return this->merkki;
  }

  // Setter for malli
  void setMalli(const std::string pMalli)
  {
    this->malli = pMalli;
  }

  // Getter for malli
  std::string getMalli() const
  {
    return this->malli;
  }

  // Setter for vuosimalli
  void setVuosimalli(const int pVuosimalli)
  {
    this->vuosimalli = pVuosimalli;
  }

  // Getter for malli
  int getVuosimalli() const
  {
    return this->vuosimalli;
  }

  // Tulosta koko olio
  // ja siihen liittyvät aliluokat
  // get - funktioilla
  void tulostaTiedot() const
  {
    // Vehicle object
    std::cout << "\n----------" << std::endl;
    std::cout << "Make: " << this->getMerkki() << std::endl;
    std::cout << "Model: " << this->getMalli() << std::endl;
    std::cout << "Year: " << std::to_string(this->getVuosimalli()) << std::endl;

    // VehicleEngine object
    std::cout << "Liters: " << std::to_string(this->getLitramaara()) << std::endl;
    std::cout << "Hp: " << std::to_string(this->getHevosvoimat()) << std::endl;

    // VehicleStatistics object
    std::cout << "Economy: " << std::to_string(this->getKulutus(0)) << ", " << std::to_string(this->getKulutus(1)) << std::endl;
  }

private:
  std::string merkki;
  std::string malli;
  int vuosimalli;
};

// Hallitsee koko autot - vektoria
// Lisää, muokkaa, hakee, lajittelee ja poistaa
// autot vektoria
class VehicleSingleton final
{
public:
  // Instanssi
  static std::shared_ptr<VehicleSingleton> getInstance();

  // Lajittelu vuosimallin perusteella
  static bool sortByVuosimalli(const std::shared_ptr<Vehicle> &vm1, const std::shared_ptr<Vehicle> &vm2);
  // Tuhoaa ja tyhjentää koko vektorin
  // Olioiden tuhoajat kutsutaan automaattisesti samalla
  void clearVehicles();
  void addVehicle(const Vehicle &aVehicle);
  void getVehicle(const std::string &aQuery, const int &aMode);
  void deleteVehicle(const std::string &aMalli);
  void modifyVehicle(const std::string &aMalli, const int &aHevosvoimat, const int &aKaupunki, const int &aMaantie);
  void printVehicles(const int &aChoice);

private:
  static std::shared_ptr<VehicleSingleton> instance;

  VehicleSingleton() = default;
  VehicleSingleton(const VehicleSingleton &aVehicleSingleton) = delete;
  std::vector<std::shared_ptr<Vehicle>> vehicles;
};

std::shared_ptr<VehicleSingleton> VehicleSingleton::instance = nullptr;

// Luo uusi instanssi jos ei ole olemassa
std::shared_ptr<VehicleSingleton> VehicleSingleton::getInstance()
{
  if (!instance)
  {
    instance = std::shared_ptr<VehicleSingleton>(new VehicleSingleton());
    return instance;
  }

  return instance;
}

// Luo uusi ajoneuvo jos se ei ole jo olemassa
void VehicleSingleton::addVehicle(const Vehicle &aVehicle)
{
  std::string malli = aVehicle.getMalli();
  bool isValid = true;

  for (auto &vehicle : vehicles)
  {
    if (vehicle->getMalli() == malli)
    {
      isValid = false;
    }
  }

  // Tarkista onko auto jo olemassa
  if (isValid)
  {
    std::cout << "\nVehicle added\n";
    vehicles.push_back(std::make_shared<Vehicle>(aVehicle));
  }
  else
  {
    std::cout << "\nVehicle already exists!\n";
  }
}

// Hae olemassaoleva auto ja tulosta
// 0 merkki, 1 malli ja muu vuosiluku
void VehicleSingleton::getVehicle(const std::string &aQuery, const int &aMode)
{
  for_each(vehicles.begin(), vehicles.end(), [aQuery, aMode](auto &h)
           {
             if (aMode == 1)
             {
               if (h->getMerkki() == aQuery)
               {
                 h->tulostaTiedot();
               }
             }
             else if (aMode == 2)
             {
               if (h->getMalli() == aQuery)
               {
                 h->tulostaTiedot();
               }
             }
             else
             {
               if (h->getVuosimalli() == stoi(aQuery))
               {
                 h->tulostaTiedot();
               }
             }
           });
}

void VehicleSingleton::deleteVehicle(const std::string &aMalli)
{
  int index = 0;

  for (auto &vehicle : vehicles)
  {
    index++;

    if (vehicle->getMalli() == aMalli)
    {
      vehicles.erase(vehicles.begin() + (index - 1));
    }
  }
}

void VehicleSingleton::modifyVehicle(const std::string &aMalli, const int &aHevosvoimat, const int &aKaupunki, const int &aMaantie)
{
  for_each(vehicles.begin(), vehicles.end(), [aMalli, aHevosvoimat, aKaupunki, aMaantie](auto &h)
           {
             if (h->getMalli() == aMalli)
             {
               h->setHevosvoimat(aHevosvoimat);
               h->setKulutus(aKaupunki, aMaantie);

               std::cout << "\nModified vehicle\n";
               h->tulostaTiedot();
             }
           });
}

// Compares two Vehicle Vuosimalli
bool VehicleSingleton::sortByVuosimalli(const std::shared_ptr<Vehicle> &vm1, const std::shared_ptr<Vehicle> &vm2)
{
  return (vm1->getVuosimalli() < vm2->getVuosimalli());
}

// Clear all vehicles and free memory
void VehicleSingleton::clearVehicles()
{
  vehicles.clear();
}

// Tulosta kaikki ajoneuvot järjestyksessä
void VehicleSingleton::printVehicles(const int &aChoice)
{
  if (aChoice && aChoice == 2)
  {
    std::sort(vehicles.begin(), vehicles.end(), sortByVuosimalli);
  }

  for_each(vehicles.begin(), vehicles.end(), [](auto &h)
           { h->tulostaTiedot(); });
}

int main()
{
  // Use a true boolean to loop menu
  bool menu = true;

  // If boolean is true
  // loop through the code
  while (menu)
  {
    // Give users a choice
    int choice;
    std::cout << "\n1. Input new vehicle\n";
    std::cout << "2. Modify existing vehicle\n";
    std::cout << "3. Delete existing vehicle\n";
    std::cout << "4. Show vehicles\n";
    std::cout << "5. Exit the application\n"
              << std::endl;

    // Get user input
    // using a try catch for correct input
    try
    {
      std::cout << ": ";
      std::cin >> choice;
    }
    catch (const std::exception &e)
    {
      // Exit the application on wrong choice
      std::cerr << e.what() << '\n';
      choice = 5;
    }

    // Switch case for choices
    switch (choice)
    {
    case 1:
      try
      {
        std::string malli, merkki;
        int vuosimalli, hevosvoimat;
        float litramaara, kulutus[2];

        std::cout << "\nMerkki (string): ";
        std::cin >> merkki;
        std::cout << "Malli (string): ";
        std::cin >> malli;
        std::cout << "Vuosimalli (int): ";
        std::cin >> vuosimalli;
        std::cout << "Litramaara (float): ";
        std::cin >> litramaara;
        std::cout << "Hevosvoimat (int): ";
        std::cin >> hevosvoimat;
        std::cout << "Kaupunki kulutus (float): ";
        std::cin >> kulutus[0];
        std::cout << "Maantie kulutus (float): ";
        std::cin >> kulutus[1];

        VehicleSingleton::getInstance()->addVehicle(Vehicle{
            merkki, malli, vuosimalli,
            litramaara, hevosvoimat,
            kulutus[0], kulutus[1]});
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }

      break;
    case 2:
      try
      {
        std::string merkki, malli;
        int hevosvoimat;
        float kulutus[2];

        std::cout << "\nMalli (string): ";
        std::cin >> malli;
        std::cout << "Hevosvoimat (int): ";
        std::cin >> hevosvoimat;
        std::cout << "Kaupunki kulutus (float): ";
        std::cin >> kulutus[0];
        std::cout << "Maantie kulutus (float): ";
        std::cin >> kulutus[1];

        VehicleSingleton::getInstance()->modifyVehicle(malli, hevosvoimat, kulutus[0], kulutus[1]);
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }

      break;
    case 3:
      try
      {
        std::string aMalli;
        std::cout << "Insert malli (string): ";
        std::cin >> aMalli;

        VehicleSingleton::getInstance()->deleteVehicle(aMalli);

        std::cout << "\nVehicle deleted\n";
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }

      break;
    case 4:
      try
      {
        int fourthChoice;
        std::string aQuery;
        std::cout << "\n1: Get all vehicles\n2: Get a vehicle using merkki, malli or vuosimalli\n";
        std::cout << "(int): ";
        std::cin >> fourthChoice;

        switch (fourthChoice)
        {
        case 1:
          int fourthFirstChoice;
          std::cout << "\n1: Don't use sort\n2: Sort using vuosimalli\n";
          std::cout << "(int): ";
          std::cin >> fourthFirstChoice;
          VehicleSingleton::getInstance()->printVehicles(fourthFirstChoice);
          break;
        case 2:
          int fourthSecondChoice;
          std::cout << "\n1: Get using merkki\n2: Get using malli\n3: Get using vuosimalli\n";
          std::cout << "(int): ";
          std::cin >> fourthSecondChoice;

          switch (fourthSecondChoice)
          {
          case 1:
            std::cout << "\nMerkki\n";
            std::cout << "(string): ";
            std::cin >> aQuery;

            VehicleSingleton::getInstance()->getVehicle(aQuery, 1);
            break;
          case 2:
            std::cout << "Malli\n";
            std::cout << "(string): ";
            std::cin >> aQuery;

            VehicleSingleton::getInstance()->getVehicle(aQuery, 2);
            break;
          case 3:
            std::cout << "Vuosimalli\n";
            std::cout << "(int): ";
            std::cin >> aQuery;

            VehicleSingleton::getInstance()->getVehicle(aQuery, 3);
            break;
          default:
            std::cout << "Invalid choice\n";
            break;
          }
          break;
        default:
          std::cout << "Invalid choice\n";
          break;
        }
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }

      break;
    default:
      std::cout << "\nExiting application..." << std::endl;
      menu = false;
      break;
    }
  }

  VehicleSingleton::getInstance()->clearVehicles();

  return EXIT_SUCCESS;
}
