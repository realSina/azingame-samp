/**
*
* Include global globalvars.inc
*
*/

#define NOEXISTE (-1)

#define MYSQL_HOST "localhost"
#define MYSQL_USER "user"
#define MYSQL_PASS ""
#define MYSQL_DB   "osrp"

#define MAX_KEYS_PER_PLAYER 10
#define MAX_PROPIOS 5
#define MAX_PRESTADOS 5

#define MAX_MUEBLES_PER_PLAYER 5

// OBJECTS ATTACH
#define TOOLS_SLOT 0  // para la palanca, destornillador, etc
#define INDEX_LASER 0 // para las armas
#define GAFAS_SLOT 3 // gafas
#define CASCO_SLOT 2 // cascos
#define BANDANAS_SLOT 1 // bandanas
#define INDEX_NIEVE 4 // para el attached

// PRESSED(keys)
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
	
// RELEASED(keys)
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

enum pInfo
{

	//---[LLAVES]---
	pPCarKey[MAX_PROPIOS],  // Llaves de coche del jugador propias
	pPCochePrestado[MAX_PRESTADOS],  // Llaves de coche del jugador prestadas
	pPCocheTemporal, // Furgoneta de armas
	pPbiskey, // Llave del negocio
	pPhousekey, // Llave de la casa
	//---[INTRO]---
	bool:SpawnState,
    Float:SpawnAngle,
    SpawnTimer,
	//---[AJAILS]---
	pJailed, // 1 - IC  // 2 - OOC
	pJailTime, // en minutos!!
	//---[CUENTAS]---
	pTut, // Tutorial hecho? 0 - NO | 1 - SI
	pAdvertencias, //Nº de advertencias
	//---[GENERALES]---
	pFixDeathCar,
	pLoteria,
	pAme[128],
	Float:pArmor,
	pMinuto,
	pHora,
	pMenu,
	pDocumentacion,
	pSeguroMedico,
	pAge, // Edad del jugador
	pSex, // Sexo del jugador -> 1 - Masculino // 2 - Femenino
	pAdmin, // Nivel de administrador
	pAdminDuty, // Si esta en adminservicio
	pHidePms, // con valor 1-MP's off
	pBigEars, // con valor 1, lees todos los mps
	pBigAntena, // con valor 1, lees todos los sms
	pPmEspera, // Esperando para volver a mandar otro privado
	pDuty, // Si esta de servicio
	pRespeto, // Cantidad de respeto que tiene el jugador
	pMember, // Faccion a la que pertenece
	pRank, // Rango que tiene en la faccion
	pJob, // Trabajo que desempeña
	pBank, // Dinero que tiene en el banco
	pPnumber[2], // Numeros de telefono
	pPTelEstado, // Apagado = 0, Encendido = 1 [Premiums]
	pUsandoTelefono,
	pIncomingCall,
	pTimerCall,
	pFacturaTelefono,
	pNotificaciones,
	pFrecuencia,
	pMiFrecuencia,
	pWalkies,
	pSkin, // Skin del jugador
	pCarLic,  // Licencia de conduccion 0 - no tiene / 1 - la tiene / 2 - tiene el teorico
	pCarLicPoints,  // Puntos del carnet de conducir.
	pFlyLic,  // Licencia de aviacion
	pBoatLic,  // Licencia de navegacion
	pAutoescCP, // Checkpoint que el jugador esta haciendo en el practico
	pAutoescVeh, // ID del vehiculo que esta usando para examinarse
	pAutoescTimer, // Timer utilizados en el sistema de la autoescuela
	Text3D:pAutoescText3d, // Texto 3d para el sistema de la autoescuela
	EnClase, // Dice que carnet se esta sacando (0-Nada,1-CocheTeorico,2-CochePractico,3-Barco,4-Vuelo)
	PreguntaID, // Pregunta a la que esta contestando en el test teorico
	//--[VARIABLES DE POSICION]--
	Float:pPos_x,
	Float:pPos_y,
	Float:pPos_z,
	Float:pAngulo,
	Float:pTmpSpawnx,
	Float:pTmpSpawny,
	Float:pTmpSpawnz,
	pTmpVw,
	pTmpInt,
	pInt, // Interior del jugador
	pVw, // Virtual World del jugador
	pNegocio, // Negocio en el que se encuentra
    pHot, //Hotel en el que se encuentra (no es lo mismo que pHotelEntered)
	pHotelEntered, // Hotel donde ha entrado (Reutilizacion del Elevador)
	//--[INVENTARIO]--
	pDrogaP[3], //preparada       |  [0]: maria
    pDrogaNP[2], //no preparada   |  [1]: coca
	pSemillas[2], //semilla       |  [2]: crack
	pParafernalia[2],
	pConsumos[3],
	pTmpConsumos[3],
	pAbstinencia,
	pConsumoTimer,
	pPhonebook, // Agenda telefonica
	pDado, // Dado
	pCartas,
	pEncendedor, // Encendedor
	pCigarrillos, // Cigarillos
	pCascos,
	pLataFuel,
	SpecID,
	SpecType,
	pHide,
	pDudaid,
	pReporting,
	pMarcado,
	pMultaMoney, // Dinero de la multa
	pMultaID, // ID del que se la ha puesto
	pFrozen, // Jugador congelado por un admin
	pTempFrozen, // Jugador congelado (no puede usar /salir) temporalmente mientras realiza una acción: ejemplo: (recargar el limpiacalles de agua, o rellenar el deposito)
	pFrozenTaser,
	pEsposado,
	pCheckpoint,
	pRefuerzos,
	pHerido,
	pAlcohol,
	pSonido,
	pSQLID,
	pUniforme,
	pMoviendoNeg,
	pEditingNeg,
	pMoviendoCasa,
    pEditingCasa,
    pMoviendoParking,
	pJugando,
	pHambre,
	pLastCar, //antigua gLastCar (ultimo coche)
	pOfertaCocheID, // PlayerID del que vende el coche
	pOfertaCocheKey, // Key del coche a vender
	pOfertaCocheMoney, // Dinero de la oferta
	//---[VARIABLES DE LOS TRABAJOS]---
	// -[GLOBALES]-
	pTrabajando,
	pOferta,
	pContrato,
	TiempoEsperaTrabajo, // con gettime()
	pRutaDeTrabajo, // LC & BA Ruta de trabajo // SP & CO Tipo de pesca/cosecha
	pTrabajandoCP,
	pListoCobro, // LC & BA - PREPARADO PARA COBRAR (1 SI - 0 NO) // SP & CO PreparadoParaVender
	pEquipoParaTrabajar,
	pMaterialTrabajo, // CO - Saco de trigo // SP - Cubo con peces // LC - AGUA CARGADA
    pGanancias,
	pTrabajoVeh,
	pTrabajoTimer, // BA - Countdown de tiempo recogiendo la basura (SetTimerEx) // AMB - T.Espera en el CP
	// -[BASURERO]-
	pBolsaBasura, // Bolsa de basura para recoger (CreateObject)
	// -[MECANICOS]-
	pProductos,
	pHabilidadMecanico,
	pEligiendoColores,
	pRepaintOffer,
	pRepaintPrice,
	pRepaintColor,
	pRepaintColor2,
	pRepairOffer,
	pRepairPrice,
	pRefillOffer,
	pRefillPrice,
	pRefillAmount,
	pEstadoMecanico,
	pClienteMecanico,
	// -[PESCA]-
	pPuedePescar,
	pHaTiradoAnzuelo,
	pHaTiradoRedes,
	pHabilidadPescador, // >0 - Nivel 1 ; >100 - Nivel 2; >300 - Nivel 3;
	pPuntosHabilidadGanados,
	pPuntosHabilidadRestantes,
	pNivelPescador,
	pRedRota,
	// -[AMBULANTE]-
	pOfertaHelado, 
	pOfertaPerrito,
    // -[PIZZA]-
    pPizzas,
    pHablandoPizza,
	// -[SEGUROS]-
	pOfreciendoS,
	pOfreciendoC,
	pOfreciendoV,
    // -[REPARTIDOR]-
	pRutasCompletadas,
    // -[LADRON]-
    pHabilidadLadron,
    pPalanca,
    pGanzua,
    pAlicates,
	// -[COMIDAS]-
	pMoviendoCom,
	pEditandoCom,
	// -[TAXISTA]-
	pEstadoTaxista,
	pClienteTaxista,
	// -[PAGOS]-
	pPagandole,
	pPagandoDin,
	//---[FIN VARIABLES DE LOS TRABAJOS]---
	pGafas,
	pBandana,
	pOfertaSaludo,
	//---Licencia Armas----
	pGunLic,
	pGunLicD,
	pGunLicM,
	//--FIN LICENCIA ARMAS----
	pHablandoArmas,
	//---[PREMIUM]---
	pPremiumTipo,
	pPremiumTime,
	//-- LowRider Minigame --
	pCurrentNote,
	bool:pInContest,
	pPointsEarned,
	bool:pJustJoined,
	//-- Muebles --
	pMuebles[MAX_MUEBLES_PER_PLAYER],
	//-- Sonidos --
	pEfecto,
	Float:pEfectoRatio,
}
new PlayerInfo[MAX_PLAYERS][pInfo];

