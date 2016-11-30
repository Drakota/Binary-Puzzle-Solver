// Classe permettant de calculer un temps d'exécution en microsecondes
// Merci à Francis Lemaire (A2014) pour avoir trouvé le code brut à la source
// de cette classe.
//
// Usage : 
//   a) Instancier la classe
//   b) Faire appel à Start() pour démarrer le chrono
//   c) Faire appel à Stop() pour arrêter le chrono
//   d) Faire appel à Read() pour obtenir le temps calculé par le chrono
//      en microsecondes. 
//
// Note : on peut refaire Start(), Stop() et Read() pour obtenir une deuxième
//        lecture sans avoir à réinstancier la classe
//
// par Pierre Prud'homme, octobre 2014
// révision Pierre P, octobre 2015
//--------------------------------------------------------------------------------
#ifndef _CHRONO_H_
#define _CHRONO_H_
#include <Windows.h>

class Chrono
{
   LARGE_INTEGER StartingTime_;
   LARGE_INTEGER EndingTime_;
   LARGE_INTEGER ElapsedMicroseconds_;
   LARGE_INTEGER Frequency_;

public:
   Chrono();
   void Start();
   void Stop();
   LONGLONG Read();
};

#endif