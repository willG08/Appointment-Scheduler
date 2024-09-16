#include "Pet.h"
#include "Person.h"
#include "DateTIme.h"
#include "GroomingAppointment.h"
#include "HaircutAppointment.h"
#include "Scheduler.h"

#include <array>
#include <iostream>
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//for floating point numbers
using namespace Catch::Matchers::Floating;

TEST_CASE("Person Class")
{
    Person p("katy", "perry", "8015559874");
    SECTION("Constructor - checks values using class getters")
    {
        CHECK(p.GetFirstName() == "Katy");
        CHECK(p.GetLastName() == "Perry");
        CHECK(p.GetPhone() == "801-555-9874");
    }

    SECTION("Setters - checks values using class getters")
    {
        //Check Setters
        p.SetFirstName("kenny");
        p.SetLastName("rogers");
        p.SetPhone("8018675309");
        CHECK(p.GetFirstName() == "Kenny");
        CHECK(p.GetLastName() == "Rogers");
        CHECK(p.GetPhone() == "801-867-5309");
    }
}


TEST_CASE("Pet Class")
{
    Pet p("Sam", "Wisely", "3908765123", "angel", "Dog");
    SECTION("Constructor - checks values using class getters")
    {
        CHECK(p.GetName() == "Angel");
        CHECK(p.GetType() == "Dog");
        CHECK(p.GetOwner().GetFirstName() == "Sam");
        CHECK(p.GetOwner().GetLastName() == "Wisely");
        CHECK(p.GetOwner().GetPhone() == "390-876-5123");
    }

    SECTION("Setters - checks values using class getters")
    {
        p.SetName("buttons");
        CHECK(p.GetName() == "Buttons");
        CHECK(p.GetType() == "Dog");
        CHECK(p.GetOwner().GetFirstName() == "Sam");
        CHECK(p.GetOwner().GetLastName() == "Wisely");
        CHECK(p.GetOwner().GetPhone() == "390-876-5123");
    }
}

TEST_CASE("DateTime Class")
{

    DateTime dt("08-01-2022","9:00 am");
    SECTION("Constructor - checks preformatted date & time using class getters")
    {
        CHECK(dt.GetDate() == "08/01/2022");
        CHECK(dt.GetTime() == "9:00am");
    }

    DateTime dt1("9-10-2023", "19:00 am");
    SECTION("Constructor - checks nonformatted date & time using class getters")
    {
        //if these tests are not passing they will impact the scheduler class unit tests later on
        CHECK(dt1.GetDate() == "09/10/2023");
        CHECK(dt1.GetTime() == "7:00pm");
    }

    SECTION("Setters - checks values using class getters")
    {
        //if these are not passing check that your setters are where the date/time formatting is taking place
        dt1.SetDate("9-1-2023");
        dt1.SetTime("20:03 pm");
        CHECK(dt1.GetDate() == "09/01/2023");
        CHECK(dt1.GetTime() == "8:03pm");
    }
}


TEST_CASE("GroomingAppointment Class")
{
    Person groomer("bob", "ross", "8015559874");
    Pet pet("sam", "wisely", "3908765123", "angel", "Dog");
    GroomingAppointment ga(groomer, pet, "9-10-2023", "19:00 am", 60);

    SECTION("Constructor - checking using class getters")
    {
        Person groomerCopy = ga.GetGroomer();
        bool check = groomer == groomerCopy;
        CHECK(check);
        Pet petCopy = ga.GetClient();
        check = pet == petCopy;
        CHECK(check);
        CHECK(ga.GetGroomingPrice() == 60);
        CHECK(ga.GetBill() == 60);
    }

    SECTION("Setters - checking values using class getters")
    {
        ga.SetGroomingPrice(65);
        CHECK(ga.GetGroomingPrice() == 65);
        CHECK(ga.GetBill() == 65);
    }
}