#define MAX_NEGOCIOS 120
enum nInfo
{
	nId, // ID en SQL del negocio.
	nName[128], // ID en SQL del negocio.
	nType, // Tipo de negocio. Con valor 1, Restaurante; 2, Bar/Nightclub; 3, 24/7; 4, Comidas rápidas; 6, Corrupto; 7, Taller de mecanicos. 
	Float:nEPos_x, // (Float) Coordenada X exterior del negocio.
	Float:nEPos_y, // (Float) Coordenada Y exterior del negocio.
	Float:nEPos_z, // (Float) Coordenada Z exterior del negocio.
	Float:nSPos_x, // (Float) Coordenada X interior del negocio.
	Float:nSPos_y, // (Float) Coordenada Y interior del negocio.
	Float:nSPos_z, // (Float) Coordenada Z interior del negocio.
	nProd, // Cantidad de productos en existencias del negocio.
	nCajaFuerte, // Cantidad de dinero en la caja fuerte del negocio.
	nLocked, // Con valor 0, el negocio está abierto y con valor 1 el negocio está cerrado.
	nOwner[128], // Nombre del dueño del negocio.
	nOwned, // Con valor 0, el negocio está en venta; con valor 1 el negocio está comprado por alguien.
	nInterior, // ID del interior del negocio.
	nCosto, // Precio de venta del negocio.
	Text3D:nPickup, // (Text3D) ID del texto en 3d que aparece en el lugar de entrada.
    nRobado, //hora ultimo robo
}

new NegocioInfo[MAX_NEGOCIOS][nInfo];

#define MAX_TRUNK_SLOTS 8
enum cInfo
{
	cId,  // ID en SAMP del coche.
	cCarKey, // Llave del coche del jugador.
	cModel, // ID del modelo del coche.
	Float:cLocationx, // (Float) Coordenada X del coche.
	Float:cLocationy, // (Float) Coordenada Y del coche.
	Float:cLocationz, // (Float) Coordenada Z del coche.
	Float:cAngle, // (Float) Grado del angulo en que se encuentra el coche.
	cColorOne, // ID del 1er color del coche.
	cColorTwo, // ID del 2do color del coche.
	cOwner[30], // Nombre del dueño del coche.
	cDescription[30], // Descripción del coche.
	cValue, // Precio del coche.
	cUsos, // 0 a 100 es la ID de la Facción asignada, 101 a más es ID del trabajo asignado.
	cOwned, // Con valor 0 si el coche no tiene dueño.
	cLock, // Con valor 1 si el coche está cerrado.
	cBroken, // Con valor 1 si el coche está roto.
	cStarted, // Con valor 1 si el coche esta encendido.
	cGas, // Cantidad de combustible disponible en el coche.
	//Sistema de Maleteros
	cSlots[128], // Todos los slots del maletero.
	cAmmos[128], // Todas las municiones en el maletero.
	cSlot[MAX_TRUNK_SLOTS], // Slot uno por uno.
	cAmmo[MAX_TRUNK_SLOTS], // Municion una por una.
    cDrogas[128], // 
	cDrogaP[3], // 
	cDrogaNP[2], // 
    cSemillas[2], // 
	cComponentes[128], // Todos los componentes.
	cComp[14], // Componente uno por uno.
	cPaintJob, // Paintjob(vinilo) del coche
	Float:cTmpx, // (Float) Coordenada temporal X del coche.
	Float:cTmpy, // (Float) Coordenada temporal Y del coche.
	Float:cTmpz, // (Float) Coordenada temporal Z del coche.
	Float:cTmpa, // (Float) Grado temporal del ángulo en que se encuentra el coche.
	cSQLID, // ID en SQL del coche.
	eliminado, // Con valor 1 si está eliminado.
	horas, // Horas aparcado.
	cParking, // ID del parking donde se encuentra.
	cDanos[50], // Todos las partes del coche.
	cDano[4], // Parte una por una del coche.
	Float:cDamage, // (Float) Vida del coche.
	//Radios
	cEmisora, // 
	cVolumen, // 
	cSubWoofer, // 
	cEquipo, // Equipo de musica
	cRadios[40], // 
	cVw, // 
	cInt, // 
	cSeguro,
    cGPS, // para el localizarveh...
	cSirena, // Sirenas
    cRobado, //hora ultimo robo
	Float:cKms, // Kilometros del coche
	cFixPos,
	cIntermitentesTmr,
};
new CarInfo[MAX_VEHICLES][cInfo];

#define MAX_PARKINGS 200
enum paInfo
{
	paSQLID, // ID en SQL del parking
	paType, // Tipo de parking. Con valor 0, público y con valor 1, privado, 2, deposito
	paCap, // Capacidad del parking.
	paTotal, // Coches actualmente aparcados en el parking.
	Float:paX, // (Float) Coordenada X del parking.
	Float:paY, // (Float) Coordenada Y del parking.
	Float:paZ, // (Float) Coordenada Z del parking.
	Float:paAngle, // (Float) Angle del parking.
	paOwner, // Llave señalada como necesario para aparcar.
    Text3D:paPickup,
}
new ParkInfo[MAX_PARKINGS][paInfo];

new CocheOcupado = 0;
new cocheselect = NOEXISTE;
new TotalVeh;
new TotalParkings;
new CodigoLlave;
new arrCoords[33][64];
new string[128];
new AnuncioTimer = 0;

#define MAX_CASAS 1500
enum hInfo
{
	hId, // ID en SQL de la casa.
	Float:hEx, // (Float) Coordenada X exterior de la casa.
	Float:hEy, // (Float) Coordenada Y exterior de la casa.
	Float:hEz, // (Float) Coordenada Z exterior de la casa.
	Float:hSx, // (Float) Coordenada X interior de la casa.
	Float:hSy, // (Float) Coordenada Y interior de la casa.
	Float:hSz, // (Float) Coordenada Z interior de la casa.
	hInterior, // ID del interior de la casa.
    hInterior2, // ID del exterior de la casa.
    hVw, // Virtualworld del exterior de la casa
	hOwned, // Con valor 0, no comprada; con 1, comprada y con -1, es un hotel.
	hOwner[MAX_PLAYER_NAME], // Nombre del dueño de la casa.
	hLevel, // Nivel necesario para poder comprar la casa.
	hValue, // Precio de la casa.
	hLock, // Con valor 1, la casa está cerrada.
    hGuns[128], // Todas las armas.
    hAmmos[128], // Todas las municiones.
	hGun[10], // Municiones una por una.
	hAmmo[10], // Armas una por una.
    hDrogas[128], // 
    hSemillas[2], // 
	hDrogaNP[2], // 
	hDrogaP[3], // 
	hDinero, // Dinero guardado en la casa.
	hAlq, // Con valor 0, no alquilable y con 1, alquilable.
	hPAlq, // Precio de alquiler.
	hAlquilados, // Numero de inquilinos actuales.
	Text3D:hPickup, // (Text3D) ID del texto 3d puesto en la entrada de la casa.
    hName[128], //Descripcion de la casa.
    hRobado, //hora ultimo robo
};
new CasaInfo[MAX_CASAS][hInfo];
new TotalCasas;


