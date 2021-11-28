#include <string.h>
class Coche
{
/*! Posibles estados del coche */
enum status { 
_status_ok, /*!< Situación normal */
_status_broken, /*!< El coche debe ir al taller */
_status_repairing, /*!< El coche está siendo reparado en el taller 
*/
_status_ready /*!< El coche ha sido reparado y el dueño puede 
recogerlo */
};
private:
std::string _license;
status _status;
unsigned int price;
public:
Coche( std::string license );
virtual ~Coche(void);
int getPrice();
// status methods
bool isOk();
void toggleOk();
bool isBroken();
void toggleBroken();
bool isRepairing();
void toggleRepairing();
bool isReady();
void toggleReady();
};
#include "Coche.h"
#include "Cliente.h"
class Concesionario
{
private:
std::vector< Coche* > _stock;
std::vector< Coche* > _repairing;
public:
Concesionario(void);
~Concesionario(void);
/*!
\brief Añade un nuevo coche al inventario
@returns false si el coche ya estaba en el inventario o en el 
taller
*/
bool addCarToStock( Coche* car );
/*!
\brief Vende un coche del inventario al usuario y lo añade a 
su lista de coches
Tras ejecutar esta función se quita el coche del inventario
@returns false si el coche no está en inventario o el cliente 
no puede pagarlo
*/
bool sellCar( Cliente* client, std::string license );
/*!
\brief Toma un coche averiado del cliente y lo añade al taller
@returns false si el cliente no tiene ese coche o el coche no 
está averiado
*/
bool checkCarInGarage( Cliente* client, std::string license );
/*!
\brief Toma un coche listo del taller y se lo devuelve al 
cliente
@returns false si el coche no está en el taller y en estado de
listo
*/
bool retrieveCarFromGarage( Cliente* cliente, std::string license );
};
