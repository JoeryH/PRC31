#include "gtest/gtest.h"
#include "MeetserieExtraTest.h"

TEST(TestVoegToe, getAantalKeer)
{
    MeetserieExtra meetserie("joery");
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getAantalKeer(10), 3);
}

TEST(TestVoegToe, getAantalVerschillendeWaarden)
{
    MeetserieExtra meetserie("joery");
    meetserie.setNaam("Dagobert Duck");
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 0);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 1);
    meetserie.voegToe(8);
    meetserie.voegToe(9);meetserie.voegToe(9);
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 3);
}

TEST(TestVoegToe, voegToeMeetserie)
{
    MeetserieExtra meetserie("joery");
    MeetserieExtra meetserie2("joery");
    meetserie2.voegToe(10);
    meetserie2.voegToe(9);
    meetserie2.voegToe(8);
    meetserie.voegToeMeetserie(meetserie2);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 3);
}