TEST_CASE("HaircutAppointment Class")
{
    Person groomer("bob", "ross", "8015559874");
    Pet pet("sam", "wisely", "3908765123", "angel", "Dog");
    HaircutAppointment ha(groomer, pet, "9-10-2023", "19:00 am", 60, 35);

    SECTION("Constructor - checking using class getters")
    {
        SECTION("Checks that groomer info is correct")
        {
            CHECK(ha.GetGroomer().GetFirstName() == "Bob");
            CHECK(ha.GetGroomer().GetLastName() == "Ross");
            CHECK(ha.GetGroomer().GetPhone() == "801-555-9874");
        }

        SECTION("Checks that client info is correct")
        {
            CHECK(ha.GetClient().GetOwner().GetFirstName() == "Sam");
            CHECK(ha.GetClient().GetOwner().GetLastName() == "Wisely");
            CHECK(ha.GetClient().GetOwner().GetPhone() == "390-876-5123");
            CHECK(ha.GetClient().GetName() == "Angel");
            CHECK(ha.GetClient().GetType() == "Dog");
        }

        SECTION("Checks appointment DateTime is correctly")
        {
            CHECK(ha.GetDateTime().GetDate() == "09/10/2023");
            CHECK(ha.GetDateTime().GetTime() == "7:00pm");
        }

        SECTION("Checks appointment prices and bill is correct")

        CHECK(ha.GetGroomingPrice() == 60);
        CHECK(ha.GetHaircutPrice() == 35);
        CHECK(ha.GetBill() == 95);
    }
    SECTION("Setters - checking new values using class getters")
    {
        ha.SetGroomingPrice(65);
        ha.SetHaircutPrice(45);
        CHECK(ha.GetGroomingPrice() == 65);
        CHECK(ha.GetHaircutPrice() == 45);
        CHECK(ha.GetBill() == 65 + 45);
    }
}

