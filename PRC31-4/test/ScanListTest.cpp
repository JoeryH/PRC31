#include "gtest/gtest.h"
#include "ScanListTest.h"
#include <cstddef>
#include <iostream>
using namespace std;

TEST(TestScanList, emptyList)
{
    ScanList* list = new ScanList();
    Scan* test = list->getScanByNr(0);
	if (test != NULL) {
		// Couldn't find a fail function, and cant use EXPECT_EQ.
		cout << "Fail: should return null" << endl;
		EXPECT_TRUE(false);
	}
    EXPECT_FALSE(list->RemoveScan(100));
    EXPECT_EQ(list->getTimesRecycled(100), 0);
}

TEST(TestScanList, normalFlow)
{
    ScanList* list = new ScanList();
    list->AddScan(100);
    list->AddScan(100);
    list->AddScan(90);
    list->AddScan(80);
    EXPECT_EQ(list->getTimesRecycled(100), 2);
    EXPECT_EQ(list->getTimesRecycled(90), 1);
    EXPECT_EQ(list->getTimesRecycled(75), 0);

    EXPECT_EQ(list->getScanByNr(2)->getSerialNumber(), 100);
}

TEST(TestScanList, ordering)
{
    ScanList* list = new ScanList();
    list->AddScan(100);
    list->AddScan(100);
    list->AddScan(90);
    list->AddScan(80);
    list->AddScan(80);
    list->AddScan(95);
    list->AddScan(75);
	EXPECT_EQ(list->getScanByNr(0)->getSerialNumber(), 75);
	EXPECT_EQ(list->getScanByNr(1)->getSerialNumber(), 80);
	EXPECT_EQ(list->getScanByNr(2)->getSerialNumber(), 90);
	EXPECT_EQ(list->getScanByNr(3)->getSerialNumber(), 95);
	EXPECT_EQ(list->getScanByNr(4)->getSerialNumber(), 100);

	list->RemoveScan(90);
	EXPECT_EQ(list->getScanByNr(2)->getSerialNumber(), 95);
	list->RemoveScan(75);
	EXPECT_EQ(list->getScanByNr(1)->getSerialNumber(), 95);
}

TEST(TestScanList, memoryLeak)
{
    {
    	ScanList* list = new ScanList();
    	list->AddScan(100);
		list->AddScan(90);
		EXPECT_TRUE(list->RemoveScan(100));
		//Check for one line that says removed.
    }
    {
    	ScanList* list = new ScanList();
    	list->AddScan(100);
		list->AddScan(90);
		delete list;
		//Check for 2 lines that says removed
    }
}