#define MAX_INTERIOR_ENTERS 21

enum intInfo
{
	PickupID,
	Float:itX,
	Float:itY,
	Float:itZ,
	Float:isX,
	Float:isY,
	Float:isZ,
	Interior,
	texto[24],
	FixPos,
	VWout,
	VWin,
};

new InteriorInfo[MAX_INTERIOR_ENTERS][intInfo] = {
{1314,1480.9926757813, -1770.5500488281, 18.444980621338, 389.6506652832, 173.78536987305, 1008.032043457, 3, "Ayuntamiento",0,0,0},
{1247,1554.3635253906, -1675.5501708984, 15.844537734985, 246.4298248291, 108.14186096191, 1002.867980957, 10, "Comisaria",0,0,0},
{1247,1568.7113,-1691.0371,5.8906,214.4302,118.3369,999.0156,10, "Comisaria",0,0,0},
{1247,1564.8456,-1665.8424,28.3956,277.8429,125.2676,1008.8203,10, "Comisaria",0,0,0},
{1240,1173.2415771484, -1323.5466308594, 15.131909370422, -346.4938659668, 143.90850830078, 1034.7789306641, 10, "Hospital General",1,0,0},
{1240,1161.1921,-1329.3536,31.4974,-368.6265,140.1281,1035.1298,10,"Hospital",1,0,0},
{1273,2232.8618,-1159.6361,25.8906,2215.1545410156,-1150.3376464844,1025.4460449219,15, "Hotel Jefferson",0,0,0},
{1273,329.1730,-1513.1047,36.0391,2266.8803710938,1647.3842773438,1083.8835449219,1, "Hotel",0,0,0},
{1273,315.3544,-1515.1603,24.9219,2266.8803710938,1647.3842773438,1083.8835449219,1, "Hotel",0,0,0},
{1273,1519.2083,-1453.0273,14.2056,2224.3513183594, 1599.2528076172, 999.63250732422,1,"Hotel",1,0,0},
{1273,1526.9440,-1457.1029,9.5000,2224.3513183594, 1599.2528076172, 999.63250732422,1,"Hotel",1,0,0},
{1239,1206.8440,-1459.6036,13.3828,1494.325195,1304.942871,1093.289062,3,"Autoescuela",0,0,0},
{1239,2229.6262,-1721.6549,13.5651,772.111999,-3.898649,1000.728820,5,"Gimnasio",1,0,0},
{1239,2232.8894,-1333.1516,23.9815,1963.9947509766, -350.07553100586, 1092.5927734375,6,"Iglesia",1,0,0},
{1254,1797.6736,-1579.0219,14.0873,2574.5551757813, -1345.8859863281, 1047.6125488281,2,"Carcel",1,0,0},
{1239,593.1945,-1249.8027,18.2086,1033.2097167969, -1901.8232421875, 3478.8303222656,1, "Banco",1,0,0},
{1272,2754.6714,-1400.4231,39.3732,1578.6800537109, -1766.9837646484, 2150.0085449219,1, "Hotel",1,0,0},
{1239,2137.9641,-1913.1593,13.5469,2532.4140625, -1285.9510498047, 1054.2897949219,2,"Club",1,0,0},
{1247,627.1810,-571.6234,17.9145,246.9915,63.3117,1003.6406,6,"Sheriff Department",0,0,1},
{1253,2577.1721,-1324.4905,1047.9634,220.70634460449,80.211738586426,1005.0390625,6,"Sala de interrogatorios",1,0,0},
{1239,2303.0413,-16.2006,26.4844,2305.2566,-16.1681,26.7422,0,"Banco",1,0,1}
};

new Menu:ATM;
new Menu:Elevador;
new Menu:Tramitacion;
new Menu:Ayuda;
new Menu:venticuatroseven;
new Menu:amu;
new Menu:bebidas;
new Menu:snacks;
new Menu:cafes;
new Menu:burger;
new Menu:restaurante;
new Menu:pizzeria;
new Menu:pollofrito;
new Menu:barcafeteria;
new Menu:alcohol;
new Menu:donuts;
new Menu:chino;
new Menu:perritos;
new Menu:helados;
new Menu:japo;
new Menu:carcel;
new Menu:azar;
new Menu:mexicano;
new Menu:Ropa;
new Menu:gafas;
new Menu:gafasnorm;
new Menu:gafascirc;
new Menu:gafascuad;
new Menu:gafasrayban;
new Menu:Casco;
new Menu:Bandanas;
new Menu:Bandanas2;
new Menu:nevera;

#define MAX_FRECUENCIAS 25
enum fInfo
{
	fId,
	fDueno[24],
	fPassword[128],
}
new Frecuencia[MAX_FRECUENCIAS][fInfo];

#define MAX_COMIDAS 100
enum coInfo
{
	coId,
	Float:coX,
	Float:coY,
	Float:coZ,
	coInt,
	coVw,
	coName[24],
	coType,
	Text3D:coText,
	coEliminado,
}
new Comidas[MAX_COMIDAS][coInfo];

new Text:Textdraw0;
new Text:Textdraw1;
new Text:Textdraw2;
new Text:Textdraw3;
new Text:Textdraw4;

#define MAX_SONIDOS 150
enum sInfo
{
	sId,
	sRadio,
	Float:sX,
	Float:sY,
	Float:sZ,
	Float:sRatio,
	sHandle,
	sEliminado,
}
new Sonidos[MAX_SONIDOS][sInfo];



enum SAZONE_MAIN {
		SAZONE_NAME[28],
		Float:SAZONE_AREA[6]
};

