#include "Scan.h"
#include <cstddef>
#include <iostream>
using namespace std;

Scan::Scan(int number) : serialNumber(number),timesRecycled(1), next(NULL) {
}

Scan::~Scan() {
	cout << "Scan with serialNumber " << serialNumber << " removed" << endl;
}

int Scan::getSerialNumber() {
	return serialNumber;
}

int Scan::getTimesRecycled() {
	return timesRecycled;
}

Scan* Scan::getNext() {
	return next;
}

void Scan::setNext(Scan* nextScan) {
	this->next = nextScan;
}

void Scan::recycle() {
	timesRecycled++;
}
