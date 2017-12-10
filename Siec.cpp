#include "Siec.h"

#include <iostream>
#include <vector>
#include <list>

//dyrektywy using, zamiast nielubiane using namespace. Raczej wystarcz�
using std::vector;
using std::list;
using std::cout;
using std::cin;

//-------------------------------------------------------------------------------//
//									Product
//-------------------------------------------------------------------------------//

Product::Product(int id)
{
	_id = id;
}

Product::getID()
{
	return _id;
}

//-------------------------------------------------------------------------------//
//									Ramp
//-------------------------------------------------------------------------------//

Ramp::Ramp(float freq)
{
	frequency = freq;
}

Ramp::addReceiver(Worker* w, float pref = -1)
{
	rampReceiver.push_back(w);
	
	//1 odbiorca, na pewno do niego
	if (rampReceiver.size() == 1) 
		rampReceiverPref.push_back(1.0);
		
	/*Dodanie nowego odbiorcy do puli odbiorc�w danego w�z�a 
	bez precyzowania prawdopodobie�stwa powoduje ustawienie 
	preferencji na rozk�ad jednostajny.*/
	else if (pref == -1)
	{
		for (int i=0; i<rampReceiver.size()-1; i++)
			rampReceiver[i] = 1/( rampReceiver.size() + 1 );
			
		rampReceiver.push_back(rampReceiver[0]);
	}
	//jak pref podany, to przelicza na nowo dla wszystkich (wz�r od K�eczka)
	else
	{
		for (int i=0; i<rampReceiver.size()-1; i++)
			rampReceiver[i] = (1 - pref) * rampReceiver[i];
			
		rampReceiver.push_back(pref);
	}
}

Ramp::update(float time)
{
	
}

Ramp::getFrequency()
{
	return frequency;
}

Ramp::getReceivers()
{
	return rampReceiver;
}

//-------------------------------------------------------------------------------//
//									Magazine
//-------------------------------------------------------------------------------//

Magazine::addProduct(Product* p)
{
	products.push_back(p);
}

Magazine::getProducts()
{
	return products;
}

//-------------------------------------------------------------------------------//
//									Worker
//-------------------------------------------------------------------------------//

Worker::Worker(float time, QueueType queue)
{
	workTime = time;
	qType = queue;
}

Worker::addReceiver(Worker* w, float pref = -1)
{
	workerReceiver.push_back(w);
	
	//tak jak w rampie
	if (workerReceiver.size() == 1) 
		workerReceiverPref.push_back(1.0);
	else if (pref == -1)
	{
		for (int i=0; i<workerReceiver.size()-1; i++)
			workerReceiver[i] = 1/( workerReceiver.size() + 1 );
			
		workerReceiver.push_back(workerReceiver[0]);
	}
	else
	{
		for (int i=0; i<workerReceiver.size()-1; i++)
			workerReceiver[i] = (1 - pref) * workerReceiver[i];
			
		workerReceiver.push_back(pref);
	}
}

Worker::addProduct(Product* p)
{
	products.push_back(p);
}

Worker::work(float time)
{
	
}

Worker::getQueueType()
{
	return qType;
}

Worker::getReceivers()
{
	return workerReceiver;
}

Worker::getProducts()
{
	return products;
}