new const gSAZones[][SAZONE_MAIN] = {
	{"The Big Ear",	                {-410.00,1403.30,-3.00,-137.90,1681.20,200.00}},
	{"Aldea Malvada",               {-1372.10,2498.50,0.00,-1277.50,2615.30,200.00}},
	{"Angel Pine",                  {-2324.90,-2584.20,-6.10,-1964.20,-2212.10,200.00}},
	{"Arco del Oeste",              {-901.10,2221.80,0.00,-592.00,2571.90,200.00}},
	{"Avispa Country Club",         {-2646.40,-355.40,0.00,-2270.00,-222.50,200.00}},
	{"Avispa Country Club",         {-2831.80,-430.20,-6.10,-2646.40,-222.50,200.00}},
	{"Avispa Country Club",         {-2361.50,-417.10,0.00,-2270.00,-355.40,200.00}},
	{"Avispa Country Club",         {-2667.80,-302.10,-28.80,-2646.40,-262.30,71.10}},
	{"Avispa Country Club",         {-2470.00,-355.40,0.00,-2270.00,-318.40,46.10}},
	{"Avispa Country Club",         {-2550.00,-355.40,0.00,-2470.00,-318.40,39.70}},
	{"Back o Beyond",               {-1166.90,-2641.10,0.00,-321.70,-1856.00,200.00}},
	{"Battery Point",               {-2741.00,1268.40,-4.50,-2533.00,1490.40,200.00}},
	{"Bayside",                     {-2741.00,2175.10,0.00,-2353.10,2722.70,200.00}},
	{"Bayside Marina",              {-2353.10,2275.70,0.00,-2153.10,2475.70,200.00}},
	{"Beacon Hill",                 {-399.60,-1075.50,-1.40,-319.00,-977.50,198.50}},
	{"Blackfield",                  {964.30,1203.20,-89.00,1197.30,1403.20,110.90}},
	{"Blackfield",                  {964.30,1403.20,-89.00,1197.30,1726.20,110.90}},
	{"Blackfield Chapel",           {1375.60,596.30,-89.00,1558.00,823.20,110.90}},
	{"Blackfield Chapel",           {1325.60,596.30,-89.00,1375.60,795.00,110.90}},
	{"Blackfield Intersection",     {1197.30,1044.60,-89.00,1277.00,1163.30,110.90}},
	{"Blackfield Intersection",     {1166.50,795.00,-89.00,1375.60,1044.60,110.90}},
	{"Blackfield Intersection",     {1277.00,1044.60,-89.00,1315.30,1087.60,110.90}},
	{"Blackfield Intersection",     {1375.60,823.20,-89.00,1457.30,919.40,110.90}},
	{"Blueberry",                   {104.50,-220.10,2.30,349.60,152.20,200.00}},
	{"Blueberry",                   {19.60,-404.10,3.80,349.60,-220.10,200.00}},
	{"Blueberry Acres",             {-319.60,-220.10,0.00,104.50,293.30,200.00}},
	{"Caligula's Palace",           {2087.30,1543.20,-89.00,2437.30,1703.20,110.90}},
	{"Caligula's Palace",           {2137.40,1703.20,-89.00,2437.30,1783.20,110.90}},
	{"Calton Heights",              {-2274.10,744.10,-6.10,-1982.30,1358.90,200.00}},
	{"Chinatown",                   {-2274.10,578.30,-7.60,-2078.60,744.10,200.00}},
	{"City Hall",                   {-2867.80,277.40,-9.10,-2593.40,458.40,200.00}},
	{"Come-A-Lot",                  {2087.30,943.20,-89.00,2623.10,1203.20,110.90}},
	{"Commerce",                    {1323.90,-1842.20,-89.00,1701.90,-1722.20,110.90}},
	{"Commerce",                    {1323.90,-1722.20,-89.00,1440.90,-1577.50,110.90}},
	{"Commerce",                    {1370.80,-1577.50,-89.00,1463.90,-1384.90,110.90}},
	{"Commerce",                    {1463.90,-1577.50,-89.00,1667.90,-1430.80,110.90}},
	{"Commerce",                    {1583.50,-1722.20,-89.00,1758.90,-1577.50,110.90}},
	{"Commerce",                    {1667.90,-1577.50,-89.00,1812.60,-1430.80,110.90}},
	{"Conference Center",           {1046.10,-1804.20,-89.00,1323.90,-1722.20,110.90}},
	{"Conference Center",           {1073.20,-1842.20,-89.00,1323.90,-1804.20,110.90}},
	{"Cranberry Station",           {-2007.80,56.30,0.00,-1922.00,224.70,100.00}},
	{"Creek",                       {2749.90,1937.20,-89.00,2921.60,2669.70,110.90}},
	{"Dillimore",                   {580.70,-674.80,-9.50,861.00,-404.70,200.00}},
	{"Doherty",                     {-2270.00,-324.10,-0.00,-1794.90,-222.50,200.00}},
	{"Doherty",                     {-2173.00,-222.50,-0.00,-1794.90,265.20,200.00}},
	{"Downtown",                    {-1982.30,744.10,-6.10,-1871.70,1274.20,200.00}},
	{"Downtown",                    {-1871.70,1176.40,-4.50,-1620.30,1274.20,200.00}},
	{"Downtown",                    {-1700.00,744.20,-6.10,-1580.00,1176.50,200.00}},
	{"Downtown",                    {-1580.00,744.20,-6.10,-1499.80,1025.90,200.00}},
	{"Downtown",                    {-2078.60,578.30,-7.60,-1499.80,744.20,200.00}},
	{"Downtown",                    {-1993.20,265.20,-9.10,-1794.90,578.30,200.00}},
	{"Downtown Los Santos",         {1463.90,-1430.80,-89.00,1724.70,-1290.80,110.90}},
	{"Downtown Los Santos",         {1724.70,-1430.80,-89.00,1812.60,-1250.90,110.90}},
	{"Downtown Los Santos",         {1463.90,-1290.80,-89.00,1724.70,-1150.80,110.90}},
	{"Downtown Los Santos",         {1370.80,-1384.90,-89.00,1463.90,-1170.80,110.90}},
	{"Downtown Los Santos",         {1724.70,-1250.90,-89.00,1812.60,-1150.80,110.90}},
	{"Downtown Los Santos",         {1370.80,-1170.80,-89.00,1463.90,-1130.80,110.90}},
	{"Downtown Los Santos",         {1378.30,-1130.80,-89.00,1463.90,-1026.30,110.90}},
	{"Downtown Los Santos",         {1391.00,-1026.30,-89.00,1463.90,-926.90,110.90}},
	{"Downtown Los Santos",         {1507.50,-1385.20,110.90,1582.50,-1325.30,335.90}},
	{"East Beach",                  {2632.80,-1852.80,-89.00,2959.30,-1668.10,110.90}},
	{"East Beach",                  {2632.80,-1668.10,-89.00,2747.70,-1393.40,110.90}},
	{"East Beach",                  {2747.70,-1668.10,-89.00,2959.30,-1498.60,110.90}},
	{"East Beach",                  {2747.70,-1498.60,-89.00,2959.30,-1120.00,110.90}},
	{"East Los Santos",             {2421.00,-1628.50,-89.00,2632.80,-1454.30,110.90}},
	{"East Los Santos",             {2222.50,-1628.50,-89.00,2421.00,-1494.00,110.90}},
	{"East Los Santos",             {2266.20,-1494.00,-89.00,2381.60,-1372.00,110.90}},
	{"East Los Santos",             {2381.60,-1494.00,-89.00,2421.00,-1454.30,110.90}},
	{"East Los Santos",             {2281.40,-1372.00,-89.00,2381.60,-1135.00,110.90}},
	{"East Los Santos",             {2381.60,-1454.30,-89.00,2462.10,-1135.00,110.90}},
	{"East Los Santos",             {2462.10,-1454.30,-89.00,2581.70,-1135.00,110.90}},
	{"Easter Basin",                {-1794.90,249.90,-9.10,-1242.90,578.30,200.00}},
	{"Easter Basin",                {-1794.90,-50.00,-0.00,-1499.80,249.90,200.00}},
	{"Easter Bay Airport",          {-1499.80,-50.00,-0.00,-1242.90,249.90,200.00}},
	{"Easter Bay Airport",          {-1794.90,-730.10,-3.00,-1213.90,-50.00,200.00}},
	{"Easter Bay Airport",          {-1213.90,-730.10,0.00,-1132.80,-50.00,200.00}},
	{"Easter Bay Airport",          {-1242.90,-50.00,0.00,-1213.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1213.90,-50.00,-4.50,-947.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1315.40,-405.30,15.40,-1264.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1354.30,-287.30,15.40,-1315.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1490.30,-209.50,15.40,-1264.40,-148.30,25.40}},
	{"Easter Bay Chemicals",        {-1132.80,-768.00,0.00,-956.40,-578.10,200.00}},
	{"Easter Bay Chemicals",        {-1132.80,-787.30,0.00,-956.40,-768.00,200.00}},
	{"El Castillo del Diablo",      {-464.50,2217.60,0.00,-208.50,2580.30,200.00}},
	{"El Castillo del Diablo",      {-208.50,2123.00,-7.60,114.00,2337.10,200.00}},
	{"El Castillo del Diablo",      {-208.50,2337.10,0.00,8.40,2487.10,200.00}},
	{"El Corona",                   {1812.60,-2179.20,-89.00,1970.60,-1852.80,110.90}},
	{"El Corona",                   {1692.60,-2179.20,-89.00,1812.60,-1842.20,110.90}},
	{"El Quebrados",                {-1645.20,2498.50,0.00,-1372.10,2777.80,200.00}},
	{"Esplanade East",              {-1620.30,1176.50,-4.50,-1580.00,1274.20,200.00}},
	{"Esplanade East",              {-1580.00,1025.90,-6.10,-1499.80,1274.20,200.00}},
	{"Esplanade East",              {-1499.80,578.30,-79.60,-1339.80,1274.20,20.30}},
	{"Esplanade North",             {-2533.00,1358.90,-4.50,-1996.60,1501.20,200.00}},
	{"Esplanade North",             {-1996.60,1358.90,-4.50,-1524.20,1592.50,200.00}},
	{"Esplanade North",             {-1982.30,1274.20,-4.50,-1524.20,1358.90,200.00}},
	{"Fallen Tree",                 {-792.20,-698.50,-5.30,-452.40,-380.00,200.00}},
	{"Fallow Bridge",               {434.30,366.50,0.00,603.00,555.60,200.00}},
	{"Fern Ridge",                  {508.10,-139.20,0.00,1306.60,119.50,200.00}},
	{"Financial",                   {-1871.70,744.10,-6.10,-1701.30,1176.40,300.00}},
	{"Fisher's Lagoon",             {1916.90,-233.30,-100.00,2131.70,13.80,200.00}},
	{"Flint Intersection",          {-187.70,-1596.70,-89.00,17.00,-1276.60,110.90}},
	{"Flint Range",                 {-594.10,-1648.50,0.00,-187.70,-1276.60,200.00}},
	{"Fort Carson",                 {-376.20,826.30,-3.00,123.70,1220.40,200.00}},
	{"Foster Valley",               {-2270.00,-430.20,-0.00,-2178.60,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-599.80,-0.00,-1794.90,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-1115.50,0.00,-1794.90,-599.80,200.00}},
	{"Foster Valley",               {-2178.60,-1250.90,0.00,-1794.90,-1115.50,200.00}},
	{"Frederick Bridge",            {2759.20,296.50,0.00,2774.20,594.70,200.00}},
	{"Gant Bridge",                 {-2741.40,1659.60,-6.10,-2616.40,2175.10,200.00}},
	{"Gant Bridge",                 {-2741.00,1490.40,-6.10,-2616.40,1659.60,200.00}},
	{"Ganton",                      {2222.50,-1852.80,-89.00,2632.80,-1722.30,110.90}},
	{"Ganton",                      {2222.50,-1722.30,-89.00,2632.80,-1628.50,110.90}},
	{"Garcia",                      {-2411.20,-222.50,-0.00,-2173.00,265.20,200.00}},
	{"Garcia",                      {-2395.10,-222.50,-5.30,-2354.00,-204.70,200.00}},
	{"Garver Bridge",               {-1339.80,828.10,-89.00,-1213.90,1057.00,110.90}},
	{"Garver Bridge",               {-1213.90,950.00,-89.00,-1087.90,1178.90,110.90}},
	{"Garver Bridge",               {-1499.80,696.40,-179.60,-1339.80,925.30,20.30}},
	{"Glen Park",                   {1812.60,-1449.60,-89.00,1996.90,-1350.70,110.90}},
	{"Glen Park",                   {1812.60,-1100.80,-89.00,1994.30,-973.30,110.90}},
	{"Glen Park",                   {1812.60,-1350.70,-89.00,2056.80,-1100.80,110.90}},
	{"Green Palms",                 {176.50,1305.40,-3.00,338.60,1520.70,200.00}},
	{"Greenglass College",          {964.30,1044.60,-89.00,1197.30,1203.20,110.90}},
	{"Greenglass College",          {964.30,930.80,-89.00,1166.50,1044.60,110.90}},
	{"Hampton Barns",               {603.00,264.30,0.00,761.90,366.50,200.00}},
	{"Hankypanky Point",            {2576.90,62.10,0.00,2759.20,385.50,200.00}},
	{"Harry Gold Parkway",          {1777.30,863.20,-89.00,1817.30,2342.80,110.90}},
	{"Hashbury",                    {-2593.40,-222.50,-0.00,-2411.20,54.70,200.00}},
	{"Hilltop Farm",                {967.30,-450.30,-3.00,1176.70,-217.90,200.00}},
	{"Hunter Quarry",               {337.20,710.80,-115.20,860.50,1031.70,203.70}},
	{"Idlewood",                    {1812.60,-1852.80,-89.00,1971.60,-1742.30,110.90}},
	{"Idlewood",                    {1812.60,-1742.30,-89.00,1951.60,-1602.30,110.90}},
	{"Idlewood",                    {1951.60,-1742.30,-89.00,2124.60,-1602.30,110.90}},
	{"Idlewood",                    {1812.60,-1602.30,-89.00,2124.60,-1449.60,110.90}},
	{"Idlewood",                    {2124.60,-1742.30,-89.00,2222.50,-1494.00,110.90}},
	{"Idlewood",                    {1971.60,-1852.80,-89.00,2222.50,-1742.30,110.90}},
	{"Jefferson",                   {1996.90,-1449.60,-89.00,2056.80,-1350.70,110.90}},
	{"Jefferson",                   {2124.60,-1494.00,-89.00,2266.20,-1449.60,110.90}},
	{"Jefferson",                   {2056.80,-1372.00,-89.00,2281.40,-1210.70,110.90}},
	{"Jefferson",                   {2056.80,-1210.70,-89.00,2185.30,-1126.30,110.90}},
	{"Jefferson",                   {2185.30,-1210.70,-89.00,2281.40,-1154.50,110.90}},
	{"Jefferson",                   {2056.80,-1449.60,-89.00,2266.20,-1372.00,110.90}},
	{"Julius Thruway East",         {2623.10,943.20,-89.00,2749.90,1055.90,110.90}},
	{"Julius Thruway East",         {2685.10,1055.90,-89.00,2749.90,2626.50,110.90}},
	{"Julius Thruway East",         {2536.40,2442.50,-89.00,2685.10,2542.50,110.90}},
	{"Julius Thruway East",         {2625.10,2202.70,-89.00,2685.10,2442.50,110.90}},
	{"Julius Thruway North",        {2498.20,2542.50,-89.00,2685.10,2626.50,110.90}},
	{"Julius Thruway North",        {2237.40,2542.50,-89.00,2498.20,2663.10,110.90}},
	{"Julius Thruway North",        {2121.40,2508.20,-89.00,2237.40,2663.10,110.90}},
	{"Julius Thruway North",        {1938.80,2508.20,-89.00,2121.40,2624.20,110.90}},
	{"Julius Thruway North",        {1534.50,2433.20,-89.00,1848.40,2583.20,110.90}},
	{"Julius Thruway North",        {1848.40,2478.40,-89.00,1938.80,2553.40,110.90}},
	{"Julius Thruway North",        {1704.50,2342.80,-89.00,1848.40,2433.20,110.90}},
	{"Julius Thruway North",        {1377.30,2433.20,-89.00,1534.50,2507.20,110.90}},
	{"Julius Thruway South",        {1457.30,823.20,-89.00,2377.30,863.20,110.90}},
	{"Julius Thruway South",        {2377.30,788.80,-89.00,2537.30,897.90,110.90}},
	{"Julius Thruway West",         {1197.30,1163.30,-89.00,1236.60,2243.20,110.90}},
	{"Julius Thruway West",         {1236.60,2142.80,-89.00,1297.40,2243.20,110.90}},
	{"Juniper Hill",                {-2533.00,578.30,-7.60,-2274.10,968.30,200.00}},
	{"Juniper Hollow",              {-2533.00,968.30,-6.10,-2274.10,1358.90,200.00}},
	{"K.A.C.C. Military Fuels",     {2498.20,2626.50,-89.00,2749.90,2861.50,110.90}},
	{"Kincaid Bridge",              {-1339.80,599.20,-89.00,-1213.90,828.10,110.90}},
	{"Kincaid Bridge",              {-1213.90,721.10,-89.00,-1087.90,950.00,110.90}},
	{"Kincaid Bridge",              {-1087.90,855.30,-89.00,-961.90,986.20,110.90}},
	{"King's",                      {-2329.30,458.40,-7.60,-1993.20,578.30,200.00}},
	{"King's",                      {-2411.20,265.20,-9.10,-1993.20,373.50,200.00}},
	{"King's",                      {-2253.50,373.50,-9.10,-1993.20,458.40,200.00}},
	{"LVA Freight Depot",           {1457.30,863.20,-89.00,1777.40,1143.20,110.90}},
	{"LVA Freight Depot",           {1375.60,919.40,-89.00,1457.30,1203.20,110.90}},
	{"LVA Freight Depot",           {1277.00,1087.60,-89.00,1375.60,1203.20,110.90}},
	{"LVA Freight Depot",           {1315.30,1044.60,-89.00,1375.60,1087.60,110.90}},
	{"LVA Freight Depot",           {1236.60,1163.40,-89.00,1277.00,1203.20,110.90}},
	{"Las Barrancas",               {-926.10,1398.70,-3.00,-719.20,1634.60,200.00}},
	{"Las Brujas",                  {-365.10,2123.00,-3.00,-208.50,2217.60,200.00}},
	{"Las Colinas",                 {1994.30,-1100.80,-89.00,2056.80,-920.80,110.90}},
	{"Las Colinas",                 {2056.80,-1126.30,-89.00,2126.80,-920.80,110.90}},
	{"Las Colinas",                 {2185.30,-1154.50,-89.00,2281.40,-934.40,110.90}},
	{"Las Colinas",                 {2126.80,-1126.30,-89.00,2185.30,-934.40,110.90}},
	{"Las Colinas",                 {2747.70,-1120.00,-89.00,2959.30,-945.00,110.90}},
	{"Las Colinas",                 {2632.70,-1135.00,-89.00,2747.70,-945.00,110.90}},
	{"Las Colinas",                 {2281.40,-1135.00,-89.00,2632.70,-945.00,110.90}},
	{"Las Payasadas",               {-354.30,2580.30,2.00,-133.60,2816.80,200.00}},
	{"Las Venturas Airport",        {1236.60,1203.20,-89.00,1457.30,1883.10,110.90}},
	{"Las Venturas Airport",        {1457.30,1203.20,-89.00,1777.30,1883.10,110.90}},
	{"Las Venturas Airport",        {1457.30,1143.20,-89.00,1777.40,1203.20,110.90}},
	{"Las Venturas Airport",        {1515.80,1586.40,-12.50,1729.90,1714.50,87.50}},
	{"Last Dime Motel",             {1823.00,596.30,-89.00,1997.20,823.20,110.90}},
	{"Leafy Hollow",                {-1166.90,-1856.00,0.00,-815.60,-1602.00,200.00}},
	{"Liberty City",                {-1000.00,400.00,1300.00,-700.00,600.00,1400.00}},
	{"Lil' Probe Inn",              {-90.20,1286.80,-3.00,153.80,1554.10,200.00}},
	{"Linden Side",                 {2749.90,943.20,-89.00,2923.30,1198.90,110.90}},
	{"Linden Station",              {2749.90,1198.90,-89.00,2923.30,1548.90,110.90}},
	{"Linden Station",              {2811.20,1229.50,-39.50,2861.20,1407.50,60.40}},
	{"Little Mexico",               {1701.90,-1842.20,-89.00,1812.60,-1722.20,110.90}},
	{"Little Mexico",               {1758.90,-1722.20,-89.00,1812.60,-1577.50,110.90}},
	{"Los Flores",                  {2581.70,-1454.30,-89.00,2632.80,-1393.40,110.90}},
	{"Los Flores",                  {2581.70,-1393.40,-89.00,2747.70,-1135.00,110.90}},
	{"Los Santos International",    {1249.60,-2394.30,-89.00,1852.00,-2179.20,110.90}},
	{"Los Santos International",    {1852.00,-2394.30,-89.00,2089.00,-2179.20,110.90}},
	{"Los Santos International",    {1382.70,-2730.80,-89.00,2201.80,-2394.30,110.90}},
	{"Los Santos International",    {1974.60,-2394.30,-39.00,2089.00,-2256.50,60.90}},
	{"Los Santos International",    {1400.90,-2669.20,-39.00,2189.80,-2597.20,60.90}},
	{"Los Santos International",    {2051.60,-2597.20,-39.00,2152.40,-2394.30,60.90}},
	{"Marina",                      {647.70,-1804.20,-89.00,851.40,-1577.50,110.90}},
	{"Marina",                      {647.70,-1577.50,-89.00,807.90,-1416.20,110.90}},
	{"Marina",                      {807.90,-1577.50,-89.00,926.90,-1416.20,110.90}},
	{"Market",                      {787.40,-1416.20,-89.00,1072.60,-1310.20,110.90}},
	{"Market",                      {952.60,-1310.20,-89.00,1072.60,-1130.80,110.90}},
	{"Market",                      {1072.60,-1416.20,-89.00,1370.80,-1130.80,110.90}},
	{"Market",                      {926.90,-1577.50,-89.00,1370.80,-1416.20,110.90}},
	{"Market Station",              {787.40,-1410.90,-34.10,866.00,-1310.20,65.80}},
	{"Martin Bridge",               {-222.10,293.30,0.00,-122.10,476.40,200.00}},
	{"Missionary Hill",             {-2994.40,-811.20,0.00,-2178.60,-430.20,200.00}},
	{"Montgomery",                  {1119.50,119.50,-3.00,1451.40,493.30,200.00}},
	{"Montgomery",                  {1451.40,347.40,-6.10,1582.40,420.80,200.00}},
	{"Montgomery Intersection",     {1546.60,208.10,0.00,1745.80,347.40,200.00}},
	{"Montgomery Intersection",     {1582.40,347.40,0.00,1664.60,401.70,200.00}},
	{"Mulholland",                  {1414.00,-768.00,-89.00,1667.60,-452.40,110.90}},
	{"Mulholland",                  {1281.10,-452.40,-89.00,1641.10,-290.90,110.90}},
	{"Mulholland",                  {1269.10,-768.00,-89.00,1414.00,-452.40,110.90}},
	{"Mulholland",                  {1357.00,-926.90,-89.00,1463.90,-768.00,110.90}},
	{"Mulholland",                  {1318.10,-910.10,-89.00,1357.00,-768.00,110.90}},
	{"Mulholland",                  {1169.10,-910.10,-89.00,1318.10,-768.00,110.90}},
	{"Mulholland",                  {768.60,-954.60,-89.00,952.60,-860.60,110.90}},
	{"Mulholland",                  {687.80,-860.60,-89.00,911.80,-768.00,110.90}},
	{"Mulholland",                  {737.50,-768.00,-89.00,1142.20,-674.80,110.90}},
	{"Mulholland",                  {1096.40,-910.10,-89.00,1169.10,-768.00,110.90}},
	{"Mulholland",                  {952.60,-937.10,-89.00,1096.40,-860.60,110.90}},
	{"Mulholland",                  {911.80,-860.60,-89.00,1096.40,-768.00,110.90}},
	{"Mulholland",                  {861.00,-674.80,-89.00,1156.50,-600.80,110.90}},
	{"Mulholland Intersection",     {1463.90,-1150.80,-89.00,1812.60,-768.00,110.90}},
	{"North Rock",                  {2285.30,-768.00,0.00,2770.50,-269.70,200.00}},
	{"Ocean Docks",                 {2373.70,-2697.00,-89.00,2809.20,-2330.40,110.90}},
	{"Ocean Docks",                 {2201.80,-2418.30,-89.00,2324.00,-2095.00,110.90}},
	{"Ocean Docks",                 {2324.00,-2302.30,-89.00,2703.50,-2145.10,110.90}},
	{"Ocean Docks",                 {2089.00,-2394.30,-89.00,2201.80,-2235.80,110.90}},
	{"Ocean Docks",                 {2201.80,-2730.80,-89.00,2324.00,-2418.30,110.90}},
	{"Ocean Docks",                 {2703.50,-2302.30,-89.00,2959.30,-2126.90,110.90}},
	{"Ocean Docks",                 {2324.00,-2145.10,-89.00,2703.50,-2059.20,110.90}},
	{"Ocean Flats",                 {-2994.40,277.40,-9.10,-2867.80,458.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-222.50,-0.00,-2593.40,277.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-430.20,-0.00,-2831.80,-222.50,200.00}},
	{"Octane Springs",              {338.60,1228.50,0.00,664.30,1655.00,200.00}},
	{"Old Venturas Strip",          {2162.30,2012.10,-89.00,2685.10,2202.70,110.90}},
	{"Palisades",                   {-2994.40,458.40,-6.10,-2741.00,1339.60,200.00}},
	{"Palomino Creek",              {2160.20,-149.00,0.00,2576.90,228.30,200.00}},
	{"Paradiso",                    {-2741.00,793.40,-6.10,-2533.00,1268.40,200.00}},
	{"Pershing Square",             {1440.90,-1722.20,-89.00,1583.50,-1577.50,110.90}},
	{"Pilgrim",                     {2437.30,1383.20,-89.00,2624.40,1783.20,110.90}},
	{"Pilgrim",                     {2624.40,1383.20,-89.00,2685.10,1783.20,110.90}},
	{"Pilson Intersection",         {1098.30,2243.20,-89.00,1377.30,2507.20,110.90}},
	{"Pirates in Men's Pants",      {1817.30,1469.20,-89.00,2027.40,1703.20,110.90}},
	{"Playa del Seville",           {2703.50,-2126.90,-89.00,2959.30,-1852.80,110.90}},
	{"Prickle Pine",                {1534.50,2583.20,-89.00,1848.40,2863.20,110.90}},
	{"Prickle Pine",                {1117.40,2507.20,-89.00,1534.50,2723.20,110.90}},
	{"Prickle Pine",                {1848.40,2553.40,-89.00,1938.80,2863.20,110.90}},
	{"Prickle Pine",                {1938.80,2624.20,-89.00,2121.40,2861.50,110.90}},
	{"Queens",                      {-2533.00,458.40,0.00,-2329.30,578.30,200.00}},
	{"Queens",                      {-2593.40,54.70,0.00,-2411.20,458.40,200.00}},
	{"Queens",                      {-2411.20,373.50,0.00,-2253.50,458.40,200.00}},
	{"Randolph Industrial Estate",  {1558.00,596.30,-89.00,1823.00,823.20,110.90}},
	{"Redsands East",               {1817.30,2011.80,-89.00,2106.70,2202.70,110.90}},
	{"Redsands East",               {1817.30,2202.70,-89.00,2011.90,2342.80,110.90}},
	{"Redsands East",               {1848.40,2342.80,-89.00,2011.90,2478.40,110.90}},
	{"Redsands West",               {1236.60,1883.10,-89.00,1777.30,2142.80,110.90}},
	{"Redsands West",               {1297.40,2142.80,-89.00,1777.30,2243.20,110.90}},
	{"Redsands West",               {1377.30,2243.20,-89.00,1704.50,2433.20,110.90}},
	{"Redsands West",               {1704.50,2243.20,-89.00,1777.30,2342.80,110.90}},
	{"Regular Tom",                 {-405.70,1712.80,-3.00,-276.70,1892.70,200.00}},
	{"Richman",                     {647.50,-1118.20,-89.00,787.40,-954.60,110.90}},
	{"Richman",                     {647.50,-954.60,-89.00,768.60,-860.60,110.90}},
	{"Richman",                     {225.10,-1369.60,-89.00,334.50,-1292.00,110.90}},
	{"Richman",                     {225.10,-1292.00,-89.00,466.20,-1235.00,110.90}},
	{"Richman",                     {72.60,-1404.90,-89.00,225.10,-1235.00,110.90}},
	{"Richman",                     {72.60,-1235.00,-89.00,321.30,-1008.10,110.90}},
	{"Richman",                     {321.30,-1235.00,-89.00,647.50,-1044.00,110.90}},
	{"Richman",                     {321.30,-1044.00,-89.00,647.50,-860.60,110.90}},
	{"Richman",                     {321.30,-860.60,-89.00,687.80,-768.00,110.90}},
	{"Richman",                     {321.30,-768.00,-89.00,700.70,-674.80,110.90}},
	{"Robada Intersection",         {-1119.00,1178.90,-89.00,-862.00,1351.40,110.90}},
	{"Roca Escalante",              {2237.40,2202.70,-89.00,2536.40,2542.50,110.90}},
	{"Roca Escalante",              {2536.40,2202.70,-89.00,2625.10,2442.50,110.90}},
	{"Rockshore East",              {2537.30,676.50,-89.00,2902.30,943.20,110.90}},
	{"Rockshore West",              {1997.20,596.30,-89.00,2377.30,823.20,110.90}},
	{"Rockshore West",              {2377.30,596.30,-89.00,2537.30,788.80,110.90}},
	{"Rodeo",                       {72.60,-1684.60,-89.00,225.10,-1544.10,110.90}},
	{"Rodeo",                       {72.60,-1544.10,-89.00,225.10,-1404.90,110.90}},
	{"Rodeo",                       {225.10,-1684.60,-89.00,312.80,-1501.90,110.90}},
	{"Rodeo",                       {225.10,-1501.90,-89.00,334.50,-1369.60,110.90}},
	{"Rodeo",                       {334.50,-1501.90,-89.00,422.60,-1406.00,110.90}},
	{"Rodeo",                       {312.80,-1684.60,-89.00,422.60,-1501.90,110.90}},
	{"Rodeo",                       {422.60,-1684.60,-89.00,558.00,-1570.20,110.90}},
	{"Rodeo",                       {558.00,-1684.60,-89.00,647.50,-1384.90,110.90}},
	{"Rodeo",                       {466.20,-1570.20,-89.00,558.00,-1385.00,110.90}},
	{"Rodeo",                       {422.60,-1570.20,-89.00,466.20,-1406.00,110.90}},
	{"Rodeo",                       {466.20,-1385.00,-89.00,647.50,-1235.00,110.90}},
	{"Rodeo",                       {334.50,-1406.00,-89.00,466.20,-1292.00,110.90}},
	{"Royal Casino",                {2087.30,1383.20,-89.00,2437.30,1543.20,110.90}},
	{"San Andreas Sound",           {2450.30,385.50,-100.00,2759.20,562.30,200.00}},
	{"Santa Flora",                 {-2741.00,458.40,-7.60,-2533.00,793.40,200.00}},
	{"Santa Maria Beach",           {342.60,-2173.20,-89.00,647.70,-1684.60,110.90}},
	{"Santa Maria Beach",           {72.60,-2173.20,-89.00,342.60,-1684.60,110.90}},
	{"Shady Cabin",                 {-1632.80,-2263.40,-3.00,-1601.30,-2231.70,200.00}},
	{"Shady Creeks",                {-1820.60,-2643.60,-8.00,-1226.70,-1771.60,200.00}},
	{"Shady Creeks",                {-2030.10,-2174.80,-6.10,-1820.60,-1771.60,200.00}},
	{"Sobell Rail Yards",           {2749.90,1548.90,-89.00,2923.30,1937.20,110.90}},
	{"Spinybed",                    {2121.40,2663.10,-89.00,2498.20,2861.50,110.90}},
	{"Starfish Casino",             {2437.30,1783.20,-89.00,2685.10,2012.10,110.90}},
	{"Starfish Casino",             {2437.30,1858.10,-39.00,2495.00,1970.80,60.90}},
	{"Starfish Casino",             {2162.30,1883.20,-89.00,2437.30,2012.10,110.90}},
	{"Temple",                      {1252.30,-1130.80,-89.00,1378.30,-1026.30,110.90}},
	{"Temple",                      {1252.30,-1026.30,-89.00,1391.00,-926.90,110.90}},
	{"Temple",                      {1252.30,-926.90,-89.00,1357.00,-910.10,110.90}},
	{"Temple",                      {952.60,-1130.80,-89.00,1096.40,-937.10,110.90}},
	{"Temple",                      {1096.40,-1130.80,-89.00,1252.30,-1026.30,110.90}},
	{"Temple",                      {1096.40,-1026.30,-89.00,1252.30,-910.10,110.90}},
	{"The Camel's Toe",             {2087.30,1203.20,-89.00,2640.40,1383.20,110.90}},
	{"The Clown's Pocket",          {2162.30,1783.20,-89.00,2437.30,1883.20,110.90}},
	{"The Emerald Isle",            {2011.90,2202.70,-89.00,2237.40,2508.20,110.90}},
	{"The Farm",                    {-1209.60,-1317.10,114.90,-908.10,-787.30,251.90}},
	{"The Four Dragons Casino",     {1817.30,863.20,-89.00,2027.30,1083.20,110.90}},
	{"The High Roller",             {1817.30,1283.20,-89.00,2027.30,1469.20,110.90}},
	{"The Mako Span",               {1664.60,401.70,0.00,1785.10,567.20,200.00}},
	{"The Panopticon",              {-947.90,-304.30,-1.10,-319.60,327.00,200.00}},
	{"The Pink Swan",               {1817.30,1083.20,-89.00,2027.30,1283.20,110.90}},
	{"The Sherman Dam",             {-968.70,1929.40,-3.00,-481.10,2155.20,200.00}},
	{"The Strip",                   {2027.40,863.20,-89.00,2087.30,1703.20,110.90}},
	{"The Strip",                   {2106.70,1863.20,-89.00,2162.30,2202.70,110.90}},
	{"The Strip",                   {2027.40,1783.20,-89.00,2162.30,1863.20,110.90}},
	{"The Strip",                   {2027.40,1703.20,-89.00,2137.40,1783.20,110.90}},
	{"The Visage",                  {1817.30,1863.20,-89.00,2106.70,2011.80,110.90}},
	{"The Visage",                  {1817.30,1703.20,-89.00,2027.40,1863.20,110.90}},
	{"Unity Station",               {1692.60,-1971.80,-20.40,1812.60,-1932.80,79.50}},
	{"Valle Ocultado",              {-936.60,2611.40,2.00,-715.90,2847.90,200.00}},
	{"Verdant Bluffs",              {930.20,-2488.40,-89.00,1249.60,-2006.70,110.90}},
	{"Verdant Bluffs",              {1073.20,-2006.70,-89.00,1249.60,-1842.20,110.90}},
	{"Verdant Bluffs",              {1249.60,-2179.20,-89.00,1692.60,-1842.20,110.90}},
	{"Verdant Meadows",             {37.00,2337.10,-3.00,435.90,2677.90,200.00}},
	{"Verona Beach",                {647.70,-2173.20,-89.00,930.20,-1804.20,110.90}},
	{"Verona Beach",                {930.20,-2006.70,-89.00,1073.20,-1804.20,110.90}},
	{"Verona Beach",                {851.40,-1804.20,-89.00,1046.10,-1577.50,110.90}},
	{"Verona Beach",                {1161.50,-1722.20,-89.00,1323.90,-1577.50,110.90}},
	{"Verona Beach",                {1046.10,-1722.20,-89.00,1161.50,-1577.50,110.90}},
	{"Vinewood",                    {787.40,-1310.20,-89.00,952.60,-1130.80,110.90}},
	{"Vinewood",                    {787.40,-1130.80,-89.00,952.60,-954.60,110.90}},
	{"Vinewood",                    {647.50,-1227.20,-89.00,787.40,-1118.20,110.90}},
	{"Vinewood",                    {647.70,-1416.20,-89.00,787.40,-1227.20,110.90}},
	{"Whitewood Estates",           {883.30,1726.20,-89.00,1098.30,2507.20,110.90}},
	{"Whitewood Estates",           {1098.30,1726.20,-89.00,1197.30,2243.20,110.90}},
	{"Willowfield",                 {1970.60,-2179.20,-89.00,2089.00,-1852.80,110.90}},
	{"Willowfield",                 {2089.00,-2235.80,-89.00,2201.80,-1989.90,110.90}},
	{"Willowfield",                 {2089.00,-1989.90,-89.00,2324.00,-1852.80,110.90}},
	{"Willowfield",                 {2201.80,-2095.00,-89.00,2324.00,-1989.90,110.90}},
	{"Willowfield",                 {2541.70,-1941.40,-89.00,2703.50,-1852.80,110.90}},
	{"Willowfield",                 {2324.00,-2059.20,-89.00,2541.70,-1852.80,110.90}},
	{"Willowfield",                 {2541.70,-2059.20,-89.00,2703.50,-1941.40,110.90}},
	{"Yellow Bell Station",         {1377.40,2600.40,-21.90,1492.40,2687.30,78.00}},
	// Main Zones
	{"Los Santos",                  {44.60,-2892.90,-242.90,2997.00,-768.00,900.00}},
	{"Las Venturas",                {869.40,596.30,-242.90,2997.00,2993.80,900.00}},
	{"Bone County",                 {-480.50,596.30,-242.90,869.40,2993.80,900.00}},
	{"Tierra Robada",               {-2997.40,1659.60,-242.90,-480.50,2993.80,900.00}},
	{"Tierra Robada",               {-1213.90,596.30,-242.90,-480.50,1659.60,900.00}},
	{"San Fierro",                  {-2997.40,-1115.50,-242.90,-1213.90,1659.60,900.00}},
	{"Red County",                  {-1213.90,-768.00,-242.90,2997.00,596.30,900.00}},
	{"Flint County",                {-1213.90,-2892.90,-242.90,44.60,-768.00,900.00}},
	{"Whetstone",                   {-2997.40,-2892.90,-242.90,-1213.90,-1115.50,900.00}}
};

