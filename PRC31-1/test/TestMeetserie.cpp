#include "gtest/gtest.h"
#include "MeetserieTest.h"

TEST(TestNaam, beginNaam)
{
    Meetserie meetserie("joery");
    EXPECT_EQ(meetserie.getNaam(), "joery");
}

TEST(TestNaam, setNaam)
{
    Meetserie meetserie("joery");
    meetserie.setNaam("Dagobert Duck");
    EXPECT_EQ(meetserie.getNaam(), "Dagobert Duck");
}

TEST(TestKomtVoor, meetwaardeKomtVoor)
{
    Meetserie meetserie("joery");
    meetserie.voegToe(10);
    EXPECT_TRUE(meetserie.meetwaardeKomtVoor(10));
}

TEST(TestVol, isVol)
{
	int aantal = 0;
    Meetserie meetserie("joery");
    EXPECT_FALSE(meetserie.isVol());
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.bepAantalMeetwaarden(aantal);
    EXPECT_EQ(aantal, 3);
    meetserie.voegToe(10);
    EXPECT_FALSE(meetserie.isVol());
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    EXPECT_FALSE(meetserie.isVol());
    meetserie.voegToe(10);
    EXPECT_TRUE(meetserie.isVol());
    meetserie.bepAantalMeetwaarden(aantal);
    EXPECT_EQ(aantal, 10);
    meetserie.voegToe(10);
    meetserie.bepAantalMeetwaarden(aantal);
    EXPECT_EQ(aantal, 10);
}

TEST(TestGetMeetwaarde, getMeetwaarde)
{
    Meetserie meetserie("joery");
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getMeetwaarde(0), 10);
}
