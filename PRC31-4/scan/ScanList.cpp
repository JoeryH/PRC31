#include "ScanList.h"
#include <cstddef>

ScanList::ScanList() {
    scans = NULL;
}

ScanList::~ScanList() {
	Scan* s = scans;
    while (s != NULL) {
		Scan* toDelete = s;
		s = s->getNext();
		delete toDelete;
    }
}

void ScanList::AddScan(int serialNumber) {
	if (scans == NULL) {
		scans = new Scan(serialNumber);
		return;
	}
	Scan* current = scans;
	Scan* previous = NULL;
	while(true) {
		if (current->getSerialNumber() < serialNumber) {
			previous = current;
			current = current->getNext();
			if (current == NULL) {
				previous->setNext(new Scan(serialNumber));
				return;
			}
		} else if (current->getSerialNumber() > serialNumber) {
			Scan* newScan = new Scan(serialNumber);
			if (previous == NULL) {
				newScan->setNext(current);
				scans = newScan;
			} else {
				previous->setNext(newScan);
				newScan->setNext(current);
			}

			return;
		} else if (current->getSerialNumber() == serialNumber) {
			current->recycle();
			return;
		}
	}
}

Scan* ScanList::getScanByNr(int position) {
	Scan* current = scans;
	while(position > -1) {
		if (position == 0) {
			return current;
		} else {
            current = current->getNext();
            position--;
		}
	}
	return NULL;
}

bool ScanList::RemoveScan(int serialNumber) {
    Scan* current = scans;
    if (current == NULL) {
		return false;
    }
	Scan* previous = NULL;
    while(current->getSerialNumber() <= serialNumber) {
		if (current->getSerialNumber() == serialNumber) {
			if (previous == NULL) {
				scans = current->getNext();
				delete current;
			} else {
                previous->setNext(current->getNext());
                delete current;
			}
			return true;
		} else {
            if (current->getNext() != NULL) {
				previous = current;
				current = current->getNext();
            } else {
				return false;
            }
		}
    }
    return false;
}

int ScanList::getTimesRecycled(int serialNumber) {
	Scan* current = scans;
    if (current == NULL) {
		return 0;
    }
    while(current->getSerialNumber() <= serialNumber) {
		if (current->getSerialNumber() == serialNumber) {
            return current->getTimesRecycled();
		} else {
			if (current->getNext() != NULL) {
				current = current->getNext();
			} else {
				return 0;
			}
		}
    }
    return 0;
}
