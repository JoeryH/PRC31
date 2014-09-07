#ifndef  SCAN_H
#define SCAN_H

class Scan
{
	private:
		int serialNumber;
		int timesRecycled;
		Scan * next;

	public:
		// Scan(int number)
		// pre:  -
		// post: serialNumber == number and timesRecycled == 1
		Scan(int number);

		// virtual ~Scan(void)
		// pre:  -
		// post: object has been destructed
		virtual ~Scan(void);

		// int getSerialNumber(void)
		// pre:  -
		// post: serialNumber has been returned
		int getSerialNumber(void);

		// int getTimesRecycled
		// pre: -
		// post: timesRecycled has been returned
		int getTimesRecycled(void);

		// Scan * getNext(void)
		// pre:  -
		// post: next scan has been returned
		Scan * getNext(void);

		// void setNext(Scan * nextScan)
		// pre:  -
		// post: next points to nextScan
		void setNext(Scan * nextScan);

		// void recycle(void)
		// pre:  -
		// post: timesRecycled has been increased by one
		void recycle(void);
};

#endif