new gPlayerUsingLoopingAnim[MAX_PLAYERS];

new Entrando[MAX_PLAYERS];
#define MAX_REGISTROS 1000
enum eRegistro { rId,rNombre[24],rNumero,rProp }
new Registro[MAX_REGISTROS][eRegistro];
new EstaEnMisionTaxi[MAX_PLAYERS];
new numcheck[MAX_PLAYERS]; // numero de check del taxista (misiones)
#define MAX_SALUDOS 7
enum saludo
{
	animliba[24],
	animnamea[64],
}
new animsaludo[MAX_SALUDOS][saludo]=
{
	{	"GANGS", "prtial_hndshk_biz_01"},
	{	"GANGS", "hndshkcb"},
	{	"GANGS", "hndshkea"},
	{	"GANGS", "hndshkfa"},
	{	"GANGS", "hndshkba"},
	{	"ON_LOOKERS", "wave_loop"},
	{	"PED", "endchat_03"}
}; // nº animación para saludo coordinado
new nevando = 0; 

new EnActividad[MAX_PLAYERS];

new Loteria;

new Premium[4][30] = 
{
	{"{FFFFFF}No"},
	{"{EAA61C}Bronce"},
	{"{D5D2CC}Plata"},
	{"{FEED01}Oro"}
};

new TotalMuebles;
#define MAX_MUEBLES 500
enum amInfo
{
	mId, // ID en sql
	Float:mX,
	Float:mY,
	Float:mZ,
	Float:mAngle,
	mMueble, // ID del catalogo
	mOwner,	 // ID del comprador en sqlid
	mVW, // VW en el que está el objeto
	mObject, // El createdynamicobject
	mOculto, // 0 - NO  |  1 - SI
	mEliminado, // 0 - NO  |  1 - SI
}
new AMuebles[MAX_MUEBLES][amInfo];