TEST_CASE("Scheduler Class")
{
        Scheduler s("../../tests/appointments_test_file.csv");
        SECTION("GetAppointments() - checking constructor correctly loads data")
        {
            CHECK(s.GetAppointments().size() == 6);
            SECTION("Appointment at position 0")
            {
                CHECK(s.GetAppointments().at(0)->GetGroomer().GetFirstName() == "Katy");
                CHECK(s.GetAppointments().at(0)->GetGroomer().GetLastName() == "Perry");
                CHECK(s.GetAppointments().at(0)->GetGroomer().GetPhone() == "801-645-8877");
                CHECK(s.GetAppointments().at(0)->GetClient().GetOwner().GetFirstName() == "Tom");
                CHECK(s.GetAppointments().at(0)->GetClient().GetOwner().GetLastName() == "Cruise");
                CHECK(s.GetAppointments().at(0)->GetClient().GetOwner().GetPhone() == "801-456-8767");
                CHECK(s.GetAppointments().at(0)->GetClient().GetName() == "Buttons");
                CHECK(s.GetAppointments().at(0)->GetClient().GetType() == "dog");
                CHECK(s.GetAppointments().at(0)->GetDateTime().GetDate() == "07/07/2023");
                CHECK(s.GetAppointments().at(0)->GetDateTime().GetTime() == "9:00am");
                CHECK(s.GetAppointments().at(0)->GetBill() == 100);
            }
            SECTION("Appointment at position 1")
            {
                CHECK(s.GetAppointments().at(1)->GetGroomer().GetFirstName() == "Katy");
                CHECK(s.GetAppointments().at(1)->GetGroomer().GetLastName() == "Perry");
                CHECK(s.GetAppointments().at(1)->GetGroomer().GetPhone() == "801-645-8777");
                CHECK(s.GetAppointments().at(1)->GetClient().GetOwner().GetFirstName() == "Jerry");
                CHECK(s.GetAppointments().at(1)->GetClient().GetOwner().GetLastName() == "Nicholson");
                CHECK(s.GetAppointments().at(1)->GetClient().GetOwner().GetPhone() == "801-456-8767");
                CHECK(s.GetAppointments().at(1)->GetClient().GetName() == "Zipper");
                CHECK(s.GetAppointments().at(1)->GetClient().GetType() == "cat");
                CHECK(s.GetAppointments().at(1)->GetDateTime().GetDate() == "07/07/2023");
                CHECK(s.GetAppointments().at(1)->GetDateTime().GetTime() == "10:00am");
                CHECK(s.GetAppointments().at(1)->GetBill() == 40);
            }
            SECTION("Appointment at position 2")
            {
                CHECK(s.GetAppointments().at(2)->GetGroomer().GetFirstName() == "Shanice");
                CHECK(s.GetAppointments().at(2)->GetGroomer().GetLastName() == "Barry");
                CHECK(s.GetAppointments().at(2)->GetGroomer().GetPhone() == "801-645-8877");
                CHECK(s.GetAppointments().at(2)->GetClient().GetOwner().GetFirstName() == "Julian");
                CHECK(s.GetAppointments().at(2)->GetClient().GetOwner().GetLastName() == "Lloyd");
                CHECK(s.GetAppointments().at(2)->GetClient().GetOwner().GetPhone() == "801-456-8767");
                CHECK(s.GetAppointments().at(2)->GetClient().GetName() == "Spot");
                CHECK(s.GetAppointments().at(2)->GetClient().GetType() == "dog");
                CHECK(s.GetAppointments().at(2)->GetDateTime().GetDate() == "07/09/2023");
                CHECK(s.GetAppointments().at(2)->GetDateTime().GetTime() == "9:00am");
                CHECK(s.GetAppointments().at(2)->GetBill() == 100);
            }
            SECTION("Appointment at position 3")
            {
                CHECK(s.GetAppointments().at(3)->GetGroomer().GetFirstName() == "Shanice");
                CHECK(s.GetAppointments().at(3)->GetGroomer().GetLastName() == "Barry");
                CHECK(s.GetAppointments().at(3)->GetGroomer().GetPhone() == "869-724-4398");
                CHECK(s.GetAppointments().at(3)->GetClient().GetOwner().GetFirstName() == "Conor");
                CHECK(s.GetAppointments().at(3)->GetClient().GetOwner().GetLastName() == "Garrett");
                CHECK(s.GetAppointments().at(3)->GetClient().GetOwner().GetPhone() == "491-693-0228");
                CHECK(s.GetAppointments().at(3)->GetClient().GetName() == "Shakespeare");
                CHECK(s.GetAppointments().at(3)->GetClient().GetType() == "cat");
                CHECK(s.GetAppointments().at(3)->GetDateTime().GetDate() == "07/09/2023");
                CHECK(s.GetAppointments().at(3)->GetDateTime().GetTime() == "9:30am");
                CHECK(s.GetAppointments().at(3)->GetBill() == 110);
            }
            SECTION("Appointment at position 4")
            {
                CHECK(s.GetAppointments().at(4)->GetGroomer().GetFirstName() == "Harry");
                CHECK(s.GetAppointments().at(4)->GetGroomer().GetLastName() == "Larson");
                CHECK(s.GetAppointments().at(4)->GetGroomer().GetPhone() == "869-724-4398");
                CHECK(s.GetAppointments().at(4)->GetClient().GetOwner().GetFirstName() == "Kaine");
                CHECK(s.GetAppointments().at(4)->GetClient().GetOwner().GetLastName() == "Morton");
                CHECK(s.GetAppointments().at(4)->GetClient().GetOwner().GetPhone() == "279-427-2923");
                CHECK(s.GetAppointments().at(4)->GetClient().GetName() == "Abby");
                CHECK(s.GetAppointments().at(4)->GetClient().GetType() == "cat");
                CHECK(s.GetAppointments().at(4)->GetDateTime().GetDate() == "07/08/2023");
                CHECK(s.GetAppointments().at(4)->GetDateTime().GetTime() == "9:30am");
                CHECK(s.GetAppointments().at(4)->GetBill() == 110);
            }
            SECTION("Appointment at position 5")
            {
                CHECK(s.GetAppointments().at(5)->GetGroomer().GetFirstName() == "Katy");
                CHECK(s.GetAppointments().at(5)->GetGroomer().GetLastName() == "Perry");
                CHECK(s.GetAppointments().at(5)->GetGroomer().GetPhone() == "801-645-8777");
                CHECK(s.GetAppointments().at(5)->GetClient().GetOwner().GetFirstName() == "John");
                CHECK(s.GetAppointments().at(5)->GetClient().GetOwner().GetLastName() == "Heath");
                CHECK(s.GetAppointments().at(5)->GetClient().GetOwner().GetPhone() == "801-456-8767");
                CHECK(s.GetAppointments().at(5)->GetClient().GetName() == "Blazer");
                CHECK(s.GetAppointments().at(5)->GetClient().GetType() == "dog");
                CHECK(s.GetAppointments().at(5)->GetDateTime().GetDate() == "07/09/2023");
                CHECK(s.GetAppointments().at(5)->GetDateTime().GetTime() == "1:00pm");
                CHECK(s.GetAppointments().at(5)->GetBill() == 40);
            }
        }

        std::set<std::string>::iterator it;
        SECTION("GetAppointmentDates() - checking for correct set size and data")
        {
            std::set<std::string> dates = s.GetAppointmentDates();
            CHECK(dates.size() == 3); // Check to make sure your date/time data is being correctly formatted within the DateTime object
            it = dates.find("07/08/2023");
            CHECK_FALSE(it == dates.end());
            it = dates.find("07/08/2023");
            CHECK_FALSE(it == dates.end());
            it = dates.find("07/09/2023");
            CHECK_FALSE(it == dates.end());
            it = dates.find("07/07/2023");
            REQUIRE(it != dates.end()); //Sample feedback in the comment
        }

        SECTION("GetGroomers() - checking for correct set size and data")
        {
            std::set<std::string> groomers = s.GetGroomers();
            CHECK(groomers.size() == 3);
            it = groomers.find("Katy Perry");
            CHECK_FALSE(it == groomers.end());
            it = groomers.find("Shanice Barry");
            CHECK_FALSE(it == groomers.end());
            it = groomers.find("Harry Larson");
            CHECK_FALSE(it == groomers.end());
        }

        std::vector<std::shared_ptr<Appointment>> appointments;
        SECTION("GetAppointmentsByDate() - checking for a correct record, vector size, and data formatting")
        {
            appointments = s.GetAppointmentsByDate("7-8-2023");
            CHECK(appointments.size() == 1);
            CHECK(appointments.at(0)->GetGroomer().GetFirstName() ==
                  "Harry"); //If this test fails, check to make sure your Person constructor is formatting the name before storing them as member variables
            CHECK(appointments.at(0)->GetGroomer().GetLastName() == "Larson");
            CHECK(appointments.at(0)->GetGroomer().GetPhone() == "869-724-4398");
            CHECK(appointments.at(0)->GetClient().GetOwner().GetFirstName() == "Kaine");
            CHECK(appointments.at(0)->GetClient().GetOwner().GetLastName() == "Morton");
            CHECK(appointments.at(0)->GetClient().GetOwner().GetPhone() == "279-427-2923");
            CHECK(appointments.at(0)->GetClient().GetName() == "Abby");
            CHECK(appointments.at(0)->GetClient().GetType() == "cat");
        }

        SECTION("Filter() - checking for a correct record, vector size, and data formatting")
        {
            appointments = s.Filter("Katy", "Perry", "7-9-2023");
            CHECK(appointments.size() == 1);
            CHECK(appointments.at(0)->GetGroomer().GetFirstName() == "Katy");
            CHECK(appointments.at(0)->GetGroomer().GetLastName() == "Perry");
            CHECK(appointments.at(0)->GetGroomer().GetPhone() == "801-645-8777");
            CHECK(appointments.at(0)->GetClient().GetOwner().GetFirstName() == "John");
            CHECK(appointments.at(0)->GetClient().GetOwner().GetLastName() == "Heath");
            CHECK(appointments.at(0)->GetClient().GetOwner().GetPhone() == "801-456-8767");
            CHECK(appointments.at(0)->GetClient().GetName() == "Blazer");
            CHECK(appointments.at(0)->GetClient().GetType() == "dog");
        }
}
