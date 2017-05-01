/*
 * contactlist.h
 *
 *  Created on: Oct 24, 2016
 *      Author: riyad
 */

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_
#include "contact.h"
using namespace std;


class Contactlist
{
public:
	Contactlist();
	void addtohead(const string&);
private:
	Contact* head;
	int size;
}





#endif /* CONTACTLIST_H_ */
