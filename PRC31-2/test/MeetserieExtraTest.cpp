#include "gtest/gtest.h"
#include "MeetserieExtraTest.h"

TEST(TestVoegToe, getAantalKeer)
{
    MeetserieExtra meetserie("meetserie");
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getAantalKeer(10), 3);
    EXPECT_EQ(meetserie.getAantalKeer(5), 0);
    meetserie.voegToe(5);
    EXPECT_EQ(meetserie.getAantalKeer(5), 1);
}

TEST(TestVoegToe, getAantalVerschillendeWaarden)
{
    MeetserieExtra meetserie("meetserie");
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 0);
    meetserie.voegToe(10);
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 1);
    meetserie.voegToe(8);
    meetserie.voegToe(9);
    meetserie.voegToe(9);
    meetserie.voegToe(10);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 3);
}

TEST(TestVoegToe, voegToeMeetserie)
{
    MeetserieExtra meetserie("meetserie");
    MeetserieExtra meetserie2("meetserie");
    meetserie2.voegToe(10);
    meetserie2.voegToe(9);
    meetserie2.voegToe(8);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 0);
    meetserie.voegToeMeetserie(meetserie2);
    EXPECT_EQ(meetserie.getAantalVerschillendeWaarden(), 3);
    EXPECT_TRUE(meetserie.meetwaardeKomtVoor(10));
    EXPECT_TRUE(meetserie.meetwaardeKomtVoor(9));
    EXPECT_TRUE(meetserie.meetwaardeKomtVoor(8));
}

TEST(MeetserieExtra, saveAndLoad) {
    MeetserieExtra meetserie("meetserie");
    meetserie.voegToe(10);
    meetserie.voegToe(2);
    meetserie.save();
    MeetserieExtra loaded = MeetserieExtra::load();
    EXPECT_EQ(loaded.getAantalVerschillendeWaarden(), 2);
    EXPECT_TRUE(loaded.meetwaardeKomtVoor(10));
    EXPECT_TRUE(loaded.meetwaardeKomtVoor(2));
    EXPECT_FALSE(loaded.meetwaardeKomtVoor(5));
}
